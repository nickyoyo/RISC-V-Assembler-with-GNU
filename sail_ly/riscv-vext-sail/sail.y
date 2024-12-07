%{
#include "symboltable.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;
void yyerror(string s);
extern int linenum; /* declared in p2.l */

//int UnionCount = 0;
int imm_nobits = 0;     //判斷instr結構有多於一個imm
int immbitcheck = 0;    //判斷instr結構是否只有一個imm
int immbit = 0;         //若instr結構只有一個imm，紀錄imm bit數
int oplistcheck = 0;    // >0 則在mapping encdec_?op，存取optable
int mapop = 0;          //用於區別oplistcheck、check_multi兩個flag
int instr_bits = 0;     // >1 在mapping clause encdec 紀錄32bit結構
int many_instr = 0;     //判斷mapping clause encdec是否多行
int check_multi = 0;    //判斷mapping clause encdec是否多行，若多行則從其中抓取opname
int Getencdecop = 0;   //判斷是否以mapping encdec_?op，存取optable
int unit_check = 0;   //一部份特權指令判斷  
int instrbits_check = 0; //存取僅限32bit以內資訊
int encdec_IF = 0;   //encdec_IF 分析
int addshamt = 0; //shamt 是否有第五位 << SHIFTIOP shamt[5] == bitzero
int boolbits = 0;
int sizebits = 0;
int encdec_rounding_mode = 0;
int LS_Check = 0;
int LFPCount = 0;        //LOAD_FP 判定HWD
int SFPCount = 0;       //STORE_FP 判定HWD
int FPCount = 0;       // LOAD_FP STORE_FP 判定次數
int Mext_U = 0;    //Mext  bool_not_bits => 有無U
int csr_check = 0;      //csr  check;

int assemblyString = 0;      //指令assembly結構存取
int encdec_createcheck = 0; //Vext跟非Vext model 擬合

int mext_MULcheck = 0; //mext MUL 處理
int mext_MULcheck1 = 0; //mext MUL 處理  mul_mnemonic

// string id_list_type;
OPtable_map table;
OPtable_stack symtable_stack;

opcctable_map opcctable;
opcctable_stack opccsymtable_stack;

opcctable_map opccTmptable;
opcctable_stack opccTmpsymtable_stack;

Mexttable_map MextTable; 
Mexttable_map MextTable1; 
Mext_stack Mexttable_stack;

Mexttable_map MextTable_ID; 
Mext_stack Mexttable_stack_ID;
Mexttable_map MextTable1_ID; 
Mext_stack Mexttable_stack1_ID;
 
Output_map instrBitTable; 
Output_stack instrtable_stack;

opccOutput_map opccoutputtable;
opccOutput_stack opccoutputsymtable_stack;

Mext_sv Mexttmp;
Mext_sv Mexttmp1;
OPtable_sv optmp;
opcctable_sv opccTmp;
Output_sv OutputTable;
opccOutput_sv opccOutputTable;


std::string BitStr;
std::string assemblyStr;
std::string OpNameStr;
std::string instType;

int yylex(void);

%}
  
%union {
   struct {
    int ival;
    bool bval;
    float fval;
    char charVal;
    char* stringVal;
    } node;
}

/* operator */

%right '^'
%left '*' '/' '%'
%left '+' '-' 
%left LESS LESS_OR_EQUAL EQUAL GREATER GREATER_OR_EQUAL NOT_EQUAL
%right '&'
%right '|' 

%nonassoc UNARY_MINUS 
 
/* keywords */
%token And As Assert Bitzero Bitone By Match Clause Dec Default Effect End Op
%token Enum Else False Forall Foreach Overload Function_ Mapping If_ In Inc Let_ Int Order Bool Cast
%token Pure Monadic Register Return Scattered Sizeof Struct Then True TwoCaret TYPE Typedef
%token Undefined Union Newtype With Val Outcome Constraint Throw Try Catch Exit Bitfield Constant
%token Repeat Until While Do Mutual Var Ref Configuration TerminationMeasure Instantiation Impl Private
%token InternalPLet InternalReturn InternalAssume
%token Forwards Backwards

%token Bar Comma Dot Eof Minus Semi Under DotDot At ColonColon Caret Star
%token Lcurly Rcurly Lparen Rparen Lsquare Rsquare LcurlyBar RcurlyBar LsquareBar RsquareBar
%token MinusGt Bidir

%token Eq EqGt Unit Colon

%token OpId Attribute LINE_DIRECTIVE

%start file

%token FIXITY

%token <node> ID TyVar    
 
%token <node> Num Bin_literal Hex_literal 
 
%token <node> STRING_LITERAL 
 
%%   
id: ID {
       //cout << $1.stringVal << endl; 
        if(assemblyString == 1){
                instType+=$1.stringVal;
                assemblyString = 2;
        }
        else if(assemblyString == 3){
                assemblyStr+=$1.stringVal;
        }
        if(immbitcheck == 1 && !strcmp($1.stringVal,"MUL")){
                //cout << $1.stringVal << endl; 
                mext_MULcheck = 1;
        }
        if(mext_MULcheck == 1){
              if(strstr($1.stringVal, "encdec_")){
                mext_MULcheck = 2;
                Mexttmp.name.clear();
                Mexttmp.name = "";
              }  
        }
        else if(strstr($1.stringVal, "mul_mnemonic")){
                mext_MULcheck1=1;        
        } 
        if(boolbits == 1 || sizebits == 1 || encdec_rounding_mode == 1 || Mext_U == 1){  
                BitStr=BitStr+$1.stringVal;  
                boolbits = 0; 
                sizebits = 0;   
                encdec_rounding_mode = 0;
        } 
        else if((strstr($1.stringVal, "encdec_")|| (strstr($1.stringVal,"vext") && strstr($1.stringVal,"_vs1")) ) && mapop < 1 && instr_bits < 1){
                mapop++;  
                if(mapop == 1){  
                        oplistcheck = 1;  
                }
                if(mapop == 2){ 
                        many_instr = 1;
                } 
        } 
        else if(oplistcheck == 1){
                oplistcheck++;
        } 
        else if(oplistcheck > 1 && encdec_IF == 0){
                //cout << $1.stringVal << endl;
                optmp.name = $1.stringVal;
                if(strstr($1.stringVal, "RISCV_")) 
                        optmp.name.erase(0,6);
                else if(strstr($1.stringVal,"VEXT") && strstr($1.stringVal,"VF")){
                        optmp.name.clear();
                        if(strstr($1.stringVal,"SVF")){
                                optmp.name = "vsext_vf";
                        }
                        else if(strstr($1.stringVal,"ZVF")){
                                optmp.name = "vzext_vf";
                        }
                        if(strstr($1.stringVal,"2")){
                                optmp.name += "2";
                        }
                        else if(strstr($1.stringVal,"4")){
                                optmp.name += "4";
                        }
                        else if(strstr($1.stringVal,"8")){
                                optmp.name += "8";
                        }
                }
                else if(strstr($1.stringVal, "WMVV_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "WMVX_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vx";
                }
                else if(strstr($1.stringVal, "FVV_VF")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vs";
                }
                else if(strstr($1.stringVal, "MVV_VR")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vs";
                }
                else if(strstr($1.stringVal, "VVCMP_")){
                        optmp.name.erase(0,6);
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "VICMP_")){
                        optmp.name.erase(0,6);
                        optmp.name += "_vi";
                }
                else if(strstr($1.stringVal, "VXCMP_")){
                        optmp.name.erase(0,6);
                        optmp.name += "_vx";
                }
                else if(strstr($1.stringVal, "VVMC_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "VXMC_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vx";
                }
                else if(strstr($1.stringVal, "VXMS_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vxm";
                }
                else if(strstr($1.stringVal, "VVMS_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vvm";
                }
                else if(strstr($1.stringVal, "FVVM_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "VVM_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vvm";
                }
                else if(strstr($1.stringVal, "VXM_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vxm";
                }
                else if(strstr($1.stringVal, "VFM_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vf";
                }
                else if(strstr($1.stringVal, "MVV_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "VIMC_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vi";
                }
                else if(strstr($1.stringVal, "VIMS_")){
                        optmp.name.erase(0,5);
                        optmp.name += "_vim";
                }
                else if(strstr($1.stringVal, "VIM_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vim";
                }
                else if(strstr($1.stringVal, "IVV_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vs";
                }
                else if(strstr($1.stringVal, "MVX_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_vx";
                }
                else if(strstr($1.stringVal, "NXS_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_wx";
                }
                else if(strstr($1.stringVal, "FWVV_")){
                        optmp.name.erase(0,5);
                        optmp.name.erase(0,1);
                        optmp.name = "VFW" + optmp.name;
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "FWV_CVT")){
                        optmp.name.erase(0,4);
                        optmp.name = "VFW" + optmp.name;
                        optmp.name += "_v";
                        //cout << optmp.name << endl;
                }
                else if(strstr($1.stringVal, "FNV_CVT")){
                        optmp.name.erase(0,4);
                        optmp.name = "VFN" + optmp.name;
                        optmp.name += "_w";
                        //cout << optmp.name << endl;
                }
                else if(strstr($1.stringVal, "FWVF_")){
                        optmp.name.erase(0,5);
                        optmp.name.erase(0,1);
                        optmp.name = "VFW" + optmp.name;
                        optmp.name += "_vf";
                }
                else if(strstr($1.stringVal, "FWF_")){
                        optmp.name.erase(0,4);
                        optmp.name.erase(0,1);
                        optmp.name = "VFW" + optmp.name;
                        optmp.name += "_wf";
                }
                else if(strstr($1.stringVal, "FWV_")){
                        optmp.name.erase(0,4);
                        optmp.name.erase(0,1);
                        optmp.name = "VFW" + optmp.name;
                        optmp.name += "_wv";
                }
                else if(strstr($1.stringVal, "FV_CVT")){
                        optmp.name.erase(0,3);
                        optmp.name = "VF" + optmp.name;
                        optmp.name += "_v";
                        //cout << optmp.name << endl;
                }
                else if(strstr($1.stringVal, "WVX_") || strstr($1.stringVal, "WVV_")){
                        optmp.name.erase(0,4);
                        if(strstr($1.stringVal,"_VADDU") || strstr($1.stringVal,"_VADD") || strstr($1.stringVal,"_VSUB") || strstr($1.stringVal,"VSUBU")){
                                optmp.name.erase(0,1);
                                optmp.name = "VW" + optmp.name;
                        }
                        if(strstr($1.stringVal, "WVX_")){
                                optmp.name += "_vx";
                        }
                        else{
                                optmp.name += "_vv";
                        }
                }
                else if(strstr($1.stringVal, "WV_")){
                        optmp.name.erase(0,3);
                        optmp.name.erase(0,1);
                        optmp.name = "VW" + optmp.name;
                        optmp.name += "_wv";
                }
                else if(strstr($1.stringVal, "WX_")){
                        optmp.name.erase(0,3);
                        optmp.name.erase(0,1);
                        optmp.name = "VW" + optmp.name;
                        optmp.name += "_wx";
                }
                else if(strstr($1.stringVal, "FVV_")){
                        optmp.name.erase(0,4);
                        optmp.name.erase(0,1);
                        optmp.name = "VF" + optmp.name;
                        optmp.name += "_vv";
                        if(strstr($1.stringVal, "VSQRT") || strstr($1.stringVal, "VRSQRT7") || strstr($1.stringVal, "VREC7") || strstr($1.stringVal, "VCLASS")){
                                optmp.name.pop_back();
                        }
                }
                else if(strstr($1.stringVal, "VV_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_vv";
                }
                else if(strstr($1.stringVal, "VF_")){
                        optmp.name.erase(0,3);
                        optmp.name.erase(0,1);
                        optmp.name = "VF" + optmp.name;
                        optmp.name += "_vf";
                }
                else if(strstr($1.stringVal, "NVS_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_wv";
                }
                else if(strstr($1.stringVal, "NV_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_wv";
                }
                else if(strstr($1.stringVal, "VX_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_vx";
                }
                else if(strstr($1.stringVal, "NX_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_wx";
                }
                else if(strstr($1.stringVal, "VX_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_vx";
                }
                else if(strstr($1.stringVal, "VI_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_vi";
                }
                else if(strstr($1.stringVal, "NIS_")){
                        optmp.name.erase(0,4);
                        optmp.name += "_wi";
                }
                else if(strstr($1.stringVal, "NI_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_wi";
                }
                else if(strstr($1.stringVal, "MM_")){
                        optmp.name.erase(0,3);
                        optmp.name += "_mm";
                }
               // printf("\n1%s\n",$1.stringVal); 
        }
        else if(instr_bits > 1 && instrbits_check == 1){
                if(strstr($1.stringVal, "simm")){
                        BitStr=BitStr+"simm";
                        imm_nobits = 1; 

                        if(strcmp($1.stringVal,"imm")){
                                immbit = 0;
                        }
                }
                else if(strstr($1.stringVal, "imm")){
                        BitStr=BitStr+"imm";
                        imm_nobits = 1; 

                        if(strcmp($1.stringVal,"imm")){
                                immbit = 0;
                        }
                }
                else if(!strcmp($1.stringVal,"csr")){
                        csr_check = 1;
                        BitStr=BitStr+$1.stringVal;
                }
                else if(!strcmp($1.stringVal,"rs1")){
                        BitStr=BitStr+$1.stringVal;
                }
                else if(!strcmp($1.stringVal,"vs1")){
                        BitStr=BitStr+$1.stringVal;
                }
                else if(!strcmp($1.stringVal,"rs2")){
                        BitStr=BitStr+$1.stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal,"vs2")){
                        BitStr=BitStr+$1.stringVal;
                }
                else if(!strcmp($1.stringVal,"rs3")){
                        BitStr=BitStr+$1.stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal,"rd")){
                        BitStr=BitStr+$1.stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal,"vd")){ 
                        BitStr=BitStr+$1.stringVal;
                }
                else if(!strcmp($1.stringVal,"vm")){
                       // cout << $1.stringVal << endl;
                        BitStr=BitStr+$1.stringVal;
                }
                else if(!strcmp($1.stringVal,"shamt")){
                        BitStr=BitStr+$1.stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal,"pred")){
                        BitStr=BitStr+$1.stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal,"succ")){
                        BitStr=BitStr+$1.stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal,"bool_bits")){
                        boolbits = 1;
                }
                else if(!strcmp($1.stringVal,"size_bits")){
                        sizebits = 1;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp($1.stringVal, "bool_not_bits")){
                    Mext_U = 1;        
                } 
                else if(!strcmp($1.stringVal,"encdec_rounding_mode")){
                        encdec_rounding_mode = 1;
                       // cout << $1.stringVal << endl;
                }
                else if(strstr($1.stringVal,"encdec_") || (strstr($1.stringVal,"vext") && strstr($1.stringVal,"_vs1"))){
                        BitStr=BitStr+"op";
                        Getencdecop = 1;
                       
                }
                instrbits_check=0;
        } 
        else if(!strcmp($1.stringVal,"shamt")){
                if(encdec_IF == 2){
                        addshamt = 1;
                        encdec_IF = 0;
                }
        } 
        else if(check_multi == 1 && strstr($1.stringVal, "RISCV_")){
                //cout << $1.stringVal << endl;  

                optmp.name = $1.stringVal;    
                optmp.name.erase(0,6); 
                if(strstr($1.stringVal, "UW")){ 
                     optmp.name.pop_back();    
                     optmp.name.pop_back();    
                     optmp.name += "_UW";     
                }    
                if(strstr($1.stringVal, "ORCB")){ 
                     optmp.name.pop_back();   
                     optmp.name += "_B";      
                }    
                if(strstr($1.stringVal, "EXT")){  
                     if(!strcmp($1.stringVal,"RISCV_SEXTB")){
                        optmp.name.pop_back(); 
                        optmp.name += "_B"; 
                     }
                     else if(strstr($1.stringVal, "BEXT")){
                     }
                     else{
                        optmp.name.pop_back(); 
                        optmp.name += "_H"; 
                     }  
                }  
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && (strstr($1.stringVal, "FM") || strstr($1.stringVal, "FNM"))){
                //cout << $1.stringVal << endl;
                optmp.name = $1.stringVal;
                optmp.opcode = ""; 
                unit_check = 0;   
                //OpNameStr = optmp.name; 
                if(!strcmp($1.stringVal,"VFMERGE")){
                        optmp.name += "_VFM"; 
                }
                if(!strcmp($1.stringVal,"VFMV")){
                        optmp.name += "_V_F"; 
                }
                if(!strcmp($1.stringVal,"VFMVFS")){
                        optmp.name.pop_back();
                        optmp.name.pop_back();
                        optmp.name += "_F_S"; 
                } 
        }
        else if(check_multi == 1 && (strstr($1.stringVal, "_D") || strstr($1.stringVal, "FCVT"))){
                //cout << $1.stringVal << endl;
                optmp.name = $1.stringVal;
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && (strstr($1.stringVal, "_S") || strstr($1.stringVal, "FCVT"))){
                //cout << $1.stringVal << endl;
                optmp.name = $1.stringVal;
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && FPCount == 1 && (LFPCount!=0 || SFPCount!=0) && (strstr($1.stringVal, "HALF") || strstr($1.stringVal, "WORD") || strstr($1.stringVal, "DOUBLE"))){
              // cout << $1.stringVal << endl;
                if(SFPCount==0){
                        optmp.name="FL"; 
                }
                if(LFPCount==0){
                        optmp.name="FS"; 
                }
                if(LFPCount == 1 || SFPCount == 1){
                        optmp.name += "H";
                }
                else if(LFPCount == 2 || SFPCount == 2){
                        optmp.name += "W";
                }
                else if(LFPCount == 3 || SFPCount == 3){
                        optmp.name += "D";
                }
                if(LFPCount == 0)
                        SFPCount++;
                if(SFPCount == 0)
                        LFPCount++;
                optmp.opcode = ""; 
        }
        else if(check_multi == 1 && unit_check == 1){
                //cout << $1.stringVal << endl;
                if(strstr($1.stringVal, "VCPOP")){
                        //cout << $1.stringVal << endl;
                        optmp.name = "vpopc_m";
                        optmp.opcode = "";
                        unit_check = 0;
                }
                else if(strstr($1.stringVal, "MVVCOMPRESS")){
                        optmp.name = "vcompress_vm";
                        optmp.opcode = "";
                        unit_check = 0;
                }
                else if(strstr($1.stringVal, "VMVSX")){
                        optmp.name = "vmv_s_x";
                        optmp.opcode = "";
                        unit_check = 0;
                }
                else if(strstr($1.stringVal, "VMVXS")){
                        optmp.name = "vmv_x_s";
                        optmp.opcode = "";
                        unit_check = 0;
                }
                else if(strstr($1.stringVal, "TYPE")){
                        unit_check = 0;       
                        if(strstr($1.stringVal, "MASKTYPEV")){
                                optmp.name = "vmerge_vvm";
                                optmp.opcode = "";
                        }
                        else if(strstr($1.stringVal, "MOVETYPEV")){
                                optmp.name = "vmv_v_v";
                                optmp.opcode = "";
                        }
                        else if(strstr($1.stringVal, "MASKTYPEX")){
                                optmp.name = "vmerge_vxm";
                                optmp.opcode = "";
                        }
                        else if(strstr($1.stringVal, "MOVETYPEX")){
                                optmp.name = "vmv_v_x";
                                optmp.opcode = "";
                        }
                        else if(strstr($1.stringVal, "MOVETYPEI")){
                                optmp.name = "vmv_v_i";
                                optmp.opcode = "";
                        }
                        else if(strstr($1.stringVal, "VMVRTYPE")){
                                optmp.name = "vmv";
                                optmp.opcode = "";
                        }
                        else if(strstr($1.stringVal, "MASKTYPEI")){
                                optmp.name = "vmerge_vim";
                                optmp.opcode = "";
                        }
                } 
                else if(!strcmp($1.stringVal,"VXSG") || !strcmp($1.stringVal,"VISG")){
                        unit_check = 0;   
                }
                else if(strstr($1.stringVal, "OP")){  
                        unit_check = 0;       
                }
                else{
                        if(!strcmp($1.stringVal,"LOAD") || !strcmp($1.stringVal,"STORE")){
                                LS_Check = 1;
                        }
                        if(!strcmp($1.stringVal,"LOAD_FP")){
                                LFPCount++;
                        }
                        if(!strcmp($1.stringVal,"STORE_FP")){
                                SFPCount++; 
                        }
                        optmp.name = $1.stringVal;
                        optmp.opcode = "";
                        //OpNameStr = optmp.name;  
                        unit_check = 0;       
                        if(strstr($1.stringVal, "PACKW")){
                                optmp.name.clear();
                                optmp.name = $1.stringVal;
                                optmp.name.erase(0,5); 
                        }
                         
                }
        }            
        else if(check_multi == 1 && (strstr($1.stringVal, "_H") && strstr($1.stringVal, "F"))){
                //cout << $1.stringVal << endl;
                optmp.name = $1.stringVal; 
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        } 
}
    | Op OpId
    | Op '-'
    | Op '|'
    | Op '^'
    | Op '*'
    ;
op_no_caret: OpId
        | '-'
        | '|'
        | '*'
        | In
        ;
op: OpId 
       | '-'
       | '|'
       | '^'
       | '*'
       | In
       ;
exp_op: OpId
        | '-'
        | '|'
        | At
        | ColonColon
        | '^'
        | '*'
        ;
pat_op : At{
                if(instr_bits > 1){
                        BitStr=BitStr+"@";
                        instrbits_check = 1;
                }
        }
        | ColonColon
        | '^' {
                if(assemblyString == 3){
                        assemblyStr+=",";
                }
        }
        ;
typ_var: TyVar
;

tyarg: '(' typ_list ')'
     ;


prefix_typ_op: /*emtpy*/ 
             | TwoCaret 
             | '-'
             | '*'
             ;

postfix_typ: atomic_typ 
        ;

typ_no_caret: prefix_typ_op postfix_typ list_1
        ;

list_1: list_1 op_no_caret prefix_typ_op postfix_typ
      | op_no_caret prefix_typ_op postfix_typ 
      | /*empty*/
      ;

typ: prefix_typ_op  postfix_typ list_2
   ;   

list_2: op prefix_typ_op postfix_typ list_2 
      | op prefix_typ_op postfix_typ 
      | /*empty*/ 
      ;

atomic_typ: id
        | Under
        | typ_var
        | lit 
        | Dec
        | Inc
        | id tyarg  
        | Register '(' typ ')' 
        | '(' typ ')'
        | '(' typ ',' typ_list ')' 
        | '{' num_list '}'
        | LcurlyBar num_list RcurlyBar /*lost*/
        | '{' kopt '.' typ '}' 
        | '{' kopt ',' typ '.' typ '}'
        ;

num_list: Num ',' num_list
        | Num
        ;
 
typ_list: typ
        | typ ',' 
        | typ ',' typ_list 
        ; 
kind: Int 
    | TYPE
    | Order 
    | Bool
    ;
 

kid_list: TyVar
        | TyVar kid_list
        ;

kopt: '(' Constant kid_list ':' kind ')'
         | '(' kid_list ':' kind ')'
         | typ_var
         ;

kopt_list: kopt
         | kopt kopt_list
         ;

quantifier: kopt_list ',' typ
             | kopt_list
             ;


/* effect: id */

id_list: id
        | id ',' id_list
        ;
effect_set: '{' id_list '}'
        | Pure
        ;

typschm: typ MinusGt typ
        | Forall quantifier '.' typ MinusGt typ
        | typ Bidir typ
        | Forall quantifier '.' typ Bidir typ
        ;

pat1: atomic_pat list_3
        ;

list_3: pat_op atomic_pat 
      | pat_op atomic_pat list_3
      | /*empty*/
      ;

pat: pat1
   | Attribute pat
   | pat1 As typ
   ;
pat_list: pat
        | pat ','
        | pat ',' pat_list
        ;

atomic_pat: Under
        | lit
        | id
        | typ_var
        | id Unit
        | id '[' Num ']'
        | id '[' Num DotDot Num ']'
        | id '(' pat_list ')'
        | atomic_pat ':' typ_no_caret
        | '(' pat ')'
        | '(' pat ',' pat_list ')'
        | '[' pat_list ']'
        | LsquareBar RsquareBar
        | LsquareBar pat_list RsquareBar
        | Struct '{' fpat_list '}'
        ;
fpat: id '=' pat
         | id
         | Under
         ;

fpat_list: fpat
        | ',' fpat fpat_list
        ;

lit: True  { 
        if(mext_MULcheck == 2){
                Mexttmp.name += "True,";
        } 
        if(mext_MULcheck1 == 1){
                Mexttmp1.name += "True,";
        } 
   }
   | False { 
        if(mext_MULcheck == 2){
                Mexttmp.name += "False,";
        } 
        if(mext_MULcheck1 == 1){
                Mexttmp1.name += "False,";
        } 
   }
   | Unit
   | Num { 
        if(immbitcheck != 0){
          immbit = $1.ival;
        }
        else if(instr_bits > 1 && imm_nobits == 1){
                if(immbit == 0){
                        BitStr = BitStr + to_string($1.ival);
                }
                imm_nobits = 0;
        }
          immbitcheck = 0;
        }  
   | Undefined 
   | Bitzero  
   | Bitone  
   | Bin_literal {
        if(mext_MULcheck == 2){
                //cout << "111" << endl;
                Mexttmp.opcode = $1.stringVal;
                Mexttmp.opcode.erase(0,2);
                Mext_insert(MextTable,Mexttmp);
                Mexttmp.name.clear();
                Mexttmp.name = "";
        }
        else if(oplistcheck > 0 && instr_bits <= 1){
                optmp.opcode = $1.stringVal;
                optmp.opcode.erase(0,2);
                //printf("\n%s\n",$1.stringVal);
                optmp.bitcode = "";
                op_insert(table,optmp);
        }
        else if(instr_bits > 1){
                string s = $1.stringVal;
                s.erase(0,2);
                BitStr = BitStr + s;
                optmp.opcode = "";
        }
}
   | Hex_literal
   | STRING_LITERAL {
                if(mext_MULcheck1 == 1 && strstr($1.stringVal, "mul")){
                        //cout << $1.stringVal << endl; 
                        Mexttmp1.opcode = $1.stringVal;
                }
                if(assemblyString == 3){
                        assemblyStr+=$1.stringVal;
                }
        }
   ;

internal_loop_measure:
                        | /*empty*/
                        | TerminationMeasure '{' exp '}'
                        ;

exp: exp0
   | Attribute exp
   | exp0 '=' exp
   | Let_ letbind In exp
   | Var atomic_exp '=' exp In exp
   | '{' block '}'
   | Return exp
   | Throw exp
   | If_ exp Then exp Else exp
   | If_ exp Then exp
   | Match exp '{' case_list '}'
   | Try exp Catch '{' case_list '}'
   | Foreach '(' id ID atomic_exp ID atomic_exp By atomic_exp In typ ')' exp
   | Foreach '(' id ID atomic_exp ID atomic_exp By atomic_exp ')' exp
   | Foreach '(' id ID atomic_exp ID atomic_exp ')' exp
   | Repeat internal_loop_measure exp Until exp
   | While internal_loop_measure exp Do exp
   ;

prefix_op: /*empty*/
        | TwoCaret
        | '-'
        | '*'
        | '~' /*lost*/
        ;

exp0: prefix_op atomic_exp list_4
    ;

list_4: /*empty*/
        | exp_op prefix_op atomic_exp
        | exp_op prefix_op atomic_exp list_4
        ;

case: pat EqGt exp
    | pat If_ exp EqGt exp
    ;

case_list: case
        | case ','
        | case ',' case_list
        ;

block:exp 
     | exp ';'
     | Let_ letbind
     | Let_ letbind ';'
     | Let_ letbind ';' block
     | Var atomic_exp '=' exp
     | Var atomic_exp '=' exp ';'
     | Var atomic_exp '=' exp ';' block
     | exp ';' block
     ;

letbind: pat '=' exp
        ;

atomic_exp: atomic_exp ':' atomic_typ
               | lit
               | id MinusGt id Unit
               | id MinusGt id '(' exp_list ')'
               | atomic_exp '.' id Unit
               | atomic_exp '.' id '(' exp_list ')'
               | atomic_exp '.' id
               | id
               | typ_var
               | Ref id
               | id Unit
               | id '(' exp_list ')'
               | Sizeof '(' typ ')'
               | Constraint '(' typ ')'
               | atomic_exp '[' exp ']'
               | atomic_exp '[' exp DotDot exp ']'
               | atomic_exp '[' exp ',' exp ']'
               | Struct '{' fexp_exp_list '}'
               | '{' exp With fexp_exp_list '}'
               | '[' ']'
               | '[' exp_list ']'
               | '[' exp With vector_update_list ']'
               | LsquareBar RsquareBar
               | LsquareBar exp_list RsquareBar
               | '(' exp ')'
               | '(' exp ',' exp_list ')'
               | Assert '(' exp ')'
               | Assert '(' exp ',' exp ')'
               ;

fexp_exp: atomic_exp '=' exp
        | id
        ;

fexp_exp_list: fexp_exp
             | fexp_exp ','
             | fexp_exp ',' fexp_exp_list
             ;

exp_list: exp
        | exp ','
        | exp ',' exp_list
        ;

vector_update: atomic_exp '=' exp
             | atomic_exp DotDot atomic_exp '=' exp
             | id
             ;

vector_update_list: vector_update
                | vector_update ',' vector_update_list
                ;

funcl_annotation: Private
                | Attribute
                ;

funcl_patexp: pat '=' exp
            | '(' pat If_ exp ')' '=' exp
            ;
funcl_patexp_typ: pat '=' exp
                     | pat MinusGt typ '=' exp
                     | Forall quantifier '.' pat MinusGt typ '=' exp
                     | '(' pat If_ exp ')' '=' exp
                     | '(' pat If_ exp ')' MinusGt typ '=' exp
                     | Forall quantifier '.' '(' pat If_ exp ')' MinusGt typ '=' exp
                     ;

funcl: funcl_annotation id funcl_patexp
          | id funcl_patexp
          ;
          
funcl_list: funcl
        | funcl And funcl_list
        ;

funcls: funcl_annotation id funcl_patexp_typ
           | id funcl_patexp_typ
           | funcl_annotation id funcl_patexp And funcl_list
           | id funcl_patexp And funcl_list
           ;

funcl_typ: Forall quantifier '.' typ
         | typ
         ;

index_range: paren_index_range At index_range
           | paren_index_range
           ;

paren_index_range: '(' paren_index_range At index_range ')'
                 | atomic_index_range
                 ;

atomic_index_range: typ
                  | typ DotDot typ
                  | '(' typ DotDot typ ')'
                  ;

r_id_def: id ':' index_range
        ;

r_def_body: r_id_def
          | r_id_def ','
          | r_id_def ',' r_def_body
          ;

param_kopt: typ_var ':' kind
          | typ_var
          ;
param_kopt_list: param_kopt
               | param_kopt ',' param_kopt_list
               ;
typaram: '(' param_kopt_list ')' ',' typ
       | '(' param_kopt_list ')'
       ;
enum_bar: id 
        | id '|' enum_bar
        ;

type_def: Typedef id typaram '=' typ
        | Typedef id '=' typ
        | Typedef id typaram MinusGt kind '=' typ
        | Typedef id ':' kind '=' typ
        | Struct id '=' '{' struct_fields '}'
        | Struct id typaram '=' '{' struct_fields '}'
        | Enum id '=' enum_bar
        | Enum id '=' '{' enum_comma '}'
        | Enum id With enum_functions '=' '{' enum_comma '}'
        | Union id '=' '{' type_unions '}'
        | Union id typaram '=' '{' type_unions '}'
        | Bitfield id ':' typ '=' '{' r_def_body '}'
        ;

enum_functions: id MinusGt typ ',' enum_functions
              | id MinusGt typ ','
              | id MinusGt typ
              ;

enum_comma: id
          | id ','
         | id EqGt exp 
         | id EqGt exp ','
         | id ',' enum_comma
         | id EqGt exp ',' enum_comma
         ;

struct_field: id ':' typ
            ;

struct_fields: struct_field
             | struct_field ','
             | struct_field ',' struct_fields
             ;

type_union: Private type_union
          | Attribute type_union
          | id ':'  typ 
          | id ':' '{' struct_fields '}'
          ;

type_unions: type_union
           | type_union ','
           | type_union ',' type_unions
           ;

rec_measure: '{' pat EqGt exp '}'
           ;

fun_def: Function_ funcls
        | Function_ rec_measure funcls
        ;

mpat: atomic_mpat_list
        | atomic_mpat As id
        ;
atomic_mpat_list: atomic_mpat  
                | atomic_mpat pat_op atomic_mpat_list
                ;
mpat_list: mpat
         | mpat ',' mpat_list
         ;

atomic_mpat: lit
        | id  
        | id '[' Num ']'
        | id '[' Num DotDot Num ']'
        | id Unit
        | id  '(' mpat_list ')' 
        | '(' mpat ')'
        | '(' mpat ',' mpat_list ')'
        | '[' mpat_list ']'
        | LsquareBar RsquareBar
        | LsquareBar mpat_list RsquareBar
        | atomic_mpat ':' typ_no_caret
        | Struct '{' fmpat_list '}'
        ;

fmpat: id '=' mpat
     | id
     ;
fmpat_list: fmpat
          | fmpat ',' fmpat_list
          ;

mpexp: mpat
     | mpat { if(encdec_IF == 1)encdec_IF = 2; }If_ exp
     ;

mapcl: Attribute mapcl 
     | mpexp Bidir {
        instrbits_check = 1;
        if(instr_bits == 1)
                instr_bits++;
        check_multi = 0;
        if(assemblyString == 2){
                assemblyString=3;
        }
     } mpexp {if(mext_MULcheck1 == 1){
                        Mext_insert(MextTable1,Mexttmp1);
                        Mexttmp1.name.clear();
                        Mexttmp1.name = "";
                 }} 
     | mpexp EqGt exp  
     | Forwards mpexp EqGt exp
     | Backwards mpexp EqGt exp
     ;

mapcl_list: mapcl 
        | mapcl ','     
        | mapcl ',' mapcl_list {mext_MULcheck = 0;}
        ;

map_def: Mapping id '=' '{' mapcl_list '}'
        | Mapping id ':' typschm '=' '{' mapcl_list '}' {
                oplistcheck = 0;
                mapop = 0;
        }
        ;

let_def: Let_ letbind
        ;


pure_opt: Monadic
        | Pure
        ;

extern_binding: id ':' STRING_LITERAL
              | Under ':' STRING_LITERAL
              ;
extern_binding_list: extern_binding
                   | extern_binding ',' extern_binding_list
                   ; 
externs: /*empty*/
        | '=' STRING_LITERAL
        | '=' '{' extern_binding_list '}'
        | '=' pure_opt STRING_LITERAL
        | '=' pure_opt '{' extern_binding_list '}'
        ;  

val_spec_def: Val STRING_LITERAL ':' typschm
        | Val id externs ':' typschm
        ;  

register_def: Register id ':' typ
            | Register id ':' typ '=' exp
            ;

default_def: Default kind Inc
        | Default kind Dec
        ;

scattered_def: Scattered Enum id
                | Scattered Union id typaram  
                | Scattered Union id
                | Scattered Function_ id 
                | Scattered Mapping id
                | Scattered Mapping id ':' funcl_typ
                | Enum Clause id '=' id
                | Function_ Clause funcl
                | Union {
                        if(assemblyString == 4){ 
                                create_opccoutput(opcctable,opccoutputtable,table);
                        }
                        assemblyString = 0;
                }Clause{                             
                        op_new_table(symtable_stack,table);
                        opcc_new_table(opccsymtable_stack,opcctable);
                        opcc_new_table(opccTmpsymtable_stack,opccTmptable);
                        immbitcheck = 1;
                        mapop = 0;
                        immbit = 0;
                        oplistcheck = 0;
                 }id '=' { unit_check =1; } type_union 
                | Mapping Clause ID {
                        oplistcheck = 0;
                        if(strcmp($3.stringVal,"encdec")==0){
                                //cout << "123" <<endl;
                                encdec_createcheck = 1;
                                instr_bits = 1;
                                check_multi = 1;
                                encdec_IF = 1;
                                FPCount++;  
                        }
                        if(strcmp($3.stringVal, "assembly")==0){   
                               // cout << Getencdecop <<endl;
                               assemblyString = 1;
                                if(mext_MULcheck1 != 0 ){ 
                                        Mext_insertOP(table,MextTable,MextTable1);
                                        Getencdecop = 1;
                                } 
                                LS_Check = 0; 
                                Getencdecop = 0;
                                addshamt = 0; 
                                BitStr.clear();  
                                LFPCount = 0;
                                SFPCount = 0;
                                mext_MULcheck = 0;
                                mext_MULcheck1 = 0; 
                                Mext_U = 0;
                                csr_check =0;
                                encdec_createcheck = 0;
                        }
                        
                } '=' mapcl{
                       // if(encdec_createcheck == 0){
                        //      op_dump(table);
                                create_output(opcctable,opccoutputtable,instrBitTable,BitStr,assemblyStr,table,Getencdecop,immbit,addshamt,LS_Check,Mext_U,csr_check);     
                        //}
                               
                        Mext_U = 0;
                        encdec_IF = 0;
                        mapop = 0;
                        immbitcheck = 0;
                        immbit = 0; 
                        oplistcheck = 0; 
                        optmp.bitcode = BitStr;
                        mext_MULcheck = 0;
                        mext_MULcheck1 = 0;
                        FPCount = 0; 
                          
                        //cout << optmp.opcode << endl;
                        //cout << optmp.bitcode << endl; 
                        if(instr_bits > 1)
                                op_insert(table,optmp);      
                        instr_bits = 0;                   
                        //printf("%s",BitStr.c_str());
                        if(Getencdecop==0){
                                BitStr.clear();
                        }
                        if(assemblyString == 3){
                                create_opccTable(table,opcctable,assemblyStr,instType);
                                assemblyStr.clear();
                                instType.clear();
                                assemblyString =4;
                        }
                }
                | End id
                ;

loop_measure: Until exp
        | Repeat exp
        | While exp
        ;
loop_measure_list: loop_measure
                 | loop_measure ',' loop_measure_list
                 ;

subst: typ_var '=' typ
     | id '=' id
     ;
subst_list: subst
        | subst ',' subst_list
        ;
instantiation_def: Instantiation id
                 | Instantiation id With subst_list
                 ;

overload_def: Overload id '=' '{' id_list'}'
            | Overload id '=' enum_bar
            ; 
 

def_aux: fun_def
            | map_def
            | FIXITY
            | val_spec_def 
            | instantiation_def
            | type_def 
            | let_def
            | register_def
            | overload_def 
            | scattered_def
            | default_def
            | LINE_DIRECTIVE 
            | TerminationMeasure id pat '=' exp
            | TerminationMeasure id loop_measure_list
            ;

def: Private def
   | Attribute def
   | def_aux  
   ;
defs_list: def 
         | def defs_list
         ;
file: defs_list
    | /*empty*/
    ;
%% 
void yyerror (string s) 
{
    cerr << "line " << linenum << ": \033[1;31m" << s << "\033[1;0m" << endl;
    exit(1); 
}
 
int main() 
{  
    yyparse();
    create_opccoutput(opcctable,opccoutputtable,table);
    //printf("%d\n",immbit);    
    //op_dump(table);
    //opcc_dump(opcctable);
    //Mext_dump(MextTable);      
    //Mext_dump(MextTable1); 
    opccoutput_dump(opccoutputtable);      
    output_dump(instrBitTable);       
    cout << "finish" << endl;
    return 0;
}   
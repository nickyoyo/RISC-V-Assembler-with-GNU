#include "symboltable.h"

using namespace std;

// memcpy(X,X+6,sizeof(X)-6);
void op_dump(OPtable_map table)
{
    cout << "OP Table" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << "name: " << i->second.name << " opcode: " << i->second.opcode << " bitcode: " << i->second.bitcode << endl;
    }
}

void opcc_dump(opcctable_map table)
{
    cout << "OPcc Table" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << "name: " << i->second.name << " instrType: " << i->second.instType << " assembleString: " << i->second.assembleString << endl;
    }
}

void Mext_dump(Mexttable_map table)
{
    cout << "Mext Table" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << "name: " << i->second.name << " opcode: " << i->second.opcode << endl;
    }
}

void output_dump(Output_map table)
{
    // cout << "Output Table" << endl;
    // for (auto i = table.begin(); i != table.end(); i++) {
    //     cout << "str: " << i->second.str << endl;
    // }
    int dec = 0;
    std::ofstream file("riscv-opc.h",ios::app);
    //std::ofstream file("riscv-opc.h");
   // file << "#ifndef RISCV_ENCODING_vext_H\n";
   // file << "#define RISCV_ENCODING_vext_H\n";
    // file << "#define MATCH_GREVI 0x68005013\n";
    // file << "#define MASK_GREVI  0xfc00707f\n";
    // file << "#define MATCH_GORCI 0x28005013\n";
    // file << "#define MASK_GORCI  0xfc00707f\n";
    // file << "#define MATCH_SHFLI 0x8001013\n";
    // file << "#define MASK_SHFLI  0xfe00707f\n";
    // file << "#define MATCH_UNSHFLI 0x8005013\n";
    // file << "#define MASK_UNSHFLI  0xfe00707f\n";
    
    
    for (auto i = table.begin(); i != table.end(); i++) {
        if(i->second.str.find("DECLARE_INSN") != std::string::npos && dec == 0){
            dec++;
            //file << "#endif\n";
            //file << "#ifdef DECLARE_INSN_VEXT\n";
        }
        file << i->second.str;
    }
     //file << "#endif\n";
     file.close();

}

void opccoutput_dump(opccOutput_map table)
{
    // cout << "opccOutput Table" << endl;
    // for (auto i = table.begin(); i != table.end(); i++) {
    //     cout << "str: " << i->second.str << endl;
    // }
    // string riscv_gpr_names_numeric="";
    // string riscv_fpr_names_numeric="";
    // string riscv_vecr_names_numeric="";
    // int i;
    // for(i = 0 ; i < 32 ; i++){
    //     string gTmp =  "\"x"+  to_string(i) ;
    //     gTmp += "\"";
    //     string fTmp =  "\"f"+  to_string(i);
    //     fTmp += "\"";
    //     string vTmp =  "\"v"+  to_string(i) ;
    //     riscv_gpr_names_numeric += gTmp;
    //     riscv_fpr_names_numeric += fTmp;
    //     riscv_vecr_names_numeric += vTmp;
    //     if(i < 31){
    //         riscv_gpr_names_numeric += ",";
    //         riscv_fpr_names_numeric += ",";
    //         riscv_vecr_names_numeric += ",";
    //     }
    //     if(i % 8 == 7){
    //         riscv_gpr_names_numeric += "\n";
    //         riscv_fpr_names_numeric += "\n";
    //         riscv_vecr_names_numeric += "\n";
    //     }
    // }
    
    //cout << riscv_fpr_names_numeric << endl;
    std::ofstream file("riscv-opc.c",ios::app);
    //std::ofstream file("riscv-opc.c");
    //file << include;
   // file <<"const struct riscv_opcode riscv_opcodes[] =\n{\n";
    for (auto i = table.begin(); i != table.end(); i++) {
        file << i->second.str;
    }
    file <<Terminate;
    file <<inst_type;
    file <<Terminate;
    
    file.close();

}

void Mext_insert(Mexttable_map &table, Mext_sv entry)
{
    bool success = false;

    if (table.find(entry.name) == table.end()){
        table.emplace(entry.name, entry);
        success = true;
    }
   
  //  return success;
}


void op_insert(OPtable_map &table, OPtable_sv entry)
{
    bool success = false;
    if (table.find(entry.name) == table.end()){
        table.emplace(entry.name, entry);
        success = true;
    }
    else{
        // if(entry.name == "ZEXTH"){
        //     table.emplace(entry.name, entry);
        // }
        for (auto i = table.begin(); i != table.end(); i++) 
            if(i->second.name == entry.name){
               i->second.bitcode = entry.bitcode;
            }
    } 
    //cout << entry.name <<endl;
    if(entry.name == "DIV" || entry.name == "REM"){
        OPtable_sv tmp;
        tmp.name = entry.name+"u";
        tmp.opcode = entry.opcode;
        tmp.bitcode = entry.bitcode;
        table.emplace(tmp.name, tmp);
    }
    if(entry.name == "DIVW" || entry.name == "REMW"){
        OPtable_sv tmp;
        entry.name.pop_back();
        string tmpstr = entry.name;
        tmp.name = entry.name+"uw";
        tmp.opcode = entry.opcode;
        tmp.bitcode = entry.bitcode;
        table.emplace(tmp.name, tmp);
    }
    int count = 2;
    if(entry.name == "vmv"){
        for(int i = 0; i<4 ;i++){
            int result = std::pow(count, i);
            OPtable_sv tmp;
            string tmpstr = entry.name;
            tmp.name = tmpstr + to_string(result);
            tmp.name += "r_v";
            tmp.opcode = entry.opcode;
            tmp.bitcode = entry.bitcode;
            table.emplace(tmp.name, tmp);
        }
    }
  //  return success;
}

void opcc_insert(opcctable_map &table, opcctable_sv entry){
    table.emplace(entry.name, entry);
}

void Mext_insertOP(OPtable_map &table,Mexttable_map &Mexttable1,Mexttable_map &Mexttable2){
    OPtable_sv Mext;
   
    for (auto i = Mexttable1.begin(); i != Mexttable1.end(); i++) {
        for (auto j = Mexttable2.begin(); j != Mexttable2.end(); j++) {

            if(i->second.name == j->second.name ){
              //    cout << i->second.name << "---" << j->second.name <<endl;
                Mext.name = j->second.opcode;
                Mext.bitcode = "";
                Mext.opcode = i->second.opcode;
                op_insert(table,Mext);
                Mext.name.clear();
                Mext.opcode.clear();
            }
        }
    }
}

bool output_insert(Output_map &table, Output_sv entry)
{
    bool success = false;
    if (table.find(entry.str) == table.end()){
        table.emplace(entry.str, entry);
        success = true;
    }
    return success;
}

bool opccouput_insert(opccOutput_map &table, opccOutput_sv entry)
{
    bool success = false;
    if (table.find(entry.str) == table.end()){
        table.emplace(entry.str, entry);
        success = true;
    }
    return success;
}

string tohex(string str){
    //字串轉16進制
    std::ostringstream oss;
    std::string packet;
    packet += str;
	oss << std::hex << std::hex << std::setw(8) << std::bitset<32>{packet}.to_ulong() << '\n';
    string asHex { oss.str() };
    asHex.erase(0,asHex.find_first_not_of(" "));
    asHex = "0x" + asHex; 
    int min_length = 10; // "0x" + 8 digits
    if (asHex.length() <= min_length) {
        asHex.insert(2, min_length - asHex.length()+1, '0'); // 在 "0x" 后面插入填充 '0'
    }
	//cout << asHex << '\n';
    return asHex;
}

std::vector<std::string> splitString(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t startPos = 0;
    size_t endPos = 0;
    while ((endPos = str.find(delimiter, startPos)) != std::string::npos) {
        tokens.push_back(str.substr(startPos, endPos - startPos));
        startPos = endPos + delimiter.length();
    }
    tokens.push_back(str.substr(startPos));
    return tokens;
}

void create_output(opcctable_map &opcctable,opccOutput_map &opccoutouttable,Output_map &table,string BitString,string assembleStr,OPtable_map &optable,int check,int immbitnum,int addshamt,int LS_Check,int Mext_U,int csr_check)
{   
    Output_sv strmatch;
    strmatch.str = strmatch.str + "#define MATCH_";
    Output_sv strmask;
    strmask.str = strmask.str + "#define MASK_";
    Output_sv strdefine;
    strdefine.str = strdefine.str + "DECLARE_INSN(";
 
    string LS_sizetablecode[][4] = {"00","01","10","11"};
    string LS_sizetable[][4] = {"B","H","W","D"};
    string U_Bit[][1] = {"0","1"};
    int LSCount = 0;int del = 0;int UCount = 0;
    
    if(Mext_U == 1){
        for (auto i = optable.begin(); i != optable.end(); i++){
                OPtable_sv Mext;

                if(i->second.name.find("U") == std::string::npos){
                    if(i->second.name.find("W") != std::string::npos){
                        Mext.name = i->second.name;
                        Mext.name.pop_back();
                        Mext.name += "UW";
                    }
                    else{
                        Mext.name = i->second.name+"U";
                    }
                }
                Mext.opcode = "";
                Mext.bitcode = i->second.bitcode;
                op_insert(optable,Mext);
                break;
        }
    }

    if(csr_check == 1){
        for (auto i = optable.begin(); i != optable.end(); i++){
                
                OPtable_sv CSR;

                if(i->second.name != "CSR" && i->second.name.find("i") == std::string::npos){
                        CSR.name = i->second.name;
                        CSR.name += "i";
                        CSR.opcode = i->second.opcode;
                        CSR.bitcode = i->second.bitcode;
                        op_insert(optable,CSR);
                }
        }
    }

    if(check == 1){
        for (auto i = optable.begin(); i != optable.end(); i++) 
            i->second.bitcode = BitString;
    }  

    for (auto i = optable.begin(); i != optable.end(); i++){
        if(i->second.name != "AMO" && (i->second.name.find("AMO") != std::string::npos &&i->second.name.find("_") == std::string::npos )){
                del = 1;
                string AM_name;
                string AM_bitcode;
                AM_name = i->second.name + "_";
                AM_bitcode = i->second.bitcode;

                OPtable_sv AM;
                for (int k = 0;k < 4; k++){
                    AM.name = AM_name + LS_sizetable[0][k];
                    AM.bitcode = AM_bitcode;
                    AM.opcode = i->second.opcode;
                    op_insert(optable,AM);
                }
        }
        if(i->second.name == "LOADRES"){
                del = 1;
                string LR_name;
                string LR_bitcode;
                LR_name = "LR_";
                LR_bitcode = i->second.bitcode;

                OPtable_sv LR;
                for (int k = 0;k < 4; k++){
                    LR.name = LR_name + LS_sizetable[0][k];
                    LR.bitcode = LR_bitcode;
                    LR.opcode = i->second.opcode;
                    op_insert(optable,LR);
                }
        }
        if(i->second.name == "STORECON"){
                del = 1;
                string SC_name;
                string SC_bitcode;
                SC_name = "SC_";
                SC_bitcode = i->second.bitcode;

                OPtable_sv SC;
                for (int k = 0;k < 4; k++){
                    SC.name = SC_name + LS_sizetable[0][k];
                    SC.bitcode = SC_bitcode;
                    SC.opcode = i->second.opcode;
                    op_insert(optable,SC);
                }
        }
    }
       
    if(LS_Check == 1){
        for (auto i = optable.begin(); i != optable.end(); i++){
            if(i->second.name == "LOAD"){
                    string LD_name;
                    string LD_bitcode;
                    LD_name = "L";
                    LD_bitcode = i->second.bitcode;

                    OPtable_sv LD;
                for (int i = 0; i < 4; i++){
                    LD.name = LD_name + LS_sizetable[0][i];
                    LD.bitcode = LD_bitcode;
                    LD.opcode = "";
                    op_insert(optable,LD);
                }
            }
            if(i->second.name == "STORE"){
                string SD_name;
                string SD_bitcode;
                SD_name = "S";
                SD_bitcode = i->second.bitcode;

                OPtable_sv SD;
                for (int i = 0; i < 4; i++){
                    SD.name = SD_name + LS_sizetable[0][i];
                    SD.bitcode = SD_bitcode;
                    SD.opcode = "";
                    op_insert(optable,SD);
                }
            }
        }
    }
    //op_dump(optable);
    // cout << BitString <<endl;
       
        for (auto i = optable.begin(); i != optable.end(); i++) {
            if(i->second.name.find("AMO") != std::string::npos && i->second.name.find("_") == std::string::npos || i->second.name == "vmv" || i->second.name == "VFUNARY0" || i->second.name == "VFWUNARY0" || i->second.name == "VFNUNARY0" || i->second.name == "VFUNARY1" || i->second.name =="FVFMATYPE"  || i->second.name == "FWVFMATYPE" || i->second.name == "FVFMTYPE"){
                i++;
                if(i == optable.end())
                    break;
            }
            if(i->second.name != "STORE" && i->second.name != "LOAD" && i->second.name != "MUL" && i->second.name != "CSR"){
               //cout << i->second.name <<endl;
                string smatch;
                std::vector<std::string> tokensmatch = splitString(i->second.bitcode, "@");
                for (const auto& token : tokensmatch) {
                    if(token == "rs1" || token == "vs1"){
                        smatch += rs1;
                    }
                    else if(token == "rs2" || token == "vs2"){
                        smatch += rs2;
                    }
                    else if(token == "rs3"){
                        smatch += rs2;
                    }
                    else if(token == "rd" || token == "vd"){
                        smatch += rs3;
                    }
                    else if(token == "csr"){
                        smatch += csr;
                    }
                    else if(token == "is_imm"){
                        if(i->second.name.find("i") == std::string::npos){
                            smatch += "0";
                        }
                        else{
                            smatch += "1";
                        }
                    }
                    else if(token == "shamt"){
                        smatch += shamt;
                        if(addshamt == 1){
                        smatch += "0"; 
                        }
                    }
                    else if(token == "pred"){
                        if(i->second.name == "FENCE"){
                            smatch += "0000";
                        }
                        else{
                            smatch += pred;
                        }
                    }
                    else if(token == "succ"){
                        if(i->second.name == "FENCE"){
                            smatch += "0000";
                        }
                        else{
                            smatch += succ;
                        }
                    }
                    else if(token == "op"){
                        smatch += i->second.opcode;
                    }
                    else if(token == "rm"){
                        smatch += rm;
                    }
                    else if(token == "vm"){
                        smatch += vm;
                    }
                    else if(token == "s"){
                        if(i->second.name.find("u") != std::string::npos){
                            smatch += "1";
                        }
                        else{
                            smatch += "0";
                        }
                    }
                    else if(token == "size"){
                        if(i->second.name.find("_B") != std::string::npos){
                            smatch += "00";
                        }
                        else if(i->second.name.find("_H") != std::string::npos){
                            smatch += "01";
                        }
                        else if(i->second.name.find("_W") != std::string::npos){
                            smatch += "10";
                        }
                        else if(i->second.name.find("_D") != std::string::npos){
                            smatch += "11";
                        }
                        else{
                            smatch += LS_sizetablecode[0][LSCount];
                            LSCount++;
                        }
                    }
                    else if(token == "is_unsigned"){
                        smatch += "0";
                    }
                    else if(token == "aq"){
                        smatch += "0";
                    }
                    else if(token == "rl"){
                        smatch += "0";
                    }
                    else if(token.find("imm") != std::string::npos){
                        //cout << i->second.name <<endl;
                        if(token == "simm"){
                            if(i->second.name.find("vmv") != std::string::npos && i->second.name.find("r_v") != std::string::npos){
                                if(i->second.name.find("1") != std::string::npos){
                                    smatch += "00000";
                                }
                                else if(i->second.name.find("2") != std::string::npos){
                                    smatch += "00001";
                                }
                                else if(i->second.name.find("4") != std::string::npos){
                                    smatch += "00011";
                                }
                                else if(i->second.name.find("8") != std::string::npos){
                                    smatch += "00111";
                                }
                            }
                            else{
                                string newtoken;
                                int count = 5;
                                while(count--)
                                    newtoken += "0";
                                smatch += newtoken;
                            }
                        }
                        else if(token == "imm"){
                            string newtoken;
                            int count = immbitnum;
                            while(count--)
                                newtoken += "0";
                            smatch += newtoken;
                        }
                        else{
                            string newtoken1;
                            newtoken1.clear();
                            string tokennum = token;
                            tokennum.erase(0,3);
                            
                            int count = std::stoi(tokennum);
                            
                            while(count--){
                                newtoken1 += "0";
                            }
                            smatch += newtoken1;
                        //  cout << smask << endl;
                        }
                    }
                    else{
                        if(token.find("_")){
                            std::vector<std::string> tokentmp = splitString(token, "_");
                            for (const auto& token1 : tokentmp)
                                 smatch += token1;
                        }
                        else{
                            smatch += token;
                        }
                    }
                }
                    
                string smask;
                std::vector<std::string> tokensmask = splitString(i->second.bitcode, "@");
                for (const auto& token : tokensmask) {
                    if(token == "rs1" || token == "vs1"){
                        smask += rs1;
                    }
                    else if(token == "rs2" || token == "vs2"){
                        smask += rs2;
                    }
                    else if(token == "rs3"){
                        smask += rs3;
                    }
                    else if(token == "rd" || token == "vd"){
                        smask += rd;
                    }
                    else if(token == "csr"){
                        smask += csr;
                    }
                    else if(token == "is_imm"){
                        smask += "1";
                    }
                    else if(token == "shamt"){
                        smask += shamt;
                        if(addshamt == 1){
                        smask += "0"; 
                        }
                    }
                    else if(token == "aq"){
                        smask += "0";
                    }
                    else if(token == "rl"){
                        smask += "0";
                    }
                    else if(token == "pred"){
                        smask += maskpred;
                    }
                    else if(token == "succ"){
                        smask += masksucc;
                    }
                    else if(token == "rm"){
                        smask += maskrm;
                    }
                    else if(token == "vm"){
                        smask += vm;
                    }
                    else if(token == "op"){
                        string newtoken;
                        int count = i->second.opcode.length();
                            while(count--)
                                newtoken += "1";
                        smask += newtoken;
                    }
                    else if(token == "size"){
                        smask += "11";
                    }
                    else if(token == "is_unsigned"){
                        smask += "1";
                    }
                    else if(token.find("imm") != std::string::npos){
                        if(token == "simm" && (i->second.name == "VMV1R_V" || i->second.name == "VMV2R_V" || i->second.name == "VMV4R_V" || i->second.name == "VMV8R_V")){
                            string newtoken;
                            int count = 5;
                            while(count--)
                                newtoken += "1";
                            smask += newtoken;
                        }
                        else if(token == "simm"){
                            string newtoken;
                            int count = 5;
                            while(count--)
                                newtoken += "0";
                            smask += newtoken;
                        }
                        else if(token == "imm"){
                            string newtoken;
                            int count = immbitnum;
                            while(count--)
                                newtoken += "0";
                            smask += newtoken;
                        }
                        else{
                            string newtoken1;
                            newtoken1.clear();
                            string tokennum = token;
                            tokennum.erase(0,3);
                            int count = std::stoi(tokennum);
                            while(count--){
                                newtoken1 += "0";
                            }
                            smask += newtoken1;
                        }
                    }
                    else{
                        string newtoken;
                        int count = token.length();
                        if(token.find("_") != std::string::npos){
                            count--;
                        }
                        while(count--)
                            newtoken += "1";
                        smask += newtoken;
                    }
                }
                if(i->second.name == "FENCE"){
                    smask.clear();
                    smask += "00000000000000000111000001111111";
                }
                if(i->second.name == "FENCEI"){
                    smask.clear();
                    smask += "00000000000000000111000001111111";
                }
                if(i->second.name == "FENCE_TSO"){
                    smask.clear();
                    smask += "11111111111100000111000001111111";
                }
                cout << "smatch : " << smatch << endl;
                cout << "smask : " << smask << endl;
                string matchhex = tohex(smatch);
                string maskhex = tohex(smask);
                transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::toupper);
                Output_sv match;
                match.str = match.str + strmatch.str + i->second.name;
                Output_sv mask;
                mask.str = mask.str + strmask.str + i->second.name;
                Output_sv define;
                string masktmp = mask.str;
                string matchtmp = match.str;
                transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::tolower);
                define.str = define.str + strdefine.str + i->second.name + ", " + matchtmp.erase(0,8) + ", " + masktmp.erase(0,8) + ")\n";
                match.str = match.str + " " + matchhex;
                mask.str = mask.str + " " + maskhex;
             cout << i->second.name << "-match : "  << matchhex << endl;
             cout << i->second.name << "-mask : " << maskhex << endl;
                output_insert(table,define);
                output_insert(table,mask);
                output_insert(table,match);
            }
            
        }
        //op_dump(optable);
        //cout << assembleStr << endl;
        //opcc_dump(opcctable);
}

void create_opccoutput(opcctable_map &opcctable,opccOutput_map &opccoutouttable,OPtable_map &optable){
    /* name, xlen, isa, operands, match, mask, match_func, pinfo.  */
    opcc_dump(opcctable);
    int rmCheck = 0;
    for (auto i = opcctable.begin(); i != opcctable.end(); i++) {
        while(i->second.instType == "AMO" && i->second.name.find("_") == std::string::npos || i->second.name == "VMV" || i->second.name == "VFUNARY0" || i->second.name == "VFWUNARY0" || i->second.name == "VFNUNARY0" || i->second.name == "VFUNARY1" || i->second.name == "FVFMATYPE" || i->second.name == "FWVFMATYPE" || i->second.name == "FVFMTYPE"){
            i++;
            if(i == opcctable.end())
                    break;
        }
        if(i == opcctable.end())
                    break;
        if(rmCheck == 1){
            rmCheck++;
            i--;
        }
        if(i->second.name != "LOADRES" && i->second.name != "STORECON" && i->second.name != "STORE" && i->second.name != "LOAD" && i->second.name != "CSR"){
            //init
            string name="";
            string xlen="";
            string isa="";
            string operands="";
            string match = "";
            string mask = "";
            string match_func="";
            string pinfo="";
            
            //name
            transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::tolower);
            if(i->second.instType == "LOADRES" || i->second.instType == "STORECON" || i->second.instType == "AMO" || (i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE") != std::string::npos)|| i->second.instType == "ZBA_RTYPEUW" || i->second.instType == "RISCV_SLLIUW" || i->second.instType == "RISCV_ORCB" || i->second.instType.find("RISCV_F") != std::string::npos || i->second.instType == "ZICOND_RTYPE"
            || i->second.instType == "VVTYPE" || i->second.instType == "MVVTYPE" || i->second.instType == "WVVTYPE"  || i->second.instType == "WVXTYPE" || i->second.instType == "WXTYPE" || i->second.instType == "MVXTYPE" ||i->second.instType == "WMVXTYPE" || i->second.instType == "WMVVTYPE" || i->second.instType == "WVTYPE" || i->second.instType == "MVVMATYPE" || i->second.instType == "MVXMATYPE" || i->second.instType == "NVSTYPE" || i->second.instType == "NVTYPE" || i->second.instType == "VXTYPE" || i->second.instType == "NXSTYPE" || i->second.instType == "NXTYPE" || i->second.instType == "VXSG" || i->second.instType == "VISG" || i->second.instType == "VITYPE" || i->second.instType == "NISTYPE" || i->second.instType == "NITYPE"
            || i->second.instType == "VEXT2TYPE" || i->second.instType == "VEXT4TYPE" || i->second.instType == "VEXT8TYPE" || i->second.instType == "MASKTYPEV" || i->second.instType == "MASKTYPEI" || i->second.instType == "MOVETYPEV" || i->second.instType == "MASKTYPEX" || i->second.instType == "MOVETYPEX" || i->second.instType == "MOVETYPEI" || i->second.instType == "VMVRTYPE" || i->second.instType == "VMVXS" || i->second.instType == "MVVCOMPRESS" || i->second.instType == "VMVSX"
            || i->second.instType == "FVVTYPE" || i->second.instType == "FVVMATYPE" || i->second.instType == "FWVVTYPE" || i->second.instType == "FWVVMATYPE" || i->second.instType == "FWVTYPE" || i->second.instType == "VFUNARY0" || i->second.instType == "VFWUNARY0" || i->second.instType == "VFNUNARY0" || i->second.instType == "VFUNARY1" || i->second.instType == "FVFTYPE" || i->second.instType == "FVFMATYPE" || i->second.instType == "FWVFTYPE" || i->second.instType == "FWVFMATYPE" || i->second.instType == "FWFTYPE" || i->second.instType == "VFMERGE" || i->second.instType == "VFMV" || i->second.instType == "VFMVFS"
            || i->second.instType == "MMTYPE" || i->second.instType == "VCPOP_M" || i->second.instType == "VFIRST_M" || i->second.instType == "VMSBF_M" || i->second.instType == "VMSOF_M" || i->second.instType == "VMSIF_M" || i->second.instType == "VIOTA_M" || i->second.instType == "VID_V"
            || i->second.instType == "RIVVTYPE" || i->second.instType == "RMVVTYPE" || i->second.instType == "RFVVTYPE" || i->second.instType == "VVMTYPE" || i->second.instType == "VVMCTYPE" || i->second.instType == "VVMSTYPE" || i->second.instType == "VVCMPTYPE" || i->second.instType == "VXMTYPE" || i->second.instType == "VXMCTYPE" ||i->second.instType == "VXMSTYPE" || i->second.instType == "VXCMPTYPE" || i->second.instType == "VIMTYPE" ||i->second.instType == "VIMCTYPE" || i->second.instType == "VIMSTYPE" || i->second.instType == "VICMPTYPE" || i->second.instType == "FVVMTYPE" || i->second.instType == "FVFMTYPE"){
                std::vector<std::string> tokenname = splitString(i->second.name, "_");
                name += "{\"";
                for (const auto& token : tokenname){
                    name += token;
                    name += ".";
                }
                name.pop_back();
                name += "\"";
            }
            else{
                name = "{\"" + i->second.name +"\"";
            }


            //isa
            // if(i->second.instType == "RTYPEW" || i->second.instType == "STORE" || i->second.instType == "LOAD" || i->second.instType == "UTYPE" || i->second.instType == "RTYPE" || i->second.instType == "BTYPE" || i->second.instType == "ITYPE" || i->second.instType.find("JAL") != std::string::npos || i->second.instType.find("SHIFTIOP") != std::string::npos){
            //     isa += "INSN_CLASS_I";
            // }
            if(i->second.instType == "FENCEI"){
                isa += "INSN_CLASS_ZIFENCEI";
            }
            else if(i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE_D") != std::string::npos){
                isa += "INSN_CLASS_D_INX";
            }
            else if(i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE_S") != std::string::npos){
                isa += "INSN_CLASS_F_INX";
            }
            else if(i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE_H") != std::string::npos){
                isa += "INSN_CLASS_ZFH_INX";
            }
            else if(i->second.instType == "AMO" || i->second.instType == "LOADRES" || i->second.instType == "STORECON"){
                isa += "INSN_CLASS_A";
            }
            else if(i->second.instType == "MUL" || i->second.instType == "MULW"){
                isa += "INSN_CLASS_ZMMUL";
            }
            else if(i->second.instType == "DIV" || i->second.instType == "REM" || i->second.instType == "DIVW" || i->second.instType == "REMW"){
                isa += "INSN_CLASS_M";
            }
            else if(i->second.instType == "CSR"){
                isa += "INSN_CLASS_ZICSR";
            }
            else if(i->second.instType == "ZBA_RTYPEUW" || i->second.instType == "RISCV_SLLIUW"){
                isa += "INSN_CLASS_ZBA";
            }
            else if(i->second.instType == "RISCV_RORIW" || i->second.instType == "RISCV_RORI" || i->second.instType == "RISCV_REV8"|| i->second.instType.find("ZBB") != std::string::npos){
                if(i->second.name == "min" || i->second.name == "minu" || i->second.name == "max" || i->second.name == "maxu" || i->second.instType == "ZBB_EXTOP"){
                    isa += "INSN_CLASS_ZBB";
                }
                else{
                    isa += "INSN_CLASS_ZBB_OR_ZBKB";
                }
            }
            else if(i->second.instType.find("CPOP") != std::string::npos || i->second.instType == "RISCV_ORCB" || i->second.instType.find("CTZ") != std::string::npos || i->second.instType.find("CLZ") != std::string::npos){
                isa += "INSN_CLASS_ZBB";
            }
            else if(i->second.instType.find("CLMUL") != std::string::npos){
                if(i->second.instType == "RISCV_CLMULR"){
                    isa += "INSN_CLASS_ZBC";
                }
                else{
                    isa += "INSN_CLASS_ZBC_OR_ZBKC";
                }
            }
            else if(i->second.instType.find("ZBKB_") != std::string::npos || i->second.instType.find("ZIP") != std::string::npos || i->second.instType == "RISCV_BREV8"){
                isa += "INSN_CLASS_ZBKB";
            }
            else if(i->second.instType.find("XPERM") != std::string::npos){
                isa += "INSN_CLASS_ZBKX";
            }
            else if(i->second.instType.find("ZBS_") != std::string::npos){
                isa += "INSN_CLASS_ZBS";
            }
            else if(i->second.instType.find("RISCV_F") != std::string::npos){
                if(i->second.instType == "RISCV_FLI_H"){
                    isa += "INSN_CLASS_ZFH_OR_ZVFH_AND_ZFA";
                }
                else if(i->second.instType.find("_D") != std::string::npos){
                    isa += "INSN_CLASS_D_AND_ZFA";
                }
                else if(i->second.instType.find("_S") != std::string::npos){
                    isa += "INSN_CLASS_ZFA";
                }
                else if(i->second.instType.find("_H") != std::string::npos){
                    isa += "INSN_CLASS_ZFH_AND_ZFA";
                }
            }
            else if(i->second.instType == "ZICOND_RTYPE"){
                isa += "INSN_CLASS_ZICOND";
            }
            else if(i->second.instType == "VVTYPE" || i->second.instType == "MVVTYPE" || i->second.instType == "WVVTYPE" || i->second.instType == "WVXTYPE"  || i->second.instType == "WXTYPE" || i->second.instType == "MVXTYPE" || i->second.instType == "WMVVTYPE" || i->second.instType == "WVTYPE" || i->second.instType == "WMVXTYPE" || i->second.instType == "MVXMATYPE" || i->second.instType == "MVVMATYPE" || i->second.instType == "NVSTYPE" || i->second.instType == "NVTYPE" || i->second.instType == "VXTYPE" || i->second.instType == "NXSTYPE" || i->second.instType == "NXTYPE" || i->second.instType == "VXSG" || i->second.instType == "VISG" || i->second.instType == "VITYPE" || i->second.instType == "NISTYPE" || i->second.instType == "NITYPE"){
                isa += "INSN_CLASS_V";
            }
            else if(i->second.instType == "VEXT2TYPE" || i->second.instType == "VEXT4TYPE" || i->second.instType == "VEXT8TYPE"){
                isa += "INSN_CLASS_V";
            }
            else if(i->second.instType == "MOVETYPEV" || i->second.instType == "MASKTYPEX" || i->second.instType == "MOVETYPEX" || i->second.instType == "MOVETYPEI" || i->second.instType == "VMVRTYPE" || i->second.instType == "VMVXS" || i->second.instType == "MVVCOMPRESS" || i->second.instType == "VMVSX"){
                isa += "INSN_CLASS_V";
            }
            else if(i->second.instType == "FVVTYPE" || i->second.instType == "FVVMATYPE" || i->second.instType == "FWVVTYPE" || i->second.instType == "FWVVMATYPE" || i->second.instType == "FWVTYPE" || i->second.instType == "VFUNARY0" || i->second.instType == "VFWUNARY0" || i->second.instType == "VFNUNARY0" || i->second.instType == "VFUNARY1" || i->second.instType == "FVFTYPE"){
                isa += "INSN_CLASS_ZVEF";
            }
            else if(i->second.instType == "FVFMATYPE" || i->second.instType == "FWVFTYPE" || i->second.instType == "FWVFMATYPE" || i->second.instType == "VFMERGE" || i->second.instType == "VFMV" || i->second.instType == "VFMVFS" || i->second.instType == "RFVVTYPE" || i->second.instType == "FVVMTYPE" || i->second.instType == "FVFMTYPE"){
                isa += "INSN_CLASS_ZVEF";
            }
            else if(i->second.instType == "MMTYPE" || i->second.instType == "VCPOP_M" || i->second.instType == "VFIRST_M" || i->second.instType == "VMSBF_M" || i->second.instType == "VMSOF_M" || i->second.instType == "VMSIF_M" || i->second.instType == "VIOTA_M" || i->second.instType == "VID_V"){
                isa += "INSN_CLASS_V"; 
            }
            else if(i->second.instType == "RIVVTYPE" || i->second.instType == "RMVVTYPE" || i->second.instType == "VVMTYPE" || i->second.instType == "VVMCTYPE" || i->second.instType == "VVMSTYPE" || i->second.instType == "VVCMPTYPE" || i->second.instType == "VXMTYPE" || i->second.instType == "VXMCTYPE" || i->second.instType == "VXMSTYPE" || i->second.instType == "VXCMPTYPE" || i->second.instType == "VIMTYPE" || i->second.instType == "VIMCTYPE" || i->second.instType == "VIMSTYPE" || i->second.instType == "VICMPTYPE"){
                isa += "INSN_CLASS_V"; 
            }
            else{
                isa += "INSN_CLASS_I";
            }

            //xlen
            if( i->second.instType == "SHIFTIWOP" ||i->second.instType == "RTYPEW" || i->second.name == "ld" || i->second.name == "sd" || i->second.name == "addiw" || i->second.name == "lr_d" || i->second.name == "sc_d" || (i->second.instType == "AMO" && i->second.name.find("_d") != std::string::npos)){
                xlen += "\t64";
            }
            else if((i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE") != std::string::npos) && (i->second.name.find("_d") != std::string::npos && i->second.name.find("_l") != std::string::npos)){
                xlen += "\t64";
            }
            else if((i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE") != std::string::npos) && (i->second.name.find("_s") != std::string::npos && i->second.name.find("_l") != std::string::npos)){
                xlen += "\t64";
            }
            else if((i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE") != std::string::npos) && (i->second.name.find("_h") != std::string::npos && i->second.name.find("_l") != std::string::npos)){
                xlen += "\t64";
            }
            else if(i->second.instType == "MULW" || i->second.instType == "DIVW" || i->second.instType == "REMW"){
                xlen += "\t64";
            }
            else if((i->second.instType == "ZBA_RTYPEUW" || i->second.instType == "RISCV_SLLIUW") && i->second.instType.find("UW") != std::string::npos || (i->second.instType == "ZBB_EXTOP" && i->second.name == "zext_h")){
                xlen += "\t64";
            }
            else if(i->second.instType == "RISCV_REV8"){
                xlen += "\t64";
            }
            else if(i->second.instType == "ZBKB_PACKW" || i->second.instType == "RISCV_BREV8"){
                xlen += "\t64";
            }
            else if(i->second.instType.find("ZIP") != std::string::npos){
                xlen += "\t32";
            }
            else{
                xlen += "\t0";
            }
            // if(i->second.instType == "FENCE"  || i->second.instType == "STORE" || i->second.instType == "LOAD" || i->second.instType == "UTYPE" || i->second.instType == "RTYPE" || i->second.instType == "BTYPE" || i->second.instType == "ITYPE" || i->second.instType.find("JAL") != std::string::npos || i->second.instType.find("SHIFTIOP") != std::string::npos)
            //operands
            std::vector<std::string> tokenoperands = splitString(i->second.assembleString, ",");
            operands += "\"";
            int symbolcount=0;
            int tokencount = 0;
            if(i->second.instType == "FENCE_TSO" || i->second.assembleString .find(",") == std::string::npos){
                operands += "\"";
            }
            else{
                for (const auto& token : tokenoperands) {
                    if(tokencount == 0){
                        //cout << token << endl;
                        if(name == "{\"\""){
                            name.pop_back();
                            name += token;
                            optable[""].name=token;
                            name += "\"";
                        }
                        tokencount++;
                    }
                    if(token.find("csr_name_map") != std::string::npos){
                        operands += "E";
                        operands += ",";
                    }
                    if(token.find("rd") != std::string::npos){
                        if(token.find("freg") != std::string::npos){
                            operands += "D";
                            operands += ",";
                        }
                        else{
                            operands += "d";
                            operands += ",";
                        }
                    }
                    if(token.find("imm") != std::string::npos){
                        if(i->second.instType == "UTYPE"){
                            operands += "u";
                            operands += ",";
                        }
                        if(i->second.instType == "BTYPE"){
                            operands += "p";
                            operands += ",";
                        }
                        if(i->second.instType.find("JALR") != std::string::npos || i->second.instType == "ITYPE" || i->second.instType == "ADDIW" || i->second.instType == "RTYPEW"){
                            operands += "j";
                            operands += ",";
                        }
                        else if(i->second.instType.find("JAL") != std::string::npos){
                            operands += "a";
                            operands += ",";
                        }
                    }
                    if(token.find("rs1") != std::string::npos && symbolcount == 1 && i->second.instType.find("JALR") == std::string::npos){
                        if(i->second.instType == "LOAD" || i->second.instType == "LOAD_FP"){
                            operands += "o(s)";
                        }
                        else if(i->second.instType == "STORE" || i->second.instType == "STORE_FP"){
                            operands += "q(s)";
                        }
                        else if(i->second.instType == "AMO" || i->second.instType == "LOADRES" || i->second.instType == "STORECON"){
                            operands += "0(s)";
                        }
                        operands += ",";
                    }
                    else if(token.find("rs1") != std::string::npos){
                        if(token.find("freg") != std::string::npos){
                            operands += "S";
                            operands += ",";
                        }
                        else if(i->second.instType == "CSR" && i->second.name.find("i") != std::string::npos){
                            operands += "Z";
                            operands += ",";
                        }
                        else if(i->second.instType == "FWVFTYPE" || i->second.instType == "FWFTYPE" || i->second.instType == "VFMERGE" || i->second.instType == "VFMV" || i->second.instType == "VFMVFS" || i->second.instType == "FVFMTYPE"){
                            operands += "S";
                            operands += ",";
                        }
                        else{
                            operands += "s";
                            operands += ",";
                        }
                    }
                    if(token.find("rs2") != std::string::npos){
                        if(token.find("freg") != std::string::npos){
                            operands += "T";
                            operands += ",";
                        }
                        else{
                            operands += "t";
                            operands += ",";
                        }
                    }
                    if(token.find("rs3") != std::string::npos){
                        if(token.find("freg") != std::string::npos){
                            operands += "R";
                            operands += ",";
                        }
                        else{
                            operands += "r";
                            operands += ",";
                        }
                    }
                    if(token.find("rm_mnemonic") != std::string::npos){
                        if(rmCheck == 0){
                            rmCheck++;
                        }
                        else if(rmCheck == 2){
                            rmCheck++;
                            if(token.find("frm") != std::string::npos){
                                operands += "m";
                                operands += ",";
                            }
                            else{
                                operands += "r";
                                operands += ",";
                            }
                        }
                    }
                    if(token.find("pred") != std::string::npos){
                        operands += "P";
                        operands += ",";
                    }
                    if(token.find("succ") != std::string::npos){
                        operands += "Q";
                        operands += ",";
                    }
                    if(token.find("shamt") != std::string::npos && i->second.name.find("iw")!= std::string::npos){
                        operands += "<";
                        operands += ",";
                    }
                    else if(token.find("shamt") != std::string::npos){
                        operands += ">";
                        operands += ",";
                    }
                    if(token == "("){
                        symbolcount++;
                    }
                    if(token.find("vd") != std::string::npos){
                        operands += "Vd";
                        operands += ",";
                    }
                    if(token.find("v0") != std::string::npos){
                        operands += "V0";
                        operands += ",";
                    }
                    if(token.find("vs2") != std::string::npos){
                        operands += "Vt";
                        operands += ",";
                    }
                    if(token.find("vs1") != std::string::npos){
                        operands += "Vs";
                        operands += ",";
                    }
                    if(token.find("vmaskvm") != std::string::npos){
                        operands.pop_back();
                        operands += "Vm";
                        operands += ",";
                    }
                    if(token.find("simm") != std::string::npos){
                        //operands.pop_back();
                        if(i->second.instType == "NISTYPE" || i->second.instType == "NITYPE" || i->second.instType == "VISG"){
                            operands += "Vj";
                            operands += ",";
                        }
                        else if(i->second.instType == "VMVRTYPE"){

                        }
                        else{
                            operands += "Vi";
                            operands += ",";
                        }
                    }
                }
            }
            operands.pop_back();
            operands += "\"";

            //match
            transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::toupper);
            match = "\tMATCH_" + i->second.name;
            //cout << i->second.name << endl;
            if(i->second.name == "REV8"){
                match.clear();
                 match += "MATCH_GREVI | MATCH_SHAMT_REV8_64";
            }
            else if(i->second.name == "BREV8"){
                match.clear();
                 match += "MATCH_GREVI | MATCH_SHAMT_BREV8";
            }
            else if(i->second.name == "ORC_B"){
                match.clear();
                match += "MATCH_GORCI | MATCH_SHAMT_ORC_B";
            }
            else if(rmCheck == 1 && (i->second.name != "FCVT_D_S" && i->second.name != "FCVT_D_W")){
                match += "|MASK_RM";
            }
            else if(i->second.instType == "RISCV_ZIP"){
                match.clear();
                match += "MATCH_SHFLI|MATCH_SHAMT_ZIP_32";
            }
            else if(i->second.instType == "RISCV_UNZIP"){
                match.clear();
                match += "MATCH_UNSHFLI|MATCH_SHAMT_ZIP_32";
            }
           

            //mask
            if(i->second.instType == "RISCV_ZIP"){
                mask.clear();
                mask += "MASK_SHFLI|MASK_SHAMT";
            }
            else if(i->second.instType == "RISCV_UNZIP"){
                mask.clear();
                mask += "MASK_UNSHFLI|MASK_SHAMT";
            }
            else if(i->second.name == "REV8" || i->second.instType == "RISCV_BREV8"){
                mask.clear();
                mask += "MASK_GREVI | MASK_SHAMT";
            }
            else if(i->second.name == "ORC_B"){
                mask.clear();
                mask += "MASK_GORCI | MASK_SHAMT";
            }
            else if(i->second.name == "FENCE"){
                mask = "MASK_FENCE|MASK_RD|MASK_RS1|(MASK_IMM & ~MASK_PRED & ~MASK_SUCC)";
            }
            else if(i->second.name == "FENCEI"){
                mask = "MASK_FENCE|MASK_RD|MASK_RS1|MASK_IMM";
            }
            else if(i->second.name == "FENCE_TSO"){
                mask = "MASK_FENCE_TSO|MASK_RD|MASK_RS1";
            }
            else if(i->second.name == "ZEXT_H"){
                mask = "MASK_ZEXT_H|MASK_RS2";
            }
            else{
                mask = "MASK_" + i->second.name;
            }
            if(i->second.instType == "LOADRES" || i->second.instType == "STORECON" || i->second.instType == "AMO"){
                mask += "|MASK_AQRL";
            }

            if(rmCheck == 1){
                mask += "|MASK_RM";
            }

            //match_func
            match_func="match_opcode";
            //pinfo
            if(i->second.instType.find("JAL") != std::string::npos){
                pinfo="INSN_JSR";
            }
            else if(i->second.instType == "BTYPE"){
                pinfo = "INSN_CONDBRANCH";
            }
            else if(i->second.instType == "LOADRES" || i->second.instType == "STORECON" || i->second.instType == "LOAD" || i->second.instType == "STORE" || i->second.instType == "LOAD_FP" || i->second.instType == "STORE_FP" || i->second.instType == "AMO"){
                pinfo = "INSN_DREF|";
               // cout << i->second.name << endl;
                if(i->second.name.find("B") != std::string::npos){
                    pinfo += "INSN_1_BYTE";
                }
                else if(i->second.name.find("H") != std::string::npos){
                    pinfo += "INSN_2_BYTE";
                }
                else if(i->second.name.find("W") != std::string::npos){
                    pinfo += "INSN_4_BYTE";
                }
                else if(i->second.name.find("D") != std::string::npos){
                    pinfo += "INSN_8_BYTE";
                }
            }
            else{
                if(i->second.instType == "VCPOP_M"){
                    pinfo="INSN_ALIAS";
                }
                else{
                    pinfo="0";
                }
            }
            
            opccOutput_sv opccOutput;
            opccOutput.str = name + ", "+ xlen + ", " + isa + ", " + operands + ", " + match + ", " + mask + ", " + match_func + ", " + pinfo + "},\n ";
           
            //cout << opccOutput.str << endl;
            opccouput_insert(opccoutouttable,opccOutput);
        }
        if(rmCheck == 1){
            if(i == opcctable.begin()){
            }
            else{
                rmCheck++;
                i--;
            }
        }
        else if(rmCheck == 3){
            rmCheck = 0;
        }
    }
   
}

void create_opccTable(OPtable_map &optable,opcctable_map &opcctable,string assembleStr,string instType){
    int check = 0;
    //op_dump(optable);
    // cout << "--" << endl;
    //cout << assembleStr << endl;
    //CSR指令
    if(assembleStr.find("csr_mnemonicop,i") != std::string::npos){
        for (auto i = optable.begin(); i != optable.end(); i++){
            if (i->second.name.find("i") != std::string::npos){
                opcctable_sv opccTmp;
                opccTmp.assembleString = assembleStr;
                opccTmp.instType = instType;
                opccTmp.name = i->second.name;
                opcctable.emplace(opccTmp.name, opccTmp);
            }
        } 
    }
    else if(assembleStr.find("csr_mnemonicop") != std::string::npos){
        for (auto i = optable.begin(); i != optable.end(); i++){
            if (i->second.name.find("i") == std::string::npos){
                opcctable_sv opccTmp;
                opccTmp.assembleString = assembleStr;
                opccTmp.instType = instType;
                opccTmp.name = i->second.name;
                opcctable.emplace(opccTmp.name, opccTmp);
            }
        }
    }
    else{
        for (auto i = optable.begin(); i != optable.end(); i++){
            if (opcctable.find(i->second.name) != opcctable.end()){
                i++;
            }
            transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::toupper);
            //cout << i->second.name << endl;
            if(assembleStr.find(i->second.name) != std::string::npos){
                opcctable_sv opccTmp;
                opccTmp.assembleString = assembleStr;
                opccTmp.instType = instType;
                transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::tolower);
                opccTmp.name = i->second.name;
                opcctable.emplace(opccTmp.name, opccTmp);
                check = 1;
                break;
            }
        } 
        //加入被忽略的指令
        if(check == 0)
            for (auto i = optable.begin(); i != optable.end(); i++){
                if (opcctable.find(i->second.name) == opcctable.end()){
                    opcctable_sv opccTmp;
                    opccTmp.assembleString = assembleStr;
                    opccTmp.instType = instType;
                    opccTmp.name = i->second.name;
                    opcctable.emplace(opccTmp.name, opccTmp);
                }
            } 
    }
}

void op_new_table(OPtable_stack &stack, OPtable_map &table)
{
    stack.push(table);
    table.clear();
}

void opcc_new_table(opcctable_stack &stack, opcctable_map &table)
{
    stack.push(table);
    table.clear();
}


void bitstring_new_table(Output_stack &stack, Output_map &table)
{
    stack.push(table);
    table.clear();
}


void op_leave_scope(OPtable_stack &stack, OPtable_map &table)
{
    op_dump(table);
    table = stack.top();
    stack.pop();
}



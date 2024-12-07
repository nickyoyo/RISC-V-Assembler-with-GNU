    #ifndef SYMTABLE_H
    #define SYMTABLE_H
    #include<iostream>
    #include<string>
    #include<map>
    #include<vector>
    #include<cstdlib>
    #include<stack>
    #include <bitset>
    #include <iomanip>
    #include <sstream>
    #include <algorithm>
    #include <fstream>
    #include <cstring>

    #define rd "00000"
    #define rs1 "00000"
    #define rs2 "00000"
    #define rs3 "00000"
    #define shamt "00000"
    #define imm7 "0000000"
    #define imm5 "00000"
    #define func7 "0000000"
    #define func5 "00000"
    #define func3 "000"
    #define pred "0011"
    #define succ "0011"
    #define aq "0"
    #define rl "0"
    #define rm "000"
    #define csr "000000000000"
    #define maskop "1111111"
    #define maskfunc7 "1111111"
    #define maskfunc5 "11111"
    #define maskfunc3 "11111"
    #define maskpred "0000"
    #define masksucc "0000"
    #define maskrm "111"

    #define include "#include \"sysdep.h\"\n#include \"opcode/riscv.h\"\n#include <stdio.h>\n"
    #define Terminate "/* Terminate the list.  */\n{0, 0, INSN_CLASS_NONE, 0, 0, 0, 0, 0}\n};\n"
    #define inst_type "\nconst struct riscv_opcode riscv_insn_types[] = \n{ \n"
    // char RTYPE[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    // char ITYPE[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    // char BTYPE[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    // char STYPE[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    // char JTYPE[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    // char ADDIW[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    // char SHIFTIWOP[][] = {"func7","rs2","rs1","func3","rd","opcode"}
    //string LD_sizetable[][4] = {"B","H","W","D"};

    //aext
    //string LOADRES[][8] = {"func5","aq","rl","rs2","rs1","func3","rd","opcode"};
    //                      11111,0,0,11111,00000,111,00000,1111111  =>0xf9f0707f 
    //string STORECON[][8] = {"func5","aq","rl","rs2","rs1","func3","rd","opcode"};
    //                      11111,0,0,01111,00000,111,00000,1111111  =>0xf8f0707f 
    //string AMO[][8] = {"func5","aq","rl","rs2","rs1","func3","rd","opcode"};
    //                      11111,0,0,01111,00000,111,00000,1111111  =>0xf8f0707f 


    struct definetable {
        std::string name;
        std::string bitcode;
    };

    struct Mexttable{
        std::string name;
        std::string opcode;
    };

    struct OPtable {
        std::string name;
        std::string opcode;
        std::string bitcode;
    };

    struct opcctable {
        std::string name;
        std::string instType;
        std::string assembleString;
    };
    

    // struct instrBitTable {
    //     std::string name;
    //     std::string instrBit;
    // };

    struct Outputtabletable {
        std::string str;
    };

    struct opccOutputtable {
        std::string str;
    };

    using Output_sv = struct Outputtabletable;
    using Output_map = std::map<std::string, Output_sv>;
    using Output_stack = std::stack<Output_map>;

    using opccOutput_sv = struct opccOutputtable;
    using opccOutput_map = std::map<std::string, opccOutput_sv>;
    using opccOutput_stack = std::stack<opccOutput_map>;

    using Mext_sv = struct Mexttable;
    using Mexttable_map = std::map<std::string, Mext_sv>;
    using Mext_stack = std::stack<Mexttable_map>;

    using opcctable_sv = struct opcctable;
    using opcctable_map = std::map<std::string, opcctable_sv>;
    using opcctable_stack = std::stack<opcctable_map>;

    using OPtable_sv = struct OPtable;
    using OPtable_map = std::map<std::string, OPtable_sv>;
    using OPtable_stack = std::stack<OPtable_map>;

    void op_dump(OPtable_map table);
    void opcc_dump(opcctable_map table);
    void Mext_dump(Mexttable_map table);
    void create_output(opcctable_map &opcctable,opccOutput_map &opccoutouttable,Output_map &table,char* BitString,char* assembleStr,OPtable_map &optable,int check,int immbitnum,int addshamt,int LD_check,int LS_Check,int Mext_U,int csr_check);
    void output_dump(Output_map table);
    void opccoutput_dump(opccOutput_map table);

    void Mext_insertOP(OPtable_map &table,Mexttable_map &Mexttable1,Mexttable_map &Mexttable2);

    void Mext_insert(Mexttable_map &table, Mext_sv entry);
    void op_insert(OPtable_map &table, OPtable_sv entry);
    void opcc_insert(opcctable_map &table, opcctable_sv entry);
    bool ouput_insert(Output_map &table, Output_sv entry);
    bool opccouput_insert(opccOutput_map &table, opccOutput_sv entry);

    void create_opccTable(OPtable_map &optable,opcctable_map &opcctable,char* assembleStr,char* instType);
    void create_opccoutput(opcctable_map &opcctable,opccOutput_map &opccoutouttable);

    void op_new_table(OPtable_stack &stack, OPtable_map &table);
    void opcc_new_table(opcctable_stack &stack, opcctable_map &table);
    void op_leave_scope(OPtable_stack &stack, OPtable_map &table);

    #endif
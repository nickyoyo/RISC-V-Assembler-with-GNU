#include "symboltable.h"

using namespace std;

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


// memcpy(X,X+6,sizeof(X)-6);
void op_dump(OPtable_map table)
{
    cout << "OP Table" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << "name: " << i->second.name << " opcode: " << i->second.opcode << " bitcode: " << i->second.bitcode << endl;
    }
}

void reg_dump(Reg_map table)
{
    cout << "Reg Table" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << "name: " << i->second.name << " str: " << i->second.str << endl;
    }

    std::ofstream file("riscv-opc.c",ios::app);
    file << include;

    for (auto i = table.begin(); i != table.end(); i++) {
        int count = 0;
        std::vector<std::string> token = splitString(i->second.str, ",");
        int tokenLength = token.size()-1;
        if(i->second.name == "maybe_lmul_flag"){
            file << const_delpointer;
            file << "riscv_vlmul[" + to_string(tokenLength) + "] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "NULL";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "NULL";
                    }
                }
                if(count < tokenLength-1)
                        file << ", ";
                count++;
            }
            file << "\n};\n";
        }
        else if(i->second.name == "maybe_ma_flag"){
            file << const_delpointer;
            //tokenLength--;
            file << "riscv_vma[" + to_string(tokenLength-1) + "] = \n {\n\t";
             for (const auto& tokens : token){
                count++;
                if(count<=tokenLength){
                    if(count == 1){
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                if(count!=1 && count < tokenLength)
                        file << ", ";

            }
            file << "\n};\n";
        }
        else if(i->second.name == "maybe_ta_flag"){
            //tokenLength--;
             file << const_delpointer;
            file << "riscv_vta[" + to_string(tokenLength-1) + "] = \n {\n\t";
             for (const auto& tokens : token){
                count++;
                if(count<=tokenLength){
                    if(count == 1){
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                if(count>1 && count < tokenLength)
                        file << ", ";
            }
            file << "\n};\n";
        }
        else if(i->second.name == "sew_flag"){
            tokenLength+=4;
            file << const_delpointer;
            file << "riscv_vsew[" + to_string(tokenLength) + "] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "NULL";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "NULL";
                    }
                }
                if(count < tokenLength-1)
                        file << ", ";
                count++;                
            }
            file << "NULL, NULL, NULL";
            file << "\n};\n";
        }
        else if(i->second.name == "reg_name_abi"){
            file << const_del;
            file << "riscv_gpr_names_abi[NGPR][NRC] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "\"NULL\"";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                if(count < tokenLength-1)
                        file << ", ";
                if(count % 8 == 7 && count != tokenLength-1)
                    file << "\n";
                count++;                
            }
            file << "\n};";
        }
        else if(i->second.name == "regtype"){
            file << const_del;
            file << "riscv_gpr_names_numeric[NGPR][NRC] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "zero_reg"){
                        file << "\"x0\"";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                if(count >= 31){
                    file << "\n";
                    break;
                }
                if(count < tokenLength-1)
                        file << ", ";
                if(count % 8 == 7 && count != tokenLength-1)
                    file << "\n";
                count++;                
            }
            file << "\n};";
        }
        else if(i->second.name == "fregtype"){
            tokenLength-=2;
            file << const_del;
            file << "riscv_fpr_names_numeric[NFPR][NRC] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "\"NULL\"";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                else{
                    break;
                }
                if(count < tokenLength-1)
                        file << ", ";
                if(count % 8 == 7 && count != tokenLength-1)
                    file << "\n";
                count++;                
            }
            file << "\n};";
        }
        else if(i->second.name == "freg_name_abi"){
            file << const_del;
            file << "riscv_fpr_names_abi[NFPR][NRC] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "\"NULL\"";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                if(count < tokenLength-1)
                        file << ", ";
                if(count % 8 == 7 && count != tokenLength-1)
                    file << "\n";
                count++;                
            }
            file << "\n};";
        }
        else if(i->second.name == "maybe_vmask"){
            file << const_del;
            file << "riscv_vecm_names_numeric[NVECM][NRC] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "\"NULL\"";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                }
                if(count < tokenLength-1 && tokenLength > 2)
                        file << ", ";
                if(count % 8 == 7 && count != tokenLength-1)
                    file << "\n";
                count++;                
            }
            file << "\n};";
        }
        else if(i->second.name == "vreg_name"){
            file << const_del;
            file << "riscv_vecr_names_numeric[NVECR][NRC] = \n {\n\t";
             for (const auto& tokens : token){
                if(count!=tokenLength){
                    if(tokens == "" && count != 0){
                        file << "\"NULL\"";
                    }
                    else if(tokens != ""){
                        file << "\"" + tokens + "\"";
                    }
                    else{
                        file << "\"NULL\"";
                    }
                }
                else{
                    break;
                }
                if(count < tokenLength-1)
                        file << ", ";
                if(count % 8 == 7 && count != tokenLength-1)
                    file << "\n";
                count++;                
            }
            file << "\n};";
        }
        file << "\n";
    }

    //no file in sail-model

    file << riscv_rm;
    file << riscv_pred_succ;
    file << riscv_th_vediv;
    file << riscv_fli_symval;
    file << riscv_fli_numval;
    file << riscv_th_vlen;
    file << "\n";

    char MASK[8][5] = { "RS1" , "RS2" , "RD" , "RM" ,"PRED" ,"SUCC", "AQ" , "RL"};
    for(int i = 0; i < 8; i++){
        file << "#define ";
        std::string tmpMASK;std::string tmpOPMASK;std::string tmpOPSH;
        tmpMASK = "MASK_" + std::string(MASK[i]);
        tmpOPMASK = "OP_MASK_" + std::string(MASK[i]);
        tmpOPSH = "OP_SH_" + std::string(MASK[i]);
        file << tmpMASK ;
        file << " (";
        file << tmpOPMASK ;
        file << " << ";
        file << tmpOPSH ;
        file << " )\n";
        tmpMASK.clear();
        tmpOPMASK.clear();
        tmpOPSH.clear();
    }
    file << "#define MASK_AQRL (MASK_AQ | MASK_RL)\n";
    file << "#define MASK_IMM ENCODE_ITYPE_IMM (-1U)\n";
    file << "#define MASK_SHAMT (OP_MASK_SHAMT << OP_SH_SHAMT)\n";
    file << "#define MATCH_SHAMT_REV8_64 (0b111000 << OP_SH_SHAMT)\n";
    file << "#define MATCH_SHAMT_ORC_B (0b00111 << OP_SH_SHAMT)\n";
    file << "#define MATCH_SHAMT_ZIP_32 (0b1111 << OP_SH_SHAMT)\n";
    file << "#define MATCH_SHAMT_BREV8 (0b00111 << OP_SH_SHAMT)\n";
    file << "\n";

    file << match_opcode;
    file << match_rd_nonzero;
    
    file.close();

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
    cout << "Output Table" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << "str: " << i->second.str << endl;
    }
    int dec = 0;
    std::ofstream file("riscv-opc.h",ios::app);
    file << "#ifndef RISCV_ENCODING_H\n";
    file << "#define RISCV_ENCODING_H\n";
    for (auto i = table.begin(); i != table.end(); i++) {
        if(i->second.str.find("DECLARE_INSN") != std::string::npos && dec == 0){
            dec++;
            file << "#endif\n";
            file << "#ifdef DECLARE_INSN\n";
        }
        file << i->second.str;
    }
     file << "#endif\n";
     file.close();

}

void opccoutput_dump(opccOutput_map table)
{
    // cout << "opccOutput Table" << endl;
    // for (auto i = table.begin(); i != table.end(); i++) {
    //     cout << "str: " << i->second.str << endl;
    // }
    string riscv_gpr_names_numeric="";
    string riscv_fpr_names_numeric="";
    string riscv_vecr_names_numeric="";
    int i;
    for(i = 0 ; i < 32 ; i++){
        string gTmp =  "\"x"+  to_string(i) ;
        gTmp += "\"";
        string fTmp =  "\"f"+  to_string(i);
        fTmp += "\"";
        string vTmp =  "\"v"+  to_string(i) ;
        riscv_gpr_names_numeric += gTmp;
        riscv_fpr_names_numeric += fTmp;
        riscv_vecr_names_numeric += vTmp;
        if(i < 31){
            riscv_gpr_names_numeric += ",";
            riscv_fpr_names_numeric += ",";
            riscv_vecr_names_numeric += ",";
        }
        if(i % 8 == 7){
            riscv_gpr_names_numeric += "\n";
            riscv_fpr_names_numeric += "\n";
            riscv_vecr_names_numeric += "\n";
        }
    }
    
    //cout << riscv_fpr_names_numeric << endl;
    //std::ofstream file("riscv-opc.c",ios::app);
    
    std::ofstream file("riscv-opc.c");
    //file << include;
    file <<"const struct riscv_opcode riscv_opcodes[] =\n{\n";
    for (auto i = table.begin(); i != table.end(); i++) {
        file << i->second.str;
    }
    file <<"/* Terminate the list.  */\n{0, 0, INSN_CLASS_NONE, 0, 0, 0, 0, 0}\n};\n";
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
        for (auto i = table.begin(); i != table.end(); i++) 
            if(i->second.name == entry.name){
               i->second.bitcode = entry.bitcode;
            }
    } 
   //  cout << entry.name <<endl;
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
  //  return success;
}

void reg_insert(Reg_map &table, Reg_sv entry){
     if (table.find(entry.name) == table.end()){
        //cout << entry.str <<  endl;
        table.emplace(entry.name, entry);
    }
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
	//cout << asHex << '\n';
    return asHex;
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
    // op_dump(optable);
    // cout << BitString <<endl;
    
        for (auto i = optable.begin(); i != optable.end(); i++) {
            if(i->second.name.find("AMO") != std::string::npos && i->second.name.find("_") == std::string::npos){
                i++;
            }
            if(i->second.name != "STORE" && i->second.name != "LOAD" && i->second.name != "MUL" && i->second.name != "CSR"){
               //cout << i->second.name <<endl;
                string smatch;
                std::vector<std::string> tokensmatch = splitString(i->second.bitcode, "@");
                for (const auto& token : tokensmatch) {
                    if(token == "rs1"){
                        smatch += rs1;
                    }
                    else if(token == "rs2"){
                        smatch += rs2;
                    }
                    else if(token == "rs3"){
                        smatch += rs2;
                    }
                    else if(token == "rd"){
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
                        if(token == "imm"){
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
                    if(token == "rs1"){
                        smask += rs1;
                    }
                    else if(token == "rs2"){
                        smask += rs2;
                    }
                    else if(token == "rs3"){
                        smask += rs3;
                    }
                    else if(token == "rd"){
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
                        if(token == "imm"){
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
                //cout << "smatch : " << smatch << endl;
                //cout << "smask : " << smask << endl;
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
            // cout << "match : " << matchhex << endl;
            // cout << "mask : " << maskhex << endl;
                output_insert(table,define);
                output_insert(table,mask);
                output_insert(table,match);
            }
        }
        //op_dump(optable);
        //cout << assembleStr << endl;
        //opcc_dump(opcctable);
        
}

void create_opccoutput(opcctable_map &opcctable,opccOutput_map &opccoutouttable){
    /* name, xlen, isa, operands, match, mask, match_func, pinfo.  */
   
    //opcc_dump(opcctable);
    int rmCheck = 0;
    for (auto i = opcctable.begin(); i != opcctable.end(); i++) {
        while(i->second.instType == "AMO" && i->second.name.find("_") == std::string::npos){
            i++;
        }
        if(rmCheck == 1){
            rmCheck++;
            i--;
        }
        if(i->second.name != "loadres" && i->second.name != "storecon" && i->second.name != "STORE" && i->second.name != "LOAD" && i->second.name != "CSR"){
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
            if(i->second.instType == "LOADRES" || i->second.instType == "STORECON" || i->second.instType == "AMO" || (i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE") != std::string::npos)){
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
            else if(i->second.instType.find("F_") != std::string::npos && i->second.instType.find("_TYPE") != std::string::npos){
                isa += "INSN_CLASS_INX";
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
            else if(i->second.instType == "MULW" || i->second.instType == "DIVW" || i->second.instType == "REMW"){
                xlen += "\t64";
            }
            else{
                xlen += "\t0";
            }
            // if(i->second.instType == "FENCE"  || i->second.instType == "STORE" || i->second.instType == "LOAD" || i->second.instType == "UTYPE" || i->second.instType == "RTYPE" || i->second.instType == "BTYPE" || i->second.instType == "ITYPE" || i->second.instType.find("JAL") != std::string::npos || i->second.instType.find("SHIFTIOP") != std::string::npos)
            //operands
            std::vector<std::string> tokenoperands = splitString(i->second.assembleString, ",");
            operands += "\"";
            int symbolcount=0;
            
            if(i->second.instType == "FENCE_TSO" || i->second.assembleString .find(",") == std::string::npos){
                operands += "\"";
            }
            else{
                for (const auto& token : tokenoperands) {
                    //cout << token << endl;
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
                }
            }
            operands.pop_back();
            operands += "\"";

            //match
            transform(i->second.name.begin(),i->second.name.end(),i->second.name.begin(),::toupper);
            match = "\tMATCH_" + i->second.name;
            //cout << i->second.name << endl;
            if(rmCheck == 1 && (i->second.name != "FCVT_D_S" && i->second.name != "FCVT_D_W")){
                match += "|MASK_RM";
            }
            //mask
            
            if(i->second.name == "FENCE"){
                mask = "MASK_FENCE|MASK_RD|MASK_RS1|(MASK_IMM & ~MASK_PRED & ~MASK_SUCC)";
            }
            else if(i->second.name == "FENCEI"){
                mask = "MASK_FENCE|MASK_RD|MASK_RS1|MASK_IMM";
            }
            else if(i->second.name == "FENCE_TSO"){
                mask = "MASK_FENCE_TSO|MASK_RD|MASK_RS1";
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
                pinfo="0";
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

void reg_new_table(Reg_stack &stack, Reg_map &table)
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



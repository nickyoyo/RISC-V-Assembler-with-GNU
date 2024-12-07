{"vmv1r.v", 	0, INSN_CLASS_V, "Vd,Vt", 	MATCH_VMV1R_V, MASK_VMV1R_V, match_opcode, 0},
 {"vmv2r.v", 	0, INSN_CLASS_V, "Vd,Vt", 	MATCH_VMV2R_V, MASK_VMV2R_V, match_opcode, 0},
 {"vmv4r.v", 	0, INSN_CLASS_V, "Vd,Vt", 	MATCH_VMV4R_V, MASK_VMV4R_V, match_opcode, 0},
 {"vmv8r.v", 	0, INSN_CLASS_V, "Vd,Vt", 	MATCH_VMV8R_V, MASK_VMV8R_V, match_opcode, 0},
 /* Terminate the list.  */
{0, 0, INSN_CLASS_NONE, 0, 0, 0, 0, 0}
};

const struct riscv_opcode riscv_insn_types[] = 
{ 
/* Terminate the list.  */
{0, 0, INSN_CLASS_NONE, 0, 0, 0, 0, 0}
};

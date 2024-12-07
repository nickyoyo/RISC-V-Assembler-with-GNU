#include "sysdep.h"
#include "opcode/riscv.h"
#include <stdio.h>


const char riscv_fpr_names_abi[NFPR][NRC] = 
 {
	"ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7", 
"fs0", "fs1", "fa0", "fa1", "fa2", "fa3", "fa4", "fa5", 
"fa6", "fa7", "fs2", "fs3", "fs4", "fs5", "fs6", "fs7", 
"fs8", "fs9", "fs10", "fs11", "ft8", "ft9", "ft10", "ft11"
};

const char riscv_fpr_names_numeric[NFPR][NRC] = 
 {
	"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", 
"f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", 
"f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23", 
"f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31"
};

const char * const riscv_vlmul[8] = 
 {
	"NULL", "mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"
};

const char * const riscv_vma[2] = 
 {
	"ma", "mu"
};

const char * const riscv_vta[2] = 
 {
	"ta", "tu"
};

const char * const riscv_vecm_names_numeric[NVECM][NRC] = 
 {
	"v0.t"
};


const char riscv_gpr_names_abi[NGPR][NRC] = 
 {
	"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", 
"fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5", 
"a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", 
"s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char riscv_gpr_names_numeric[NGPR][NRC] = 
 {
	"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", 
"x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", 
"x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", 
"x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31"

};

const char * const riscv_vsew[8] = 
 {
	"e8", "e16", "e32", "e64", "NULL", "NULL", "NULL", "NULL"
};

const char riscv_vecr_names_numeric[NVECR][NRC] = 
 {
	"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", 
"v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", 
"v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", 
"v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"
};


const char * const riscv_rm[8] = 
{
};

const char * const riscv_pred_succ[16] = 
{
};

const char * const riscv_th_vediv[4] = 
{
};

const char * const riscv_fli_symval[32] = 
{
};

const float riscv_fli_numval[32] = 
{
};

static int 
match_opcode (const struct riscv_opcode *op, insn_t insn)
{
  return ((insn ^ op->match) & op->mask) == 0;
}

static int
match_rd_nonzero (const struct riscv_opcode *op, insn_t insn)
{
  return (op->pinfo == INSN_MACRO || match_opcode (op, insn))
	&& ((insn & MASK_RD) != 0);
}

#define MASK_RS1 (OP_MASK_RS1 << OP_SH_RS1 )
#define MASK_RS2 (OP_MASK_RS2 << OP_SH_RS2 )
#define MASK_RD (OP_MASK_RD << OP_SH_RD )
#define MASK_RM (OP_MASK_RM << OP_SH_RM )
#define MASK_PRED (OP_MASK_PRED << OP_SH_PRED )
#define MASK_SUCC (OP_MASK_SUCC << OP_SH_SUCC )
#define MASK_AQ (OP_MASK_AQ << OP_SH_AQ )
#define MASK_RL (OP_MASK_RL << OP_SH_RL )
#define MASK_AQRL (MASK_AQ | MASK_RL)
#define MASK_IMM ENCODE_ITYPE_IMM (-1U)
#include "sysdep.h"
#include "opcode/riscv.h"
#include <stdio.h>


const char riscv_fpr_names_abi[NFPR][NRC] = 
 {
	"ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7", 
"fs0", "fs1", "fa0", "fa1", "fa2", "fa3", "fa4", "fa5", 
"fa6", "fa7", "fs2", "fs3", "fs4", "fs5", "fs6", "fs7", 
"fs8", "fs9", "fs10", "fs11", "ft8", "ft9", "ft10", "ft11"
};

const char riscv_fpr_names_numeric[NFPR][NRC] = 
 {
	"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", 
"f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", 
"f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23", 
"f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31"
};

const char * const riscv_vlmul[8] = 
 {
	NULL, "mf8", "mf4", "mf2", "m1", "m2", "m4", "m8"
};

const char * const riscv_vma[2] = 
 {
	"ma", "mu"
};

const char * const riscv_vta[2] = 
 {
	"ta", "tu"
};

const char riscv_vecm_names_numeric[NVECM][NRC] = 
 {
	"v0.t"
};


const char riscv_gpr_names_abi[NGPR][NRC] = 
 {
	"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", 
"fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5", 
"a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", 
"s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char riscv_gpr_names_numeric[NGPR][NRC] = 
 {
	"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", 
"x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", 
"x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", 
"x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31"

};

const char * const riscv_vsew[8] = 
 {
	"e8", "e16", "e32", "e64", NULL, NULL, NULL, NULL
};

const char riscv_vecr_names_numeric[NVECR][NRC] = 
 {
	"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", 
"v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", 
"v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", 
"v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"
};


const char * const riscv_rm[8] = 
{
};

const char * const riscv_pred_succ[16] = 
{
};

const char * const riscv_th_vediv[4] = 
{
};

const char * const riscv_fli_symval[32] = 
{
};

const float riscv_fli_numval[32] = 
{
};
const char * const riscv_th_vlen[4] =
{
};

#define MASK_RS1 (OP_MASK_RS1 << OP_SH_RS1 )
#define MASK_RS2 (OP_MASK_RS2 << OP_SH_RS2 )
#define MASK_RD (OP_MASK_RD << OP_SH_RD )
#define MASK_RM (OP_MASK_RM << OP_SH_RM )
#define MASK_PRED (OP_MASK_PRED << OP_SH_PRED )
#define MASK_SUCC (OP_MASK_SUCC << OP_SH_SUCC )
#define MASK_AQ (OP_MASK_AQ << OP_SH_AQ )
#define MASK_RL (OP_MASK_RL << OP_SH_RL )
#define MASK_AQRL (MASK_AQ | MASK_RL)
#define MASK_IMM ENCODE_ITYPE_IMM (-1U)

static int 
match_opcode (const struct riscv_opcode *op, insn_t insn)
{
  return ((insn ^ op->match) & op->mask) == 0;
}

static int
match_rd_nonzero (const struct riscv_opcode *op, insn_t insn)
{
  return (op->pinfo == INSN_MACRO || match_opcode (op, insn))
	&& ((insn & MASK_RD) != 0);
}


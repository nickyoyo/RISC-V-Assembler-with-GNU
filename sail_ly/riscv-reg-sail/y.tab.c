/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sail.y"

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

int mext_MULcheck = 0; //mext MUL 處理
int mext_MULcheck1 = 0; //mext MUL 處理  mul_mnemonic

//reg 
int regcreate =0;
int regCount=0;
int funCount=0;
int funName=0;
int regFlag=0;

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

Reg_sv Regtable;
Reg_map RegMaptable;
Reg_stack Regsymtable_stack;

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
std::string regstr;
std::string regname;

int yylex(void);


#line 168 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LESS = 258,                    /* LESS  */
    LESS_OR_EQUAL = 259,           /* LESS_OR_EQUAL  */
    EQUAL = 260,                   /* EQUAL  */
    GREATER = 261,                 /* GREATER  */
    GREATER_OR_EQUAL = 262,        /* GREATER_OR_EQUAL  */
    NOT_EQUAL = 263,               /* NOT_EQUAL  */
    UNARY_MINUS = 264,             /* UNARY_MINUS  */
    And = 265,                     /* And  */
    As = 266,                      /* As  */
    Assert = 267,                  /* Assert  */
    Bitzero = 268,                 /* Bitzero  */
    Bitone = 269,                  /* Bitone  */
    By = 270,                      /* By  */
    Match = 271,                   /* Match  */
    Clause = 272,                  /* Clause  */
    Dec = 273,                     /* Dec  */
    Default = 274,                 /* Default  */
    Effect = 275,                  /* Effect  */
    End = 276,                     /* End  */
    Op = 277,                      /* Op  */
    Enum = 278,                    /* Enum  */
    Else = 279,                    /* Else  */
    False = 280,                   /* False  */
    Forall = 281,                  /* Forall  */
    Foreach = 282,                 /* Foreach  */
    Overload = 283,                /* Overload  */
    Function_ = 284,               /* Function_  */
    Mapping = 285,                 /* Mapping  */
    If_ = 286,                     /* If_  */
    In = 287,                      /* In  */
    Inc = 288,                     /* Inc  */
    Let_ = 289,                    /* Let_  */
    Int = 290,                     /* Int  */
    Order = 291,                   /* Order  */
    Bool = 292,                    /* Bool  */
    Cast = 293,                    /* Cast  */
    Pure = 294,                    /* Pure  */
    Monadic = 295,                 /* Monadic  */
    Register = 296,                /* Register  */
    Return = 297,                  /* Return  */
    Scattered = 298,               /* Scattered  */
    Sizeof = 299,                  /* Sizeof  */
    Struct = 300,                  /* Struct  */
    Then = 301,                    /* Then  */
    True = 302,                    /* True  */
    TwoCaret = 303,                /* TwoCaret  */
    TYPE = 304,                    /* TYPE  */
    Typedef = 305,                 /* Typedef  */
    Undefined = 306,               /* Undefined  */
    Union = 307,                   /* Union  */
    Newtype = 308,                 /* Newtype  */
    With = 309,                    /* With  */
    Val = 310,                     /* Val  */
    Outcome = 311,                 /* Outcome  */
    Constraint = 312,              /* Constraint  */
    Throw = 313,                   /* Throw  */
    Try = 314,                     /* Try  */
    Catch = 315,                   /* Catch  */
    Exit = 316,                    /* Exit  */
    Bitfield = 317,                /* Bitfield  */
    Constant = 318,                /* Constant  */
    Repeat = 319,                  /* Repeat  */
    Until = 320,                   /* Until  */
    While = 321,                   /* While  */
    Do = 322,                      /* Do  */
    Mutual = 323,                  /* Mutual  */
    Var = 324,                     /* Var  */
    Ref = 325,                     /* Ref  */
    Configuration = 326,           /* Configuration  */
    TerminationMeasure = 327,      /* TerminationMeasure  */
    Instantiation = 328,           /* Instantiation  */
    Impl = 329,                    /* Impl  */
    Private = 330,                 /* Private  */
    InternalPLet = 331,            /* InternalPLet  */
    InternalReturn = 332,          /* InternalReturn  */
    InternalAssume = 333,          /* InternalAssume  */
    Forwards = 334,                /* Forwards  */
    Backwards = 335,               /* Backwards  */
    Bar = 336,                     /* Bar  */
    Comma = 337,                   /* Comma  */
    Dot = 338,                     /* Dot  */
    Eof = 339,                     /* Eof  */
    Minus = 340,                   /* Minus  */
    Semi = 341,                    /* Semi  */
    Under = 342,                   /* Under  */
    DotDot = 343,                  /* DotDot  */
    At = 344,                      /* At  */
    ColonColon = 345,              /* ColonColon  */
    Caret = 346,                   /* Caret  */
    Star = 347,                    /* Star  */
    Lcurly = 348,                  /* Lcurly  */
    Rcurly = 349,                  /* Rcurly  */
    Lparen = 350,                  /* Lparen  */
    Rparen = 351,                  /* Rparen  */
    Lsquare = 352,                 /* Lsquare  */
    Rsquare = 353,                 /* Rsquare  */
    LcurlyBar = 354,               /* LcurlyBar  */
    RcurlyBar = 355,               /* RcurlyBar  */
    LsquareBar = 356,              /* LsquareBar  */
    RsquareBar = 357,              /* RsquareBar  */
    MinusGt = 358,                 /* MinusGt  */
    Bidir = 359,                   /* Bidir  */
    Eq = 360,                      /* Eq  */
    EqGt = 361,                    /* EqGt  */
    Unit = 362,                    /* Unit  */
    Colon = 363,                   /* Colon  */
    OpId = 364,                    /* OpId  */
    Attribute = 365,               /* Attribute  */
    LINE_DIRECTIVE = 366,          /* LINE_DIRECTIVE  */
    FIXITY = 367,                  /* FIXITY  */
    ID = 368,                      /* ID  */
    TyVar = 369,                   /* TyVar  */
    Num = 370,                     /* Num  */
    Bin_literal = 371,             /* Bin_literal  */
    Hex_literal = 372,             /* Hex_literal  */
    STRING_LITERAL = 373           /* STRING_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LESS 258
#define LESS_OR_EQUAL 259
#define EQUAL 260
#define GREATER 261
#define GREATER_OR_EQUAL 262
#define NOT_EQUAL 263
#define UNARY_MINUS 264
#define And 265
#define As 266
#define Assert 267
#define Bitzero 268
#define Bitone 269
#define By 270
#define Match 271
#define Clause 272
#define Dec 273
#define Default 274
#define Effect 275
#define End 276
#define Op 277
#define Enum 278
#define Else 279
#define False 280
#define Forall 281
#define Foreach 282
#define Overload 283
#define Function_ 284
#define Mapping 285
#define If_ 286
#define In 287
#define Inc 288
#define Let_ 289
#define Int 290
#define Order 291
#define Bool 292
#define Cast 293
#define Pure 294
#define Monadic 295
#define Register 296
#define Return 297
#define Scattered 298
#define Sizeof 299
#define Struct 300
#define Then 301
#define True 302
#define TwoCaret 303
#define TYPE 304
#define Typedef 305
#define Undefined 306
#define Union 307
#define Newtype 308
#define With 309
#define Val 310
#define Outcome 311
#define Constraint 312
#define Throw 313
#define Try 314
#define Catch 315
#define Exit 316
#define Bitfield 317
#define Constant 318
#define Repeat 319
#define Until 320
#define While 321
#define Do 322
#define Mutual 323
#define Var 324
#define Ref 325
#define Configuration 326
#define TerminationMeasure 327
#define Instantiation 328
#define Impl 329
#define Private 330
#define InternalPLet 331
#define InternalReturn 332
#define InternalAssume 333
#define Forwards 334
#define Backwards 335
#define Bar 336
#define Comma 337
#define Dot 338
#define Eof 339
#define Minus 340
#define Semi 341
#define Under 342
#define DotDot 343
#define At 344
#define ColonColon 345
#define Caret 346
#define Star 347
#define Lcurly 348
#define Rcurly 349
#define Lparen 350
#define Rparen 351
#define Lsquare 352
#define Rsquare 353
#define LcurlyBar 354
#define RcurlyBar 355
#define LsquareBar 356
#define RsquareBar 357
#define MinusGt 358
#define Bidir 359
#define Eq 360
#define EqGt 361
#define Unit 362
#define Colon 363
#define OpId 364
#define Attribute 365
#define LINE_DIRECTIVE 366
#define FIXITY 367
#define ID 368
#define TyVar 369
#define Num 370
#define Bin_literal 371
#define Hex_literal 372
#define STRING_LITERAL 373

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 98 "sail.y"

   struct {
    int ival;
    bool bval;
    float fval;
    char charVal;
    char* stringVal;
    } node;

#line 467 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '^'  */
  YYSYMBOL_4_ = 4,                         /* '*'  */
  YYSYMBOL_5_ = 5,                         /* '/'  */
  YYSYMBOL_6_ = 6,                         /* '%'  */
  YYSYMBOL_7_ = 7,                         /* '+'  */
  YYSYMBOL_8_ = 8,                         /* '-'  */
  YYSYMBOL_LESS = 9,                       /* LESS  */
  YYSYMBOL_LESS_OR_EQUAL = 10,             /* LESS_OR_EQUAL  */
  YYSYMBOL_EQUAL = 11,                     /* EQUAL  */
  YYSYMBOL_GREATER = 12,                   /* GREATER  */
  YYSYMBOL_GREATER_OR_EQUAL = 13,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 14,                 /* NOT_EQUAL  */
  YYSYMBOL_15_ = 15,                       /* '&'  */
  YYSYMBOL_16_ = 16,                       /* '|'  */
  YYSYMBOL_UNARY_MINUS = 17,               /* UNARY_MINUS  */
  YYSYMBOL_And = 18,                       /* And  */
  YYSYMBOL_As = 19,                        /* As  */
  YYSYMBOL_Assert = 20,                    /* Assert  */
  YYSYMBOL_Bitzero = 21,                   /* Bitzero  */
  YYSYMBOL_Bitone = 22,                    /* Bitone  */
  YYSYMBOL_By = 23,                        /* By  */
  YYSYMBOL_Match = 24,                     /* Match  */
  YYSYMBOL_Clause = 25,                    /* Clause  */
  YYSYMBOL_Dec = 26,                       /* Dec  */
  YYSYMBOL_Default = 27,                   /* Default  */
  YYSYMBOL_Effect = 28,                    /* Effect  */
  YYSYMBOL_End = 29,                       /* End  */
  YYSYMBOL_Op = 30,                        /* Op  */
  YYSYMBOL_Enum = 31,                      /* Enum  */
  YYSYMBOL_Else = 32,                      /* Else  */
  YYSYMBOL_False = 33,                     /* False  */
  YYSYMBOL_Forall = 34,                    /* Forall  */
  YYSYMBOL_Foreach = 35,                   /* Foreach  */
  YYSYMBOL_Overload = 36,                  /* Overload  */
  YYSYMBOL_Function_ = 37,                 /* Function_  */
  YYSYMBOL_Mapping = 38,                   /* Mapping  */
  YYSYMBOL_If_ = 39,                       /* If_  */
  YYSYMBOL_In = 40,                        /* In  */
  YYSYMBOL_Inc = 41,                       /* Inc  */
  YYSYMBOL_Let_ = 42,                      /* Let_  */
  YYSYMBOL_Int = 43,                       /* Int  */
  YYSYMBOL_Order = 44,                     /* Order  */
  YYSYMBOL_Bool = 45,                      /* Bool  */
  YYSYMBOL_Cast = 46,                      /* Cast  */
  YYSYMBOL_Pure = 47,                      /* Pure  */
  YYSYMBOL_Monadic = 48,                   /* Monadic  */
  YYSYMBOL_Register = 49,                  /* Register  */
  YYSYMBOL_Return = 50,                    /* Return  */
  YYSYMBOL_Scattered = 51,                 /* Scattered  */
  YYSYMBOL_Sizeof = 52,                    /* Sizeof  */
  YYSYMBOL_Struct = 53,                    /* Struct  */
  YYSYMBOL_Then = 54,                      /* Then  */
  YYSYMBOL_True = 55,                      /* True  */
  YYSYMBOL_TwoCaret = 56,                  /* TwoCaret  */
  YYSYMBOL_TYPE = 57,                      /* TYPE  */
  YYSYMBOL_Typedef = 58,                   /* Typedef  */
  YYSYMBOL_Undefined = 59,                 /* Undefined  */
  YYSYMBOL_Union = 60,                     /* Union  */
  YYSYMBOL_Newtype = 61,                   /* Newtype  */
  YYSYMBOL_With = 62,                      /* With  */
  YYSYMBOL_Val = 63,                       /* Val  */
  YYSYMBOL_Outcome = 64,                   /* Outcome  */
  YYSYMBOL_Constraint = 65,                /* Constraint  */
  YYSYMBOL_Throw = 66,                     /* Throw  */
  YYSYMBOL_Try = 67,                       /* Try  */
  YYSYMBOL_Catch = 68,                     /* Catch  */
  YYSYMBOL_Exit = 69,                      /* Exit  */
  YYSYMBOL_Bitfield = 70,                  /* Bitfield  */
  YYSYMBOL_Constant = 71,                  /* Constant  */
  YYSYMBOL_Repeat = 72,                    /* Repeat  */
  YYSYMBOL_Until = 73,                     /* Until  */
  YYSYMBOL_While = 74,                     /* While  */
  YYSYMBOL_Do = 75,                        /* Do  */
  YYSYMBOL_Mutual = 76,                    /* Mutual  */
  YYSYMBOL_Var = 77,                       /* Var  */
  YYSYMBOL_Ref = 78,                       /* Ref  */
  YYSYMBOL_Configuration = 79,             /* Configuration  */
  YYSYMBOL_TerminationMeasure = 80,        /* TerminationMeasure  */
  YYSYMBOL_Instantiation = 81,             /* Instantiation  */
  YYSYMBOL_Impl = 82,                      /* Impl  */
  YYSYMBOL_Private = 83,                   /* Private  */
  YYSYMBOL_InternalPLet = 84,              /* InternalPLet  */
  YYSYMBOL_InternalReturn = 85,            /* InternalReturn  */
  YYSYMBOL_InternalAssume = 86,            /* InternalAssume  */
  YYSYMBOL_Forwards = 87,                  /* Forwards  */
  YYSYMBOL_Backwards = 88,                 /* Backwards  */
  YYSYMBOL_Bar = 89,                       /* Bar  */
  YYSYMBOL_Comma = 90,                     /* Comma  */
  YYSYMBOL_Dot = 91,                       /* Dot  */
  YYSYMBOL_Eof = 92,                       /* Eof  */
  YYSYMBOL_Minus = 93,                     /* Minus  */
  YYSYMBOL_Semi = 94,                      /* Semi  */
  YYSYMBOL_Under = 95,                     /* Under  */
  YYSYMBOL_DotDot = 96,                    /* DotDot  */
  YYSYMBOL_At = 97,                        /* At  */
  YYSYMBOL_ColonColon = 98,                /* ColonColon  */
  YYSYMBOL_Caret = 99,                     /* Caret  */
  YYSYMBOL_Star = 100,                     /* Star  */
  YYSYMBOL_Lcurly = 101,                   /* Lcurly  */
  YYSYMBOL_Rcurly = 102,                   /* Rcurly  */
  YYSYMBOL_Lparen = 103,                   /* Lparen  */
  YYSYMBOL_Rparen = 104,                   /* Rparen  */
  YYSYMBOL_Lsquare = 105,                  /* Lsquare  */
  YYSYMBOL_Rsquare = 106,                  /* Rsquare  */
  YYSYMBOL_LcurlyBar = 107,                /* LcurlyBar  */
  YYSYMBOL_RcurlyBar = 108,                /* RcurlyBar  */
  YYSYMBOL_LsquareBar = 109,               /* LsquareBar  */
  YYSYMBOL_RsquareBar = 110,               /* RsquareBar  */
  YYSYMBOL_MinusGt = 111,                  /* MinusGt  */
  YYSYMBOL_Bidir = 112,                    /* Bidir  */
  YYSYMBOL_Eq = 113,                       /* Eq  */
  YYSYMBOL_EqGt = 114,                     /* EqGt  */
  YYSYMBOL_Unit = 115,                     /* Unit  */
  YYSYMBOL_Colon = 116,                    /* Colon  */
  YYSYMBOL_OpId = 117,                     /* OpId  */
  YYSYMBOL_Attribute = 118,                /* Attribute  */
  YYSYMBOL_LINE_DIRECTIVE = 119,           /* LINE_DIRECTIVE  */
  YYSYMBOL_FIXITY = 120,                   /* FIXITY  */
  YYSYMBOL_ID = 121,                       /* ID  */
  YYSYMBOL_TyVar = 122,                    /* TyVar  */
  YYSYMBOL_Num = 123,                      /* Num  */
  YYSYMBOL_Bin_literal = 124,              /* Bin_literal  */
  YYSYMBOL_Hex_literal = 125,              /* Hex_literal  */
  YYSYMBOL_STRING_LITERAL = 126,           /* STRING_LITERAL  */
  YYSYMBOL_127_ = 127,                     /* '('  */
  YYSYMBOL_128_ = 128,                     /* ')'  */
  YYSYMBOL_129_ = 129,                     /* ','  */
  YYSYMBOL_130_ = 130,                     /* '{'  */
  YYSYMBOL_131_ = 131,                     /* '}'  */
  YYSYMBOL_132_ = 132,                     /* '.'  */
  YYSYMBOL_133_ = 133,                     /* ':'  */
  YYSYMBOL_134_ = 134,                     /* '['  */
  YYSYMBOL_135_ = 135,                     /* ']'  */
  YYSYMBOL_136_ = 136,                     /* '='  */
  YYSYMBOL_137_ = 137,                     /* '~'  */
  YYSYMBOL_138_ = 138,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 139,                 /* $accept  */
  YYSYMBOL_id = 140,                       /* id  */
  YYSYMBOL_op_no_caret = 141,              /* op_no_caret  */
  YYSYMBOL_op = 142,                       /* op  */
  YYSYMBOL_exp_op = 143,                   /* exp_op  */
  YYSYMBOL_pat_op = 144,                   /* pat_op  */
  YYSYMBOL_typ_var = 145,                  /* typ_var  */
  YYSYMBOL_tyarg = 146,                    /* tyarg  */
  YYSYMBOL_prefix_typ_op = 147,            /* prefix_typ_op  */
  YYSYMBOL_postfix_typ = 148,              /* postfix_typ  */
  YYSYMBOL_typ_no_caret = 149,             /* typ_no_caret  */
  YYSYMBOL_list_1 = 150,                   /* list_1  */
  YYSYMBOL_typ = 151,                      /* typ  */
  YYSYMBOL_list_2 = 152,                   /* list_2  */
  YYSYMBOL_atomic_typ = 153,               /* atomic_typ  */
  YYSYMBOL_num_list = 154,                 /* num_list  */
  YYSYMBOL_typ_list = 155,                 /* typ_list  */
  YYSYMBOL_kind = 156,                     /* kind  */
  YYSYMBOL_kid_list = 157,                 /* kid_list  */
  YYSYMBOL_kopt = 158,                     /* kopt  */
  YYSYMBOL_kopt_list = 159,                /* kopt_list  */
  YYSYMBOL_quantifier = 160,               /* quantifier  */
  YYSYMBOL_id_list = 161,                  /* id_list  */
  YYSYMBOL_typschm = 162,                  /* typschm  */
  YYSYMBOL_pat1 = 163,                     /* pat1  */
  YYSYMBOL_list_3 = 164,                   /* list_3  */
  YYSYMBOL_pat = 165,                      /* pat  */
  YYSYMBOL_pat_list = 166,                 /* pat_list  */
  YYSYMBOL_atomic_pat = 167,               /* atomic_pat  */
  YYSYMBOL_fpat = 168,                     /* fpat  */
  YYSYMBOL_fpat_list = 169,                /* fpat_list  */
  YYSYMBOL_lit = 170,                      /* lit  */
  YYSYMBOL_internal_loop_measure = 171,    /* internal_loop_measure  */
  YYSYMBOL_exp = 172,                      /* exp  */
  YYSYMBOL_173_1 = 173,                    /* $@1  */
  YYSYMBOL_prefix_op = 174,                /* prefix_op  */
  YYSYMBOL_exp0 = 175,                     /* exp0  */
  YYSYMBOL_list_4 = 176,                   /* list_4  */
  YYSYMBOL_case = 177,                     /* case  */
  YYSYMBOL_case_list = 178,                /* case_list  */
  YYSYMBOL_block = 179,                    /* block  */
  YYSYMBOL_letbind = 180,                  /* letbind  */
  YYSYMBOL_atomic_exp = 181,               /* atomic_exp  */
  YYSYMBOL_fexp_exp = 182,                 /* fexp_exp  */
  YYSYMBOL_fexp_exp_list = 183,            /* fexp_exp_list  */
  YYSYMBOL_exp_list = 184,                 /* exp_list  */
  YYSYMBOL_vector_update = 185,            /* vector_update  */
  YYSYMBOL_vector_update_list = 186,       /* vector_update_list  */
  YYSYMBOL_funcl_annotation = 187,         /* funcl_annotation  */
  YYSYMBOL_funcl_patexp = 188,             /* funcl_patexp  */
  YYSYMBOL_funcl_patexp_typ = 189,         /* funcl_patexp_typ  */
  YYSYMBOL_funcl = 190,                    /* funcl  */
  YYSYMBOL_funcl_list = 191,               /* funcl_list  */
  YYSYMBOL_funcls = 192,                   /* funcls  */
  YYSYMBOL_funcl_typ = 193,                /* funcl_typ  */
  YYSYMBOL_index_range = 194,              /* index_range  */
  YYSYMBOL_paren_index_range = 195,        /* paren_index_range  */
  YYSYMBOL_atomic_index_range = 196,       /* atomic_index_range  */
  YYSYMBOL_r_id_def = 197,                 /* r_id_def  */
  YYSYMBOL_r_def_body = 198,               /* r_def_body  */
  YYSYMBOL_param_kopt = 199,               /* param_kopt  */
  YYSYMBOL_param_kopt_list = 200,          /* param_kopt_list  */
  YYSYMBOL_typaram = 201,                  /* typaram  */
  YYSYMBOL_enum_bar = 202,                 /* enum_bar  */
  YYSYMBOL_type_def = 203,                 /* type_def  */
  YYSYMBOL_enum_functions = 204,           /* enum_functions  */
  YYSYMBOL_enum_comma = 205,               /* enum_comma  */
  YYSYMBOL_struct_field = 206,             /* struct_field  */
  YYSYMBOL_struct_fields = 207,            /* struct_fields  */
  YYSYMBOL_type_union = 208,               /* type_union  */
  YYSYMBOL_type_unions = 209,              /* type_unions  */
  YYSYMBOL_rec_measure = 210,              /* rec_measure  */
  YYSYMBOL_fun_def = 211,                  /* fun_def  */
  YYSYMBOL_212_2 = 212,                    /* $@2  */
  YYSYMBOL_mpat = 213,                     /* mpat  */
  YYSYMBOL_atomic_mpat_list = 214,         /* atomic_mpat_list  */
  YYSYMBOL_mpat_list = 215,                /* mpat_list  */
  YYSYMBOL_atomic_mpat = 216,              /* atomic_mpat  */
  YYSYMBOL_fmpat = 217,                    /* fmpat  */
  YYSYMBOL_fmpat_list = 218,               /* fmpat_list  */
  YYSYMBOL_mpexp = 219,                    /* mpexp  */
  YYSYMBOL_220_3 = 220,                    /* $@3  */
  YYSYMBOL_mapcl = 221,                    /* mapcl  */
  YYSYMBOL_222_4 = 222,                    /* $@4  */
  YYSYMBOL_223_5 = 223,                    /* $@5  */
  YYSYMBOL_mapcl_list = 224,               /* mapcl_list  */
  YYSYMBOL_map_def = 225,                  /* map_def  */
  YYSYMBOL_226_6 = 226,                    /* $@6  */
  YYSYMBOL_227_7 = 227,                    /* $@7  */
  YYSYMBOL_let_def = 228,                  /* let_def  */
  YYSYMBOL_pure_opt = 229,                 /* pure_opt  */
  YYSYMBOL_extern_binding = 230,           /* extern_binding  */
  YYSYMBOL_extern_binding_list = 231,      /* extern_binding_list  */
  YYSYMBOL_externs = 232,                  /* externs  */
  YYSYMBOL_val_spec_def = 233,             /* val_spec_def  */
  YYSYMBOL_register_def = 234,             /* register_def  */
  YYSYMBOL_default_def = 235,              /* default_def  */
  YYSYMBOL_scattered_def = 236,            /* scattered_def  */
  YYSYMBOL_237_8 = 237,                    /* $@8  */
  YYSYMBOL_238_9 = 238,                    /* $@9  */
  YYSYMBOL_239_10 = 239,                   /* $@10  */
  YYSYMBOL_240_11 = 240,                   /* $@11  */
  YYSYMBOL_loop_measure = 241,             /* loop_measure  */
  YYSYMBOL_loop_measure_list = 242,        /* loop_measure_list  */
  YYSYMBOL_subst = 243,                    /* subst  */
  YYSYMBOL_subst_list = 244,               /* subst_list  */
  YYSYMBOL_instantiation_def = 245,        /* instantiation_def  */
  YYSYMBOL_overload_def = 246,             /* overload_def  */
  YYSYMBOL_def_aux = 247,                  /* def_aux  */
  YYSYMBOL_def = 248,                      /* def  */
  YYSYMBOL_defs_list = 249,                /* defs_list  */
  YYSYMBOL_file = 250                      /* file  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  94
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1873

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  389
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  818

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   373


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     6,    15,     2,
     127,   128,     4,     7,   129,     8,   132,     5,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   133,   138,
       2,   136,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   135,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   130,    16,   131,   137,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     9,    10,
      11,    12,    13,    14,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   358,   359,   360,   361,   362,   364,   365,
     366,   367,   368,   370,   371,   372,   373,   374,   375,   377,
     378,   379,   380,   381,   382,   383,   385,   391,   392,   398,
     401,   405,   406,   407,   408,   411,   414,   417,   418,   419,
     422,   425,   426,   427,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   446,   447,
     450,   451,   452,   454,   455,   456,   457,   461,   462,   465,
     466,   467,   470,   471,   474,   475,   481,   482,   488,   489,
     490,   491,   494,   497,   498,   499,   502,   503,   504,   506,
     507,   508,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   527,   528,   529,
     532,   533,   536,   544,   552,   553,   565,   566,   567,   568,
     591,   592,   613,   614,   615,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   628,   639,   640,   641,
     642,   643,   644,   647,   648,   649,   650,   651,   654,   657,
     658,   659,   662,   663,   666,   667,   668,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   682,   685,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,   705,   706,   707,
     708,   709,   710,   711,   712,   715,   716,   719,   720,   721,
     724,   725,   726,   729,   730,   731,   734,   735,   738,   739,
     742,   743,   745,   746,   747,   748,   749,   750,   753,   754,
     757,   758,   761,   762,   763,   764,   767,   768,   771,   772,
     775,   776,   779,   780,   781,   784,   787,   788,   789,   792,
     793,   795,   796,   798,   799,   801,   802,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   814,   815,   816,   819,
     820,   821,   824,   825,   826,   827,   828,   829,   832,   835,
     836,   837,   840,   841,   842,   843,   846,   847,   848,   851,
     854,   854,   855,   858,   859,   861,   862,   864,   865,   868,
     869,   870,   871,   872,   873,   874,   875,   876,   877,   878,
     879,   880,   883,   884,   886,   887,   890,   891,   891,   894,
     895,   897,   895,   916,   917,   918,   921,   922,   923,   926,
     926,   946,   946,   961,   965,   966,   969,   970,   972,   973,
     975,   976,   977,   978,   979,   982,   983,   986,   987,   990,
     991,   994,   995,   996,   997,   998,   999,  1000,  1001,  1002,
    1007,  1015,  1002,  1016,  1016,  1072,  1075,  1076,  1077,  1079,
    1080,  1083,  1084,  1086,  1087,  1089,  1090,  1093,  1094,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1114,  1115,  1116,  1118,  1119,  1121,  1122
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'^'", "'*'", "'/'",
  "'%'", "'+'", "'-'", "LESS", "LESS_OR_EQUAL", "EQUAL", "GREATER",
  "GREATER_OR_EQUAL", "NOT_EQUAL", "'&'", "'|'", "UNARY_MINUS", "And",
  "As", "Assert", "Bitzero", "Bitone", "By", "Match", "Clause", "Dec",
  "Default", "Effect", "End", "Op", "Enum", "Else", "False", "Forall",
  "Foreach", "Overload", "Function_", "Mapping", "If_", "In", "Inc",
  "Let_", "Int", "Order", "Bool", "Cast", "Pure", "Monadic", "Register",
  "Return", "Scattered", "Sizeof", "Struct", "Then", "True", "TwoCaret",
  "TYPE", "Typedef", "Undefined", "Union", "Newtype", "With", "Val",
  "Outcome", "Constraint", "Throw", "Try", "Catch", "Exit", "Bitfield",
  "Constant", "Repeat", "Until", "While", "Do", "Mutual", "Var", "Ref",
  "Configuration", "TerminationMeasure", "Instantiation", "Impl",
  "Private", "InternalPLet", "InternalReturn", "InternalAssume",
  "Forwards", "Backwards", "Bar", "Comma", "Dot", "Eof", "Minus", "Semi",
  "Under", "DotDot", "At", "ColonColon", "Caret", "Star", "Lcurly",
  "Rcurly", "Lparen", "Rparen", "Lsquare", "Rsquare", "LcurlyBar",
  "RcurlyBar", "LsquareBar", "RsquareBar", "MinusGt", "Bidir", "Eq",
  "EqGt", "Unit", "Colon", "OpId", "Attribute", "LINE_DIRECTIVE", "FIXITY",
  "ID", "TyVar", "Num", "Bin_literal", "Hex_literal", "STRING_LITERAL",
  "'('", "')'", "','", "'{'", "'}'", "'.'", "':'", "'['", "']'", "'='",
  "'~'", "';'", "$accept", "id", "op_no_caret", "op", "exp_op", "pat_op",
  "typ_var", "tyarg", "prefix_typ_op", "postfix_typ", "typ_no_caret",
  "list_1", "typ", "list_2", "atomic_typ", "num_list", "typ_list", "kind",
  "kid_list", "kopt", "kopt_list", "quantifier", "id_list", "typschm",
  "pat1", "list_3", "pat", "pat_list", "atomic_pat", "fpat", "fpat_list",
  "lit", "internal_loop_measure", "exp", "$@1", "prefix_op", "exp0",
  "list_4", "case", "case_list", "block", "letbind", "atomic_exp",
  "fexp_exp", "fexp_exp_list", "exp_list", "vector_update",
  "vector_update_list", "funcl_annotation", "funcl_patexp",
  "funcl_patexp_typ", "funcl", "funcl_list", "funcls", "funcl_typ",
  "index_range", "paren_index_range", "atomic_index_range", "r_id_def",
  "r_def_body", "param_kopt", "param_kopt_list", "typaram", "enum_bar",
  "type_def", "enum_functions", "enum_comma", "struct_field",
  "struct_fields", "type_union", "type_unions", "rec_measure", "fun_def",
  "$@2", "mpat", "atomic_mpat_list", "mpat_list", "atomic_mpat", "fmpat",
  "fmpat_list", "mpexp", "$@3", "mapcl", "$@4", "$@5", "mapcl_list",
  "map_def", "$@6", "$@7", "let_def", "pure_opt", "extern_binding",
  "extern_binding_list", "externs", "val_spec_def", "register_def",
  "default_def", "scattered_def", "$@8", "$@9", "$@10", "$@11",
  "loop_measure", "loop_measure_list", "subst", "subst_list",
  "instantiation_def", "overload_def", "def_aux", "def", "defs_list",
  "file", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-532)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-320)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     410,   346,    53,    32,    53,    15,    67,  1462,    53,   370,
      53,    53,    53,   122,    53,    53,    53,   410,   410,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,   410,  -532,    87,  -532,  -532,  -532,  -532,    55,
     208,  -532,  -532,    53,    68,   -31,   198,  1462,   198,   198,
       7,    -3,   134,  -532,  -532,  -532,   154,  -532,  -532,  -532,
    1376,  -532,  1462,  -532,  -532,  -532,  -532,  -532,  1462,  1462,
     155,  -532,   292,   185,    46,  -532,  -532,   173,    53,    53,
      53,    53,   125,   287,   283,   301,   201,   211,   216,  1299,
     270,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,   224,    53,    25,    35,  -532,  -532,  1505,    53,
    -532,   267,  1421,    53,  -532,  -532,  -532,   269,   327,   191,
    -532,   295,   311,  -532,   343,   297,  -532,  1462,   315,   232,
    1233,  -532,  -532,  -532,   232,  1623,  -532,   232,  -532,  -532,
     309,   326,   338,   332,   328,   346,   232,   -47,   349,   333,
    -532,   327,   226,   341,   232,  1233,  1233,  1233,   356,   372,
    -532,   171,    53,   402,   384,    53,   508,  -532,    53,  -532,
    1462,   401,  -532,  1505,  1233,   -32,  1462,   -13,   524,  -532,
    1421,   415,   422,  -532,  -532,   -32,  -532,  1743,   339,   418,
    -532,    21,   419,  -532,   427,  1462,  -532,  -532,  1462,  -532,
     425,   -25,  -532,  -532,  -532,  -532,   432,  1233,  1462,  1233,
    -532,  1233,  1233,   482,   482,  1323,  1233,  1256,  -532,  -532,
    1323,   428,  1743,  -532,    46,   429,   366,  -532,   430,   437,
     439,    53,   438,   433,  -532,   346,   232,   215,   440,    53,
    -532,  -532,  -532,  -532,   196,   121,   327,   435,  -532,  -532,
    -532,  1233,   362,   436,   441,   444,  -532,  -532,   232,   445,
     -30,   443,    53,   451,   450,   186,  1233,  -532,   452,     2,
    -532,   -32,   453,   457,   199,   232,  1233,   198,   567,  -532,
    1546,  1546,   462,  -532,  -532,   465,  -532,   472,   232,   322,
     469,  -532,   110,  -532,  -532,   232,   232,   467,   191,  1462,
    -532,  -532,   470,  -532,   477,  -532,  1233,    53,   547,   562,
    -532,  -532,   536,   475,  1233,  1233,   479,   480,   478,   484,
      53,   754,  1233,  1233,  1009,   291,  -532,  -532,   353,  -532,
    1462,  1323,   471,   481,    50,  1233,   206,  -532,  1233,   -32,
    -532,  -532,   346,   338,   485,   486,   488,   487,    53,   232,
     490,  -532,   215,   215,   489,   491,   492,   215,   493,   495,
     498,   506,   505,  -532,   196,  -532,   507,  -532,  -532,    53,
     232,   171,   509,    53,  1233,    53,  -532,  -532,    53,  -532,
    1233,  -532,  -532,   517,   517,   510,  -532,   232,  1582,  1233,
     504,   597,   603,  -532,   198,   511,  1662,  1662,  1078,  1546,
    1662,  1662,   253,  -532,   605,  -532,    40,   528,  -532,   521,
     515,   232,   232,   522,   544,   354,   523,   280,   232,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,   232,  -532,  -532,  -532,
    -532,  -532,  -532,  -532,   518,   525,   535,  1233,  1233,   530,
    1233,   585,   586,  1233,   232,  1323,   232,  -532,  -532,   533,
     553,   369,   602,  -532,   170,   534,    53,  -532,  1233,    53,
    1743,  1233,  1233,    34,   374,   877,  -532,  -532,  -532,  -532,
    -532,  -532,  -532,  -532,    44,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,   232,   206,  -532,   539,  -532,  -532,   232,   232,
      53,  -532,   537,  -532,   232,  -532,  -532,    64,   215,  -532,
     542,  -532,   546,   548,   196,  -532,   545,    53,  -532,  -532,
    -532,    53,   550,   538,  -532,  -532,   549,   552,  -532,   346,
    -532,  1462,   554,   551,  1233,   198,  -532,    53,   569,   572,
    -532,   559,   581,  -532,   375,   557,  -532,  1662,   570,   657,
      53,   232,  1662,  1233,   588,  1546,  -532,   344,   573,   472,
    -532,  -532,   232,  -532,   232,   232,   568,   574,  1743,  1546,
    -532,  1462,  1323,   666,  -532,  1462,   575,  1233,  1233,   417,
     579,   302,   382,   580,   577,   582,   167,  -532,  -532,  1233,
    1323,  1323,  -532,   227,   584,   289,  -532,   -10,   663,  1117,
    1233,  -532,  1323,  1743,   232,   232,  -532,  -532,  -532,  -532,
    -532,    53,  -532,  -532,  -532,   215,  -532,  -532,  -532,  -532,
     583,   589,   590,  -532,  -532,    53,   578,   346,   591,   210,
     232,   119,  -532,  -532,   587,   593,   594,  1233,  1233,  1662,
    -532,  -532,  1662,  -532,   592,   -14,  1233,  -532,  -532,  -532,
      72,  -532,  -532,  -532,   232,   232,  -532,  -532,   596,   595,
     598,    52,  -532,   110,   599,   180,   604,   600,   294,  1233,
     601,  -532,  -532,  -532,  -532,  1233,  -532,  1233,  1323,  -532,
    -532,  -532,   606,   608,   230,   252,   613,   609,  -532,  1233,
    -532,  -532,  1233,  1233,  1233,  -532,  1233,  -532,    69,    50,
    -532,  1743,  -532,   612,  -532,    59,    53,  -532,  -532,  1233,
     607,  -532,  1233,   610,   232,  1233,  1662,    53,  -532,  -532,
    -532,  -532,   617,  -532,   614,  -532,  -532,  1662,  -532,  -532,
    -532,   232,  -532,  -532,  -532,  -532,  1233,  1233,  1462,  -532,
    1323,  -532,  -532,   621,  -532,  -532,  -532,  -532,  1323,  1233,
    1323,  -532,   624,   626,   620,   622,  -532,  1172,  -532,  -532,
    -532,    59,   630,  -532,   616,  -532,  -532,  -532,  -532,   628,
    1233,   623,   699,  -532,  -532,  -532,   625,  -532,   632,   647,
    -532,  -532,   131,  -532,   400,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,   668,   669,   232,    59,   654,  -532,  1233,  -532,
    -532,  1233,  1323,  1233,  1233,   232,    59,  -532,  -532,   232,
    -532,  -532,   175,  -532,  -532,   640,   641,   634,   232,  1233,
    -532,  -532,  1233,   645,  -532,  -532,  1233,  -532
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     389,     0,     0,     0,     0,   280,     0,     0,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,   380,
     371,   374,   369,   370,   375,   372,   376,   379,   378,   373,
     377,   385,   386,   388,     0,    63,    65,    66,    64,     0,
       0,     2,   355,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,   117,   118,   113,     0,   112,   116,    92,
       0,   114,     0,    29,   115,   119,   120,   121,     0,     0,
      94,    95,    86,     0,    85,    93,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   330,     0,     0,
     365,   383,   384,   387,     1,   340,   339,     6,     7,     4,
       5,     3,     0,     0,     0,     0,   208,   209,     0,     0,
     348,     0,     0,     0,   282,   281,   353,     0,    31,     0,
     104,    89,     0,    87,     0,     0,    96,     0,     0,    31,
     143,    28,    26,    27,    31,     0,    82,    31,   341,   344,
     345,   343,     0,     0,     0,     0,    31,     0,     0,     0,
     350,    31,     0,     0,    31,   143,   143,   143,     0,   359,
     382,     0,     0,     0,     0,     0,   245,   253,     0,   368,
       0,     0,   219,     0,   143,     0,     0,     0,     0,   223,
       0,     0,     0,    34,    33,     0,    32,     0,     0,     0,
     109,     0,   108,   110,     0,    90,   105,   101,     0,   103,
       0,     0,    88,   146,   145,   135,     0,   143,     0,   143,
     144,   143,   143,   122,   122,     0,   143,   143,   147,   166,
       0,   125,     0,   100,    83,   337,    31,   342,   240,   241,
       0,     0,     0,     0,   248,     0,    31,     0,     0,     0,
     335,   325,   324,   331,     0,     0,    31,     0,   357,   356,
     358,   143,     0,     0,     0,   363,   366,   347,    31,     0,
     262,     0,     0,    76,     0,     0,   143,   218,     0,     0,
      71,    72,    75,     0,     0,    31,   143,     0,     0,   222,
       0,     0,     0,    48,    49,     0,    45,     0,    31,     0,
      44,    46,    43,    35,    47,    31,    31,     0,     0,     0,
     106,    91,     0,    99,     0,    97,   143,     0,     0,     0,
     131,   132,     0,     0,   143,   143,     0,     0,     0,     0,
       0,   143,   143,   143,   143,   174,   175,   168,     0,   126,
       0,     0,   157,     0,   149,   143,    39,    84,   143,     0,
     227,   346,     0,     0,   244,     0,   269,     0,     0,    31,
       0,   247,     0,     0,     0,   276,     0,     0,     0,     0,
       0,   328,     0,   333,     0,   336,     0,   381,   360,     0,
      31,     0,   261,     0,   143,   263,   254,   246,     0,   367,
     143,   210,   279,     0,    67,     0,    73,    31,     0,   143,
       0,   212,   220,   225,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   289,   306,   283,   285,   310,   354,   316,
       0,    31,    31,    59,     0,     0,     0,     0,    31,    50,
      16,    17,    14,    15,    18,    13,    31,    40,    78,    80,
     321,   111,   107,   102,     0,     0,     0,   143,   143,     0,
     143,     0,     0,   143,    31,     0,    31,   176,   189,   200,
       0,     0,     0,   186,   200,     0,     0,   177,   143,     0,
       0,   143,   143,   159,     0,   143,   130,    24,    25,    20,
      21,    22,    23,    19,   143,   148,   127,    11,     9,    10,
      12,     8,    31,    36,   338,     0,   239,   242,    31,    31,
     270,   251,     0,   250,    31,   272,   273,    31,   277,   256,
       0,   351,     0,     0,     0,   332,     0,     0,   362,   361,
     364,   260,     0,   264,   266,    77,     0,     0,    68,     0,
      74,     0,     0,     0,   143,     0,   224,     0,     0,     0,
     298,   287,     0,   309,     0,     0,   293,     0,     0,     0,
       0,    31,     0,   143,     0,   317,   320,     0,     0,     0,
      55,    52,    31,    54,    31,    31,    60,     0,     0,     0,
      98,     0,     0,   134,   128,     0,     0,   143,   143,     0,
       0,   174,     0,   197,     0,     0,   143,   190,   191,   143,
       0,     0,   187,     0,     0,   173,   167,     0,     0,   143,
     143,   165,     0,     0,    31,    31,   243,   268,   271,   252,
     249,     0,   274,   278,   257,     0,   327,   326,   329,   334,
       0,   236,     0,   259,   255,   265,     0,     0,     0,     0,
      31,     0,   213,   221,   303,   304,     0,   143,   143,     0,
     299,   295,     0,   297,     0,     0,   143,   284,   300,   286,
     285,   313,   311,   318,    31,    31,    51,    58,     0,     0,
       0,    31,    30,    42,     0,     0,   154,     0,     0,   143,
       0,   124,   141,   142,   193,   143,   179,   143,   198,   184,
     180,   202,     0,     0,   174,     0,   206,     0,   169,   143,
     178,   171,   143,   143,   143,   181,   143,   161,   162,   149,
      38,     0,   226,     0,   352,    31,   237,   258,   267,   143,
       0,    70,   143,     0,    31,   143,     0,     0,   301,   314,
     315,   288,     0,   294,     0,   291,   308,     0,    79,    81,
      53,    31,    56,    62,    41,   322,   143,   143,   155,   136,
       0,   133,   137,     0,   195,   199,   192,   185,     0,   143,
       0,   188,     0,     0,     0,     0,   129,   143,   151,    37,
     275,    31,   232,   235,   229,   231,   238,   211,    69,     0,
     143,     0,   215,   302,   305,   296,     0,   312,     0,     0,
     152,   156,     0,   194,     0,   203,   207,   170,   172,   182,
     183,   164,   232,     0,    31,    31,     0,   214,   143,   292,
      57,   143,     0,   143,   143,    31,    31,   233,   228,    31,
     216,   153,     0,   140,   204,   233,     0,     0,    31,   143,
     234,   230,   143,     0,   139,   217,   143,   138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -532,    -2,   293,  -532,  -532,  -374,   -81,  -532,  -116,  -215,
     233,  -532,   541,   126,   320,  -266,  -502,  -142,   111,   494,
     513,  -152,   403,  -106,  -532,   558,    23,     0,   650,   611,
     496,   460,   618,   310,  -532,   312,  -532,    98,  -532,  -531,
    -460,  -166,  -199,  -532,  -492,  -307,  -532,    48,   499,   164,
     615,   746,  -357,   748,  -532,  -472,    47,  -532,  -532,   104,
    -532,   458,   217,   -70,  -532,   296,  -344,  -532,  -333,  -325,
    -321,  -532,  -532,  -532,  -376,   261,  -375,   263,  -532,    99,
    -377,  -532,  -241,  -532,  -532,  -423,  -532,  -532,  -532,  -532,
    -532,  -532,  -326,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,  -532,   556,  -532,   442,  -532,  -532,  -532,   532,
     777,  -532
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    70,   482,   426,   474,   135,    71,   419,   187,   292,
     223,   483,   188,   427,   293,   414,   557,    39,   385,   271,
     272,   273,   264,   189,    72,   136,   121,   122,    74,   193,
     194,    75,   314,   449,   306,   220,   221,   475,   656,   657,
     333,    76,   572,   573,   574,   450,   676,   677,   109,   172,
     179,   392,   393,   114,   341,   753,   754,   755,   611,   612,
     229,   230,   144,   167,    21,   164,   261,   346,   347,   355,
     356,    48,    22,    49,   404,   405,   532,   406,   625,   626,
     407,   539,   409,   544,   717,   410,    23,   117,   559,    24,
     245,   361,   362,   153,    25,    26,    27,    28,    85,   239,
     605,   181,   159,   160,   255,   256,    29,    30,    31,    32,
      33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    44,    45,   233,    52,   591,    77,   336,    82,    83,
      84,    87,    88,    89,    90,   492,   328,   455,   222,   528,
     529,   334,   531,   416,   534,   531,   535,   495,   496,   512,
      73,   514,   542,   282,   660,   169,   500,   526,   506,   408,
      46,   102,   309,   131,   108,   240,   112,   112,   203,   131,
     648,    40,   204,   467,   468,    40,   183,    43,   469,   540,
     184,   228,    40,   183,   235,    40,   470,   184,   183,   125,
     111,   304,   184,   383,   438,   131,   138,   139,   140,   141,
     254,    95,   714,    40,   374,   123,   683,    94,   673,   236,
      63,   124,    50,   350,   270,   269,    96,    40,   275,   375,
     210,   163,   166,   166,   270,   105,   291,   173,   186,   686,
     305,   180,   158,   420,   421,   186,   190,   192,   422,   684,
     186,   715,   643,   276,   384,   685,   423,   200,   116,   687,
     103,   171,   464,  -319,   326,   177,   654,   132,   133,   326,
     365,   291,    41,   132,   133,    47,    41,   471,   472,   723,
     424,   584,    40,    41,   792,   165,    41,   598,   533,   253,
     257,   531,   634,   260,   463,   168,   263,   473,   623,   132,
     133,   203,   589,   541,    41,   204,   735,   603,   608,   134,
     -61,   218,   459,   460,   461,   290,   751,   485,    51,   192,
     270,   205,   377,   265,   601,   301,   171,   771,   302,   274,
     486,    40,   206,   177,   104,   541,   207,   747,   270,   208,
     477,    97,    98,   325,   478,   808,    99,   209,   325,   726,
     290,    40,   479,   210,   100,   380,    40,   425,    40,   345,
     704,    73,   581,   211,   212,   354,   183,   358,   389,   213,
     184,   214,   360,    41,   215,    40,   480,   363,    86,   702,
     326,   364,   142,   531,   711,   705,   531,   712,   270,   793,
     166,   143,   228,   459,   460,   461,   542,   118,   693,   671,
     126,   698,   672,   241,   242,   108,   178,  -201,   402,   402,
     694,   106,   127,   647,   119,   216,   190,   781,   186,   128,
     254,   359,    41,    63,   727,  -201,   192,   217,   352,   576,
     147,   149,  -201,   809,   218,   436,   137,   459,   460,   461,
     558,   129,    41,   798,   197,   198,   107,    41,   447,    41,
     191,   130,   432,   481,   806,   101,   150,   197,   198,   325,
     763,   183,   161,   353,   151,   184,    41,   267,   197,   198,
     767,   456,   678,   653,   278,   457,   345,   152,   738,   154,
     354,   354,   243,    73,   679,   354,   244,   458,   227,  -205,
     162,   185,   360,   658,   326,  -205,   593,   508,   536,   253,
     183,   260,   742,   260,   184,   743,   263,   618,   690,   291,
     537,   174,   675,   186,   459,   460,   461,   538,   739,    35,
      36,    37,   108,   689,   402,   402,   402,   402,   402,   402,
     339,    78,   456,    38,   681,   182,   457,    79,    80,   554,
     142,   522,   555,   456,   142,   730,   682,   457,   458,   148,
     145,   196,   186,   146,   195,   222,   459,   460,   461,   458,
      81,  -196,   199,  -196,   155,   156,   157,     1,   201,     2,
     219,     3,   226,   571,    63,   413,     4,     5,     6,   269,
     295,   296,     7,   142,   583,   644,   645,   585,   290,     8,
      63,     9,   231,    10,   232,   248,   249,   250,    11,   238,
      12,   197,   198,    13,   246,   700,   749,   291,   691,   237,
      14,   326,   551,   552,   268,   459,   460,   461,   345,   462,
      15,    16,   251,    17,   517,   518,   354,   578,   579,   326,
     326,   252,   360,   631,   632,   610,   459,   460,   461,   163,
     590,   326,   291,   258,   459,   460,   461,   308,   667,   310,
     259,   311,   312,   108,   262,   624,   329,   332,    18,    19,
      20,   772,   459,   460,   461,   402,   794,   266,   637,   774,
     402,   675,   277,   402,   619,   664,   665,   113,   113,    91,
      92,   280,   281,   303,   297,   299,   290,   402,   300,   307,
     325,   367,   313,   342,   335,   338,   343,   344,   348,   349,
     357,   366,   369,   371,   376,   373,   381,   370,   571,   674,
     378,   379,   387,   382,   655,   394,   391,   326,   655,   388,
     325,   290,   412,   802,   411,   413,   418,   430,   433,   345,
     434,   437,   438,   354,   439,   440,   443,   444,   445,   465,
     291,   446,   466,   260,   488,  -210,   435,   490,   491,   489,
     498,   525,   497,   499,   441,   442,   494,   402,   502,   501,
     402,   503,   451,   452,   454,   504,   505,   507,   511,   384,
     524,   527,   543,   519,  -307,   476,   546,   294,   484,   326,
     545,   549,   550,   560,   553,   561,   562,   326,   567,   326,
     565,   568,   576,   577,   580,   620,   571,   615,   599,   582,
     202,   595,   606,   604,   607,   327,   609,   616,   225,   621,
     327,   614,   294,   627,   513,   617,   628,   234,   629,   290,
     516,   630,   633,   635,   610,   247,   636,   651,   659,   523,
     642,   646,   652,   686,   402,   624,   661,   666,   669,   668,
     670,   326,   680,   785,   699,   402,   695,  -211,   696,   701,
     713,   697,   707,   706,   720,   708,   784,   721,   325,   722,
     725,   729,   732,   728,   736,   758,   325,   766,   674,   737,
     403,   403,   740,   750,   741,   765,   760,   563,   564,   773,
     566,   655,   777,   569,   778,   779,   786,   780,   203,   788,
     789,   791,   204,   790,   795,   799,   796,   340,   810,   811,
     812,   587,   588,   816,   638,   332,   594,   351,   205,   724,
     586,   515,   337,   417,   386,   224,   592,   748,   776,   206,
     325,   327,   110,   207,   431,   279,   208,   115,   783,   372,
     756,   487,   298,   639,   209,   640,   764,   613,   368,    93,
     210,     0,     0,   510,     0,     0,   390,     0,     0,     0,
     211,   212,     0,     0,     0,     0,   213,     0,   214,   415,
       0,   215,   315,     0,   622,     0,   428,   429,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,     0,     0,   403,   403,   403,   403,
     403,   403,     0,     0,   448,     0,     0,     0,     0,     0,
       0,     0,   216,     0,     0,     0,     0,   662,   663,     0,
       0,   203,     0,     0,   217,   204,     0,     0,     0,     0,
     493,   218,     0,     0,     0,     0,     0,     0,     0,   332,
     688,   205,     0,     0,     0,   327,     0,     0,     0,     0,
       0,   509,   206,     0,     0,     0,   207,     0,     0,   330,
     294,     0,     0,     0,     0,     0,     0,   209,   520,     0,
       0,     0,     0,   210,     0,     0,     0,   709,   710,     0,
       0,     0,     0,   211,   212,     0,   716,     0,     0,   213,
       0,   214,   547,   548,   331,     0,     0,     0,     0,   556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   731,
       0,     0,     0,     0,     0,   733,     0,   734,     0,     0,
       0,     0,     0,     0,     0,   570,     0,   575,     0,     0,
       0,     0,     0,   744,   745,   216,   746,   403,     0,     0,
       0,     0,   403,     0,     0,   403,     0,   217,  -158,   757,
       0,     0,   759,   203,   218,   762,     0,   204,   294,   403,
       0,     0,   327,     0,     0,     0,     0,     0,     0,   596,
     597,     0,     0,   205,     0,   600,   769,   770,   602,     0,
     327,   327,     0,     0,   206,     0,     0,     0,   207,   775,
       0,   208,   327,   294,     0,     0,     0,   332,     0,   209,
       0,     0,     0,     0,     0,   210,     0,     0,     0,     0,
     787,     0,     0,     0,     0,   211,   212,     0,     0,     0,
       0,   213,     0,   214,     0,     0,   215,     0,     0,   403,
       0,     0,   403,   556,     0,   649,   650,     0,   800,    53,
      54,   801,     0,   803,   804,     0,     0,     0,    40,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,   814,
       0,   203,   815,     0,     0,   204,   817,   216,   327,     0,
       0,   395,     0,    57,     0,     0,   692,    58,     0,   217,
       0,   205,     0,     0,   453,     0,   218,     0,     0,     0,
       0,   294,   206,     0,     0,     0,   207,     0,     0,   330,
       0,   703,     0,     0,     0,     0,   403,   209,     0,     0,
       0,     0,     0,   210,     0,     0,   203,   403,     0,     0,
     204,     0,     0,   211,   212,   718,   719,   398,   530,   213,
     327,   214,   556,    61,   331,     0,   205,     0,   327,    41,
     327,    64,    65,    66,    67,   400,     0,   206,     0,     0,
       0,   207,   401,     0,   330,     0,     0,     0,     0,     0,
       0,     0,   209,     0,     0,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,   216,   752,   203,   211,   212,
       0,   204,     0,     0,   213,   761,   214,   217,  -160,   331,
       0,     0,   327,     0,   218,     0,     0,   205,     0,     0,
     203,     0,   768,     0,   204,     0,     0,     0,   206,     0,
       0,     0,   207,     0,     0,   208,     0,     0,     0,     0,
     205,     0,     0,   209,     0,     0,     0,     0,     0,   210,
     216,   206,   782,     0,     0,   207,     0,     0,   330,   211,
     212,     0,   217,  -163,     0,   213,   209,   214,     0,   218,
     215,     0,   210,     0,     0,     0,     0,     0,     0,     0,
      53,    54,   211,   212,     0,   797,   752,     0,   213,    40,
     214,     0,    55,   331,     0,     0,   805,   752,     0,     0,
     807,     0,     0,   316,    53,    54,     0,     0,     0,   813,
       0,   216,    56,    40,    57,     0,    55,     0,    58,     0,
       0,     0,     0,   217,     0,     0,     0,     0,     0,     0,
     218,   155,   156,   157,   216,   317,   318,     0,    57,     0,
       0,     0,    58,     0,     0,     0,   217,     0,   319,     0,
       0,     0,     0,   218,    59,     0,     0,    53,    54,     0,
       0,   320,     0,     0,     0,     0,    40,     0,    60,    55,
       0,     0,     0,     0,    61,     0,     0,    62,     0,     0,
      41,    63,    64,    65,    66,    67,    68,     0,     0,    56,
       0,    57,   321,    69,     0,    58,     0,     0,    61,     0,
       0,     0,    53,    54,    41,    63,    64,    65,    66,    67,
     322,    40,     0,   323,    55,   175,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,     0,     0,    56,     0,    57,     0,     0,     0,
      58,     0,     0,    53,    54,    60,   120,     0,     0,     0,
       0,    61,    40,     0,    62,    55,     0,    41,    63,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,     0,    56,    59,    57,     0,     0,
       0,    58,     0,     0,     0,     0,    53,    54,     0,     0,
      60,     0,     0,     0,     0,    40,    61,     0,    55,    62,
       0,     0,    41,    63,    64,    65,    66,    67,   176,     0,
       0,     0,     0,     0,     0,    69,     0,    59,    56,     0,
      57,     0,     0,     0,    58,     0,     0,    53,    54,     0,
       0,    60,     0,     0,     0,     0,    40,    61,     0,    55,
      62,     0,     0,    41,    63,    64,    65,    66,    67,    68,
       0,     0,     0,     0,     0,     0,    69,     0,     0,   395,
      59,    57,     0,    53,    54,    58,     0,     0,     0,     0,
       0,     0,    40,     0,    60,    55,     0,     0,     0,     0,
      61,     0,     0,    62,     0,     0,    41,    63,    64,    65,
      66,    67,   170,   396,   397,    56,     0,    57,     0,    69,
       0,    58,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,    40,     0,   398,    55,     0,     0,     0,
       0,    61,     0,     0,   399,     0,     0,    41,     0,    64,
      65,    66,    67,   400,     0,     0,    56,    59,    57,     0,
     401,     0,    58,    53,    54,     0,     0,     0,     0,     0,
       0,    60,    40,     0,     0,    55,     0,    61,     0,     0,
      62,     0,     0,    41,    63,    64,    65,    66,    67,   521,
       0,     0,     0,     0,     0,   395,    69,    57,    59,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,    41,    63,    64,    65,    66,    67,
      68,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,    53,    54,     0,     0,     0,   283,
       0,   398,     0,    40,     0,     0,    55,    61,     0,     0,
       0,     0,     0,    41,   284,    64,    65,    66,    67,   400,
       0,     0,   285,     0,     0,     0,   401,     0,    57,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,    41,    63,    64,    65,    66,    67,
     288,     0,     0,   289
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,   145,     6,   465,     8,   222,    10,    11,
      12,    13,    14,    15,    16,   348,   215,   324,   134,   396,
     397,   220,   398,   289,   400,   401,   401,   352,   353,   373,
       7,   375,   406,   185,   565,   105,   357,   394,   364,   280,
      25,    43,   208,     3,    46,   151,    48,    49,     4,     3,
     552,    30,     8,     3,     4,    30,     4,    25,     8,    19,
       8,   142,    30,     4,   111,    30,    16,     8,     4,    69,
      47,    96,     8,    71,    40,     3,    78,    79,    80,    81,
     161,    26,    96,    30,   114,    62,    96,     0,   580,   136,
     122,    68,    25,   235,   175,   127,    41,    30,   111,   129,
      56,   103,   104,   105,   185,   136,   187,   109,    56,    40,
     135,   113,    89,     3,     4,    56,    95,   119,     8,   129,
      56,   135,   545,   136,   122,   135,    16,   127,   121,   589,
      62,   108,   331,   136,   215,   112,   559,    97,    98,   220,
     246,   222,   121,    97,    98,   130,   121,    97,    98,   651,
      40,   458,    30,   121,    23,   130,   121,   490,   399,   161,
     162,   537,   537,   165,   330,   130,   168,   117,   525,    97,
      98,     4,   138,   133,   121,     8,   668,   498,   504,   133,
     128,   137,   132,   133,   134,   187,   127,   339,   121,   191,
     271,    24,   262,   170,   130,   195,   173,   728,   198,   176,
     342,    30,    35,   180,   136,   133,    39,   138,   289,    42,
       4,     3,     4,   215,     8,    40,     8,    50,   220,    39,
     222,    30,    16,    56,    16,    39,    30,   117,    30,   231,
     111,   208,    62,    66,    67,   237,     4,   239,    39,    72,
       8,    74,   244,   121,    77,    30,    40,   126,   126,    39,
     331,   130,   127,   629,   629,   136,   632,   632,   339,   128,
     262,   136,   343,   132,   133,   134,   640,   133,   601,   576,
     115,   615,   579,    47,    48,   277,   112,   110,   280,   281,
     605,    83,   127,   549,   130,   118,    95,   747,    56,   134,
     371,    95,   121,   122,   114,   128,   298,   130,    83,   129,
      83,    84,   135,   128,   137,   307,   133,   132,   133,   134,
     426,    19,   121,   785,   128,   129,   118,   121,   320,   121,
     129,   136,   299,   117,   796,   117,    25,   128,   129,   331,
     706,     4,    62,   118,   133,     8,   121,   173,   128,   129,
     717,   111,   115,   558,   180,   115,   348,   136,    96,   133,
     352,   353,   126,   330,   127,   357,   130,   127,   141,   129,
     136,    34,   364,   562,   445,   135,   482,   369,   115,   371,
       4,   373,   679,   375,     8,   682,   378,   519,   593,   460,
     127,   114,   581,    56,   132,   133,   134,   134,   136,    43,
      44,    45,   394,   592,   396,   397,   398,   399,   400,   401,
      34,    31,   111,    57,   115,   136,   115,    37,    38,   129,
     127,   388,   132,   111,   127,   121,   127,   115,   127,   136,
     133,   110,    56,   136,   129,   541,   132,   133,   134,   127,
      60,   129,   135,   131,    72,    73,    74,    27,   123,    29,
     130,    31,   133,   445,   122,   123,    36,    37,    38,   127,
     111,   112,    42,   127,   456,   111,   112,   459,   460,    49,
     122,    51,   130,    53,   136,   155,   156,   157,    58,   136,
      60,   128,   129,    63,   133,   617,   691,   558,   594,   130,
      70,   562,   128,   129,   174,   132,   133,   134,   490,   136,
      80,    81,   136,    83,   383,   384,   498,   128,   129,   580,
     581,   129,   504,   128,   129,   507,   132,   133,   134,   511,
     136,   592,   593,   111,   132,   133,   134,   207,   136,   209,
     136,   211,   212,   525,    16,   527,   216,   217,   118,   119,
     120,   730,   132,   133,   134,   537,   136,   136,   540,   738,
     542,   740,    18,   545,   521,   128,   129,    48,    49,    17,
      18,   136,   130,   128,   136,   136,   558,   559,   131,   127,
     562,   251,    80,   133,   136,   136,   129,   128,   130,   136,
     130,   136,   136,   129,   131,   130,   266,   136,   580,   581,
     129,   131,   129,   131,   561,    18,   276,   668,   565,   132,
     592,   593,   127,   792,   132,   123,   127,   130,   128,   601,
     123,    54,    40,   605,    68,   130,   127,   127,   130,   138,
     691,   127,   131,   615,   129,    18,   306,   129,   131,   133,
     129,    18,   133,   131,   314,   315,   136,   629,   133,   136,
     632,   133,   322,   323,   324,   129,   131,   130,   129,   122,
     136,   130,   114,   133,    39,   335,   131,   187,   338,   730,
     129,   129,   108,   135,   131,   130,   121,   738,    73,   740,
     130,    75,   129,   110,    62,   111,   668,   129,   131,   135,
     129,   132,   126,   131,   126,   215,   131,   128,   137,   128,
     220,   131,   222,   114,   374,   133,   114,   146,   129,   691,
     380,   110,   135,   123,   696,   154,    39,   129,    32,   389,
     112,   128,   128,    40,   706,   707,   131,   128,   131,   129,
     128,   792,   128,    97,   136,   717,   133,    18,   129,   128,
     128,   131,   129,   136,   128,   131,    96,   132,   730,   131,
     131,   131,   131,   129,   128,   128,   738,   123,   740,   131,
     280,   281,   129,   131,   135,   128,   136,   437,   438,   128,
     440,   728,   128,   443,   128,   135,   128,   135,     4,   136,
     135,   114,     8,   131,    96,   111,    97,   226,   128,   128,
     136,   461,   462,   128,   541,   465,   483,   236,    24,   653,
     460,   378,   224,   289,   271,   135,   474,   689,   740,    35,
     792,   331,    46,    39,   298,   180,    42,    49,   751,   258,
     696,   343,   191,   542,    50,   542,   707,   511,   252,    32,
      56,    -1,    -1,   371,    -1,    -1,   275,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    72,    -1,    74,   288,
      -1,    77,   214,    -1,   524,    -1,   295,   296,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   543,    -1,    -1,   396,   397,   398,   399,
     400,   401,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,   567,   568,    -1,
      -1,     4,    -1,    -1,   130,     8,    -1,    -1,    -1,    -1,
     349,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,
     590,    24,    -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,
      -1,   370,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    50,   387,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,   627,   628,    -1,
      -1,    -1,    -1,    66,    67,    -1,   636,    -1,    -1,    72,
      -1,    74,   411,   412,    77,    -1,    -1,    -1,    -1,   418,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   659,
      -1,    -1,    -1,    -1,    -1,   665,    -1,   667,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   444,    -1,   446,    -1,    -1,
      -1,    -1,    -1,   683,   684,   118,   686,   537,    -1,    -1,
      -1,    -1,   542,    -1,    -1,   545,    -1,   130,   131,   699,
      -1,    -1,   702,     4,   137,   705,    -1,     8,   558,   559,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,   488,
     489,    -1,    -1,    24,    -1,   494,   726,   727,   497,    -1,
     580,   581,    -1,    -1,    35,    -1,    -1,    -1,    39,   739,
      -1,    42,   592,   593,    -1,    -1,    -1,   747,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
     760,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    72,    -1,    74,    -1,    -1,    77,    -1,    -1,   629,
      -1,    -1,   632,   552,    -1,   554,   555,    -1,   788,    21,
      22,   791,    -1,   793,   794,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   809,
      -1,     4,   812,    -1,    -1,     8,   816,   118,   668,    -1,
      -1,    53,    -1,    55,    -1,    -1,   595,    59,    -1,   130,
      -1,    24,    -1,    -1,   135,    -1,   137,    -1,    -1,    -1,
      -1,   691,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,
      -1,   620,    -1,    -1,    -1,    -1,   706,    50,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,     4,   717,    -1,    -1,
       8,    -1,    -1,    66,    67,   644,   645,   109,   110,    72,
     730,    74,   651,   115,    77,    -1,    24,    -1,   738,   121,
     740,   123,   124,   125,   126,   127,    -1,    35,    -1,    -1,
      -1,    39,   134,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   695,     4,    66,    67,
      -1,     8,    -1,    -1,    72,   704,    74,   130,   131,    77,
      -1,    -1,   792,    -1,   137,    -1,    -1,    24,    -1,    -1,
       4,    -1,   721,    -1,     8,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,
     118,    35,   751,    -1,    -1,    39,    -1,    -1,    42,    66,
      67,    -1,   130,   131,    -1,    72,    50,    74,    -1,   137,
      77,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    66,    67,    -1,   784,   785,    -1,    72,    30,
      74,    -1,    33,    77,    -1,    -1,   795,   796,    -1,    -1,
     799,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,   808,
      -1,   118,    53,    30,    55,    -1,    33,    -1,    59,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    72,    73,    74,   118,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    -1,    -1,    -1,   130,    -1,    65,    -1,
      -1,    -1,    -1,   137,    95,    -1,    -1,    21,    22,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    30,    -1,   109,    33,
      -1,    -1,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    53,
      -1,    55,   109,   134,    -1,    59,    -1,    -1,   115,    -1,
      -1,    -1,    21,    22,   121,   122,   123,   124,   125,   126,
     127,    30,    -1,   130,    33,    34,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      59,    -1,    -1,    21,    22,   109,   110,    -1,    -1,    -1,
      -1,   115,    30,    -1,   118,    33,    -1,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    53,    95,    55,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    30,   115,    -1,    33,   118,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    95,    53,    -1,
      55,    -1,    -1,    -1,    59,    -1,    -1,    21,    22,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    30,   115,    -1,    33,
     118,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    53,
      95,    55,    -1,    21,    22,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,   109,    33,    -1,    -1,    -1,    -1,
     115,    -1,    -1,   118,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,    87,    88,    53,    -1,    55,    -1,   134,
      -1,    59,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,   109,    33,    -1,    -1,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,   123,
     124,   125,   126,   127,    -1,    -1,    53,    95,    55,    -1,
     134,    -1,    59,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    30,    -1,    -1,    33,    -1,   115,    -1,    -1,
     118,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    53,   134,    55,    95,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,
      -1,   109,    -1,    30,    -1,    -1,    33,   115,    -1,    -1,
      -1,    -1,    -1,   121,    41,   123,   124,   125,   126,   127,
      -1,    -1,    49,    -1,    -1,    -1,   134,    -1,    55,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,   130
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    29,    31,    36,    37,    38,    42,    49,    51,
      53,    58,    60,    63,    70,    80,    81,    83,   118,   119,
     120,   203,   211,   225,   228,   233,   234,   235,   236,   245,
     246,   247,   248,   249,   250,    43,    44,    45,    57,   156,
      30,   121,   140,    25,   140,   140,    25,   130,   210,   212,
      25,   121,   140,    21,    22,    33,    53,    55,    59,    95,
     109,   115,   118,   122,   123,   124,   125,   126,   127,   134,
     140,   145,   163,   165,   167,   170,   180,   140,    31,    37,
      38,    60,   140,   140,   140,   237,   126,   140,   140,   140,
     140,   248,   248,   249,     0,    26,    41,     3,     4,     8,
      16,   117,   140,    62,   136,   136,    83,   118,   140,   187,
     190,   165,   140,   187,   192,   192,   121,   226,   133,   130,
     110,   165,   166,   165,   165,   166,   115,   127,   134,    19,
     136,     3,    97,    98,   133,   144,   164,   133,   140,   140,
     140,   140,   127,   136,   201,   133,   136,   201,   136,   201,
      25,   133,   136,   232,   133,    72,    73,    74,   165,   241,
     242,    62,   136,   140,   204,   130,   140,   202,   130,   202,
     127,   165,   188,   140,   114,    34,   127,   165,   188,   189,
     140,   240,   136,     4,     8,    34,    56,   147,   151,   162,
      95,   129,   140,   168,   169,   129,   110,   128,   129,   135,
     166,   123,   151,     4,     8,    24,    35,    39,    42,    50,
      56,    66,    67,    72,    74,    77,   118,   130,   137,   172,
     174,   175,   147,   149,   167,   151,   133,   201,   145,   199,
     200,   130,   136,   156,   151,   111,   136,   130,   136,   238,
     162,    47,    48,   126,   130,   229,   133,   151,   172,   172,
     172,   136,   129,   140,   145,   243,   244,   140,   111,   136,
     140,   205,    16,   140,   161,   165,   136,   188,   172,   127,
     145,   158,   159,   160,   165,   111,   136,    18,   188,   189,
     136,   130,   160,    26,    41,    49,    95,   107,   127,   130,
     140,   145,   148,   153,   170,   111,   112,   136,   168,   136,
     131,   166,   166,   128,    96,   135,   173,   127,   172,   180,
     172,   172,   172,    80,   171,   171,    20,    52,    53,    65,
      78,   109,   127,   130,   134,   140,   145,   170,   181,   172,
      42,    77,   172,   179,   181,   136,   148,   164,   136,    34,
     151,   193,   133,   129,   128,   140,   206,   207,   130,   136,
     156,   151,    83,   118,   140,   208,   209,   130,   140,    95,
     140,   230,   231,   126,   130,   162,   136,   172,   242,   136,
     136,   129,   151,   130,   114,   129,   131,   202,   129,   131,
      39,   172,   131,    71,   122,   157,   159,   129,   132,    39,
     151,   172,   190,   191,    18,    53,    87,    88,   109,   118,
     127,   134,   140,   170,   213,   214,   216,   219,   221,   221,
     224,   132,   127,   123,   154,   151,   154,   158,   127,   146,
       3,     4,     8,    16,    40,   117,   142,   152,   151,   151,
     130,   169,   165,   128,   123,   172,   140,    54,    40,    68,
     130,   172,   172,   127,   127,   130,   127,   140,   110,   172,
     184,   172,   172,   135,   172,   184,   111,   115,   127,   132,
     133,   134,   136,   180,   181,   138,   131,     3,     4,     8,
      16,    97,    98,   117,   143,   176,   172,     4,     8,    16,
      40,   117,   141,   150,   172,   160,   156,   200,   129,   133,
     129,   131,   207,   151,   136,   208,   208,   133,   129,   131,
     209,   136,   133,   133,   129,   131,   231,   130,   140,   151,
     244,   129,   205,   172,   205,   161,   172,   157,   157,   133,
     151,   127,   165,   172,   136,    18,   191,   130,   219,   219,
     110,   213,   215,   221,   213,   215,   115,   127,   134,   220,
      19,   133,   144,   114,   222,   129,   131,   151,   151,   129,
     108,   128,   129,   131,   129,   132,   151,   155,   147,   227,
     135,   130,   121,   172,   172,   130,   172,    73,    75,   172,
     151,   140,   181,   182,   183,   151,   129,   110,   128,   129,
      62,    62,   135,   140,   184,   140,   153,   172,   172,   138,
     136,   179,   174,   147,   141,   132,   151,   151,   207,   131,
     151,   130,   151,   209,   131,   239,   126,   126,   231,   131,
     140,   197,   198,   204,   131,   129,   128,   133,   156,   165,
     111,   128,   172,   191,   140,   217,   218,   114,   114,   129,
     110,   128,   129,   135,   215,   123,    39,   140,   149,   214,
     216,   172,   112,   224,   111,   112,   128,   154,   155,   151,
     151,   129,   128,   148,   224,   165,   177,   178,   181,    32,
     178,   131,   172,   172,   128,   129,   128,   136,   129,   131,
     128,   184,   184,   183,   140,   181,   185,   186,   115,   127,
     128,   115,   127,    96,   129,   135,    40,   179,   172,   181,
     148,   147,   151,   207,   208,   133,   129,   131,   205,   136,
     156,   128,    39,   151,   111,   136,   136,   129,   131,   172,
     172,   215,   215,   128,    96,   135,   172,   223,   151,   151,
     128,   132,   131,   155,   152,   131,    39,   114,   129,   131,
     121,   172,   131,   172,   172,   183,   128,   131,    96,   136,
     129,   135,   184,   184,   172,   172,   172,   138,   176,   148,
     131,   127,   151,   194,   195,   196,   198,   172,   128,   172,
     136,   151,   172,   213,   218,   128,   123,   219,   151,   172,
     172,   178,   181,   128,   181,   172,   186,   128,   128,   135,
     135,   179,   151,   195,    96,    97,   128,   172,   136,   135,
     131,   114,    23,   128,   136,    96,    97,   151,   194,   111,
     172,   172,   181,   172,   172,   151,   194,   151,    40,   128,
     128,   128,   136,   151,   172,   172,   128,   172
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   139,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   142,   142,   142,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   144,   144,   144,   145,
     146,   147,   147,   147,   147,   148,   149,   150,   150,   150,
     151,   152,   152,   152,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   154,   154,
     155,   155,   155,   156,   156,   156,   156,   157,   157,   158,
     158,   158,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   163,   164,   164,   164,   165,   165,   165,   166,
     166,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   168,   168,   168,
     169,   169,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   173,   172,   172,   172,   172,
     172,   172,   172,   174,   174,   174,   174,   174,   175,   176,
     176,   176,   177,   177,   178,   178,   178,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   180,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   183,   183,   183,
     184,   184,   184,   185,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   189,   189,   189,   189,   190,   190,
     191,   191,   192,   192,   192,   192,   193,   193,   194,   194,
     195,   195,   196,   196,   196,   197,   198,   198,   198,   199,
     199,   200,   200,   201,   201,   202,   202,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   205,   205,   205,   205,   205,   205,   206,   207,
     207,   207,   208,   208,   208,   208,   209,   209,   209,   210,
     212,   211,   211,   213,   213,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   217,   217,   218,   218,   219,   220,   219,   221,
     222,   223,   221,   221,   221,   221,   224,   224,   224,   226,
     225,   227,   225,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   232,   232,   232,   233,   233,   234,   234,   235,
     235,   236,   236,   236,   236,   236,   236,   236,   236,   237,
     238,   239,   236,   240,   236,   236,   241,   241,   241,   242,
     242,   243,   243,   244,   244,   245,   245,   246,   246,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   248,   248,   248,   249,   249,   250,   250
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     3,     4,     3,     0,
       3,     4,     3,     0,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     5,     3,     3,     5,     7,     3,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     2,     6,
       5,     1,     1,     2,     3,     1,     1,     3,     3,     6,
       3,     6,     2,     2,     3,     0,     1,     2,     3,     1,
       2,     3,     1,     1,     1,     1,     2,     4,     6,     4,
       3,     3,     5,     3,     2,     3,     4,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     4,     1,     2,     3,     4,     6,
       3,     2,     2,     6,     4,     0,     6,     6,    13,    11,
       9,     5,     5,     0,     1,     1,     1,     1,     3,     0,
       3,     4,     3,     5,     1,     2,     3,     1,     2,     2,
       3,     4,     4,     5,     6,     3,     3,     3,     1,     4,
       6,     4,     6,     3,     1,     1,     2,     2,     4,     4,
       4,     4,     6,     6,     4,     5,     2,     3,     5,     2,
       3,     3,     5,     4,     6,     3,     1,     1,     2,     3,
       1,     2,     3,     3,     5,     1,     1,     3,     1,     1,
       3,     7,     3,     5,     8,     7,     9,    12,     3,     2,
       1,     3,     3,     2,     5,     4,     4,     1,     3,     1,
       5,     1,     1,     3,     5,     3,     1,     2,     3,     3,
       1,     1,     3,     5,     3,     1,     3,     5,     4,     7,
       6,     6,     7,     4,     6,     8,     6,     7,     8,     5,
       4,     3,     1,     2,     3,     4,     3,     5,     3,     1,
       2,     3,     2,     2,     3,     5,     1,     2,     3,     5,
       0,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     4,     6,     2,     4,     3,     5,     3,     2,     3,
       3,     4,     3,     1,     1,     3,     1,     0,     4,     2,
       0,     0,     5,     3,     4,     4,     1,     2,     3,     0,
       7,     0,     9,     2,     1,     1,     3,     3,     1,     3,
       0,     2,     4,     3,     5,     4,     5,     4,     6,     3,
       3,     3,     4,     3,     3,     3,     5,     5,     3,     0,
       0,     0,     8,     0,     6,     2,     2,     2,     2,     1,
       3,     3,     3,     1,     3,     2,     4,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     2,     2,     1,     1,     2,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* id: ID  */
#line 147 "sail.y"
       {
        if(strstr((yyvsp[0].node).stringVal, "_flag") || strstr((yyvsp[0].node).stringVal, "_vmask")){
                regname = (yyvsp[0].node).stringVal;    
        }
        if(funName==1 && strstr((yyvsp[0].node).stringVal, "reg")){
                regname = (yyvsp[0].node).stringVal;
                funName = 0;
        }
        if(regCount == 1 && funCount == 1){
                if(strstr((yyvsp[0].node).stringVal, "x") || strstr((yyvsp[0].node).stringVal, "zero_reg")){
                        //cout << $1.stringVal << endl;
                        regstr+=(yyvsp[0].node).stringVal; 
                        regstr+=","; 
                }
                if(strstr((yyvsp[0].node).stringVal, "f")){
                        //cout << $1.stringVal << endl;
                        regstr+=(yyvsp[0].node).stringVal; 
                        regstr+=","; 
                }
        }
        if(assemblyString == 1){
                instType+=(yyvsp[0].node).stringVal;
                assemblyString = 2;
        }
        else if(assemblyString == 3){
                assemblyStr+=(yyvsp[0].node).stringVal;
        }
        if(immbitcheck == 1 && !strcmp((yyvsp[0].node).stringVal,"MUL")){
                //cout << $1.stringVal << endl; 
                mext_MULcheck = 1;
        }
        if(mext_MULcheck == 1){
              if(strstr((yyvsp[0].node).stringVal, "encdec_")){
                mext_MULcheck = 2;
                Mexttmp.name.clear();
                Mexttmp.name = "";
              }  
        }
        else if(strstr((yyvsp[0].node).stringVal, "mul_mnemonic")){
                mext_MULcheck1=1;        
        } 
        if(boolbits == 1 || sizebits == 1 || encdec_rounding_mode == 1 || Mext_U == 1){  
                BitStr=BitStr+(yyvsp[0].node).stringVal;  
                boolbits = 0; 
                sizebits = 0;   
                encdec_rounding_mode = 0;
        } 
        else if(strstr((yyvsp[0].node).stringVal, "encdec_") && mapop < 1 && instr_bits < 1){
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
                optmp.name = (yyvsp[0].node).stringVal;
                //cout << $1.stringVal << endl; 
                if(strstr((yyvsp[0].node).stringVal, "RISCV_")) 
                        optmp.name.erase(0,6);
               // printf("\n1%s\n",$1.stringVal); 
        }
        else if(instr_bits > 1 && instrbits_check == 1){
                if(strstr((yyvsp[0].node).stringVal, "imm")){
                        BitStr=BitStr+"imm";
                        imm_nobits = 1; 

                        if(strcmp((yyvsp[0].node).stringVal,"imm")){
                                immbit = 0;
                        }
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"csr")){
                        csr_check = 1;
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"rs1")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"rs2")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"rs3")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"rd")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"shamt")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"pred")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"succ")){
                        BitStr=BitStr+(yyvsp[0].node).stringVal;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"bool_bits")){
                        boolbits = 1;
                }
                else if(!strcmp((yyvsp[0].node).stringVal,"size_bits")){
                        sizebits = 1;
                       // cout << $1.stringVal << endl;
                }
                else if(!strcmp((yyvsp[0].node).stringVal, "bool_not_bits")){
                    Mext_U = 1;        
                } 
                else if(!strcmp((yyvsp[0].node).stringVal,"encdec_rounding_mode")){
                        encdec_rounding_mode = 1;
                       // cout << $1.stringVal << endl;
                }
                else if(strstr((yyvsp[0].node).stringVal,"encdec_")){
                        BitStr=BitStr+"op";
                        Getencdecop = 1;
                       
                }
                instrbits_check=0;
        } 
        else if(!strcmp((yyvsp[0].node).stringVal,"shamt")){
                if(encdec_IF == 2){
                        addshamt = 1;
                        encdec_IF = 0;
                }
        }
        else if(check_multi == 1 && strstr((yyvsp[0].node).stringVal, "RISCV_")){
                //cout << $1.stringVal << endl;
                optmp.name = (yyvsp[0].node).stringVal;
                optmp.name.erase(0,6);
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && (strstr((yyvsp[0].node).stringVal, "FM") || strstr((yyvsp[0].node).stringVal, "FNM"))){
                //cout << $1.stringVal << endl;
                optmp.name = (yyvsp[0].node).stringVal;
                optmp.opcode = ""; 
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && (strstr((yyvsp[0].node).stringVal, "_D") || strstr((yyvsp[0].node).stringVal, "FCVT"))){
                //cout << $1.stringVal << endl;
                optmp.name = (yyvsp[0].node).stringVal;
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && (strstr((yyvsp[0].node).stringVal, "_S") || strstr((yyvsp[0].node).stringVal, "FCVT"))){
                //cout << $1.stringVal << endl;
                optmp.name = (yyvsp[0].node).stringVal;
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        }
        else if(check_multi == 1 && FPCount == 1 && (LFPCount!=0 || SFPCount!=0) && (strstr((yyvsp[0].node).stringVal, "HALF") || strstr((yyvsp[0].node).stringVal, "WORD") || strstr((yyvsp[0].node).stringVal, "DOUBLE"))){
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
                if(strstr((yyvsp[0].node).stringVal, "OP")){
                        unit_check = 0;       
                }
                else if(strstr((yyvsp[0].node).stringVal, "TYPE")){
                        unit_check = 0;       
                }
                else{
                        if(!strcmp((yyvsp[0].node).stringVal,"LOAD") || !strcmp((yyvsp[0].node).stringVal,"STORE")){
                                LS_Check = 1;
                        }
                        if(!strcmp((yyvsp[0].node).stringVal,"LOAD_FP")){
                                LFPCount++;
                        }
                        if(!strcmp((yyvsp[0].node).stringVal,"STORE_FP")){
                                SFPCount++;
                        }
                        optmp.name = (yyvsp[0].node).stringVal;
                        optmp.opcode = "";
                        //OpNameStr = optmp.name;  
                        unit_check = 0;       
                        
                }
        }             
}
#line 2697 "y.tab.c"
    break;

  case 26: /* pat_op: At  */
#line 385 "sail.y"
           {
                if(instr_bits > 1){
                        BitStr=BitStr+"@";
                        instrbits_check = 1;
                }
        }
#line 2708 "y.tab.c"
    break;

  case 28: /* pat_op: '^'  */
#line 392 "sail.y"
              {
                if(assemblyString == 3){
                        assemblyStr+=",";
                }
        }
#line 2718 "y.tab.c"
    break;

  case 112: /* lit: True  */
#line 536 "sail.y"
           { 
        if(mext_MULcheck == 2){
                Mexttmp.name += "True,";
        } 
        if(mext_MULcheck1 == 1){
                Mexttmp1.name += "True,";
        } 
   }
#line 2731 "y.tab.c"
    break;

  case 113: /* lit: False  */
#line 544 "sail.y"
           { 
        if(mext_MULcheck == 2){
                Mexttmp.name += "False,";
        } 
        if(mext_MULcheck1 == 1){
                Mexttmp1.name += "False,";
        } 
   }
#line 2744 "y.tab.c"
    break;

  case 115: /* lit: Num  */
#line 553 "sail.y"
         { 
        if(immbitcheck != 0){
          immbit = (yyvsp[0].node).ival;
        }
        else if(instr_bits > 1 && imm_nobits == 1){
                if(immbit == 0){
                        BitStr = BitStr + to_string((yyvsp[0].node).ival);
                }
                imm_nobits = 0;
        }
          immbitcheck = 0;
        }
#line 2761 "y.tab.c"
    break;

  case 119: /* lit: Bin_literal  */
#line 568 "sail.y"
                 {
        if(mext_MULcheck == 2){
                //cout << "111" << endl;
                Mexttmp.opcode = (yyvsp[0].node).stringVal;
                Mexttmp.opcode.erase(0,2);
                Mext_insert(MextTable,Mexttmp);
                Mexttmp.name.clear();
                Mexttmp.name = "";
        }
        else if(oplistcheck > 0 && instr_bits <= 1){
                optmp.opcode = (yyvsp[0].node).stringVal;
                optmp.opcode.erase(0,2);
                //printf("\n%s\n",$1.stringVal);
                optmp.bitcode = "";
                op_insert(table,optmp);
        }
        else if(instr_bits > 1){
                string s = (yyvsp[0].node).stringVal;
                s.erase(0,2);
                BitStr = BitStr + s;
                optmp.opcode = "";
        }
}
#line 2789 "y.tab.c"
    break;

  case 121: /* lit: STRING_LITERAL  */
#line 592 "sail.y"
                    {
                cout << (yyvsp[0].node).stringVal << endl;
                if(regCount == 1){
                        regstr+=(yyvsp[0].node).stringVal; 
                        regstr+=","; 
                }
                if(regFlag == 3){
                        regstr+=(yyvsp[0].node).stringVal; 
                        regstr+=","; 
                }
                //cout << regstr << endl; 
                if(mext_MULcheck1 == 1 && strstr((yyvsp[0].node).stringVal, "mul")){
                        //cout << $1.stringVal << endl; 
                        Mexttmp1.opcode = (yyvsp[0].node).stringVal;
                }
                if(assemblyString == 3){
                        assemblyStr+=(yyvsp[0].node).stringVal;
                }
        }
#line 2813 "y.tab.c"
    break;

  case 135: /* $@1: %empty  */
#line 628 "sail.y"
           { regCount = 1; }
#line 2819 "y.tab.c"
    break;

  case 136: /* exp: Match $@1 exp '{' case_list '}'  */
#line 629 "sail.y"
   { 
        Regtable.name=regname; 
        Regtable.str=regstr; 
        reg_insert(RegMaptable,Regtable);    
        regCount=0; 
        funCount=0;
        regFlag = 0;
        regname.clear();
        regstr.clear();
        }
#line 2834 "y.tab.c"
    break;

  case 280: /* $@2: %empty  */
#line 854 "sail.y"
                   { funName = 1; funCount = 1; }
#line 2840 "y.tab.c"
    break;

  case 307: /* $@3: %empty  */
#line 891 "sail.y"
            { if(encdec_IF == 1)encdec_IF = 2; }
#line 2846 "y.tab.c"
    break;

  case 310: /* $@4: %empty  */
#line 895 "sail.y"
            {
        regFlag = 0;
     }
#line 2854 "y.tab.c"
    break;

  case 311: /* $@5: %empty  */
#line 897 "sail.y"
             {
        if(funCount == 1){
                regCount=1;
        }
        instrbits_check = 1;
        if(instr_bits == 1)
                instr_bits++;
        check_multi = 0;
        if(assemblyString == 2){
                assemblyString=3;
        }
     }
#line 2871 "y.tab.c"
    break;

  case 312: /* mapcl: mpexp $@4 Bidir $@5 mpexp  */
#line 908 "sail.y"
             {if(mext_MULcheck1 == 1){
                        Mext_insert(MextTable1,Mexttmp1);
                        Mexttmp1.name.clear();
                        Mexttmp1.name = "";
                 }
                 regCount=0;
                 regFlag = 3;
        }
#line 2884 "y.tab.c"
    break;

  case 318: /* mapcl_list: mapcl ',' mapcl_list  */
#line 923 "sail.y"
                               {mext_MULcheck = 0;}
#line 2890 "y.tab.c"
    break;

  case 319: /* $@6: %empty  */
#line 926 "sail.y"
                   {
                //cout << $2.stringVal << endl;
                if(strstr((yyvsp[0].node).stringVal, "regtype") || strstr((yyvsp[0].node).stringVal, "reg_")){
                        regname.clear();
                        regname = (yyvsp[0].node).stringVal;
                        funName = 0;
                        regCount = 1;
                        funCount = 1;
                }
        }
#line 2905 "y.tab.c"
    break;

  case 320: /* map_def: Mapping ID $@6 '=' '{' mapcl_list '}'  */
#line 935 "sail.y"
                               {
                funName =0;
                funCount=0;
                regCount=0;
                regFlag = 0;
                Regtable.name = regname;
                Regtable.str = regstr;
                reg_insert(RegMaptable,Regtable); 
                regstr.clear();
                regname.clear();
        }
#line 2921 "y.tab.c"
    break;

  case 321: /* $@7: %empty  */
#line 946 "sail.y"
                                        {regFlag=3;}
#line 2927 "y.tab.c"
    break;

  case 322: /* map_def: Mapping id ':' typschm '=' '{' $@7 mapcl_list '}'  */
#line 946 "sail.y"
                                                                    {
                funName =0;
                funCount=0;
                regCount=0;
                regFlag = 0;
                Regtable.name = regname;
                Regtable.str = regstr;
                reg_insert(RegMaptable,Regtable); 
                regstr.clear();
                regname.clear();
                oplistcheck = 0;
                mapop = 0;
        }
#line 2945 "y.tab.c"
    break;

  case 348: /* scattered_def: Function_ Clause funcl  */
#line 1001 "sail.y"
                                         { regstr.clear();}
#line 2951 "y.tab.c"
    break;

  case 349: /* $@8: %empty  */
#line 1002 "sail.y"
                        {
                        if(assemblyString == 3){ 
                                create_opccoutput(opcctable,opccoutputtable);
                        }
                        assemblyString = 0;
                }
#line 2962 "y.tab.c"
    break;

  case 350: /* $@9: %empty  */
#line 1007 "sail.y"
                       {                             
                        op_new_table(symtable_stack,table);
                        opcc_new_table(opccsymtable_stack,opcctable);
                        opcc_new_table(opccTmpsymtable_stack,opccTmptable);
                        immbitcheck = 1;
                        mapop = 0;
                        immbit = 0;
                        oplistcheck = 0;
                 }
#line 2976 "y.tab.c"
    break;

  case 351: /* $@10: %empty  */
#line 1015 "sail.y"
                         { unit_check =1; }
#line 2982 "y.tab.c"
    break;

  case 353: /* $@11: %empty  */
#line 1016 "sail.y"
                                    {
                        oplistcheck = 0;
                        if(strcmp((yyvsp[0].node).stringVal,"encdec")==0){
                                //cout << "123" <<endl;
                                instr_bits = 1;
                                check_multi = 1;
                                encdec_IF = 1;
                                FPCount++;  
                        }
                        if(strcmp((yyvsp[0].node).stringVal, "assembly")==0){   
                               // cout << Getencdecop <<endl;
                               assemblyString = 1;
                                if(mext_MULcheck1 != 0 ){ 
                                        Mext_insertOP(table,MextTable,MextTable1);
                                        Getencdecop = 1;
                                } 
                                create_output(opcctable,opccoutputtable,instrBitTable,BitStr,assemblyStr,table,Getencdecop,immbit,addshamt,LS_Check,Mext_U,csr_check);
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
                        }
                        
                }
#line 3017 "y.tab.c"
    break;

  case 354: /* scattered_def: Mapping Clause ID $@11 '=' mapcl  */
#line 1045 "sail.y"
                           {
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
                        }
                }
#line 3049 "y.tab.c"
    break;


#line 3053 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1124 "sail.y"
 
void yyerror (string s) 
{
    cerr << "line " << linenum << ": \033[1;31m" << s << "\033[1;0m" << endl;
    exit(1); 
}
 
int main() 
{ 
    reg_new_table(Regsymtable_stack,RegMaptable);
    yyparse();
    create_opccoutput(opcctable,opccoutputtable);
    //printf("%d\n",immbit);    
    //op_dump(table); 
    reg_dump(RegMaptable);
    //opcc_dump(opcctable);
    //Mext_dump(MextTable);    
    //Mext_dump(MextTable1); 
    //opccoutput_dump(opccoutputtable);      
    //output_dump(instrBitTable);       
    cout << "finish" << endl;
    return 0;
}   

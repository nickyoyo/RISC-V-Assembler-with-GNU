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


#line 155 "y.tab.c"

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
#line 85 "sail.y"

   struct {
    int ival;
    bool bval;
    float fval;
    char charVal;
    char* stringVal;
    } node;

#line 454 "y.tab.c"

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
  YYSYMBOL_prefix_op = 173,                /* prefix_op  */
  YYSYMBOL_exp0 = 174,                     /* exp0  */
  YYSYMBOL_list_4 = 175,                   /* list_4  */
  YYSYMBOL_case = 176,                     /* case  */
  YYSYMBOL_case_list = 177,                /* case_list  */
  YYSYMBOL_block = 178,                    /* block  */
  YYSYMBOL_letbind = 179,                  /* letbind  */
  YYSYMBOL_atomic_exp = 180,               /* atomic_exp  */
  YYSYMBOL_fexp_exp = 181,                 /* fexp_exp  */
  YYSYMBOL_fexp_exp_list = 182,            /* fexp_exp_list  */
  YYSYMBOL_exp_list = 183,                 /* exp_list  */
  YYSYMBOL_vector_update = 184,            /* vector_update  */
  YYSYMBOL_vector_update_list = 185,       /* vector_update_list  */
  YYSYMBOL_funcl_annotation = 186,         /* funcl_annotation  */
  YYSYMBOL_funcl_patexp = 187,             /* funcl_patexp  */
  YYSYMBOL_funcl_patexp_typ = 188,         /* funcl_patexp_typ  */
  YYSYMBOL_funcl = 189,                    /* funcl  */
  YYSYMBOL_funcl_list = 190,               /* funcl_list  */
  YYSYMBOL_funcls = 191,                   /* funcls  */
  YYSYMBOL_funcl_typ = 192,                /* funcl_typ  */
  YYSYMBOL_index_range = 193,              /* index_range  */
  YYSYMBOL_paren_index_range = 194,        /* paren_index_range  */
  YYSYMBOL_atomic_index_range = 195,       /* atomic_index_range  */
  YYSYMBOL_r_id_def = 196,                 /* r_id_def  */
  YYSYMBOL_r_def_body = 197,               /* r_def_body  */
  YYSYMBOL_param_kopt = 198,               /* param_kopt  */
  YYSYMBOL_param_kopt_list = 199,          /* param_kopt_list  */
  YYSYMBOL_typaram = 200,                  /* typaram  */
  YYSYMBOL_enum_bar = 201,                 /* enum_bar  */
  YYSYMBOL_type_def = 202,                 /* type_def  */
  YYSYMBOL_enum_functions = 203,           /* enum_functions  */
  YYSYMBOL_enum_comma = 204,               /* enum_comma  */
  YYSYMBOL_struct_field = 205,             /* struct_field  */
  YYSYMBOL_struct_fields = 206,            /* struct_fields  */
  YYSYMBOL_type_union = 207,               /* type_union  */
  YYSYMBOL_type_unions = 208,              /* type_unions  */
  YYSYMBOL_rec_measure = 209,              /* rec_measure  */
  YYSYMBOL_fun_def = 210,                  /* fun_def  */
  YYSYMBOL_mpat = 211,                     /* mpat  */
  YYSYMBOL_atomic_mpat_list = 212,         /* atomic_mpat_list  */
  YYSYMBOL_mpat_list = 213,                /* mpat_list  */
  YYSYMBOL_atomic_mpat = 214,              /* atomic_mpat  */
  YYSYMBOL_fmpat = 215,                    /* fmpat  */
  YYSYMBOL_fmpat_list = 216,               /* fmpat_list  */
  YYSYMBOL_mpexp = 217,                    /* mpexp  */
  YYSYMBOL_218_1 = 218,                    /* $@1  */
  YYSYMBOL_mapcl = 219,                    /* mapcl  */
  YYSYMBOL_220_2 = 220,                    /* $@2  */
  YYSYMBOL_mapcl_list = 221,               /* mapcl_list  */
  YYSYMBOL_map_def = 222,                  /* map_def  */
  YYSYMBOL_let_def = 223,                  /* let_def  */
  YYSYMBOL_pure_opt = 224,                 /* pure_opt  */
  YYSYMBOL_extern_binding = 225,           /* extern_binding  */
  YYSYMBOL_extern_binding_list = 226,      /* extern_binding_list  */
  YYSYMBOL_externs = 227,                  /* externs  */
  YYSYMBOL_val_spec_def = 228,             /* val_spec_def  */
  YYSYMBOL_register_def = 229,             /* register_def  */
  YYSYMBOL_default_def = 230,              /* default_def  */
  YYSYMBOL_scattered_def = 231,            /* scattered_def  */
  YYSYMBOL_232_3 = 232,                    /* $@3  */
  YYSYMBOL_233_4 = 233,                    /* $@4  */
  YYSYMBOL_234_5 = 234,                    /* $@5  */
  YYSYMBOL_235_6 = 235,                    /* $@6  */
  YYSYMBOL_loop_measure = 236,             /* loop_measure  */
  YYSYMBOL_loop_measure_list = 237,        /* loop_measure_list  */
  YYSYMBOL_subst = 238,                    /* subst  */
  YYSYMBOL_subst_list = 239,               /* subst_list  */
  YYSYMBOL_instantiation_def = 240,        /* instantiation_def  */
  YYSYMBOL_overload_def = 241,             /* overload_def  */
  YYSYMBOL_def_aux = 242,                  /* def_aux  */
  YYSYMBOL_def = 243,                      /* def  */
  YYSYMBOL_defs_list = 244,                /* defs_list  */
  YYSYMBOL_file = 245                      /* file  */
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
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1950

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  384
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  812

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
       0,   134,   134,   362,   363,   364,   365,   366,   368,   369,
     370,   371,   372,   374,   375,   376,   377,   378,   379,   381,
     382,   383,   384,   385,   386,   387,   389,   395,   396,   402,
     405,   409,   410,   411,   412,   415,   418,   421,   422,   423,
     426,   429,   430,   431,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   450,   451,
     454,   455,   456,   458,   459,   460,   461,   465,   466,   469,
     470,   471,   474,   475,   478,   479,   485,   486,   492,   493,
     494,   495,   498,   501,   502,   503,   506,   507,   508,   510,
     511,   512,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   531,   532,   533,
     536,   537,   540,   548,   556,   557,   569,   570,   571,   572,
     595,   596,   607,   608,   609,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   631,   632,   633,   634,   635,   638,   641,   642,
     643,   646,   647,   650,   651,   652,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   666,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   699,   700,   703,   704,   705,   708,
     709,   710,   713,   714,   715,   718,   719,   722,   723,   726,
     727,   729,   730,   731,   732,   733,   734,   737,   738,   741,
     742,   745,   746,   747,   748,   751,   752,   755,   756,   759,
     760,   763,   764,   765,   768,   771,   772,   773,   776,   777,
     779,   780,   782,   783,   785,   786,   789,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   803,   804,
     805,   808,   809,   810,   811,   812,   813,   816,   819,   820,
     821,   824,   825,   826,   827,   830,   831,   832,   835,   838,
     839,   842,   843,   845,   846,   848,   849,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   861,   862,   863,   864,
     867,   868,   870,   871,   874,   875,   875,   878,   879,   879,
     892,   893,   894,   897,   898,   899,   902,   903,   909,   913,
     914,   917,   918,   920,   921,   923,   924,   925,   926,   927,
     930,   931,   934,   935,   938,   939,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   955,   963,   950,   964,   964,
    1021,  1024,  1025,  1026,  1028,  1029,  1032,  1033,  1035,  1036,
    1038,  1039,  1042,  1043,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1063,  1064,
    1065,  1067,  1068,  1070,  1071
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
  "lit", "internal_loop_measure", "exp", "prefix_op", "exp0", "list_4",
  "case", "case_list", "block", "letbind", "atomic_exp", "fexp_exp",
  "fexp_exp_list", "exp_list", "vector_update", "vector_update_list",
  "funcl_annotation", "funcl_patexp", "funcl_patexp_typ", "funcl",
  "funcl_list", "funcls", "funcl_typ", "index_range", "paren_index_range",
  "atomic_index_range", "r_id_def", "r_def_body", "param_kopt",
  "param_kopt_list", "typaram", "enum_bar", "type_def", "enum_functions",
  "enum_comma", "struct_field", "struct_fields", "type_union",
  "type_unions", "rec_measure", "fun_def", "mpat", "atomic_mpat_list",
  "mpat_list", "atomic_mpat", "fmpat", "fmpat_list", "mpexp", "$@1",
  "mapcl", "$@2", "mapcl_list", "map_def", "let_def", "pure_opt",
  "extern_binding", "extern_binding_list", "externs", "val_spec_def",
  "register_def", "default_def", "scattered_def", "$@3", "$@4", "$@5",
  "$@6", "loop_measure", "loop_measure_list", "subst", "subst_list",
  "instantiation_def", "overload_def", "def_aux", "def", "defs_list",
  "file", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-534)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-306)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1830,   363,   182,   100,   182,   195,   109,  1419,   182,   367,
     182,   182,   182,   131,   182,   182,   182,  1830,  1830,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  1830,  -534,    83,  -534,  -534,  -534,  -534,    77,
      86,  -534,  -534,   182,   -14,   -63,   218,  -534,  -534,  1419,
    1321,   182,  -534,   218,    17,   306,  -534,  -534,  -534,    23,
    -534,  -534,  -534,  1373,  -534,  1419,  -534,  -534,  -534,  -534,
    -534,  1419,  1419,   284,  -534,   172,    63,    39,  -534,  -534,
      90,   182,   182,   182,   182,   128,   331,   220,   216,   179,
     248,   201,  1275,   330,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,   266,   182,    10,    25,  1471,
     182,  -534,   249,   141,  1419,   -52,   392,  -534,  1321,  -534,
    -534,   239,   285,   105,  -534,   323,   350,  -534,   296,   342,
    -534,  1419,   356,    70,  1124,  -534,  -534,  -534,    70,  1604,
    -534,    70,  -534,  -534,   333,   359,   375,   369,   372,   363,
      70,   -43,   398,   374,  -534,   239,   303,   370,    70,  1124,
    1124,  1124,   394,   404,  -534,   175,   182,   423,   399,   182,
     522,  -534,   182,  -534,  1419,   406,  -534,  1471,  1124,   123,
    -534,   141,   415,   413,   194,    70,  1124,   218,   529,  -534,
     412,  -534,  -534,   141,  -534,  1728,   351,   414,  1526,  -534,
      67,   416,  -534,   418,  1419,  -534,  -534,  1419,  -534,   425,
     169,  -534,  -534,  -534,  1124,   424,  1124,  1419,  1124,  -534,
    1124,  1124,   474,   474,  1235,  1124,  1173,  -534,  -534,  1235,
     419,  1728,  -534,    39,   420,   324,  -534,   426,   428,   433,
     182,   432,   427,  -534,   363,    70,   231,   434,   182,  -534,
    -534,  -534,  -534,   210,   -54,   239,   429,  -534,  -534,  -534,
    1124,   371,   435,   436,   439,  -534,  -534,    70,   444,   146,
     438,   182,   446,   445,   198,  1124,  -534,   447,   455,   455,
     449,  -534,    70,  1569,  1124,   451,   570,   571,  -534,   218,
    1526,   458,  -534,  -534,   464,  -534,   469,    70,   346,   466,
    -534,    59,  -534,  -534,    70,    70,   465,   468,  1687,  1687,
    1647,  1526,  1687,  1687,   304,  -534,   555,  -534,    35,   318,
     470,   471,   105,  1419,  -534,  -534,   475,  -534,   483,  -534,
     477,   182,   557,   572,  -534,  -534,   545,   484,  1124,  1124,
     488,   491,   489,   493,   182,   754,  1124,  1124,   200,   104,
    -534,  -534,   358,  -534,  1419,  1235,   485,   495,    84,  1124,
     111,  -534,  1124,   141,  -534,  -534,   363,   375,   499,   497,
     502,   501,   182,    70,   486,  -534,   231,   231,   500,   505,
     504,   231,   506,   503,   507,   508,   510,  -534,   210,  -534,
     513,  -534,  -534,   182,    70,   175,   515,   182,  1124,   182,
    -534,  -534,   182,  -534,  1124,  -534,  -534,   512,  -534,   363,
    -534,  1419,   527,   518,  1124,   218,  -534,  -534,    70,    70,
     519,   539,   343,   521,   327,    70,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,    70,  -534,  -534,  -534,  1526,   182,   536,
     540,  -534,   524,   546,  -534,   389,   526,  -534,  1687,   534,
     623,   182,    70,  1687,  -534,  1124,  1526,  -534,  -534,  -534,
    -534,   528,  1419,   544,  1124,  1124,   537,  1124,   595,   594,
    1124,    70,  1235,    70,  -534,  -534,   543,   563,   391,   612,
    -534,    -6,   542,   182,  -534,  1124,   182,  1728,  1124,  1124,
      73,   368,   850,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,    42,  -534,  -534,  -534,  -534,  -534,  -534,  -534,    70,
     111,  -534,   547,  -534,  -534,    70,    70,   182,  -534,   549,
    -534,    70,  -534,  -534,    56,   231,  -534,   550,  -534,   552,
     559,   210,  -534,   560,   182,  -534,  -534,  -534,   182,   561,
     554,  -534,  -534,   562,   363,   565,   215,    70,   204,  -534,
    -534,   384,   568,   469,  -534,  -534,    70,  -534,    70,    70,
     569,   574,  1728,   573,   564,   576,   575,  1124,  1124,  1687,
    -534,  -534,  1687,  -534,   580,   252,  1124,  -534,  -534,  -534,
      50,  1687,  -534,  -534,  -534,     6,   582,   578,  1235,   643,
    -534,  1419,   585,  1124,  1124,   396,   590,   326,   373,   591,
     597,   603,   647,  -534,  -534,  1124,  1235,  1235,  -534,   261,
     606,   301,  -534,   242,   648,  1015,  1124,  -534,  1235,  1728,
      70,    70,  -534,  -534,  -534,  -534,  -534,   182,  -534,  -534,
    -534,   231,  -534,  -534,  -534,  -534,   566,   593,   605,  -534,
    -534,   182,   601,   610,  -534,  1124,   604,    70,  1124,    70,
      70,  -534,  -534,   611,   609,   613,    61,  -534,    59,  -534,
    1687,   182,  -534,  -534,  -534,  -534,   614,  -534,   625,  -534,
    -534,  -534,  1124,  1124,  1419,  -534,   234,  1124,   615,  -534,
    -534,  -534,  -534,  1124,  -534,  1124,  1235,  -534,  -534,  -534,
     624,   622,   254,   228,   626,   621,  -534,  1124,  -534,  -534,
    1124,  1124,  1124,  -534,  1124,  -534,    76,    84,  -534,  1728,
    -534,   629,  -534,    53,   182,  -534,  -534,  1124,  -534,   633,
    1124,   627,   750,  -534,  -534,  -534,    70,  -534,  -534,  -534,
    -534,  -534,  -534,   634,   656,  -534,  -534,  1235,  -534,  -534,
     644,  -534,  -534,  -534,  -534,  1235,  1124,  1235,  -534,   645,
     646,   636,   641,  -534,  1101,  -534,  -534,  -534,    53,   683,
    -534,   684,  -534,  -534,  -534,   669,  -534,  1124,   652,  -534,
    1124,    24,  -534,   380,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,   689,   691,    70,    53,    70,  -534,  -534,  -534,  1235,
    1124,  1124,    70,    53,  -534,  -534,   650,   166,  -534,  -534,
     662,   666,  1124,    70,  1124,  -534,  -534,  -534,   667,  -534,
    1124,  -534
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     384,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   344,     0,     0,     0,     0,     0,     0,   375,
     366,   369,   364,   365,   370,   367,   371,   374,   373,   368,
     372,   380,   381,   383,     0,    63,    65,    66,    64,     0,
       0,     2,   350,     0,     0,     0,     0,   207,   208,     0,
       0,     0,   279,     0,     0,     0,   117,   118,   113,     0,
     112,   116,    92,     0,   114,     0,    29,   115,   119,   120,
     121,     0,     0,    94,    95,    86,     0,    85,    93,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,     0,     0,   360,   378,   379,   382,     1,   335,   334,
       6,     7,     4,     5,     3,     0,     0,     0,     0,     0,
       0,   343,     0,     0,     0,     0,     0,   222,     0,   280,
     348,    31,     0,     0,   104,    89,     0,    87,     0,     0,
      96,     0,     0,    31,   142,    28,    26,    27,    31,     0,
      82,    31,   336,   339,   340,   338,     0,     0,     0,     0,
      31,     0,     0,     0,   345,    31,     0,     0,    31,   142,
     142,   142,     0,   354,   377,     0,     0,     0,     0,     0,
     244,   252,     0,   363,     0,     0,   218,     0,   142,     0,
      71,    72,    75,     0,     0,    31,   142,     0,     0,   221,
       0,    34,    33,     0,    32,     0,     0,     0,     0,   109,
       0,   108,   110,     0,    90,   105,   101,     0,   103,     0,
       0,    88,   145,   144,   142,     0,   142,     0,   142,   143,
     142,   142,   122,   122,     0,   142,   142,   146,   165,     0,
     125,     0,   100,    83,   332,    31,   337,   239,   240,     0,
       0,     0,     0,   247,     0,    31,     0,     0,     0,   330,
     320,   319,   326,     0,     0,    31,     0,   352,   351,   353,
     142,     0,     0,     0,   358,   361,   342,    31,     0,   261,
       0,     0,    76,     0,     0,   142,   217,     0,     0,    67,
       0,    73,    31,     0,   142,     0,   211,   219,   224,     0,
       0,     0,    48,    49,     0,    45,     0,    31,     0,    44,
      46,    43,    35,    47,    31,    31,     0,     0,     0,     0,
       0,     0,     0,     0,   288,   287,   304,   281,   283,     0,
     313,     0,     0,     0,   106,    91,     0,    99,     0,    97,
       0,     0,     0,     0,   131,   132,     0,     0,   142,   142,
       0,     0,     0,     0,     0,   142,   142,   142,   142,   173,
     174,   167,     0,   126,     0,     0,   156,     0,   148,   142,
      39,    84,   142,     0,   226,   341,     0,     0,   243,     0,
     268,     0,     0,    31,     0,   246,     0,     0,     0,   275,
       0,     0,     0,     0,     0,   323,     0,   328,     0,   331,
       0,   376,   355,     0,    31,     0,   260,     0,   142,   262,
     253,   245,     0,   362,   142,   209,   278,     0,    68,     0,
      74,     0,     0,     0,   142,     0,   223,   349,    31,    31,
      59,     0,     0,     0,     0,    31,    50,    16,    17,    14,
      15,    18,    13,    31,    40,    78,    80,     0,     0,     0,
       0,   296,   285,     0,   307,     0,     0,   291,     0,     0,
       0,     0,    31,     0,   308,   142,   314,   316,   111,   107,
     102,     0,     0,     0,   142,   142,     0,   142,     0,     0,
     142,    31,     0,    31,   175,   188,   199,     0,     0,     0,
     185,   199,     0,     0,   176,   142,     0,     0,   142,   142,
     158,     0,   142,   130,    24,    25,    20,    21,    22,    23,
      19,   142,   147,   127,    11,     9,    10,    12,     8,    31,
      36,   333,     0,   238,   241,    31,    31,   269,   250,     0,
     249,    31,   271,   272,    31,   276,   255,     0,   346,     0,
       0,     0,   327,     0,     0,   357,   356,   359,   259,     0,
     263,   265,    77,     0,     0,     0,     0,    31,     0,   212,
     220,     0,     0,     0,    55,    52,    31,    54,    31,    31,
      60,     0,     0,     0,   301,   302,     0,   142,   142,     0,
     297,   293,     0,   295,     0,     0,   142,   282,   298,   284,
     283,     0,   310,   315,    98,     0,   153,     0,     0,   134,
     128,     0,     0,   142,   142,     0,     0,   173,     0,   196,
       0,     0,   142,   189,   190,   142,     0,     0,   186,     0,
       0,   172,   166,     0,     0,   142,   142,   164,     0,     0,
      31,    31,   242,   267,   270,   251,   248,     0,   273,   277,
     256,     0,   322,   321,   324,   329,     0,   235,     0,   258,
     254,   264,     0,     0,    70,   142,     0,    31,   142,    31,
      31,    51,    58,     0,     0,     0,    31,    30,    42,   317,
       0,     0,   299,   311,   312,   286,     0,   292,     0,   289,
     306,   309,   142,   142,   154,   135,     0,   142,     0,   124,
     140,   141,   192,   142,   178,   142,   197,   183,   179,   201,
       0,     0,   173,     0,   205,     0,   168,   142,   177,   170,
     142,   142,   142,   180,   142,   160,   161,   148,    38,     0,
     225,     0,   347,    31,   236,   257,   266,   142,    69,     0,
     142,     0,   214,    79,    81,    53,    31,    56,    62,    41,
     300,   303,   294,     0,     0,   151,   155,     0,   133,   136,
       0,   194,   198,   191,   184,     0,   142,     0,   187,     0,
       0,     0,     0,   129,   142,   150,    37,   274,    31,   231,
     234,   228,   230,   237,   210,     0,   213,   142,     0,   290,
     142,     0,   193,     0,   202,   206,   169,   171,   181,   182,
     163,   231,     0,    31,    31,    31,   215,    57,   152,     0,
     142,   142,    31,    31,   232,   227,     0,     0,   139,   203,
     232,     0,   142,    31,   142,   233,   229,   216,     0,   138,
     142,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -534,    -2,   288,  -534,  -534,  -298,   -22,  -534,  -131,  -216,
     347,  -534,   276,   143,   315,  -262,  -490,  -130,   196,   511,
     630,  -166,   401,   -60,  -534,   579,    36,   -20,   668,   608,
     492,   535,   583,   262,   312,  -534,    98,  -534,  -533,  -471,
    -180,  -206,  -534,  -496,  -343,  -534,    68,   227,   140,   698,
     771,  -250,   765,  -534,  -399,    64,  -534,  -534,   110,  -534,
     452,   -16,   -79,  -534,   289,  -371,  -534,  -342,  -345,  -348,
    -534,  -534,  -288,   383,  -279,   386,  -534,   176,  -292,  -534,
     -19,  -534,  -360,  -534,  -534,  -534,  -534,  -353,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,   581,  -534,
     454,  -534,  -534,  -534,   509,   801,  -534
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    73,   509,   433,   501,   139,    74,   426,   195,   301,
     232,   510,   196,   434,   302,   421,   561,    39,   280,   181,
     182,   183,   273,   197,    75,   140,   125,   126,    77,   202,
     203,    78,   338,   476,   229,   230,   502,   586,   587,   357,
      79,   598,   599,   600,   477,   694,   695,   110,   116,   117,
     287,   288,    52,   365,   760,   761,   762,   637,   638,   238,
     239,   148,   171,    21,   168,   270,   370,   371,   379,   380,
      53,    22,   316,   317,   443,   318,   565,   566,   319,   450,
     320,   581,   321,    23,    24,   254,   385,   386,   157,    25,
      26,    27,    28,    88,   248,   631,   190,   163,   164,   264,
     265,    29,    30,    31,    32,    33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    44,    45,    50,    55,   482,    80,   231,    85,    86,
      87,    90,    91,    92,    93,   360,   439,   440,   352,   242,
     453,   617,   442,   358,   445,   442,   539,   291,   541,   173,
     519,   522,   523,   527,   446,   533,   423,   333,   135,   416,
      40,   105,   135,    76,   109,   672,   212,   789,   106,   118,
     213,    50,   129,   135,   451,    40,   607,   191,   678,   185,
     191,   192,   427,   428,   192,   191,   653,   429,   244,   192,
     151,   153,   387,   108,   191,   430,   388,   563,   192,   142,
     143,   144,   145,    97,   186,   112,   115,   494,   495,   100,
     101,   180,   496,   245,   102,   249,   583,    40,   219,   431,
     497,   127,   103,    98,   167,   170,   170,   128,   177,   194,
     691,   209,   194,   465,   374,   504,   704,   194,    99,   505,
     673,   201,   107,   602,   237,    43,   194,   506,   162,   236,
      40,    41,   136,   137,    54,    40,   136,   137,   120,    40,
     169,   736,   610,   263,   705,   175,    41,   136,   137,   491,
     184,   507,   790,   123,   115,   172,   486,   487,   488,   180,
     442,    40,   199,   262,   266,   550,   728,   269,   452,   574,
     272,   180,   138,   300,   490,   624,   432,   629,   634,   227,
     758,   498,   499,   452,   325,   109,   627,   326,    41,   -61,
     742,   133,   401,   299,   278,   389,   314,   512,   201,   134,
     199,   500,   350,   104,   212,    40,   803,   350,   213,   300,
     274,   615,    40,   175,   754,   483,   486,   487,   488,   484,
      46,    41,   349,   141,   214,    40,    41,   349,   508,   299,
      41,   485,    51,   284,   200,   215,   513,   404,   369,   216,
      40,   154,   217,   191,   378,   279,   382,   192,    40,   176,
     218,   384,    41,    76,   645,   146,   219,    89,   188,   689,
     398,    40,   690,    66,   147,   328,   220,   221,   179,   170,
     716,   417,   222,   193,   223,   399,   180,   224,    47,   545,
      51,   442,   453,   780,   442,   711,   712,   109,   314,   671,
     665,   652,   444,   666,   804,   194,    41,    66,   486,   487,
     488,    47,   562,    41,   329,   383,   314,   314,   314,   314,
     314,   314,   155,    48,   376,   647,    41,   276,   225,   412,
     201,   231,   206,   207,   745,    49,   206,   207,   191,   463,
     226,    41,   192,   350,   158,   480,    48,   227,   701,    41,
     648,   180,   474,   206,   207,   237,   658,   146,   668,   377,
     250,   251,    41,   349,   749,   737,   152,   750,   363,   459,
     486,   487,   488,   178,   746,   483,   486,   487,   488,   484,
     369,   702,   730,   263,   378,   378,   696,   703,   619,   378,
     194,   485,   676,  -204,   156,   795,   384,   669,   697,  -204,
      76,   535,   165,   262,   801,   269,   228,   269,    81,   130,
     272,   693,   166,   708,    82,    83,    35,    36,    37,   211,
     187,   131,   707,   109,   643,   198,   699,   234,   132,   447,
      38,   257,   258,   259,   206,   207,   243,    84,   700,   252,
     454,   448,   455,   253,   256,   314,   564,   483,   449,   121,
     277,   484,   122,   159,   160,   161,   314,   546,   286,   577,
     350,   314,   204,   485,   314,  -195,   558,  -195,   146,   559,
     205,   285,   304,   305,   149,   300,   235,   150,    66,   420,
     597,   555,   556,   179,   407,   408,   330,   208,   332,   210,
     334,   609,   335,   336,   611,   299,   146,   353,   356,   709,
     486,   487,   488,   756,   489,   649,   650,    66,   585,   240,
     486,   487,   488,   255,   616,   486,   487,   488,   241,   685,
     247,   364,   486,   487,   488,   369,   791,   571,   572,   604,
     605,   375,   391,   378,   682,   683,    94,    95,   246,   384,
     260,   771,   636,   261,   267,   268,   167,   405,   271,   773,
     300,   693,   275,   396,   282,   283,   413,   289,   290,   324,
     306,   331,   323,   327,   337,   359,   362,   367,   410,   366,
     299,   368,   372,   373,   381,   390,   350,   314,   395,   400,
     314,   393,   394,   422,   397,   402,   403,   279,   406,   314,
     435,   436,   409,   797,   350,   350,   349,   414,  -209,   415,
     418,   419,   420,   425,  -305,   437,   350,   300,   438,   456,
     468,   469,   457,   460,   597,   692,   461,   462,   478,   479,
     481,   464,   465,   466,   467,   470,   349,   299,   471,   472,
     473,   503,   521,   492,   511,   369,   493,   585,   515,   378,
     516,   517,   518,   524,   525,   526,   529,   531,   547,   269,
     530,   532,   528,   534,   538,   544,   548,   554,   553,   520,
     567,   212,   557,   569,   568,   213,   570,   575,   314,   564,
     540,   573,   576,   584,   350,   588,   543,   591,   593,   594,
     536,   214,   602,   603,   606,   677,   549,   608,   632,   621,
     625,   630,   215,   641,   597,   633,   216,   300,   704,   217,
     642,   635,   640,   644,   551,   552,   651,   218,   656,   713,
     660,   560,   657,   219,   659,   661,   662,   299,   667,   675,
     585,   674,   636,   220,   221,   350,   679,   582,   684,   222,
     686,   223,   714,   350,   224,   350,   589,   590,   687,   592,
     303,   688,   595,   315,   698,   349,   715,   717,   718,   725,
     720,   726,   732,   349,   727,   692,   739,   596,   733,   601,
     613,   614,   743,   744,   356,   747,   748,  -200,   212,   351,
     757,   765,   213,   767,   351,   225,   303,   350,  -210,   769,
     770,   778,   772,   776,   777,  -200,   779,   226,   214,   783,
     785,   784,  -200,   787,   227,   792,   802,   349,   793,   215,
     805,   622,   623,   216,   806,   810,   217,   626,   620,   578,
     628,   729,   612,   542,   218,   755,   339,   233,   322,   424,
     219,   281,   361,   618,   458,   775,   189,   111,   119,   514,
     220,   221,   782,   646,   763,   315,   222,   639,   223,   663,
     664,   224,   560,    96,   654,   655,   579,   731,   670,   580,
       0,     0,   392,   315,   315,   315,   315,   315,   315,   537,
       0,     0,     0,     0,   212,   680,   681,     0,   213,     0,
       0,     0,     0,     0,   475,     0,     0,     0,     0,     0,
       0,     0,   225,     0,   214,     0,     0,   356,   706,     0,
       0,     0,     0,     0,   226,   215,     0,     0,     0,   216,
     351,   227,   354,     0,     0,     0,     0,   710,     0,     0,
     218,     0,     0,     0,     0,     0,   219,   719,     0,     0,
     722,     0,     0,     0,     0,     0,   220,   221,     0,     0,
       0,     0,   222,   721,   223,   723,   724,   355,     0,     0,
       0,     0,   560,     0,   734,   735,     0,     0,     0,   738,
       0,     0,     0,     0,     0,   740,     0,   741,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   751,   752,     0,   753,     0,   225,     0,
       0,     0,   315,     0,     0,     0,     0,     0,     0,   764,
     226,  -157,   766,   315,     0,     0,     0,   227,   315,   759,
       0,   315,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   768,     0,     0,     0,     0,   351,   774,     0,
       0,     0,     0,     0,     0,     0,   356,     0,     0,   212,
       0,     0,   303,   213,     0,     0,     0,     0,     0,   786,
       0,     0,   788,     0,   781,     0,     0,     0,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,   798,   799,   216,     0,     0,   354,     0,   794,
     759,   796,     0,     0,   807,   218,   809,     0,   800,   759,
       0,   219,   811,     0,     0,     0,     0,     0,     0,   808,
       0,   220,   221,     0,     0,     0,     0,   222,     0,   223,
       0,     0,   355,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,   315,   212,     0,   315,     0,   213,
       0,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,     0,     0,   351,     0,   214,     0,     0,   212,     0,
       0,     0,   213,   225,     0,     0,   215,     0,     0,     0,
     216,   351,   351,   354,     0,   226,  -159,     0,   214,     0,
       0,   218,   227,   351,   303,     0,     0,   219,     0,   215,
       0,     0,     0,   216,     0,     0,   217,   220,   221,     0,
       0,     0,     0,   222,   218,   223,     0,   212,   355,     0,
     219,   213,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,     0,     0,     0,   315,   222,   214,   223,     0,
       0,   224,     0,     0,     0,     0,     0,     0,   215,     0,
       0,     0,   216,     0,     0,   354,     0,     0,     0,   225,
       0,   351,     0,   218,     0,     0,     0,     0,     0,   219,
       0,   226,  -162,     0,     0,     0,     0,     0,   227,   220,
     221,     0,   225,     0,   303,   222,     0,   223,     0,     0,
     355,     0,     0,     0,   226,   340,    56,    57,     0,     0,
       0,   227,     0,     0,     0,    40,     0,     0,    58,     0,
       0,     0,   351,     0,     0,     0,     0,     0,     0,     0,
     351,     0,   351,     0,     0,     0,     0,   341,   342,     0,
      60,   225,     0,     0,    61,     0,    56,    57,     0,     0,
     343,     0,     0,   226,     0,    40,     0,     0,    58,     0,
     227,     0,     0,   344,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,     0,     0,     0,    59,     0,
      60,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,    56,    57,   345,     0,     0,   159,   160,   161,
      64,    40,     0,     0,    58,   113,    41,    66,    67,    68,
      69,    70,   346,     0,     0,   347,     0,     0,     0,   348,
      62,     0,     0,     0,    59,     0,    60,     0,     0,     0,
      61,     0,     0,     0,    63,     0,     0,     0,     0,     0,
      64,     0,     0,    65,    56,    57,    41,    66,    67,    68,
      69,    70,    71,    40,     0,     0,    58,     0,     0,    72,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,    60,     0,
      63,     0,    61,     0,     0,     0,    64,     0,     0,    65,
      56,    57,    41,    66,    67,    68,    69,    70,   114,    40,
       0,     0,    58,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,    59,     0,    60,     0,     0,     0,    61,     0,
       0,     0,    63,   124,     0,     0,     0,     0,    64,     0,
       0,    65,    56,    57,    41,    66,    67,    68,    69,    70,
      71,    40,     0,     0,    58,     0,     0,    72,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,    60,     0,    63,     0,
      61,     0,     0,     0,    64,     0,     0,    65,     0,     0,
      41,    66,    67,    68,    69,    70,    71,    56,    57,     0,
       0,     0,     0,    72,     0,     0,    40,     0,     0,    58,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   307,
      63,    60,     0,     0,     0,    61,    64,     0,     0,    65,
      56,    57,    41,    66,    67,    68,    69,    70,   174,    40,
       0,     0,    58,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,   308,   309,     0,     0,     0,     0,     0,
       0,     0,    59,     0,    60,    56,    57,     0,    61,     0,
       0,     0,     0,     0,    40,   310,     0,    58,     0,     0,
       0,    64,     0,     0,   311,     0,     0,    41,     0,    67,
      68,    69,    70,   312,     0,     0,     0,    59,     0,    60,
     313,     0,     0,    61,    62,     0,     0,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,    40,    63,     0,
      58,     0,     0,     0,    64,     0,     0,    65,     0,     0,
      41,    66,    67,    68,    69,    70,   411,     0,     0,    62,
     307,     0,    60,    72,     0,     0,    61,     0,    56,    57,
       0,     0,     0,    63,     0,     0,     0,    40,     0,    64,
      58,     0,     0,     0,     0,    41,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,    72,     0,
     307,     0,    60,     0,     0,     0,    61,     0,     0,    56,
      57,     0,     0,     0,   292,     0,   310,   441,    40,     0,
       0,    58,    64,     0,     0,     0,     0,     0,    41,   293,
      67,    68,    69,    70,   312,     0,     0,   294,     0,     0,
       0,   313,     0,    60,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,     0,    41,     0,
      67,    68,    69,    70,   312,     0,     0,     0,     0,     0,
       0,   313,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,    41,
      66,    67,    68,    69,    70,   297,     0,     1,   298,     2,
       0,     3,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     8,
       0,     9,     0,    10,     0,     0,     0,     0,    11,     0,
      12,     0,     0,    13,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,     5,     6,   348,     8,   138,    10,    11,
      12,    13,    14,    15,    16,   231,   308,   309,   224,   149,
     318,   492,   310,   229,   312,   313,   397,   193,   399,   108,
     372,   376,   377,   381,   313,   388,   298,   217,     3,   289,
      30,    43,     3,     7,    46,    39,     4,    23,    62,    51,
       8,    53,    72,     3,    19,    30,    62,     4,   591,   111,
       4,     8,     3,     4,     8,     4,   556,     8,   111,     8,
      86,    87,   126,   136,     4,    16,   130,   437,     8,    81,
      82,    83,    84,     0,   136,    49,    50,     3,     4,     3,
       4,   113,     8,   136,     8,   155,   456,    30,    56,    40,
      16,    65,    16,    26,   106,   107,   108,    71,   110,    56,
     606,   131,    56,    40,   244,     4,    40,    56,    41,     8,
     114,   123,   136,   129,   146,    25,    56,    16,    92,   145,
      30,   121,    97,    98,    25,    30,    97,    98,   121,    30,
     130,   674,   485,   165,   615,   109,   121,    97,    98,   355,
     114,    40,   128,   130,   118,   130,   132,   133,   134,   181,
     448,    30,    95,   165,   166,   415,   656,   169,   133,   448,
     172,   193,   133,   195,   354,   517,   117,   525,   531,   137,
     127,    97,    98,   133,   204,   187,   130,   207,   121,   128,
     686,    19,   271,   195,    71,   255,   198,   363,   200,   136,
      95,   117,   224,   117,     4,    30,    40,   229,     8,   231,
     174,   138,    30,   177,   138,   111,   132,   133,   134,   115,
      25,   121,   224,   133,    24,    30,   121,   229,   117,   231,
     121,   127,     5,    39,   129,    35,   366,    39,   240,    39,
      30,    25,    42,     4,   246,   122,   248,     8,    30,   109,
      50,   253,   121,   217,    39,   127,    56,   126,   118,   602,
     114,    30,   605,   122,   136,    96,    66,    67,   127,   271,
     641,   290,    72,    34,    74,   129,   298,    77,    83,   409,
      53,   569,   580,   754,   572,   627,   631,   289,   290,   581,
     569,   553,   311,   572,   128,    56,   121,   122,   132,   133,
     134,    83,   433,   121,   135,    95,   308,   309,   310,   311,
     312,   313,   133,   118,    83,   111,   121,   177,   118,   283,
     322,   452,   128,   129,    96,   130,   128,   129,     4,   331,
     130,   121,     8,   355,   133,   135,   118,   137,    96,   121,
     136,   363,   344,   128,   129,   367,   562,   127,    96,   118,
      47,    48,   121,   355,   697,   121,   136,   700,    34,   323,
     132,   133,   134,   114,   136,   111,   132,   133,   134,   115,
     372,   129,   660,   395,   376,   377,   115,   135,   509,   381,
      56,   127,   588,   129,   136,   784,   388,   135,   127,   135,
     354,   393,    62,   395,   793,   397,   134,   399,    31,   115,
     402,   607,   136,   619,    37,    38,    43,    44,    45,   133,
      18,   127,   618,   415,   544,   130,   115,   141,   134,   115,
      57,   159,   160,   161,   128,   129,   150,    60,   127,   126,
     112,   127,   114,   130,   158,   437,   438,   111,   134,   133,
     178,   115,   136,    72,    73,    74,   448,   411,   186,   451,
     472,   453,   129,   127,   456,   129,   129,   131,   127,   132,
     110,   185,   111,   112,   133,   487,   133,   136,   122,   123,
     472,   128,   129,   127,   278,   279,   214,   135,   216,   123,
     218,   483,   220,   221,   486,   487,   127,   225,   226,   620,
     132,   133,   134,   709,   136,   111,   112,   122,   462,   130,
     132,   133,   134,   133,   136,   132,   133,   134,   136,   136,
     136,   235,   132,   133,   134,   517,   136,   128,   129,   128,
     129,   245,   260,   525,   128,   129,    17,    18,   130,   531,
     136,   737,   534,   129,   111,   136,   538,   275,    16,   745,
     562,   747,   136,   267,   129,   132,   284,    18,   136,   131,
     136,   127,   136,   128,    80,   136,   136,   129,   282,   133,
     562,   128,   130,   136,   130,   136,   588,   569,   129,   131,
     572,   136,   136,   297,   130,   129,   131,   122,   131,   581,
     304,   305,   133,   789,   606,   607,   588,   136,    18,    18,
     132,   127,   123,   127,    39,   130,   618,   619,   130,   129,
     338,   339,   131,   128,   606,   607,   123,   130,   346,   347,
     348,    54,    40,    68,   130,   127,   618,   619,   127,   130,
     127,   359,   136,   138,   362,   627,   131,   591,   129,   631,
     133,   129,   131,   133,   129,   131,   133,   129,   111,   641,
     133,   131,   136,   130,   129,   133,   128,   108,   129,   373,
     114,     4,   131,   129,   114,     8,   110,   123,   660,   661,
     398,   135,    39,   135,   686,   121,   404,   130,    73,    75,
     394,    24,   129,   110,    62,    32,   414,   135,   126,   132,
     131,   131,    35,   129,   686,   126,    39,   709,    40,    42,
     128,   131,   131,   128,   418,   419,   128,    50,   129,   133,
     136,   425,   128,    56,   131,   129,   131,   709,   128,   131,
     674,   129,   714,    66,    67,   737,   131,   455,   128,    72,
     129,    74,   129,   745,    77,   747,   464,   465,   131,   467,
     195,   128,   470,   198,   128,   737,   131,   136,   128,   128,
     136,   132,   128,   745,   131,   747,   131,   471,   123,   473,
     488,   489,   128,   131,   492,   129,   135,   110,     4,   224,
     131,   128,     8,   136,   229,   118,   231,   789,    18,   135,
     114,   135,   128,   128,   128,   128,   135,   130,    24,    96,
     111,    97,   135,   131,   137,    96,   136,   789,    97,    35,
     128,   515,   516,    39,   128,   128,    42,   521,   510,   452,
     524,   658,   487,   402,    50,   707,   223,   139,   200,   298,
      56,   181,   233,   501,   322,   747,   118,    46,    53,   367,
      66,    67,   758,   547,   714,   290,    72,   538,    74,   567,
     568,    77,   556,    32,   558,   559,   453,   661,   576,   453,
      -1,    -1,   261,   308,   309,   310,   311,   312,   313,   395,
      -1,    -1,    -1,    -1,     4,   593,   594,    -1,     8,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    24,    -1,    -1,   615,   616,    -1,
      -1,    -1,    -1,    -1,   130,    35,    -1,    -1,    -1,    39,
     355,   137,    42,    -1,    -1,    -1,    -1,   621,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,   645,    -1,    -1,
     648,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    72,   647,    74,   649,   650,    77,    -1,    -1,
      -1,    -1,   656,    -1,   672,   673,    -1,    -1,    -1,   677,
      -1,    -1,    -1,    -1,    -1,   683,    -1,   685,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   701,   702,    -1,   704,    -1,   118,    -1,
      -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,    -1,   717,
     130,   131,   720,   448,    -1,    -1,    -1,   137,   453,   713,
      -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   726,    -1,    -1,    -1,    -1,   472,   746,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   754,    -1,    -1,     4,
      -1,    -1,   487,     8,    -1,    -1,    -1,    -1,    -1,   767,
      -1,    -1,   770,    -1,   758,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,   790,   791,    39,    -1,    -1,    42,    -1,   783,
     784,   785,    -1,    -1,   802,    50,   804,    -1,   792,   793,
      -1,    56,   810,    -1,    -1,    -1,    -1,    -1,    -1,   803,
      -1,    66,    67,    -1,    -1,    -1,    -1,    72,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,   569,     4,    -1,   572,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,   588,    -1,    24,    -1,    -1,     4,    -1,
      -1,    -1,     8,   118,    -1,    -1,    35,    -1,    -1,    -1,
      39,   606,   607,    42,    -1,   130,   131,    -1,    24,    -1,
      -1,    50,   137,   618,   619,    -1,    -1,    56,    -1,    35,
      -1,    -1,    -1,    39,    -1,    -1,    42,    66,    67,    -1,
      -1,    -1,    -1,    72,    50,    74,    -1,     4,    77,    -1,
      56,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,   660,    72,    24,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,   118,
      -1,   686,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,   137,    66,
      67,    -1,   118,    -1,   709,    72,    -1,    74,    -1,    -1,
      77,    -1,    -1,    -1,   130,    20,    21,    22,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,    -1,   737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     745,    -1,   747,    -1,    -1,    -1,    -1,    52,    53,    -1,
      55,   118,    -1,    -1,    59,    -1,    21,    22,    -1,    -1,
      65,    -1,    -1,   130,    -1,    30,    -1,    -1,    33,    -1,
     137,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,   109,    -1,    -1,    72,    73,    74,
     115,    30,    -1,    -1,    33,    34,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,   130,    -1,    -1,    -1,   134,
      95,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      59,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,   118,    21,    22,   121,   122,   123,   124,
     125,   126,   127,    30,    -1,    -1,    33,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
     109,    -1,    59,    -1,    -1,    -1,   115,    -1,    -1,   118,
      21,    22,   121,   122,   123,   124,   125,   126,   127,    30,
      -1,    -1,    33,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    59,    -1,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,    21,    22,   121,   122,   123,   124,   125,   126,
     127,    30,    -1,    -1,    33,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,   109,    -1,
      59,    -1,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,    21,    22,    -1,
      -1,    -1,    -1,   134,    -1,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
     109,    55,    -1,    -1,    -1,    59,   115,    -1,    -1,   118,
      21,    22,   121,   122,   123,   124,   125,   126,   127,    30,
      -1,    -1,    33,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    21,    22,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    30,   109,    -1,    33,    -1,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    53,    -1,    55,
     134,    -1,    -1,    59,    95,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,   109,    -1,
      33,    -1,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    95,
      53,    -1,    55,   134,    -1,    -1,    59,    -1,    21,    22,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    30,    -1,   115,
      33,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
      53,    -1,    55,    -1,    -1,    -1,    59,    -1,    -1,    21,
      22,    -1,    -1,    -1,    26,    -1,   109,   110,    30,    -1,
      -1,    33,   115,    -1,    -1,    -1,    -1,    -1,   121,    41,
     123,   124,   125,   126,   127,    -1,    -1,    49,    -1,    -1,
      -1,   134,    -1,    55,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,    -1,    27,   130,    29,
      -1,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    58,    -1,
      60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    29,    31,    36,    37,    38,    42,    49,    51,
      53,    58,    60,    63,    70,    80,    81,    83,   118,   119,
     120,   202,   210,   222,   223,   228,   229,   230,   231,   240,
     241,   242,   243,   244,   245,    43,    44,    45,    57,   156,
      30,   121,   140,    25,   140,   140,    25,    83,   118,   130,
     140,   186,   191,   209,    25,   140,    21,    22,    33,    53,
      55,    59,    95,   109,   115,   118,   122,   123,   124,   125,
     126,   127,   134,   140,   145,   163,   165,   167,   170,   179,
     140,    31,    37,    38,    60,   140,   140,   140,   232,   126,
     140,   140,   140,   140,   243,   243,   244,     0,    26,    41,
       3,     4,     8,    16,   117,   140,    62,   136,   136,   140,
     186,   189,   165,    34,   127,   165,   187,   188,   140,   191,
     121,   133,   136,   130,   110,   165,   166,   165,   165,   166,
     115,   127,   134,    19,   136,     3,    97,    98,   133,   144,
     164,   133,   140,   140,   140,   140,   127,   136,   200,   133,
     136,   200,   136,   200,    25,   133,   136,   227,   133,    72,
      73,    74,   165,   236,   237,    62,   136,   140,   203,   130,
     140,   201,   130,   201,   127,   165,   187,   140,   114,   127,
     145,   158,   159,   160,   165,   111,   136,    18,   187,   188,
     235,     4,     8,    34,    56,   147,   151,   162,   130,    95,
     129,   140,   168,   169,   129,   110,   128,   129,   135,   166,
     123,   151,     4,     8,    24,    35,    39,    42,    50,    56,
      66,    67,    72,    74,    77,   118,   130,   137,   172,   173,
     174,   147,   149,   167,   151,   133,   200,   145,   198,   199,
     130,   136,   156,   151,   111,   136,   130,   136,   233,   162,
      47,    48,   126,   130,   224,   133,   151,   172,   172,   172,
     136,   129,   140,   145,   238,   239,   140,   111,   136,   140,
     204,    16,   140,   161,   165,   136,   187,   172,    71,   122,
     157,   159,   129,   132,    39,   151,   172,   189,   190,    18,
     136,   160,    26,    41,    49,    95,   107,   127,   130,   140,
     145,   148,   153,   170,   111,   112,   136,    53,    87,    88,
     109,   118,   127,   134,   140,   170,   211,   212,   214,   217,
     219,   221,   168,   136,   131,   166,   166,   128,    96,   135,
     172,   127,   172,   179,   172,   172,   172,    80,   171,   171,
      20,    52,    53,    65,    78,   109,   127,   130,   134,   140,
     145,   170,   180,   172,    42,    77,   172,   178,   180,   136,
     148,   164,   136,    34,   151,   192,   133,   129,   128,   140,
     205,   206,   130,   136,   156,   151,    83,   118,   140,   207,
     208,   130,   140,    95,   140,   225,   226,   126,   130,   162,
     136,   172,   237,   136,   136,   129,   151,   130,   114,   129,
     131,   201,   129,   131,    39,   172,   131,   157,   157,   133,
     151,   127,   165,   172,   136,    18,   190,   219,   132,   127,
     123,   154,   151,   154,   158,   127,   146,     3,     4,     8,
      16,    40,   117,   142,   152,   151,   151,   130,   130,   217,
     217,   110,   211,   213,   219,   211,   213,   115,   127,   134,
     218,    19,   133,   144,   112,   114,   129,   131,   169,   165,
     128,   123,   130,   140,    54,    40,    68,   130,   172,   172,
     127,   127,   130,   127,   140,   110,   172,   183,   172,   172,
     135,   172,   183,   111,   115,   127,   132,   133,   134,   136,
     179,   180,   138,   131,     3,     4,     8,    16,    97,    98,
     117,   143,   175,   172,     4,     8,    16,    40,   117,   141,
     150,   172,   160,   156,   199,   129,   133,   129,   131,   206,
     151,   136,   207,   207,   133,   129,   131,   208,   136,   133,
     133,   129,   131,   226,   130,   140,   151,   239,   129,   204,
     172,   204,   161,   172,   133,   156,   165,   111,   128,   172,
     190,   151,   151,   129,   108,   128,   129,   131,   129,   132,
     151,   155,   147,   221,   140,   215,   216,   114,   114,   129,
     110,   128,   129,   135,   213,   123,    39,   140,   149,   212,
     214,   220,   172,   221,   135,   165,   176,   177,   121,   172,
     172,   130,   172,    73,    75,   172,   151,   140,   180,   181,
     182,   151,   129,   110,   128,   129,    62,    62,   135,   140,
     183,   140,   153,   172,   172,   138,   136,   178,   173,   147,
     141,   132,   151,   151,   206,   131,   151,   130,   151,   208,
     131,   234,   126,   126,   226,   131,   140,   196,   197,   203,
     131,   129,   128,   156,   128,    39,   151,   111,   136,   111,
     112,   128,   154,   155,   151,   151,   129,   128,   148,   131,
     136,   129,   131,   172,   172,   213,   213,   128,    96,   135,
     172,   217,    39,   114,   129,   131,   180,    32,   177,   131,
     172,   172,   128,   129,   128,   136,   129,   131,   128,   183,
     183,   182,   140,   180,   184,   185,   115,   127,   128,   115,
     127,    96,   129,   135,    40,   178,   172,   180,   148,   147,
     151,   206,   207,   133,   129,   131,   204,   136,   128,   172,
     136,   151,   172,   151,   151,   128,   132,   131,   155,   152,
     211,   216,   128,   123,   172,   172,   177,   121,   172,   131,
     172,   172,   182,   128,   131,    96,   136,   129,   135,   183,
     183,   172,   172,   172,   138,   175,   148,   131,   127,   151,
     193,   194,   195,   197,   172,   128,   172,   136,   151,   135,
     114,   180,   128,   180,   172,   185,   128,   128,   135,   135,
     178,   151,   194,    96,    97,   111,   172,   131,   172,    23,
     128,   136,    96,    97,   151,   193,   151,   180,   172,   172,
     151,   193,   136,    40,   128,   128,   128,   172,   151,   172,
     128,   172
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
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   173,   173,   173,   173,   174,   175,   175,
     175,   176,   176,   177,   177,   177,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   179,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   181,   181,   182,   182,   182,   183,
     183,   183,   184,   184,   184,   185,   185,   186,   186,   187,
     187,   188,   188,   188,   188,   188,   188,   189,   189,   190,
     190,   191,   191,   191,   191,   192,   192,   193,   193,   194,
     194,   195,   195,   195,   196,   197,   197,   197,   198,   198,
     199,   199,   200,   200,   201,   201,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   203,   203,
     203,   204,   204,   204,   204,   204,   204,   205,   206,   206,
     206,   207,   207,   207,   207,   208,   208,   208,   209,   210,
     210,   211,   211,   212,   212,   213,   213,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     215,   215,   216,   216,   217,   218,   217,   219,   220,   219,
     219,   219,   219,   221,   221,   221,   222,   222,   223,   224,
     224,   225,   225,   226,   226,   227,   227,   227,   227,   227,
     228,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   231,   231,   231,   232,   233,   234,   231,   235,   231,
     231,   236,   236,   236,   237,   237,   238,   238,   239,   239,
     240,   240,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     243,   244,   244,   245,   245
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
       3,     2,     2,     6,     4,     5,     6,    13,    11,     9,
       5,     5,     0,     1,     1,     1,     1,     3,     0,     3,
       4,     3,     5,     1,     2,     3,     1,     2,     2,     3,
       4,     4,     5,     6,     3,     3,     3,     1,     4,     6,
       4,     6,     3,     1,     1,     2,     2,     4,     4,     4,
       4,     6,     6,     4,     5,     2,     3,     5,     2,     3,
       3,     5,     4,     6,     3,     1,     1,     2,     3,     1,
       2,     3,     3,     5,     1,     1,     3,     1,     1,     3,
       7,     3,     5,     8,     7,     9,    12,     3,     2,     1,
       3,     3,     2,     5,     4,     4,     1,     3,     1,     5,
       1,     1,     3,     5,     3,     1,     2,     3,     3,     1,
       1,     3,     5,     3,     1,     3,     5,     4,     7,     6,
       6,     7,     4,     6,     8,     6,     7,     8,     5,     4,
       3,     1,     2,     3,     4,     3,     5,     3,     1,     2,
       3,     2,     2,     3,     5,     1,     2,     3,     5,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     4,
       6,     2,     4,     3,     5,     3,     2,     3,     3,     4,
       3,     1,     1,     3,     1,     0,     4,     2,     0,     4,
       3,     4,     4,     1,     2,     3,     6,     8,     2,     1,
       1,     3,     3,     1,     3,     0,     2,     4,     3,     5,
       4,     5,     4,     6,     3,     3,     3,     4,     3,     3,
       3,     5,     5,     3,     0,     0,     0,     8,     0,     6,
       2,     2,     2,     2,     1,     3,     3,     3,     1,     3,
       2,     4,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     2,     2,
       1,     1,     2,     1,     0
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
#line 134 "sail.y"
       {
       //cout << $1.stringVal << endl; 
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
                if(strstr((yyvsp[0].node).stringVal, "UW")){ 
                     optmp.name.pop_back();    
                     optmp.name.pop_back();    
                     optmp.name += "_UW";     
                }    
                if(strstr((yyvsp[0].node).stringVal, "ORCB")){ 
                     optmp.name.pop_back();   
                     optmp.name += "_B";      
                }    
                if(strstr((yyvsp[0].node).stringVal, "EXT")){  
                     if(!strcmp((yyvsp[0].node).stringVal,"RISCV_SEXTB")){
                        optmp.name.pop_back(); 
                        optmp.name += "_B"; 
                     }
                     else if(strstr((yyvsp[0].node).stringVal, "BEXT")){
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
                        if(strstr((yyvsp[0].node).stringVal, "PACKW")){
                                optmp.name.clear();
                                optmp.name = (yyvsp[0].node).stringVal;
                                optmp.name.erase(0,5); 
                        }
                         
                }
        }            
        else if(check_multi == 1 && (strstr((yyvsp[0].node).stringVal, "_H") && strstr((yyvsp[0].node).stringVal, "F"))){
                //cout << $1.stringVal << endl;
                optmp.name = (yyvsp[0].node).stringVal; 
                optmp.opcode = "";
                unit_check = 0;   
                //OpNameStr = optmp.name;  
        } 
}
#line 2709 "y.tab.c"
    break;

  case 26: /* pat_op: At  */
#line 389 "sail.y"
           {
                if(instr_bits > 1){
                        BitStr=BitStr+"@";
                        instrbits_check = 1;
                }
        }
#line 2720 "y.tab.c"
    break;

  case 28: /* pat_op: '^'  */
#line 396 "sail.y"
              {
                if(assemblyString == 3){
                        assemblyStr+=",";
                }
        }
#line 2730 "y.tab.c"
    break;

  case 112: /* lit: True  */
#line 540 "sail.y"
           { 
        if(mext_MULcheck == 2){
                Mexttmp.name += "True,";
        } 
        if(mext_MULcheck1 == 1){
                Mexttmp1.name += "True,";
        } 
   }
#line 2743 "y.tab.c"
    break;

  case 113: /* lit: False  */
#line 548 "sail.y"
           { 
        if(mext_MULcheck == 2){
                Mexttmp.name += "False,";
        } 
        if(mext_MULcheck1 == 1){
                Mexttmp1.name += "False,";
        } 
   }
#line 2756 "y.tab.c"
    break;

  case 115: /* lit: Num  */
#line 557 "sail.y"
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
#line 2773 "y.tab.c"
    break;

  case 119: /* lit: Bin_literal  */
#line 572 "sail.y"
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
#line 2801 "y.tab.c"
    break;

  case 121: /* lit: STRING_LITERAL  */
#line 596 "sail.y"
                    {
                if(mext_MULcheck1 == 1 && strstr((yyvsp[0].node).stringVal, "mul")){
                        //cout << $1.stringVal << endl; 
                        Mexttmp1.opcode = (yyvsp[0].node).stringVal;
                }
                if(assemblyString == 3){
                        assemblyStr+=(yyvsp[0].node).stringVal;
                }
        }
#line 2815 "y.tab.c"
    break;

  case 305: /* $@1: %empty  */
#line 875 "sail.y"
            { if(encdec_IF == 1)encdec_IF = 2; }
#line 2821 "y.tab.c"
    break;

  case 308: /* $@2: %empty  */
#line 879 "sail.y"
                   {
        instrbits_check = 1;
        if(instr_bits == 1)
                instr_bits++;
        check_multi = 0;
        if(assemblyString == 2){
                assemblyString=3;
        }
     }
#line 2835 "y.tab.c"
    break;

  case 309: /* mapcl: mpexp Bidir $@2 mpexp  */
#line 887 "sail.y"
             {if(mext_MULcheck1 == 1){
                        Mext_insert(MextTable1,Mexttmp1);
                        Mexttmp1.name.clear();
                        Mexttmp1.name = "";
                 }}
#line 2845 "y.tab.c"
    break;

  case 315: /* mapcl_list: mapcl ',' mapcl_list  */
#line 899 "sail.y"
                               {mext_MULcheck = 0;}
#line 2851 "y.tab.c"
    break;

  case 317: /* map_def: Mapping id ':' typschm '=' '{' mapcl_list '}'  */
#line 903 "sail.y"
                                                        {
                oplistcheck = 0;
                mapop = 0;
        }
#line 2860 "y.tab.c"
    break;

  case 344: /* $@3: %empty  */
#line 950 "sail.y"
                        {
                        if(assemblyString == 4){ 
                                create_opccoutput(opcctable,opccoutputtable);
                        }
                        assemblyString = 0;
                }
#line 2871 "y.tab.c"
    break;

  case 345: /* $@4: %empty  */
#line 955 "sail.y"
                       {                             
                        op_new_table(symtable_stack,table);
                        opcc_new_table(opccsymtable_stack,opcctable);
                        opcc_new_table(opccTmpsymtable_stack,opccTmptable);
                        immbitcheck = 1;
                        mapop = 0;
                        immbit = 0;
                        oplistcheck = 0;
                 }
#line 2885 "y.tab.c"
    break;

  case 346: /* $@5: %empty  */
#line 963 "sail.y"
                         { unit_check =1; }
#line 2891 "y.tab.c"
    break;

  case 348: /* $@6: %empty  */
#line 964 "sail.y"
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
#line 2926 "y.tab.c"
    break;

  case 349: /* scattered_def: Mapping Clause ID $@6 '=' mapcl  */
#line 993 "sail.y"
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
                                assemblyString =4;
                        }
                }
#line 2959 "y.tab.c"
    break;


#line 2963 "y.tab.c"

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

#line 1073 "sail.y"
 
void yyerror (string s) 
{
    cerr << "line " << linenum << ": \033[1;31m" << s << "\033[1;0m" << endl;
    exit(1); 
}
 
int main() 
{  
    yyparse();
    create_opccoutput(opcctable,opccoutputtable);
    //printf("%d\n",immbit);    
    op_dump(table);
    //opcc_dump(opcctable);
    //Mext_dump(MextTable);      
    //Mext_dump(MextTable1); 
    opccoutput_dump(opccoutputtable);      
    output_dump(instrBitTable);       
    cout << "finish" << endl;
    return 0;
}   

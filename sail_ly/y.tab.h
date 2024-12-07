/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 313 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

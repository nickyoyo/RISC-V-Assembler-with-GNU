%{
#include "symboltable.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;
void yyerror(string s);
extern int linenum; /* declared in p2.l */

SymbolTable *scope;
Symbol *symbol;
bool CurrentMethod = false;
vector<int> methodparameter;
bool Mainexist = false;

int yylex(void);

%}
 
%union {
   struct {
    int ival;
    bool bval;
    float fval;
    char *str;
    char *id;
    char *type;
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

%token Num Bin_literal Hex_literal

%token Eq EqGt Unit Colon

%token OpId Attribute LINE_DIRECTIVE

%start file

%token FIXITY

%token <node> TyVar

%token <string> ID

%token <node> STRING_LITERAL

%%
id: ID 
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
pat_op : At
        | ColonColon
        | '^'
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

typ: prefix_typ_op postfix_typ list_2
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

lit: True
   | False
   | Unit
   | Num
   | Undefined
   | Bitzero
   | Bitone
   | Bin_literal
   | Hex_literal
   | STRING_LITERAL
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
          | id ':' typ
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
        | id '(' mpat_list ')'
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
     | mpat If_ exp
     ;

mapcl: Attribute mapcl
     | mpexp Bidir mpexp
     | mpexp EqGt exp
     | Forwards mpexp EqGt exp
     | Backwards mpexp EqGt exp
     ;

mapcl_list: mapcl
        | mapcl ','
        | mapcl ',' mapcl_list
        ;

map_def: Mapping id '=' '{' mapcl_list '}'
        | Mapping id ':' typschm '=' '{' mapcl_list '}'
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
                | Union Clause id '=' type_union
                | Mapping Clause id '=' mapcl
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
    //sym_dump(table);             
    cout << "finish" << endl;
    return 0;
}
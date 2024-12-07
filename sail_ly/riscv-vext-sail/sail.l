%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; }//printf("<%s>\n",#t);
#define tokenInteger(t) {LIST; printf("<%s:%s>\n","int",yytext);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}
#define tokenKeyword() {LIST; }//printf("<keyword: %s>\n", yytext);
#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG]; 
char str_buf[MAX_LINE_LENG];
// extern "C" int yylex();

%} 

/* regular definitions */
letter [A-Za-z]
number [0-9]+
id     ({letter}|_)({letter}|{number}|_|\')*
float  {number}+(\.{number}+)?
integer (-)?{number}+
hex 0x[A-Fa-f0-9_]+
bin 0b[0-1_]+
oper_char [!%&+-.:<>=@^|#]
oper_charcomment [/*]
operator {oper_char}+(_{id})? 
operatorcomment {oper_charcomment}+(_{id})? 
type_var  \'{id}
wsc [ \t]
ws {wsc}+

line_directive ${id}
%x STRING
%x COMMENT_1   
%x COMMENT_2
%x PRE_PROCESS
%% 
%Cpp-style-comment
 
"//"          {
              BEGIN COMMENT_1;
              strcat(buf, "//");
              } 
<COMMENT_1>\n {
              LIST;
             // printf("%d: %s\n", linenum++, buf);
              buf[0] = '\0';
              BEGIN INITIAL;
              }
<COMMENT_1>.  {LIST;}

%C-style-comment
"/*"            {
                BEGIN COMMENT_2;
                strcat(buf, "//");
                }
"/**"            {
                BEGIN COMMENT_2;
                strcat(buf, "//");
                }
<COMMENT_2>"*/" {
                BEGIN INITIAL;
                strcat(buf, "//");
                }
<COMMENT_2>\n   {
              //  printf("%d: %s\n", linenum++, buf);
                buf[0] = '\0';
                }
<COMMENT_2>.    {LIST;}

{line_directive} {
        BEGIN PRE_PROCESS;
        LIST;
}
<PRE_PROCESS>. {
        LIST;
}
<PRE_PROCESS>\n {
      //  printf("%d: %s\n", linenum++, buf);
        buf[0] = '\0';
        BEGIN INITIAL;
        return LINE_DIRECTIVE;
} 
 

\"  {BEGIN STRING;LIST;}
<STRING>\"\" {LIST;strcat(str_buf, "\"");}
<STRING>\" {LIST; /*printf("<string:%s>\n",str_buf);*/ yylval.node.stringVal = strdup(str_buf); str_buf[0]='\0';BEGIN INITIAL; return STRING_LITERAL;}
<STRING>. {LIST;strcat(str_buf, yytext);}

"~" {token('~'); return '~';}

%Delimiters
"."  {token('.'); return '.';}
".." {token(".."); return DotDot;}
","  {token(','); return ',';} 
":"  {token(':'); return ':';}  
"::" {token("::"); return ColonColon;}
";"  {token(';'); return ';';} 
"("  {token('('); return '(';}
")"  {token(')'); return ')';} 
"["  {token('['); return '[';}
"]"  {token(']'); return ']';}
"[|" {token("[|"); return LsquareBar;}
"|]" {token("|]"); return RsquareBar;}
"{"  {token('{') ; return '{';}
"}"  {token("}") ; return '}';}
"{|" {token("{|") ; return LcurlyBar;}
"|}" {token("|}") ; return RcurlyBar;}
"_"  {token('_'); return Under;}
"->" {token("->"); return MinusGt;}
"<->" {token("<->"); return Bidir;}
"=>" {token("=>"); return EqGt;}
"@"  {token("@"); return At;}
"2"{ws}"^" {token("2^"); return TwoCaret;}
"()" {token("()"); return Unit;}
unit {token("()"); return Unit;}


%Operators

"="  {token("=");  return '=';} 
"<"  {token("<");  return OpId;} 
"<=" {token("<="); return OpId;}    
">=" {token(">="); return OpId;}    
">"  {token(">");  return OpId;}   
"==" {token("=="); return OpId;}   
"!=" {token("!="); return OpId;}    
"&"  {token("&"); return OpId;}   
"|"  {token("|"); return '|';}      
"^"  {token("!");  return '^';}           
        
%keyword    
and      {tokenKeyword(); return And;}  
as       {tokenKeyword(); return As;} 
assert   {tokenKeyword(); return Assert;}
bitzero {tokenKeyword(); return Bitzero;} 
bitone {tokenKeyword(); return Bitone;} 
by      {tokenKeyword(); return By;}
match {tokenKeyword(); return Match;}  
clause {tokenKeyword(); return Clause;} 
dec  {tokenKeyword(); return Dec;}
operator {tokenKeyword(); return Op;} 
default {tokenKeyword(); return Default;} 
effect {tokenKeyword(); return Effect;} 
end {tokenKeyword(); return End;}  
enum {tokenKeyword(); return Enum;}
else {tokenKeyword(); return Else;}  
exit {tokenKeyword(); return Exit;}   
cast {tokenKeyword(); return Cast;} 
false  {tokenKeyword(); return False;}    
forall {tokenKeyword(); return Forall;}        
foreach {tokenKeyword(); return Foreach;}        
function {tokenKeyword(); return Function_;}  
mapping {tokenKeyword(); return Mapping;}  
overload {tokenKeyword(); return Overload;}    
throw {tokenKeyword(); return Throw;}   
try {tokenKeyword(); return Try;}   
catch {tokenKeyword(); return Catch;}    
if {tokenKeyword(); return If_;}    
in {tokenKeyword(); return In;}      
inc  {tokenKeyword(); return Inc;}   
let  {tokenKeyword(); return Let_;}  
var {tokenKeyword(); return Var;}    
ref {tokenKeyword(); return Ref;} 
Int  {tokenKeyword(); return Int;}  
Order {tokenKeyword(); return Order;} 
Bool  {tokenKeyword(); return Bool;}
pure {tokenKeyword(); return Pure;}
monadic {tokenKeyword(); return Monadic;}
register {tokenKeyword(); return Register;}
return {tokenKeyword(); return Return;}
scattered {tokenKeyword(); return Scattered;}
sizeof {tokenKeyword(); return Sizeof;}
constraint {tokenKeyword(); return Constraint;}
constant {tokenKeyword(); return Constant;}
struct {tokenKeyword(); return Struct;}
then {tokenKeyword(); return Then;}
true {tokenKeyword(); return True;}
Type {tokenKeyword(); return TYPE;}
type {tokenKeyword(); return Typedef;}
undefined {tokenKeyword(); return Undefined;}
union {tokenKeyword(); return Union;}
newtype {tokenKeyword(); return Newtype;}
with {tokenKeyword(); return With;}
val {tokenKeyword(); return Val;} 
outcome {tokenKeyword(); return Outcome;}
instantiation {tokenKeyword(); return Instantiation;}
impl {tokenKeyword(); return Impl;}
private {tokenKeyword(); return Private;}
repeat {tokenKeyword(); return Repeat;}
until {tokenKeyword(); return Until;}
while {tokenKeyword(); return While;} 
do {tokenKeyword(); return Do;} 
mutual {tokenKeyword(); return Mutual;}  
bitfield {tokenKeyword(); return Bitfield;}
configuration {tokenKeyword(); return Configuration;} 
termination_measure {tokenKeyword(); return TerminationMeasure;}
forwards {tokenKeyword(); return Forwards;}
backwards {tokenKeyword(); return Backwards;}
internal_plet {tokenKeyword(); return InternalPLet;}
internal_return {tokenKeyword(); return InternalReturn;}
internal_assume {tokenKeyword(); return InternalAssume;}
"infix"  {tokenKeyword(); return FIXITY;}      
"infixl" {tokenKeyword(); return FIXITY;}   
"infixr" {tokenKeyword(); return FIXITY;}  
     
{id}    {   
        //tokenString(ID, yytext); 
        yylval.node.stringVal = strdup(yytext);
        return ID;    
        }           
{integer} {    
        //  tokenInteger("int");  
          yylval.node.ival = atoi(yytext);
           return Num;     
          }          
             
{bin} {     
        yylval.node.stringVal = strdup(yytext);
        return Bin_literal;
} 
{hex} { 
        yylval.node.stringVal = strdup(yytext);
        //printf("hex\n");
        return Hex_literal; 
} 
 
{operator} { 
        return OpId;
}

{operatorcomment} {
        return OpId;
}

{type_var} {
        //tokenString(Type ID, yytext);
        return TyVar;
}



\n      {
        LIST;
        //printf("%d: %s\n", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}
 
<<EOF>> {
        LIST; 
        //printf("%d: %s\n\n", linenum++, buf);
        buf[0] = '\0';
        yyterminate();
        }

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1); 
        }

%%

%option noyywrap
%option never-interactive
%option yylineno

%{
    #include <stdio.h>
    void remove_all_inputs_of_symbol(const char * str, char * result, char deleted_symbol);
    int bin_from_str_to_dec(const char * str);
    bool isNotKeyword(const char* str);
%}

%x MLCOMMENT SLCOMMENT STRING CHAR IDENTIFICATOR MLSTRING
DIGIT             [0-9]
HEX_DIGIT         [0-9A-Fa-f]
BIN_DIGIT         [01]

%%
%{ 	int numInt;
long numLong;
float numFloat;
double numDouble;
char commentText[1000];
char str[1000];
char tmpChar;
char * tmp = 0;
int complexTemplateNestingLevel = 0; //Уровень вложенности для сложных шаблонов ${}

%}

file			{ printf("Found keyword - FILE\n"); }
field			{ printf("Found keyword - FIELD\n"); }
property		{ printf("Found keyword - PROPERTY\n"); }
get				{ printf("Found keyword - GET\n"); }
set				{ printf("Found keyword - SET\n"); }
receiver		{ printf("Found keyword - RECEIVER\n"); }
param			{ printf("Found keyword - PARAM\n"); }
setparam		{ printf("Found keyword - SETPARAM\n"); }
delegate		{ printf("Found keyword - DELEGATE\n"); }
package			{ printf("Found keyword - PACKAGE\n"); }
import			{ printf("Found keyword - IMPORT\n"); }
class			{ printf("Found keyword - CLASS\n"); }
interface		{ printf("Found keyword - INTERFACE\n"); }
fun				{ printf("Found keyword - FUN\n"); }
object			{ printf("Found keyword - OBJECT\n"); }
val				{ printf("Found keyword - VAL\n"); }
var				{ printf("Found keyword - VAR\n"); }
typealias		{ printf("Found keyword - TYPE_ALIAS\n"); }
constructor		{ printf("Found keyword - CONSTRUCTOR\n"); }
by				{ printf("Found keyword - BY\n"); }
companion		{ printf("Found keyword - COMPANION\n"); }
init			{ printf("Found keyword - INIT\n"); }
this			{ printf("Found keyword - THIS\n"); }
super			{ printf("Found keyword - SUPER\n"); }
typeof			{ printf("Found keyword - TYPEOF\n"); }
where			{ printf("Found keyword - WHERE\n"); }
if				{ printf("Found keyword - IF\n"); }
else			{ printf("Found keyword - ELSE\n"); }
when			{ printf("Found keyword - WHEN\n"); }
try				{ printf("Found keyword - TRY\n"); }
catch			{ printf("Found keyword - CATCH\n"); }
finally			{ printf("Found keyword - FINALLY\n"); }
for				{ printf("Found keyword - FOR\n"); }
do				{ printf("Found keyword - DO\n"); }
while			{ printf("Found keyword - WHILE\n"); }
throw			{ printf("Found keyword - THROW\n"); }
return			{ printf("Found keyword - RETURN\n"); }
continue		{ printf("Found keyword - COUNTINUE\n"); }
break			{ printf("Found keyword - BREAK\n"); }
as				{ printf("Found keyword - AS\n"); }
is				{ printf("Found keyword - IS\n"); }
in				{ printf("Found keyword - IN\n"); }
out				{ printf("Found keyword - OUT\n"); }
dynamic			{ printf("Found keyword - DYNAMIC\n"); }
public			{ printf("Found keyword - PUBLIC\n"); }
private			{ printf("Found keyword - PRIVATE\n"); }
protected		{ printf("Found keyword - PROTECTED\n"); }
internal		{ printf("Found keyword - INTERNAL\n"); }
enum			{ printf("Found keyword - ENUM\n"); }
sealed			{ printf("Found keyword - SEALED\n"); }
annotation		{ printf("Found keyword - ANNOTATION\n"); }
data			{ printf("Found keyword - DATA\n"); }
inner			{ printf("Found keyword - INNER\n"); }
tailrec			{ printf("Found keyword - TAILREC\n"); }
operator		{ printf("Found keyword - OPERATOR\n"); }
inline			{ printf("Found keyword - INLINE\n"); }
infix			{ printf("Found keyword - INFIX\n"); }
external		{ printf("Found keyword - EXTERNAL\n"); }
suspend			{ printf("Found keyword - SUSPEND\n"); }
override		{ printf("Found keyword - OVERRIDE\n"); }
abstract		{ printf("Found keyword - ABSTRACT\n"); }
final			{ printf("Found keyword - FINAL\n"); }
open			{ printf("Found keyword - OPEN\n"); }
const			{ printf("Found keyword - CONST\n"); }
lateinit		{ printf("Found keyword - LATEINIT\n"); }
vararg			{ printf("Found keyword - VARARG\n"); }
noinline		{ printf("Found keyword - NOINLINE\n"); }
crossinline		{ printf("Found keyword - CROSSINLINE\n"); }
reified			{ printf("Found keyword - REIFIED\n"); }
expect			{ printf("Found keyword - EXPECT\n"); }
actual			{ printf("Found keyword - ACTUAL\n"); }

\.\.\.		{printf("Found operator - \.\.\. RESERVED");}
\.			{printf("Found operator - \. DOT");}
\,			{printf("Found operator - \, COMMA");}
\(			{printf("Found operator - \( LPAREN");}
\)			{printf("Found operator - \) RPAREN");}
\[			{printf("Found operator - \[ LSQUARE");}
\]			{printf("Found operator - \] RSQUARE");}
\{			{printf("Found operator - \{ LCURL");}
\}			{
                if (complexTemplateNestingLevel > 0) 
                {
                    printf("Found operator - + ADD\n");
                    str[0] = 0;
                    --complexTemplateNestingLevel;
                    BEGIN(STRING);
                }
                else 
                {
                    printf("Found operator - \} RCURL");                
                }                
            }
\*			{printf("Found operator - \* MULT");}
\%			{printf("Found operator - \% MOD");}
\/			{printf("Found operator - \\ DIV");}
\+			{printf("Found operator - \+ ADD");}
\-			{printf("Found operator - \- SUB");}
\+\+		{printf("Found operator - \+\+ INCR");}
\-\-		{printf("Found operator - \-\- DECR");}
\&\&		{printf("Found operator - \&\& CONJ");}
\|\|		{printf("Found operator - \|\| DISJ");}
\!			{printf("Found operator - \! EXCL");}
\:			{printf("Found operator - \: COLON");}
\;			{printf("Found operator - \; SEMICOLON");}
\=			{printf("Found operator - \= ASSIGNMENT");}
\+\=		{printf("Found operator - \+\= ADD_ASSIGNMENT");}
\-\=		{printf("Found operator - \-\= SUB_ASSIGNMENT");}
\*\=		{printf("Found operator - \*\= MULT_ASSIGNMENT");}
\/\=		{printf("Found operator - \/\= DIV_ASSIGNMENT");}
\%\=		{printf("Found operator - \%\= MOD_ASSIGNMENT");}
\-\>		{printf("Found operator - \-\> ARROW");}
\=\>		{printf("Found operator - \=\> DOUBLE_ARROW");}
\.\.		{printf("Found operator - \.\. RANGE");}
\:\:		{printf("Found operator - \:\: COLONCOLON");}
\;\;		{printf("Found operator - \;\; DOUBLE_SEMICOLONS");}
\#			{printf("Found operator - \# HASH");}
\@			{printf("Found operator - \@ AT_NO");}
\<			{printf("Found operator - \< LANGLE");}
\>			{printf("Found operator - \> RANGLE");}
\<\=		{printf("Found operator - \<\= LE");}
\>\=		{printf("Found operator - \>\= GE");}
\!\=		{printf("Found operator - \!\= EXCL_EQ");}
\!\=\=		{printf("Found operator - \!\=\= EXCL_EQEQ");}
as\?		{printf("Found operator - AS\? AS_SAFE");}
\=\=		{printf("Found operator - \=\= EQEQ");}
\=\=\=		{printf("Found operator - \=\=\= EQEQEQ");}
shl         {printf("Found operator - shl LSHIFT");}
shr         {printf("Found operator - shr RSHIFT");}
ushr        {printf("Found operator - ushr URSHIFT");}
and         {printf("Found operator - and AND");}
or          {printf("Found operator - or OR");}
xor         {printf("Found operator - xor XOR");}
inv         {printf("Found operator - inv INV");}

Int             {printf("Found datatype - INT");}
Float           {printf("Found datatype - FLOAT");}
Double          {printf("Found datatype - DOUBLE");}
Long            {printf("Found datatype - LONG");}
Short           {printf("Found datatype - SHORT");}
Byte            {printf("Found datatype - BYTE");}
String          {printf("Found datatype - STRING");}
Char            {printf("Found datatype - CHAR");}
Boolean         {printf("Found datatype - BOOLEAN");}
Array           {printf("Found datatype - ARRAY");}
IntArray        {printf("Found datatype - INTARRAY");}
FloatArray      {printf("Found datatype - FLOATARRAY");}
DoubleArray     {printf("Found datatype - DOUBLEARRAY");}
LongArray       {printf("Found datatype - LONGARRAY");}
ShortArray      {printf("Found datatype - SHORTARRAY");}
ByteArray       {printf("Found datatype - BYTEARRAY");}
BooleanArray    {printf("Found datatype - BOOLEANARRAY");}

                    
"//"				{   commentText[0] = 0; BEGIN(SLCOMMENT);}
<SLCOMMENT>[^\n]+	{   strcat(commentText, yytext);}
<SLCOMMENT>\n		{   printf("Found comment - %s\n", commentText);
					        BEGIN(INITIAL);}

"/*"				{	commentText[0] = 0; BEGIN(MLCOMMENT);}
<MLCOMMENT>[^*]+	{   strcat(commentText, yytext);}
<MLCOMMENT>\*+[^/]* {   strcat(commentText, yytext);}
<MLCOMMENT>\*+\/	{   
                        printf("Found comment - %s\n", commentText);
					    BEGIN(INITIAL); 
                    }
<MLCOMMENT><<EOF>>	{ printf("ERROR End of file found after \"%s\", but expected */", commentText); }


[1-9](_*{DIGIT})*|0       {  remove_all_inputs_of_symbol( yytext, tmp, '_');
                                numInt = atoi(tmp);
                                printf("Found decimal number - %d\n", numInt);
                             }

([1-9](_*{DIGIT})*|0)[lL]    {  remove_all_inputs_of_symbol( yytext, tmp, '_');
                                tmp[strlen(tmp)-1] = 0;
                                numLong = atol(tmp);
                                printf("Found decimal number - %ld\n", numLong);
                             }

([1-9](_*{DIGIT})*|0)_+|([1-9](_*{DIGIT})*|0)_*[lL]_+ {  printf("Illegal underscore", yytext);}


0[xX]{HEX_DIGIT}(_*{HEX_DIGIT})*    { remove_all_inputs_of_symbol( yytext + 2, tmp,'_');
                                      sscanf(tmp,"%x",&numInt);
                                      printf("Found hex number - %d\n", numInt);
                                    }
0[xX]{HEX_DIGIT}(_*{HEX_DIGIT})*_+  {  printf("Illegal underscore", yytext);}

(0|[1-9](_*{DIGIT})*)(\.{DIGIT}(_*{DIGIT})*)?([eE][+-]?[{DIGIT}](_*{DIGIT})*)? { 
                                    remove_all_inputs_of_symbol( yytext, tmp, '_'); 
                                    numDouble = atof(tmp);
                                    printf("Found decimal number - %.2f\n", numDouble);                                    
                                    }


(0|[1-9](_*{DIGIT})*)(\.{DIGIT}(_*{DIGIT})*)?([eE][+-]?[{DIGIT}](_*{DIGIT})*)?[fF] { 
                                    remove_all_inputs_of_symbol( yytext, tmp, '_'); 
                                    tmp[strlen(tmp)-1] = 0;
                                    numFloat = (float)atof(tmp);
                                    printf("Found decimal number - %.2f\n", numFloat);
}

0[bB]{BIN_DIGIT}(_*{BIN_DIGIT})*    { remove_all_inputs_of_symbol( yytext + 2, tmp, '_');
                                      tmp = strchr(tmp, 1);
                                      numInt = bin_from_str_to_dec(tmp);
                                      printf("Found binary number - %d\n", numInt); 
                                    }
0[bB]{BIN_DIGIT}(_*{BIN_DIGIT})*_+  {  printf("Illegal underscore", yytext);}

true { printf("Found boolean literal - TRUE"); }
false { printf("Found boolean literal - FALSE"); }

\'\'                    { printf("ERROR! Found empty character literal\n"); }
\'                      { tmpChar = 0 ; BEGIN(CHAR); }
<CHAR>[^\n\\\']         { tmpChar = yytext[0]; }
<CHAR>\\u{HEX_DIGIT}{4} {; // Преобразовать юникод строку в юникод символ
                        } 
<CHAR>\\t               { tmpChar = '\t'; }
<CHAR>\\b               { tmpChar = '\b'; }
<CHAR>\\r               { tmpChar = '\r'; }
<CHAR>\\n               { tmpChar = '\n'; }
<CHAR>\\\'              { tmpChar = '\''; }
<CHAR>\\\"              { tmpChar = '\"'; }
<CHAR>\\\\              { tmpChar = '\\'; }
<CHAR>\\\$              { tmpChar = '\$'; }
<CHAR>\'                { 
                            printf("Found char literal - %c\n", tmpChar);
                            BEGIN(INITIAL);
                        }
<CHAR>\n                { printf("ERROR New line found, but expected \'"); }
<CHAR><<EOF>>           { printf("ERROR End of file found, but expected \'"); }

<CHAR,STRING>\\([^utbrn'"\\$]|(u({HEX_DIGIT}{5,}|{HEX_DIGIT}{0,3}))) { 
                          printf("ERROR! Found illegal escape %s\n", yytext); 
                        }
<CHAR>..+               { printf("ERROR! Too many symbols in character literal %s\n", yytext); }

\"                  {   
                        str[0] = 0;
                        BEGIN(STRING);
                    }
<STRING>[^\\\"\n$]+  { strcat(str, yytext); }
<STRING>\\n         { strcat(str, "\n"); }
<STRING>\\\\        { strcat(str, "\\"); }
<STRING>\\\"        { strcat(str, "\""); }
<STRING>\\t         { strcat(str, "\t"); }
<STRING>\\b         { strcat(str, "\b"); }
<STRING>\\r         { strcat(str, "\r"); }
<STRING>\\$         { strcat(str, "\$"); }
<STRING>\\\'        { strcat(str, "\'"); }
<STRING>\"          { 
                        printf("Found string literal %s\n", str);
                        BEGIN(INITIAL);
                    }
<STRING>\n          { printf("ERROR New line found after \"%s\", but \" expected", str); }
<STRING><<EOF>>     { printf("ERROR End of file found after \"%s\", but \" expected", str); }
<STRING>\\\n        {;//Делать ничего не нужно
                    }
<STRING,MLSTRING>\$[a-zA-Z_]\w*  {
                                    if (!isNotKeyword(yytext + 1))
                                    {
                                        printf("ERROR! Found keyword, but expected identificator\n", yytext + 1);
                                    }
                                    else 
                                    {
                                        printf("Found string literal %s\n", str);
                                        printf("Found operator - \+ ADD\n");
                                        printf("Found identificator - %s\n", yytext + 1);
                                        printf("Found operator - \+ ADD\n");
                                        str[0] = 0;
                                    }                            
                                }

<STRING,MLSTRING>\$`[^\n\\`\[\]]+` {
                               printf("Found string literal %s\n", str);
                               printf("Found operator - \+ ADD\n");
                               str[0] = 0;
                               strcpy(str, yytext + 2);
                               str[yyleng - 2 - 1] = 0;
                               printf("Found identificator - %s\n", str);
                               printf("Found operator - \+ ADD\n");
                               str[0] = 0;                            
                          }

<STRING,MLSTRING>\$`[^`\n]*[\\\[\]][^`\n]*` { printf("ERROR! Found invalid identificator in template %s\n", yytext); }

<STRING,MLSTRING>\$\{          {
                                    printf("Found string literal %s\n", str);
                                    printf("Found operator - \+ ADD\n");
                                    ++complexTemplateNestingLevel;
                                    BEGIN(INITIAL);
                                }
<STRING,MLSTRING>\$\{\}      { printf("ERROR! Found empty complex template"); }

\"\"\"              {
                        str[0] = 0;
                        BEGIN(MLSTRING);
                    }
<MLSTRING>[^$"]+    { strcat(str, yytext); }
<MLSTRING>\"{1,2}   { strcat(str, yytext); }
<MLSTRING>\"{3,}    {
                        strcat(str, yytext);
                        str[strlen(str - 3)] = 0;
                        printf("Found multi line string literal %s\n", str);
                    }
<MLSTRING><<EOF>>   { printf("ERROR! Found end of file, but expected \"\"\""); }


\n { printf("Found new line"); }

[a-zA-Z_]\w* { printf("Found identificator - %s\n", yytext); }

``                              { printf("ERROR! Found empty identificator name\n"); }
"`"                             {
                                    str[0] = 0;
                                    BEGIN(IDENTIFICATOR);
                                }
<IDENTIFICATOR>[^\n\\`\[\]]+    { strcat(str, yytext); }
<IDENTIFICATOR>\n               { printf("ERROR! In string %s expected `\n", str); }
<IDENTIFICATOR>[\\\[\]]         { printf("ERROR! There is an illegal character %s In string %s \n", yytext, str); }
<IDENTIFICATOR><<EOF>>               { printf("ERROR! In string %s expected `\n", str); }
<IDENTIFICATOR>`                {
                                    printf("Found identificator - %s\n", str);
                                    BEGIN(INITIAL);
                                }

<<EOF>> {
            if (complexTemplateNestingLevel > 0) 
            {
                printf("ERROR! Found end of file, but expected }");
            }
            else 
            {
                printf("Found end of file");
            }
        }

%%

bool isNotKeyword(const char* str)
{
    bool result = strcmp(str, "file") && strcmp(str, "field") && strcmp(str, "property") &&
                  strcmp(str, "get") && strcmp(str, "set") && strcmp(str, "receiver") &&
                  strcmp(str, "param") && strcmp(str, "setparam") && strcmp(str, "delegate") &&
                  strcmp(str, "package") && strcmp(str, "import") && strcmp(str, "class") &&
                  strcmp(str, "interface") && strcmp(str, "fun") && strcmp(str, "object") &&
                  strcmp(str, "val") && strcmp(str, "var") && strcmp(str, "typealias") &&
                  strcmp(str, "constructor") && strcmp(str, "by") && strcmp(str, "companion") &&
                  strcmp(str, "init") && strcmp(str, "this") && strcmp(str, "super") &&
                  strcmp(str, "typeof") && strcmp(str, "where") && strcmp(str, "if") &&
                  strcmp(str, "else") && strcmp(str, "when") && strcmp(str, "try") &&
                  strcmp(str, "catch") && strcmp(str, "finally") && strcmp(str, "for") &&
                  strcmp(str, "do") && strcmp(str, "while") && strcmp(str, "throw") &&
                  strcmp(str, "return") && strcmp(str, "continue") && strcmp(str, "break") &&
                  strcmp(str, "as") && strcmp(str, "is") && strcmp(str, "in") &&
                  strcmp(str, "out") && strcmp(str, "dynamic") && strcmp(str, "public") &&
                  strcmp(str, "private") && strcmp(str, "protected") && strcmp(str, "internal") &&
                  strcmp(str, "enum") && strcmp(str, "sealed") && strcmp(str, "annotation") &&
                  strcmp(str, "data") && strcmp(str, "inner") && strcmp(str, "tailrec") &&
                  strcmp(str, "operator") && strcmp(str, "inline") && strcmp(str, "infix") &&
                  strcmp(str, "external") && strcmp(str, "suspend") && strcmp(str, "override") &&
                  strcmp(str, "abstract") && strcmp(str, "final") && strcmp(str, "open") &&
                  strcmp(str, "const") && strcmp(str, "lateinit") && strcmp(str, "vararg") &&
                  strcmp(str, "noinline") && strcmp(str, "crossinline") && strcmp(str, "reified") &&
                  strcmp(str, "expect") && strcmp(str, "actual");
    return result;
}

void remove_all_inputs_of_symbol(const char * str, char * result, char deleted_symbol) {
	int j = 0;	
    for(int i = 0; str[i] != 0; i++) {
        if(str[i] != deleted_symbol) {
            result[j++] = str[i];
        }
    }
    result[j] = 0;
}

int bin_from_str_to_dec(const char * str) {
    int value=0;
    for(int i=0; str[i]!=0; i++){
        value<<=1;
        value+=str[i]-'0';
    }
    return value;
}

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yylex();
    return;
}
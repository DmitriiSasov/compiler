%option noyywrap
%option never-interactive
%option yylineno

%{
    #include <stdio.h>
    void remove_all_inputs_of_symbol(const char * str, char * result, char deleted_symbol);
    int bin_from_str_to_dec(const char * str);
%}

%x MLCOMMENT SLCOMMENT STRING CHAR
DIGIT             [0-9]
HEX_DIGIT         [0-9A-Fa-f]
BIN_DIGIT         [01]

%%
%{ 	int numInt;
long numLong;
float numFloat;
double numDouble'
char commentText[1000];
char str[1000];
char tmpChar
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
\}			{printf("Found operator - \} RCURL");}
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

                    
"//"				{   commmentText[0] = 0; BEGIN(SLCOMMENT);}
<SLCOMMENT>[^\n]+	{   strcat(commentText, yytext);}
<SLCOMMENT>\n		{   printf("Found comment - %s\n", commentText);
					        BEGIN(INITIAL);}

"/*"				{	commentText[0] = 0; BEGIN(MLCOMMENT);}
<MLCOMMENT>[^*]+	{   strcat(commentText, yytext);}
<MLCOMMENT>\*+[^/]* {   strcat(commentText, yytext);}
<MLCOMMENT>\*+\/	{   printf("Found comment - %s\n", commentText);
					        BEGIN(INITIAL); }

([1-9](_?{DIGIT})*|0)L?      {  remove_all_inputs_of_symbol( yytext, tmp, '_');
                                if( tmp[strlen(tmp)-1] == 'L' || tmp[strlen(tmp)-1] == 'l'){
                                    tmp[strlen(tmp)-1] = 0;
                                    numLong = atol(tmp);
                                    printf("Found decimal number - %ld\n", numLong);
                                } else {
                                    numInt = atoi(tmp);
                                    printf("Found decimal number - %d\n", numInt);
                                }
                             }

0[xX]{HEX_DIGIT}(_?{HEX_DIGIT})*    { remove_all_inputs_of_symbol( yytext + 2, tmp,'_');
                                      sscanf(tmp,"%x",&numInt);
                                      printf("Found hex number - %d\n", numInt);
                                    }


(0|[1-9](_?{DIGIT})*)(\.{DIGIT}(_?{DIGIT})*)?([eE][+-]?[{DIGIT}](_?{DIGIT})*)?[fF]? { 
                                    remove_all_inputs_of_symbol( yytext, tmp, '_'); 
                                    if( tmp[strlen(tmp)-1] == 'F' || tmp[strlen(tmp)-1] == 'f'){
                                        tmp[strlen(tmp)-1] = 0;
                                        numFloat = (float)atof(tmp);
                                        printf("Found decimal number - %.2f\n", numFloat);
                                    } else {
                                        numDouble = atof(tmp);
                                        printf("Found decimal number - %.2f\n", numDouble);
                                    }
}

0[bB]{BIN_DIGIT}(_?{BIN_DIGIT})*    { remove_all_inputs_of_symbol( yytext + 2, tmp, '_');
                                      tmp = strchr(tmp, 1);
                                      numInt = bin_from_str_to_dec(tmp);
                                      printf("Found binary number - %d\n", numInt); 
                                    }

true { printf("Found boolean literal - TRUE");
false { printf("Found boolean literal - FALSE");

      \'                { tmpChar[0] = 0 ; BEGIN(CHAR); }
<CHAR>[^\n\\]           { tmpChar = yytext[0]; }
<CHAR>\\u{HEX_DIGIT}{4} { // Преобразовать юникод строку в юникод символ}
<CHAR>\\t               { tmpChar = '\t'; }
<CHAR>\\b               { tmpChar = '\b'; }
<CHAR>\\r               { tmpChar = '\r'; }
<CHAR>\\n               { tmpChar = '\n'; }
<CHAR>\\\'              { tmpChar = '\''; }
<CHAR>\\\"              { tmpChar = '\"'; }
<CHAR>\\\\              { tmpChar = '\\'; }
<CHAR>\\\$              { tmpChar = '\$'; }
<CHAR>\'                { printf("Found char literal - %c\n", tmpChar);
                            BEGIN(INITIAL}

[a-zA-Z_]\w* { printf("Found identificator - %s\n", yytext)}



%%

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
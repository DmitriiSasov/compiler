%option noyywrap
%option never-interactive
%option yylineno

%{
    #include <stdio.h>
    void remove_all_inputs_of_symbol(const char * str, char * result, char deleted_symbol);
    int bin_from_str_to_dec(const char * str);
    void reportAboutErrorInSimpleTemplate(bool* isSimpleTemplate, const char* str);
%}

%x MLCOMMENT SLCOMMENT STRING CHAR IDENTIFICATOR
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
bool isSimpleTemplate = false; //Относится ли текущая часть строки к простому шаблону $varname
int complexTemplateNestingLevel = 0; //Уровень вложенности для сложных шаблонов ${}

%}

file			{ 
                  printf("Found keyword - FILE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword file cannot be used as an identifier");
                }
field			{  
                  printf("Found keyword - FIELD\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword field cannot be used as an identifier");
                }
property		{  
                  printf("Found keyword - PROPERTY\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword property cannot be used as an identifier");
                }
get				{ 
                  printf("Found keyword - GET\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword get cannot be used as an identifier");
                }
set				{  
                  printf("Found keyword - SET\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword set cannot be used as an identifier");
                }
receiver		{  
                  printf("Found keyword - RECEIVER\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword receiver cannot be used as an identifier");
                }
param			{  
                  printf("Found keyword - PARAM\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword param cannot be used as an identifier");
                }
setparam		{  
                  printf("Found keyword - SETPARAM\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword setparam cannot be used as an identifier");
                }
delegate		{  
                  printf("Found keyword - DELEGATE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword delegate cannot be used as an identifier");
                }
package			{  
                  printf("Found keyword - PACKAGE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword package cannot be used as an identifier");
                }
import			{  
                  printf("Found keyword - IMPORT\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword import cannot be used as an identifier");
                }
class			{  
                  printf("Found keyword - CLASS\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword class cannot be used as an identifier");
                }
interface		{ 
                  printf("Found keyword - INTERFACE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword interface cannot be used as an identifier");
                }
fun				{  
                  printf("Found keyword - FUN\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword fun cannot be used as an identifier");
                }
object			{  
                  printf("Found keyword - OBJECT\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword object cannot be used as an identifier");
                }
val				{  
                  printf("Found keyword - VAL\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword val cannot be used as an identifier");
                }
var				{  
                  printf("Found keyword - VAR\n");
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword var cannot be used as an identifier");
                }
typealias		{  
                  printf("Found keyword - TYPE_ALIAS\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword typealias cannot be used as an identifier");
                }
constructor		{  
                  printf("Found keyword - CONSTRUCTOR\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword constructor cannot be used as an identifier");
                }
by				{  
                  printf("Found keyword - BY\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword by cannot be used as an identifier");
                }
companion		{  
                  printf("Found keyword - COMPANION\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword companion cannot be used as an identifier");
                }
init			{  
                  printf("Found keyword - INIT\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword init cannot be used as an identifier");
                }
this			{  
                  printf("Found keyword - THIS\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword this cannot be used as an identifier");
                }
super			{  
                  printf("Found keyword - SUPER\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword super cannot be used as an identifier");
                }
typeof			{  
                  printf("Found keyword - TYPEOF\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword typeof cannot be used as an identifier");
                }
where			{  
                  printf("Found keyword - WHERE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword where cannot be used as an identifier");
                }
if				{  
                  printf("Found keyword - IF\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword if cannot be used as an identifier");
                }
else			{  
                  printf("Found keyword - ELSE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword else cannot be used as an identifier");
                }
when			{  
                  printf("Found keyword - WHEN\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword when cannot be used as an identifier");
                }
try				{  
                  printf("Found keyword - TRY\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword try cannot be used as an identifier");
                }
catch			{  
                  printf("Found keyword - CATCH\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword catch cannot be used as an identifier");
                }
finally			{  
                  printf("Found keyword - FINALLY\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword finally cannot be used as an identifier");
                }
for				{  
                  printf("Found keyword - FOR\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword for cannot be used as an identifier");
                }
do				{  
                  printf("Found keyword - DO\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword do cannot be used as an identifier");
                }
while			{  
                  printf("Found keyword - WHILE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword while cannot be used as an identifier");
                }
throw			{  
                  printf("Found keyword - THROW\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword throw cannot be used as an identifier");
                }
return			{  
                  printf("Found keyword - RETURN\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword return cannot be used as an identifier");
                }
continue		{  
                  printf("Found keyword - COUNTINUE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword continue cannot be used as an identifier");
                }
break			{  
                  printf("Found keyword - BREAK\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword break cannot be used as an identifier");
                }
as				{  
                  printf("Found keyword - AS\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword as cannot be used as an identifier");
                }
is				{  
                  printf("Found keyword - IS\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword is cannot be used as an identifier");
                }
in				{  
                  printf("Found keyword - IN\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword in cannot be used as an identifier");
                }
out				{  
                  printf("Found keyword - OUT\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword out cannot be used as an identifier");
                }
dynamic			{  
                  printf("Found keyword - DYNAMIC\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword dynamic cannot be used as an identifier");
                }
public			{  
                  printf("Found keyword - PUBLIC\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword public cannot be used as an identifier");
                }
private			{  
                  printf("Found keyword - PRIVATE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword private cannot be used as an identifier");
                }
protected		{  
                  printf("Found keyword - PROTECTED\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword protected cannot be used as an identifier");
                }
internal		{  
                  printf("Found keyword - INTERNAL\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword internal cannot be used as an identifier");
                }
enum			{  
                  printf("Found keyword - ENUM\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword enum cannot be used as an identifier");
                }
sealed			{  
                  printf("Found keyword - SEALED\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword sealed cannot be used as an identifier");
                }
annotation		{  
                  printf("Found keyword - ANNOTATION\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword annotation cannot be used as an identifier");
                }
data			{  
                  printf("Found keyword - DATA\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword data cannot be used as an identifier");
                }
inner			{  
                  printf("Found keyword - INNER\n");
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword inner cannot be used as an identifier");
                }
tailrec			{  
                  printf("Found keyword - TAILREC\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword tailrec cannot be used as an identifier");
                }
operator		{  
                  printf("Found keyword - OPERATOR\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword operator cannot be used as an identifier");
                }
inline			{  
                  printf("Found keyword - INLINE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword inline cannot be used as an identifier");
                }
infix			{  
                  printf("Found keyword - INFIX\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword infix cannot be used as an identifier");
                }
external		{  
                  printf("Found keyword - EXTERNAL\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword external cannot be used as an identifier");
                }
suspend			{  
                  printf("Found keyword - SUSPEND\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword suspend cannot be used as an identifier");
                }
override		{  
                  printf("Found keyword - OVERRIDE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword override cannot be used as an identifier");
                }
abstract		{  
                  printf("Found keyword - ABSTRACT\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword abstract cannot be used as an identifier");
                }
final			{  
                  printf("Found keyword - FINAL\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword final cannot be used as an identifier");
                }
open			{  
                  printf("Found keyword - OPEN\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword open cannot be used as an identifier");
                }
const			{  
                  printf("Found keyword - CONST\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword const cannot be used as an identifier");
                }
lateinit		{  
                  printf("Found keyword - LATEINIT\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword lateinit cannot be used as an identifier");
                }
vararg			{  
                  printf("Found keyword - VARARG\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword vararg cannot be used as an identifier");
                }
noinline		{  
                  printf("Found keyword - NOINLINE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword noinline cannot be used as an identifier");
                }
crossinline		{  
                  printf("Found keyword - CROSSINLINE\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword crossinline cannot be used as an identifier");
                }
reified			{  
                  printf("Found keyword - REIFIED\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword reified cannot be used as an identifier");
                }
expect			{ 
                  printf("Found keyword - EXPECT\n");
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword expect cannot be used as an identifier");
                }
actual			{  
                  printf("Found keyword - ACTUAL\n"); 
                  reportAboutErrorInSimpleTemplate(&isSimpleTemplate, 
                  "Keyword actual cannot be used as an identifier");
                }

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

      \'              { tmpChar = 0 ; BEGIN(CHAR); }
<CHAR>[^\n\\]           { tmpChar = yytext[0]; }
<CHAR>\\u{HEX_DIGIT}{4} { // Преобразовать юникод строку в юникод символ
                        }
<CHAR>\\t               { tmpChar = '\t'; }
<CHAR>\\b               { tmpChar = '\b'; }
<CHAR>\\r               { tmpChar = '\r'; }
<CHAR>\\n               { tmpChar = '\n'; }
<CHAR>\\\'              { tmpChar = '\''; }
<CHAR>\\\"              { tmpChar = '\"'; }
<CHAR>\\\\              { tmpChar = '\\'; }
<CHAR>\\\$              { tmpChar = '\$'; }
<CHAR>\'                { printf("Found char literal - %c\n", tmpChar);
                            BEGIN(INITIAL);}
<STRING>\n              { printf("ERROR New line found, but expected \'"); }
<STRING><<EOF>>         { printf("ERROR End of file found, but expected \'"); }

\"                  {   
                        str[0] = 0;
                        BEGIN(STRING);
                    }
<STRING>[^\\\"\n]+  { strcat(str, yytext); }
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
<STRING>\$[a-zA-Z_] {
                            printf("Found string literal %s\n", str);
                            printf("Found operator - \+ ADD\n");
                            unput(yytext[1]);
                            isSimpleTemplate = true;
                            BEGIN(INITIAL);                            
                    }

<STRING>\$\{        {
                        printf("Found string literal %s\n", str);
                        printf("Found operator - \+ ADD\n");
                        ++complexTemplateNestingLevel;
                        BEGIN(INITIAL);
                    }
<STRING>\$\{\}      { printf("ERROR! Found empty complex template"); }

\n { printf("Found new line"); }

[a-zA-Z_]\w* { printf("Found identificator - %s\n", yytext);
               if (isSimpleTemplate) 
               {
                    printf("Found operator - + ADD\n");
                    str[0] = 0;
                    isSimpleTemplate = false;
                    BEGIN(STRING);                    
               } 
             }

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

void reportAboutErrorInSimpleTemplate(bool* isSimpleTemplate, const char* str)
{
    if (*isSimpleTemplate)
    {
        printf(str);
        *isSimpleTemplate = false;
    }
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
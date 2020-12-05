%option noyywrap
%option never-interactive
%option yylineno

%{
    #include <stdio.h>
    #include "synt_analyzer.tab.h"
    void remove_all_inputs_of_symbol(const char * str, char * result, char deleted_symbol);
    int bin_from_str_to_dec(const char * str);
    bool isNotKeyword(const char* str);
%}

%x MLCOMMENT SLCOMMENT STRING CHAR IDENTIFICATOR MLSTRING
DIGIT             [0-9]
HEX_DIGIT         [0-9A-Fa-f]
BIN_DIGIT         [01]

%%
%{ 	
int numInt;
long numLong;
float numFloat;
double numDouble;
char commentText[1000];
char str[1000];
char tmpChar;
char * tmp = 0;
char forNum[100];
static int complexTemplateNestingLevel = 0; //Уровень вложенности для сложных шаблонов ${}
static bool isMLString = false;    //Встретилась ли интерполяция в многострочной строковой константе

%}

field			{ return FIELD; }
property		{ return PROPERTY; }
get				{ return GET; }
set				{ return SET; }
receiver		{ return RECEIVER;}
param			{ return PARAM;}
setparam		{ return SETPARAM;}
delegate		{ return DELEGATE;}
class			{ return CLASS;}
interface		{ return INTERFACE;}
fun				{ return FUN;}
object			{ return OBJECT;}
val				{ return VAL; }
var				{ return VAR;}
constructor		{ return CONSTRUCTOR;}
by				{ return BY;}
companion		{ return COMPANION;}
init			{ return INIT;}
this			{ return THIS;}
super			{ return SUPER;}
typeof			{ return TYPEOF;}
where			{ return WHERE;}
if				{ return IF;}
else			{ return ELSE;}
when			{ return WHEN;}
for				{ return FOR;}
do				{ return DO;}
while			{ return WHILE;}
return			{ return RETURN;}
continue		{ return CONTINUE;}
break			{ return BREAK;}
as				{ return AS;}
in				{ return IN;}
out				{ return OUT;}
dynamic			{ return DYNAMIC;}
public			{ return PUBLIC;}
private			{ return PRIVATE;}
protected		{ return PROTECTED;}
internal		{ return INTERNAL;}
enum			{ return ENUM;}
sealed			{ return SEALED;}
annotation		{ return ANNOTATION;}
data			{ return DATA;}
inner			{ return INNER;}
tailrec			{ return TAILREC;}
operator		{ return OPERATOR;}
inline			{ return INLINE;}
infix			{ return INFIX;}
external		{ return EXTERNAL;}
suspend			{ return SUSPEND;}
override		{ return OVERRIDE;}
abstract		{ return ABSTRACT;}
final			{ return FINAL;}
open			{ return OPEN;}
const			{ return CONST;}
lateinit		{ return LATEINIT;}
vararg			{ return VARARG;}
noinline		{ return NOINLINE;}
crossinline		{ return CROSSINLINE;}
reified			{ return REIFIED;}
expect			{ return EXPECT;}
actual			{ return ACTUAL;}

\.			{return '.';}
\,			{return ',';}
\(			{return '(';}
\)			{return ')';}
\[			{return '[';}
\]			{return ']';}
\{			{return '{';}
\}			{
                if (complexTemplateNestingLevel > 0) 
                {
                    printf("Found operator - + ADD\n");
                    str[0] = 0;
                    --complexTemplateNestingLevel;
                    if (isMLString)
                    {
                        isMLString = false;
                        BEGIN(MLSTRING);
                    }
                    else 
                    {
                        BEGIN(STRING);
                    }
                    return '+';
                }
                else 
                {
				return '}';                
                }                
            }
\*			{return '*';}
\%			{return '%';}
\/			{return '/';}
\+			{return '+';}
\-			{return '-';}
\&\&		{return AND;}
\|\|		{return OR;}
\!			{return '!';}
\:			{return ':';}
\;			{return ';';}
\=			{return '=';}
\+\=		{return ASUM;}
\-\=		{return ASUB;}
\*\=		{return AMUL;}
\/\=		{return ADIV;}
\%\=		{return AMOD;}
\.\.		{return RANGE;}
\;\;		{printf("ERROR! Found %s", yytext);}
\#			{return '#';}
\@			{return '@';}
\<			{return '<';}
\>			{return '>';}
\<\=		{return LOEQ;}
\>\=		{return MOEQ;}
\!\=		{return NEQ;}
\=\=		{return EQ;}
                    
"//"				{   commentText[0] = 0; BEGIN(SLCOMMENT);}
<SLCOMMENT>[^\n]+	{   strcat(commentText, yytext);}
<SLCOMMENT>\n		{   printf("Found comment - \"%s\"\n", commentText);
					        BEGIN(INITIAL);}

"/*"				{	commentText[0] = 0; BEGIN(MLCOMMENT);}
<MLCOMMENT>[^*]+	{   strcat(commentText, yytext);}
<MLCOMMENT>\*+[^/]* {   strcat(commentText, yytext);}
<MLCOMMENT>\*+\/	{   
                        printf("Found comment - \"%s\"\n", commentText);
					    BEGIN(INITIAL); 
                    }
<MLCOMMENT><<EOF>>	{ printf("ERROR! End of file found after \"%s\", but expected */\n", commentText); }




([1-9](_*{DIGIT})*|0)[fF]           { remove_all_inputs_of_symbol( yytext, forNum, '_'); 
                                      forNum[strlen(forNum)-1] = 0;
                                      yylval.Float_v = (float)atof(forNum);
                                      return FLOAT;
                                    }
([1-9](_*{DIGIT})*|0)(\.|[Ee][+-]?){DIGIT}(_*{DIGIT})* {
                                      remove_all_inputs_of_symbol( yytext, forNum, '_'); 
                                      yylval.Double_v = atof(forNum);
                                      return DOUBLE;  
                                    }

([1-9](_*{DIGIT})*|0)(\.|[eE][+-]?){DIGIT}(_*{DIGIT})*[fF] {
                                      remove_all_inputs_of_symbol( yytext, forNum, '_'); 
                                      forNum[strlen(forNum)-1] = 0;
                                      yylval.Float_v = (float)atof(forNum);
                                      return FLOAT;
                                    }

([1-9](_*{DIGIT})*|0)\.{DIGIT}(_*{DIGIT})*[eE][+-]?{DIGIT}(_*{DIGIT})* {
                                      remove_all_inputs_of_symbol( yytext, forNum, '_'); 
                                      yylval.Double_v = atof(forNum);
                                      return DOUBLE;  
                                    }

([1-9](_*{DIGIT})*|0)\.{DIGIT}(_*{DIGIT})*[eE][+-]?{DIGIT}(_*{DIGIT})*[fF] {
                                      remove_all_inputs_of_symbol( yytext, forNum, '_'); 
                                      forNum[strlen(forNum)-1] = 0;
                                      yylval.Double_v = atof(forNum);
                                      return DOUBLE;  
                                    }


[1-9](_*{DIGIT})*|0                 { remove_all_inputs_of_symbol( yytext, forNum, '_');
                                      yylval.Int_v = atoi(forNum);
                                      return INT;
                                    }

([1-9](_*{DIGIT})*|0)L              { remove_all_inputs_of_symbol( yytext, forNum, '_');
                                      forNum[strlen(forNum)-1] = 0;
                                      numLong = atol(forNum);
                                      printf("Found decimal number - %ld\n", numLong);
                                    }


0[xX]{HEX_DIGIT}(_*{HEX_DIGIT})*    { remove_all_inputs_of_symbol( yytext + 2, forNum,'_');
                                      sscanf(forNum,"%x",&numInt);
                                      yylval.Int_v = numInt;
                                      return INT;
                                    }
                                    

0[bB]{BIN_DIGIT}(_*{BIN_DIGIT})*    { remove_all_inputs_of_symbol( yytext + 2, forNum, '_');
                                      tmp = forNum;
                                      yylval.Int_v = bin_from_str_to_dec(tmp);
                                      return INT; 
                                    }


([1-9](_*{DIGIT})*|0)_+             {  printf("ERROR! Illegal underscore\"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*[LfF]_+      {  printf("ERROR! Illegal underscore\"%s\"\n", yytext);}

0[xX]{HEX_DIGIT}(_*{HEX_DIGIT})*_+  {  printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
0[bB]{BIN_DIGIT}(_*{BIN_DIGIT})*_+  {  printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
0[xX]_+({HEX_DIGIT}*_*)*            {  printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
0[bB]_+({BIN_DIGIT}*_*)*            {  printf("ERROR! Illegal underscore \"%s\"\n", yytext);}

([1-9](_*{DIGIT})*|0)_+(\._*|[Ee]_*[+-]?_*){DIGIT}(_*{DIGIT})*_*       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*(\._+|[Ee]_+[+-]?_*){DIGIT}(_*{DIGIT})*_*       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*(\._+|[Ee]_*[+-]_+){DIGIT}(_*{DIGIT})*_*        { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*(\._*|[Ee]_*[+-]?_*){DIGIT}(_*{DIGIT})*_+       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*(\._*|[Ee]_*[+-]?_*){DIGIT}(_*{DIGIT})*_*[fF]_+ { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}

([1-9](_*{DIGIT})*|0)_+\._*{DIGIT}(_*{DIGIT})*_*[eE]_*[+-]?_*{DIGIT}(_*{DIGIT})*_*       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*\._+{DIGIT}(_*{DIGIT})*_*[eE]_*[+-]?_*{DIGIT}(_*{DIGIT})*_*       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*\._*{DIGIT}(_*{DIGIT})*_+[eE]_*[+-]?_*{DIGIT}(_*{DIGIT})*_*       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*\._*{DIGIT}(_*{DIGIT})*_*[eE]_+[+-]?_*{DIGIT}(_*{DIGIT})*_*       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*\._*{DIGIT}(_*{DIGIT})*_*[eE]_*[+-]_+{DIGIT}(_*{DIGIT})*_*        { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_*\._*{DIGIT}(_*{DIGIT})*_*[eE]_*[+-]?_*{DIGIT}(_*{DIGIT})*_+       { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}
([1-9](_*{DIGIT})*|0)_+\._*{DIGIT}(_*{DIGIT})*_*[eE]_*[+-]?_*{DIGIT}(_*{DIGIT})*_*[fF]_+ { printf("ERROR! Illegal underscore \"%s\"\n", yytext);}

{DIGIT}+[eE][+-]?                    {  printf("ERROR! The value is out of range \"%s\"\n", yytext);}
{DIGIT}[0-9_]*[a-zA-Z][0-9a-zA-Z_]*  {  printf("ERROR! Unresolved reference \"%s\"\n", yytext);}                               


true 	{	yylval.Bool_v = true;
			return BOOLEAN;
		}
false 	{	yylval.Bool_v = false;
			return BOOLEAN;
		}

\'\'                    { printf("ERROR! Found empty character literal\n"); }
\'                      { tmpChar = 0 ; BEGIN(CHAR); }
<CHAR>[^\n\\\']         { tmpChar = yytext[0]; }
<CHAR,STRING>\\u{HEX_DIGIT}{4} {; // Преобразовать юникод строку в юникод символ
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
                            yylval.Char_v = tmpChar;
                            BEGIN(INITIAL);
							return CHAR;
                        }
<CHAR>\n                { printf("ERROR! New line found, but expected \'\n"); }
<CHAR><<EOF>>           { printf("ERROR! End of file found, but expected \'\n"); }

<CHAR>\\([^utbrn'"\\$]|(u({HEX_DIGIT}{5,}|{HEX_DIGIT}{0,3}))) { 
                          printf("ERROR! Found illegal escape \'%s\'\n", yytext); 
                        }
<CHAR>[^'\n][^'\n]+          { printf("ERROR! Too many symbols in character literal \'%s\'\n", yytext); }

\"                  {   
                        str[0] = 0;
                        BEGIN(STRING);
                    }
<STRING>[^\\\"\n$]+ { strcat(str, yytext); }
<STRING>\\n         { strcat(str, "\n"); }
<STRING>\\\\        { strcat(str, "\\"); }
<STRING>\\\"        { strcat(str, "\""); }
<STRING>\\t         { strcat(str, "\t"); }
<STRING>\\b         { strcat(str, "\b"); }
<STRING>\\r         { strcat(str, "\r"); }
<STRING>\\$         { strcat(str, "\$"); }
<STRING>\\\'        { strcat(str, "\'"); }
<STRING>\"          { 
                        yylval.String_v = str;
                        BEGIN(INITIAL);
						return STRING;
                    }
<STRING>\\([^utbrn'"\\$]|(u{HEX_DIGIT}{0,3})) { printf("ERROR! Found illegal escape \"%s\"\n", yytext); }
<STRING>\n          { printf("ERROR! New line found after \"%s\", but \" expected\n", str); }
<STRING><<EOF>>     { printf("ERROR! End of file found after \"%s\", but \" expected\n", str); }
<STRING>\\\n        {;//Делать ничего не нужно
                    }
<STRING>\$[a-zA-Z_][a-zA-Z_0-9]*  {
                            if (!isNotKeyword(yytext + 1))
                            {
                                printf("ERROR! Found keyword \"%s\", but expected identificator\n", yytext + 1);
                            }
                            else 
                            {
                                printf("Found string literal \"%s\"\n", str);
                                printf("Found operator - \+ ADD\n");
                                printf("Found identificator - \"%s\"\n", yytext + 1);
                                printf("Found operator - \+ ADD\n");
                                str[0] = 0;
                            }                            
                        }

<STRING>\$`[^\n\\`\[\]]+` {
                               printf("Found string literal \"%s\"\n", str);
                               printf("Found operator - \+ ADD\n");
                               str[0] = 0;
                               strcpy(str, yytext + 2);
                               str[yyleng - 2 - 1] = 0;
                               printf("Found identificator - \"%s\"\n", str);
                               printf("Found operator - \+ ADD\n");
                               str[0] = 0;                            
                          }

<STRING,MLSTRING>\$`[^`\n]*[\\\[\]][^`\n]*` { printf("ERROR! Found invalid identificator in template %s\n", yytext + 1); }

<STRING>\$\{                    {
                                    printf("Found string literal \"%s\"\n", str);
                                    printf("Found operator - \+ ADD\n");
                                    ++complexTemplateNestingLevel;
                                    BEGIN(INITIAL);
                                }
<STRING,MLSTRING>\$\{\}         { printf("ERROR! Found empty complex template\n"); }
<STRING,MLSTRING>\$             { strcat(str, yytext); }

\"\"\"              {
                        str[0] = 0;
                        BEGIN(MLSTRING);
                    }
<MLSTRING>[^$"]+    { strcat(str, yytext); }
<MLSTRING>\"{1,2}   { strcat(str, yytext); }
<MLSTRING>\"{3,}    {
                        strcat(str, yytext);
                        str[strlen(str) - 3] = 0;
                        yylval.String_v = str;
                        BEGIN(INITIAL);
						return STRING;
                    }
<MLSTRING>\$[a-zA-Z_][a-zA-Z_0-9]* {
                            if (!isNotKeyword(yytext + 1))
                            {
                                printf("ERROR! Found keyword \"%s\", but expected identificator\n", yytext + 1);
                            }
                            else 
                            {
                                printf("Found multi line string literal \"%s\"\n", str);
                                printf("Found operator - \+ ADD\n");
                                printf("Found identificator - \"%s\"\n", yytext + 1);
                                printf("Found operator - \+ ADD\n");
                                str[0] = 0;
                            }                            
                         }

<MLSTRING>\$`[^\n\\`\[\]]+` {
                               printf("Found multi line string literal \"%s\"\n", str);
                               printf("Found operator - \+ ADD\n");
                               str[0] = 0;
                               strcpy(str, yytext + 2);
                               str[yyleng - 2 - 1] = 0;
                               printf("Found identificator - \"%s\"\n", str);
                               printf("Found operator - \+ ADD\n");
                               str[0] = 0;                            
                            }                    
<MLSTRING>\$\{      {
                        printf("Found multi line string literal \"%s\"\n", str);
                        printf("Found operator - \+ ADD\n");
                        ++complexTemplateNestingLevel;
                        isMLString = true;
                        BEGIN(INITIAL);
                    }
<MLSTRING><<EOF>>   { printf("ERROR! Found end of file, but expected \"\"\"\n"); }


\n { printf("Found new line\n"); }

[a-zA-Z_][a-zA-Z_0-9]* 	{ 
							strcpy(yylval.Id, yytext);
							return ID;						
						}

``                              { printf("ERROR! Found empty identificator name\n"); }
"`"                             {
                                    str[0] = 0;
                                    BEGIN(IDENTIFICATOR);
                                }
<IDENTIFICATOR>[^\n\\`\[\]]+    { strcat(str, yytext); }
<IDENTIFICATOR>\n               { printf("ERROR! In string %s expected `\n", str); }
<IDENTIFICATOR>[\\\[\]]         { printf("ERROR! There is an illegal character \'%s\' in identificator \"%s\" \n", yytext, str); }
<IDENTIFICATOR><<EOF>>               { printf("ERROR! In string \"%s\" expected `\n", str); }
<IDENTIFICATOR>`                {
                                    yylval.Id = str;
                                    BEGIN(INITIAL);
									return ID;
                                }

<<EOF>> {
            if (complexTemplateNestingLevel > 0) 
            {
                printf("ERROR! Found end of file, but expected }\n");
                return 0;
            }
            else 
            {
                printf("Found end of file\n");
                return 0;
            }
        }

[\r\t\f\v ]+ {;}
.            {printf("Found unidentified symbol \'%s\'\n", yytext);}

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
































































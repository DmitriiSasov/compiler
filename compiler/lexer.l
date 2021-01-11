%option noyywrap
%option never-interactive
%option yylineno

%{
    #include <stdio.h>
    #include <exception>
    #include "synt_analyzer.tab.h"
    void remove_all_inputs_of_symbol(const char * str, char * result, char deleted_symbol);
    int bin_from_str_to_dec(const char * str);
    bool isNotKeyword(const char* str);
    enum InterpolElemType 
    {
        _STRING,
        _ID,
        _PLUS,
        _OPEN_BRACKET,
        _CLOSE_BRACKET,
        _None
    };
    struct InterpolationElement 
    {
        char * stringOrId;
        enum InterpolElemType type;
        struct InterpolationElement * next;
        struct InterpolationElement * previous;
    };
    struct InterpolElementsLinkedList 
    {
        struct InterpolationElement * first;
        struct InterpolationElement * last;    
    };
    bool addToList(struct InterpolElementsLinkedList * list, struct InterpolationElement * newElement);
    bool removeLastFromList(struct InterpolElementsLinkedList * list);
    bool removeFirstFromList(InterpolElementsLinkedList * list);
    InterpolationElement * createInterpolationElement(char * strOrId, InterpolationElement * next, InterpolationElement * previous, enum InterpolElemType type);
    InterpolElementsLinkedList * createList();
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
static char str[1000];
char tmpChar;
char * tmp = 0;
char forNum[100];
static int complexTemplateNestingLevel = 0; //Уровень вложенности для сложных шаблонов ${}
static bool isMLString = false;    //Встретилась ли интерполяция в многострочной строковой константе
static struct InterpolElementsLinkedList * list = createList();
static int elementToRemoveFromStack = 0;
struct InterpolationElement * el;

while (elementToRemoveFromStack > 0)
{
    if (list->first->type == _PLUS)
    {
        removeFirstFromList(list);
        --elementToRemoveFromStack;
        return '+';
    }
    else if (list->first->type == _ID)
    {
        yylval.IdOrString = list->first->stringOrId;
        removeFirstFromList(list);
        --elementToRemoveFromStack;
        return ID;
    }
    else if (list->first->type == _STRING)
    {
        yylval.IdOrString = list->first->stringOrId;
        removeFirstFromList(list);
        --elementToRemoveFromStack;
        return STR;
    }
    else if (list->first->type == _OPEN_BRACKET) 
    {
         removeFirstFromList(list);
        --elementToRemoveFromStack;
        return '(';
    }
}



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
                    //Сохраняем +, чтобы вернуть его после )
                    el = createInterpolationElement(0, 0, 0, _PLUS);
                    addToList(list, el);
                    ++elementToRemoveFromStack;

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
                    return ')';
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
							return CHR;
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
                        yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                        strcpy(yylval.IdOrString, str);
                        BEGIN(INITIAL);
						return STR;
                    }
<STRING>\\([^utbrn'"\\$]|(u{HEX_DIGIT}{0,3})) { printf("ERROR! Found illegal escape \"%s\"\n", yytext); }
<STRING>\n          { printf("ERROR! New line found after \"%s\", but \" expected\n", str); }
<STRING><<EOF>>     { printf("ERROR! End of file found after \"%s\", but \" expected\n", str); }
<STRING>\\\n        {;//Делать ничего не нужно
                    }

<STRING,MLSTRING>\$[a-zA-Z_][a-zA-Z_0-9]*  {
                            if (!isNotKeyword(yytext + 1))
                            {
                                printf("ERROR! Found keyword \"%s\", but expected identificator\n", yytext + 1);
                            }
                            else 
                            {
                                yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                                strcpy(yylval.IdOrString, str);
                                str[0] = 0;

                                el = createInterpolationElement(0, 0, 0, _PLUS);
                                addToList(list, el);
                                ++elementToRemoveFromStack;

                                el = createInterpolationElement(0, 0, 0, _ID);
                                el->stringOrId = (char *)malloc(strlen(yytext + 1) + 1);
                                strcpy(el->stringOrId, yytext + 1);
                                addToList(list, el);
                                ++elementToRemoveFromStack;

                                el = createInterpolationElement(0, 0, 0, _PLUS);
                                addToList(list, el);
                                ++elementToRemoveFromStack;
                                str[0] = 0;

                                return STR;
                            }                               
                        }

<STRING,MLSTRING>\$`[^\n\\`\[\]]+` {
                                yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                                strcpy(yylval.IdOrString, str);
                                str[0] = 0;

                                el = createInterpolationElement(0, 0, 0, _PLUS);
                                addToList(list, el);
                                ++elementToRemoveFromStack;

                                el = createInterpolationElement(0, 0, 0, _ID);
                                strcpy(str, yytext + 2);
                                str[yyleng - 2 - 1] = 0;
                                el->stringOrId = (char *)malloc(strlen(str + 1) + 1);
                                strcpy(el->stringOrId, str);
                                addToList(list, el);
                                ++elementToRemoveFromStack;

                                el = createInterpolationElement(0, 0, 0, _PLUS);
                                addToList(list, el);
                                ++elementToRemoveFromStack;
                                str[0] = 0; 

                                return STR;                   
                          }

<STRING,MLSTRING>\$`[^`\n]*[\\\[\]][^`\n]*` { printf("ERROR! Found invalid identificator in template %s\n", yytext + 1); }

<STRING>\$\{                    {
                                    yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                                    strcpy(yylval.IdOrString, str);

                                    el = createInterpolationElement(0, 0, 0, _PLUS);
                                    addToList(list, el);
                                    ++elementToRemoveFromStack;

                                    el = createInterpolationElement(0, 0, 0, _OPEN_BRACKET);
                                    addToList(list, el);
                                    ++elementToRemoveFromStack;

                                    ++complexTemplateNestingLevel;
                                    BEGIN(INITIAL);

                                    return STR;
                                }
<STRING,MLSTRING>\$\{\}         { printf("ERROR! Found empty complex template\n"); }
<STRING,MLSTRING>\$             { strcat(str, yytext); }

\"\"\"              {
                        throw std::exception("Unsupported multiline constants");
                        str[0] = 0;
                        BEGIN(MLSTRING);
                    }
<MLSTRING>[^$"]+    { strcat(str, yytext); }
<MLSTRING>\"{1,2}   { strcat(str, yytext); }
<MLSTRING>\"{3,}    {
                        strcat(str, yytext);
                        str[strlen(str) - 3] = 0;
                        yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                        strcpy(yylval.IdOrString, str);
                        BEGIN(INITIAL);

						return STR;
                    }
                    
<MLSTRING>\$\{      {
                        yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                        strcpy(yylval.IdOrString, str);

                        el = createInterpolationElement(0, 0, 0, _PLUS);
                        addToList(list, el);
                        ++elementToRemoveFromStack;

                        el = createInterpolationElement(0, 0, 0, _OPEN_BRACKET);
                        addToList(list, el);
                        ++elementToRemoveFromStack;

                        ++complexTemplateNestingLevel;
                        isMLString = true;
                        
                        BEGIN(INITIAL);

                        return STR;
                    }
<MLSTRING><<EOF>>   { printf("ERROR! Found end of file, but expected \"\"\"\n"); }


\n { return NEW_LINE; }

[a-zA-Z_][a-zA-Z_0-9]* 	{ 
							yylval.IdOrString = (char *)malloc(strlen(yytext) + 1);
                            strcpy(yylval.IdOrString, yytext);
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
                                    yylval.IdOrString = (char *)malloc(strlen(str) + 1);
                                    strcpy(yylval.IdOrString, str);
                                    BEGIN(INITIAL);
									return ID;
                                }

<<EOF>> {
            if (complexTemplateNestingLevel > 0) 
            {
                printf("ERROR! Found end of file, but expected }\n");
                
            }
            else 
            {
                printf("Found end of file\n");
            }

            return 0;
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


InterpolElementsLinkedList * createList()
{
    InterpolElementsLinkedList* res = (InterpolElementsLinkedList*)malloc(sizeof(InterpolElementsLinkedList));
    res->first = 0;
    res->last = 0;

    return res;
}

InterpolationElement * createInterpolationElement(char * strOrId, InterpolationElement * next, InterpolationElement * previous, enum InterpolElemType type)
{
    InterpolationElement * res = (InterpolationElement *)malloc(sizeof(InterpolationElement));
    res->stringOrId = strOrId;
    res->next = next;
    res->previous = previous;
    res->type = type;
    return res;
}

bool addToList(InterpolElementsLinkedList * list, InterpolationElement * newElement)
{
    if (list == 0) 
    {
        return false;
    }
    if (list->first == 0) 
    {
        list->first = newElement;
        list->last = newElement;
        return true;
    }
    list->last->next = newElement;
    newElement->previous = list->last;
    list->last = newElement;
    return true;
}

bool removeFirstFromList(InterpolElementsLinkedList * list) 
{
    if (list == 0) 
    {
        return false;
    }
    if (list->first == 0) 
    {
        return true;
    }
    if (list->first == list->last)
    {
        free(list->first);
        list->first = list->last = 0;
        return true;
    }
    InterpolationElement * tmp = list->first->next;
    tmp->previous = 0;
    free(list->first);
    list->first = tmp;
    return true;
}

bool removeLastFromList(InterpolElementsLinkedList * list) 
{
    if (list == 0) 
    {
        return false;
    }
    if (list->first == 0) 
    {
        return true;
    }
    InterpolationElement * tmp = list->last;
    list->last = list->last->previous;
    if (list->last != 0)
        list->last->next = 0;
    else
        list->first = 0;
    tmp->previous = 0;
    free(tmp);
    return true;
}

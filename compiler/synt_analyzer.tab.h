/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_SYNT_ANALYZER_TAB_H_INCLUDED
# define YY_YY_SYNT_ANALYZER_TAB_H_INCLUDED
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
    NEW_LINE = 258,                /* NEW_LINE  */
    ID = 259,                      /* ID  */
    CLASS = 260,                   /* CLASS  */
    PUBLIC = 261,                  /* PUBLIC  */
    PRIVATE = 262,                 /* PRIVATE  */
    PROTECTED = 263,               /* PROTECTED  */
    FIELD = 264,                   /* FIELD  */
    PARAM = 265,                   /* PARAM  */
    SETPARAM = 266,                /* SETPARAM  */
    DELEGATE = 267,                /* DELEGATE  */
    INTERFACE = 268,               /* INTERFACE  */
    OBJECT = 269,                  /* OBJECT  */
    PROPERTY = 270,                /* PROPERTY  */
    DYNAMIC = 271,                 /* DYNAMIC  */
    ENUM = 272,                    /* ENUM  */
    SEALED = 273,                  /* SEALED  */
    SUSPEND = 274,                 /* SUSPEND  */
    INNER = 275,                   /* INNER  */
    EXTERNAL = 276,                /* EXTERNAL  */
    ACTUAL = 277,                  /* ACTUAL  */
    ANNOTATION = 278,              /* ANNOTATION  */
    GET = 279,                     /* GET  */
    SET = 280,                     /* SET  */
    RECEIVER = 281,                /* RECEIVER  */
    CONSTRUCTOR = 282,             /* CONSTRUCTOR  */
    BY = 283,                      /* BY  */
    COMPANION = 284,               /* COMPANION  */
    INIT = 285,                    /* INIT  */
    LATEINIT = 286,                /* LATEINIT  */
    VARARG = 287,                  /* VARARG  */
    THIS = 288,                    /* THIS  */
    SUPER = 289,                   /* SUPER  */
    INTERNAL = 290,                /* INTERNAL  */
    OVERRIDE = 291,                /* OVERRIDE  */
    ABSTRACT = 292,                /* ABSTRACT  */
    FUN = 293,                     /* FUN  */
    VAR = 294,                     /* VAR  */
    VAL = 295,                     /* VAL  */
    TYPEOF = 296,                  /* TYPEOF  */
    IF = 297,                      /* IF  */
    ELSE = 298,                    /* ELSE  */
    WHERE = 299,                   /* WHERE  */
    WHEN = 300,                    /* WHEN  */
    DO = 301,                      /* DO  */
    WHILE = 302,                   /* WHILE  */
    FOR = 303,                     /* FOR  */
    BREAK = 304,                   /* BREAK  */
    CONTINUE = 305,                /* CONTINUE  */
    AS = 306,                      /* AS  */
    IN = 307,                      /* IN  */
    OUT = 308,                     /* OUT  */
    DATA = 309,                    /* DATA  */
    RETURN = 310,                  /* RETURN  */
    TAILREC = 311,                 /* TAILREC  */
    OPERATOR = 312,                /* OPERATOR  */
    INLINE = 313,                  /* INLINE  */
    NOINLINE = 314,                /* NOINLINE  */
    CROSSINLINE = 315,             /* CROSSINLINE  */
    REIFIED = 316,                 /* REIFIED  */
    EXPECT = 317,                  /* EXPECT  */
    INFIX = 318,                   /* INFIX  */
    OPEN = 319,                    /* OPEN  */
    FINAL = 320,                   /* FINAL  */
    CONST = 321,                   /* CONST  */
    INT = 322,                     /* INT  */
    FLOAT = 323,                   /* FLOAT  */
    DOUBLE = 324,                  /* DOUBLE  */
    STRING = 325,                  /* STRING  */
    CHAR = 326,                    /* CHAR  */
    BOOLEAN = 327,                 /* BOOLEAN  */
    ASUM = 328,                    /* ASUM  */
    ASUB = 329,                    /* ASUB  */
    ADIV = 330,                    /* ADIV  */
    AMUL = 331,                    /* AMUL  */
    AMOD = 332,                    /* AMOD  */
    OR = 333,                      /* OR  */
    AND = 334,                     /* AND  */
    EQ = 335,                      /* EQ  */
    AEQ = 336,                     /* AEQ  */
    NEQ = 337,                     /* NEQ  */
    NAEQ = 338,                    /* NAEQ  */
    LOEQ = 339,                    /* LOEQ  */
    MOEQ = 340,                    /* MOEQ  */
    RANGE = 341,                   /* RANGE  */
    UMINUS = 342,                  /* UMINUS  */
    UPLUS = 343                    /* UPLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 138 "synt_analyzer.y"

	int Int_v;
	float Float_v;
	double Double_v;
	char Char_v;
	char * String_v;
	char * Id;
	bool Bool_v;
	
	enum visibilityMod visibilityModU;
	enum inheritanceMod inheritanceModU;
	
	struct modifiersS * modifiersU;
	struct exprS * exprU;
	struct factParamsList * factParamsListU;
	struct stmtS * stmtU;
	struct stmtList * stmtListU;
	struct ifStmtS * ifStmtU;
	struct forLoopS * forLoopU;
	struct whileLoopS * whileLoopU;
	struct assignmentS * assignmentU;
	struct propertyS * propertyU;
	struct varOrValDeclS * varOrValDeclU;
	struct typeS * typeU;
	struct templateTypeS * templateTypeU;
	struct typesList * typesListU;
	struct formalParamS * formalParamU;
	struct formalParamsList * formalParamsListU;
	struct funcDeclS * funcDeclU;
	struct funcS * funcU;
	struct constructorS * constructorU;
	struct methodS * methodU;
	struct initializerS * initializerU;
	struct classS * classU;
	struct classBodyElementS * classBodyElementU;
	struct classBodyS * classBodyU;
	struct programElementS * programElementU;
	struct programS * programU;

#line 192 "synt_analyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNT_ANALYZER_TAB_H_INCLUDED  */

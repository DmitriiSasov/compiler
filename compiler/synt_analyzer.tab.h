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
    STR = 260,                     /* STR  */
    CLASS = 261,                   /* CLASS  */
    PUBLIC = 262,                  /* PUBLIC  */
    PRIVATE = 263,                 /* PRIVATE  */
    PROTECTED = 264,               /* PROTECTED  */
    FIELD = 265,                   /* FIELD  */
    PARAM = 266,                   /* PARAM  */
    SETPARAM = 267,                /* SETPARAM  */
    DELEGATE = 268,                /* DELEGATE  */
    INTERFACE = 269,               /* INTERFACE  */
    OBJECT = 270,                  /* OBJECT  */
    PROPERTY = 271,                /* PROPERTY  */
    DYNAMIC = 272,                 /* DYNAMIC  */
    ENUM = 273,                    /* ENUM  */
    SEALED = 274,                  /* SEALED  */
    SUSPEND = 275,                 /* SUSPEND  */
    INNER = 276,                   /* INNER  */
    EXTERNAL = 277,                /* EXTERNAL  */
    ACTUAL = 278,                  /* ACTUAL  */
    ANNOTATION = 279,              /* ANNOTATION  */
    GET = 280,                     /* GET  */
    SET = 281,                     /* SET  */
    RECEIVER = 282,                /* RECEIVER  */
    CONSTRUCTOR = 283,             /* CONSTRUCTOR  */
    BY = 284,                      /* BY  */
    COMPANION = 285,               /* COMPANION  */
    INIT = 286,                    /* INIT  */
    LATEINIT = 287,                /* LATEINIT  */
    VARARG = 288,                  /* VARARG  */
    THIS = 289,                    /* THIS  */
    SUPER = 290,                   /* SUPER  */
    INTERNAL = 291,                /* INTERNAL  */
    OVERRIDE = 292,                /* OVERRIDE  */
    ABSTRACT = 293,                /* ABSTRACT  */
    FUN = 294,                     /* FUN  */
    VAR = 295,                     /* VAR  */
    VAL = 296,                     /* VAL  */
    TYPEOF = 297,                  /* TYPEOF  */
    IF = 298,                      /* IF  */
    ELSE = 299,                    /* ELSE  */
    WHERE = 300,                   /* WHERE  */
    WHEN = 301,                    /* WHEN  */
    DO = 302,                      /* DO  */
    WHILE = 303,                   /* WHILE  */
    FOR = 304,                     /* FOR  */
    BREAK = 305,                   /* BREAK  */
    CONTINUE = 306,                /* CONTINUE  */
    AS = 307,                      /* AS  */
    IN = 308,                      /* IN  */
    OUT = 309,                     /* OUT  */
    DATA = 310,                    /* DATA  */
    RETURN = 311,                  /* RETURN  */
    TAILREC = 312,                 /* TAILREC  */
    OPERATOR = 313,                /* OPERATOR  */
    INLINE = 314,                  /* INLINE  */
    NOINLINE = 315,                /* NOINLINE  */
    CROSSINLINE = 316,             /* CROSSINLINE  */
    REIFIED = 317,                 /* REIFIED  */
    EXPECT = 318,                  /* EXPECT  */
    INFIX = 319,                   /* INFIX  */
    OPEN = 320,                    /* OPEN  */
    FINAL = 321,                   /* FINAL  */
    CONST = 322,                   /* CONST  */
    INT = 323,                     /* INT  */
    FLOAT = 324,                   /* FLOAT  */
    DOUBLE = 325,                  /* DOUBLE  */
    CHR = 326,                     /* CHR  */
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
#line 19 "synt_analyzer.y"

	int Int_v;
	float Float_v;
	double Double_v;
	char Char_v;
	char * IdOrString;
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

#line 191 "synt_analyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNT_ANALYZER_TAB_H_INCLUDED  */

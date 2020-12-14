/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "synt_analyzer.y"


	#include <stdio.h>
	#include <malloc.h>
	#include <string.h>
	#include "print_funcs.h"
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;
	
	struct programS * root;
	
	struct programS * createProgram();
	struct programS * createProgram(struct classS * clas);
	struct programS * createProgram(struct methodS * meth);
	struct programS * createProgram(struct propertyS * prop);
	struct programS * addToProgram(struct programS * prog, struct classS * clas);
	struct programS * addToProgram(struct programS * prog, struct methodS * meth);
	struct programS * addToProgram(struct programS * prog, struct propertyS * prop);
	
	struct classS * createClass(struct modifiersS * mods, char * id, char * parentId, struct classBodyS * body);
	struct classS * createClass(struct modifiersS * mods, char * id, struct classBodyS * body);	
	struct classS * createClass(char * id, char * parentId, struct classBodyS * body);
	struct classS * createClass(char * id, struct classBodyS * body);
	
	struct classBodyS * createClassBody();
	struct classBodyS * createClassBody(struct methodS * meth);
	struct classBodyS * createClassBody(struct initializerS * initializer);
	struct classBodyS * createClassBody(struct propertyS * prop);
	struct classBodyS * createClassBody(struct constructorS * constr);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct methodS * meth);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct initializerS * initializer);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct propertyS * prop);
	struct classBodyS * addToClassBody(struct classBodyS * body, struct constructorS * constr);
	
	struct propertyS * createProperty(struct modifiersS * mods, struct varOrValDeclS * decl);
	struct propertyS * createProperty(struct varOrValDeclS * decl);
	
	struct methodS * createMethod(struct modifiersS * mods, struct funcDeclS * funcDecl);
	struct methodS * createMethod(struct modifiersS * mods, struct funcS * func);
	struct methodS * createMethod(struct funcDeclS * funcDecl);
	struct methodS * createMethod(struct funcS * func);
	
	struct initializerS * createInit(struct stmtList * stmts);
	
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, struct stmtList * stmts);
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params);
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams);
	struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts);
	struct constructorS * createConstructor(struct formalParamsList * params, struct stmtList * stmts);
	struct constructorS * createConstructor(struct formalParamsList * params);
	struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams);
	struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts);
	
	struct formalParamsList * createFormalParamsList();
	struct formalParamsList * createFormalParamsList(char * id, struct typeS * type);
	struct formalParamsList * addToFormalParamsList(struct formalParamsList * list, char * id, struct typeS * type);
	
	struct modifiersS * createModifiers(int isAbstruct, int isOverride, enum visibilityMod vMod, enum inheritanceMod iMod);
	
	struct funcS * createFunc(struct funcDeclS * decl, struct stmtList * stmts);
	struct funcS * createFunc(struct funcDeclS * decl, struct exprS * expr);
	
	struct funcDeclS * createFuncDecl(char * id, struct formalParamsList * params, struct typeS * type);
	
	struct stmtList * createStmtList();
	struct stmtList * createStmtList(struct stmtS * stmt);
	struct stmtList * addToStmtList(struct stmtList * list, struct stmtS * stmt);
	
	struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, int isVal);
	struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, struct exprS * initValue, int isVal);
	struct varOrValDeclS * createVarOrValDecl(struct formalParamsList * idsAndTypes, struct exprS * initValue, int isVal);
	
	struct typeS * createType(char * id);
	struct typeS * createType(struct templateTypeS * type);
	
	struct templateTypeS * createTemplateType(char * id, struct typesList * templateTypes);
	
	struct typesList * createTypesList(char * id);
	struct typesList * createTypesList(struct templateTypeS * tt);
	struct typesList * addToTypesList(struct typesList * list, char * id);
	struct typesList * addToTypesList(struct typesList * list, struct templateTypeS * tt);
	
	struct stmtS * createStmt(struct varOrValDeclS * v, enum stmtType type);
	struct stmtS * createStmt(struct assignmentS * assign, enum stmtType type);
	struct stmtS * createStmt(struct whileLoopS * loop, enum stmtType type);
	struct stmtS * createStmt(struct forLoopS * loop, enum stmtType type);
	struct stmtS * createStmt(struct ifStmtS * ifStmt, enum stmtType type);
	struct stmtS * createStmt(struct exprS * expr, enum stmtType type);
	struct stmtS * createStmt(enum stmtType type);
	
	struct exprS * createExpr(char * idOrString, enum exprType type);
	struct exprS * createExpr(int val, enum exprType type);
	struct exprS * createExpr(char * idOrString, struct factParamsList * params, enum exprType type);
	struct exprS * createExpr(float val, enum exprType type);
	struct exprS * createExpr(double val, enum exprType type);
	struct exprS * createExpr(char val, enum exprType type);
	struct exprS * createExpr(bool val, enum exprType type);
	struct exprS * createExpr(struct exprS * expr, enum exprType type);
	struct exprS * createExpr(struct exprS * left, struct exprS * right, enum exprType type);
	struct exprS * createExpr(struct exprS * left, char * right, enum exprType type);
	struct exprS * createExpr(struct exprS * left, char * right, struct factParamsList * params, enum exprType type);
	
	struct factParamsList * createFactParamsList();
	struct factParamsList * createFactParamsList(struct exprS * expr);
	struct factParamsList * addToFactParamsList(struct factParamsList * list, struct exprS * expr);
	
	struct assignmentS * createAssignment(struct exprS * left, struct exprS * right, enum assignmentType type); 
	
	struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtS * stmt, int isDoWhile);
	struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtList * stmts, int isDoWhile);
	struct whileLoopS * createWhileLoop(struct exprS * cond, int isDoWhile);
	
	struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtS * stmt);
	struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtList * stmts);
	struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtList * stmts);
	struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtS * stmt);
	struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr);
	struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr);
	
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions);
	struct ifStmtS * createIfStmt(struct exprS * cond);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtS * altAction);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtList * altActions);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtS * altAction);
	struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtList * altActions);
	struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtS * altAction);
	struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtList * altActions);
	

#line 206 "synt_analyzer.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "synt_analyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEW_LINE = 3,                   /* NEW_LINE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 6,                     /* PUBLIC  */
  YYSYMBOL_PRIVATE = 7,                    /* PRIVATE  */
  YYSYMBOL_PROTECTED = 8,                  /* PROTECTED  */
  YYSYMBOL_FIELD = 9,                      /* FIELD  */
  YYSYMBOL_PARAM = 10,                     /* PARAM  */
  YYSYMBOL_SETPARAM = 11,                  /* SETPARAM  */
  YYSYMBOL_DELEGATE = 12,                  /* DELEGATE  */
  YYSYMBOL_INTERFACE = 13,                 /* INTERFACE  */
  YYSYMBOL_OBJECT = 14,                    /* OBJECT  */
  YYSYMBOL_PROPERTY = 15,                  /* PROPERTY  */
  YYSYMBOL_DYNAMIC = 16,                   /* DYNAMIC  */
  YYSYMBOL_ENUM = 17,                      /* ENUM  */
  YYSYMBOL_SEALED = 18,                    /* SEALED  */
  YYSYMBOL_SUSPEND = 19,                   /* SUSPEND  */
  YYSYMBOL_INNER = 20,                     /* INNER  */
  YYSYMBOL_EXTERNAL = 21,                  /* EXTERNAL  */
  YYSYMBOL_ACTUAL = 22,                    /* ACTUAL  */
  YYSYMBOL_ANNOTATION = 23,                /* ANNOTATION  */
  YYSYMBOL_GET = 24,                       /* GET  */
  YYSYMBOL_SET = 25,                       /* SET  */
  YYSYMBOL_RECEIVER = 26,                  /* RECEIVER  */
  YYSYMBOL_CONSTRUCTOR = 27,               /* CONSTRUCTOR  */
  YYSYMBOL_BY = 28,                        /* BY  */
  YYSYMBOL_COMPANION = 29,                 /* COMPANION  */
  YYSYMBOL_INIT = 30,                      /* INIT  */
  YYSYMBOL_LATEINIT = 31,                  /* LATEINIT  */
  YYSYMBOL_VARARG = 32,                    /* VARARG  */
  YYSYMBOL_THIS = 33,                      /* THIS  */
  YYSYMBOL_SUPER = 34,                     /* SUPER  */
  YYSYMBOL_INTERNAL = 35,                  /* INTERNAL  */
  YYSYMBOL_OVERRIDE = 36,                  /* OVERRIDE  */
  YYSYMBOL_ABSTRACT = 37,                  /* ABSTRACT  */
  YYSYMBOL_FUN = 38,                       /* FUN  */
  YYSYMBOL_VAR = 39,                       /* VAR  */
  YYSYMBOL_VAL = 40,                       /* VAL  */
  YYSYMBOL_TYPEOF = 41,                    /* TYPEOF  */
  YYSYMBOL_IF = 42,                        /* IF  */
  YYSYMBOL_ELSE = 43,                      /* ELSE  */
  YYSYMBOL_WHERE = 44,                     /* WHERE  */
  YYSYMBOL_WHEN = 45,                      /* WHEN  */
  YYSYMBOL_DO = 46,                        /* DO  */
  YYSYMBOL_WHILE = 47,                     /* WHILE  */
  YYSYMBOL_FOR = 48,                       /* FOR  */
  YYSYMBOL_BREAK = 49,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 50,                  /* CONTINUE  */
  YYSYMBOL_AS = 51,                        /* AS  */
  YYSYMBOL_IN = 52,                        /* IN  */
  YYSYMBOL_OUT = 53,                       /* OUT  */
  YYSYMBOL_DATA = 54,                      /* DATA  */
  YYSYMBOL_RETURN = 55,                    /* RETURN  */
  YYSYMBOL_TAILREC = 56,                   /* TAILREC  */
  YYSYMBOL_OPERATOR = 57,                  /* OPERATOR  */
  YYSYMBOL_INLINE = 58,                    /* INLINE  */
  YYSYMBOL_NOINLINE = 59,                  /* NOINLINE  */
  YYSYMBOL_CROSSINLINE = 60,               /* CROSSINLINE  */
  YYSYMBOL_REIFIED = 61,                   /* REIFIED  */
  YYSYMBOL_EXPECT = 62,                    /* EXPECT  */
  YYSYMBOL_INFIX = 63,                     /* INFIX  */
  YYSYMBOL_OPEN = 64,                      /* OPEN  */
  YYSYMBOL_FINAL = 65,                     /* FINAL  */
  YYSYMBOL_CONST = 66,                     /* CONST  */
  YYSYMBOL_INT = 67,                       /* INT  */
  YYSYMBOL_FLOAT = 68,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 69,                    /* DOUBLE  */
  YYSYMBOL_STRING = 70,                    /* STRING  */
  YYSYMBOL_CHAR = 71,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 72,                   /* BOOLEAN  */
  YYSYMBOL_ASUM = 73,                      /* ASUM  */
  YYSYMBOL_ASUB = 74,                      /* ASUB  */
  YYSYMBOL_ADIV = 75,                      /* ADIV  */
  YYSYMBOL_AMUL = 76,                      /* AMUL  */
  YYSYMBOL_AMOD = 77,                      /* AMOD  */
  YYSYMBOL_OR = 78,                        /* OR  */
  YYSYMBOL_AND = 79,                       /* AND  */
  YYSYMBOL_EQ = 80,                        /* EQ  */
  YYSYMBOL_AEQ = 81,                       /* AEQ  */
  YYSYMBOL_NEQ = 82,                       /* NEQ  */
  YYSYMBOL_NAEQ = 83,                      /* NAEQ  */
  YYSYMBOL_LOEQ = 84,                      /* LOEQ  */
  YYSYMBOL_MOEQ = 85,                      /* MOEQ  */
  YYSYMBOL_86_ = 86,                       /* '<'  */
  YYSYMBOL_87_ = 87,                       /* '>'  */
  YYSYMBOL_RANGE = 88,                     /* RANGE  */
  YYSYMBOL_89_ = 89,                       /* '+'  */
  YYSYMBOL_90_ = 90,                       /* '-'  */
  YYSYMBOL_91_ = 91,                       /* '/'  */
  YYSYMBOL_92_ = 92,                       /* '*'  */
  YYSYMBOL_93_ = 93,                       /* '%'  */
  YYSYMBOL_UMINUS = 94,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 95,                     /* UPLUS  */
  YYSYMBOL_96_ = 96,                       /* '!'  */
  YYSYMBOL_97_ = 97,                       /* '.'  */
  YYSYMBOL_98_ = 98,                       /* '('  */
  YYSYMBOL_99_ = 99,                       /* ')'  */
  YYSYMBOL_100_ = 100,                     /* '['  */
  YYSYMBOL_101_ = 101,                     /* ']'  */
  YYSYMBOL_102_ = 102,                     /* ':'  */
  YYSYMBOL_103_ = 103,                     /* '{'  */
  YYSYMBOL_104_ = 104,                     /* '}'  */
  YYSYMBOL_105_ = 105,                     /* ';'  */
  YYSYMBOL_106_ = 106,                     /* ','  */
  YYSYMBOL_107_ = 107,                     /* '='  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_program = 109,                  /* program  */
  YYSYMBOL_class = 110,                    /* class  */
  YYSYMBOL_classBody = 111,                /* classBody  */
  YYSYMBOL_property = 112,                 /* property  */
  YYSYMBOL_method = 113,                   /* method  */
  YYSYMBOL_initializer = 114,              /* initializer  */
  YYSYMBOL_constructor = 115,              /* constructor  */
  YYSYMBOL_optFormalParams = 116,          /* optFormalParams  */
  YYSYMBOL_formalParams = 117,             /* formalParams  */
  YYSYMBOL_modifiers = 118,                /* modifiers  */
  YYSYMBOL_visibilityModifier = 119,       /* visibilityModifier  */
  YYSYMBOL_inheritanceModifier = 120,      /* inheritanceModifier  */
  YYSYMBOL_func = 121,                     /* func  */
  YYSYMBOL_funcDeclaration = 122,          /* funcDeclaration  */
  YYSYMBOL_block = 123,                    /* block  */
  YYSYMBOL_varDeclaration = 124,           /* varDeclaration  */
  YYSYMBOL_valDeclaration = 125,           /* valDeclaration  */
  YYSYMBOL_type = 126,                     /* type  */
  YYSYMBOL_templateType = 127,             /* templateType  */
  YYSYMBOL_type_seq = 128,                 /* type_seq  */
  YYSYMBOL_stmts = 129,                    /* stmts  */
  YYSYMBOL_stmt = 130,                     /* stmt  */
  YYSYMBOL_expr = 131,                     /* expr  */
  YYSYMBOL_optFactParams = 132,            /* optFactParams  */
  YYSYMBOL_factParams = 133,               /* factParams  */
  YYSYMBOL_assignment = 134,               /* assignment  */
  YYSYMBOL_whileLoop = 135,                /* whileLoop  */
  YYSYMBOL_doWhileLoop = 136,              /* doWhileLoop  */
  YYSYMBOL_forLoop = 137,                  /* forLoop  */
  YYSYMBOL_ifStmt = 138,                   /* ifStmt  */
  YYSYMBOL_optNewLines = 139,              /* optNewLines  */
  YYSYMBOL_newLines = 140,                 /* newLines  */
  YYSYMBOL_semis = 141                     /* semis  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1736

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  250
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  422

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   343


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    96,     2,     2,     2,    93,     2,     2,
      98,    99,    92,    89,   106,    90,    97,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,   105,
      86,   107,    87,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   101,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   103,     2,   104,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    88,    94,    95
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   313,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   327,   328,   329,   330,   331,   332,
     333,   334,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   353,   354,   355,   356,
     359,   360,   361,   362,   365,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   383,   384,   387,
     388,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   447,   449,   451,   453,
     455,   457,   458,   459,   461,   465,   466,   467,   468,   472,
     473,   476,   477,   481,   485,   486,   487,   488,   492,   493,
     494,   498,   499,   500,   503,   504,   507,   510,   511,   512,
     513,   516,   517,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   582,   583,   586,   587,   590,   591,   592,   593,   594,
     595,   598,   599,   600,   603,   604,   605,   608,   609,   610,
     611,   612,   613,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   631,   632,   635,   636,   639,
     640
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEW_LINE", "ID",
  "CLASS", "PUBLIC", "PRIVATE", "PROTECTED", "FIELD", "PARAM", "SETPARAM",
  "DELEGATE", "INTERFACE", "OBJECT", "PROPERTY", "DYNAMIC", "ENUM",
  "SEALED", "SUSPEND", "INNER", "EXTERNAL", "ACTUAL", "ANNOTATION", "GET",
  "SET", "RECEIVER", "CONSTRUCTOR", "BY", "COMPANION", "INIT", "LATEINIT",
  "VARARG", "THIS", "SUPER", "INTERNAL", "OVERRIDE", "ABSTRACT", "FUN",
  "VAR", "VAL", "TYPEOF", "IF", "ELSE", "WHERE", "WHEN", "DO", "WHILE",
  "FOR", "BREAK", "CONTINUE", "AS", "IN", "OUT", "DATA", "RETURN",
  "TAILREC", "OPERATOR", "INLINE", "NOINLINE", "CROSSINLINE", "REIFIED",
  "EXPECT", "INFIX", "OPEN", "FINAL", "CONST", "INT", "FLOAT", "DOUBLE",
  "STRING", "CHAR", "BOOLEAN", "ASUM", "ASUB", "ADIV", "AMUL", "AMOD",
  "OR", "AND", "EQ", "AEQ", "NEQ", "NAEQ", "LOEQ", "MOEQ", "'<'", "'>'",
  "RANGE", "'+'", "'-'", "'/'", "'*'", "'%'", "UMINUS", "UPLUS", "'!'",
  "'.'", "'('", "')'", "'['", "']'", "':'", "'{'", "'}'", "';'", "','",
  "'='", "$accept", "program", "class", "classBody", "property", "method",
  "initializer", "constructor", "optFormalParams", "formalParams",
  "modifiers", "visibilityModifier", "inheritanceModifier", "func",
  "funcDeclaration", "block", "varDeclaration", "valDeclaration", "type",
  "templateType", "type_seq", "stmts", "stmt", "expr", "optFactParams",
  "factParams", "assignment", "whileLoop", "doWhileLoop", "forLoop",
  "ifStmt", "optNewLines", "newLines", "semis", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,    60,    62,   341,    43,
      45,    47,    42,    37,   342,   343,    33,    46,    40,    41,
      91,    93,    58,   123,   125,    59,    44,    61
};
#endif

#define YYPACT_NINF (-243)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     938,  -243,    30,  -243,  -243,  -243,  -243,    77,    43,    34,
      33,    35,  -243,  -243,  -243,   424,  -243,    24,  -243,    25,
     141,   247,  -243,    -5,  -243,  -243,    59,   -39,   -49,    86,
     102,    38,    86,   177,   156,   -30,   -16,    68,   -14,    68,
    -243,  -243,    24,  -243,    59,   -39,    59,   -39,    95,  -243,
      96,  -243,  -243,   187,   196,    73,   250,   262,   171,    24,
    -243,   446,  -243,  -243,  -243,   111,   622,   145,   139,   145,
      81,   139,    97,   145,   139,   145,   113,   139,   122,    68,
     161,   126,   -10,   161,     7,    59,   -39,   109,  -243,   145,
     133,   145,   194,   199,   208,   139,   209,   139,   231,   234,
     236,  1242,    59,   949,   175,  -243,   179,  -243,  -243,  -243,
    -243,  -243,  -243,   446,   446,   446,   446,   997,   174,   176,
     183,  -243,   636,    24,  -243,  -243,  -243,   114,    40,    59,
     -39,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,   191,   189,   217,   197,  -243,   161,   201,
     305,   204,   205,   310,   682,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,   221,  1401,   222,
     223,    24,    24,   867,  -243,    24,    24,   320,  -243,   496,
      24,    24,    24,    24,    24,  -243,   320,   446,   332,   -57,
     -57,   -57,  1475,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   333,
     446,   725,    68,  -243,  -243,    24,  -243,  -243,  -243,    59,
     -39,    59,   -39,   243,   238,   341,   446,  -243,   446,   248,
     446,   446,   251,  -243,   742,   446,   253,   306,   308,   446,
      37,    59,   -39,    59,   -39,   527,    59,   -39,    59,   -39,
      59,   -39,  1295,   446,   446,   446,   446,   446,   446,    59,
     -39,    59,   -39,    59,   -39,    59,   -39,    59,   -39,    59,
     -39,  1348,   997,   257,   268,   278,  -243,  1057,   831,   242,
     242,   242,   242,   297,   297,   297,   297,   354,   225,   225,
     -57,   -57,   -57,   283,  1432,  -243,   785,   284,    59,   -39,
      68,   161,   217,  -243,   -54,   997,   997,   161,   997,   997,
     828,  -243,  1498,   446,   294,   300,  1521,   280,    68,    59,
     -39,  -243,  -243,   997,   997,   997,   997,   997,   997,  -243,
    -243,   446,   446,   446,  -243,  -243,   115,   302,  -243,  -243,
     398,  -243,  -243,   845,  1002,  1544,   446,   446,  1062,   161,
      49,   997,   304,   307,   186,  -243,   119,   217,  -243,  -243,
     362,   364,   -18,   435,  1567,  1590,  -243,  -243,  -243,   356,
     357,  -243,  -243,   312,   313,   229,  -243,  1002,  1002,  1002,
    -243,  -243,  -243,   446,   446,   446,   446,   314,   318,  -243,
    -243,   -39,  -243,  -243,   -39,  -243,  -243,   -39,  1613,  1636,
     326,   327,   446,   446,  1122,  1182,   183,   183,   329,   334,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   183,   183,
    -243,  -243
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   247,     0,   125,   126,   128,   127,    61,    64,     0,
       0,     0,   130,   129,   249,     0,     4,     0,     5,     0,
      62,    63,    43,     0,    39,    38,     3,     2,     0,    67,
      65,    66,    74,    75,    76,     0,     0,     0,     0,     0,
       1,     8,     0,     9,    12,    13,     7,     6,     0,    41,
       0,    37,    36,    68,    70,    69,    71,    73,    72,   245,
      42,     0,   131,   248,   250,     0,     0,    81,    82,    78,
      77,    80,    79,    96,    95,    97,    98,    99,   100,    57,
       0,     0,     0,     0,     0,    11,    10,     0,    40,    84,
      83,    88,    87,    85,    86,    90,    89,    94,    93,    92,
      91,     0,   246,     0,   177,   178,     0,   180,   181,   184,
     182,   183,   185,     0,     0,     0,     0,   132,     0,     0,
       0,    21,     0,     0,    24,    28,    27,     0,    62,    23,
      22,   105,   106,   102,   101,   104,   103,   120,   119,   121,
     122,   123,   124,     0,    58,   144,   138,   145,     0,     0,
       0,   141,     0,     0,     0,   108,   107,   112,   111,   109,
     110,   114,   113,   118,   117,   116,   115,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,   245,   151,     0,
       0,     0,     0,     0,     0,   136,   245,   211,     0,   188,
     189,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    44,    17,     0,    29,    34,    33,    32,
      35,    26,    25,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,   170,   169,   172,   171,     0,   174,   173,   156,   155,
     154,   153,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   158,   157,   160,   159,   164,   163,   162,   161,   166,
     165,     0,   213,     0,   212,   208,   186,   197,   198,   199,
     200,   201,   202,   203,   204,   195,   196,   210,   190,   191,
     193,   192,   194,   205,     0,    20,     0,     0,    31,    30,
      57,     0,   147,   148,     0,   139,   140,     0,   142,   143,
       0,    15,     0,     0,     0,     0,     0,     0,     0,   175,
     176,   134,   152,   216,   217,   218,   219,   220,   215,   135,
     179,     0,   211,   211,   207,    16,    52,     0,   133,   146,
       0,    60,    18,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,     0,    51,    46,   149,   150,    14,
     234,   233,   235,     0,     0,     0,   223,   222,   221,     0,
       0,   209,   206,     0,     0,     0,    45,     0,     0,     0,
     226,   225,   224,     0,     0,   211,   211,     0,     0,   240,
     237,   243,   239,   236,   242,   241,   238,   244,     0,     0,
       0,     0,   211,   211,     0,     0,    54,    53,     0,     0,
     229,   228,   227,   232,   231,   230,    56,    55,    48,    47,
      50,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,   402,  -141,     4,     6,   -96,   -94,  -189,   -29,
      32,  1474,    28,    -7,    -3,  -113,     3,     5,   -74,  -224,
    -243,   331,    36,   165,  -242,  -243,  -243,  -243,  -243,  -243,
    -243,  -175,    14,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,   122,   123,   124,   125,   126,   143,   144,
     127,   128,    21,    22,    23,    62,   175,   176,   146,   147,
     304,   177,   178,   179,   273,   274,   180,   181,   182,   183,
     184,   101,   102,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   303,   252,    24,    17,    25,    18,   213,    82,   151,
      84,   271,    49,   234,    26,    45,    50,    47,    24,    42,
      25,    43,    51,   297,    52,   379,   217,     1,   218,    44,
      48,    46,    19,   339,    28,    31,    34,    36,    35,    38,
     209,   317,    86,   210,     3,     4,     5,    19,    55,     3,
       4,     5,   340,    65,    66,   237,    85,    68,    70,   103,
      74,    76,    63,     9,    10,    11,    64,   223,    79,    24,
     296,    25,    81,     6,   227,    71,    53,    54,     6,    32,
     129,    90,    92,     3,     4,     5,    80,    64,    83,   149,
     352,   353,     3,     4,     5,   131,   150,   133,    59,    87,
      60,   137,    61,   139,    12,    13,   152,    12,    13,    93,
      94,   337,     6,   150,    29,   118,   358,   155,   134,   157,
      49,     6,   220,   222,    50,    24,   215,    25,   216,    14,
      51,    37,    52,    39,   136,   318,   219,   221,   217,    69,
     218,    12,    13,   400,   401,     3,     4,     5,   370,   140,
      12,    13,     9,    10,    11,   150,    55,    24,   142,    25,
     408,   409,     3,     4,     5,   145,    12,    13,   129,   343,
     156,   242,   244,   247,     6,   249,   251,    53,    54,   260,
     262,   264,   266,   268,   270,   241,   243,   246,   380,   248,
     250,     6,    77,   259,   261,   263,   265,   267,   269,    59,
     217,    88,   218,    61,   238,    12,    13,    99,   100,    12,
      13,   153,   154,    75,    24,   299,    25,   354,    59,   373,
     374,   375,    59,   355,    89,   129,   117,   338,   148,   298,
     158,   360,    91,   341,   220,   367,   159,    24,   215,    25,
     216,    12,    13,   376,   160,   320,   162,   217,   219,   218,
     367,    12,    13,     3,     4,     5,     3,     4,     5,   319,
      12,    13,   387,   388,   389,   392,   395,   164,     3,     4,
       5,   165,   166,   187,   212,   369,   188,   211,   189,   190,
     191,   192,     6,    56,    57,     6,    59,    95,   322,   350,
     224,   411,   414,   416,   417,   150,   220,     6,    97,    24,
     215,    25,   216,   225,   226,   420,   421,   322,   228,   229,
     219,   230,   231,    24,   232,    25,   206,   207,   208,   235,
     239,   240,   209,     1,   129,   210,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   275,   293,   245,   209,
     301,   300,   210,   220,   362,   302,    24,   215,    25,   216,
     307,   313,   272,   314,   310,   315,   330,   219,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   331,   294,   332,   391,   394,   397,
     361,   333,   349,   336,   368,   203,   204,   205,   206,   207,
     208,   305,   346,   306,   209,   308,   309,   210,   347,   368,
     312,   356,   357,   371,   316,   377,   372,   378,   383,   384,
     385,   386,   402,   390,   393,   396,   403,    41,   323,   324,
     325,   326,   327,   328,    40,   406,   407,     1,   418,     2,
       3,     4,     5,   419,   186,     0,     0,     0,     1,   104,
     412,   415,    -1,   204,   205,   206,   207,   208,     0,     0,
     104,   209,     0,     0,   210,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,     0,     0,     0,   105,   106,
       0,     0,     0,     0,    10,    11,     0,   167,   345,   105,
     106,   168,   169,   170,   171,   172,     0,     0,    12,    13,
     173,     0,     0,     0,     0,     0,   351,   272,   272,     1,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
       0,   364,   365,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,    14,
       1,   115,     0,   116,     0,   113,   114,     0,    59,     0,
     366,     0,   115,     0,   116,     0,     0,     0,   398,   399,
     272,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,   272,   253,
     254,   255,   256,   257,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,     0,     0,   209,     0,     0,   210,     0,     0,     0,
       0,    14,     0,   258,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,   209,     1,     0,   210,     3,     4,
       5,     0,    14,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     3,     4,     5,     0,     0,     0,     0,   119,
       0,     0,   120,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,   119,     0,     0,   120,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    12,    13,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,     0,     0,     0,   119,
       0,     0,   120,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,     0,     0,     0,   121,    14,     1,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
     214,    14,     0,     0,     0,     1,    12,    13,     3,     4,
       5,     0,   119,     0,     0,   120,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,     0,     0,   119,
       0,     0,   120,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,     0,     0,     0,   233,    14,     1,    12,
      13,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,   119,     0,     0,   120,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,     0,     0,   295,
      14,     1,     0,     0,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   311,    14,     1,    12,
      13,     3,     4,     5,     0,   119,     0,     0,   120,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,     0,
       1,   104,   119,     0,     0,   120,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,     0,     0,   335,
      14,     0,    12,    13,     0,     0,     0,     0,     0,     0,
     105,   106,     0,     0,     0,     0,     0,     0,     0,    12,
      13,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,     0,     0,     0,   209,     0,
       0,   210,   342,    14,   107,   108,   109,   110,   111,   112,
       0,     1,     0,     2,     3,     4,     5,     0,     0,   359,
      14,     0,     0,   104,     0,     0,   113,   114,     0,     0,
       0,     0,     0,   115,     0,   116,     0,     0,     0,     0,
       0,     0,    14,     6,     7,     8,     9,    10,    11,     0,
       0,     0,   105,   106,     0,     0,     0,     0,    10,    11,
       0,   167,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,    12,    13,   173,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,   113,   114,
       0,    10,    11,    14,   167,   115,     0,   116,   168,   169,
     170,   171,   172,   185,    64,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   107,
     108,   109,   110,   111,   112,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   113,   114,     0,   209,   105,   106,   210,   115,     0,
     116,    10,    11,     0,   167,    59,     0,    14,   168,   169,
     170,   171,   172,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   107,
     108,   109,   110,   111,   112,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   113,   114,     0,   209,   105,   106,   210,   115,     0,
     116,    10,    11,     0,   167,    59,     0,   366,   168,   169,
     170,   171,   172,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,   105,   106,     0,   115,     0,
     116,    10,    11,     0,   167,    59,     0,   410,   168,   169,
     170,   171,   172,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,   105,   106,     0,   115,     0,
     116,    10,    11,     0,   167,    59,     0,   413,   168,   169,
     170,   171,   172,     0,     0,     0,     0,   173,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,   113,   114,     0,    10,    11,     0,   167,   115,     0,
     116,   168,   169,   170,   171,   172,   174,     0,     0,     0,
     173,     0,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,   113,   114,     0,    10,    11,     0,
     167,   115,     0,   116,   168,   169,   170,   171,   172,   321,
       0,     0,     0,   173,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,     0,   113,   114,     0,
      10,    11,     0,   167,   115,     0,   116,   168,   236,   170,
     171,   172,   329,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,    20,     0,     0,     0,     0,     0,
       0,    30,    33,     0,     0,     0,     0,     0,     0,    20,
     113,   114,     0,     0,     0,    58,     0,   115,     0,   116,
       0,     0,     0,    67,    59,    72,    73,     0,    78,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,     0,     0,   209,
      96,    98,   210,   334,     0,     0,     0,     0,     0,     0,
       0,     0,   132,     0,     0,   135,     0,     0,   138,     0,
       0,   141,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   161,
       0,   163,   209,     0,   276,   210,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,     0,     0,   209,     0,   344,   210,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,     0,     0,     0,   209,     0,
     348,   210,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,     0,
       0,   209,     0,   363,   210,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,   209,     0,   381,   210,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,     0,     0,   209,     0,   382,
     210,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     0,     0,     0,
     209,     0,   404,   210,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,     0,     0,   209,     0,   405,   210
};

static const yytype_int16 yycheck[] =
{
       0,   225,   177,     0,     0,     0,     0,   120,    37,    83,
      39,   186,    19,   154,     0,    15,    19,    17,    15,    15,
      15,    15,    19,   212,    19,    43,   122,     3,   122,    15,
       5,    17,     0,    87,     4,     7,     8,     4,     4,     4,
      97,     4,    42,   100,     6,     7,     8,    15,    20,     6,
       7,     8,   106,   102,   103,   168,    42,    29,    30,    59,
      32,    33,     3,    38,    39,    40,   105,    27,    98,    66,
     211,    66,     4,    35,   148,    37,    36,    37,    35,    36,
      66,    53,    54,     6,     7,     8,   102,   105,   102,    99,
     332,   333,     6,     7,     8,    67,   106,    69,   103,     4,
     105,    73,   107,    75,    64,    65,    99,    64,    65,    36,
      37,   300,    35,   106,    37,     4,   340,    89,    37,    91,
     127,    35,   122,   123,   127,   122,   122,   122,   122,   105,
     127,    98,   127,    98,    37,    98,   122,   123,   234,    37,
     234,    64,    65,   385,   386,     6,     7,     8,    99,    36,
      64,    65,    38,    39,    40,   106,   128,   154,    36,   154,
     402,   403,     6,     7,     8,     4,    64,    65,   154,   310,
      37,   171,   172,   173,    35,   175,   176,    36,    37,   179,
     180,   181,   182,   183,   184,   171,   172,   173,   363,   175,
     176,    35,    36,   179,   180,   181,   182,   183,   184,   103,
     296,   105,   296,   107,   168,    64,    65,    36,    37,    64,
      65,   102,   103,    36,   211,   215,   211,   102,   103,    33,
      34,   102,   103,   336,    37,   211,    61,   301,   102,   215,
      36,   344,    36,   307,   234,   348,    37,   234,   234,   234,
     234,    64,    65,   356,    36,   245,    37,   343,   234,   343,
     363,    64,    65,     6,     7,     8,     6,     7,     8,   245,
      64,    65,    33,    34,   377,   378,   379,    36,     6,     7,
       8,    37,    36,    98,    98,   349,    97,   103,   113,   114,
     115,   116,    35,    36,    37,    35,   103,    37,   252,   318,
      99,   404,   405,   406,   407,   106,   296,    35,    36,   296,
     296,   296,   296,    86,   107,   418,   419,   271,   107,     4,
     296,   107,   107,   310,     4,   310,    91,    92,    93,    98,
      98,    98,    97,     3,   310,   100,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     4,     4,   173,    97,
     102,    98,   100,   343,   344,     4,   343,   343,   343,   343,
     102,    98,   187,    47,   103,    47,    99,   343,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   106,   210,    98,   377,   378,   379,
     344,    98,   102,    99,   348,    88,    89,    90,    91,    92,
      93,   226,    98,   228,    97,   230,   231,   100,    98,   363,
     235,    99,     4,    99,   239,    43,    99,    43,    52,    52,
      98,    98,    98,   377,   378,   379,    98,    15,   253,   254,
     255,   256,   257,   258,     0,    99,    99,     3,    99,     5,
       6,     7,     8,    99,   103,    -1,    -1,    -1,     3,     4,
     404,   405,    88,    89,    90,    91,    92,    93,    -1,    -1,
       4,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    39,    40,    -1,    42,   313,    33,
      34,    46,    47,    48,    49,    50,    -1,    -1,    64,    65,
      55,    -1,    -1,    -1,    -1,    -1,   331,   332,   333,     3,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,   346,   347,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,   105,
       3,    96,    -1,    98,    -1,    89,    90,    -1,   103,    -1,
     105,    -1,    96,    -1,    98,    -1,    -1,    -1,   383,   384,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,   403,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,     3,    -1,   100,     6,     7,
       8,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    64,    65,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,   104,   105,     3,    -1,
      -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,    -1,    -1,    -1,     3,    64,    65,     6,     7,
       8,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,   104,   105,     3,    64,
      65,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,   104,
     105,     3,    -1,    -1,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,     3,    64,
      65,     6,     7,     8,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    -1,
       3,     4,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,   104,
     105,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,   104,   105,    67,    68,    69,    70,    71,    72,
      -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,   104,
     105,    -1,    -1,     4,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    64,    65,    55,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    89,    90,
      -1,    39,    40,   105,    42,    96,    -1,    98,    46,    47,
      48,    49,    50,   104,   105,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    67,
      68,    69,    70,    71,    72,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    89,    90,    -1,    97,    33,    34,   100,    96,    -1,
      98,    39,    40,    -1,    42,   103,    -1,   105,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    89,    90,    -1,    97,    33,    34,   100,    96,    -1,
      98,    39,    40,    -1,    42,   103,    -1,   105,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    -1,    33,    34,    -1,    96,    -1,
      98,    39,    40,    -1,    42,   103,    -1,   105,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    -1,    33,    34,    -1,    96,    -1,
      98,    39,    40,    -1,    42,   103,    -1,   105,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    89,    90,    -1,    39,    40,    -1,    42,    96,    -1,
      98,    46,    47,    48,    49,    50,   104,    -1,    -1,    -1,
      55,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    89,    90,    -1,    39,    40,    -1,
      42,    96,    -1,    98,    46,    47,    48,    49,    50,   104,
      -1,    -1,    -1,    55,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    89,    90,    -1,
      39,    40,    -1,    42,    96,    -1,    98,    46,    47,    48,
      49,    50,   104,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     0,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      89,    90,    -1,    -1,    -1,    21,    -1,    96,    -1,    98,
      -1,    -1,    -1,    29,   103,    31,    32,    -1,    34,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      56,    57,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    95,
      -1,    97,    97,    -1,    99,   100,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    97,    -1,    99,   100,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      99,   100,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    99,   100,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    99,   100,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    99,
     100,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    99,   100,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    99,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    35,    36,    37,    38,
      39,    40,    64,    65,   105,   109,   110,   112,   113,   118,
     119,   120,   121,   122,   124,   125,   140,   141,     4,    37,
     119,   120,    36,   119,   120,     4,     4,    98,     4,    98,
       0,   110,   112,   113,   140,   141,   140,   141,     5,   121,
     122,   124,   125,    36,    37,   120,    36,    37,   119,   103,
     105,   107,   123,     3,   105,   102,   103,   119,   120,    37,
     120,    37,   119,   119,   120,    36,   120,    36,   119,    98,
     102,     4,   117,   102,   117,   140,   141,     4,   105,    37,
     120,    36,   120,    36,    37,    37,   119,    36,   119,    36,
      37,   139,   140,   141,     4,    33,    34,    67,    68,    69,
      70,    71,    72,    89,    90,    96,    98,   131,     4,    27,
      30,   104,   111,   112,   113,   114,   115,   118,   119,   140,
     141,   120,   119,   120,    37,   119,    37,   120,   119,   120,
      36,   119,    36,   116,   117,     4,   126,   127,   102,    99,
     106,   126,    99,   102,   103,   120,    37,   120,    36,    37,
      36,   119,    37,   119,    36,    37,    36,    42,    46,    47,
      48,    49,    50,    55,   104,   124,   125,   129,   130,   131,
     134,   135,   136,   137,   138,   104,   129,    98,    97,   131,
     131,   131,   131,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    97,
     100,   103,    98,   123,   104,   112,   113,   114,   115,   140,
     141,   140,   141,    27,    99,    86,   107,   126,   107,     4,
     107,   107,     4,   104,   111,    98,    47,   123,   130,    98,
      98,   140,   141,   140,   141,   131,   140,   141,   140,   141,
     140,   141,   139,    73,    74,    75,    76,    77,   107,   140,
     141,   140,   141,   140,   141,   140,   141,   140,   141,   140,
     141,   139,   131,   132,   133,     4,    99,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,     4,   131,   104,   111,   116,   140,   141,
      98,   102,     4,   127,   128,   131,   131,   102,   131,   131,
     103,   104,   131,    98,    47,    47,   131,     4,    98,   140,
     141,   104,   130,   131,   131,   131,   131,   131,   131,   104,
      99,   106,    98,    98,   101,   104,    99,   116,   126,    87,
     106,   126,   104,   111,    99,   131,    98,    98,    99,   102,
     117,   131,   132,   132,   102,   123,    99,     4,   127,   104,
     123,   130,   141,    99,   131,   131,   105,   123,   130,   126,
      99,    99,    99,    33,    34,   102,   123,    43,    43,    43,
     139,    99,    99,    52,    52,    98,    98,    33,    34,   123,
     130,   141,   123,   130,   141,   123,   130,   141,   131,   131,
     132,   132,    98,    98,    99,    99,    99,    99,   132,   132,
     105,   123,   130,   105,   123,   130,   123,   123,    99,    99,
     123,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   123,   123,   123,   123,   124,   124,
     124,   125,   125,   125,   126,   126,   127,   128,   128,   128,
     128,   129,   129,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   139,   139,   140,   140,   141,
     141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     2,     2,     8,     6,     7,     5,     7,     5,
       6,     4,     1,     1,     1,     2,     2,     1,     1,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     2,     2,     1,     2,     6,     5,    10,    10,    11,
      11,     5,     4,     9,     9,    10,    10,     0,     1,     3,
       5,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     2,     3,     7,     5,     5,     3,     3,     4,     6,
       6,     4,     6,     6,     1,     1,     4,     1,     1,     3,
       3,     1,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     4,     3,     6,
       3,     0,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     5,     5,     5,     6,     6,     6,     9,     9,     9,
       9,     9,     9,     5,     5,     5,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     0,     1,     1,     2,     1,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: semis  */
#line 313 "synt_analyzer.y"
                {root = createProgram(); puts("program created");}
#line 2176 "synt_analyzer.tab.cpp"
    break;

  case 3: /* program: newLines  */
#line 314 "synt_analyzer.y"
                {root = createProgram();puts("program created");}
#line 2182 "synt_analyzer.tab.cpp"
    break;

  case 4: /* program: class  */
#line 315 "synt_analyzer.y"
        {root = createProgram((yyvsp[0].classU));puts("program created");}
#line 2188 "synt_analyzer.tab.cpp"
    break;

  case 5: /* program: method  */
#line 316 "synt_analyzer.y"
                {root = createProgram((yyvsp[0].methodU));puts("program created");}
#line 2194 "synt_analyzer.tab.cpp"
    break;

  case 6: /* program: property semis  */
#line 317 "synt_analyzer.y"
                        {root = createProgram((yyvsp[-1].propertyU));puts("program created");}
#line 2200 "synt_analyzer.tab.cpp"
    break;

  case 7: /* program: property newLines  */
#line 318 "synt_analyzer.y"
                        {root = createProgram((yyvsp[-1].propertyU));puts("program created");}
#line 2206 "synt_analyzer.tab.cpp"
    break;

  case 8: /* program: program class  */
#line 319 "synt_analyzer.y"
                {(yyval.programU) = addToProgram((yyvsp[-1].programU), (yyvsp[0].classU));puts("class added to prog");}
#line 2212 "synt_analyzer.tab.cpp"
    break;

  case 9: /* program: program method  */
#line 320 "synt_analyzer.y"
                        {(yyval.programU) = addToProgram((yyvsp[-1].programU), (yyvsp[0].methodU));puts("meth added to prog");}
#line 2218 "synt_analyzer.tab.cpp"
    break;

  case 10: /* program: program property semis  */
#line 321 "synt_analyzer.y"
                                {(yyval.programU) = addToProgram((yyvsp[-2].programU), (yyvsp[-1].propertyU));puts("prop added to prog");}
#line 2224 "synt_analyzer.tab.cpp"
    break;

  case 11: /* program: program property newLines  */
#line 322 "synt_analyzer.y"
                                {(yyval.programU) = addToProgram((yyvsp[-2].programU), (yyvsp[-1].propertyU));puts("prop added to prog");}
#line 2230 "synt_analyzer.tab.cpp"
    break;

  case 12: /* program: program newLines  */
#line 323 "synt_analyzer.y"
                   {(yyval.programU) = (yyvsp[-1].programU);puts("new lines added to prog");}
#line 2236 "synt_analyzer.tab.cpp"
    break;

  case 13: /* program: program semis  */
#line 324 "synt_analyzer.y"
                {(yyval.programU) = (yyvsp[-1].programU);puts("semis added to prog");}
#line 2242 "synt_analyzer.tab.cpp"
    break;

  case 14: /* class: modifiers CLASS ID ':' ID '{' classBody '}'  */
#line 327 "synt_analyzer.y"
                                                        {(yyval.classU) = createClass((yyvsp[-7].modifiersU), (yyvsp[-5].Id), (yyvsp[-3].Id), (yyvsp[-1].classBodyU));puts("class created");}
#line 2248 "synt_analyzer.tab.cpp"
    break;

  case 15: /* class: modifiers CLASS ID '{' classBody '}'  */
#line 328 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].modifiersU), (yyvsp[-3].Id), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2254 "synt_analyzer.tab.cpp"
    break;

  case 16: /* class: CLASS ID ':' ID '{' classBody '}'  */
#line 329 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].Id), (yyvsp[-3].Id), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2260 "synt_analyzer.tab.cpp"
    break;

  case 17: /* class: CLASS ID '{' classBody '}'  */
#line 330 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-3].Id), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2266 "synt_analyzer.tab.cpp"
    break;

  case 18: /* class: modifiers CLASS ID ':' ID '{' '}'  */
#line 331 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-6].modifiersU), (yyvsp[-4].Id), (yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2272 "synt_analyzer.tab.cpp"
    break;

  case 19: /* class: modifiers CLASS ID '{' '}'  */
#line 332 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].modifiersU), (yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2278 "synt_analyzer.tab.cpp"
    break;

  case 20: /* class: CLASS ID ':' ID '{' '}'  */
#line 333 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].Id), (yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2284 "synt_analyzer.tab.cpp"
    break;

  case 21: /* class: CLASS ID '{' '}'  */
#line 334 "synt_analyzer.y"
                        {(yyval.classU) = createClass((yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2290 "synt_analyzer.tab.cpp"
    break;

  case 22: /* classBody: semis  */
#line 337 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2296 "synt_analyzer.tab.cpp"
    break;

  case 23: /* classBody: newLines  */
#line 338 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody();  puts("class body created");}
#line 2302 "synt_analyzer.tab.cpp"
    break;

  case 24: /* classBody: method  */
#line 339 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].methodU));  puts("class body created");}
#line 2308 "synt_analyzer.tab.cpp"
    break;

  case 25: /* classBody: property semis  */
#line 340 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2314 "synt_analyzer.tab.cpp"
    break;

  case 26: /* classBody: property newLines  */
#line 341 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2320 "synt_analyzer.tab.cpp"
    break;

  case 27: /* classBody: constructor  */
#line 342 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].constructorU));  puts("class body created");}
#line 2326 "synt_analyzer.tab.cpp"
    break;

  case 28: /* classBody: initializer  */
#line 343 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].initializerU));  puts("class body created");}
#line 2332 "synt_analyzer.tab.cpp"
    break;

  case 29: /* classBody: classBody method  */
#line 344 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].methodU));  puts("meth added to class body");}
#line 2338 "synt_analyzer.tab.cpp"
    break;

  case 30: /* classBody: classBody property semis  */
#line 345 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2344 "synt_analyzer.tab.cpp"
    break;

  case 31: /* classBody: classBody property newLines  */
#line 346 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2350 "synt_analyzer.tab.cpp"
    break;

  case 32: /* classBody: classBody newLines  */
#line 347 "synt_analyzer.y"
                         {(yyval.classBodyU) = (yyvsp[-1].classBodyU); puts("new lines added to class body");}
#line 2356 "synt_analyzer.tab.cpp"
    break;

  case 33: /* classBody: classBody constructor  */
#line 348 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].constructorU)); puts("constr added to class body");}
#line 2362 "synt_analyzer.tab.cpp"
    break;

  case 34: /* classBody: classBody initializer  */
#line 349 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].initializerU)); puts("init added to class body");}
#line 2368 "synt_analyzer.tab.cpp"
    break;

  case 35: /* classBody: classBody semis  */
#line 350 "synt_analyzer.y"
                        {(yyval.classBodyU) = (yyvsp[-1].classBodyU); puts("semis added to class body");}
#line 2374 "synt_analyzer.tab.cpp"
    break;

  case 36: /* property: modifiers valDeclaration  */
#line 353 "synt_analyzer.y"
                                        {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2380 "synt_analyzer.tab.cpp"
    break;

  case 37: /* property: modifiers varDeclaration  */
#line 354 "synt_analyzer.y"
                                {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2386 "synt_analyzer.tab.cpp"
    break;

  case 38: /* property: valDeclaration  */
#line 355 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2392 "synt_analyzer.tab.cpp"
    break;

  case 39: /* property: varDeclaration  */
#line 356 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2398 "synt_analyzer.tab.cpp"
    break;

  case 40: /* method: modifiers funcDeclaration ';'  */
#line 359 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2404 "synt_analyzer.tab.cpp"
    break;

  case 41: /* method: modifiers func  */
#line 360 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].modifiersU), (yyvsp[0].funcU)); puts("meth created");}
#line 2410 "synt_analyzer.tab.cpp"
    break;

  case 42: /* method: funcDeclaration ';'  */
#line 361 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2416 "synt_analyzer.tab.cpp"
    break;

  case 43: /* method: func  */
#line 362 "synt_analyzer.y"
        {(yyval.methodU) = createMethod((yyvsp[0].funcU)); puts("meth created");}
#line 2422 "synt_analyzer.tab.cpp"
    break;

  case 44: /* initializer: INIT block  */
#line 365 "synt_analyzer.y"
                        {(yyval.initializerU) = createInit((yyvsp[0].stmtListU)); puts("init created");}
#line 2428 "synt_analyzer.tab.cpp"
    break;

  case 45: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' block  */
#line 369 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-5].visibilityModU), (yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2434 "synt_analyzer.tab.cpp"
    break;

  case 46: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')'  */
#line 370 "synt_analyzer.y"
                                                                {(yyval.constructorU) = createConstructor((yyvsp[-4].visibilityModU), (yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2440 "synt_analyzer.tab.cpp"
    break;

  case 47: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 371 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2446 "synt_analyzer.tab.cpp"
    break;

  case 48: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 372 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2452 "synt_analyzer.tab.cpp"
    break;

  case 49: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 373 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2458 "synt_analyzer.tab.cpp"
    break;

  case 50: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 374 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2464 "synt_analyzer.tab.cpp"
    break;

  case 51: /* constructor: CONSTRUCTOR '(' optFormalParams ')' block  */
#line 375 "synt_analyzer.y"
                                                {(yyval.constructorU) = createConstructor((yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2470 "synt_analyzer.tab.cpp"
    break;

  case 52: /* constructor: CONSTRUCTOR '(' optFormalParams ')'  */
#line 376 "synt_analyzer.y"
                                        {(yyval.constructorU) = createConstructor((yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2476 "synt_analyzer.tab.cpp"
    break;

  case 53: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 377 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2482 "synt_analyzer.tab.cpp"
    break;

  case 54: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 378 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2488 "synt_analyzer.tab.cpp"
    break;

  case 55: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 379 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2494 "synt_analyzer.tab.cpp"
    break;

  case 56: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 380 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2500 "synt_analyzer.tab.cpp"
    break;

  case 57: /* optFormalParams: %empty  */
#line 383 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = 0; puts("opt formal params created");}
#line 2506 "synt_analyzer.tab.cpp"
    break;

  case 58: /* optFormalParams: formalParams  */
#line 384 "synt_analyzer.y"
                {(yyval.formalParamsListU) = (yyvsp[0].formalParamsListU); puts("opt formal params created");}
#line 2512 "synt_analyzer.tab.cpp"
    break;

  case 59: /* formalParams: ID ':' type  */
#line 387 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = createFormalParamsList((yyvsp[-2].Id), (yyvsp[0].typeU)); puts("formal params created");}
#line 2518 "synt_analyzer.tab.cpp"
    break;

  case 60: /* formalParams: formalParams ',' ID ':' type  */
#line 388 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = addToFormalParamsList((yyvsp[-4].formalParamsListU), (yyvsp[-2].Id), (yyvsp[0].typeU)); puts("formal params created");}
#line 2524 "synt_analyzer.tab.cpp"
    break;

  case 61: /* modifiers: OVERRIDE  */
#line 391 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, None); puts("mods created");}
#line 2530 "synt_analyzer.tab.cpp"
    break;

  case 62: /* modifiers: visibilityModifier  */
#line 392 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2536 "synt_analyzer.tab.cpp"
    break;

  case 63: /* modifiers: inheritanceModifier  */
#line 393 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2542 "synt_analyzer.tab.cpp"
    break;

  case 64: /* modifiers: ABSTRACT  */
#line 394 "synt_analyzer.y"
                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, None); puts("mods created");}
#line 2548 "synt_analyzer.tab.cpp"
    break;

  case 65: /* modifiers: OVERRIDE visibilityModifier  */
#line 395 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2554 "synt_analyzer.tab.cpp"
    break;

  case 66: /* modifiers: OVERRIDE inheritanceModifier  */
#line 396 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2560 "synt_analyzer.tab.cpp"
    break;

  case 67: /* modifiers: OVERRIDE ABSTRACT  */
#line 397 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2566 "synt_analyzer.tab.cpp"
    break;

  case 68: /* modifiers: visibilityModifier OVERRIDE  */
#line 398 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2572 "synt_analyzer.tab.cpp"
    break;

  case 69: /* modifiers: visibilityModifier inheritanceModifier  */
#line 399 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2578 "synt_analyzer.tab.cpp"
    break;

  case 70: /* modifiers: visibilityModifier ABSTRACT  */
#line 400 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2584 "synt_analyzer.tab.cpp"
    break;

  case 71: /* modifiers: inheritanceModifier OVERRIDE  */
#line 401 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2590 "synt_analyzer.tab.cpp"
    break;

  case 72: /* modifiers: inheritanceModifier visibilityModifier  */
#line 402 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2596 "synt_analyzer.tab.cpp"
    break;

  case 73: /* modifiers: inheritanceModifier ABSTRACT  */
#line 403 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2602 "synt_analyzer.tab.cpp"
    break;

  case 74: /* modifiers: ABSTRACT OVERRIDE  */
#line 404 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2608 "synt_analyzer.tab.cpp"
    break;

  case 75: /* modifiers: ABSTRACT visibilityModifier  */
#line 405 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2614 "synt_analyzer.tab.cpp"
    break;

  case 76: /* modifiers: ABSTRACT inheritanceModifier  */
#line 406 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2620 "synt_analyzer.tab.cpp"
    break;

  case 77: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier  */
#line 407 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2626 "synt_analyzer.tab.cpp"
    break;

  case 78: /* modifiers: OVERRIDE visibilityModifier ABSTRACT  */
#line 408 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2632 "synt_analyzer.tab.cpp"
    break;

  case 79: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier  */
#line 409 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2638 "synt_analyzer.tab.cpp"
    break;

  case 80: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT  */
#line 410 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2644 "synt_analyzer.tab.cpp"
    break;

  case 81: /* modifiers: OVERRIDE ABSTRACT visibilityModifier  */
#line 411 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2650 "synt_analyzer.tab.cpp"
    break;

  case 82: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier  */
#line 412 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2656 "synt_analyzer.tab.cpp"
    break;

  case 83: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier  */
#line 413 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2662 "synt_analyzer.tab.cpp"
    break;

  case 84: /* modifiers: visibilityModifier OVERRIDE ABSTRACT  */
#line 414 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2668 "synt_analyzer.tab.cpp"
    break;

  case 85: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE  */
#line 415 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2674 "synt_analyzer.tab.cpp"
    break;

  case 86: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT  */
#line 416 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2680 "synt_analyzer.tab.cpp"
    break;

  case 87: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier  */
#line 417 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2686 "synt_analyzer.tab.cpp"
    break;

  case 88: /* modifiers: visibilityModifier ABSTRACT OVERRIDE  */
#line 418 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2692 "synt_analyzer.tab.cpp"
    break;

  case 89: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier  */
#line 419 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2698 "synt_analyzer.tab.cpp"
    break;

  case 90: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT  */
#line 420 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2704 "synt_analyzer.tab.cpp"
    break;

  case 91: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT  */
#line 421 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2710 "synt_analyzer.tab.cpp"
    break;

  case 92: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE  */
#line 422 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2716 "synt_analyzer.tab.cpp"
    break;

  case 93: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier  */
#line 423 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2722 "synt_analyzer.tab.cpp"
    break;

  case 94: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE  */
#line 424 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2728 "synt_analyzer.tab.cpp"
    break;

  case 95: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier  */
#line 425 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2734 "synt_analyzer.tab.cpp"
    break;

  case 96: /* modifiers: ABSTRACT OVERRIDE visibilityModifier  */
#line 426 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2740 "synt_analyzer.tab.cpp"
    break;

  case 97: /* modifiers: ABSTRACT visibilityModifier OVERRIDE  */
#line 427 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2746 "synt_analyzer.tab.cpp"
    break;

  case 98: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier  */
#line 428 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2752 "synt_analyzer.tab.cpp"
    break;

  case 99: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE  */
#line 429 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2758 "synt_analyzer.tab.cpp"
    break;

  case 100: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier  */
#line 430 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2764 "synt_analyzer.tab.cpp"
    break;

  case 101: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier ABSTRACT  */
#line 431 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2770 "synt_analyzer.tab.cpp"
    break;

  case 102: /* modifiers: OVERRIDE visibilityModifier ABSTRACT inheritanceModifier  */
#line 432 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2776 "synt_analyzer.tab.cpp"
    break;

  case 103: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier ABSTRACT  */
#line 433 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2782 "synt_analyzer.tab.cpp"
    break;

  case 104: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT visibilityModifier  */
#line 434 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2788 "synt_analyzer.tab.cpp"
    break;

  case 105: /* modifiers: OVERRIDE ABSTRACT visibilityModifier inheritanceModifier  */
#line 435 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2794 "synt_analyzer.tab.cpp"
    break;

  case 106: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier visibilityModifier  */
#line 436 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2800 "synt_analyzer.tab.cpp"
    break;

  case 107: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier ABSTRACT  */
#line 437 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2806 "synt_analyzer.tab.cpp"
    break;

  case 108: /* modifiers: visibilityModifier OVERRIDE ABSTRACT inheritanceModifier  */
#line 438 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2812 "synt_analyzer.tab.cpp"
    break;

  case 109: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE ABSTRACT  */
#line 439 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2818 "synt_analyzer.tab.cpp"
    break;

  case 110: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT OVERRIDE  */
#line 440 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2824 "synt_analyzer.tab.cpp"
    break;

  case 111: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier OVERRIDE  */
#line 441 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2830 "synt_analyzer.tab.cpp"
    break;

  case 112: /* modifiers: visibilityModifier ABSTRACT OVERRIDE inheritanceModifier  */
#line 442 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2836 "synt_analyzer.tab.cpp"
    break;

  case 113: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier ABSTRACT  */
#line 443 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2842 "synt_analyzer.tab.cpp"
    break;

  case 114: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT visibilityModifier  */
#line 444 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2848 "synt_analyzer.tab.cpp"
    break;

  case 115: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT OVERRIDE  */
#line 446 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2854 "synt_analyzer.tab.cpp"
    break;

  case 116: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE ABSTRACT  */
#line 448 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2860 "synt_analyzer.tab.cpp"
    break;

  case 117: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier OVERRIDE  */
#line 450 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2866 "synt_analyzer.tab.cpp"
    break;

  case 118: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE visibilityModifier  */
#line 452 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2872 "synt_analyzer.tab.cpp"
    break;

  case 119: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier visibilityModifier  */
#line 454 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2878 "synt_analyzer.tab.cpp"
    break;

  case 120: /* modifiers: ABSTRACT OVERRIDE visibilityModifier inheritanceModifier  */
#line 456 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2884 "synt_analyzer.tab.cpp"
    break;

  case 121: /* modifiers: ABSTRACT visibilityModifier OVERRIDE inheritanceModifier  */
#line 457 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2890 "synt_analyzer.tab.cpp"
    break;

  case 122: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier OVERRIDE  */
#line 458 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2896 "synt_analyzer.tab.cpp"
    break;

  case 123: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE visibilityModifier  */
#line 460 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2902 "synt_analyzer.tab.cpp"
    break;

  case 124: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier OVERRIDE  */
#line 462 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2908 "synt_analyzer.tab.cpp"
    break;

  case 125: /* visibilityModifier: PUBLIC  */
#line 465 "synt_analyzer.y"
                                {(yyval.visibilityModU) = Public;}
#line 2914 "synt_analyzer.tab.cpp"
    break;

  case 126: /* visibilityModifier: PRIVATE  */
#line 466 "synt_analyzer.y"
                {(yyval.visibilityModU) = Private;}
#line 2920 "synt_analyzer.tab.cpp"
    break;

  case 127: /* visibilityModifier: INTERNAL  */
#line 467 "synt_analyzer.y"
                {(yyval.visibilityModU) = Internal;}
#line 2926 "synt_analyzer.tab.cpp"
    break;

  case 128: /* visibilityModifier: PROTECTED  */
#line 468 "synt_analyzer.y"
                {(yyval.visibilityModU) = Protected;}
#line 2932 "synt_analyzer.tab.cpp"
    break;

  case 129: /* inheritanceModifier: FINAL  */
#line 472 "synt_analyzer.y"
                           {(yyval.inheritanceModU) = Final;}
#line 2938 "synt_analyzer.tab.cpp"
    break;

  case 130: /* inheritanceModifier: OPEN  */
#line 473 "synt_analyzer.y"
       {(yyval.inheritanceModU) = Open;}
#line 2944 "synt_analyzer.tab.cpp"
    break;

  case 131: /* func: funcDeclaration block  */
#line 476 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-1].funcDeclU), (yyvsp[0].stmtListU)); puts("func created");}
#line 2950 "synt_analyzer.tab.cpp"
    break;

  case 132: /* func: funcDeclaration '=' expr  */
#line 477 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-2].funcDeclU), (yyvsp[0].exprU)); puts("func created");}
#line 2956 "synt_analyzer.tab.cpp"
    break;

  case 133: /* funcDeclaration: FUN ID '(' optFormalParams ')' ':' type  */
#line 481 "synt_analyzer.y"
                                                                {(yyval.funcDeclU) = createFuncDecl((yyvsp[-5].Id), (yyvsp[-3].formalParamsListU), (yyvsp[0].typeU));  puts("func decl created");}
#line 2962 "synt_analyzer.tab.cpp"
    break;

  case 134: /* block: '{' optNewLines stmts optNewLines '}'  */
#line 485 "synt_analyzer.y"
                                                {(yyval.stmtListU) = (yyvsp[-2].stmtListU);  puts("block created");}
#line 2968 "synt_analyzer.tab.cpp"
    break;

  case 135: /* block: '{' semis stmts optNewLines '}'  */
#line 486 "synt_analyzer.y"
                                        {(yyval.stmtListU) = (yyvsp[-2].stmtListU);  puts("block created");}
#line 2974 "synt_analyzer.tab.cpp"
    break;

  case 136: /* block: '{' semis '}'  */
#line 487 "synt_analyzer.y"
                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2980 "synt_analyzer.tab.cpp"
    break;

  case 137: /* block: '{' optNewLines '}'  */
#line 488 "synt_analyzer.y"
                        {(yyval.stmtListU) = 0;  puts("block created");}
#line 2986 "synt_analyzer.tab.cpp"
    break;

  case 138: /* varDeclaration: VAR ID ':' type  */
#line 492 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].Id), (yyvsp[0].typeU), 0); puts("val created");}
#line 2992 "synt_analyzer.tab.cpp"
    break;

  case 139: /* varDeclaration: VAR ID ':' type '=' expr  */
#line 493 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].Id), (yyvsp[-2].typeU), (yyvsp[0].exprU), 0); puts("val created");}
#line 2998 "synt_analyzer.tab.cpp"
    break;

  case 140: /* varDeclaration: VAR '(' formalParams ')' '=' expr  */
#line 494 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 0); puts("val created"); }
#line 3004 "synt_analyzer.tab.cpp"
    break;

  case 141: /* valDeclaration: VAL ID ':' type  */
#line 498 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].Id), (yyvsp[0].typeU), 1); puts("var created"); }
#line 3010 "synt_analyzer.tab.cpp"
    break;

  case 142: /* valDeclaration: VAL ID ':' type '=' expr  */
#line 499 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].Id), (yyvsp[-2].typeU), (yyvsp[0].exprU), 1); puts("var created"); }
#line 3016 "synt_analyzer.tab.cpp"
    break;

  case 143: /* valDeclaration: VAL '(' formalParams ')' '=' expr  */
#line 500 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 1); puts("var created"); }
#line 3022 "synt_analyzer.tab.cpp"
    break;

  case 144: /* type: ID  */
#line 503 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].Id)); puts("type created"); }
#line 3028 "synt_analyzer.tab.cpp"
    break;

  case 145: /* type: templateType  */
#line 504 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].templateTypeU)); puts("type created"); }
#line 3034 "synt_analyzer.tab.cpp"
    break;

  case 146: /* templateType: ID '<' type_seq '>'  */
#line 507 "synt_analyzer.y"
                                        {(yyval.templateTypeU) = createTemplateType((yyvsp[-3].Id), (yyvsp[-1].typesListU)); puts("template type created"); }
#line 3040 "synt_analyzer.tab.cpp"
    break;

  case 147: /* type_seq: ID  */
#line 510 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].Id)); puts("type seq created"); }
#line 3046 "synt_analyzer.tab.cpp"
    break;

  case 148: /* type_seq: templateType  */
#line 511 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].templateTypeU)); puts("type seq created"); }
#line 3052 "synt_analyzer.tab.cpp"
    break;

  case 149: /* type_seq: type_seq ',' ID  */
#line 512 "synt_analyzer.y"
                        {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].Id));  puts("type seq created"); }
#line 3058 "synt_analyzer.tab.cpp"
    break;

  case 150: /* type_seq: type_seq ',' templateType  */
#line 513 "synt_analyzer.y"
                                {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].templateTypeU));  puts("type seq created"); }
#line 3064 "synt_analyzer.tab.cpp"
    break;

  case 151: /* stmts: stmt  */
#line 516 "synt_analyzer.y"
                {(yyval.stmtListU) = createStmtList((yyvsp[0].stmtU));  puts("stmts created"); }
#line 3070 "synt_analyzer.tab.cpp"
    break;

  case 152: /* stmts: stmts optNewLines stmt  */
#line 517 "synt_analyzer.y"
                                {(yyval.stmtListU) = addToStmtList((yyvsp[-2].stmtListU), (yyvsp[0].stmtU));  puts("stmts created"); }
#line 3076 "synt_analyzer.tab.cpp"
    break;

  case 153: /* stmt: valDeclaration semis  */
#line 520 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3082 "synt_analyzer.tab.cpp"
    break;

  case 154: /* stmt: valDeclaration newLines  */
#line 521 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3088 "synt_analyzer.tab.cpp"
    break;

  case 155: /* stmt: varDeclaration semis  */
#line 522 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3094 "synt_analyzer.tab.cpp"
    break;

  case 156: /* stmt: varDeclaration newLines  */
#line 523 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3100 "synt_analyzer.tab.cpp"
    break;

  case 157: /* stmt: assignment semis  */
#line 524 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 3106 "synt_analyzer.tab.cpp"
    break;

  case 158: /* stmt: assignment newLines  */
#line 525 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 3112 "synt_analyzer.tab.cpp"
    break;

  case 159: /* stmt: whileLoop semis  */
#line 526 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), WhileLoop);  puts("stmt created"); }
#line 3118 "synt_analyzer.tab.cpp"
    break;

  case 160: /* stmt: whileLoop newLines  */
#line 527 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), WhileLoop);  puts("stmt created"); }
#line 3124 "synt_analyzer.tab.cpp"
    break;

  case 161: /* stmt: forLoop semis  */
#line 528 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].forLoopU), ForLoop);  puts("stmt created"); }
#line 3130 "synt_analyzer.tab.cpp"
    break;

  case 162: /* stmt: forLoop newLines  */
#line 529 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].forLoopU), ForLoop);  puts("stmt created"); }
#line 3136 "synt_analyzer.tab.cpp"
    break;

  case 163: /* stmt: doWhileLoop semis  */
#line 530 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 3142 "synt_analyzer.tab.cpp"
    break;

  case 164: /* stmt: doWhileLoop newLines  */
#line 531 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 3148 "synt_analyzer.tab.cpp"
    break;

  case 165: /* stmt: ifStmt semis  */
#line 532 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].ifStmtU), IfStmt);  puts("stmt created"); }
#line 3154 "synt_analyzer.tab.cpp"
    break;

  case 166: /* stmt: ifStmt newLines  */
#line 533 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].ifStmtU), IfStmt);  puts("stmt created"); }
#line 3160 "synt_analyzer.tab.cpp"
    break;

  case 167: /* stmt: expr newLines  */
#line 534 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 3166 "synt_analyzer.tab.cpp"
    break;

  case 168: /* stmt: expr semis  */
#line 535 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 3172 "synt_analyzer.tab.cpp"
    break;

  case 169: /* stmt: BREAK semis  */
#line 536 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 3178 "synt_analyzer.tab.cpp"
    break;

  case 170: /* stmt: BREAK newLines  */
#line 537 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 3184 "synt_analyzer.tab.cpp"
    break;

  case 171: /* stmt: CONTINUE semis  */
#line 538 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 3190 "synt_analyzer.tab.cpp"
    break;

  case 172: /* stmt: CONTINUE newLines  */
#line 539 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 3196 "synt_analyzer.tab.cpp"
    break;

  case 173: /* stmt: RETURN semis  */
#line 540 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 3202 "synt_analyzer.tab.cpp"
    break;

  case 174: /* stmt: RETURN newLines  */
#line 541 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 3208 "synt_analyzer.tab.cpp"
    break;

  case 175: /* stmt: RETURN expr newLines  */
#line 542 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 3214 "synt_analyzer.tab.cpp"
    break;

  case 176: /* stmt: RETURN expr semis  */
#line 543 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 3220 "synt_analyzer.tab.cpp"
    break;

  case 177: /* expr: ID  */
#line 546 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Id), Identificator);  puts("expr created"); }
#line 3226 "synt_analyzer.tab.cpp"
    break;

  case 178: /* expr: THIS  */
#line 547 "synt_analyzer.y"
        {(yyval.exprU) = createExpr(0, This);  puts("expr created"); }
#line 3232 "synt_analyzer.tab.cpp"
    break;

  case 179: /* expr: ID '(' optFactParams ')'  */
#line 548 "synt_analyzer.y"
                                {(yyval.exprU) = createExpr((yyvsp[-3].Id), (yyvsp[-1].factParamsListU), MethodCall);  puts("expr created"); }
#line 3238 "synt_analyzer.tab.cpp"
    break;

  case 180: /* expr: INT  */
#line 549 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Int_v), Int);  puts("expr created"); }
#line 3244 "synt_analyzer.tab.cpp"
    break;

  case 181: /* expr: FLOAT  */
#line 550 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Float_v), Float);  puts("expr created"); }
#line 3250 "synt_analyzer.tab.cpp"
    break;

  case 182: /* expr: STRING  */
#line 551 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].String_v), String);  puts("expr created"); }
#line 3256 "synt_analyzer.tab.cpp"
    break;

  case 183: /* expr: CHAR  */
#line 552 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Char_v), Char);  puts("expr created"); }
#line 3262 "synt_analyzer.tab.cpp"
    break;

  case 184: /* expr: DOUBLE  */
#line 553 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Double_v), Double);  puts("expr created"); }
#line 3268 "synt_analyzer.tab.cpp"
    break;

  case 185: /* expr: BOOLEAN  */
#line 554 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Bool_v), Boolean);  puts("expr created"); }
#line 3274 "synt_analyzer.tab.cpp"
    break;

  case 186: /* expr: '(' expr ')'  */
#line 555 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-1].exprU), ExprInBrackets);  puts("expr created"); }
#line 3280 "synt_analyzer.tab.cpp"
    break;

  case 187: /* expr: '!' expr  */
#line 556 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].exprU), LogicalNot);}
#line 3286 "synt_analyzer.tab.cpp"
    break;

  case 188: /* expr: '+' expr  */
#line 557 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryPlusExpr);  puts("expr created"); }
#line 3292 "synt_analyzer.tab.cpp"
    break;

  case 189: /* expr: '-' expr  */
#line 558 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryMinusExpr);  puts("expr created"); }
#line 3298 "synt_analyzer.tab.cpp"
    break;

  case 190: /* expr: expr '+' expr  */
#line 559 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sum);  puts("expr created"); }
#line 3304 "synt_analyzer.tab.cpp"
    break;

  case 191: /* expr: expr '-' expr  */
#line 560 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sub);  puts("expr created"); }
#line 3310 "synt_analyzer.tab.cpp"
    break;

  case 192: /* expr: expr '*' expr  */
#line 561 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mul);  puts("expr created"); }
#line 3316 "synt_analyzer.tab.cpp"
    break;

  case 193: /* expr: expr '/' expr  */
#line 562 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Div);  puts("expr created"); }
#line 3322 "synt_analyzer.tab.cpp"
    break;

  case 194: /* expr: expr '%' expr  */
#line 563 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mod);  puts("expr created"); }
#line 3328 "synt_analyzer.tab.cpp"
    break;

  case 195: /* expr: expr '<' expr  */
#line 564 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Less);  puts("expr created"); }
#line 3334 "synt_analyzer.tab.cpp"
    break;

  case 196: /* expr: expr '>' expr  */
#line 565 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), More);  puts("expr created"); }
#line 3340 "synt_analyzer.tab.cpp"
    break;

  case 197: /* expr: expr OR expr  */
#line 566 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Or);  puts("expr created"); }
#line 3346 "synt_analyzer.tab.cpp"
    break;

  case 198: /* expr: expr AND expr  */
#line 567 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), And);  puts("expr created"); }
#line 3352 "synt_analyzer.tab.cpp"
    break;

  case 199: /* expr: expr EQ expr  */
#line 568 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Eq);  puts("expr created"); }
#line 3358 "synt_analyzer.tab.cpp"
    break;

  case 200: /* expr: expr AEQ expr  */
#line 569 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Aeq);}
#line 3364 "synt_analyzer.tab.cpp"
    break;

  case 201: /* expr: expr NEQ expr  */
#line 570 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Neq);  puts("expr created"); }
#line 3370 "synt_analyzer.tab.cpp"
    break;

  case 202: /* expr: expr NAEQ expr  */
#line 571 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Naeq);  puts("expr created"); }
#line 3376 "synt_analyzer.tab.cpp"
    break;

  case 203: /* expr: expr LOEQ expr  */
#line 572 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Loeq);  puts("expr created"); }
#line 3382 "synt_analyzer.tab.cpp"
    break;

  case 204: /* expr: expr MOEQ expr  */
#line 573 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Moeq);  puts("expr created"); }
#line 3388 "synt_analyzer.tab.cpp"
    break;

  case 205: /* expr: expr '.' ID  */
#line 574 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].Id), FieldCalcExpr);  puts("expr created"); }
#line 3394 "synt_analyzer.tab.cpp"
    break;

  case 206: /* expr: expr '.' ID '(' optFactParams ')'  */
#line 575 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr((yyvsp[-5].exprU), (yyvsp[-3].Id), (yyvsp[-1].factParamsListU), MethodCalcExpr);  puts("expr created"); }
#line 3400 "synt_analyzer.tab.cpp"
    break;

  case 207: /* expr: expr '[' expr ']'  */
#line 576 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-3].exprU), (yyvsp[-1].exprU), ArrayElementCall);  puts("expr created"); }
#line 3406 "synt_analyzer.tab.cpp"
    break;

  case 208: /* expr: SUPER '.' ID  */
#line 577 "synt_analyzer.y"
                {(yyval.exprU) = createExpr(0, (yyvsp[0].Id), ParentFieldCall);  puts("expr created"); }
#line 3412 "synt_analyzer.tab.cpp"
    break;

  case 209: /* expr: SUPER '.' ID '(' optFactParams ')'  */
#line 578 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr(0, (yyvsp[-3].Id), (yyvsp[-1].factParamsListU), ParentMethodCall);  puts("expr created"); }
#line 3418 "synt_analyzer.tab.cpp"
    break;

  case 210: /* expr: expr RANGE expr  */
#line 579 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Range);  puts("expr created"); }
#line 3424 "synt_analyzer.tab.cpp"
    break;

  case 211: /* optFactParams: %empty  */
#line 582 "synt_analyzer.y"
                                {(yyval.factParamsListU) = 0;   puts("opt fact params created"); }
#line 3430 "synt_analyzer.tab.cpp"
    break;

  case 212: /* optFactParams: factParams  */
#line 583 "synt_analyzer.y"
                {(yyval.factParamsListU) = (yyvsp[0].factParamsListU);   puts("opt fact params created"); }
#line 3436 "synt_analyzer.tab.cpp"
    break;

  case 213: /* factParams: expr  */
#line 586 "synt_analyzer.y"
                        {(yyval.factParamsListU) = createFactParamsList((yyvsp[0].exprU));   puts("fact params created"); }
#line 3442 "synt_analyzer.tab.cpp"
    break;

  case 214: /* factParams: factParams ',' expr  */
#line 587 "synt_analyzer.y"
                        {(yyval.factParamsListU) = addToFactParamsList((yyvsp[-2].factParamsListU), (yyvsp[0].exprU));   puts("fact params created"); }
#line 3448 "synt_analyzer.tab.cpp"
    break;

  case 215: /* assignment: expr '=' expr  */
#line 590 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Assign); puts("assignment created"); }
#line 3454 "synt_analyzer.tab.cpp"
    break;

  case 216: /* assignment: expr ASUM expr  */
#line 591 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asum); puts("assignment created"); }
#line 3460 "synt_analyzer.tab.cpp"
    break;

  case 217: /* assignment: expr ASUB expr  */
#line 592 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asub); puts("assignment created"); }
#line 3466 "synt_analyzer.tab.cpp"
    break;

  case 218: /* assignment: expr ADIV expr  */
#line 593 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Adiv); puts("assignment created"); }
#line 3472 "synt_analyzer.tab.cpp"
    break;

  case 219: /* assignment: expr AMUL expr  */
#line 594 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amul); puts("assignment created"); }
#line 3478 "synt_analyzer.tab.cpp"
    break;

  case 220: /* assignment: expr AMOD expr  */
#line 595 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amod); puts("assignment created"); }
#line 3484 "synt_analyzer.tab.cpp"
    break;

  case 221: /* whileLoop: WHILE '(' expr ')' stmt  */
#line 598 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[0].stmtU), 0); puts("whileLoop created"); }
#line 3490 "synt_analyzer.tab.cpp"
    break;

  case 222: /* whileLoop: WHILE '(' expr ')' block  */
#line 599 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[0].stmtListU), 0); puts("whileLoop created"); }
#line 3496 "synt_analyzer.tab.cpp"
    break;

  case 223: /* whileLoop: WHILE '(' expr ')' ';'  */
#line 600 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 0); puts("whileLoop created"); }
#line 3502 "synt_analyzer.tab.cpp"
    break;

  case 224: /* doWhileLoop: DO stmt WHILE '(' expr ')'  */
#line 603 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].stmtU), 1); puts("doWhileLoop created"); }
#line 3508 "synt_analyzer.tab.cpp"
    break;

  case 225: /* doWhileLoop: DO block WHILE '(' expr ')'  */
#line 604 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].stmtListU), 1); puts("doWhileLoop created"); }
#line 3514 "synt_analyzer.tab.cpp"
    break;

  case 226: /* doWhileLoop: DO WHILE '(' expr ')' optNewLines  */
#line 605 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 1); puts("doWhileLoop created"); }
#line 3520 "synt_analyzer.tab.cpp"
    break;

  case 227: /* forLoop: FOR '(' ID ':' type IN expr ')' stmt  */
#line 608 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].Id), (yyvsp[-4].typeU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3526 "synt_analyzer.tab.cpp"
    break;

  case 228: /* forLoop: FOR '(' ID ':' type IN expr ')' block  */
#line 609 "synt_analyzer.y"
                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].Id), (yyvsp[-4].typeU), (yyvsp[-2].exprU), (yyvsp[0].stmtListU)); puts("forLoop created"); }
#line 3532 "synt_analyzer.tab.cpp"
    break;

  case 229: /* forLoop: FOR '(' ID ':' type IN expr ')' ';'  */
#line 610 "synt_analyzer.y"
                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].Id), (yyvsp[-4].typeU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3538 "synt_analyzer.tab.cpp"
    break;

  case 230: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' stmt  */
#line 611 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3544 "synt_analyzer.tab.cpp"
    break;

  case 231: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block  */
#line 612 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), (yyvsp[0].stmtListU)); puts("forLoop created"); }
#line 3550 "synt_analyzer.tab.cpp"
    break;

  case 232: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' ';'  */
#line 613 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3556 "synt_analyzer.tab.cpp"
    break;

  case 233: /* ifStmt: IF '(' expr ')' stmt  */
#line 616 "synt_analyzer.y"
                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3562 "synt_analyzer.tab.cpp"
    break;

  case 234: /* ifStmt: IF '(' expr ')' block  */
#line 617 "synt_analyzer.y"
                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU), (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3568 "synt_analyzer.tab.cpp"
    break;

  case 235: /* ifStmt: IF '(' expr ')' semis  */
#line 618 "synt_analyzer.y"
                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3574 "synt_analyzer.tab.cpp"
    break;

  case 236: /* ifStmt: IF '(' expr ')' stmt ELSE stmt  */
#line 619 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3580 "synt_analyzer.tab.cpp"
    break;

  case 237: /* ifStmt: IF '(' expr ')' block ELSE stmt  */
#line 620 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3586 "synt_analyzer.tab.cpp"
    break;

  case 238: /* ifStmt: IF '(' expr ')' semis ELSE stmt  */
#line 621 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3592 "synt_analyzer.tab.cpp"
    break;

  case 239: /* ifStmt: IF '(' expr ')' stmt ELSE block  */
#line 622 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU), (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3598 "synt_analyzer.tab.cpp"
    break;

  case 240: /* ifStmt: IF '(' expr ')' block ELSE block  */
#line 623 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU), (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3604 "synt_analyzer.tab.cpp"
    break;

  case 241: /* ifStmt: IF '(' expr ')' semis ELSE block  */
#line 624 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3610 "synt_analyzer.tab.cpp"
    break;

  case 242: /* ifStmt: IF '(' expr ')' stmt ELSE semis  */
#line 625 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU)); puts("ifStmt created"); }
#line 3616 "synt_analyzer.tab.cpp"
    break;

  case 243: /* ifStmt: IF '(' expr ')' block ELSE semis  */
#line 626 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU)); puts("ifStmt created"); }
#line 3622 "synt_analyzer.tab.cpp"
    break;

  case 244: /* ifStmt: IF '(' expr ')' semis ELSE semis  */
#line 627 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU)); puts("ifStmt created"); }
#line 3628 "synt_analyzer.tab.cpp"
    break;

  case 245: /* optNewLines: %empty  */
#line 631 "synt_analyzer.y"
                       { puts("opt new lines created"); }
#line 3634 "synt_analyzer.tab.cpp"
    break;

  case 246: /* optNewLines: newLines  */
#line 632 "synt_analyzer.y"
           { puts("opt new lines created"); }
#line 3640 "synt_analyzer.tab.cpp"
    break;

  case 247: /* newLines: NEW_LINE  */
#line 635 "synt_analyzer.y"
                        { puts("new lines created"); }
#line 3646 "synt_analyzer.tab.cpp"
    break;

  case 248: /* newLines: newLines NEW_LINE  */
#line 636 "synt_analyzer.y"
                                { puts("new lines created"); }
#line 3652 "synt_analyzer.tab.cpp"
    break;

  case 249: /* semis: ';'  */
#line 639 "synt_analyzer.y"
                { puts("semis created"); }
#line 3658 "synt_analyzer.tab.cpp"
    break;

  case 250: /* semis: semis ';'  */
#line 640 "synt_analyzer.y"
                { puts("semis created"); }
#line 3664 "synt_analyzer.tab.cpp"
    break;


#line 3668 "synt_analyzer.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 644 "synt_analyzer.y"

//Секция пользовательского кода


//Вспомогательные функция
struct programS * createProgram(struct programElementS * pe)
{
	struct programS * prog = (struct programS * ) malloc(sizeof(struct programS));
	prog->first = pe;
	prog->last = pe;
	return prog;
}

struct programS * addToProgram(struct programS * prog, struct programElementS * pe)
{
	if (prog->last != 0)
	{
		prog->last->next = pe;
		prog->last = pe;			
	}
	else
	{
		prog->first = pe;
		prog->last = pe;
	}
	return prog;
}

struct programElementS * createProgramElement(struct classS * clas, struct methodS * meth, struct propertyS * prop, struct programElementS * next)
{
	struct programElementS * pe = (struct programElementS *) malloc(sizeof(struct programElementS));
	pe->clas = clas;
	pe->method = meth;
	pe->property = prop;
	pe->next = next;
	return pe;
}

struct programElementS * createProgramElement(struct classS * clas)
{
	return createProgramElement(clas, 0, 0, 0);
}

struct programElementS * createProgramElement(struct methodS * meth)
{
	return createProgramElement(0, meth, 0, 0);
}

struct programElementS * createProgramElement(struct propertyS * prop)
{
	return createProgramElement(0, 0, prop, 0);
}

//Нужные функции
struct programS * createProgram()
{
	struct programS * prog = (struct programS * ) malloc(sizeof(struct programS));
	prog->first = 0;
	prog->last = 0;
	return prog;	
}

struct programS * createProgram(struct classS * clas)
{	
	return createProgram(createProgramElement(clas));
}

struct programS * createProgram(struct methodS * meth)
{
	return createProgram(createProgramElement(meth));
}

struct programS * createProgram(struct propertyS * prop)
{
	return createProgram(createProgramElement(prop));
}

struct programS * addToProgram(struct programS * prog, struct classS * clas)
{
	return addToProgram(prog, createProgramElement(clas));
}

struct programS * addToProgram(struct programS * prog, struct methodS * meth)
{
	return addToProgram(prog, createProgramElement(meth));
}

struct programS * addToProgram(struct programS * prog, struct propertyS * prop)
{
	return addToProgram(prog, createProgramElement(prop));
}



struct classS * createClass(struct modifiersS * mods, char * id, char * parentId, struct classBodyS * body)
{
	struct classS * clas = (struct classS *)malloc(sizeof(struct classS));
	clas->mods = mods;
	clas->name = id;
	clas->parentClassName = parentId;
	clas->body = body;
	return clas;
	
}

struct classS * createClass(struct modifiersS * mods, char * id, struct classBodyS * body)
{
	return createClass(mods, id, 0, body);
}

struct classS * createClass(char * id, char * parentId, struct classBodyS * body)
{
	return createClass(0, id, parentId, body);
}

struct classS * createClass(char * id, struct classBodyS * body)
{
	return createClass(0, id, 0, body);
}

//Вспомогательные функции
struct classBodyElementS * createClassBodyElement(struct methodS * meth, struct initializerS * initializer, struct propertyS * prop, struct constructorS * constr, struct classBodyElementS * next)
{
	struct classBodyElementS * cbe = (struct classBodyElementS * )malloc(sizeof(struct classBodyElementS));
	cbe->method = meth;
	cbe->property = prop;
	cbe->constructor = constr;
	cbe->init = initializer;
	cbe->next = next;
	return cbe;
}

struct classBodyS * createClassBody(struct classBodyElementS * cbe)
{
	struct classBodyS * cb = (struct classBodyS *)malloc(sizeof(struct classBodyS));
	cb->first = cbe;
	cb->last = cbe;
	return cb;
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct classBodyElementS * cbe)
{
	if (body->last != 0)
	{
		body->last->next = cbe;
		body->last = cbe;
	}
	else
	{
		body->first = cbe;
		body->last = cbe;
	}
	
	return body;
}

//Нужные функции
struct classBodyS * createClassBody()
{
	struct classBodyS * cb = (struct classBodyS *)malloc(sizeof(struct classBodyS));
	cb->first = 0;
	cb->last = 0;
	return cb;
}

struct classBodyS * createClassBody(struct methodS * meth)
{
	return createClassBody(createClassBodyElement(meth, 0, 0, 0, 0));
}

struct classBodyS * createClassBody(struct initializerS * initializer)
{
	return createClassBody(createClassBodyElement(0, initializer, 0, 0, 0));
}

struct classBodyS * createClassBody(struct propertyS * prop)
{
	return createClassBody(createClassBodyElement(0, 0, prop, 0, 0));
}

struct classBodyS * createClassBody(struct constructorS * constr)
{
	return createClassBody(createClassBodyElement(0, 0, 0, constr, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct methodS * meth)
{
	return addToClassBody(body, createClassBodyElement(meth, 0, 0, 0, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct initializerS * initializer)
{
	return addToClassBody(body, createClassBodyElement(0, initializer, 0, 0, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct propertyS * prop)
{
	return addToClassBody(body, createClassBodyElement(0, 0, prop, 0, 0));
}

struct classBodyS * addToClassBody(struct classBodyS * body, struct constructorS * constr)
{
	return addToClassBody(body, createClassBodyElement(0, 0, 0, constr, 0));
}



struct propertyS * createProperty(struct modifiersS * mods, struct varOrValDeclS * decl)
{
	struct propertyS * p = (struct propertyS *)malloc(sizeof(struct propertyS));
	p->mods = mods;
	p->varOrVal = decl;
	return p;
}

struct propertyS * createProperty(struct varOrValDeclS * decl)
{
	return createProperty(0, decl);
}


struct methodS * createMethod(struct modifiersS * mods, struct funcDeclS * funcDecl, struct funcS * func)
{
	struct methodS * m = (struct methodS *)malloc(sizeof(struct methodS));
	m->mods = mods;
	m->func = func;
	m->funcDecl = funcDecl;
	return m;
}

struct methodS * createMethod(struct modifiersS * mods, struct funcDeclS * funcDecl)
{
	return createMethod(mods, funcDecl, 0);
}

struct methodS * createMethod(struct modifiersS * mods, struct funcS * func)
{
	return createMethod(mods, 0, func);
}

struct methodS * createMethod(struct funcDeclS * funcDecl)
{
	return createMethod(0, funcDecl, 0);
}

struct methodS * createMethod(struct funcS * func)
{
	return createMethod(0, 0, func);
}


struct initializerS * createInit(struct stmtList * stmts)
{
	struct initializerS * i = (struct initializerS *)malloc(sizeof(struct initializerS * ));
	i->stmts = stmts;
	return i;
}




struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, struct stmtList * stmts)
{
	return createConstructor(mod, params, 0, 0, stmts);
}

struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params)
{
	return createConstructor(mod, params, 0, 0, 0);
}

struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams)
{
	return createConstructor(mod, params, parentOrAnotherConstr, anotherConstrParams, 0);
}

struct constructorS * createConstructor(enum visibilityMod mod, struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts)
{
	struct constructorS * c = (struct constructorS *)malloc(sizeof(struct constructorS));
	c->mod = mod;
	c->params = params;
	c->stmts = stmts;
	if (parentOrAnotherConstr != 0)
	{
		c->anotherConstructorId = (char *)malloc(strlen(parentOrAnotherConstr));
		strcpy(c->anotherConstructorId, parentOrAnotherConstr);
	}
	else
	{
		c->anotherConstructorId = 0;
	}
	c->anotherConstrParams = anotherConstrParams;
	return c;
}

struct constructorS * createConstructor(struct formalParamsList * params, struct stmtList * stmts)
{
	return createConstructor(Public, params, 0, 0, stmts);
}

struct constructorS * createConstructor(struct formalParamsList * params)
{
	return createConstructor(Public, params, 0, 0, 0);
}

struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams)
{
	return createConstructor(Public, params, parentOrAnotherConstr, anotherConstrParams, 0);
}

struct constructorS * createConstructor(struct formalParamsList * params, const char * parentOrAnotherConstr, struct factParamsList * anotherConstrParams, struct stmtList * stmts)
{
	return createConstructor(Public, params, parentOrAnotherConstr, anotherConstrParams, stmts);
}


struct formalParamS * createFormalParam(char * id, struct typeS * type)
{
	struct formalParamS * fp = (struct formalParamS *)malloc(sizeof(struct formalParamS));
	fp->type = type;
	fp->name = id;
	fp-> next = 0;
	return fp;
}

struct formalParamsList * createFormalParamsList(char * id, struct typeS * type)
{
	struct formalParamsList * fpl = (struct formalParamsList *)malloc(sizeof(struct formalParamsList));
	fpl->first = createFormalParam(id, type);
	fpl->last = fpl->first;
	return fpl;
}

struct formalParamsList * addToFormalParamsList(struct formalParamsList * list, char * id, struct typeS * type)
{
	list->last->next = createFormalParam(id, type);
	list->last = list->last->next;
	return list;
}



struct modifiersS * createModifiers(int isAbstruct, int isOverride, enum visibilityMod vMod, enum inheritanceMod iMod)
{
	struct modifiersS * m = (struct modifiersS * )malloc(sizeof(struct modifiersS));
	m->isAbstract = isAbstruct;
	m->isOverride = isOverride;
	m->vMod = vMod;
	m->iMod = iMod;
	return m;
}
	
	
struct funcS * createFunc(struct funcDeclS * decl, struct stmtList * stmts, struct exprS * expr)
{
	struct funcS * f = (struct funcS *)malloc(sizeof(struct funcS));
	f->delc = decl;
	f->stmts = stmts;
	f->expr = expr;
	return f;
}	

struct funcS * createFunc(struct funcDeclS * decl, struct stmtList * stmts)
{
	return createFunc(decl, stmts, 0);
}

struct funcS * createFunc(struct funcDeclS * decl, struct exprS * expr)
{
	return createFunc(decl, 0, expr);
}


struct funcDeclS * createFuncDecl(char * id, struct formalParamsList * params, struct typeS * type)
{
	struct funcDeclS * fd = (struct funcDeclS *)malloc(sizeof(struct funcDeclS));
	fd->name = id;
	fd->params = params;
	fd->type = type;
	return fd;
}


struct stmtList * createStmtList(struct stmtS * stmt)
{
	struct stmtList * sl = (struct stmtList *)malloc(sizeof(struct stmtList));
	sl->first = stmt;
	sl->last = stmt;
	return sl;
}

struct stmtList * addToStmtList(struct stmtList * list, struct stmtS * stmt)
{
	list->last->next = stmt;
	list->last = stmt;
	return list;
}


struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, struct formalParamsList * idsAndTypes, struct exprS * initValue, int isVal)
{
	struct varOrValDeclS * v = (struct varOrValDeclS *)malloc(sizeof(struct varOrValDeclS));
	v->isVal = isVal;
	v->id = id;
	v->type = type;
	v->namesAndTypes = idsAndTypes;
	v->initValue = initValue;
	return v;
}

struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, int isVal)
{
	return createVarOrValDecl(id, type, 0, 0, isVal);
}

struct varOrValDeclS * createVarOrValDecl(char * id, struct typeS * type, struct exprS * initValue, int isVal)
{
	return createVarOrValDecl(id, type, 0, initValue, isVal);
}

struct varOrValDeclS * createVarOrValDecl(struct formalParamsList * idsAndTypes, struct exprS * initValue, int isVal)
{
	return createVarOrValDecl(0, 0, idsAndTypes, initValue, isVal);
}


struct typeS * createType(char * id, struct templateTypeS * type)
{
	struct typeS * t = (struct typeS * )malloc(sizeof(struct typeS));
	t->easyType = id;
	t->complexType = type;
	return t;
}

struct typeS * createType(char * id)
{
	return createType(id, 0);
}

struct typeS * createType(struct templateTypeS * type)
{
	return createType(0, type);
}


struct templateTypeS * createTemplateType(char * id, struct typesList * templateTypes)
{
	struct templateTypeS * tt = (struct templateTypeS *)malloc(sizeof(struct templateTypeS));
	tt->type = id;
	tt->list = templateTypes;
	return tt;
}


struct typesList * createTypesList(char * id, struct templateTypeS * type)
{
	struct typesList * tl = (struct typesList *)malloc(sizeof(struct typesList));
	struct typeS * listElement = 0;
	if (id != 0)
	{
		listElement = createType(id, 0);
	}
	else
	{
		listElement = createType(0, type);
	}
	tl->first = listElement;
	tl->last = listElement;
	return tl;
}

struct typesList * createTypesList(char * id)
{
	return createTypesList(id, 0);
}

struct typesList * createTypesList(struct templateTypeS * type)
{
	return createTypesList(0, type);
}

struct typesList * addToTypesList(struct typesList * list, char * id, struct templateTypeS * type)
{
	struct typeS * newListElement = 0;
	if (id != 0)
	{
		newListElement = createType(id);
	}
	else
	{
		newListElement = createType(type);
	}
	list->last->next = newListElement;
	list->last = newListElement;
	return list;
}

struct typesList * addToTypesList(struct typesList * list, char * id)
{
	return addToTypesList(list, id, 0);
}

struct typesList * addToTypesList(struct typesList * list, struct templateTypeS * type)
{
	return addToTypesList(list, 0, type);
}




struct stmtS * createStmt(struct varOrValDeclS * v, struct assignmentS * assign, struct whileLoopS * wLoop, forLoopS * fLoop, struct ifStmtS * ifStmt, struct exprS * expr, enum stmtType type)
{
	struct stmtS * s = (struct stmtS *)malloc(sizeof(struct stmtS));
	s->varOrVal = v;
	s->assignment = assign;
	s->whileLoop = wLoop;
	s->forLoop = fLoop;
	s->ifStmt = ifStmt;
	s->expr = expr;
	s->type = type;
	s->next = 0;
	return s;
}

struct stmtS * createStmt(struct varOrValDeclS * v, enum stmtType type)
{
	return createStmt(v, 0, 0, 0, 0, 0, type);
}

struct stmtS * createStmt(struct assignmentS * assign, enum stmtType type)
{
	return createStmt(0, assign, 0, 0, 0, 0, type);
}

struct stmtS * createStmt(struct whileLoopS * loop, enum stmtType type)
{
	return createStmt(0, 0, loop, 0, 0, 0, type);
}

struct stmtS * createStmt(struct forLoopS * loop, enum stmtType type)
{
	return createStmt(0, 0, 0, loop, 0, 0, type);
}

struct stmtS * createStmt(struct ifStmtS * ifStmt, enum stmtType type)
{
	return createStmt(0, 0, 0, 0, ifStmt, 0, type);
}

struct stmtS * createStmt(struct exprS * expr, enum stmtType type)
{
	return createStmt(0, 0, 0, 0, 0, expr, type);
}

struct stmtS * createStmt(enum stmtType type)
{
	return createStmt(0, 0, 0, 0, 0, 0, type);
}


struct exprS * createExpr(char * idOrString, int iVal, struct factParamsList * params, float fVal, double dVal, char cVar, bool bVar, struct exprS * exprL, struct exprS * exprR,  enum exprType type)
{
	struct exprS * e = (struct exprS *)malloc(sizeof(struct exprS));
	e->type = type;
	e->left = exprL;
	e->right = exprR;
	e->factParams = params;
	e->stringOrId = idOrString;
	e->charV = cVar;
	e->intV = iVal;
	e->floatV = fVal;
	e->doubleV = dVal;
	e->booleanV = bVar;
	e->next = 0;
	return e;
	
}

struct exprS * createExpr(char * idOrString, enum exprType type)
{
	return createExpr(idOrString, 0, 0, 0, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(int val, enum exprType type)
{
	return createExpr(0, val, 0, 0, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(char * idOrString, struct factParamsList * params, enum exprType type)
{
	return createExpr(idOrString, 0, params, 0, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(float val, enum exprType type)
{
	return createExpr(0, 0, 0, val, 0, 0, 0, 0, 0, type);
}

struct exprS * createExpr(double val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, val, 0, 0, 0, 0, type);
}

struct exprS * createExpr(char val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, val, 0, 0, 0, type);
}

struct exprS * createExpr(bool val, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, val, 0, 0, type);
}

struct exprS * createExpr(struct exprS * expr, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, 0, expr, 0, type);
}

struct exprS * createExpr(struct exprS * left, struct exprS * right, enum exprType type)
{
	return createExpr(0, 0, 0, 0, 0, 0, 0, left, right, type);
}

struct exprS * createExpr(struct exprS * left, char * right, enum exprType type)
{
	return createExpr(right, 0, 0, 0, 0, 0, 0, left, 0, type);
}

struct exprS * createExpr(struct exprS * left, char * right, struct factParamsList * params, enum exprType type)
{
	return createExpr(right, 0, params, 0, 0, 0, 0, left, 0, type);
}



struct factParamsList * createFactParamsList(struct exprS * expr)
{
	struct factParamsList * l = (struct factParamsList *)malloc(sizeof(struct factParamsList));
	l->first = expr;
	l->last = expr;
	return l;
}

struct factParamsList * addToFactParamsList(struct factParamsList * list, struct exprS * expr)
{
	list->last->next = expr;
	list->last = expr;
	return list;
}



struct assignmentS * createAssignment(struct exprS * left, struct exprS * right, enum assignmentType type)
{
	struct assignmentS * a = (struct assignmentS *)malloc(sizeof(struct assignmentS));
	a->type = type;
	a->left = left;
	a->right = right;
	return a;
}

struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtS * stmt, struct stmtList * stmts, int isDoWhile)
{
	struct whileLoopS * l = (struct whileLoopS *)malloc(sizeof(struct whileLoopS));
	l->isDoWhile = isDoWhile;
	l->cond = cond;
	if (stmt == 0) 
	{
		l->stmts = stmts;		
	}
	else
	{
		stmts = createStmtList(stmt);
	}
	return l;
}

struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtS * stmt, int isDoWhile)
{
	return createWhileLoop(cond, stmt, 0, isDoWhile);
}

struct whileLoopS * createWhileLoop(struct exprS * cond, struct stmtList * stmts, int isDoWhile)
{
	return createWhileLoop(cond, 0, stmts, isDoWhile);
}

struct whileLoopS * createWhileLoop(struct exprS * cond, int isDoWhile)
{
	return createWhileLoop(cond, 0, 0, isDoWhile);
}



struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtS * stmt, struct stmtList * stmts, struct formalParamsList * idsAndTypes)
{
	struct forLoopS * l = (struct forLoopS *)malloc(sizeof(struct forLoopS));
	
	if (id == 0)
	{
		l->params = idsAndTypes;
	}
	else
	{
		l->params = createFormalParamsList(id, type);
	}
	l->iterableExpr = iterableExpr;
	if (stmt == 0)
	{
		l->stmts = stmts;
	}
	else
	{
		l->stmts = createStmtList(stmt);
	}
	
	return l;
}

struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtS * stmt)
{
	return createForLoop(id, type, iterableExpr, stmt, 0, 0);
}

struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr, struct stmtList * stmts)
{
	return createForLoop(id, type, iterableExpr, 0, stmts, 0);
}

struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtList * stmts)
{
	return createForLoop(0, 0, iterableExpr, 0, stmts, idsAndTypes);
}

struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr, struct stmtS * stmt)
{
	return createForLoop(0, 0, iterableExpr, stmt, 0, idsAndTypes);
}

struct forLoopS * createForLoop(char * id, struct typeS * type, struct exprS * iterableExpr)
{
	return createForLoop(id, type, iterableExpr, 0, 0, 0);
}

struct forLoopS * createForLoop(struct formalParamsList * idsAndTypes, struct exprS * iterableExpr)
{
	return createForLoop(0, 0, iterableExpr, 0, 0, idsAndTypes);
}


struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtList * altActions, struct stmtS * action, struct stmtS * altAction)
{
	struct ifStmtS * i = (struct ifStmtS *)malloc(sizeof(struct ifStmtS));
	i->condition = cond;
	if (action == 0)
	{
		i->actions = actions;
	}
	else
	{
		i->actions = createStmtList(action);
	}
	if (altAction == 0)
	{
		i->altActions = altActions;
	}
	else
	{
		i->altActions = createStmtList(altAction);
	}
	return i;
}


struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action)
{
	return createIfStmt(cond, 0, 0, action, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions)
{
	return createIfStmt(cond, actions, 0, 0, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond)
{
	return createIfStmt(cond, 0, 0, 0, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtS * altAction)
{
	return createIfStmt(cond, 0, 0, action, altAction);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtS * action, struct stmtList * altActions)
{
	return createIfStmt(cond, 0, altActions, action, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtS * altAction)
{
	return createIfStmt(cond, actions, 0, 0, altAction);
}

struct ifStmtS * createIfStmt(struct exprS * cond, struct stmtList * actions, struct stmtList * altActions)
{
	return createIfStmt(cond, actions, altActions, 0, 0);
}

struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtS * altAction)
{
	return createIfStmt(cond, 0, 0, 0, altAction);
}

struct ifStmtS * createIfStmt(struct exprS * cond, int action, struct stmtList * altActions)
{
	return createIfStmt(cond, 0, altActions, 0, 0);
}




void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r");
	FILE * file = fopen("tree.dot", "w");
	
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);

    return;
}




















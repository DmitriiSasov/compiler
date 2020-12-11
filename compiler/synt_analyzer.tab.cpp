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
	#include "tree_nodes.h"
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
	
	struct stmtS * createStmt(struct propertyS * prop, enum stmtType type);
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
	

#line 204 "synt_analyzer.tab.cpp"

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1893

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  588

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
       0,   311,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   325,   326,   327,   328,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   347,   348,   349,   350,   353,   354,   355,   356,
     359,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   377,   378,   381,   382,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   441,   443,   445,   447,   449,   451,   452,   453,
     455,   459,   460,   461,   462,   466,   467,   470,   471,   475,
     479,   480,   481,   482,   486,   487,   488,   492,   493,   494,
     497,   498,   501,   504,   505,   506,   507,   510,   511,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   574,   575,   578,   579,   582,
     583,   584,   585,   586,   587,   590,   591,   592,   595,   596,
     597,   600,   601,   602,   603,   604,   605,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   623,
     624,   627,   628,   631,   632
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

#define YYPACT_NINF (-404)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-240)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     424,  -404,    13,  -404,  -404,  -404,  -404,   158,   215,    13,
      13,    13,  -404,  -404,  -404,   295,  -404,    35,  -404,    13,
     164,   301,  -404,    36,  -404,  -404,    21,   -60,    71,    21,
     199,   319,    81,    59,    62,  -404,  -404,    35,  -404,    21,
     -60,    21,   -60,   203,   518,   344,  -404,   -17,  -404,  -404,
      13,   333,   145,   384,   430,   147,   501,    13,    13,    13,
      13,    13,    21,   -60,    13,  -404,    37,  -404,  -404,   145,
     147,   190,   571,   584,   190,    35,    13,  -404,   -66,   313,
     436,   558,   313,    -4,   595,     0,   -15,   152,    60,   152,
     162,  -404,   471,   209,   110,   627,   630,   179,  1509,  1144,
     180,    13,    13,    19,   413,    19,    43,   413,    43,    19,
     413,    19,   150,   413,   150,    13,    13,    13,    13,    13,
      13,    13,    19,    43,    19,   150,    43,   150,   413,    43,
     413,   150,    43,   150,    70,  -404,    79,    13,    13,    13,
      13,    35,    35,  1071,  -404,  -404,  -404,  -404,  -404,  -404,
     180,   180,   180,   180,  -404,    35,    13,  1774,  -404,   964,
      35,    35,    35,    35,    35,  -404,  1581,  1705,   174,   667,
     207,   637,   207,   148,   637,   166,   207,   637,   207,   153,
     637,   201,   152,   258,   163,   -11,   258,    52,   154,   207,
     231,   207,   248,   249,   263,   637,   277,   637,   306,   316,
     322,    13,   290,   269,  1653,   278,   296,    21,   -60,    21,
     -60,   817,    21,   -60,   138,   138,   138,  1648,    21,   -60,
     257,  -404,   284,    13,    13,    13,    13,    13,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   399,   180,    13,    21,   -60,    21,
     -60,    21,   -60,    21,   -60,    21,   -60,    21,   -60,  -404,
      13,    13,    13,   751,    35,  -404,  -404,  -404,    13,   192,
      21,   -60,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,    13,    28,    11,    32,  -404,    13,
      13,    13,    32,    13,    13,    13,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,   180,   330,
      13,    13,    13,    13,    13,    13,    21,   -60,  -404,  -404,
     180,   180,   180,   180,   180,  1768,  1793,   711,   711,   711,
     711,   598,   598,   598,   598,   750,   617,   617,   138,   138,
     138,   345,  1028,   180,   308,   348,   339,  -404,    35,  -404,
    -404,  -404,    21,   -60,    21,   -60,   241,   310,   359,   361,
     391,   371,   258,   373,   477,   383,   386,   498,   667,  1705,
      13,    28,    13,   180,   405,   466,   467,   180,    72,  1705,
    1705,  1705,  1705,  1705,    13,  -404,  1705,    13,    13,  -404,
      21,   -60,    13,    13,    13,    13,  -404,    13,    13,    13,
      13,    13,   924,   419,   414,   180,  1679,    13,    13,    13,
    1679,    13,    13,   180,   667,   152,   421,   420,   519,   180,
     180,   425,   180,   180,   428,  -404,  -404,    13,    13,   429,
     180,   444,   445,   435,   460,   152,    13,   968,    13,    13,
      13,    11,  -404,    13,  1705,  1705,    13,  1705,  1705,    13,
     180,   468,    13,  1679,    13,    13,    13,    13,    13,   470,
    -404,   476,   152,   258,   -10,   258,   667,  1705,  -404,  1217,
     478,   180,   180,  1290,   258,    66,  -404,    30,    13,  -404,
    -404,    13,  -404,  1059,    22,    22,    38,    13,  1679,  1679,
    -404,  -404,  -404,    13,    13,   226,   479,   575,  -404,   541,
     542,   545,  1290,   491,   492,   540,   544,    13,  -404,    30,
      11,  -404,    13,    13,    13,  -404,  -404,    13,    13,   368,
     315,  1217,  1217,  1217,   180,   180,    13,    13,    13,  -404,
    -404,  -404,   -60,  -404,  -404,   -60,  -404,  -404,   -60,  1679,
    1679,   496,   499,   406,   508,   509,    13,    13,    13,    13,
      13,    13,   180,   180,   507,   515,  1363,  1436,    13,    13,
      13,    13,  -404,  -404,  -404,  -404,  -404,  -404,   526,   530,
     180,   180,    41,    41,    13,    13,   339,   339,   547,   548,
    -404,  -404,    41,    41,   339,   339,  -404,  -404
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   241,   239,   121,   122,   124,   123,   239,   239,   239,
     239,   239,   126,   125,   243,     0,     4,     0,     5,   239,
      58,   239,    39,   239,    35,    34,     3,     2,     0,   240,
       0,     0,     0,     0,     0,     1,     8,     0,     9,    12,
      13,     7,     6,     0,     0,     0,    38,     0,   242,   244,
     239,   239,    61,   239,   239,    71,   239,   239,   239,   239,
     239,   239,    11,    10,   239,    37,   239,    33,    32,    64,
      66,    65,   239,   239,    68,   239,   239,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   239,    77,    78,    74,    73,    76,    75,    92,
      91,    93,    94,    95,    96,   239,   239,   239,   239,   239,
     239,   239,    80,    79,    84,    83,    81,    82,    86,    85,
      90,    89,    88,    87,   171,   172,     0,   239,   239,   239,
     239,     0,     0,     0,   174,   175,   178,   176,   177,   179,
       0,     0,     0,     0,   133,     0,   239,   239,   147,     0,
       0,     0,     0,     0,     0,   132,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,   164,   163,   166,
     165,     0,   168,   167,   182,   183,   181,     0,   150,   149,
       0,   148,     0,   239,   239,   239,   239,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   161,   162,   152,
     151,   154,   153,   158,   157,   156,   155,   160,   159,   131,
     239,   239,   239,     0,     0,    20,    24,    23,   239,   239,
      19,    18,   101,   102,    98,    97,   100,    99,   116,   115,
     117,   118,   119,   120,   239,    54,   140,   134,   141,   239,
     239,   239,   137,   239,   239,   239,   104,   103,   108,   107,
     105,   106,   110,   109,   114,   113,   112,   111,   205,   202,
     239,   239,   239,   239,   239,   239,   169,   170,   180,   130,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   189,   190,   204,   184,   185,   187,   186,
     188,   199,     0,     0,     0,     0,     0,    17,     0,    25,
      30,    29,    28,    31,    22,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
     239,   206,   239,     0,     0,     0,     0,     0,     0,   210,
     211,   212,   213,   214,   239,   201,   209,   239,   239,    40,
      27,    26,   239,   239,   239,   239,    55,   239,   239,   239,
     239,   239,     0,     0,     0,   205,   239,   239,   239,   239,
     239,   239,   239,   205,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,   173,   239,   239,     0,
       0,     0,     0,     0,     0,     0,   239,     0,   239,   239,
     239,   143,   144,   239,   135,   136,   239,   138,   139,   239,
       0,     0,   239,   239,   239,   239,   239,   239,   239,     0,
      16,     0,    53,     0,     0,     0,     0,   208,   203,     0,
       0,     0,     0,     0,     0,     0,   200,    48,   239,   129,
     142,   239,    56,     0,   228,   227,   239,   239,   239,   239,
     217,   216,   215,   239,   239,     0,     0,     0,    14,     0,
       0,     0,   220,     0,     0,     0,     0,   239,    47,    42,
     145,   146,   239,   239,   239,   219,   218,   239,   239,     0,
       0,     0,     0,     0,     0,     0,   239,   239,   239,    41,
     234,   231,   237,   233,   230,   236,   235,   232,   238,   239,
     239,     0,     0,     0,     0,     0,   239,   239,   239,   239,
     239,   239,   205,   205,     0,     0,     0,     0,   239,   239,
     239,   239,   223,   222,   221,   226,   225,   224,     0,     0,
     205,   205,    50,    49,   239,   239,     0,     0,     0,     0,
      52,    51,    44,    43,     0,     0,    46,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -404,  -404,   625,  -321,   149,    12,  -250,  -243,  -373,   -86,
     246,   597,    -1,   -33,   -32,   -24,   -41,   -39,  -158,  -403,
    -404,   551,   364,   506,  -379,  -404,  -404,  -404,  -404,  -404,
    -404,    -2,   457,   202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,   263,   155,   265,   266,   267,   284,   285,
     156,    20,    21,    22,    23,   491,    24,    25,   287,   288,
     443,   157,   158,   159,   370,   371,   160,   161,   162,   163,
     164,   360,    29,   271
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   118,    67,   120,    68,    30,    31,    32,    33,    34,
      65,    66,    18,   350,     1,   442,     1,    43,    44,    45,
     351,    47,     1,    77,    48,     1,   428,    38,   292,    53,
      56,     1,   111,     1,   436,     1,   101,   102,     1,     1,
       1,     1,   438,    71,     1,    49,     1,   402,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      12,    13,    90,    58,    47,  -239,    60,    92,    93,    94,
      95,    96,    97,    98,   100,    50,   411,   480,   104,   106,
    -239,   110,   112,  -239,  -239,    57,    75,   116,   290,   478,
      76,   123,   125,   437,   511,   291,   481,  -239,   115,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,  -239,  -239,  -239,   203,   204,   205,   206,  -239,
      14,    46,    91,    49,  -239,   483,   126,   127,     1,    17,
       1,   293,   350,     1,   220,   222,   117,    59,   291,   351,
      61,     1,   119,   -57,    37,   494,   121,     1,   201,   272,
     412,   274,   291,   558,   559,   278,   202,   280,   260,    67,
     312,    68,  -239,  -239,   134,   275,  -239,   350,   296,   281,
     298,   574,   575,     1,   351,     1,   -57,   -57,   -57,   308,
    -239,  -239,    27,   277,   396,     3,     4,     5,    64,  -239,
    -239,  -239,  -239,   135,   136,   132,   133,    40,     1,    42,
     -60,   320,   321,   322,   323,   324,  -239,  -239,  -239,  -239,
     -58,   -58,   -58,   350,     6,   244,    51,   283,   245,    63,
     351,     9,    10,    11,   343,   124,    19,   144,   145,   146,
     147,   148,   149,   -60,   -60,   -60,   294,   295,   344,   345,
     346,    19,   286,    12,    13,   289,   356,   357,   297,   150,
     151,    12,    13,    12,    13,   349,   152,    99,   153,     9,
      10,    11,   358,   359,   299,   361,   300,   362,   363,   364,
     365,   366,   367,   368,   309,    35,    10,    11,     1,   301,
       2,     3,     4,     5,     1,   479,   -59,   482,   373,   374,
     375,   376,   377,   378,   303,    67,   493,    68,   264,     3,
       4,     5,   389,    65,    66,     3,     4,     5,   507,    75,
       6,     7,     8,     9,    10,    11,     1,   392,   -63,   -59,
     -59,   -59,   305,   208,   210,   213,    69,    70,     6,   458,
       3,     4,     5,   306,     6,    54,    71,   219,   307,    12,
      13,   248,   250,   252,   254,   256,   258,   310,   403,   404,
     405,   -63,   -63,   -63,    12,    13,   314,    12,    13,     6,
      72,    73,   413,    12,    13,   414,   415,     1,   319,   -62,
     416,   417,   418,   419,   315,   420,   421,   422,   423,   424,
      14,   526,   527,   341,   429,   430,   431,   432,   433,   434,
     435,   387,   348,   317,   349,   268,     1,   528,    75,  -239,
    -239,  -239,   -62,   -62,   -62,   450,   451,     1,   372,     2,
       3,     4,     5,     1,   459,   -70,   461,   462,   463,   548,
     549,   464,    75,   384,   465,   484,   388,   466,  -239,   349,
     469,   470,   471,   472,   473,   474,   475,    26,   393,     6,
       7,     8,     9,    10,    11,   353,   355,   291,   -70,   -70,
     -70,   508,    39,   105,    41,   495,   496,   394,   395,   497,
     397,   398,   499,   500,   501,   502,   503,   504,    12,    13,
     399,   505,   506,   400,    62,   349,   529,   530,   533,   536,
      12,    13,   401,   407,     1,   519,   -72,   520,   122,   268,
     521,   522,   523,   408,   409,   524,   525,   264,   426,   439,
     427,   221,   440,   441,   541,   542,   543,   446,   452,    14,
     221,   449,   563,   566,   456,    12,    13,   544,   545,   -72,
     -72,   -72,   454,   455,   552,   553,   554,   555,   556,   557,
     391,   348,   580,   581,    69,    70,   568,   569,   570,   571,
     586,   587,   457,   264,     3,     4,     5,   468,   313,   476,
     576,   577,   578,   579,     1,   477,   -67,   487,   509,   510,
     584,   585,    12,    13,   512,   513,   348,     1,   514,   -69,
     515,   516,   517,     6,   546,   107,   518,   547,   207,   209,
     212,     3,     4,     5,   353,   560,   167,   550,   551,   -67,
     -67,   -67,   218,   561,   268,   264,   247,   249,   251,   253,
     255,   257,   -69,   -69,   -69,   572,   270,    52,    55,   573,
       6,   113,   348,     3,     4,     5,     3,     4,     5,   353,
      36,     0,    74,     3,     4,     5,   582,   583,   268,   211,
     166,     0,     0,     0,     0,     0,   214,   215,   216,   217,
     268,     0,     6,     0,   128,     6,   130,     0,   316,     0,
       1,   486,     6,     3,     4,     5,   103,     0,   108,   109,
       0,   114,     0,   268,     0,   353,   238,   239,   240,   241,
     242,   243,   129,   131,   261,   244,     0,   262,   245,     0,
       0,     0,     6,     7,     8,     9,    10,    11,   241,   242,
     243,     0,   268,     0,   244,     0,     0,   245,     0,     0,
     352,   354,     0,   532,   535,   538,     0,     0,     0,   268,
       0,    12,    13,     0,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
       0,   342,     0,     0,     1,     0,     0,     3,     4,     5,
       0,     0,     0,     0,     0,     0,   269,     0,   273,     0,
       0,   276,    14,     0,   279,     0,     0,   282,   261,     0,
       0,   262,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,   302,     0,   304,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   390,     0,     0,   244,     0,
       0,   245,     0,     0,   369,    12,    13,     0,     0,     0,
       1,     0,     0,     0,     0,   270,   379,   380,   381,   382,
     383,     0,     0,   485,     0,     0,     0,   492,  -240,   239,
     240,   241,   242,   243,     0,     0,     0,   244,     0,   386,
     245,     0,     0,     0,     0,   347,    14,     0,     0,   352,
     269,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,     0,   406,
       0,     0,     0,   410,     0,   531,   534,   537,     0,     0,
       0,     0,     0,     0,   352,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   369,     0,     0,   244,     0,     0,   245,     0,   369,
     564,   567,    14,   270,     0,   444,   445,     1,   447,   448,
       3,     4,     5,     0,     0,     0,   453,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,   262,     0,   467,     0,     0,     6,
       7,     8,     9,    10,    11,   269,     0,     1,     0,     0,
       0,     1,     0,     0,     3,     4,     5,   488,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,     0,     0,   261,     0,     0,   262,   269,
       0,     0,     0,     6,     7,     8,     9,    10,    11,     0,
       0,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   425,    14,
     539,   540,    12,    13,   269,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   369,   369,
       0,   244,     1,   269,   245,     3,     4,     5,     0,    14,
       0,   246,   460,    14,     1,   134,   369,   369,     0,     0,
     269,     0,     0,     0,     0,     0,   261,     0,     0,   262,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,   135,   136,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,    12,    13,   244,     0,     0,   245,   385,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,   149,     0,     0,     0,     0,   134,     0,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     0,
     150,   151,     0,   498,    14,     0,     0,   152,     0,   153,
       0,     0,     0,     0,     0,     0,    14,   135,   136,     6,
       7,     8,     0,    10,    11,     0,   137,     0,     0,     0,
     138,   139,   140,   141,   142,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,   134,     0,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
     152,     0,   153,     0,     0,     0,     0,     0,   165,    49,
     135,   136,     6,     7,     8,     0,    10,    11,     0,   137,
       0,     0,     0,   138,   139,   140,   141,   142,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,     0,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,   134,     0,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,   150,   151,     0,     0,
       0,     0,     0,   152,     0,   153,     0,     0,     0,     0,
      75,     0,    14,   135,   136,     6,     7,     8,     0,    10,
      11,     0,   137,     0,     0,     0,   138,   139,   140,   141,
     142,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,   134,     0,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,   152,     0,   153,     0,
       0,     0,     0,    75,     0,   490,   135,   136,     6,     7,
       8,     0,    10,    11,     0,   137,     0,     0,     0,   138,
     139,   140,   141,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,     0,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
     134,     0,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,   150,   151,     0,     0,     0,     0,     0,   152,
       0,   153,     0,     0,     0,     0,    75,     0,   562,   135,
     136,     6,     7,     8,     0,    10,    11,     0,   137,     0,
       0,     0,   138,   139,   140,   141,   142,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,   134,     0,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,   152,     0,   153,     0,     0,     0,     0,    75,
       0,   565,   135,   136,     6,     7,     8,     0,    10,    11,
       0,   137,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,     0,   144,   145,   146,   147,
     148,   149,     0,     0,     0,   134,     0,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
       0,     0,     0,     0,     0,   152,     0,   153,     0,     0,
       0,     0,     0,   154,   135,   136,     6,     7,     8,     0,
      10,    11,     0,   137,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,   144,   145,
     146,   147,   148,   149,     0,     0,     0,   134,     0,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,   152,     0,   153,
       0,     0,     1,     0,     0,   259,   135,   136,     6,     7,
       8,     0,    10,    11,     0,   137,     0,     0,     0,   138,
     311,   140,   141,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,     0,
     144,   145,   146,   147,   148,   149,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   150,   151,     0,   244,     0,   318,   245,   152,
       0,   153,     0,     0,     0,     0,    75,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,     0,   244,     1,   134,   245,
       3,     4,     5,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     0,   244,     0,     0,   245,     0,   135,   136,     6,
       7,     8,     0,    10,    11,     0,   137,     0,     0,     0,
     138,   139,   140,   141,   142,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,   144,   145,   146,   147,   148,   149,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   150,   151,   244,     0,     0,   245,     0,
     152,     0,   153,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,     0,     0,
     244,     0,     0,   245
};

static const yytype_int16 yycheck[] =
{
       2,    87,    43,    89,    43,     7,     8,     9,    10,    11,
      43,    43,     0,   263,     3,   418,     3,    19,    20,    21,
     263,    23,     3,    47,     3,     3,   405,    15,   186,    30,
      31,     3,    36,     3,   413,     3,   102,   103,     3,     3,
       3,     3,   415,    44,     3,   105,     3,   368,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      64,    65,    64,     4,    66,    43,     4,    69,    70,    71,
      72,    73,    74,    75,    76,     4,     4,    87,    79,    80,
      37,    82,    83,    64,    65,     4,   103,   102,    99,   462,
     107,    92,    93,   414,   497,   106,   106,    86,    98,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   102,   103,   106,   137,   138,   139,   140,   107,
     105,   105,   105,   105,   103,   466,    36,    37,     3,     0,
       3,    99,   402,     3,   156,   157,     4,    98,   106,   402,
      98,     3,   102,     5,    15,    99,     4,     3,    98,   170,
      98,   172,   106,   552,   553,   176,    97,   178,     4,   220,
     204,   220,    37,    36,     4,    37,    36,   437,   189,    36,
     191,   570,   571,     3,   437,     3,    38,    39,    40,   201,
      36,    37,     0,    37,   362,     6,     7,     8,     5,    64,
      65,    64,    65,    33,    34,    36,    37,    15,     3,    17,
       5,   223,   224,   225,   226,   227,    36,    37,    64,    65,
      38,    39,    40,   483,    35,    97,    37,    36,   100,    37,
     483,    38,    39,    40,   246,    36,     0,    67,    68,    69,
      70,    71,    72,    38,    39,    40,   102,   103,   260,   261,
     262,    15,     4,    64,    65,   102,   268,   269,    37,    89,
      90,    64,    65,    64,    65,   263,    96,    75,    98,    38,
      39,    40,   284,   285,    36,   287,    37,   289,   290,   291,
     292,   293,   294,   295,     4,     0,    39,    40,     3,    36,
       5,     6,     7,     8,     3,   463,     5,   465,   310,   311,
     312,   313,   314,   315,    37,   356,   474,   356,   169,     6,
       7,     8,   346,   356,   356,     6,     7,     8,   102,   103,
      35,    36,    37,    38,    39,    40,     3,    27,     5,    38,
      39,    40,    36,   141,   142,   143,    36,    37,    35,   435,
       6,     7,     8,    37,    35,    36,   357,   155,    36,    64,
      65,   159,   160,   161,   162,   163,   164,    98,   370,   371,
     372,    38,    39,    40,    64,    65,    98,    64,    65,    35,
      36,    37,   384,    64,    65,   387,   388,     3,   104,     5,
     392,   393,   394,   395,    98,   397,   398,   399,   400,   401,
     105,    33,    34,     4,   406,   407,   408,   409,   410,   411,
     412,   103,   263,   211,   402,   169,     3,   102,   103,     6,
       7,     8,    38,    39,    40,   427,   428,     3,    98,     5,
       6,     7,     8,     3,   436,     5,   438,   439,   440,    33,
      34,   443,   103,    98,   446,   469,    98,   449,    35,   437,
     452,   453,   454,   455,   456,   457,   458,     0,    99,    35,
      36,    37,    38,    39,    40,   263,   264,   106,    38,    39,
      40,   495,    15,    37,    17,   477,   478,    86,   107,   481,
     107,     4,   484,   485,   486,   487,   488,   489,    64,    65,
     107,   493,   494,   107,    37,   483,   520,   521,   522,   523,
      64,    65,     4,    98,     3,   507,     5,   509,    37,   263,
     512,   513,   514,    47,    47,   517,   518,   368,    99,    98,
     106,   157,   102,     4,   526,   527,   528,   102,    99,   105,
     166,   103,   556,   557,    99,    64,    65,   539,   540,    38,
      39,    40,    98,    98,   546,   547,   548,   549,   550,   551,
     348,   402,   576,   577,    36,    37,   558,   559,   560,   561,
     584,   585,   102,   414,     6,     7,     8,    99,   204,    99,
     572,   573,   574,   575,     3,    99,     5,    99,    99,     4,
     582,   583,    64,    65,    43,    43,   437,     3,    43,     5,
      99,    99,    52,    35,    98,    37,    52,    98,   141,   142,
     143,     6,     7,     8,   402,    98,   100,    99,    99,    38,
      39,    40,   155,    98,   368,   466,   159,   160,   161,   162,
     163,   164,    38,    39,    40,    99,   169,    30,    31,    99,
      35,    36,   483,     6,     7,     8,     6,     7,     8,   437,
      15,    -1,    45,     6,     7,     8,    99,    99,   402,   143,
      99,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     414,    -1,    35,    -1,    37,    35,    36,    -1,   211,    -1,
       3,   469,    35,     6,     7,     8,    79,    -1,    81,    82,
      -1,    84,    -1,   437,    -1,   483,    88,    89,    90,    91,
      92,    93,    95,    96,    27,    97,    -1,    30,   100,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    91,    92,
      93,    -1,   466,    -1,    97,    -1,    -1,   100,    -1,    -1,
     263,   264,    -1,   521,   522,   523,    -1,    -1,    -1,   483,
      -1,    64,    65,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,   245,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,   171,    -1,
      -1,   174,   105,    -1,   177,    -1,    -1,   180,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,   195,    -1,   197,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   348,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   308,    64,    65,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,   368,   320,   321,   322,   323,
     324,    -1,    -1,   469,    -1,    -1,    -1,   473,    88,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,   343,
     100,    -1,    -1,    -1,    -1,   104,   105,    -1,    -1,   402,
     263,    -1,    -1,    -1,    -1,    -1,   502,    -1,    -1,    -1,
      -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,
      -1,    -1,    -1,   377,    -1,   521,   522,   523,    -1,    -1,
      -1,    -1,    -1,    -1,   437,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   405,    -1,    -1,    97,    -1,    -1,   100,    -1,   413,
     556,   557,   105,   466,    -1,   419,   420,     3,   422,   423,
       6,     7,     8,    -1,    -1,    -1,   430,    -1,    -1,    -1,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    -1,   450,    -1,    -1,    35,
      36,    37,    38,    39,    40,   368,    -1,     3,    -1,    -1,
      -1,     3,    -1,    -1,     6,     7,     8,   471,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,   402,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    -1,
      -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     524,   525,    64,    65,   437,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   552,   553,
      -1,    97,     3,   466,   100,     6,     7,     8,    -1,   105,
      -1,   107,   104,   105,     3,     4,   570,   571,    -1,    -1,
     483,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    33,    34,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    64,    65,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,     4,    -1,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,   104,   105,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    33,    34,    35,
      36,    37,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,     4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,   104,   105,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,     4,    -1,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
     103,    -1,   105,    33,    34,    35,    36,    37,    -1,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,     4,    -1,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,   103,    -1,   105,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
       4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,   103,    -1,   105,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,     4,    -1,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,   103,
      -1,   105,    33,    34,    35,    36,    37,    -1,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,     4,    -1,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,   104,    33,    34,    35,    36,    37,    -1,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,     4,    -1,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
      -1,    -1,     3,    -1,    -1,   104,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    89,    90,    -1,    97,    -1,    99,   100,    96,
      -1,    98,    -1,    -1,    -1,    -1,   103,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,     3,     4,   100,
       6,     7,     8,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    33,    34,    35,
      36,    37,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    89,    90,    97,    -1,    -1,   100,    -1,
      96,    -1,    98,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    35,    36,    37,    38,
      39,    40,    64,    65,   105,   109,   110,   112,   113,   118,
     119,   120,   121,   122,   124,   125,   140,   141,   139,   140,
     139,   139,   139,   139,   139,     0,   110,   112,   113,   140,
     141,   140,   141,   139,   139,   139,   105,   139,     3,   105,
       4,    37,   119,   120,    36,   119,   120,     4,     4,    98,
       4,    98,   140,   141,     5,   121,   122,   124,   125,    36,
      37,   120,    36,    37,   119,   103,   107,   123,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   105,   139,   139,   139,   139,   139,   139,   139,   141,
     139,   102,   103,   119,   120,    37,   120,    37,   119,   119,
     120,    36,   120,    36,   119,    98,   102,     4,   117,   102,
     117,     4,    37,   120,    36,   120,    36,    37,    37,   119,
      36,   119,    36,    37,     4,    33,    34,    42,    46,    47,
      48,    49,    50,    55,    67,    68,    69,    70,    71,    72,
      89,    90,    96,    98,   104,   112,   118,   129,   130,   131,
     134,   135,   136,   137,   138,   104,   129,   131,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,    98,    97,   139,   139,   139,   139,   140,   141,   140,
     141,   131,   140,   141,   131,   131,   131,   131,   140,   141,
     139,   130,   139,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    97,   100,   107,   140,   141,   140,
     141,   140,   141,   140,   141,   140,   141,   140,   141,   104,
       4,    27,    30,   111,   112,   113,   114,   115,   118,   119,
     140,   141,   120,   119,   120,    37,   119,    37,   120,   119,
     120,    36,   119,    36,   116,   117,     4,   126,   127,   102,
      99,   106,   126,    99,   102,   103,   120,    37,   120,    36,
      37,    36,   119,    37,   119,    36,    37,    36,   139,     4,
      98,    47,   123,   130,    98,    98,   140,   141,    99,   104,
     139,   139,   139,   139,   139,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,     4,   131,   139,   139,   139,   139,   104,   112,   113,
     114,   115,   140,   141,   140,   141,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   131,
     132,   133,    98,   139,   139,   139,   139,   139,   139,   131,
     131,   131,   131,   131,    98,   101,   131,   103,    98,   123,
     140,   141,    27,    99,    86,   107,   126,   107,     4,   107,
     107,     4,   111,   139,   139,   139,   131,    98,    47,    47,
     131,     4,    98,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   104,    99,   106,   132,   139,
     139,   139,   139,   139,   139,   139,   132,   111,   116,    98,
     102,     4,   127,   128,   131,   131,   102,   131,   131,   103,
     139,   139,    99,   131,    98,    98,    99,   102,   117,   139,
     104,   139,   139,   139,   139,   139,   139,   131,    99,   139,
     139,   139,   139,   139,   139,   139,    99,    99,   116,   126,
      87,   106,   126,   111,   123,   130,   141,    99,   131,   131,
     105,   123,   130,   126,    99,   139,   139,   139,   104,   139,
     139,   139,   139,   139,   139,   139,   139,   102,   123,    99,
       4,   127,    43,    43,    43,    99,    99,    52,    52,   139,
     139,   139,   139,   139,   139,   139,    33,    34,   102,   123,
     123,   130,   141,   123,   130,   141,   123,   130,   141,   131,
     131,   139,   139,   139,   139,   139,    98,    98,    33,    34,
      99,    99,   139,   139,   139,   139,   139,   139,   132,   132,
      98,    98,   105,   123,   130,   105,   123,   130,   139,   139,
     139,   139,    99,    99,   132,   132,   139,   139,   139,   139,
     123,   123,    99,    99,   139,   139,   123,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   123,   123,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   134,
     134,   134,   134,   134,   134,   135,   135,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     139,   140,   140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     2,     2,    14,    10,    12,     8,     1,     1,
       1,     2,     2,     1,     1,     2,     3,     3,     2,     2,
       2,     2,     3,     3,     1,     1,     4,     3,     2,     1,
       3,    11,     9,    19,    19,    21,    21,     9,     7,    17,
      17,    19,    19,     0,     1,     5,     9,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     1,     1,     1,     1,     1,     1,     3,     5,    13,
       5,     4,     3,     3,     7,    11,    11,     7,    11,    11,
       1,     1,     7,     1,     1,     5,     5,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     1,     1,     6,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       8,     4,     3,     8,     3,     0,     1,     1,     5,     4,
       4,     4,     4,     4,     4,     9,     9,     9,    11,    11,
      10,    17,    17,    17,    17,    17,    17,     9,     9,     9,
      13,    13,    13,    13,    13,    13,    13,    13,    13,     0,
       1,     1,     2,     1,     2
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
#line 311 "synt_analyzer.y"
                {root = createProgram();}
#line 2251 "synt_analyzer.tab.cpp"
    break;

  case 3: /* program: newLines  */
#line 312 "synt_analyzer.y"
                {root = createProgram();}
#line 2257 "synt_analyzer.tab.cpp"
    break;

  case 4: /* program: class  */
#line 313 "synt_analyzer.y"
        {root = createProgram((yyvsp[0].classU));}
#line 2263 "synt_analyzer.tab.cpp"
    break;

  case 5: /* program: method  */
#line 314 "synt_analyzer.y"
                {root = createProgram((yyvsp[0].methodU));}
#line 2269 "synt_analyzer.tab.cpp"
    break;

  case 6: /* program: property semis  */
#line 315 "synt_analyzer.y"
                        {root = createProgram((yyvsp[-1].propertyU));}
#line 2275 "synt_analyzer.tab.cpp"
    break;

  case 7: /* program: property newLines  */
#line 316 "synt_analyzer.y"
                        {root = createProgram((yyvsp[-1].propertyU));}
#line 2281 "synt_analyzer.tab.cpp"
    break;

  case 8: /* program: program class  */
#line 317 "synt_analyzer.y"
                {(yyval.programU) = addToProgram((yyvsp[-1].programU), (yyvsp[0].classU));}
#line 2287 "synt_analyzer.tab.cpp"
    break;

  case 9: /* program: program method  */
#line 318 "synt_analyzer.y"
                        {(yyval.programU) = addToProgram((yyvsp[-1].programU), (yyvsp[0].methodU));}
#line 2293 "synt_analyzer.tab.cpp"
    break;

  case 10: /* program: program property semis  */
#line 319 "synt_analyzer.y"
                                {(yyval.programU) = addToProgram((yyvsp[-2].programU), (yyvsp[-1].propertyU));}
#line 2299 "synt_analyzer.tab.cpp"
    break;

  case 11: /* program: program property newLines  */
#line 320 "synt_analyzer.y"
                                {(yyval.programU) = addToProgram((yyvsp[-2].programU), (yyvsp[-1].propertyU));}
#line 2305 "synt_analyzer.tab.cpp"
    break;

  case 14: /* class: modifiers optNewLines CLASS optNewLines ID optNewLines ':' optNewLines ID optNewLines '{' optNewLines classBody '}'  */
#line 325 "synt_analyzer.y"
                                                                                                                                {(yyval.classU) = createClass((yyvsp[-13].modifiersU), (yyvsp[-9].Id), (yyvsp[-5].Id), (yyvsp[-1].classBodyU));}
#line 2311 "synt_analyzer.tab.cpp"
    break;

  case 15: /* class: modifiers optNewLines CLASS optNewLines ID optNewLines '{' optNewLines classBody '}'  */
#line 326 "synt_analyzer.y"
                                                                                        {(yyval.classU) = createClass((yyvsp[-9].modifiersU), (yyvsp[-5].Id), (yyvsp[-1].classBodyU));}
#line 2317 "synt_analyzer.tab.cpp"
    break;

  case 16: /* class: CLASS optNewLines ID optNewLines ':' optNewLines ID optNewLines '{' optNewLines classBody '}'  */
#line 327 "synt_analyzer.y"
                                                                                                {(yyval.classU) = createClass((yyvsp[-9].Id), (yyvsp[-5].Id), (yyvsp[-1].classBodyU));}
#line 2323 "synt_analyzer.tab.cpp"
    break;

  case 17: /* class: CLASS optNewLines ID optNewLines '{' optNewLines classBody '}'  */
#line 328 "synt_analyzer.y"
                                                                        {(yyval.classU) = createClass((yyvsp[-5].Id), (yyvsp[-1].classBodyU));}
#line 2329 "synt_analyzer.tab.cpp"
    break;

  case 18: /* classBody: semis  */
#line 331 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody();}
#line 2335 "synt_analyzer.tab.cpp"
    break;

  case 19: /* classBody: newLines  */
#line 332 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody();}
#line 2341 "synt_analyzer.tab.cpp"
    break;

  case 20: /* classBody: method  */
#line 333 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].methodU));}
#line 2347 "synt_analyzer.tab.cpp"
    break;

  case 21: /* classBody: property semis  */
#line 334 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));}
#line 2353 "synt_analyzer.tab.cpp"
    break;

  case 22: /* classBody: property newLines  */
#line 335 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));}
#line 2359 "synt_analyzer.tab.cpp"
    break;

  case 23: /* classBody: constructor  */
#line 336 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].constructorU));}
#line 2365 "synt_analyzer.tab.cpp"
    break;

  case 24: /* classBody: initializer  */
#line 337 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].initializerU));}
#line 2371 "synt_analyzer.tab.cpp"
    break;

  case 25: /* classBody: classBody method  */
#line 338 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].methodU));}
#line 2377 "synt_analyzer.tab.cpp"
    break;

  case 26: /* classBody: classBody property semis  */
#line 339 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU));}
#line 2383 "synt_analyzer.tab.cpp"
    break;

  case 27: /* classBody: classBody property newLines  */
#line 340 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU));}
#line 2389 "synt_analyzer.tab.cpp"
    break;

  case 29: /* classBody: classBody constructor  */
#line 342 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].constructorU));}
#line 2395 "synt_analyzer.tab.cpp"
    break;

  case 30: /* classBody: classBody initializer  */
#line 343 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].initializerU));}
#line 2401 "synt_analyzer.tab.cpp"
    break;

  case 32: /* property: modifiers optNewLines valDeclaration  */
#line 347 "synt_analyzer.y"
                                                {(yyval.propertyU) = createProperty((yyvsp[-2].modifiersU), (yyvsp[0].varOrValDeclU));}
#line 2407 "synt_analyzer.tab.cpp"
    break;

  case 33: /* property: modifiers optNewLines varDeclaration  */
#line 348 "synt_analyzer.y"
                                        {(yyval.propertyU) = createProperty((yyvsp[-2].modifiersU), (yyvsp[0].varOrValDeclU));}
#line 2413 "synt_analyzer.tab.cpp"
    break;

  case 34: /* property: valDeclaration  */
#line 349 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU));}
#line 2419 "synt_analyzer.tab.cpp"
    break;

  case 35: /* property: varDeclaration  */
#line 350 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU));}
#line 2425 "synt_analyzer.tab.cpp"
    break;

  case 36: /* method: modifiers optNewLines funcDeclaration ';'  */
#line 353 "synt_analyzer.y"
                                                        {(yyval.methodU) = createMethod((yyvsp[-3].modifiersU), (yyvsp[-1].funcDeclU));}
#line 2431 "synt_analyzer.tab.cpp"
    break;

  case 37: /* method: modifiers optNewLines func  */
#line 354 "synt_analyzer.y"
                                {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[0].funcU));}
#line 2437 "synt_analyzer.tab.cpp"
    break;

  case 38: /* method: funcDeclaration ';'  */
#line 355 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU));}
#line 2443 "synt_analyzer.tab.cpp"
    break;

  case 39: /* method: func  */
#line 356 "synt_analyzer.y"
        {(yyval.methodU) = createMethod((yyvsp[0].funcU));}
#line 2449 "synt_analyzer.tab.cpp"
    break;

  case 40: /* initializer: INIT optNewLines block  */
#line 359 "synt_analyzer.y"
                                        {(yyval.initializerU) = createInit((yyvsp[0].stmtListU));}
#line 2455 "synt_analyzer.tab.cpp"
    break;

  case 41: /* constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block  */
#line 363 "synt_analyzer.y"
                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-4].formalParamsListU), (yyvsp[0].stmtListU));}
#line 2461 "synt_analyzer.tab.cpp"
    break;

  case 42: /* constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  */
#line 364 "synt_analyzer.y"
                                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-8].visibilityModU), (yyvsp[-2].formalParamsListU));}
#line 2467 "synt_analyzer.tab.cpp"
    break;

  case 43: /* constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'  */
#line 365 "synt_analyzer.y"
                                                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-18].visibilityModU), (yyvsp[-12].formalParamsListU), "super", (yyvsp[-2].factParamsListU));}
#line 2473 "synt_analyzer.tab.cpp"
    break;

  case 44: /* constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')'  */
#line 366 "synt_analyzer.y"
                                                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-18].visibilityModU), (yyvsp[-12].formalParamsListU), "this", (yyvsp[-2].factParamsListU));}
#line 2479 "synt_analyzer.tab.cpp"
    break;

  case 45: /* constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block  */
#line 367 "synt_analyzer.y"
                                                                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-20].visibilityModU), (yyvsp[-14].formalParamsListU), "super", (yyvsp[-4].factParamsListU), (yyvsp[0].stmtListU));}
#line 2485 "synt_analyzer.tab.cpp"
    break;

  case 46: /* constructor: visibilityModifier optNewLines CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block  */
#line 368 "synt_analyzer.y"
                                                                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-20].visibilityModU), (yyvsp[-14].formalParamsListU), "this", (yyvsp[-4].factParamsListU), (yyvsp[0].stmtListU));}
#line 2491 "synt_analyzer.tab.cpp"
    break;

  case 47: /* constructor: CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines block  */
#line 369 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-4].formalParamsListU), (yyvsp[0].stmtListU));}
#line 2497 "synt_analyzer.tab.cpp"
    break;

  case 48: /* constructor: CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')'  */
#line 370 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-2].formalParamsListU));}
#line 2503 "synt_analyzer.tab.cpp"
    break;

  case 49: /* constructor: CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')'  */
#line 371 "synt_analyzer.y"
                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-12].formalParamsListU), "super", (yyvsp[-2].factParamsListU));}
#line 2509 "synt_analyzer.tab.cpp"
    break;

  case 50: /* constructor: CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')'  */
#line 372 "synt_analyzer.y"
                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-12].formalParamsListU), "this", (yyvsp[-2].factParamsListU));}
#line 2515 "synt_analyzer.tab.cpp"
    break;

  case 51: /* constructor: CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines SUPER optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block  */
#line 373 "synt_analyzer.y"
                                                                                                                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-14].formalParamsListU), "super", (yyvsp[-4].factParamsListU), (yyvsp[0].stmtListU));}
#line 2521 "synt_analyzer.tab.cpp"
    break;

  case 52: /* constructor: CONSTRUCTOR optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines THIS optNewLines '(' optNewLines optFactParams optNewLines ')' optNewLines block  */
#line 374 "synt_analyzer.y"
                                                                                                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-14].formalParamsListU), "this", (yyvsp[-4].factParamsListU), (yyvsp[0].stmtListU));}
#line 2527 "synt_analyzer.tab.cpp"
    break;

  case 53: /* optFormalParams: %empty  */
#line 377 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = 0;}
#line 2533 "synt_analyzer.tab.cpp"
    break;

  case 54: /* optFormalParams: formalParams  */
#line 378 "synt_analyzer.y"
                {(yyval.formalParamsListU) = (yyvsp[0].formalParamsListU);}
#line 2539 "synt_analyzer.tab.cpp"
    break;

  case 55: /* formalParams: ID optNewLines ':' optNewLines type  */
#line 381 "synt_analyzer.y"
                                                        {(yyval.formalParamsListU) = createFormalParamsList((yyvsp[-4].Id), (yyvsp[0].typeU));}
#line 2545 "synt_analyzer.tab.cpp"
    break;

  case 56: /* formalParams: formalParams optNewLines ',' optNewLines ID optNewLines ':' optNewLines type  */
#line 382 "synt_analyzer.y"
                                                                                {(yyval.formalParamsListU) = addToFormalParamsList((yyvsp[-8].formalParamsListU), (yyvsp[-4].Id), (yyvsp[0].typeU));}
#line 2551 "synt_analyzer.tab.cpp"
    break;

  case 57: /* modifiers: OVERRIDE  */
#line 385 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, None);}
#line 2557 "synt_analyzer.tab.cpp"
    break;

  case 58: /* modifiers: visibilityModifier  */
#line 386 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None);}
#line 2563 "synt_analyzer.tab.cpp"
    break;

  case 59: /* modifiers: inheritanceModifier  */
#line 387 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU));}
#line 2569 "synt_analyzer.tab.cpp"
    break;

  case 60: /* modifiers: ABSTRACT  */
#line 388 "synt_analyzer.y"
                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, None);}
#line 2575 "synt_analyzer.tab.cpp"
    break;

  case 61: /* modifiers: OVERRIDE optNewLines visibilityModifier  */
#line 389 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None);}
#line 2581 "synt_analyzer.tab.cpp"
    break;

  case 62: /* modifiers: OVERRIDE optNewLines inheritanceModifier  */
#line 390 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU));}
#line 2587 "synt_analyzer.tab.cpp"
    break;

  case 63: /* modifiers: OVERRIDE optNewLines ABSTRACT  */
#line 391 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None);}
#line 2593 "synt_analyzer.tab.cpp"
    break;

  case 64: /* modifiers: visibilityModifier optNewLines OVERRIDE  */
#line 392 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), None);}
#line 2599 "synt_analyzer.tab.cpp"
    break;

  case 65: /* modifiers: visibilityModifier optNewLines inheritanceModifier  */
#line 393 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2605 "synt_analyzer.tab.cpp"
    break;

  case 66: /* modifiers: visibilityModifier optNewLines ABSTRACT  */
#line 394 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), None);}
#line 2611 "synt_analyzer.tab.cpp"
    break;

  case 67: /* modifiers: inheritanceModifier optNewLines OVERRIDE  */
#line 395 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[-2].inheritanceModU));}
#line 2617 "synt_analyzer.tab.cpp"
    break;

  case 68: /* modifiers: inheritanceModifier optNewLines visibilityModifier  */
#line 396 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2623 "synt_analyzer.tab.cpp"
    break;

  case 69: /* modifiers: inheritanceModifier optNewLines ABSTRACT  */
#line 397 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[-2].inheritanceModU));}
#line 2629 "synt_analyzer.tab.cpp"
    break;

  case 70: /* modifiers: ABSTRACT optNewLines OVERRIDE  */
#line 398 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None);}
#line 2635 "synt_analyzer.tab.cpp"
    break;

  case 71: /* modifiers: ABSTRACT optNewLines visibilityModifier  */
#line 399 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), None);}
#line 2641 "synt_analyzer.tab.cpp"
    break;

  case 72: /* modifiers: ABSTRACT optNewLines inheritanceModifier  */
#line 400 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[0].inheritanceModU));}
#line 2647 "synt_analyzer.tab.cpp"
    break;

  case 73: /* modifiers: OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier  */
#line 401 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2653 "synt_analyzer.tab.cpp"
    break;

  case 74: /* modifiers: OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT  */
#line 402 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None);}
#line 2659 "synt_analyzer.tab.cpp"
    break;

  case 75: /* modifiers: OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier  */
#line 403 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2665 "synt_analyzer.tab.cpp"
    break;

  case 76: /* modifiers: OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT  */
#line 404 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU));}
#line 2671 "synt_analyzer.tab.cpp"
    break;

  case 77: /* modifiers: OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier  */
#line 405 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None);}
#line 2677 "synt_analyzer.tab.cpp"
    break;

  case 78: /* modifiers: OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier  */
#line 406 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU));}
#line 2683 "synt_analyzer.tab.cpp"
    break;

  case 79: /* modifiers: visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier  */
#line 407 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-4].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2689 "synt_analyzer.tab.cpp"
    break;

  case 80: /* modifiers: visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT  */
#line 408 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), None);}
#line 2695 "synt_analyzer.tab.cpp"
    break;

  case 81: /* modifiers: visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE  */
#line 409 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-4].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2701 "synt_analyzer.tab.cpp"
    break;

  case 82: /* modifiers: visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT  */
#line 410 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-4].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2707 "synt_analyzer.tab.cpp"
    break;

  case 83: /* modifiers: visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier  */
#line 411 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-4].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2713 "synt_analyzer.tab.cpp"
    break;

  case 84: /* modifiers: visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE  */
#line 412 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), None);}
#line 2719 "synt_analyzer.tab.cpp"
    break;

  case 85: /* modifiers: inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier  */
#line 413 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2725 "synt_analyzer.tab.cpp"
    break;

  case 86: /* modifiers: inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT  */
#line 414 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-4].inheritanceModU));}
#line 2731 "synt_analyzer.tab.cpp"
    break;

  case 87: /* modifiers: inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT  */
#line 415 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2737 "synt_analyzer.tab.cpp"
    break;

  case 88: /* modifiers: inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE  */
#line 416 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2743 "synt_analyzer.tab.cpp"
    break;

  case 89: /* modifiers: inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier  */
#line 417 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2749 "synt_analyzer.tab.cpp"
    break;

  case 90: /* modifiers: inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE  */
#line 418 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-4].inheritanceModU));}
#line 2755 "synt_analyzer.tab.cpp"
    break;

  case 91: /* modifiers: ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier  */
#line 419 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU));}
#line 2761 "synt_analyzer.tab.cpp"
    break;

  case 92: /* modifiers: ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier  */
#line 420 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None);}
#line 2767 "synt_analyzer.tab.cpp"
    break;

  case 93: /* modifiers: ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE  */
#line 421 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None);}
#line 2773 "synt_analyzer.tab.cpp"
    break;

  case 94: /* modifiers: ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier  */
#line 422 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2779 "synt_analyzer.tab.cpp"
    break;

  case 95: /* modifiers: ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE  */
#line 423 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU));}
#line 2785 "synt_analyzer.tab.cpp"
    break;

  case 96: /* modifiers: ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier  */
#line 424 "synt_analyzer.y"
                                                                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2791 "synt_analyzer.tab.cpp"
    break;

  case 97: /* modifiers: OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT  */
#line 425 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2797 "synt_analyzer.tab.cpp"
    break;

  case 98: /* modifiers: OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier  */
#line 426 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2803 "synt_analyzer.tab.cpp"
    break;

  case 99: /* modifiers: OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT  */
#line 427 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2809 "synt_analyzer.tab.cpp"
    break;

  case 100: /* modifiers: OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier  */
#line 428 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2815 "synt_analyzer.tab.cpp"
    break;

  case 101: /* modifiers: OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier  */
#line 429 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2821 "synt_analyzer.tab.cpp"
    break;

  case 102: /* modifiers: OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier  */
#line 430 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2827 "synt_analyzer.tab.cpp"
    break;

  case 103: /* modifiers: visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier optNewLines ABSTRACT  */
#line 431 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-6].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2833 "synt_analyzer.tab.cpp"
    break;

  case 104: /* modifiers: visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT optNewLines inheritanceModifier  */
#line 432 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-6].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2839 "synt_analyzer.tab.cpp"
    break;

  case 105: /* modifiers: visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT  */
#line 433 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-6].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2845 "synt_analyzer.tab.cpp"
    break;

  case 106: /* modifiers: visibilityModifier optNewLines inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE  */
#line 434 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-6].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2851 "synt_analyzer.tab.cpp"
    break;

  case 107: /* modifiers: visibilityModifier optNewLines ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE  */
#line 435 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-6].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2857 "synt_analyzer.tab.cpp"
    break;

  case 108: /* modifiers: visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier  */
#line 436 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-6].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2863 "synt_analyzer.tab.cpp"
    break;

  case 109: /* modifiers: inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier optNewLines ABSTRACT  */
#line 437 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-6].inheritanceModU));}
#line 2869 "synt_analyzer.tab.cpp"
    break;

  case 110: /* modifiers: inheritanceModifier optNewLines OVERRIDE optNewLines ABSTRACT optNewLines visibilityModifier  */
#line 438 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-6].inheritanceModU));}
#line 2875 "synt_analyzer.tab.cpp"
    break;

  case 111: /* modifiers: inheritanceModifier optNewLines visibilityModifier optNewLines ABSTRACT optNewLines OVERRIDE  */
#line 440 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), (yyvsp[-6].inheritanceModU));}
#line 2881 "synt_analyzer.tab.cpp"
    break;

  case 112: /* modifiers: inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE optNewLines ABSTRACT  */
#line 442 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), (yyvsp[-6].inheritanceModU));}
#line 2887 "synt_analyzer.tab.cpp"
    break;

  case 113: /* modifiers: inheritanceModifier optNewLines ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE  */
#line 444 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-6].inheritanceModU));}
#line 2893 "synt_analyzer.tab.cpp"
    break;

  case 114: /* modifiers: inheritanceModifier optNewLines ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier  */
#line 446 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-6].inheritanceModU));}
#line 2899 "synt_analyzer.tab.cpp"
    break;

  case 115: /* modifiers: ABSTRACT optNewLines OVERRIDE optNewLines inheritanceModifier optNewLines visibilityModifier  */
#line 448 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2905 "synt_analyzer.tab.cpp"
    break;

  case 116: /* modifiers: ABSTRACT optNewLines OVERRIDE optNewLines visibilityModifier optNewLines inheritanceModifier  */
#line 450 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2911 "synt_analyzer.tab.cpp"
    break;

  case 117: /* modifiers: ABSTRACT optNewLines visibilityModifier optNewLines OVERRIDE optNewLines inheritanceModifier  */
#line 451 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), (yyvsp[0].inheritanceModU));}
#line 2917 "synt_analyzer.tab.cpp"
    break;

  case 118: /* modifiers: ABSTRACT optNewLines visibilityModifier optNewLines inheritanceModifier optNewLines OVERRIDE  */
#line 452 "synt_analyzer.y"
                                                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-4].visibilityModU), (yyvsp[-2].inheritanceModU));}
#line 2923 "synt_analyzer.tab.cpp"
    break;

  case 119: /* modifiers: ABSTRACT optNewLines inheritanceModifier optNewLines OVERRIDE optNewLines visibilityModifier  */
#line 454 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2929 "synt_analyzer.tab.cpp"
    break;

  case 120: /* modifiers: ABSTRACT optNewLines inheritanceModifier optNewLines visibilityModifier optNewLines OVERRIDE  */
#line 456 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-4].inheritanceModU));}
#line 2935 "synt_analyzer.tab.cpp"
    break;

  case 121: /* visibilityModifier: PUBLIC  */
#line 459 "synt_analyzer.y"
                                {(yyval.visibilityModU) = Public;}
#line 2941 "synt_analyzer.tab.cpp"
    break;

  case 122: /* visibilityModifier: PRIVATE  */
#line 460 "synt_analyzer.y"
                {(yyval.visibilityModU) = Private;}
#line 2947 "synt_analyzer.tab.cpp"
    break;

  case 123: /* visibilityModifier: INTERNAL  */
#line 461 "synt_analyzer.y"
                {(yyval.visibilityModU) = Internal;}
#line 2953 "synt_analyzer.tab.cpp"
    break;

  case 124: /* visibilityModifier: PROTECTED  */
#line 462 "synt_analyzer.y"
                {(yyval.visibilityModU) = Protected;}
#line 2959 "synt_analyzer.tab.cpp"
    break;

  case 125: /* inheritanceModifier: FINAL  */
#line 466 "synt_analyzer.y"
                           {(yyval.inheritanceModU) = Final;}
#line 2965 "synt_analyzer.tab.cpp"
    break;

  case 126: /* inheritanceModifier: OPEN  */
#line 467 "synt_analyzer.y"
       {(yyval.inheritanceModU) = Open;}
#line 2971 "synt_analyzer.tab.cpp"
    break;

  case 127: /* func: funcDeclaration optNewLines block  */
#line 470 "synt_analyzer.y"
                                                {(yyval.funcU) = createFunc((yyvsp[-2].funcDeclU), (yyvsp[0].stmtListU));}
#line 2977 "synt_analyzer.tab.cpp"
    break;

  case 128: /* func: funcDeclaration optNewLines '=' optNewLines expr  */
#line 471 "synt_analyzer.y"
                                                        {(yyval.funcU) = createFunc((yyvsp[-4].funcDeclU), (yyvsp[0].exprU));}
#line 2983 "synt_analyzer.tab.cpp"
    break;

  case 129: /* funcDeclaration: FUN optNewLines ID optNewLines '(' optNewLines optFormalParams optNewLines ')' optNewLines ':' optNewLines type  */
#line 475 "synt_analyzer.y"
                                                                                                                                        {(yyval.funcDeclU) = createFuncDecl((yyvsp[-10].Id), (yyvsp[-6].formalParamsListU), (yyvsp[0].typeU));}
#line 2989 "synt_analyzer.tab.cpp"
    break;

  case 130: /* block: '{' optNewLines stmts optNewLines '}'  */
#line 479 "synt_analyzer.y"
                                                {(yyval.stmtListU) = (yyvsp[-2].stmtListU);}
#line 2995 "synt_analyzer.tab.cpp"
    break;

  case 131: /* block: '{' semis stmts '}'  */
#line 480 "synt_analyzer.y"
                        {(yyval.stmtListU) = (yyvsp[-1].stmtListU);}
#line 3001 "synt_analyzer.tab.cpp"
    break;

  case 132: /* block: '{' semis '}'  */
#line 481 "synt_analyzer.y"
                {(yyval.stmtListU) = 0;}
#line 3007 "synt_analyzer.tab.cpp"
    break;

  case 133: /* block: '{' optNewLines '}'  */
#line 482 "synt_analyzer.y"
                        {(yyval.stmtListU) = 0;}
#line 3013 "synt_analyzer.tab.cpp"
    break;

  case 134: /* varDeclaration: VAR optNewLines ID optNewLines ':' optNewLines type  */
#line 486 "synt_analyzer.y"
                                                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].Id), (yyvsp[0].typeU), 0);}
#line 3019 "synt_analyzer.tab.cpp"
    break;

  case 135: /* varDeclaration: VAR optNewLines ID optNewLines ':' optNewLines type optNewLines '=' optNewLines expr  */
#line 487 "synt_analyzer.y"
                                                                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-8].Id), (yyvsp[-4].typeU), (yyvsp[0].exprU), 0);}
#line 3025 "synt_analyzer.tab.cpp"
    break;

  case 136: /* varDeclaration: VAR optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines '=' optNewLines expr  */
#line 488 "synt_analyzer.y"
                                                                                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-6].formalParamsListU), (yyvsp[0].exprU), 0);}
#line 3031 "synt_analyzer.tab.cpp"
    break;

  case 137: /* valDeclaration: VAL optNewLines ID optNewLines ':' optNewLines type  */
#line 492 "synt_analyzer.y"
                                                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].Id), (yyvsp[0].typeU), 1);}
#line 3037 "synt_analyzer.tab.cpp"
    break;

  case 138: /* valDeclaration: VAL optNewLines ID optNewLines ':' optNewLines type optNewLines '=' optNewLines expr  */
#line 493 "synt_analyzer.y"
                                                                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-8].Id), (yyvsp[-4].typeU), (yyvsp[0].exprU), 1);}
#line 3043 "synt_analyzer.tab.cpp"
    break;

  case 139: /* valDeclaration: VAL optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines '=' optNewLines expr  */
#line 494 "synt_analyzer.y"
                                                                                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-6].formalParamsListU), (yyvsp[0].exprU), 1);}
#line 3049 "synt_analyzer.tab.cpp"
    break;

  case 140: /* type: ID  */
#line 497 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].Id));}
#line 3055 "synt_analyzer.tab.cpp"
    break;

  case 141: /* type: templateType  */
#line 498 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].templateTypeU));}
#line 3061 "synt_analyzer.tab.cpp"
    break;

  case 142: /* templateType: ID optNewLines '<' optNewLines type_seq optNewLines '>'  */
#line 501 "synt_analyzer.y"
                                                                        {(yyval.templateTypeU) = createTemplateType((yyvsp[-6].Id), (yyvsp[-2].typesListU));}
#line 3067 "synt_analyzer.tab.cpp"
    break;

  case 143: /* type_seq: ID  */
#line 504 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].Id));}
#line 3073 "synt_analyzer.tab.cpp"
    break;

  case 144: /* type_seq: templateType  */
#line 505 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].templateTypeU));}
#line 3079 "synt_analyzer.tab.cpp"
    break;

  case 145: /* type_seq: type_seq optNewLines ',' optNewLines ID  */
#line 506 "synt_analyzer.y"
                                                {(yyval.typesListU) = addToTypesList((yyvsp[-4].typesListU), (yyvsp[0].Id)); }
#line 3085 "synt_analyzer.tab.cpp"
    break;

  case 146: /* type_seq: type_seq optNewLines ',' optNewLines templateType  */
#line 507 "synt_analyzer.y"
                                                        {(yyval.typesListU) = addToTypesList((yyvsp[-4].typesListU), (yyvsp[0].templateTypeU)); }
#line 3091 "synt_analyzer.tab.cpp"
    break;

  case 147: /* stmts: stmt  */
#line 510 "synt_analyzer.y"
                {(yyval.stmtListU) = createStmtList((yyvsp[0].stmtU));}
#line 3097 "synt_analyzer.tab.cpp"
    break;

  case 148: /* stmts: stmts stmt  */
#line 511 "synt_analyzer.y"
                {(yyval.stmtListU) = addToStmtList((yyvsp[-1].stmtListU), (yyvsp[0].stmtU));}
#line 3103 "synt_analyzer.tab.cpp"
    break;

  case 149: /* stmt: property semis  */
#line 514 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].propertyU), Property);}
#line 3109 "synt_analyzer.tab.cpp"
    break;

  case 150: /* stmt: property newLines  */
#line 515 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].propertyU), Property);}
#line 3115 "synt_analyzer.tab.cpp"
    break;

  case 151: /* stmt: assignment semis  */
#line 516 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);}
#line 3121 "synt_analyzer.tab.cpp"
    break;

  case 152: /* stmt: assignment newLines  */
#line 517 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);}
#line 3127 "synt_analyzer.tab.cpp"
    break;

  case 153: /* stmt: whileLoop semis  */
#line 518 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), WhileLoop);}
#line 3133 "synt_analyzer.tab.cpp"
    break;

  case 154: /* stmt: whileLoop newLines  */
#line 519 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), WhileLoop);}
#line 3139 "synt_analyzer.tab.cpp"
    break;

  case 155: /* stmt: forLoop semis  */
#line 520 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].forLoopU), ForLoop);}
#line 3145 "synt_analyzer.tab.cpp"
    break;

  case 156: /* stmt: forLoop newLines  */
#line 521 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].forLoopU), ForLoop);}
#line 3151 "synt_analyzer.tab.cpp"
    break;

  case 157: /* stmt: doWhileLoop semis  */
#line 522 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);}
#line 3157 "synt_analyzer.tab.cpp"
    break;

  case 158: /* stmt: doWhileLoop newLines  */
#line 523 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);}
#line 3163 "synt_analyzer.tab.cpp"
    break;

  case 159: /* stmt: ifStmt semis  */
#line 524 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].ifStmtU), IfStmt);}
#line 3169 "synt_analyzer.tab.cpp"
    break;

  case 160: /* stmt: ifStmt newLines  */
#line 525 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].ifStmtU), IfStmt);}
#line 3175 "synt_analyzer.tab.cpp"
    break;

  case 161: /* stmt: expr newLines  */
#line 526 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);}
#line 3181 "synt_analyzer.tab.cpp"
    break;

  case 162: /* stmt: expr semis  */
#line 527 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);}
#line 3187 "synt_analyzer.tab.cpp"
    break;

  case 163: /* stmt: BREAK semis  */
#line 528 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Break);}
#line 3193 "synt_analyzer.tab.cpp"
    break;

  case 164: /* stmt: BREAK newLines  */
#line 529 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Break);}
#line 3199 "synt_analyzer.tab.cpp"
    break;

  case 165: /* stmt: CONTINUE semis  */
#line 530 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);}
#line 3205 "synt_analyzer.tab.cpp"
    break;

  case 166: /* stmt: CONTINUE newLines  */
#line 531 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);}
#line 3211 "synt_analyzer.tab.cpp"
    break;

  case 167: /* stmt: RETURN semis  */
#line 532 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Return);}
#line 3217 "synt_analyzer.tab.cpp"
    break;

  case 168: /* stmt: RETURN newLines  */
#line 533 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Return);}
#line 3223 "synt_analyzer.tab.cpp"
    break;

  case 169: /* stmt: RETURN expr newLines  */
#line 534 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);}
#line 3229 "synt_analyzer.tab.cpp"
    break;

  case 170: /* stmt: RETURN expr semis  */
#line 535 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);}
#line 3235 "synt_analyzer.tab.cpp"
    break;

  case 171: /* expr: ID  */
#line 538 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Id), Identificator);}
#line 3241 "synt_analyzer.tab.cpp"
    break;

  case 172: /* expr: THIS  */
#line 539 "synt_analyzer.y"
        {(yyval.exprU) = createExpr(0, This);}
#line 3247 "synt_analyzer.tab.cpp"
    break;

  case 173: /* expr: ID '(' optNewLines optFactParams optNewLines ')'  */
#line 540 "synt_analyzer.y"
                                                        {(yyval.exprU) = createExpr((yyvsp[-5].Id), (yyvsp[-2].factParamsListU), MethodCall);}
#line 3253 "synt_analyzer.tab.cpp"
    break;

  case 174: /* expr: INT  */
#line 541 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Int_v), Int);}
#line 3259 "synt_analyzer.tab.cpp"
    break;

  case 175: /* expr: FLOAT  */
#line 542 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Float_v), Float);}
#line 3265 "synt_analyzer.tab.cpp"
    break;

  case 176: /* expr: STRING  */
#line 543 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].String_v), String);}
#line 3271 "synt_analyzer.tab.cpp"
    break;

  case 177: /* expr: CHAR  */
#line 544 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Char_v), Char);}
#line 3277 "synt_analyzer.tab.cpp"
    break;

  case 178: /* expr: DOUBLE  */
#line 545 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Double_v), Double);}
#line 3283 "synt_analyzer.tab.cpp"
    break;

  case 179: /* expr: BOOLEAN  */
#line 546 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Bool_v), Boolean);}
#line 3289 "synt_analyzer.tab.cpp"
    break;

  case 180: /* expr: '(' expr ')'  */
#line 547 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-1].exprU), ExprInBrackets);}
#line 3295 "synt_analyzer.tab.cpp"
    break;

  case 181: /* expr: '!' expr  */
#line 548 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].exprU), LogicalNot);}
#line 3301 "synt_analyzer.tab.cpp"
    break;

  case 182: /* expr: '+' expr  */
#line 549 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryPlusExpr);}
#line 3307 "synt_analyzer.tab.cpp"
    break;

  case 183: /* expr: '-' expr  */
#line 550 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryMinusExpr);}
#line 3313 "synt_analyzer.tab.cpp"
    break;

  case 184: /* expr: expr '+' expr  */
#line 551 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sum);}
#line 3319 "synt_analyzer.tab.cpp"
    break;

  case 185: /* expr: expr '-' expr  */
#line 552 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sub);}
#line 3325 "synt_analyzer.tab.cpp"
    break;

  case 186: /* expr: expr '*' expr  */
#line 553 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mul);}
#line 3331 "synt_analyzer.tab.cpp"
    break;

  case 187: /* expr: expr '/' expr  */
#line 554 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Div);}
#line 3337 "synt_analyzer.tab.cpp"
    break;

  case 188: /* expr: expr '%' expr  */
#line 555 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mod);}
#line 3343 "synt_analyzer.tab.cpp"
    break;

  case 189: /* expr: expr '<' expr  */
#line 556 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Less);}
#line 3349 "synt_analyzer.tab.cpp"
    break;

  case 190: /* expr: expr '>' expr  */
#line 557 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), More);}
#line 3355 "synt_analyzer.tab.cpp"
    break;

  case 191: /* expr: expr OR expr  */
#line 558 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Or);}
#line 3361 "synt_analyzer.tab.cpp"
    break;

  case 192: /* expr: expr AND expr  */
#line 559 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), And);}
#line 3367 "synt_analyzer.tab.cpp"
    break;

  case 193: /* expr: expr EQ expr  */
#line 560 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Eq);}
#line 3373 "synt_analyzer.tab.cpp"
    break;

  case 194: /* expr: expr AEQ expr  */
#line 561 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Aeq);}
#line 3379 "synt_analyzer.tab.cpp"
    break;

  case 195: /* expr: expr NEQ expr  */
#line 562 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Neq);}
#line 3385 "synt_analyzer.tab.cpp"
    break;

  case 196: /* expr: expr NAEQ expr  */
#line 563 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Naeq);}
#line 3391 "synt_analyzer.tab.cpp"
    break;

  case 197: /* expr: expr LOEQ expr  */
#line 564 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Loeq);}
#line 3397 "synt_analyzer.tab.cpp"
    break;

  case 198: /* expr: expr MOEQ expr  */
#line 565 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Moeq);}
#line 3403 "synt_analyzer.tab.cpp"
    break;

  case 199: /* expr: expr '.' ID  */
#line 566 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].Id), FieldCalcExpr);}
#line 3409 "synt_analyzer.tab.cpp"
    break;

  case 200: /* expr: expr '.' ID '(' optNewLines optFactParams optNewLines ')'  */
#line 567 "synt_analyzer.y"
                                                                {(yyval.exprU) = createExpr((yyvsp[-7].exprU), (yyvsp[-5].Id), (yyvsp[-2].factParamsListU), MethodCalcExpr);}
#line 3415 "synt_analyzer.tab.cpp"
    break;

  case 201: /* expr: expr '[' expr ']'  */
#line 568 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-3].exprU), (yyvsp[-1].exprU), ArrayElementCall);}
#line 3421 "synt_analyzer.tab.cpp"
    break;

  case 202: /* expr: SUPER '.' ID  */
#line 569 "synt_analyzer.y"
                {(yyval.exprU) = createExpr(0, (yyvsp[0].Id), ParentFieldCall);}
#line 3427 "synt_analyzer.tab.cpp"
    break;

  case 203: /* expr: SUPER '.' ID '(' optNewLines optFactParams optNewLines ')'  */
#line 570 "synt_analyzer.y"
                                                                {(yyval.exprU) = createExpr(0, (yyvsp[-5].Id), (yyvsp[-2].factParamsListU), ParentMethodCall);}
#line 3433 "synt_analyzer.tab.cpp"
    break;

  case 204: /* expr: expr RANGE expr  */
#line 571 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Range);}
#line 3439 "synt_analyzer.tab.cpp"
    break;

  case 205: /* optFactParams: %empty  */
#line 574 "synt_analyzer.y"
                                {(yyval.factParamsListU) = 0;}
#line 3445 "synt_analyzer.tab.cpp"
    break;

  case 206: /* optFactParams: factParams  */
#line 575 "synt_analyzer.y"
                {(yyval.factParamsListU) = (yyvsp[0].factParamsListU);}
#line 3451 "synt_analyzer.tab.cpp"
    break;

  case 207: /* factParams: expr  */
#line 578 "synt_analyzer.y"
                        {(yyval.factParamsListU) = createFactParamsList((yyvsp[0].exprU));}
#line 3457 "synt_analyzer.tab.cpp"
    break;

  case 208: /* factParams: factParams optNewLines ',' optNewLines expr  */
#line 579 "synt_analyzer.y"
                                                {(yyval.factParamsListU) = addToFactParamsList((yyvsp[-4].factParamsListU), (yyvsp[0].exprU));}
#line 3463 "synt_analyzer.tab.cpp"
    break;

  case 209: /* assignment: expr '=' optNewLines expr  */
#line 582 "synt_analyzer.y"
                                        {(yyval.assignmentU) = createAssignment((yyvsp[-3].exprU), (yyvsp[0].exprU), Assign);}
#line 3469 "synt_analyzer.tab.cpp"
    break;

  case 210: /* assignment: expr ASUM optNewLines expr  */
#line 583 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-3].exprU), (yyvsp[0].exprU), Asum);}
#line 3475 "synt_analyzer.tab.cpp"
    break;

  case 211: /* assignment: expr ASUB optNewLines expr  */
#line 584 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-3].exprU), (yyvsp[0].exprU), Asub);}
#line 3481 "synt_analyzer.tab.cpp"
    break;

  case 212: /* assignment: expr ADIV optNewLines expr  */
#line 585 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-3].exprU), (yyvsp[0].exprU), Adiv);}
#line 3487 "synt_analyzer.tab.cpp"
    break;

  case 213: /* assignment: expr AMUL optNewLines expr  */
#line 586 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-3].exprU), (yyvsp[0].exprU), Amul);}
#line 3493 "synt_analyzer.tab.cpp"
    break;

  case 214: /* assignment: expr AMOD optNewLines expr  */
#line 587 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-3].exprU), (yyvsp[0].exprU), Amod);}
#line 3499 "synt_analyzer.tab.cpp"
    break;

  case 215: /* whileLoop: WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt  */
#line 590 "synt_analyzer.y"
                                                                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-4].exprU), (yyvsp[0].stmtU), 0);}
#line 3505 "synt_analyzer.tab.cpp"
    break;

  case 216: /* whileLoop: WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines block  */
#line 591 "synt_analyzer.y"
                                                                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-4].exprU), (yyvsp[0].stmtListU), 0);}
#line 3511 "synt_analyzer.tab.cpp"
    break;

  case 217: /* whileLoop: WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines ';'  */
#line 592 "synt_analyzer.y"
                                                                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-4].exprU), 0);}
#line 3517 "synt_analyzer.tab.cpp"
    break;

  case 218: /* doWhileLoop: DO optNewLines stmt optNewLines WHILE optNewLines '(' optNewLines expr optNewLines ')'  */
#line 595 "synt_analyzer.y"
                                                                                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[-8].stmtU), 1);}
#line 3523 "synt_analyzer.tab.cpp"
    break;

  case 219: /* doWhileLoop: DO optNewLines block optNewLines WHILE optNewLines '(' optNewLines expr optNewLines ')'  */
#line 596 "synt_analyzer.y"
                                                                                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[-8].stmtListU), 1);}
#line 3529 "synt_analyzer.tab.cpp"
    break;

  case 220: /* doWhileLoop: DO optNewLines WHILE optNewLines '(' optNewLines expr optNewLines ')' optNewLines  */
#line 597 "synt_analyzer.y"
                                                                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), 1);}
#line 3535 "synt_analyzer.tab.cpp"
    break;

  case 221: /* forLoop: FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines stmt  */
#line 600 "synt_analyzer.y"
                                                                                                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-12].Id), (yyvsp[-8].typeU), (yyvsp[-4].exprU), (yyvsp[0].stmtU));}
#line 3541 "synt_analyzer.tab.cpp"
    break;

  case 222: /* forLoop: FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines block  */
#line 601 "synt_analyzer.y"
                                                                                                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-12].Id), (yyvsp[-8].typeU), (yyvsp[-4].exprU), (yyvsp[0].stmtListU));}
#line 3547 "synt_analyzer.tab.cpp"
    break;

  case 223: /* forLoop: FOR optNewLines '(' optNewLines ID optNewLines ':' optNewLines type optNewLines IN optNewLines expr optNewLines ')' optNewLines ';'  */
#line 602 "synt_analyzer.y"
                                                                                                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-12].Id), (yyvsp[-8].typeU), (yyvsp[-4].exprU));}
#line 3553 "synt_analyzer.tab.cpp"
    break;

  case 224: /* forLoop: FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines stmt  */
#line 603 "synt_analyzer.y"
                                                                                                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-10].formalParamsListU), (yyvsp[-4].exprU), (yyvsp[0].stmtU));}
#line 3559 "synt_analyzer.tab.cpp"
    break;

  case 225: /* forLoop: FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines block  */
#line 604 "synt_analyzer.y"
                                                                                                                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-10].formalParamsListU), (yyvsp[-4].exprU), (yyvsp[0].stmtListU));}
#line 3565 "synt_analyzer.tab.cpp"
    break;

  case 226: /* forLoop: FOR optNewLines '(' optNewLines '(' optNewLines formalParams optNewLines ')' optNewLines IN optNewLines expr optNewLines ')' optNewLines ';'  */
#line 605 "synt_analyzer.y"
                                                                                                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-10].formalParamsListU), (yyvsp[-4].exprU));}
#line 3571 "synt_analyzer.tab.cpp"
    break;

  case 227: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt  */
#line 608 "synt_analyzer.y"
                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[0].stmtU));}
#line 3577 "synt_analyzer.tab.cpp"
    break;

  case 228: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block  */
#line 609 "synt_analyzer.y"
                                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[0].stmtListU));}
#line 3583 "synt_analyzer.tab.cpp"
    break;

  case 229: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis  */
#line 610 "synt_analyzer.y"
                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU));}
#line 3589 "synt_analyzer.tab.cpp"
    break;

  case 230: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines stmt  */
#line 611 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), (yyvsp[-4].stmtU), (yyvsp[0].stmtU));}
#line 3595 "synt_analyzer.tab.cpp"
    break;

  case 231: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines stmt  */
#line 612 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), (yyvsp[-4].stmtListU), (yyvsp[0].stmtU));}
#line 3601 "synt_analyzer.tab.cpp"
    break;

  case 232: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines stmt  */
#line 613 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), 0, (yyvsp[0].stmtU));}
#line 3607 "synt_analyzer.tab.cpp"
    break;

  case 233: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines block  */
#line 614 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), (yyvsp[-4].stmtU), (yyvsp[0].stmtListU));}
#line 3613 "synt_analyzer.tab.cpp"
    break;

  case 234: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines block  */
#line 615 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), (yyvsp[-4].stmtListU), (yyvsp[0].stmtListU));}
#line 3619 "synt_analyzer.tab.cpp"
    break;

  case 235: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines block  */
#line 616 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), 0, (yyvsp[0].stmtListU));}
#line 3625 "synt_analyzer.tab.cpp"
    break;

  case 236: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines stmt optNewLines ELSE optNewLines semis  */
#line 617 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), (yyvsp[-4].stmtU));}
#line 3631 "synt_analyzer.tab.cpp"
    break;

  case 237: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines block optNewLines ELSE optNewLines semis  */
#line 618 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU), (yyvsp[-4].stmtListU));}
#line 3637 "synt_analyzer.tab.cpp"
    break;

  case 238: /* ifStmt: IF optNewLines '(' optNewLines expr optNewLines ')' optNewLines semis optNewLines ELSE optNewLines semis  */
#line 619 "synt_analyzer.y"
                                                                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-8].exprU));}
#line 3643 "synt_analyzer.tab.cpp"
    break;


#line 3647 "synt_analyzer.tab.cpp"

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

#line 636 "synt_analyzer.y"

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
	c->anotherConstructorId = (char *)parentOrAnotherConstr;
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




struct stmtS * createStmt(struct propertyS * prop, struct assignmentS * assign, struct whileLoopS * wLoop, forLoopS * fLoop, struct ifStmtS * ifStmt, struct exprS * expr, enum stmtType type)
{
	struct stmtS * s = (struct stmtS *)malloc(sizeof(struct stmtS));
	s->property = prop;
	s->assignment = assign;
	s->whileLoop = wLoop;
	s->forLoop = fLoop;
	s->ifStmt = ifStmt;
	s->expr = expr;
	s->type = type;
	s->next = 0;
	return s;
}


struct stmtS * createStmt(struct propertyS * prop, enum stmtType type)
{
	return createStmt(prop, 0, 0, 0, 0, 0, type);
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
	e->stringOrVarName = idOrString;
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
	yyin = fopen(argv[1], "r" );
	FILE * file = fopen("tree.dot", "w");
	
    yyparse();
	
	
    return;
}




















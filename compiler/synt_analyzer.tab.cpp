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
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;

#line 82 "synt_analyzer.tab.cpp"

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
  YYSYMBOL_FILE = 67,                      /* FILE  */
  YYSYMBOL_INT = 68,                       /* INT  */
  YYSYMBOL_FLOAT = 69,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 70,                    /* DOUBLE  */
  YYSYMBOL_STRING = 71,                    /* STRING  */
  YYSYMBOL_CHAR = 72,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 73,                   /* BOOLEAN  */
  YYSYMBOL_ASUM = 74,                      /* ASUM  */
  YYSYMBOL_ASUB = 75,                      /* ASUB  */
  YYSYMBOL_ADIV = 76,                      /* ADIV  */
  YYSYMBOL_AMUL = 77,                      /* AMUL  */
  YYSYMBOL_AMOD = 78,                      /* AMOD  */
  YYSYMBOL_OR = 79,                        /* OR  */
  YYSYMBOL_AND = 80,                       /* AND  */
  YYSYMBOL_EQ = 81,                        /* EQ  */
  YYSYMBOL_AEQ = 82,                       /* AEQ  */
  YYSYMBOL_NEQ = 83,                       /* NEQ  */
  YYSYMBOL_NAEQ = 84,                      /* NAEQ  */
  YYSYMBOL_LOEQ = 85,                      /* LOEQ  */
  YYSYMBOL_MOEQ = 86,                      /* MOEQ  */
  YYSYMBOL_TRUE = 87,                      /* TRUE  */
  YYSYMBOL_FALSE = 88,                     /* FALSE  */
  YYSYMBOL_89_ = 89,                       /* '<'  */
  YYSYMBOL_90_ = 90,                       /* '>'  */
  YYSYMBOL_RANGE = 91,                     /* RANGE  */
  YYSYMBOL_92_ = 92,                       /* '+'  */
  YYSYMBOL_93_ = 93,                       /* '-'  */
  YYSYMBOL_94_ = 94,                       /* '/'  */
  YYSYMBOL_95_ = 95,                       /* '*'  */
  YYSYMBOL_96_ = 96,                       /* '%'  */
  YYSYMBOL_UMINUS = 97,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 98,                     /* UPLUS  */
  YYSYMBOL_99_ = 99,                       /* '!'  */
  YYSYMBOL_100_ = 100,                     /* '.'  */
  YYSYMBOL_101_ = 101,                     /* '('  */
  YYSYMBOL_102_ = 102,                     /* ')'  */
  YYSYMBOL_103_ = 103,                     /* '['  */
  YYSYMBOL_104_ = 104,                     /* ']'  */
  YYSYMBOL_105_ = 105,                     /* ':'  */
  YYSYMBOL_106_ = 106,                     /* ';'  */
  YYSYMBOL_107_ = 107,                     /* ','  */
  YYSYMBOL_108_ = 108,                     /* '='  */
  YYSYMBOL_109_ = 109,                     /* '{'  */
  YYSYMBOL_110_ = 110,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 111,                 /* $accept  */
  YYSYMBOL_program = 112,                  /* program  */
  YYSYMBOL_class = 113,                    /* class  */
  YYSYMBOL_classDeclarationWithoutInheritance = 114, /* classDeclarationWithoutInheritance  */
  YYSYMBOL_classDeclaration = 115,         /* classDeclaration  */
  YYSYMBOL_property = 116,                 /* property  */
  YYSYMBOL_method = 117,                   /* method  */
  YYSYMBOL_initializer = 118,              /* initializer  */
  YYSYMBOL_constructor = 119,              /* constructor  */
  YYSYMBOL_optVisibilityModifier = 120,    /* optVisibilityModifier  */
  YYSYMBOL_optFormalParams = 121,          /* optFormalParams  */
  YYSYMBOL_formalParams = 122,             /* formalParams  */
  YYSYMBOL_memberModifier = 123,           /* memberModifier  */
  YYSYMBOL_visibilityModifier = 124,       /* visibilityModifier  */
  YYSYMBOL_inheritanceModifier = 125,      /* inheritanceModifier  */
  YYSYMBOL_func = 126,                     /* func  */
  YYSYMBOL_funcDeclaration = 127,          /* funcDeclaration  */
  YYSYMBOL_block = 128,                    /* block  */
  YYSYMBOL_varDeclaration = 129,           /* varDeclaration  */
  YYSYMBOL_valDeclaration = 130,           /* valDeclaration  */
  YYSYMBOL_type = 131,                     /* type  */
  YYSYMBOL_templateType = 132,             /* templateType  */
  YYSYMBOL_type_seq = 133,                 /* type_seq  */
  YYSYMBOL_stmts = 134,                    /* stmts  */
  YYSYMBOL_stmt = 135,                     /* stmt  */
  YYSYMBOL_expr = 136,                     /* expr  */
  YYSYMBOL_optFactParams = 137,            /* optFactParams  */
  YYSYMBOL_factParams = 138,               /* factParams  */
  YYSYMBOL_assignment = 139,               /* assignment  */
  YYSYMBOL_whileLoop = 140,                /* whileLoop  */
  YYSYMBOL_doWhileLoop = 141,              /* doWhileLoop  */
  YYSYMBOL_forLoop = 142,                  /* forLoop  */
  YYSYMBOL_ifStmt = 143,                   /* ifStmt  */
  YYSYMBOL_optNewLines = 144,              /* optNewLines  */
  YYSYMBOL_newLines = 145,                 /* newLines  */
  YYSYMBOL_semis = 146                     /* semis  */
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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1949

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  111
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  491

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


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
       2,     2,     2,    99,     2,     2,     2,    96,     2,     2,
     101,   102,    95,    92,   107,    93,   100,    94,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   105,   106,
      89,   108,    90,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   103,     2,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   109,     2,   110,     2,     2,     2,     2,
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
      85,    86,    87,    88,    91,    97,    98
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   127,   128,   129,   130,   133,   134,   137,
     138,   139,   142,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   194,   198,   199,
     200,   201,   202,   203,   206,   207,   211,   212,   216,   217,
     221,   225,   226,   227,   228,   232,   233,   234,   238,   239,
     243,   247,   248,   249,   250,   254,   255,   256,   260,   261,
     262,   265,   266,   269,   270,   273,   274,   277,   278,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   349,   350,   353,   354,   357,   358,   359,   360,
     361,   362,   365,   366,   367,   370,   371,   374,   375,   376,
     377,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   395,   396,   399,   400,   403,   404
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
  "EXPECT", "INFIX", "OPEN", "FINAL", "CONST", "FILE", "INT", "FLOAT",
  "DOUBLE", "STRING", "CHAR", "BOOLEAN", "ASUM", "ASUB", "ADIV", "AMUL",
  "AMOD", "OR", "AND", "EQ", "AEQ", "NEQ", "NAEQ", "LOEQ", "MOEQ", "TRUE",
  "FALSE", "'<'", "'>'", "RANGE", "'+'", "'-'", "'/'", "'*'", "'%'",
  "UMINUS", "UPLUS", "'!'", "'.'", "'('", "')'", "'['", "']'", "':'",
  "';'", "','", "'='", "'{'", "'}'", "$accept", "program", "class",
  "classDeclarationWithoutInheritance", "classDeclaration", "property",
  "method", "initializer", "constructor", "optVisibilityModifier",
  "optFormalParams", "formalParams", "memberModifier",
  "visibilityModifier", "inheritanceModifier", "func", "funcDeclaration",
  "block", "varDeclaration", "valDeclaration", "type", "templateType",
  "type_seq", "stmts", "stmt", "expr", "optFactParams", "factParams",
  "assignment", "whileLoop", "doWhileLoop", "forLoop", "ifStmt",
  "optNewLines", "newLines", "semis", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,    60,
      62,   344,    43,    45,    47,    42,    37,   345,   346,    33,
      46,    40,    41,    91,    93,    58,    59,    44,    61,   123,
     125
};
#endif

#define YYPACT_NINF (-320)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-194)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1254,    19,  -320,    19,  -320,  -320,  -320,    19,  -320,   -76,
    -320,  -320,  -320,    19,    19,    19,    19,    29,    30,   148,
    -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
      19,    19,    19,    19,  -320,    44,    33,    19,    19,    34,
      35,    36,    38,   279,   383,  -320,   426,  1386,  -320,  1148,
      48,    52,    53,    54,    56,  1460,   650,  -320,    82,  -320,
     -10,    19,    79,  1112,   103,   112,  -320,    28,  -320,    28,
    -320,  1282,    28,  1848,  1848,  1848,  1848,  -320,  -320,    28,
     -89,   -10,  -320,    28,  -320,    28,  -320,    28,  -320,    28,
      19,    19,    19,   295,    26,  -320,    57,  -320,  -320,   147,
     295,    11,    26,    11,    11,  -320,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
     114,    28,  -320,    28,  -320,    28,  -320,    28,  -320,    28,
    -320,    28,  1534,  -320,  1608,  -320,    58,  -320,  1848,    19,
      19,    19,    19,    19,    19,    28,   130,   130,   130,  1715,
      19,  -320,  -320,   133,   149,   169,   258,  -320,    60,  -320,
    -320,   258,  -320,    65,  -320,  -320,  -320,   -55,    19,    19,
     258,  -320,    66,  -320,  -320,   258,   258,  -320,    72,  -320,
    -320,   258,    19,  1848,  1848,  1848,  1848,  1848,  1848,  1848,
    1848,  1848,  1848,  1848,  1848,  1848,  1848,  1848,  1848,  1848,
    1848,  1848,  1848,  1848,  1848,  1848,  1848,    19,   818,   740,
      42,  1848,    85,   192,  1848,    -1,   -23,   228,    19,    19,
      19,  -320,    87,  -320,  -320,  -320,  -320,    88,  -320,  -320,
    -320,    19,  -320,   136,   156,  -320,    89,  -320,  -320,  -320,
    -320,    91,  -320,  -320,  -320,    92,  -320,  -320,  -320,  -320,
      93,  -320,  -320,   191,  1631,  1631,  1631,  1631,  1631,   185,
     578,   469,   469,   469,   469,  1095,  1095,  1095,  1095,  1172,
     128,   128,   130,   130,   130,    42,  1715,  1631,  1848,  -320,
     541,  -320,   888,  1715,   144,   162,  1715,    19,    19,  -320,
    -320,   183,   145,   150,  -320,  -320,  1848,    19,    19,  -320,
    -320,  -320,  -320,    19,    86,  1631,    19,    23,   176,  -320,
     105,  1848,  1848,   157,   184,   296,    19,    19,    19,    19,
      19,  1631,   296,   299,   305,  -320,   218,   214,  -320,    19,
    1656,  1681,    19,    19,    19,    19,   296,   296,   318,   296,
     318,    19,    23,  -320,  -320,  -320,    19,   958,  -320,  -320,
    1035,   318,   224,   -93,    19,    19,    12,    20,  -320,    19,
      20,   229,   223,  1848,     4,     4,    94,  -320,  -320,  -320,
      19,    19,    19,    19,   235,    84,   249,   237,   101,   238,
      95,  1631,   304,   307,   308,   300,   318,   302,   351,    19,
      19,    19,    19,    19,    19,   151,    19,    19,    19,    19,
    -320,    19,    19,   251,   257,   364,  1848,   261,  1848,    19,
    -320,   958,   958,   958,  1848,  1848,   265,    19,    19,    12,
      19,    19,  1631,    19,  1631,   239,  -320,  -320,    28,  -320,
    -320,    28,  -320,  -320,    28,  1715,  1715,    19,   318,  1848,
     284,   -82,  1848,    19,    19,   190,   206,   318,  -320,  1631,
    -320,  -320,    19,  1631,   274,   275,    19,    19,  -320,   377,
      19,    19,  1112,  1112,  -320,  1848,  1848,  -320,  -320,  -320,
    -320,    19,    19,   290,   291,    18,    18,   -10,   -10,  -320,
    -320
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      64,   195,   128,   193,    71,    72,    74,   193,   129,     0,
      73,    70,    75,   193,   193,   193,   193,     0,     0,     0,
      77,    76,   131,   132,   135,   133,   134,   136,   137,   138,
     193,   193,   193,   193,   197,     0,     0,   193,   193,     0,
       0,     0,     0,   193,    64,    65,    64,    64,    97,   193,
       0,     0,     0,     0,     0,    64,    64,   196,     0,   194,
       0,   193,     0,    64,     0,     0,   121,   120,   123,   122,
     125,   193,   124,     0,     0,     0,     0,     1,   104,   103,
       0,     0,   100,    99,   102,   101,   108,   107,   106,   105,
     193,   193,   193,     0,     0,    36,   193,    14,    13,     0,
       0,    64,     0,    64,    64,    98,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
       0,   119,   110,   109,   112,   111,   116,   115,   114,   113,
     118,   117,    64,   198,    64,    11,   193,    57,     0,   193,
     193,   193,   193,   193,   126,   127,   141,   142,   140,   193,
     193,     8,     7,     0,     0,     0,     0,    54,   193,    32,
      34,     0,    38,   193,    16,    15,    35,     0,   193,   193,
       0,    53,   193,    31,    33,     0,     0,    40,   193,    18,
      17,     0,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,    64,    64,
     160,     0,     0,     0,     0,     0,     0,     0,   193,   193,
     193,    45,   193,    23,    20,    56,    46,   193,    24,    21,
      37,   193,    78,     0,     0,    44,   193,    22,    19,    55,
      50,   193,    28,    25,    52,   193,    30,    27,    39,    51,
     193,    29,    26,     0,   167,   168,   169,   170,   171,   150,
     151,   152,   153,   154,   155,   156,   157,   148,   149,   161,
     143,   144,   146,   145,   147,   158,   193,   166,   162,    84,
      64,    83,    64,   193,     0,     0,   193,   193,   193,   139,
      12,     0,     0,     0,    42,    43,     0,   193,   193,    41,
      47,    49,    48,   193,     0,   164,   193,   163,     0,    82,
       0,     0,     0,     0,     0,     0,   193,   193,   193,   193,
     193,    79,    66,     0,     0,   159,     0,     0,    81,   193,
     193,   193,   193,   193,   193,   193,    66,     0,     0,     0,
       0,   193,    67,    10,     9,   130,   193,    64,   176,   175,
      64,     0,     0,     0,   193,   193,    91,    85,    92,   193,
      88,     0,     0,     0,   182,   181,   193,   174,   173,   172,
     193,   193,   193,   193,     0,     0,     0,     0,     0,     0,
     193,   165,     0,     0,     0,     0,     0,     0,     0,   193,
     193,   193,   193,   193,   193,     0,   193,   193,   193,   193,
      68,   193,   193,     0,     0,     0,     0,     0,     0,   193,
      58,    64,    64,    64,     0,     0,     0,   193,   193,    95,
     193,   193,    86,   193,    89,     0,   188,   185,   191,   187,
     184,   190,   189,   186,   192,   193,   193,   193,     0,     0,
       0,     0,     0,   193,   193,     0,     0,     0,    80,    87,
      94,    93,   193,    90,     0,     0,   193,   193,    69,     0,
     193,   193,    64,    64,    96,   162,   162,   178,   177,   180,
     179,   193,   193,     0,     0,    61,    60,     0,     0,    63,
      62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,   198,
      40,  -273,   159,  -320,   314,  1517,  1685,   129,  1719,  1723,
    -319,   -21,  -320,   -50,   120,   309,  -164,  -320,  -320,  -320,
    -320,  -320,  -320,    -3,     1,    31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     351,   352,    44,    45,    46,    95,    96,   147,    97,    98,
     367,   368,   431,    47,    48,    49,   316,   317,    50,    51,
      52,    53,    54,   130,    59,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    55,    57,   297,    60,   142,   144,     1,   461,   382,
      62,    63,    64,    65,   383,     1,   160,     4,     5,     6,
     146,     1,     1,     1,    61,   462,     1,    73,    74,    75,
      76,   370,    66,    68,    80,    81,    78,    82,    84,    86,
      99,    88,   380,   104,    77,     1,    10,  -193,    67,    69,
      72,   132,   345,   241,   146,   134,   136,   138,   148,   140,
       1,     1,    11,     1,    90,    91,    92,    79,     1,     1,
      83,    85,    87,    89,   365,     1,   369,   410,   217,   299,
     131,   133,   135,   137,   139,   141,   145,   163,   164,   165,
       1,     1,     1,   177,     1,     1,     1,     1,     1,   146,
     298,  -193,   155,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,  -193,  -193,   458,
    -193,     1,   294,     1,   143,    34,    34,   228,   468,    34,
      34,    34,    34,   218,    34,   128,   221,   222,   223,   224,
     225,    70,     2,   229,    34,    57,   226,   227,    34,    34,
      34,   308,    34,   176,    34,   177,   235,   105,   290,   292,
     177,   240,   249,   230,   178,   243,   244,   219,   258,   177,
     149,     8,     9,   151,    12,   177,   400,   217,     1,   263,
     335,   383,   150,   304,   305,   309,   313,   310,   311,   312,
     143,   -59,    93,   403,   152,   103,   217,   339,   383,   161,
     162,    20,    21,   153,   288,   217,    22,    23,    24,    25,
      26,    27,   124,   125,   126,   301,   302,   303,   127,   177,
     127,   128,   300,   128,   177,    28,    29,   307,   306,   295,
      30,    31,   100,   177,   102,   321,   327,    32,   177,    33,
     328,   329,   177,   171,    34,   330,   419,   177,   217,   342,
     146,   186,   105,   322,   105,   112,   113,   114,   115,   116,
     117,   118,   453,   454,   119,   120,   121,   122,   123,   124,
     125,   126,     1,   314,   326,   127,   338,   318,   128,   343,
     320,   217,   466,   323,   324,   325,    90,    91,    92,   185,
     344,   191,   192,   353,   332,   333,   242,   217,   467,   354,
     334,   481,   482,   336,   337,    11,    12,    90,    91,    92,
     355,   356,   366,   346,   347,   348,   349,   350,    71,   381,
     383,   390,    12,    90,    91,    92,   357,   399,   401,   360,
     361,   362,   363,    20,    21,   402,   404,   406,   371,   372,
     407,   408,   409,   373,   411,   412,   427,    94,   101,    20,
      21,   384,   385,   386,   387,   428,   388,   389,   429,   433,
     447,   392,   393,   394,   460,   470,   471,   395,   396,   397,
     398,   474,   156,   157,   158,   159,   364,   405,   376,     4,
       5,     6,   485,   486,   430,     0,   413,   414,   415,   416,
     417,   418,     0,   421,   422,   423,   424,   166,   425,   426,
     105,     0,   105,   179,   180,     0,   435,     0,    10,     0,
      12,     0,     0,     0,   448,   449,   386,   450,   451,     1,
     452,  -193,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,   455,   456,   457,     0,     0,    20,    21,     0,
     464,   465,   438,   441,   444,     0,     0,   220,     0,   469,
       0,    10,    11,   472,   473,     0,     0,   475,   476,     0,
       0,     0,     1,     0,     0,     0,     0,   375,   483,   484,
     379,     0,   487,   488,     0,     0,   374,     0,     0,   378,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,     0,     0,     0,     0,
     293,     0,     0,   296,   420,     0,     0,     0,     0,     0,
       0,   437,   440,   443,     1,     2,     3,     4,     5,     6,
     436,   439,   442,     0,   117,   118,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,   127,
       0,     7,   128,     0,     8,     9,    10,    11,    12,     0,
       0,     1,     0,    13,     0,     0,     0,    14,    15,    16,
      17,    18,   478,   480,     0,     0,    19,   315,     0,     0,
       0,   477,   479,     0,     0,    20,    21,     0,     0,    22,
      23,    24,    25,    26,    27,   331,   489,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
     340,   341,     0,    30,    31,     0,     0,     0,     0,     0,
      32,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      -2,  -193,     0,     0,     2,     3,     4,     5,     6,   113,
     114,   115,   116,   117,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,   127,     0,
       7,   128,   391,     8,     9,    10,    11,    12,     0,     0,
       0,     0,    13,     0,     0,     0,    14,    15,    16,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,     0,     0,    22,    23,
      24,    25,    26,    27,     0,   432,     0,   434,     0,     0,
       0,     0,     0,   445,   446,     0,     0,    28,    29,     0,
       0,     0,    30,    31,     2,     3,     4,     5,     6,    32,
       0,    33,     0,     0,     0,     0,   143,     0,   459,     0,
       0,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     8,     9,    10,    11,    12,     0,     0,
       0,     0,    13,     0,   315,   315,    14,    15,    16,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,     0,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,    28,    29,     0,
       0,     0,    30,    31,     0,     0,     0,     0,     0,    32,
       0,    33,     0,     0,     0,     0,   143,     0,     7,     0,
     291,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,     2,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,    32,     7,    33,
       0,     8,     9,    10,    11,    12,     0,     0,   289,     0,
      13,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,     2,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,    32,     7,    33,
       0,     8,     9,    10,    11,    12,     0,     0,   319,     0,
      13,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     0,    28,    29,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,    32,     0,    33,
       0,     0,     0,     0,    34,     7,     0,   146,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     1,    20,
      21,     0,     0,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,    28,    29,     0,     0,     0,    30,    31,     0,
       0,     0,     0,     0,    32,     0,    33,     0,     0,     0,
       0,   377,     7,     0,   146,     8,     9,    10,    11,    12,
       0,     1,     0,     0,    13,     0,     0,     0,    14,    15,
      16,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     1,    20,    21,     0,     0,
      22,    23,    24,    25,    26,    27,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   127,     0,     0,   128,    28,
      29,     0,     0,     0,    30,    31,     0,     0,     0,     0,
       0,    32,     0,    33,     0,     0,     0,     0,     0,     0,
       0,   146,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,   127,     0,
       0,   128,     0,     0,    34,     0,   129,     1,     2,     3,
       4,     5,     6,  -194,   122,   123,   124,   125,   126,     0,
       0,     0,   127,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   154,     0,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
      14,    15,    16,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    21,
       0,     0,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,     0,     0,     0,    30,    31,     0,     0,
       0,     0,     0,    32,     0,    33,     0,     0,     0,     0,
      34,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,     0,   127,     0,     0,   128,    -4,     0,    34,     0,
       2,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,    14,    15,    16,    17,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    21,     0,     0,    22,    23,    24,    25,    26,    27,
      -3,     0,     0,     0,     2,     3,     4,     5,     6,     0,
       0,     0,     0,    28,    29,     0,     0,     0,    30,    31,
       0,     0,     0,     0,     0,    32,     0,    33,     0,     0,
       7,     0,     0,     8,     9,    10,    11,    12,     0,     0,
       0,     0,    13,     0,     0,     0,    14,    15,    16,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,     0,     0,    22,    23,
      24,    25,    26,    27,    -6,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     0,     0,     0,    28,    29,     0,
       0,     0,    30,    31,     0,     0,     0,     0,     0,    32,
       0,    33,     0,     0,     7,     0,     0,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
      14,    15,    16,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    21,
       0,     0,    22,    23,    24,    25,    26,    27,    -5,     0,
     167,   172,     2,     3,     4,     5,     6,   181,     0,   187,
       0,    28,    29,     0,     0,     0,    30,    31,     0,     0,
       0,     0,     0,    32,     1,    33,     0,     0,     7,     0,
       0,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,    15,    16,    17,    18,     1,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,     0,   231,     1,     0,     0,     0,   236,     0,
       0,     0,     0,     0,     0,    28,    29,   245,     0,     0,
      30,    31,   250,   254,     0,     0,     0,    32,   259,    33,
     111,   112,   113,   114,   115,   116,   117,   118,     1,     0,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
       0,   127,  -193,     0,   128,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,   127,     0,   358,   128,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   168,   173,
       0,   127,     0,   359,   128,   182,     0,   188,     0,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   169,   174,     0,   127,   170,   175,   128,   183,
       0,   189,     0,   184,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     2,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
     251,   255,     0,     0,     0,     0,   260,     0,     0,     0,
       0,     8,     9,     0,     0,   233,     0,     0,     0,   234,
     238,     0,     0,     0,   239,     0,     0,     0,     0,   247,
       0,     0,     0,   248,   252,   256,     0,     0,   253,   257,
     261,     0,     0,     0,   262,     0,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,    32,     0,    33
};

static const yytype_int16 yycheck[] =
{
       3,     0,     1,     4,     7,    55,    56,     3,    90,   102,
      13,    14,    15,    16,   107,     3,   105,     6,     7,     8,
     109,     3,     3,     3,   100,   107,     3,    30,    31,    32,
      33,   350,     3,     3,    37,    38,     3,     3,     3,     3,
      43,     3,   361,    46,     0,     3,    35,    43,    17,    18,
      19,     3,   325,   108,   109,     3,     3,     3,    61,     3,
       3,     3,    36,     3,    38,    39,    40,    36,     3,     3,
      39,    40,    41,    42,   347,     3,   349,   396,   101,   102,
      49,    50,    51,    52,    53,    54,     4,    90,    91,    92,
       3,     3,     3,    96,     3,     3,     3,     3,     3,   109,
     101,    89,    71,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   109,   108,   448,
     107,     3,    47,     3,   106,   106,   106,     4,   457,   106,
     106,   106,   106,   146,   106,   103,   149,   150,   151,   152,
     153,     3,     4,     4,   106,   154,   159,   160,   106,   106,
     106,     5,   106,   106,   106,   168,   106,    47,   218,   219,
     173,   106,   106,     4,    27,   178,   179,   146,   106,   182,
     101,    33,    34,    63,    37,   188,   102,   101,     3,   192,
     104,   107,    63,   106,   106,   106,     5,   106,   106,   106,
     106,   106,    43,   102,   101,    46,   101,   102,   107,    80,
      81,    64,    65,   101,   217,   101,    68,    69,    70,    71,
      72,    73,    94,    95,    96,   228,   229,   230,   100,   232,
     100,   103,     4,   103,   237,    87,    88,   101,   241,    47,
      92,    93,    44,   246,    46,   101,   101,    99,   251,   101,
     105,   101,   255,    94,   106,   105,   105,   260,   101,   102,
     109,   102,   142,   101,   144,    80,    81,    82,    83,    84,
      85,    86,    33,    34,    89,    90,    91,    92,    93,    94,
      95,    96,     3,   286,   101,   100,   110,   290,   103,   105,
     293,   101,   102,   296,   297,   298,    38,    39,    40,   101,
       4,   103,   104,     4,   307,   308,   177,   101,   102,     4,
     313,   475,   476,   316,   317,    36,    37,    38,    39,    40,
     102,   107,     4,   326,   327,   328,   329,   330,    19,   105,
     107,   102,    37,    38,    39,    40,   339,   102,    89,   342,
     343,   344,   345,    64,    65,   108,   108,    43,   351,   352,
      43,    43,    52,   356,    52,     4,   105,    43,    44,    64,
      65,   364,   365,   366,   367,   108,   369,   370,     4,   108,
     105,   374,   375,   376,    90,   101,   101,   380,   381,   382,
     383,     4,    73,    74,    75,    76,   346,   390,   357,     6,
       7,     8,   102,   102,   415,    -1,   399,   400,   401,   402,
     403,   404,    -1,   406,   407,   408,   409,    93,   411,   412,
     290,    -1,   292,    99,   100,    -1,   419,    -1,    35,    -1,
      37,    -1,    -1,    -1,   427,   428,   429,   430,   431,     3,
     433,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   445,   446,   447,    -1,    -1,    64,    65,    -1,
     453,   454,   421,   422,   423,    -1,    -1,   148,    -1,   462,
      -1,    35,    36,   466,   467,    -1,    -1,   470,   471,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,   357,   481,   482,
     360,    -1,   485,   486,    -1,    -1,   357,    -1,    -1,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,   224,   405,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   422,   423,     3,     4,     5,     6,     7,     8,
     421,   422,   423,    -1,    85,    86,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    30,   103,    -1,    33,    34,    35,    36,    37,    -1,
      -1,     3,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,   472,   473,    -1,    -1,    55,   288,    -1,    -1,
      -1,   472,   473,    -1,    -1,    64,    65,    -1,    -1,    68,
      69,    70,    71,    72,    73,   306,   487,   488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
     321,   322,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,   110,    -1,    -1,     4,     5,     6,     7,     8,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,
      30,   103,   373,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    68,    69,
      70,    71,    72,    73,    -1,   416,    -1,   418,    -1,    -1,
      -1,    -1,    -1,   424,   425,    -1,    -1,    87,    88,    -1,
      -1,    -1,    92,    93,     4,     5,     6,     7,     8,    99,
      -1,   101,    -1,    -1,    -1,    -1,   106,    -1,   449,    -1,
      -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,   475,   476,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,    87,    88,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,    -1,    -1,    -1,   106,    -1,    30,    -1,
     110,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    99,    30,   101,
      -1,    33,    34,    35,    36,    37,    -1,    -1,   110,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    99,    30,   101,
      -1,    33,    34,    35,    36,    37,    -1,    -1,   110,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
      -1,    -1,    -1,    -1,   106,    30,    -1,   109,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    64,
      65,    -1,    -1,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,    -1,    87,    88,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,    -1,    -1,    -1,
      -1,   106,    30,    -1,   109,    33,    34,    35,    36,    37,
      -1,     3,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    64,    65,    -1,    -1,
      68,    69,    70,    71,    72,    73,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    87,
      88,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,
      -1,   103,    -1,    -1,   106,    -1,   108,     3,     4,     5,
       6,     7,     8,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,     3,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   101,    -1,    -1,    -1,    -1,
     106,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,     0,    -1,   106,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    68,    69,    70,    71,    72,    73,
       0,    -1,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    68,    69,
      70,    71,    72,    73,     0,    -1,    -1,    -1,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,     0,    -1,
      93,    94,     4,     5,     6,     7,     8,   100,    -1,   102,
      -1,    87,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    99,     3,   101,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,     3,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,    -1,   166,     3,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,   180,    -1,    -1,
      92,    93,   185,   186,    -1,    -1,    -1,    99,   191,   101,
      79,    80,    81,    82,    83,    84,    85,    86,     3,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,    -1,   103,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,    -1,   102,   103,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    93,    94,
      -1,   100,    -1,   102,   103,   100,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    93,    94,    -1,   100,    93,    94,   103,   100,
      -1,   102,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,     4,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    33,    34,    -1,    -1,   166,    -1,    -1,    -1,   166,
     171,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,   180,   185,   186,    -1,    -1,   185,   186,
     191,    -1,    -1,    -1,   191,    -1,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    30,    33,    34,
      35,    36,    37,    42,    46,    47,    48,    49,    50,    55,
      64,    65,    68,    69,    70,    71,    72,    73,    87,    88,
      92,    93,    99,   101,   106,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   123,   124,   125,   134,   135,   136,
     139,   140,   141,   142,   143,   145,   146,   145,   144,   145,
     144,   100,   144,   144,   144,   144,     3,   146,     3,   146,
       3,   136,   146,   144,   144,   144,   144,     0,     3,   146,
     144,   144,     3,   146,     3,   146,     3,   146,     3,   146,
      38,    39,    40,   123,   125,   126,   127,   129,   130,   144,
     120,   125,   120,   123,   144,   135,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    89,
      90,    91,    92,    93,    94,    95,    96,   100,   103,   108,
     144,   146,     3,   146,     3,   146,     3,   146,     3,   146,
       3,   146,   134,   106,   134,     4,   109,   128,   144,   101,
     128,   135,   101,   101,     3,   146,   136,   136,   136,   136,
     105,   128,   128,   144,   144,   144,   125,   126,   127,   129,
     130,   123,   126,   127,   129,   130,   106,   144,    27,   125,
     125,   126,   127,   129,   130,   120,   123,   126,   127,   129,
     130,   120,   120,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   101,   144,   146,
     136,   144,   144,   144,   144,   144,   144,   144,     4,     4,
       4,   126,   127,   129,   130,   106,   126,   127,   129,   130,
     106,   108,   128,   144,   144,   126,   127,   129,   130,   106,
     126,   127,   129,   130,   126,   127,   129,   130,   106,   126,
     127,   129,   130,   144,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   144,   110,
     134,   110,   134,   136,    47,    47,   136,     4,   101,   102,
       4,   144,   144,   144,   106,   106,   144,   101,     5,   106,
     106,   106,   106,     5,   144,   136,   137,   138,   144,   110,
     144,   101,   101,   144,   144,   144,   101,   101,   105,   101,
     105,   136,   144,   144,   144,   104,   144,   144,   110,   102,
     136,   136,   102,   105,     4,   122,   144,   144,   144,   144,
     144,   121,   122,     4,     4,   102,   107,   144,   102,   102,
     144,   144,   144,   144,   121,   122,     4,   131,   132,   122,
     131,   144,   144,   144,   128,   135,   146,   106,   128,   135,
     131,   105,   102,   107,   144,   144,   144,   144,   144,   144,
     102,   136,   144,   144,   144,   144,   144,   144,   144,   102,
     102,    89,   108,   102,   108,   144,    43,    43,    43,    52,
     131,    52,     4,   144,   144,   144,   144,   144,   144,   105,
     128,   144,   144,   144,   144,   144,   144,   105,   108,     4,
     132,   133,   136,   108,   136,   144,   128,   135,   146,   128,
     135,   146,   128,   135,   146,   136,   136,   105,   144,   144,
     144,   144,   144,    33,    34,   144,   144,   144,   131,   136,
      90,    90,   107,   136,   144,   144,   102,   102,   131,   144,
     101,   101,   144,   144,     4,   144,   144,   128,   135,   128,
     135,   137,   137,   144,   144,   102,   102,   144,   144,   128,
     128
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   111,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   114,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   124,   124,   124,   124,   125,   125,   125,   126,   126,
     127,   128,   128,   128,   128,   129,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   140,   140,   140,   141,   141,   142,   142,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   144,   144,   145,   145,   146,   146
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     3,     3,     7,
       7,     3,     5,     2,     2,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     2,     4,     3,     4,
       3,     5,     5,     5,     4,     4,     4,     5,     5,     5,
       4,     4,     4,     3,     3,     4,     4,     3,    11,     9,
      19,    19,    21,    21,     0,     1,     0,     1,     5,     9,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
      13,     5,     4,     3,     3,     7,    11,    13,     7,    11,
      13,     1,     1,     7,     7,     1,     5,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     1,     1,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     0,     1,     1,     5,     4,     4,     4,     4,
       4,     4,     9,     9,     9,     8,     8,    17,    17,    17,
      17,     9,     9,     9,    13,    13,    13,    13,    13,    13,
      13,    13,    13,     0,     1,     1,     2,     1,     2
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

#line 2103 "synt_analyzer.tab.cpp"

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

#line 409 "synt_analyzer.y"

//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}




















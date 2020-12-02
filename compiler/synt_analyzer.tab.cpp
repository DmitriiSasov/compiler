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
  YYSYMBOL_103_ = 103,                     /* ';'  */
  YYSYMBOL_104_ = 104,                     /* ','  */
  YYSYMBOL_105_ = 105,                     /* '='  */
  YYSYMBOL_106_ = 106,                     /* '{'  */
  YYSYMBOL_107_ = 107,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_program = 109,                  /* program  */
  YYSYMBOL_class = 110,                    /* class  */
  YYSYMBOL_classDeclarationWithoutInheritance = 111, /* classDeclarationWithoutInheritance  */
  YYSYMBOL_classDeclaration = 112,         /* classDeclaration  */
  YYSYMBOL_property = 113,                 /* property  */
  YYSYMBOL_method = 114,                   /* method  */
  YYSYMBOL_initializer = 115,              /* initializer  */
  YYSYMBOL_constructor = 116,              /* constructor  */
  YYSYMBOL_optVisibilityModifier = 117,    /* optVisibilityModifier  */
  YYSYMBOL_optFormalParams = 118,          /* optFormalParams  */
  YYSYMBOL_formalParams = 119,             /* formalParams  */
  YYSYMBOL_memberModifier = 120,           /* memberModifier  */
  YYSYMBOL_visibilityModifier = 121,       /* visibilityModifier  */
  YYSYMBOL_inheritanceModifier = 122,      /* inheritanceModifier  */
  YYSYMBOL_func = 123,                     /* func  */
  YYSYMBOL_funcDeclaration = 124,          /* funcDeclaration  */
  YYSYMBOL_block = 125,                    /* block  */
  YYSYMBOL_varDeclaration = 126,           /* varDeclaration  */
  YYSYMBOL_valDeclaration = 127,           /* valDeclaration  */
  YYSYMBOL_type = 128,                     /* type  */
  YYSYMBOL_templateType = 129,             /* templateType  */
  YYSYMBOL_type_seq = 130,                 /* type_seq  */
  YYSYMBOL_stmts = 131,                    /* stmts  */
  YYSYMBOL_stmt = 132,                     /* stmt  */
  YYSYMBOL_expr = 133,                     /* expr  */
  YYSYMBOL_optFactParams = 134,            /* optFactParams  */
  YYSYMBOL_factParams = 135,               /* factParams  */
  YYSYMBOL_assignment = 136,               /* assignment  */
  YYSYMBOL_whileLoop = 137,                /* whileLoop  */
  YYSYMBOL_doWhileLoop = 138,              /* doWhileLoop  */
  YYSYMBOL_forLoop = 139,                  /* forLoop  */
  YYSYMBOL_ifStmt = 140,                   /* ifStmt  */
  YYSYMBOL_optNewLines = 141,              /* optNewLines  */
  YYSYMBOL_newLines = 142,                 /* newLines  */
  YYSYMBOL_semis = 143                     /* semis  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  474

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
      98,    99,    92,    89,   104,    90,    97,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,   103,
      86,   105,    87,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   101,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   106,     2,   107,     2,     2,     2,     2,
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
       0,   175,   175,   176,   177,   178,   179,   182,   183,   186,
     187,   188,   191,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   243,   247,   248,
     249,   250,   251,   252,   255,   256,   260,   261,   265,   266,
     270,   274,   275,   276,   277,   281,   282,   283,   287,   288,
     292,   296,   297,   298,   299,   303,   304,   305,   309,   310,
     311,   314,   315,   318,   319,   322,   323,   326,   327,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   398,   399,   402,   403,   406,   407,   408,
     409,   410,   411,   414,   415,   416,   419,   420,   423,   424,
     425,   426,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   444,   445,   448,   449,   452,   453
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
  "'.'", "'('", "')'", "'['", "']'", "':'", "';'", "','", "'='", "'{'",
  "'}'", "$accept", "program", "class",
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
     335,   336,   337,   338,   339,   340,    60,    62,   341,    43,
      45,    47,    42,    37,   342,   343,    33,    46,    40,    41,
      91,    93,    58,    59,    44,    61,   123,   125
};
#endif

#define YYPACT_NINF (-326)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-195)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1089,  -326,   -97,    44,  -326,  -326,  -326,    44,  -326,   -73,
    -326,  -326,  -326,    44,    44,    44,    44,    11,    11,    23,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  1495,  1495,
    1495,  1495,  -326,    58,    11,    44,    44,    11,    11,    11,
      11,   488,   220,  -326,   173,  1236,  -326,   114,    11,    11,
      11,    11,    11,  1163,   562,    44,    60,    85,     2,   116,
      35,  1015,    54,    70,    85,    37,    85,    37,   159,    85,
      37,   -24,   -24,   -24,  1573,  -326,    85,    37,   -40,     2,
      85,    37,    85,    37,    85,    37,    85,    37,    44,    44,
      44,   118,   182,  -326,    15,  -326,  -326,    95,   118,   223,
     182,   223,   223,  -326,    44,    44,    44,    44,    44,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,   167,  1495,    44,    85,    37,
      85,    37,    85,    37,    85,    37,    85,    37,    85,    37,
    -326,  1309,  -326,  1382,  1495,  -326,    11,  -326,   112,    44,
      44,    44,    44,    44,    85,    37,  -326,    44,  -326,  -326,
     211,   228,   231,   242,  -326,    22,  -326,  -326,   242,  -326,
      25,  -326,  -326,  -326,   -71,    44,    44,   242,  -326,    26,
    -326,  -326,   242,   242,  -326,    27,  -326,  -326,   242,    44,
    1495,  1495,  1495,  1495,  1495,  1664,  1685,   792,   792,   792,
     792,   367,   367,   367,   367,   450,   175,   175,   -24,   -24,
     -24,   155,  1549,  1495,  1642,    44,    12,   722,   642,    44,
    1495,   207,   213,  1495,    -1,   257,    44,    44,    44,  -326,
      28,  -326,  -326,  -326,  -326,    33,  -326,  -326,  -326,    44,
    -326,   165,   158,  -326,    34,  -326,  -326,  -326,  -326,    39,
    -326,  -326,  -326,    41,  -326,  -326,  -326,  -326,    42,  -326,
    -326,   260,  1642,  1642,  1642,  1642,  1642,    44,  -326,  1642,
     170,   172,  -326,   465,  -326,   798,  1495,  1403,   188,   193,
    1403,    44,    44,  -326,   194,    36,    63,  -326,  -326,  1495,
      44,    44,  -326,  -326,  -326,  -326,    44,  1495,  -326,    44,
     187,  -326,    44,   196,  1495,  1495,   198,   199,   294,    44,
      44,    44,    44,    44,  1642,   294,   296,   299,    44,  1495,
    -326,   205,    44,  1596,  1619,    44,    44,    44,    44,   294,
     294,   307,   294,   307,    44,    12,  -326,  -326,   214,  1642,
    -326,   867,  -326,  -326,   941,   307,   210,   -44,    44,    44,
      14,     6,  -326,    44,     6,   215,   212,  -326,    18,    18,
      48,  -326,  -326,  -326,    44,    44,    44,    44,   218,   -27,
     232,   216,   -15,   221,    50,   277,   284,   285,   278,   307,
     281,   325,    44,    44,    44,    44,    44,    44,    21,    44,
      44,    44,    44,  -326,    44,    44,   233,   229,   332,  1495,
     235,  1495,    44,  -326,   867,   867,   867,  1495,  1495,   236,
      44,    44,    14,    44,    44,  1642,    44,  1642,   141,  -326,
    -326,    37,  -326,  -326,    37,  -326,  -326,    37,  1403,  1403,
      44,   307,  1495,   250,   -41,  1495,    44,    44,   244,   245,
     307,  -326,  1642,  -326,  -326,    44,  1642,   243,   254,    44,
      44,  -326,   349,    44,    44,  1015,  1015,  -326,  1495,  1495,
    -326,  -326,  -326,  -326,    44,    44,   255,   259,     4,     4,
       2,     2,  -326,  -326
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      64,   196,   129,   194,    71,    72,    74,   194,   130,     0,
      73,    70,    75,   194,   194,   194,   194,     0,     0,     0,
      77,    76,   132,   133,   136,   134,   135,   137,     0,     0,
       0,     0,   198,     0,     0,   194,   194,     0,     0,     0,
       0,   194,    64,    65,    64,    64,    97,     0,     0,     0,
       0,     0,     0,    64,    64,   194,     0,   195,     0,     0,
       0,    64,     0,     0,   122,   121,   124,   123,     0,   126,
     125,   140,   141,   139,     0,     1,   104,   103,     0,     0,
     100,    99,   102,   101,   108,   107,   106,   105,   194,   194,
     194,     0,     0,    36,   194,    14,    13,     0,     0,    64,
       0,    64,    64,    98,   194,   194,   194,   194,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   119,   120,
     110,   109,   112,   111,   116,   115,   114,   113,   118,   117,
     197,    64,   199,    64,   163,    11,   194,    57,   160,   194,
     194,   194,   194,   194,   127,   128,   138,   194,     8,     7,
       0,     0,     0,     0,    54,   194,    32,    34,     0,    38,
     194,    16,    15,    35,     0,   194,   194,     0,    53,   194,
      31,    33,     0,     0,    40,   194,    18,    17,     0,   194,
       0,     0,     0,     0,     0,   149,   150,   151,   152,   153,
     154,   155,   156,   147,   148,   162,   142,   143,   145,   144,
     146,   157,     0,     0,   165,   194,   164,    64,    64,   194,
       0,     0,     0,     0,     0,     0,   194,   194,   194,    45,
     194,    23,    20,    56,    46,   194,    24,    21,    37,   194,
      78,     0,     0,    44,   194,    22,    19,    55,    50,   194,
      28,    25,    52,   194,    30,    27,    39,    51,   194,    29,
      26,     0,   168,   169,   170,   171,   172,   194,   159,   167,
       0,     0,    84,    64,    83,    64,   163,   194,     0,     0,
     194,   194,   194,    12,     0,     0,     0,    42,    43,     0,
     194,   194,    41,    47,    49,    48,   194,   163,   131,   194,
       0,    82,   194,     0,     0,     0,     0,     0,     0,   194,
     194,   194,   194,   194,    79,    66,     0,     0,   194,     0,
      81,     0,   194,     0,     0,   194,   194,   194,   194,    66,
       0,     0,     0,     0,   194,    67,    10,     9,     0,   166,
     161,    64,   177,   176,    64,     0,     0,     0,   194,   194,
      91,    85,    92,   194,    88,     0,     0,   158,   183,   182,
     194,   175,   174,   173,   194,   194,   194,   194,     0,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,   194,   194,   194,   194,   194,   194,     0,   194,
     194,   194,   194,    68,   194,   194,     0,     0,     0,     0,
       0,     0,   194,    58,    64,    64,    64,     0,     0,     0,
     194,   194,    95,   194,   194,    86,   194,    89,     0,   189,
     186,   192,   188,   185,   191,   190,   187,   193,   194,   194,
     194,     0,     0,     0,     0,     0,   194,   194,     0,     0,
       0,    80,    87,    94,    93,   194,    90,     0,     0,   194,
     194,    69,     0,   194,   194,    64,    64,    96,   163,   163,
     179,   178,   181,   180,   194,   194,     0,     0,    61,    60,
       0,     0,    63,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,    65,
      30,  -234,   -25,  -326,   192,  1342,  1364,   -39,  1368,  1406,
    -325,   -38,  -326,   -48,    -2,   366,  -274,  -326,  -326,  -326,
    -326,  -326,  -326,    -3,  1558,    31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     334,   335,    42,    43,    44,    93,    94,   147,    95,    96,
     351,   352,   414,    45,    46,    47,   215,   216,    48,    49,
      50,    51,    52,   174,    57,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    55,   302,   281,    58,   141,   143,     1,   354,     1,
      60,    61,    62,    63,     1,     1,    91,     1,     1,   101,
     364,     1,   150,   318,    59,     1,     1,     2,     1,     1,
       1,     1,    78,    79,   239,   146,     1,     1,    97,   158,
     159,   102,     1,   103,     1,     1,   444,     1,    65,    67,
      70,     1,   144,     1,   393,   366,     8,     9,    75,   151,
     367,  -194,   157,   445,   145,    77,   146,   168,    81,    83,
      85,    87,   383,   125,   328,   183,   126,   367,   129,   131,
     133,   135,   137,   139,   386,   160,   161,   162,   140,   367,
      22,    23,    24,    25,    26,    27,   349,   282,   353,   155,
    -194,   190,   191,   192,   193,   194,   441,    98,   146,   100,
    -194,  -194,    28,    29,    32,   451,  -194,     1,   173,    30,
     148,    31,   175,   402,   213,   233,    32,   146,   238,   247,
     256,   287,    12,   149,   310,   240,   288,   292,   311,   103,
     142,   103,   293,   217,   294,   295,   220,   221,   222,   223,
     224,   142,   152,   -59,   225,    12,    88,    89,    90,    20,
      21,   312,     1,   291,   182,   313,   188,   189,   153,   273,
     275,   211,   241,   242,   436,   437,     1,   218,  -194,     4,
       5,     6,    20,    21,   464,   465,   261,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    10,    11,
     219,   125,   270,   271,   126,   226,   276,    32,    11,   127,
      88,    89,    90,   284,   285,   286,     4,     5,     6,     4,
       5,     6,   227,    92,    99,   228,   289,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   267,   278,    10,   125,    12,    10,   126,
     279,   283,    32,   290,   297,   296,   122,   123,   124,   298,
     300,   103,   125,   103,   303,   126,   299,   306,   307,   308,
      88,    89,    90,   163,    20,    21,   304,   315,   316,   176,
     177,   305,   309,   317,   320,   322,   319,   325,   327,   321,
     336,   326,   358,   337,   340,   362,   329,   330,   331,   332,
     333,   350,   365,   357,   374,   338,   367,   382,   384,   341,
     389,   385,   344,   345,   346,   347,   387,   390,   391,   395,
     392,   355,   356,   394,   411,   410,   412,   443,   430,   359,
     416,   453,   363,   449,   450,   368,   369,   370,   371,   403,
     372,   373,   454,   457,   468,   375,   376,   377,   469,   348,
     413,   378,   379,   380,   381,   419,   422,   425,     0,     0,
       0,   388,   360,     0,     0,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   401,    68,   404,   405,   406,   407,
       0,   408,   409,     0,    71,    72,    73,    74,     0,   418,
       0,     0,   420,   423,   426,     0,     0,   431,   432,   370,
     433,   434,     0,   435,     0,     0,   460,   462,     0,     0,
       0,     0,     0,     0,     0,   438,   439,   440,     0,     0,
       0,   472,   473,   447,   448,   421,   424,   427,     0,     0,
       0,     0,   452,     0,     0,     0,   455,   456,     0,     0,
     458,   459,     0,   461,   463,   119,   120,   121,   122,   123,
     124,   466,   467,     0,   125,   470,   471,   126,     1,     2,
       3,     4,     5,     6,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     1,   212,     0,     0,     7,     0,     0,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
     214,    14,    15,    16,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,    11,    12,    88,    89,    90,    20,
      21,     0,    22,    23,    24,    25,    26,    27,  -195,   120,
     121,   122,   123,   124,     0,     0,     0,   125,     0,     0,
     126,     0,    20,    21,    28,    29,   262,   263,   264,   265,
     266,    30,    -2,    31,     0,     0,     2,     3,     4,     5,
       6,     0,  -194,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,     0,   277,     0,     0,   280,
       0,     0,     7,     0,     0,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,     0,     0,     0,    14,    15,
      16,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     2,     3,     4,     5,
       6,    28,    29,     0,     0,   314,     0,     0,    30,     0,
      31,     0,     0,   214,     0,   142,     0,     0,     0,     0,
     323,   324,     7,     0,     0,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,   339,     0,     0,    14,    15,
      16,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,    28,    29,     0,     0,     0,     0,     0,    30,     0,
      31,     0,     0,     0,     0,   142,     0,     0,     0,   274,
       0,     0,     7,     0,     0,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,   415,     0,   417,    14,    15,
      16,    17,    18,   428,   429,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,   442,     0,
       0,   446,     2,     3,     4,     5,     6,     0,     0,     0,
       0,    28,    29,     0,     0,     0,     0,     0,    30,     0,
      31,     0,     0,     0,   214,   214,     0,     0,     7,   272,
       0,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,    22,    23,    24,    25,    26,
      27,     2,     3,     4,     5,     6,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,    28,    29,   125,
       0,     0,   126,     0,    30,     0,    31,     7,     0,     0,
       8,     9,    10,    11,    12,   301,     0,     0,     0,    13,
       0,     0,     0,    14,    15,    16,    17,    18,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     0,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,    28,    29,     0,     0,
       0,     0,     0,    30,     0,    31,     0,     0,     0,     0,
      32,     7,     0,   146,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,    14,    15,    16,
      17,    18,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    21,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
      28,    29,     0,     0,     0,     0,     0,    30,     0,    31,
       0,     0,     0,     0,   361,     7,     0,   146,     8,     9,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,    28,    29,     0,     0,     0,     0,
       0,    30,     0,    31,     0,     0,     0,     0,     0,     7,
       0,   146,     8,     9,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,    14,    15,    16,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,    22,    23,    24,    25,
      26,    27,     0,    -3,     0,     0,   140,     2,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,    28,    29,
       0,     0,     0,     0,     0,    30,     0,    31,     0,     0,
       0,     0,    32,     7,     0,     0,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,    14,
      15,    16,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    -4,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,    28,    29,     0,     0,     0,     0,     0,    30,
       0,    31,     0,     0,     0,     0,     7,     0,     0,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,    14,    15,    16,    17,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    21,     0,    22,    23,    24,    25,    26,    27,    -6,
       0,     0,     0,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,     0,
       0,     0,    30,     0,    31,     0,     0,     0,     0,     7,
       0,     0,     8,     9,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,    14,    15,    16,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    -5,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,     0,     0,     0,     0,    30,     1,    31,     0,     0,
       0,     0,     7,     0,     0,     8,     9,    10,    11,    12,
       0,     0,     0,     0,    13,     0,     0,     0,    14,    15,
      16,    17,    18,   164,   169,     0,     0,    19,     0,     0,
     178,     0,   184,     0,     0,     0,    20,    21,     0,    22,
      23,    24,    25,    26,    27,   165,   170,     0,     0,   166,
     171,     0,   179,     0,   185,     0,   180,     0,   186,     0,
       0,    28,    29,     0,     0,     0,     0,     0,    30,     0,
      31,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   167,   172,     2,
     125,     0,     0,   126,   181,   229,   187,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,     0,     0,     0,   248,   252,     0,   230,     8,     9,
     257,   231,   235,     0,     0,     0,   236,     0,     0,     0,
       0,   244,     0,     0,     0,   245,   249,   253,     0,     0,
     250,   254,   258,     0,     0,     0,   259,     0,    53,     0,
       0,     0,    22,    23,    24,    25,    26,    27,     0,   232,
       0,     0,     0,     0,   237,    64,    66,    69,     0,     0,
       0,     0,     0,   246,    28,    29,     0,     0,   251,   255,
       0,    30,    76,    31,   260,    80,    82,    84,    86,     0,
       0,     0,     0,     0,     0,   128,   130,   132,   134,   136,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,     0,     0,   126,
     268,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     125,     0,   156,   126,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   125,     0,   342,   126,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,     0,   343,   126,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,   125,
       0,     0,   126,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,   125,     0,     0,   126,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,     0,     0,   126
};

static const yytype_int16 yycheck[] =
{
       3,    98,   276,     4,     7,    53,    54,     3,   333,     3,
      13,    14,    15,    16,     3,     3,    41,     3,     3,    44,
     345,     3,    61,   297,    97,     3,     3,     4,     3,     3,
       3,     3,    35,    36,   105,   106,     3,     3,    41,    78,
      79,    44,     3,    45,     3,     3,    87,     3,    17,    18,
      19,     3,    55,     3,   379,    99,    33,    34,     0,    61,
     104,    43,   102,   104,     4,    34,   106,    92,    37,    38,
      39,    40,    99,    97,   308,   100,   100,   104,    47,    48,
      49,    50,    51,    52,    99,    88,    89,    90,     3,   104,
      67,    68,    69,    70,    71,    72,   330,    98,   332,    68,
      86,   104,   105,   106,   107,   108,   431,    42,   106,    44,
     106,   105,    89,    90,   103,   440,   104,     3,   103,    96,
       4,    98,    27,   102,   127,   103,   103,   106,   103,   103,
     103,   103,    37,    98,    98,   174,   103,   103,   102,   141,
     103,   143,   103,   146,   103,   103,   149,   150,   151,   152,
     153,   103,    98,   103,   157,    37,    38,    39,    40,    64,
      65,    98,     3,     5,    99,   102,   101,   102,    98,   217,
     218,     4,   175,   176,    33,    34,     3,   146,     5,     6,
       7,     8,    64,    65,   458,   459,   189,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    35,    36,
      98,    97,   215,   216,   100,     4,   219,   103,    36,   105,
      38,    39,    40,   226,   227,   228,     6,     7,     8,     6,
       7,     8,     4,    41,    42,     4,   239,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    98,    47,    35,    97,    37,    35,   100,
      47,     4,   103,    98,   267,     5,    91,    92,    93,    99,
     273,   273,    97,   275,   277,   100,   104,   280,   281,   282,
      38,    39,    40,    91,    64,    65,    98,   290,   291,    97,
      98,    98,    98,   296,   107,    99,   299,    99,     4,   302,
       4,   102,   341,     4,    99,   344,   309,   310,   311,   312,
     313,     4,   102,    99,    99,   318,   104,    99,    86,   322,
      43,   105,   325,   326,   327,   328,   105,    43,    43,     4,
      52,   334,   335,    52,   105,   102,     4,    87,   102,   341,
     105,    98,   344,    99,    99,   348,   349,   350,   351,   388,
     353,   354,    98,     4,    99,   358,   359,   360,    99,   329,
     398,   364,   365,   366,   367,   404,   405,   406,    -1,    -1,
      -1,   374,   341,    -1,    -1,    -1,    -1,    -1,    -1,   382,
     383,   384,   385,   386,   387,    19,   389,   390,   391,   392,
      -1,   394,   395,    -1,    28,    29,    30,    31,    -1,   402,
      -1,    -1,   404,   405,   406,    -1,    -1,   410,   411,   412,
     413,   414,    -1,   416,    -1,    -1,   455,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,   430,    -1,    -1,
      -1,   470,   471,   436,   437,   404,   405,   406,    -1,    -1,
      -1,    -1,   445,    -1,    -1,    -1,   449,   450,    -1,    -1,
     453,   454,    -1,   455,   456,    88,    89,    90,    91,    92,
      93,   464,   465,    -1,    97,   468,   469,   100,     3,     4,
       5,     6,     7,     8,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     3,   126,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,
     144,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    36,    37,    38,    39,    40,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    88,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
     100,    -1,    64,    65,    89,    90,   190,   191,   192,   193,
     194,    96,     0,    98,    -1,    -1,     4,     5,     6,     7,
       8,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,   223,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   276,    -1,    -1,    -1,     4,     5,     6,     7,
       8,    89,    90,    -1,    -1,   289,    -1,    -1,    96,    -1,
      98,    -1,    -1,   297,    -1,   103,    -1,    -1,    -1,    -1,
     304,   305,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,   319,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,   107,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,   399,    -1,   401,    46,    47,
      48,    49,    50,   407,   408,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,   432,    -1,
      -1,   435,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,   458,   459,    -1,    -1,    30,   107,
      -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,     4,     5,     6,     7,     8,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    89,    90,    97,
      -1,    -1,   100,    -1,    96,    -1,    98,    30,    -1,    -1,
      33,    34,    35,    36,    37,   107,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
     103,    30,    -1,   106,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,   103,    30,    -1,   106,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    30,
      -1,   106,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    -1,     0,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,    -1,   103,    30,    -1,    -1,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,     0,    -1,    -1,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,     0,
      -1,    -1,    -1,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,     0,    -1,    -1,    -1,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,     3,    98,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    91,    92,    -1,    -1,    55,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    91,    92,    -1,    -1,    91,
      92,    -1,    98,    -1,   100,    -1,    98,    -1,   100,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    91,    92,     4,
      97,    -1,    -1,   100,    98,   163,   100,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,   182,   183,    -1,   163,    33,    34,
     188,   163,   168,    -1,    -1,    -1,   168,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,   177,   182,   183,    -1,    -1,
     182,   183,   188,    -1,    -1,    -1,   188,    -1,     0,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,   163,
      -1,    -1,    -1,    -1,   168,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,   177,    89,    90,    -1,    -1,   182,   183,
      -1,    96,    34,    98,   188,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
     101,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    99,   100,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    99,   100,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    99,   100,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    30,    33,    34,
      35,    36,    37,    42,    46,    47,    48,    49,    50,    55,
      64,    65,    67,    68,    69,    70,    71,    72,    89,    90,
      96,    98,   103,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   122,   131,   132,   133,   136,   137,
     138,   139,   140,   142,   143,    98,   141,   142,   141,    97,
     141,   141,   141,   141,   142,   143,   142,   143,   133,   142,
     143,   133,   133,   133,   133,     0,   142,   143,   141,   141,
     142,   143,   142,   143,   142,   143,   142,   143,    38,    39,
      40,   120,   122,   123,   124,   126,   127,   141,   117,   122,
     117,   120,   141,   132,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    97,   100,   105,   142,   143,
     142,   143,   142,   143,   142,   143,   142,   143,   142,   143,
       3,   131,   103,   131,   141,     4,   106,   125,     4,    98,
     125,   132,    98,    98,   142,   143,    99,   102,   125,   125,
     141,   141,   141,   122,   123,   124,   126,   127,   120,   123,
     124,   126,   127,   103,   141,    27,   122,   122,   123,   124,
     126,   127,   117,   120,   123,   124,   126,   127,   117,   117,
     141,   141,   141,   141,   141,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,     4,   133,   141,   133,   134,   135,   141,   143,    98,
     141,   141,   141,   141,   141,   141,     4,     4,     4,   123,
     124,   126,   127,   103,   123,   124,   126,   127,   103,   105,
     125,   141,   141,   123,   124,   126,   127,   103,   123,   124,
     126,   127,   123,   124,   126,   127,   103,   123,   124,   126,
     127,   141,   133,   133,   133,   133,   133,    98,   101,   133,
     141,   141,   107,   131,   107,   131,   141,   133,    47,    47,
     133,     4,    98,     4,   141,   141,   141,   103,   103,   141,
      98,     5,   103,   103,   103,   103,     5,   141,    99,   104,
     141,   107,   134,   141,    98,    98,   141,   141,   141,    98,
      98,   102,    98,   102,   133,   141,   141,   141,   134,   141,
     107,   141,    99,   133,   133,    99,   102,     4,   119,   141,
     141,   141,   141,   141,   118,   119,     4,     4,   141,   133,
      99,   141,    99,    99,   141,   141,   141,   141,   118,   119,
       4,   128,   129,   119,   128,   141,   141,    99,   125,   132,
     143,   103,   125,   132,   128,   102,    99,   104,   141,   141,
     141,   141,   141,   141,    99,   141,   141,   141,   141,   141,
     141,   141,    99,    99,    86,   105,    99,   105,   141,    43,
      43,    43,    52,   128,    52,     4,   141,   141,   141,   141,
     141,   141,   102,   125,   141,   141,   141,   141,   141,   141,
     102,   105,     4,   129,   130,   133,   105,   133,   141,   125,
     132,   143,   125,   132,   143,   125,   132,   143,   133,   133,
     102,   141,   141,   141,   141,   141,    33,    34,   141,   141,
     141,   128,   133,    87,    87,   104,   133,   141,   141,    99,
      99,   128,   141,    98,    98,   141,   141,     4,   141,   141,
     125,   132,   125,   132,   134,   134,   141,   141,    99,    99,
     141,   141,   125,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   111,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   121,   121,   121,   121,   122,   122,   122,   123,   123,
     124,   125,   125,   125,   125,   126,   126,   126,   127,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   136,
     136,   136,   136,   137,   137,   137,   138,   138,   139,   139,
     139,   139,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143
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
       2,     2,     2,     2,     2,     2,     2,     3,     3,     1,
       1,     6,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     8,     4,
       3,     8,     3,     0,     1,     1,     5,     4,     4,     4,
       4,     4,     4,     9,     9,     9,     8,     8,    17,    17,
      17,    17,     9,     9,     9,    13,    13,    13,    13,    13,
      13,    13,    13,    13,     0,     1,     1,     2,     1,     2
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

#line 2061 "synt_analyzer.tab.cpp"

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

#line 458 "synt_analyzer.y"

//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}




















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
	#include "create_tree.h"
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;
	
	struct programS * root;
	
	

#line 87 "synt_analyzer.tab.cpp"

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
  YYSYMBOL_semis = 139                     /* semis  */
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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  397

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
       0,   194,   194,   195,   196,   197,   198,   199,   200,   201,
     204,   205,   206,   207,   208,   209,   210,   211,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   226,   227,
     228,   229,   232,   233,   234,   235,   238,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   256,
     257,   260,   261,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   320,   322,
     324,   326,   328,   330,   331,   332,   334,   338,   339,   340,
     341,   345,   346,   349,   350,   354,   358,   359,   360,   361,
     365,   366,   367,   371,   372,   373,   376,   377,   380,   383,
     384,   385,   386,   389,   390,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   443,   444,   447,   448,   451,   452,   453,   454,   455,
     456,   459,   460,   461,   464,   465,   466,   469,   470,   471,
     472,   473,   474,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   492,   493,   494,   495
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
  "ifStmt", "semis", YY_NULLPTR
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

#define YYPACT_NINF (-270)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     977,  -270,    20,  -270,  -270,  -270,  -270,   159,   194,    24,
      19,    23,  -270,  -270,  -270,   147,  -270,    11,  -270,    38,
     161,    77,  -270,   196,  -270,  -270,    41,    46,   211,    95,
      52,   211,    32,   171,   -66,   -45,    44,   -41,    44,  -270,
    -270,    11,  -270,    41,    41,    61,  -270,   197,  -270,  -270,
     177,    35,   107,   168,   185,   127,   447,  -270,  1110,  -270,
    -270,  -270,    75,   661,   116,   257,   116,    56,   257,    58,
     116,   257,   116,    45,   257,    65,    44,   104,    13,   -61,
     104,   -24,    41,   125,  -270,   116,    83,   116,   115,   124,
     136,   257,   153,   257,   163,   158,   179,   140,  -270,   143,
     152,  1287,   162,   169,    11,    11,   906,  -270,  -270,  -270,
    -270,  -270,  -270,  1110,  1110,  1110,  1110,  -270,    11,    11,
    1181,  -270,   349,    11,    11,    11,    11,    11,   507,  1544,
     150,   174,   184,  -270,   675,    11,  -270,  -270,  -270,   118,
      -1,    41,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,   167,   182,   188,   170,  -270,   104,
     201,   285,   204,   205,   312,   721,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  1110,   317,
    1110,   227,   273,   280,  1110,    33,    41,    41,   555,    41,
     -51,   -51,   -51,  1360,    41,    41,  -270,  -270,  1110,  1110,
    1110,  1110,  1110,  1110,  1110,  1110,  1110,  1110,  1110,  1110,
    1110,  1110,  1110,  1110,  1110,  1110,  1110,  1110,  1110,   324,
    1110,  1110,    41,    41,    41,    41,    41,    41,  -270,  1234,
     764,    44,  -270,  -270,    11,  -270,  -270,  -270,    41,    41,
     236,   234,   333,  1110,  -270,  1110,   238,  1110,  1110,   235,
    -270,   781,  1544,   242,   237,   244,  1383,  1110,   246,   247,
    1406,   245,    44,    41,  -270,  1544,  1544,  1544,  1544,  1544,
    1566,   870,   299,   299,   299,   299,   193,   193,   193,   193,
     316,   222,   222,   -51,   -51,   -51,   248,  1321,  1544,  -270,
    -270,   824,   252,    41,    44,   104,   188,  -270,   -54,  1544,
    1544,   104,  1544,  1544,   867,  -270,  -270,  1110,  1110,   560,
    1429,  1110,  1110,   988,   104,    -8,  1110,  -270,  -270,   129,
     275,  -270,  -270,   373,  -270,  -270,   884,  1544,   281,   336,
     338,    31,   988,  1452,  1475,  -270,  -270,  -270,   341,   342,
     296,   176,  -270,   142,   188,  -270,  -270,  -270,   560,   560,
     560,  -270,  -270,  1110,  1110,  -270,   313,   322,   214,  -270,
    -270,  -270,    41,  -270,  -270,    41,  -270,  -270,    41,  1498,
    1521,  1110,  1110,   323,   345,  1061,  1121,   298,   311,  1110,
    1110,  -270,  -270,  -270,  -270,  -270,  -270,   184,   184,   315,
     348,  -270,  -270,   184,   184,  -270,  -270
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   226,     0,   117,   118,   120,   119,    53,    56,     0,
       0,     0,   122,   121,   225,     0,     3,     0,     4,     0,
      54,    55,    35,     0,    31,    30,     2,     0,    59,    57,
      58,    66,    67,    68,     0,     0,     0,     0,     0,     1,
       6,     0,     7,     9,     5,     0,    33,     0,    29,    28,
      60,    62,    61,    63,    65,    64,     0,    34,     0,   123,
     228,   227,     0,     0,    73,    74,    70,    69,    72,    71,
      88,    87,    89,    90,    91,    92,    49,     0,     0,     0,
       0,     0,     8,     0,    32,    76,    75,    80,    79,    77,
      78,    82,    81,    86,    85,    84,    83,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   161,   164,
     162,   163,   165,     0,     0,     0,     0,   129,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   124,
       0,     0,     0,    17,     0,     0,    19,    22,    21,     0,
      54,    18,    97,    98,    94,    93,    96,    95,   112,   111,
     113,   114,   115,   116,     0,    50,   136,   130,   137,     0,
       0,     0,   133,     0,     0,     0,   100,    99,   104,   103,
     101,   102,   106,   105,   110,   109,   108,   107,   191,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
     168,   169,   167,     0,   146,   145,   128,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   147,   148,   150,   149,   151,   127,     0,
       0,    49,    36,    13,     0,    23,    26,    25,    27,    20,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
      15,     0,   193,     0,   192,   188,     0,     0,     0,     0,
       0,     0,     0,   156,   166,   196,   197,   198,   199,   200,
     177,   178,   179,   180,   181,   182,   183,   184,   175,   176,
     190,   170,   171,   173,   172,   174,   185,     0,   195,   126,
      16,     0,     0,    24,    49,     0,   139,   140,     0,   131,
     132,     0,   134,   135,     0,    11,   159,     0,   191,     0,
       0,     0,     0,     0,     0,     0,   191,   187,    12,    44,
       0,   125,   138,     0,    52,    14,     0,   194,     0,   214,
     213,     0,   206,     0,     0,   203,   202,   201,     0,     0,
       0,     0,    43,    38,   141,   142,    10,   189,     0,     0,
       0,   205,   204,     0,     0,   186,     0,     0,     0,    37,
     220,   217,     0,   219,   216,     0,   221,   218,     0,     0,
       0,   191,   191,     0,     0,     0,     0,     0,     0,   191,
     191,   209,   208,   207,   212,   211,   210,    46,    45,     0,
       0,    48,    47,    40,    39,    42,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,   400,  -163,     4,     5,  -122,  -118,  -224,   -25,
      40,  1363,    22,   -11,    -9,   -70,     3,     6,   -79,  -233,
    -270,   320,    69,   155,  -269,  -270,  -270,  -270,  -270,  -270,
    -270,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,   134,   135,   136,   137,   138,   154,   155,
     139,   140,    21,    22,    23,    59,   118,   119,   157,   158,
     298,   120,   121,   122,   253,   254,   123,   124,   125,   126,
     127,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   162,   251,    24,    17,    18,    25,   292,    46,   297,
      47,    79,   236,    81,     1,    43,   237,    44,    24,    41,
      42,    25,    48,    35,    27,    49,   240,    37,    34,    30,
      33,   182,    76,   322,    60,    50,    51,   261,   160,   328,
      19,    82,    52,    45,    60,   161,   219,   340,    78,   220,
      65,    67,   323,    71,    73,    19,   128,    77,     3,     4,
       5,    80,   232,    12,    13,    83,    24,   291,    72,    25,
     320,    87,    86,    88,   350,   163,     9,    10,    11,   130,
     244,   151,   161,     3,     4,     5,   142,     6,   144,    68,
     345,   339,   148,   145,   150,   147,    12,    13,   161,    12,
      13,   153,   377,   378,   186,   187,   189,   166,   156,   168,
     389,   390,     6,    53,    54,   159,    14,    36,   194,   195,
     167,    38,   222,   223,   224,   225,   226,   227,    46,   236,
      47,   262,    66,   237,   238,   239,    61,    24,   234,   235,
      25,   326,    48,    89,    90,    49,    61,    39,    62,    63,
       1,   169,     2,     3,     4,     5,     9,    10,    11,    12,
      13,   170,    52,    95,    96,     3,     4,     5,    24,   236,
     183,    25,   171,   237,     3,     4,     5,     3,     4,     5,
      12,    13,     6,     7,     8,     9,    10,    11,   263,   197,
     173,     3,     4,     5,     6,   176,    28,    50,    51,   175,
       3,     4,     5,     6,   236,    91,     6,    74,   237,   356,
     357,    12,    13,   129,    85,   177,   321,     3,     4,     5,
       6,    93,   324,    12,    13,    12,    13,   164,   165,     6,
      31,   341,    56,    24,   293,   338,    25,   315,   178,   329,
     179,    12,    13,   336,   358,    56,     6,   373,   374,   342,
     180,   238,    14,   230,    24,   234,   235,    25,    12,    13,
     184,   188,   336,     3,     4,     5,   241,   185,   190,   191,
     192,   193,   231,   359,   242,    12,    13,   243,   360,   363,
     366,   213,   214,   215,   216,   217,   218,    56,   161,   246,
     219,   238,     6,   220,    24,   234,   235,    25,   197,    56,
      56,    57,    84,    58,    58,   382,   385,    24,   245,   331,
      25,   247,   248,   216,   217,   218,   249,   391,   392,   219,
     258,   255,   220,   395,   396,   257,   238,   259,   286,    24,
     234,   235,    25,   252,   294,   256,   295,   296,   304,   260,
     301,   306,   308,   307,   311,   312,   316,   314,   362,   365,
     368,   319,     1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   343,   287,   288,   344,   330,   348,
     347,   349,   337,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   353,   354,   355,   219,   387,   299,   220,
     300,   337,   302,   303,    -1,   214,   215,   216,   217,   218,
     388,   371,   310,   219,   393,    40,   220,   361,   364,   367,
     372,   379,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   380,   383,   386,   219,   394,   229,   220,
       1,    97,     0,     0,    14,     0,   221,     0,     0,     0,
       0,     0,   327,   252,     0,     0,   333,   334,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,     0,     0,     0,    10,    11,     0,   100,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,   369,   370,
      60,    97,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,   252,   252,     0,     0,
       0,     0,     0,     0,   252,   252,   113,   114,     0,     0,
      98,    99,     0,   115,     0,   116,    10,    11,     0,   100,
       0,   117,    14,   101,   102,   103,   104,   105,     1,     0,
       0,     0,   106,     1,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,     0,   113,   114,     0,    10,
      11,     0,   100,   115,     0,   116,   101,   102,   103,   104,
     105,   228,    61,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   113,
     114,     0,   219,     0,     0,   220,   115,     0,   116,     0,
      14,     0,     0,    56,     1,    14,     0,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     3,     4,     5,     0,     0,     0,     0,   131,     0,
       0,   132,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,   131,     0,     0,   132,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     1,    12,    13,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,     0,     0,     0,   131,     0,
       0,   132,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,     0,     0,     0,   133,    14,     1,     0,     0,
       3,     4,     5,     0,     0,     0,     0,     0,     0,   233,
      14,     0,     0,     0,     1,    12,    13,     3,     4,     5,
       0,   131,     0,     0,   132,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,     0,     0,     0,   131,     0,
       0,   132,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,     0,     0,     0,   250,    14,     1,    12,    13,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,   131,     0,     0,   132,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,     0,     0,     0,   290,    14,
       1,     0,     0,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,    14,     1,    12,    13,
       3,     4,     5,     0,   131,     0,     0,   132,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    11,     0,     1,
      97,   131,     0,     0,   132,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,     0,     0,     0,   318,    14,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    98,
      99,     0,     0,     0,     0,     0,     0,     0,    12,    13,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,     0,     0,     0,   219,     0,     0,
     220,   325,    14,   107,   108,   109,   110,   111,   112,     0,
       1,     0,     2,     3,     4,     5,     0,     0,   346,    14,
       0,     0,    97,     0,     0,   113,   114,     0,     0,     0,
       0,     0,   115,     0,   116,     0,     0,     0,     0,     0,
       0,    14,     6,     7,     8,     9,    10,    11,     0,     0,
       0,    98,    99,     0,     0,     0,     0,    10,    11,     0,
     100,     0,     0,     0,   101,   102,   103,   104,   105,     0,
       0,    12,    13,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,    14,     0,   115,     0,   116,     0,     0,     0,
       0,    56,     0,   335,    98,    99,     0,     0,     0,     0,
      10,    11,     0,   100,     0,     0,     0,   101,   102,   103,
     104,   105,     0,     0,    97,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,     0,     0,     0,     0,     0,
     113,   114,     0,     0,    98,    99,     0,   115,     0,   116,
      10,    11,     0,   100,    56,     0,   381,   101,   102,   103,
     104,   105,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,     0,     0,    97,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,     0,   115,     0,   116,     0,
     113,   114,     0,     0,    98,    99,     0,   115,     0,   116,
      10,    11,     0,   100,    56,     0,   384,   101,   102,   103,
     104,   105,     0,     0,     0,     0,   106,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
     113,   114,     0,    10,    11,     0,   100,   115,     0,   116,
     101,   102,   103,   104,   105,   196,     0,     0,     0,   106,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,   113,   114,     0,    10,    11,     0,   100,
     115,     0,   116,   101,   181,   103,   104,   105,   289,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
      29,    32,     0,     0,     0,     0,   113,   114,    20,     0,
       0,     0,     0,   115,    55,   116,     0,     0,     0,     0,
      56,    64,     0,    69,    70,     0,    75,     0,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,    92,    94,   219,     0,
       0,   220,   317,     0,     0,     0,     0,     0,   143,     0,
       0,   146,     0,     0,   149,     0,     0,   152,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   172,     0,   174,   219,     0,   264,
     220,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,     0,     0,     0,
     219,     0,   309,   220,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
       0,     0,     0,   219,     0,   313,   220,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,     0,     0,     0,   219,     0,   332,   220,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,     0,     0,   219,
       0,   351,   220,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     0,
       0,     0,   219,     0,   352,   220,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,     0,     0,     0,   219,     0,   375,   220,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,     0,     0,   219,     0,
     376,   220,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,     0,
       0,   219,     0,     0,   220,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
       0,     0,     0,   219,     0,     0,   220
};

static const yytype_int16 yycheck[] =
{
       0,    80,   165,     0,     0,     0,     0,   231,    19,   242,
      19,    36,   134,    38,     3,    15,   134,    17,    15,    15,
      15,    15,    19,     4,     4,    19,    27,     4,     4,     7,
       8,   101,    98,    87,     3,    36,    37,     4,    99,   308,
       0,    41,    20,     5,     3,   106,    97,   316,     4,   100,
      28,    29,   106,    31,    32,    15,    56,   102,     6,     7,
       8,   102,   132,    64,    65,     4,    63,   230,    36,    63,
     294,    36,    50,    51,    43,    99,    38,    39,    40,     4,
     159,    36,   106,     6,     7,     8,    64,    35,    66,    37,
     323,    99,    70,    37,    72,    37,    64,    65,   106,    64,
      65,    36,   371,   372,   104,   105,   106,    85,     4,    87,
     379,   380,    35,    36,    37,   102,   105,    98,   118,   119,
      37,    98,   122,   123,   124,   125,   126,   127,   139,   251,
     139,    98,    37,   251,   134,   135,   105,   134,   134,   134,
     134,   304,   139,    36,    37,   139,   105,     0,   102,   103,
       3,    36,     5,     6,     7,     8,    38,    39,    40,    64,
      65,    37,   140,    36,    37,     6,     7,     8,   165,   291,
     101,   165,    36,   291,     6,     7,     8,     6,     7,     8,
      64,    65,    35,    36,    37,    38,    39,    40,   188,   120,
      37,     6,     7,     8,    35,    37,    37,    36,    37,    36,
       6,     7,     8,    35,   326,    37,    35,    36,   326,    33,
      34,    64,    65,    58,    37,    36,   295,     6,     7,     8,
      35,    36,   301,    64,    65,    64,    65,   102,   103,    35,
      36,   102,   103,   230,   234,   314,   230,   262,    98,   309,
      97,    64,    65,   313,   102,   103,    35,    33,    34,   319,
      98,   251,   105,   103,   251,   251,   251,   251,    64,    65,
      98,   106,   332,     6,     7,     8,    99,    98,   113,   114,
     115,   116,    98,   343,    86,    64,    65,   107,   348,   349,
     350,    88,    89,    90,    91,    92,    93,   103,   106,     4,
      97,   291,    35,   100,   291,   291,   291,   291,   229,   103,
     103,   105,   105,   107,   107,   375,   376,   304,   107,   309,
     304,   107,   107,    91,    92,    93,     4,   387,   388,    97,
      47,     4,   100,   393,   394,    98,   326,    47,     4,   326,
     326,   326,   326,   178,    98,   180,   102,     4,   103,   184,
     102,    99,    98,   106,    98,    98,    98,   102,   348,   349,
     350,    99,     3,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    99,   220,   221,     4,   309,    43,
      99,    43,   313,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    52,    52,    99,    97,    99,   243,   100,
     245,   332,   247,   248,    88,    89,    90,    91,    92,    93,
      99,    98,   257,    97,    99,    15,   100,   348,   349,   350,
      98,    98,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    98,   375,   376,    97,    99,   128,   100,
       3,     4,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,   307,   308,    -1,    -1,   311,   312,    -1,    -1,
      -1,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,   353,   354,
       3,     4,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,   371,   372,    -1,    -1,
      -1,    -1,    -1,    -1,   379,   380,    89,    90,    -1,    -1,
      33,    34,    -1,    96,    -1,    98,    39,    40,    -1,    42,
      -1,   104,   105,    46,    47,    48,    49,    50,     3,    -1,
      -1,    -1,    55,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    89,    90,    -1,    39,
      40,    -1,    42,    96,    -1,    98,    46,    47,    48,    49,
      50,   104,   105,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    89,
      90,    -1,    97,    -1,    -1,   100,    96,    -1,    98,    -1,
     105,    -1,    -1,   103,     3,   105,    -1,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,     7,     8,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    64,    65,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,   104,   105,     3,    -1,    -1,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,    -1,    -1,    -1,     3,    64,    65,     6,     7,     8,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,   104,   105,     3,    64,    65,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,   104,   105,
       3,    -1,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,     3,    64,    65,
       6,     7,     8,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    -1,     3,
       4,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,   104,   105,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
     100,   104,   105,    67,    68,    69,    70,    71,    72,    -1,
       3,    -1,     5,     6,     7,     8,    -1,    -1,   104,   105,
      -1,    -1,     4,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    64,    65,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      -1,    -1,   105,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,   103,    -1,   105,    33,    34,    -1,    -1,    -1,    -1,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,     4,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    33,    34,    -1,    96,    -1,    98,
      39,    40,    -1,    42,   103,    -1,   105,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    67,    68,    69,
      70,    71,    72,    -1,    -1,     4,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,
      89,    90,    -1,    -1,    33,    34,    -1,    96,    -1,    98,
      39,    40,    -1,    42,   103,    -1,   105,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      89,    90,    -1,    39,    40,    -1,    42,    96,    -1,    98,
      46,    47,    48,    49,    50,   104,    -1,    -1,    -1,    55,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    89,    90,    -1,    39,    40,    -1,    42,
      96,    -1,    98,    46,    47,    48,    49,    50,   104,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,    -1,    -1,    -1,    -1,    89,    90,    15,    -1,
      -1,    -1,    -1,    96,    21,    98,    -1,    -1,    -1,    -1,
     103,    28,    -1,    30,    31,    -1,    33,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    53,    54,    97,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    -1,    -1,    71,    -1,    -1,    74,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    91,    -1,    93,    97,    -1,    99,
     100,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    99,   100,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    99,   100,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    99,   100,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    99,   100,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    99,   100,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    97,    -1,    99,   100,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      99,   100,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    35,    36,    37,    38,
      39,    40,    64,    65,   105,   109,   110,   112,   113,   118,
     119,   120,   121,   122,   124,   125,   139,     4,    37,   119,
     120,    36,   119,   120,     4,     4,    98,     4,    98,     0,
     110,   112,   113,   139,   139,     5,   121,   122,   124,   125,
      36,    37,   120,    36,    37,   119,   103,   105,   107,   123,
       3,   105,   102,   103,   119,   120,    37,   120,    37,   119,
     119,   120,    36,   120,    36,   119,    98,   102,     4,   117,
     102,   117,   139,     4,   105,    37,   120,    36,   120,    36,
      37,    37,   119,    36,   119,    36,    37,     4,    33,    34,
      42,    46,    47,    48,    49,    50,    55,    67,    68,    69,
      70,    71,    72,    89,    90,    96,    98,   104,   124,   125,
     129,   130,   131,   134,   135,   136,   137,   138,   139,   131,
       4,    27,    30,   104,   111,   112,   113,   114,   115,   118,
     119,   139,   120,   119,   120,    37,   119,    37,   120,   119,
     120,    36,   119,    36,   116,   117,     4,   126,   127,   102,
      99,   106,   126,    99,   102,   103,   120,    37,   120,    36,
      37,    36,   119,    37,   119,    36,    37,    36,    98,    97,
      98,    47,   123,   130,    98,    98,   139,   139,   131,   139,
     131,   131,   131,   131,   139,   139,   104,   130,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    97,
     100,   107,   139,   139,   139,   139,   139,   139,   104,   129,
     103,    98,   123,   104,   112,   113,   114,   115,   139,   139,
      27,    99,    86,   107,   126,   107,     4,   107,   107,     4,
     104,   111,   131,   132,   133,     4,   131,    98,    47,    47,
     131,     4,    98,   139,    99,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,     4,   131,   131,   104,
     104,   111,   116,   139,    98,   102,     4,   127,   128,   131,
     131,   102,   131,   131,   103,   104,    99,   106,    98,    99,
     131,    98,    98,    99,   102,   117,    98,   101,   104,    99,
     116,   126,    87,   106,   126,   104,   111,   131,   132,   123,
     130,   139,    99,   131,   131,   105,   123,   130,   126,    99,
     132,   102,   123,    99,     4,   127,   104,    99,    43,    43,
      43,    99,    99,    52,    52,    99,    33,    34,   102,   123,
     123,   130,   139,   123,   130,   139,   123,   130,   139,   131,
     131,    98,    98,    33,    34,    99,    99,   132,   132,    98,
      98,   105,   123,   130,   105,   123,   130,    99,    99,   132,
     132,   123,   123,    99,    99,   123,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   113,   113,   113,   113,   114,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   119,
     119,   120,   120,   121,   121,   122,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   125,   126,   126,   127,   128,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   139,   139,   139,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     3,     2,
       8,     6,     7,     5,     7,     5,     6,     4,     1,     1,
       2,     1,     1,     2,     3,     2,     2,     2,     2,     2,
       1,     1,     3,     2,     2,     1,     2,     6,     5,    10,
      10,    11,    11,     5,     4,     9,     9,    10,    10,     0,
       1,     3,     5,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     2,     3,     7,     4,     3,     3,     2,
       4,     6,     6,     4,     6,     6,     1,     1,     4,     1,
       1,     3,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     4,     3,     6,
       3,     0,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     5,     5,     5,     6,     6,     5,     9,     9,     9,
       9,     9,     9,     5,     5,     5,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     1,     1,     2,     2
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
#line 194 "synt_analyzer.y"
                {root = createProgram(); puts("program created");}
#line 2023 "synt_analyzer.tab.cpp"
    break;

  case 3: /* program: class  */
#line 195 "synt_analyzer.y"
        {root = createProgram((yyvsp[0].classU));puts("program created");}
#line 2029 "synt_analyzer.tab.cpp"
    break;

  case 4: /* program: method  */
#line 196 "synt_analyzer.y"
                {root = createProgram((yyvsp[0].methodU));puts("program created");}
#line 2035 "synt_analyzer.tab.cpp"
    break;

  case 5: /* program: property semis  */
#line 197 "synt_analyzer.y"
                        {root = createProgram((yyvsp[-1].propertyU));puts("program created");}
#line 2041 "synt_analyzer.tab.cpp"
    break;

  case 6: /* program: program class  */
#line 198 "synt_analyzer.y"
                {(yyval.programU) = addToProgram((yyvsp[-1].programU), (yyvsp[0].classU));puts("class added to prog");}
#line 2047 "synt_analyzer.tab.cpp"
    break;

  case 7: /* program: program method  */
#line 199 "synt_analyzer.y"
                        {(yyval.programU) = addToProgram((yyvsp[-1].programU), (yyvsp[0].methodU));puts("meth added to prog");}
#line 2053 "synt_analyzer.tab.cpp"
    break;

  case 8: /* program: program property semis  */
#line 200 "synt_analyzer.y"
                                {(yyval.programU) = addToProgram((yyvsp[-2].programU), (yyvsp[-1].propertyU));puts("prop added to prog");}
#line 2059 "synt_analyzer.tab.cpp"
    break;

  case 10: /* class: modifiers CLASS ID ':' ID '{' classBody '}'  */
#line 204 "synt_analyzer.y"
                                                        {(yyval.classU) = createClass((yyvsp[-7].modifiersU), (yyvsp[-5].Id), (yyvsp[-3].Id), (yyvsp[-1].classBodyU));puts("class created");}
#line 2065 "synt_analyzer.tab.cpp"
    break;

  case 11: /* class: modifiers CLASS ID '{' classBody '}'  */
#line 205 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].modifiersU), (yyvsp[-3].Id), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2071 "synt_analyzer.tab.cpp"
    break;

  case 12: /* class: CLASS ID ':' ID '{' classBody '}'  */
#line 206 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].Id), (yyvsp[-3].Id), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2077 "synt_analyzer.tab.cpp"
    break;

  case 13: /* class: CLASS ID '{' classBody '}'  */
#line 207 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-3].Id), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2083 "synt_analyzer.tab.cpp"
    break;

  case 14: /* class: modifiers CLASS ID ':' ID '{' '}'  */
#line 208 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-6].modifiersU), (yyvsp[-4].Id), (yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2089 "synt_analyzer.tab.cpp"
    break;

  case 15: /* class: modifiers CLASS ID '{' '}'  */
#line 209 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].modifiersU), (yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2095 "synt_analyzer.tab.cpp"
    break;

  case 16: /* class: CLASS ID ':' ID '{' '}'  */
#line 210 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].Id), (yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2101 "synt_analyzer.tab.cpp"
    break;

  case 17: /* class: CLASS ID '{' '}'  */
#line 211 "synt_analyzer.y"
                        {(yyval.classU) = createClass((yyvsp[-2].Id), createClassBody()); puts("class created");}
#line 2107 "synt_analyzer.tab.cpp"
    break;

  case 18: /* classBody: semis  */
#line 214 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2113 "synt_analyzer.tab.cpp"
    break;

  case 19: /* classBody: method  */
#line 215 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].methodU));  puts("class body created");}
#line 2119 "synt_analyzer.tab.cpp"
    break;

  case 20: /* classBody: property semis  */
#line 216 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2125 "synt_analyzer.tab.cpp"
    break;

  case 21: /* classBody: constructor  */
#line 217 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].constructorU));  puts("class body created");}
#line 2131 "synt_analyzer.tab.cpp"
    break;

  case 22: /* classBody: initializer  */
#line 218 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].initializerU));  puts("class body created");}
#line 2137 "synt_analyzer.tab.cpp"
    break;

  case 23: /* classBody: classBody method  */
#line 219 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].methodU));  puts("meth added to class body");}
#line 2143 "synt_analyzer.tab.cpp"
    break;

  case 24: /* classBody: classBody property semis  */
#line 220 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2149 "synt_analyzer.tab.cpp"
    break;

  case 25: /* classBody: classBody constructor  */
#line 221 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].constructorU)); puts("constr added to class body");}
#line 2155 "synt_analyzer.tab.cpp"
    break;

  case 26: /* classBody: classBody initializer  */
#line 222 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].initializerU)); puts("init added to class body");}
#line 2161 "synt_analyzer.tab.cpp"
    break;

  case 27: /* classBody: classBody semis  */
#line 223 "synt_analyzer.y"
                        {(yyval.classBodyU) = (yyvsp[-1].classBodyU); puts("semis added to class body");}
#line 2167 "synt_analyzer.tab.cpp"
    break;

  case 28: /* property: modifiers valDeclaration  */
#line 226 "synt_analyzer.y"
                                        {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2173 "synt_analyzer.tab.cpp"
    break;

  case 29: /* property: modifiers varDeclaration  */
#line 227 "synt_analyzer.y"
                                {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2179 "synt_analyzer.tab.cpp"
    break;

  case 30: /* property: valDeclaration  */
#line 228 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2185 "synt_analyzer.tab.cpp"
    break;

  case 31: /* property: varDeclaration  */
#line 229 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2191 "synt_analyzer.tab.cpp"
    break;

  case 32: /* method: modifiers funcDeclaration ';'  */
#line 232 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2197 "synt_analyzer.tab.cpp"
    break;

  case 33: /* method: modifiers func  */
#line 233 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].modifiersU), (yyvsp[0].funcU)); puts("meth created");}
#line 2203 "synt_analyzer.tab.cpp"
    break;

  case 34: /* method: funcDeclaration ';'  */
#line 234 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2209 "synt_analyzer.tab.cpp"
    break;

  case 35: /* method: func  */
#line 235 "synt_analyzer.y"
        {(yyval.methodU) = createMethod((yyvsp[0].funcU)); puts("meth created");}
#line 2215 "synt_analyzer.tab.cpp"
    break;

  case 36: /* initializer: INIT block  */
#line 238 "synt_analyzer.y"
                        {(yyval.initializerU) = createInit((yyvsp[0].stmtListU)); puts("init created");}
#line 2221 "synt_analyzer.tab.cpp"
    break;

  case 37: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' block  */
#line 242 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-5].visibilityModU), (yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2227 "synt_analyzer.tab.cpp"
    break;

  case 38: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')'  */
#line 243 "synt_analyzer.y"
                                                                {(yyval.constructorU) = createConstructor((yyvsp[-4].visibilityModU), (yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2233 "synt_analyzer.tab.cpp"
    break;

  case 39: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 244 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2239 "synt_analyzer.tab.cpp"
    break;

  case 40: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 245 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2245 "synt_analyzer.tab.cpp"
    break;

  case 41: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 246 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2251 "synt_analyzer.tab.cpp"
    break;

  case 42: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 247 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2257 "synt_analyzer.tab.cpp"
    break;

  case 43: /* constructor: CONSTRUCTOR '(' optFormalParams ')' block  */
#line 248 "synt_analyzer.y"
                                                {(yyval.constructorU) = createConstructor((yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2263 "synt_analyzer.tab.cpp"
    break;

  case 44: /* constructor: CONSTRUCTOR '(' optFormalParams ')'  */
#line 249 "synt_analyzer.y"
                                        {(yyval.constructorU) = createConstructor((yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2269 "synt_analyzer.tab.cpp"
    break;

  case 45: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 250 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2275 "synt_analyzer.tab.cpp"
    break;

  case 46: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 251 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2281 "synt_analyzer.tab.cpp"
    break;

  case 47: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 252 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2287 "synt_analyzer.tab.cpp"
    break;

  case 48: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 253 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2293 "synt_analyzer.tab.cpp"
    break;

  case 49: /* optFormalParams: %empty  */
#line 256 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = 0; puts("opt formal params created");}
#line 2299 "synt_analyzer.tab.cpp"
    break;

  case 50: /* optFormalParams: formalParams  */
#line 257 "synt_analyzer.y"
                {(yyval.formalParamsListU) = (yyvsp[0].formalParamsListU); puts("opt formal params created");}
#line 2305 "synt_analyzer.tab.cpp"
    break;

  case 51: /* formalParams: ID ':' type  */
#line 260 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = createFormalParamsList((yyvsp[-2].Id), (yyvsp[0].typeU)); puts("formal params created");}
#line 2311 "synt_analyzer.tab.cpp"
    break;

  case 52: /* formalParams: formalParams ',' ID ':' type  */
#line 261 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = addToFormalParamsList((yyvsp[-4].formalParamsListU), (yyvsp[-2].Id), (yyvsp[0].typeU)); puts("formal params created");}
#line 2317 "synt_analyzer.tab.cpp"
    break;

  case 53: /* modifiers: OVERRIDE  */
#line 264 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, None); puts("mods created");}
#line 2323 "synt_analyzer.tab.cpp"
    break;

  case 54: /* modifiers: visibilityModifier  */
#line 265 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2329 "synt_analyzer.tab.cpp"
    break;

  case 55: /* modifiers: inheritanceModifier  */
#line 266 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2335 "synt_analyzer.tab.cpp"
    break;

  case 56: /* modifiers: ABSTRACT  */
#line 267 "synt_analyzer.y"
                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, None); puts("mods created");}
#line 2341 "synt_analyzer.tab.cpp"
    break;

  case 57: /* modifiers: OVERRIDE visibilityModifier  */
#line 268 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2347 "synt_analyzer.tab.cpp"
    break;

  case 58: /* modifiers: OVERRIDE inheritanceModifier  */
#line 269 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2353 "synt_analyzer.tab.cpp"
    break;

  case 59: /* modifiers: OVERRIDE ABSTRACT  */
#line 270 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2359 "synt_analyzer.tab.cpp"
    break;

  case 60: /* modifiers: visibilityModifier OVERRIDE  */
#line 271 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2365 "synt_analyzer.tab.cpp"
    break;

  case 61: /* modifiers: visibilityModifier inheritanceModifier  */
#line 272 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2371 "synt_analyzer.tab.cpp"
    break;

  case 62: /* modifiers: visibilityModifier ABSTRACT  */
#line 273 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2377 "synt_analyzer.tab.cpp"
    break;

  case 63: /* modifiers: inheritanceModifier OVERRIDE  */
#line 274 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2383 "synt_analyzer.tab.cpp"
    break;

  case 64: /* modifiers: inheritanceModifier visibilityModifier  */
#line 275 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2389 "synt_analyzer.tab.cpp"
    break;

  case 65: /* modifiers: inheritanceModifier ABSTRACT  */
#line 276 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2395 "synt_analyzer.tab.cpp"
    break;

  case 66: /* modifiers: ABSTRACT OVERRIDE  */
#line 277 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2401 "synt_analyzer.tab.cpp"
    break;

  case 67: /* modifiers: ABSTRACT visibilityModifier  */
#line 278 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2407 "synt_analyzer.tab.cpp"
    break;

  case 68: /* modifiers: ABSTRACT inheritanceModifier  */
#line 279 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2413 "synt_analyzer.tab.cpp"
    break;

  case 69: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier  */
#line 280 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2419 "synt_analyzer.tab.cpp"
    break;

  case 70: /* modifiers: OVERRIDE visibilityModifier ABSTRACT  */
#line 281 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2425 "synt_analyzer.tab.cpp"
    break;

  case 71: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier  */
#line 282 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2431 "synt_analyzer.tab.cpp"
    break;

  case 72: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT  */
#line 283 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2437 "synt_analyzer.tab.cpp"
    break;

  case 73: /* modifiers: OVERRIDE ABSTRACT visibilityModifier  */
#line 284 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2443 "synt_analyzer.tab.cpp"
    break;

  case 74: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier  */
#line 285 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2449 "synt_analyzer.tab.cpp"
    break;

  case 75: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier  */
#line 286 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2455 "synt_analyzer.tab.cpp"
    break;

  case 76: /* modifiers: visibilityModifier OVERRIDE ABSTRACT  */
#line 287 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2461 "synt_analyzer.tab.cpp"
    break;

  case 77: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE  */
#line 288 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2467 "synt_analyzer.tab.cpp"
    break;

  case 78: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT  */
#line 289 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2473 "synt_analyzer.tab.cpp"
    break;

  case 79: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier  */
#line 290 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2479 "synt_analyzer.tab.cpp"
    break;

  case 80: /* modifiers: visibilityModifier ABSTRACT OVERRIDE  */
#line 291 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2485 "synt_analyzer.tab.cpp"
    break;

  case 81: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier  */
#line 292 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2491 "synt_analyzer.tab.cpp"
    break;

  case 82: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT  */
#line 293 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2497 "synt_analyzer.tab.cpp"
    break;

  case 83: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT  */
#line 294 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2503 "synt_analyzer.tab.cpp"
    break;

  case 84: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE  */
#line 295 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2509 "synt_analyzer.tab.cpp"
    break;

  case 85: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier  */
#line 296 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2515 "synt_analyzer.tab.cpp"
    break;

  case 86: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE  */
#line 297 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2521 "synt_analyzer.tab.cpp"
    break;

  case 87: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier  */
#line 298 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2527 "synt_analyzer.tab.cpp"
    break;

  case 88: /* modifiers: ABSTRACT OVERRIDE visibilityModifier  */
#line 299 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2533 "synt_analyzer.tab.cpp"
    break;

  case 89: /* modifiers: ABSTRACT visibilityModifier OVERRIDE  */
#line 300 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2539 "synt_analyzer.tab.cpp"
    break;

  case 90: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier  */
#line 301 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2545 "synt_analyzer.tab.cpp"
    break;

  case 91: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE  */
#line 302 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2551 "synt_analyzer.tab.cpp"
    break;

  case 92: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier  */
#line 303 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2557 "synt_analyzer.tab.cpp"
    break;

  case 93: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier ABSTRACT  */
#line 304 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2563 "synt_analyzer.tab.cpp"
    break;

  case 94: /* modifiers: OVERRIDE visibilityModifier ABSTRACT inheritanceModifier  */
#line 305 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2569 "synt_analyzer.tab.cpp"
    break;

  case 95: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier ABSTRACT  */
#line 306 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2575 "synt_analyzer.tab.cpp"
    break;

  case 96: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT visibilityModifier  */
#line 307 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2581 "synt_analyzer.tab.cpp"
    break;

  case 97: /* modifiers: OVERRIDE ABSTRACT visibilityModifier inheritanceModifier  */
#line 308 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2587 "synt_analyzer.tab.cpp"
    break;

  case 98: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier visibilityModifier  */
#line 309 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2593 "synt_analyzer.tab.cpp"
    break;

  case 99: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier ABSTRACT  */
#line 310 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2599 "synt_analyzer.tab.cpp"
    break;

  case 100: /* modifiers: visibilityModifier OVERRIDE ABSTRACT inheritanceModifier  */
#line 311 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2605 "synt_analyzer.tab.cpp"
    break;

  case 101: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE ABSTRACT  */
#line 312 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2611 "synt_analyzer.tab.cpp"
    break;

  case 102: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT OVERRIDE  */
#line 313 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2617 "synt_analyzer.tab.cpp"
    break;

  case 103: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier OVERRIDE  */
#line 314 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2623 "synt_analyzer.tab.cpp"
    break;

  case 104: /* modifiers: visibilityModifier ABSTRACT OVERRIDE inheritanceModifier  */
#line 315 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2629 "synt_analyzer.tab.cpp"
    break;

  case 105: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier ABSTRACT  */
#line 316 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2635 "synt_analyzer.tab.cpp"
    break;

  case 106: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT visibilityModifier  */
#line 317 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2641 "synt_analyzer.tab.cpp"
    break;

  case 107: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT OVERRIDE  */
#line 319 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2647 "synt_analyzer.tab.cpp"
    break;

  case 108: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE ABSTRACT  */
#line 321 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2653 "synt_analyzer.tab.cpp"
    break;

  case 109: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier OVERRIDE  */
#line 323 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2659 "synt_analyzer.tab.cpp"
    break;

  case 110: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE visibilityModifier  */
#line 325 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2665 "synt_analyzer.tab.cpp"
    break;

  case 111: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier visibilityModifier  */
#line 327 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2671 "synt_analyzer.tab.cpp"
    break;

  case 112: /* modifiers: ABSTRACT OVERRIDE visibilityModifier inheritanceModifier  */
#line 329 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2677 "synt_analyzer.tab.cpp"
    break;

  case 113: /* modifiers: ABSTRACT visibilityModifier OVERRIDE inheritanceModifier  */
#line 330 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2683 "synt_analyzer.tab.cpp"
    break;

  case 114: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier OVERRIDE  */
#line 331 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2689 "synt_analyzer.tab.cpp"
    break;

  case 115: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE visibilityModifier  */
#line 333 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2695 "synt_analyzer.tab.cpp"
    break;

  case 116: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier OVERRIDE  */
#line 335 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2701 "synt_analyzer.tab.cpp"
    break;

  case 117: /* visibilityModifier: PUBLIC  */
#line 338 "synt_analyzer.y"
                                {(yyval.visibilityModU) = Public;}
#line 2707 "synt_analyzer.tab.cpp"
    break;

  case 118: /* visibilityModifier: PRIVATE  */
#line 339 "synt_analyzer.y"
                {(yyval.visibilityModU) = Private;}
#line 2713 "synt_analyzer.tab.cpp"
    break;

  case 119: /* visibilityModifier: INTERNAL  */
#line 340 "synt_analyzer.y"
                {(yyval.visibilityModU) = Internal;}
#line 2719 "synt_analyzer.tab.cpp"
    break;

  case 120: /* visibilityModifier: PROTECTED  */
#line 341 "synt_analyzer.y"
                {(yyval.visibilityModU) = Protected;}
#line 2725 "synt_analyzer.tab.cpp"
    break;

  case 121: /* inheritanceModifier: FINAL  */
#line 345 "synt_analyzer.y"
                           {(yyval.inheritanceModU) = Final;}
#line 2731 "synt_analyzer.tab.cpp"
    break;

  case 122: /* inheritanceModifier: OPEN  */
#line 346 "synt_analyzer.y"
       {(yyval.inheritanceModU) = Open;}
#line 2737 "synt_analyzer.tab.cpp"
    break;

  case 123: /* func: funcDeclaration block  */
#line 349 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-1].funcDeclU), (yyvsp[0].stmtListU)); puts("func created");}
#line 2743 "synt_analyzer.tab.cpp"
    break;

  case 124: /* func: funcDeclaration '=' expr  */
#line 350 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-2].funcDeclU), (yyvsp[0].exprU)); puts("func created");}
#line 2749 "synt_analyzer.tab.cpp"
    break;

  case 125: /* funcDeclaration: FUN ID '(' optFormalParams ')' ':' type  */
#line 354 "synt_analyzer.y"
                                                                {(yyval.funcDeclU) = createFuncDecl((yyvsp[-5].Id), (yyvsp[-3].formalParamsListU), (yyvsp[0].typeU));  puts("func decl created");}
#line 2755 "synt_analyzer.tab.cpp"
    break;

  case 126: /* block: '{' semis stmts '}'  */
#line 358 "synt_analyzer.y"
                                {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2761 "synt_analyzer.tab.cpp"
    break;

  case 127: /* block: '{' semis '}'  */
#line 359 "synt_analyzer.y"
                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2767 "synt_analyzer.tab.cpp"
    break;

  case 128: /* block: '{' stmts '}'  */
#line 360 "synt_analyzer.y"
                {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2773 "synt_analyzer.tab.cpp"
    break;

  case 129: /* block: '{' '}'  */
#line 361 "synt_analyzer.y"
                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2779 "synt_analyzer.tab.cpp"
    break;

  case 130: /* varDeclaration: VAR ID ':' type  */
#line 365 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].Id), (yyvsp[0].typeU), 0); puts("val created");}
#line 2785 "synt_analyzer.tab.cpp"
    break;

  case 131: /* varDeclaration: VAR ID ':' type '=' expr  */
#line 366 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].Id), (yyvsp[-2].typeU), (yyvsp[0].exprU), 0); puts("val created");}
#line 2791 "synt_analyzer.tab.cpp"
    break;

  case 132: /* varDeclaration: VAR '(' formalParams ')' '=' expr  */
#line 367 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 0); puts("val created"); }
#line 2797 "synt_analyzer.tab.cpp"
    break;

  case 133: /* valDeclaration: VAL ID ':' type  */
#line 371 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].Id), (yyvsp[0].typeU), 1); puts("var created"); }
#line 2803 "synt_analyzer.tab.cpp"
    break;

  case 134: /* valDeclaration: VAL ID ':' type '=' expr  */
#line 372 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].Id), (yyvsp[-2].typeU), (yyvsp[0].exprU), 1); puts("var created"); }
#line 2809 "synt_analyzer.tab.cpp"
    break;

  case 135: /* valDeclaration: VAL '(' formalParams ')' '=' expr  */
#line 373 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 1); puts("var created"); }
#line 2815 "synt_analyzer.tab.cpp"
    break;

  case 136: /* type: ID  */
#line 376 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].Id)); puts("type created"); }
#line 2821 "synt_analyzer.tab.cpp"
    break;

  case 137: /* type: templateType  */
#line 377 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].templateTypeU)); puts("type created"); }
#line 2827 "synt_analyzer.tab.cpp"
    break;

  case 138: /* templateType: ID '<' type_seq '>'  */
#line 380 "synt_analyzer.y"
                                        {(yyval.templateTypeU) = createTemplateType((yyvsp[-3].Id), (yyvsp[-1].typesListU)); puts("template type created"); }
#line 2833 "synt_analyzer.tab.cpp"
    break;

  case 139: /* type_seq: ID  */
#line 383 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].Id)); puts("type seq created"); }
#line 2839 "synt_analyzer.tab.cpp"
    break;

  case 140: /* type_seq: templateType  */
#line 384 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].templateTypeU)); puts("type seq created"); }
#line 2845 "synt_analyzer.tab.cpp"
    break;

  case 141: /* type_seq: type_seq ',' ID  */
#line 385 "synt_analyzer.y"
                        {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].Id));  puts("type seq created"); }
#line 2851 "synt_analyzer.tab.cpp"
    break;

  case 142: /* type_seq: type_seq ',' templateType  */
#line 386 "synt_analyzer.y"
                                {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].templateTypeU));  puts("type seq created"); }
#line 2857 "synt_analyzer.tab.cpp"
    break;

  case 143: /* stmts: stmt  */
#line 389 "synt_analyzer.y"
                {(yyval.stmtListU) = createStmtList((yyvsp[0].stmtU));  puts("stmts created"); }
#line 2863 "synt_analyzer.tab.cpp"
    break;

  case 144: /* stmts: stmts stmt  */
#line 390 "synt_analyzer.y"
                {(yyval.stmtListU) = addToStmtList((yyvsp[-1].stmtListU), (yyvsp[0].stmtU));  puts("stmts created"); }
#line 2869 "synt_analyzer.tab.cpp"
    break;

  case 145: /* stmt: valDeclaration semis  */
#line 393 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 2875 "synt_analyzer.tab.cpp"
    break;

  case 146: /* stmt: varDeclaration semis  */
#line 394 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 2881 "synt_analyzer.tab.cpp"
    break;

  case 147: /* stmt: assignment semis  */
#line 395 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 2887 "synt_analyzer.tab.cpp"
    break;

  case 148: /* stmt: whileLoop semis  */
#line 396 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), WhileLoop);  puts("stmt created"); }
#line 2893 "synt_analyzer.tab.cpp"
    break;

  case 149: /* stmt: forLoop semis  */
#line 397 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].forLoopU), ForLoop);  puts("stmt created"); }
#line 2899 "synt_analyzer.tab.cpp"
    break;

  case 150: /* stmt: doWhileLoop semis  */
#line 398 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 2905 "synt_analyzer.tab.cpp"
    break;

  case 151: /* stmt: ifStmt semis  */
#line 399 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].ifStmtU), IfStmt);  puts("stmt created"); }
#line 2911 "synt_analyzer.tab.cpp"
    break;

  case 152: /* stmt: expr semis  */
#line 400 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 2917 "synt_analyzer.tab.cpp"
    break;

  case 153: /* stmt: BREAK semis  */
#line 401 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 2923 "synt_analyzer.tab.cpp"
    break;

  case 154: /* stmt: CONTINUE semis  */
#line 402 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 2929 "synt_analyzer.tab.cpp"
    break;

  case 155: /* stmt: RETURN semis  */
#line 403 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 2935 "synt_analyzer.tab.cpp"
    break;

  case 156: /* stmt: RETURN expr semis  */
#line 404 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 2941 "synt_analyzer.tab.cpp"
    break;

  case 157: /* expr: ID  */
#line 407 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Id), Identificator);  puts("expr created"); }
#line 2947 "synt_analyzer.tab.cpp"
    break;

  case 158: /* expr: THIS  */
#line 408 "synt_analyzer.y"
        {(yyval.exprU) = createExpr(0, This);  puts("expr created"); }
#line 2953 "synt_analyzer.tab.cpp"
    break;

  case 159: /* expr: ID '(' optFactParams ')'  */
#line 409 "synt_analyzer.y"
                                {(yyval.exprU) = createExpr((yyvsp[-3].Id), (yyvsp[-1].factParamsListU), MethodCall);  puts("expr created"); }
#line 2959 "synt_analyzer.tab.cpp"
    break;

  case 160: /* expr: INT  */
#line 410 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Int_v), Int);  puts("expr created"); }
#line 2965 "synt_analyzer.tab.cpp"
    break;

  case 161: /* expr: FLOAT  */
#line 411 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Float_v), Float);  puts("expr created"); }
#line 2971 "synt_analyzer.tab.cpp"
    break;

  case 162: /* expr: STRING  */
#line 412 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].String_v), String);  puts("expr created"); }
#line 2977 "synt_analyzer.tab.cpp"
    break;

  case 163: /* expr: CHAR  */
#line 413 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Char_v), Char);  puts("expr created"); }
#line 2983 "synt_analyzer.tab.cpp"
    break;

  case 164: /* expr: DOUBLE  */
#line 414 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Double_v), Double);  puts("expr created"); }
#line 2989 "synt_analyzer.tab.cpp"
    break;

  case 165: /* expr: BOOLEAN  */
#line 415 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Bool_v), Boolean);  puts("expr created"); }
#line 2995 "synt_analyzer.tab.cpp"
    break;

  case 166: /* expr: '(' expr ')'  */
#line 416 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-1].exprU), ExprInBrackets);  puts("expr created"); }
#line 3001 "synt_analyzer.tab.cpp"
    break;

  case 167: /* expr: '!' expr  */
#line 417 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].exprU), LogicalNot);}
#line 3007 "synt_analyzer.tab.cpp"
    break;

  case 168: /* expr: '+' expr  */
#line 418 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryPlusExpr);  puts("expr created"); }
#line 3013 "synt_analyzer.tab.cpp"
    break;

  case 169: /* expr: '-' expr  */
#line 419 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryMinusExpr);  puts("expr created"); }
#line 3019 "synt_analyzer.tab.cpp"
    break;

  case 170: /* expr: expr '+' expr  */
#line 420 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sum);  puts("expr created"); }
#line 3025 "synt_analyzer.tab.cpp"
    break;

  case 171: /* expr: expr '-' expr  */
#line 421 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sub);  puts("expr created"); }
#line 3031 "synt_analyzer.tab.cpp"
    break;

  case 172: /* expr: expr '*' expr  */
#line 422 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mul);  puts("expr created"); }
#line 3037 "synt_analyzer.tab.cpp"
    break;

  case 173: /* expr: expr '/' expr  */
#line 423 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Div);  puts("expr created"); }
#line 3043 "synt_analyzer.tab.cpp"
    break;

  case 174: /* expr: expr '%' expr  */
#line 424 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mod);  puts("expr created"); }
#line 3049 "synt_analyzer.tab.cpp"
    break;

  case 175: /* expr: expr '<' expr  */
#line 425 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Less);  puts("expr created"); }
#line 3055 "synt_analyzer.tab.cpp"
    break;

  case 176: /* expr: expr '>' expr  */
#line 426 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), More);  puts("expr created"); }
#line 3061 "synt_analyzer.tab.cpp"
    break;

  case 177: /* expr: expr OR expr  */
#line 427 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Or);  puts("expr created"); }
#line 3067 "synt_analyzer.tab.cpp"
    break;

  case 178: /* expr: expr AND expr  */
#line 428 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), And);  puts("expr created"); }
#line 3073 "synt_analyzer.tab.cpp"
    break;

  case 179: /* expr: expr EQ expr  */
#line 429 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Eq);  puts("expr created"); }
#line 3079 "synt_analyzer.tab.cpp"
    break;

  case 180: /* expr: expr AEQ expr  */
#line 430 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Aeq);}
#line 3085 "synt_analyzer.tab.cpp"
    break;

  case 181: /* expr: expr NEQ expr  */
#line 431 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Neq);  puts("expr created"); }
#line 3091 "synt_analyzer.tab.cpp"
    break;

  case 182: /* expr: expr NAEQ expr  */
#line 432 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Naeq);  puts("expr created"); }
#line 3097 "synt_analyzer.tab.cpp"
    break;

  case 183: /* expr: expr LOEQ expr  */
#line 433 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Loeq);  puts("expr created"); }
#line 3103 "synt_analyzer.tab.cpp"
    break;

  case 184: /* expr: expr MOEQ expr  */
#line 434 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Moeq);  puts("expr created"); }
#line 3109 "synt_analyzer.tab.cpp"
    break;

  case 185: /* expr: expr '.' ID  */
#line 435 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].Id), FieldCalcExpr);  puts("expr created"); }
#line 3115 "synt_analyzer.tab.cpp"
    break;

  case 186: /* expr: expr '.' ID '(' optFactParams ')'  */
#line 436 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr((yyvsp[-5].exprU), (yyvsp[-3].Id), (yyvsp[-1].factParamsListU), MethodCalcExpr);  puts("expr created"); }
#line 3121 "synt_analyzer.tab.cpp"
    break;

  case 187: /* expr: expr '[' expr ']'  */
#line 437 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-3].exprU), (yyvsp[-1].exprU), ArrayElementCall);  puts("expr created"); }
#line 3127 "synt_analyzer.tab.cpp"
    break;

  case 188: /* expr: SUPER '.' ID  */
#line 438 "synt_analyzer.y"
                {(yyval.exprU) = createExpr(0, (yyvsp[0].Id), ParentFieldCall);  puts("expr created"); }
#line 3133 "synt_analyzer.tab.cpp"
    break;

  case 189: /* expr: SUPER '.' ID '(' optFactParams ')'  */
#line 439 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr(0, (yyvsp[-3].Id), (yyvsp[-1].factParamsListU), ParentMethodCall);  puts("expr created"); }
#line 3139 "synt_analyzer.tab.cpp"
    break;

  case 190: /* expr: expr RANGE expr  */
#line 440 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Range);  puts("expr created"); }
#line 3145 "synt_analyzer.tab.cpp"
    break;

  case 191: /* optFactParams: %empty  */
#line 443 "synt_analyzer.y"
                                {(yyval.factParamsListU) = 0;   puts("opt fact params created"); }
#line 3151 "synt_analyzer.tab.cpp"
    break;

  case 192: /* optFactParams: factParams  */
#line 444 "synt_analyzer.y"
                {(yyval.factParamsListU) = (yyvsp[0].factParamsListU);   puts("opt fact params created"); }
#line 3157 "synt_analyzer.tab.cpp"
    break;

  case 193: /* factParams: expr  */
#line 447 "synt_analyzer.y"
                        {(yyval.factParamsListU) = createFactParamsList((yyvsp[0].exprU));   puts("fact params created"); }
#line 3163 "synt_analyzer.tab.cpp"
    break;

  case 194: /* factParams: factParams ',' expr  */
#line 448 "synt_analyzer.y"
                        {(yyval.factParamsListU) = addToFactParamsList((yyvsp[-2].factParamsListU), (yyvsp[0].exprU));   puts("fact params created"); }
#line 3169 "synt_analyzer.tab.cpp"
    break;

  case 195: /* assignment: expr '=' expr  */
#line 451 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Assign); puts("assignment created"); }
#line 3175 "synt_analyzer.tab.cpp"
    break;

  case 196: /* assignment: expr ASUM expr  */
#line 452 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asum); puts("assignment created"); }
#line 3181 "synt_analyzer.tab.cpp"
    break;

  case 197: /* assignment: expr ASUB expr  */
#line 453 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asub); puts("assignment created"); }
#line 3187 "synt_analyzer.tab.cpp"
    break;

  case 198: /* assignment: expr ADIV expr  */
#line 454 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Adiv); puts("assignment created"); }
#line 3193 "synt_analyzer.tab.cpp"
    break;

  case 199: /* assignment: expr AMUL expr  */
#line 455 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amul); puts("assignment created"); }
#line 3199 "synt_analyzer.tab.cpp"
    break;

  case 200: /* assignment: expr AMOD expr  */
#line 456 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amod); puts("assignment created"); }
#line 3205 "synt_analyzer.tab.cpp"
    break;

  case 201: /* whileLoop: WHILE '(' expr ')' stmt  */
#line 459 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[0].stmtU), 0); puts("whileLoop created"); }
#line 3211 "synt_analyzer.tab.cpp"
    break;

  case 202: /* whileLoop: WHILE '(' expr ')' block  */
#line 460 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[0].stmtListU), 0); puts("whileLoop created"); }
#line 3217 "synt_analyzer.tab.cpp"
    break;

  case 203: /* whileLoop: WHILE '(' expr ')' ';'  */
#line 461 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 0); puts("whileLoop created"); }
#line 3223 "synt_analyzer.tab.cpp"
    break;

  case 204: /* doWhileLoop: DO stmt WHILE '(' expr ')'  */
#line 464 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].stmtU), 1); puts("doWhileLoop created"); }
#line 3229 "synt_analyzer.tab.cpp"
    break;

  case 205: /* doWhileLoop: DO block WHILE '(' expr ')'  */
#line 465 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].stmtListU), 1); puts("doWhileLoop created"); }
#line 3235 "synt_analyzer.tab.cpp"
    break;

  case 206: /* doWhileLoop: DO WHILE '(' expr ')'  */
#line 466 "synt_analyzer.y"
                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), 1); puts("doWhileLoop created"); }
#line 3241 "synt_analyzer.tab.cpp"
    break;

  case 207: /* forLoop: FOR '(' ID ':' type IN expr ')' stmt  */
#line 469 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].Id), (yyvsp[-4].typeU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3247 "synt_analyzer.tab.cpp"
    break;

  case 208: /* forLoop: FOR '(' ID ':' type IN expr ')' block  */
#line 470 "synt_analyzer.y"
                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].Id), (yyvsp[-4].typeU), (yyvsp[-2].exprU), (yyvsp[0].stmtListU)); puts("forLoop created"); }
#line 3253 "synt_analyzer.tab.cpp"
    break;

  case 209: /* forLoop: FOR '(' ID ':' type IN expr ')' ';'  */
#line 471 "synt_analyzer.y"
                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].Id), (yyvsp[-4].typeU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3259 "synt_analyzer.tab.cpp"
    break;

  case 210: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' stmt  */
#line 472 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3265 "synt_analyzer.tab.cpp"
    break;

  case 211: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block  */
#line 473 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), (yyvsp[0].stmtListU)); puts("forLoop created"); }
#line 3271 "synt_analyzer.tab.cpp"
    break;

  case 212: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' ';'  */
#line 474 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3277 "synt_analyzer.tab.cpp"
    break;

  case 213: /* ifStmt: IF '(' expr ')' stmt  */
#line 477 "synt_analyzer.y"
                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3283 "synt_analyzer.tab.cpp"
    break;

  case 214: /* ifStmt: IF '(' expr ')' block  */
#line 478 "synt_analyzer.y"
                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU), (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3289 "synt_analyzer.tab.cpp"
    break;

  case 215: /* ifStmt: IF '(' expr ')' semis  */
#line 479 "synt_analyzer.y"
                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3295 "synt_analyzer.tab.cpp"
    break;

  case 216: /* ifStmt: IF '(' expr ')' stmt ELSE stmt  */
#line 480 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3301 "synt_analyzer.tab.cpp"
    break;

  case 217: /* ifStmt: IF '(' expr ')' block ELSE stmt  */
#line 481 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3307 "synt_analyzer.tab.cpp"
    break;

  case 218: /* ifStmt: IF '(' expr ')' semis ELSE stmt  */
#line 482 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3313 "synt_analyzer.tab.cpp"
    break;

  case 219: /* ifStmt: IF '(' expr ')' stmt ELSE block  */
#line 483 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU), (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3319 "synt_analyzer.tab.cpp"
    break;

  case 220: /* ifStmt: IF '(' expr ')' block ELSE block  */
#line 484 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU), (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3325 "synt_analyzer.tab.cpp"
    break;

  case 221: /* ifStmt: IF '(' expr ')' semis ELSE block  */
#line 485 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtListU)); puts("ifStmt created"); }
#line 3331 "synt_analyzer.tab.cpp"
    break;

  case 222: /* ifStmt: IF '(' expr ')' stmt ELSE semis  */
#line 486 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU)); puts("ifStmt created"); }
#line 3337 "synt_analyzer.tab.cpp"
    break;

  case 223: /* ifStmt: IF '(' expr ')' block ELSE semis  */
#line 487 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU)); puts("ifStmt created"); }
#line 3343 "synt_analyzer.tab.cpp"
    break;

  case 224: /* ifStmt: IF '(' expr ')' semis ELSE semis  */
#line 488 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU)); puts("ifStmt created"); }
#line 3349 "synt_analyzer.tab.cpp"
    break;

  case 225: /* semis: ';'  */
#line 492 "synt_analyzer.y"
                { puts("semis created"); }
#line 3355 "synt_analyzer.tab.cpp"
    break;

  case 226: /* semis: NEW_LINE  */
#line 493 "synt_analyzer.y"
                { puts("semis created"); }
#line 3361 "synt_analyzer.tab.cpp"
    break;

  case 227: /* semis: semis ';'  */
#line 494 "synt_analyzer.y"
                { puts("semis created"); }
#line 3367 "synt_analyzer.tab.cpp"
    break;

  case 228: /* semis: semis NEW_LINE  */
#line 495 "synt_analyzer.y"
                        { puts("semis created"); }
#line 3373 "synt_analyzer.tab.cpp"
    break;


#line 3377 "synt_analyzer.tab.cpp"

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

#line 499 "synt_analyzer.y"

//Секция пользовательского кода



void main(int argc, char **argv ){
	//yyin = fopen(argv[1], "r");
	yyin = fopen("2_funcs.txt", "r");
	FILE * file = fopen("tree.dot", "w");
	
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);

    return;
}




















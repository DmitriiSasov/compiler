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
  YYSYMBOL_102_ = 102,                     /* '{'  */
  YYSYMBOL_103_ = 103,                     /* '}'  */
  YYSYMBOL_104_ = 104,                     /* ':'  */
  YYSYMBOL_105_ = 105,                     /* ';'  */
  YYSYMBOL_106_ = 106,                     /* ','  */
  YYSYMBOL_107_ = 107,                     /* '='  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_program = 109,                  /* program  */
  YYSYMBOL_class = 110,                    /* class  */
  YYSYMBOL_classBody = 111,                /* classBody  */
  YYSYMBOL_classDeclarationWithoutInheritance = 112, /* classDeclarationWithoutInheritance  */
  YYSYMBOL_classDeclaration = 113,         /* classDeclaration  */
  YYSYMBOL_property = 114,                 /* property  */
  YYSYMBOL_method = 115,                   /* method  */
  YYSYMBOL_initializer = 116,              /* initializer  */
  YYSYMBOL_constructor = 117,              /* constructor  */
  YYSYMBOL_optFormalParams = 118,          /* optFormalParams  */
  YYSYMBOL_formalParams = 119,             /* formalParams  */
  YYSYMBOL_modifiers = 120,                /* modifiers  */
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1602

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  557

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
       2,     2,     2,     2,     2,     2,     2,     2,   104,   105,
      86,   107,    87,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   101,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   102,     2,   103,     2,     2,     2,     2,
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
       0,   175,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   189,   190,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     209,   212,   215,   216,   219,   220,   223,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   241,
     242,   245,   246,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   315,   316,   317,
     318,   322,   323,   326,   327,   331,   335,   336,   337,   338,
     342,   343,   344,   348,   349,   350,   353,   354,   357,   358,
     361,   362,   365,   366,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     429,   430,   433,   434,   437,   438,   439,   440,   441,   442,
     445,   446,   447,   450,   451,   454,   455,   456,   457,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   475,   476,   479,   480,   483,   484
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
  "'.'", "'('", "')'", "'['", "']'", "'{'", "'}'", "':'", "';'", "','",
  "'='", "$accept", "program", "class", "classBody",
  "classDeclarationWithoutInheritance", "classDeclaration", "property",
  "method", "initializer", "constructor", "optFormalParams",
  "formalParams", "modifiers", "visibilityModifier", "inheritanceModifier",
  "func", "funcDeclaration", "block", "varDeclaration", "valDeclaration",
  "type", "templateType", "type_seq", "stmts", "stmt", "expr",
  "optFactParams", "factParams", "assignment", "whileLoop", "doWhileLoop",
  "forLoop", "ifStmt", "optNewLines", "newLines", "semis", YY_NULLPTR
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
      91,    93,   123,   125,    58,    59,    44,    61
};
#endif

#define YYPACT_NINF (-373)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-232)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     334,  -373,  -373,  -373,  -373,  -373,   214,   363,  -373,  -373,
    -373,    61,  -373,    23,    23,     6,  -373,    23,   149,   402,
      25,   -46,   167,    25,   324,  -373,  -373,     6,  -373,    25,
     -46,     1,   -23,    25,   -46,   221,   113,   337,  -373,  -373,
     408,    99,   473,   518,   159,   521,    25,   -46,    23,    23,
      23,    23,    23,    23,    23,  -373,    48,  -373,  -373,    99,
     159,   230,   547,   550,   230,   176,   198,   588,   176,   184,
     605,   831,    70,   831,   164,   189,   226,   238,  -373,   -80,
     264,   260,    58,   621,   699,   110,    11,   292,    11,     3,
     292,     3,    11,   292,    11,    13,   292,    13,    23,    23,
     789,     6,  -373,  -373,  -373,    23,   218,    25,   -46,  -373,
     815,  -373,    23,    23,    23,     6,    23,  -373,    11,     3,
      11,    13,     3,    13,   292,     3,   292,    13,     3,    13,
     274,   656,   274,   185,   656,   237,   274,   656,   274,   215,
     656,   268,   225,   224,  -373,     6,    23,    23,    23,    25,
     -46,    25,   -46,   311,   228,  -373,   235,   141,   213,  1096,
     877,  1368,   274,   279,   274,   322,   360,   325,   656,   367,
     656,   370,   371,   376,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,    23,  -373,    25,   -46,
    -373,  -373,  -373,    23,    23,    23,    23,    23,    23,   316,
    -373,   318,    23,    23,    23,    23,     6,     6,   599,  -373,
    -373,  -373,  -373,  -373,  -373,  1368,  1368,  1368,  1368,  -373,
       6,    23,  1358,  -373,   675,     6,     6,     6,     6,     6,
    -373,  1167,  1459,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,   412,   320,   412,   412,   416,
     412,   416,    23,   421,   332,  1238,   336,   347,    25,   -46,
      25,   -46,   197,    25,   -46,   109,   109,   109,  1233,    25,
     -46,   307,  -373,   329,    23,    23,    23,    23,    23,  1368,
    1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,
    1368,  1368,  1368,  1368,  1368,   431,  1368,    23,    25,   -46,
      25,   -46,    25,   -46,    25,   -46,    25,   -46,    25,   -46,
    -373,    23,    23,    38,    23,    23,    23,    15,    17,  -373,
      23,    17,  1368,   351,    23,    23,    23,    23,    23,    25,
     -46,  -373,  -373,  1368,  1368,  1368,  1368,  1368,  1481,  1502,
    1289,  1289,  1289,  1289,   809,   809,   809,   809,   871,   454,
     454,   109,   109,   109,   352,  1389,  1368,   348,   354,   349,
     412,   357,   -76,   375,   355,    66,   356,  1459,    23,    38,
      23,  1368,   417,   418,  1368,    69,  1459,  1459,  1459,  1459,
    1459,    23,  -373,  1459,    23,    67,    23,    23,    23,    23,
      23,    23,    23,    23,   368,   365,  1368,  1263,   374,   379,
    1263,    23,    23,  1368,   416,    77,   469,   383,   380,   378,
     479,  1368,   381,  1368,  -373,    23,    23,   398,  1368,  1368,
     406,   410,   412,    23,  -373,    23,  -373,    23,    67,    23,
      23,    15,    23,    23,  1459,    23,  1459,  1368,   411,    23,
    1413,  1436,    23,    23,    23,   419,   343,   413,   263,   416,
    1368,   435,   -77,  1368,  1459,  -373,   950,  -373,  -373,  1023,
     416,   119,  -373,    23,    23,    23,    23,  -373,  -373,  1459,
    -373,  -373,    23,  1459,    29,    29,    49,  -373,  -373,  -373,
      23,    23,   427,   438,   416,   359,   529,   494,   497,   500,
     492,   526,    23,    23,  -373,    23,    23,  -373,    23,    23,
      23,    23,    23,  1368,  1368,   482,   483,   950,   950,   950,
    1368,  1368,    23,    23,    23,    23,  -373,  -373,   -46,  -373,
    -373,   -46,  -373,  -373,   -46,  1263,  1263,   484,   493,  1368,
    1368,   499,   501,     2,     2,    23,    23,    23,    23,   224,
     224,   505,   507,  1238,  1238,  -373,  -373,     2,     2,  -373,
    -373,  -373,  -373,   224,   224,  -373,  -373
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   233,   117,   118,   120,   119,   231,   231,   122,   121,
     235,     0,     4,   231,   231,     0,     5,   231,    54,   231,
       3,     2,     0,   232,     0,     1,     8,     0,     9,    12,
      13,     0,     0,     7,     6,     0,     0,     0,   234,   236,
     231,    57,   231,   231,    67,   231,    11,    10,   231,   231,
     231,   231,   231,   231,   231,    35,   231,    33,    32,    60,
      62,    61,   231,   231,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    70,    69,
      72,    71,    88,    87,    89,    90,    91,    92,   231,   231,
       0,     0,    18,    22,    21,   231,   231,    17,    16,    31,
       0,    30,   231,   231,   231,   231,   231,   123,    76,    75,
      80,    79,    77,    78,    82,    81,    86,    85,    84,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,   231,   231,   231,    26,
      29,    20,    19,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    94,    93,    96,    95,
     112,   111,   113,   114,   115,   116,   231,    36,    25,    24,
      23,    28,    27,   231,   231,   231,   231,   231,   231,   166,
     167,     0,   231,   231,   231,   231,     0,     0,     0,   169,
     170,   173,   171,   172,   174,     0,     0,     0,     0,   129,
       0,   231,   231,   142,     0,     0,     0,     0,     0,     0,
     128,     0,   124,   100,    99,   104,   103,   101,   102,   106,
     105,   110,   109,   108,   107,    49,     0,    49,     0,     0,
       0,     0,   231,     0,     0,     0,     0,     0,   159,   158,
     161,   160,     0,   163,   162,   177,   178,   176,     0,   145,
     144,     0,   143,     0,   231,   231,   231,   231,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   156,   157,
     147,   146,   149,   148,   153,   152,   151,   150,   155,   154,
     127,   231,   231,    50,   231,   231,   231,   136,   130,   137,
     231,   133,   200,   197,   231,   231,   231,   231,   231,   164,
     165,   175,   126,     0,     0,     0,     0,     0,   186,   187,
     188,   189,   190,   191,   192,   193,   184,   185,   199,   179,
     180,   182,   181,   183,   194,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,   202,   231,   201,
     231,     0,     0,     0,     0,     0,   205,   206,   207,   208,
     209,   231,   196,   204,   231,    44,   231,   231,   231,   231,
     231,   231,   231,   231,     0,     0,   200,   231,     0,     0,
     231,   231,   231,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   231,   231,     0,     0,     0,
       0,     0,     0,   231,    51,   231,    43,   231,    38,   231,
     231,   140,   231,   231,   131,   231,   134,     0,     0,   231,
       0,     0,   231,   231,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   198,     0,   214,   213,     0,
       0,     0,   195,   231,   231,   231,   231,    37,   125,   132,
     139,   138,   231,   135,   220,   219,   231,   212,   211,   210,
     231,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   231,    52,   231,   231,   141,   231,   231,
     231,   231,   231,   200,   200,     0,     0,     0,     0,     0,
       0,     0,   231,   231,   231,   231,   226,   223,   229,   225,
     222,   228,   227,   224,   230,   231,   231,     0,     0,   200,
     200,     0,     0,    46,    45,   231,   231,   231,   231,     0,
       0,     0,     0,     0,     0,    48,    47,    40,    39,   216,
     215,   218,   217,     0,     0,    42,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -373,  -373,   580,   534,  -373,  -373,   134,    60,   -85,   203,
    -230,  -246,   137,   577,    -3,  -373,  -373,    -5,  -373,  -373,
    -248,   200,  -373,   448,   -28,   283,  -372,  -373,  -373,  -373,
    -373,  -373,  -373,    -6,   582,   128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,   100,    13,    14,   220,   102,   103,   104,
     312,   313,   221,    18,    19,    55,    56,   117,    57,    58,
     318,   319,   433,   222,   223,   224,   368,   369,   225,   226,
     227,   228,   229,   363,    23,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    24,   316,   321,   320,     1,     1,    31,    32,     1,
     471,    35,    36,    37,     1,   147,     1,   315,     1,    42,
       1,    45,   115,   389,   416,   147,     1,   116,    38,   472,
     386,   423,     1,    61,    65,    66,    67,    68,    69,    70,
    -231,     1,    71,    72,    73,    74,    75,    76,    77,  -231,
      79,     1,     1,    80,    81,    82,    83,    84,    85,    39,
      16,    25,    87,    89,     1,    93,    95,     2,     3,     4,
       1,    28,  -231,   401,   109,  -231,  -231,   119,   121,    50,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   122,   123,     5,     6,     7,   153,
     154,  -231,     1,    48,  -231,    49,   156,   157,   158,   159,
     161,    10,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,  -231,     8,     9,   174,    21,   176,
     387,   512,   513,   180,    15,   182,  -231,    17,   187,    30,
     190,   191,   192,    34,  -231,    27,   128,   129,    17,    59,
      60,    61,     1,    78,    39,    47,   424,   535,   536,   233,
     146,   235,     1,  -231,  -231,   392,    10,   402,   111,  -231,
     146,  -231,   386,     2,     3,     4,   444,     8,     9,   115,
     245,   425,     2,     3,     4,  -231,  -231,   246,   247,   248,
     249,   250,   251,   112,   272,  -231,   254,   255,   256,   257,
       1,   468,     5,   272,    40,   101,   295,   101,   105,   296,
     105,     5,   480,  -231,  -231,   271,   273,     1,   481,   -53,
      94,     1,   177,  -231,  -231,   386,    51,   326,   150,   152,
     113,     8,     9,     1,   145,    88,   494,   105,   150,   195,
       8,     9,   114,   160,   145,   196,   322,   105,     8,     9,
     325,   183,   -53,   -53,   -53,   193,   -54,   -54,   -54,    52,
      53,    54,     8,     9,    59,    60,  -231,  -231,   333,   334,
     335,   336,   337,   189,   179,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   356,     8,     9,   295,     1,   120,   296,  -231,  -231,
    -231,   118,    10,   148,   185,   357,   358,   359,   360,   361,
     362,   197,   364,   148,   365,   366,   234,   198,   371,   372,
     373,   374,   375,   186,     8,     9,   115,  -231,     8,     9,
       2,     3,     4,   194,   259,   261,   264,     1,     8,     9,
       2,     3,     4,     2,     3,     4,    53,    54,   270,    52,
      53,    54,   299,   301,   303,   305,   307,   309,   236,     5,
      43,   238,   394,   395,   396,   115,     1,   466,   -56,     5,
       6,     7,     5,    62,    63,   403,   463,   464,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,     8,     9,
     330,   417,   495,   496,   420,   421,   422,   237,     8,     9,
     426,   -56,   -56,   -56,   240,     1,   242,   -55,   243,   437,
     438,     1,   244,   -59,   252,   253,   311,   445,   314,   446,
     317,   447,   448,   449,   450,   323,   451,   452,   475,   453,
     324,   479,   332,   456,   327,   354,   459,   460,   461,    10,
     -55,   -55,   -55,   467,   232,   328,   -59,   -59,   -59,   370,
     381,   474,   384,   385,   478,   386,   388,   482,   483,   484,
     485,   390,   391,   393,   398,   399,   486,   414,   487,   488,
     489,   415,   418,   427,   490,   491,     1,   419,   -58,   517,
     520,   523,   428,   431,   429,   430,   503,   504,   435,   505,
     506,   262,   507,   508,   509,   510,   511,   439,   265,   266,
     267,   268,   516,   519,   522,   442,   527,   528,   529,   530,
     455,   -58,   -58,   -58,   443,   550,   552,   465,   462,   531,
     532,     1,   470,   -66,     1,   492,   -68,   539,   540,   541,
     542,   543,   544,   497,   545,   546,   493,   498,   549,   551,
     499,   553,   554,   500,   501,   292,   293,   294,   555,   556,
       1,   295,   -63,     1,   296,   -65,   -66,   -66,   -66,   -68,
     -68,   -68,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   502,   355,
     514,   515,    20,   533,   476,   -63,   -63,   -63,   -65,   -65,
     -65,    26,   534,    29,     2,     3,     4,    33,   537,    41,
     538,    44,     1,   199,   547,   367,   548,   110,   231,    46,
     432,     2,     3,     4,    64,     0,   376,   377,   378,   379,
     380,     0,     0,     5,     0,    90,     0,     2,     3,     4,
       0,     0,   200,   201,     0,   518,   521,   524,     0,   383,
       5,    96,    86,     0,    91,    92,     0,    97,   106,     0,
     106,     0,     0,   107,   397,   107,     5,   400,   124,     0,
     125,   127,     2,     3,     4,     0,   209,   210,   211,   212,
     213,   214,     0,     0,     0,     0,     0,   106,     1,   367,
       0,     0,   149,   151,     0,     0,   367,   106,   215,   216,
       0,     5,   149,     0,   434,   217,   436,   218,     0,     0,
       0,   440,   441,     0,    10,     2,     3,     4,   175,     0,
       0,   178,     0,     0,   181,     0,     0,   184,     0,     0,
     454,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,     0,     0,   469,     5,   126,   473,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,   241,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     0,
       0,     0,   295,     0,     0,   296,     0,     0,     0,     0,
      10,     0,   297,     0,     0,     0,   367,   367,   258,   260,
     263,     0,     1,   525,   526,     2,     3,     4,     0,     0,
       0,     0,   269,     0,     0,     0,   298,   300,   302,   304,
     306,   308,   367,   367,     0,     0,    98,     0,     1,    99,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     2,     3,     4,
       0,     0,    98,     0,   329,    99,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    98,     0,
       0,    99,     0,     0,     0,     0,     5,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,   199,     0,     2,     3,     4,     0,     0,     0,     0,
       0,     0,   144,     0,    10,     8,     9,   289,   290,   291,
     292,   293,   294,     0,     0,     0,   295,     0,     0,   296,
     200,   201,     5,     6,     7,     0,     0,     0,   155,   202,
      10,     0,     0,   203,   204,   205,   206,   207,     0,     0,
       0,     0,   208,     0,     0,     0,    10,     0,     0,     0,
       0,     8,     9,     0,   209,   210,   211,   212,   213,   214,
       0,     0,     0,     0,   199,     0,     2,     3,     4,  -232,
     290,   291,   292,   293,   294,     0,   215,   216,   295,     0,
       0,   296,     0,   217,     0,   218,     0,     0,     0,     0,
     230,     0,    39,   200,   201,     5,     6,     7,     0,     0,
       0,     0,   202,     0,     0,     0,   203,   204,   205,   206,
     207,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,     0,   209,   210,   211,
     212,   213,   214,     0,     0,     0,     0,   199,     0,     2,
       3,     4,     0,     0,     0,     0,     0,     0,     0,   215,
     216,     0,     0,     0,     0,     0,   217,     0,   218,     0,
       0,     0,   115,     0,     0,    10,   200,   201,     5,     6,
       7,     0,     0,     0,     0,   202,     0,     0,     0,   203,
     204,   205,   206,   207,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,     0,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
     199,     0,     2,     3,     4,     0,     0,     0,     0,     0,
       0,     0,   215,   216,     0,     0,     0,     0,     0,   217,
       0,   218,     0,     0,     0,   115,     0,     0,   477,   200,
     201,     5,     6,     7,     0,     0,     0,     0,   202,     0,
       0,     0,   203,   204,   205,   206,   207,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,     0,   209,   210,   211,   212,   213,   214,     0,
       0,   199,     0,     2,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   216,     0,     0,     0,
       0,     0,   217,     0,   218,     0,     0,     0,     0,   219,
     200,   201,     5,     6,     7,     0,     0,     0,     0,   202,
       0,     0,     0,   203,   204,   205,   206,   207,     0,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,     0,   209,   210,   211,   212,   213,   214,
       0,     0,   199,     0,     2,     3,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,   216,     0,     0,
       0,     0,     0,   217,     0,   218,     1,     0,     0,     0,
     310,   200,   201,     5,     6,     7,     0,     0,     0,     0,
     202,     0,     0,     0,   203,   204,   205,   206,   207,     0,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,     0,   209,   210,   211,   212,   213,
     214,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   215,   216,     0,
     295,     0,   331,   296,   217,     0,   218,     0,     0,     0,
     115,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
     295,     1,   199,   296,     2,     3,     4,     0,     0,     0,
       0,     0,   199,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,   295,     0,     0,   296,
       0,   200,   201,     5,     6,     7,     0,     0,     0,     0,
     202,   200,   201,     0,   203,   204,   205,   206,   207,     0,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,     0,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,   209,   210,   211,   212,   213,
     214,     0,     0,     0,     0,     0,     0,   215,   216,     0,
       0,     0,     0,     0,   217,     0,   218,   215,   216,     0,
       0,     0,     0,     0,   217,     0,   218,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,   295,     0,     0,   296,
     382,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     0,     0,     0,
     295,     0,   457,   296,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,     0,     0,   295,     0,   458,   296,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,     0,     0,     0,   295,     0,     0,   296,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,     0,     0,   295,     0,
       0,   296,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,     0,     0,   295,
       0,     0,   296
};

static const yytype_int16 yycheck[] =
{
       6,     7,   248,   251,   250,     3,     3,    13,    14,     3,
      87,    17,    18,    19,     3,   100,     3,   247,     3,    22,
       3,    24,   102,    99,   396,   110,     3,   107,     3,   106,
     106,   403,     3,    36,    40,    41,    42,    43,    44,    45,
      37,     3,    48,    49,    50,    51,    52,    53,    54,    36,
      56,     3,     3,    59,    60,    61,    62,    63,    64,   105,
       0,     0,    65,    66,     3,    68,    69,     6,     7,     8,
       3,    11,    43,     4,     4,    64,    65,    80,    81,   102,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    36,    37,    35,    36,    37,   105,
     106,    86,     3,   102,   102,   104,   112,   113,   114,   115,
     116,   105,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   107,    64,    65,   130,     0,   132,
     360,   503,   504,   136,     0,   138,    37,     0,   143,    11,
     146,   147,   148,    15,   106,    11,    36,    37,    11,    36,
      37,   154,     3,   105,   105,    27,   404,   529,   530,   162,
     100,   164,     3,    64,    65,    99,   105,    98,     4,   102,
     110,   104,   106,     6,     7,     8,   422,    64,    65,   102,
     186,   104,     6,     7,     8,    36,    37,   193,   194,   195,
     196,   197,   198,     4,   222,    36,   202,   203,   204,   205,
       3,   449,    35,   231,    37,    71,    97,    73,    71,   100,
      73,    35,   460,    64,    65,   221,   222,     3,    99,     5,
      36,     3,    37,    64,    65,   106,     5,   255,   100,   101,
       4,    64,    65,     3,   100,    37,   484,   100,   110,    98,
      64,    65,     4,   115,   110,   104,   252,   110,    64,    65,
     255,    36,    38,    39,    40,    27,    38,    39,    40,    38,
      39,    40,    64,    65,    36,    37,    36,    37,   274,   275,
     276,   277,   278,   145,    37,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   297,    64,    65,    97,     3,    36,   100,     6,     7,
       8,    37,   105,   100,    36,   311,   312,   313,   314,   315,
     316,    98,   318,   110,   320,   321,    37,   104,   324,   325,
     326,   327,   328,    98,    64,    65,   102,    35,    64,    65,
       6,     7,     8,    98,   206,   207,   208,     3,    64,    65,
       6,     7,     8,     6,     7,     8,    39,    40,   220,    38,
      39,    40,   224,   225,   226,   227,   228,   229,    36,    35,
      36,    36,   368,   369,   370,   102,     3,   104,     5,    35,
      36,    37,    35,    36,    37,   381,    33,    34,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,    64,    65,
     262,   397,    33,    34,   400,   401,   402,    37,    64,    65,
     405,    38,    39,    40,    37,     3,    36,     5,    37,   415,
     416,     3,    36,     5,    98,    97,     4,   423,    98,   425,
       4,   427,   428,   429,   430,     4,   432,   433,   456,   435,
      98,   459,   103,   439,    98,     4,   442,   443,   444,   105,
      38,    39,    40,   448,   161,    98,    38,    39,    40,    98,
      98,   456,   104,    99,   459,   106,    99,   463,   464,   465,
     466,    86,   107,   107,    47,    47,   472,    99,   474,   475,
     476,   106,    98,     4,   480,   481,     3,    98,     5,   507,
     508,   509,    99,     4,   104,   107,   492,   493,   107,   495,
     496,   208,   498,   499,   500,   501,   502,    99,   215,   216,
     217,   218,   507,   508,   509,    99,   512,   513,   514,   515,
      99,    38,    39,    40,   104,   543,   544,   104,    99,   525,
     526,     3,    87,     5,     3,    98,     5,   533,   534,   535,
     536,   537,   538,     4,   539,   540,    98,    43,   543,   544,
      43,   547,   548,    43,    52,    91,    92,    93,   553,   554,
       3,    97,     5,     3,   100,     5,    38,    39,    40,    38,
      39,    40,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,    52,   296,
      98,    98,     0,    99,   456,    38,    39,    40,    38,    39,
      40,    11,    99,    11,     6,     7,     8,    15,    99,    22,
      99,    24,     3,     4,    99,   322,    99,    73,   160,    27,
     410,     6,     7,     8,    37,    -1,   333,   334,   335,   336,
     337,    -1,    -1,    35,    -1,    37,    -1,     6,     7,     8,
      -1,    -1,    33,    34,    -1,   507,   508,   509,    -1,   356,
      35,    36,    65,    -1,    67,    68,    -1,    70,    71,    -1,
      73,    -1,    -1,    71,   371,    73,    35,   374,    37,    -1,
      83,    84,     6,     7,     8,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,   100,     3,   396,
      -1,    -1,   100,   101,    -1,    -1,   403,   110,    89,    90,
      -1,    35,   110,    -1,   411,    96,   413,    98,    -1,    -1,
      -1,   418,   419,    -1,   105,     6,     7,     8,   131,    -1,
      -1,   134,    -1,    -1,   137,    -1,    -1,   140,    -1,    -1,
     437,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,   450,    35,    36,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,   170,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   503,   504,   206,   207,
     208,    -1,     3,   510,   511,     6,     7,     8,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,   529,   530,    -1,    -1,    27,    -1,     3,    30,
      -1,     6,     7,     8,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
      -1,    -1,    27,    -1,   262,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    64,    65,    -1,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,     4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,   105,    64,    65,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      33,    34,    35,    36,    37,    -1,    -1,    -1,   103,    42,
     105,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,     4,    -1,     6,     7,     8,    88,
      89,    90,    91,    92,    93,    -1,    89,    90,    97,    -1,
      -1,   100,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
     103,    -1,   105,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,     4,    -1,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,   105,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
       4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,     4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,   103,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,     4,    -1,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,     3,    -1,    -1,    -1,
     103,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    89,    90,    -1,
      97,    -1,    99,   100,    96,    -1,    98,    -1,    -1,    -1,
     102,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,     3,     4,   100,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,     4,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    33,    34,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    98,    89,    90,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    98,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
     101,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    99,   100,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    99,   100,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,    35,    36,    37,    64,    65,
     105,   109,   110,   112,   113,   114,   115,   120,   121,   122,
     142,   143,   141,   142,   141,     0,   110,   114,   115,   142,
     143,   141,   141,   142,   143,   141,   141,   141,     3,   105,
      37,   121,   122,    36,   121,   122,   142,   143,   102,   104,
     102,     5,    38,    39,    40,   123,   124,   126,   127,    36,
      37,   122,    36,    37,   121,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   105,   141,
     141,   141,   141,   141,   141,   141,   121,   122,    37,   122,
      37,   121,   121,   122,    36,   122,    36,   121,    27,    30,
     111,   114,   115,   116,   117,   120,   121,   142,   143,     4,
     111,     4,     4,     4,     4,   102,   107,   125,    37,   122,
      36,   122,    36,    37,    37,   121,    36,   121,    36,    37,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   103,   114,   115,   116,   117,   142,
     143,   142,   143,   141,   141,   103,   141,   141,   141,   141,
     143,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   122,   121,   122,    37,   121,    37,
     122,   121,   122,    36,   121,    36,    98,   125,   142,   143,
     141,   141,   141,    27,    98,    98,   104,    98,   104,     4,
      33,    34,    42,    46,    47,    48,    49,    50,    55,    67,
      68,    69,    70,    71,    72,    89,    90,    96,    98,   103,
     114,   120,   131,   132,   133,   136,   137,   138,   139,   140,
     103,   131,   133,   122,    37,   122,    36,    37,    36,   121,
      37,   121,    36,    37,    36,   141,   141,   141,   141,   141,
     141,   141,    98,    97,   141,   141,   141,   141,   142,   143,
     142,   143,   133,   142,   143,   133,   133,   133,   133,   142,
     143,   141,   132,   141,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    97,   100,   107,   142,   143,
     142,   143,   142,   143,   142,   143,   142,   143,   142,   143,
     103,     4,   118,   119,    98,   118,   119,     4,   128,   129,
     119,   128,   141,     4,    98,   125,   132,    98,    98,   142,
     143,    99,   103,   141,   141,   141,   141,   141,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,     4,   133,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   133,   134,   135,
      98,   141,   141,   141,   141,   141,   133,   133,   133,   133,
     133,    98,   101,   133,   104,    99,   106,   118,    99,    99,
      86,   107,    99,   107,   141,   141,   141,   133,    47,    47,
     133,     4,    98,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,    99,   106,   134,   141,    98,    98,
     141,   141,   141,   134,   128,   104,   125,     4,    99,   104,
     107,     4,   129,   130,   133,   107,   133,   141,   141,    99,
     133,   133,    99,   104,   119,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   133,    99,   141,    99,    99,   141,
     141,   141,    99,    33,    34,   104,   104,   125,   128,   133,
      87,    87,   106,   133,   125,   132,   143,   105,   125,   132,
     128,    99,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,    98,    98,   128,    33,    34,     4,    43,    43,
      43,    52,    52,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   134,   134,    98,    98,   125,   132,   143,   125,
     132,   143,   125,   132,   143,   133,   133,   141,   141,   141,
     141,   141,   141,    99,    99,   134,   134,    99,    99,   141,
     141,   141,   141,   141,   141,   125,   125,    99,    99,   125,
     132,   125,   132,   141,   141,   125,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   113,   114,   114,   115,   115,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   122,   122,   123,   123,   124,   125,   125,   125,   125,
     126,   126,   126,   127,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   139,   139,   139,   139,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   142,   142,   143,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     2,     2,     6,     6,     1,     1,     1,     2,
       2,     1,     1,     3,     3,     3,     2,     3,     3,     2,
       5,     5,     3,     3,     4,     3,     3,    11,     9,    19,
      19,    21,    21,     9,     7,    17,    17,    19,    19,     0,
       1,     5,     9,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     1,     1,     1,
       1,     1,     1,     3,     5,    13,     5,     4,     3,     3,
       7,    11,    13,     7,    11,    13,     1,     1,     7,     7,
       1,     5,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     8,     4,     3,     8,     3,
       0,     1,     1,     5,     4,     4,     4,     4,     4,     4,
       9,     9,     9,     8,     8,    17,    17,    17,    17,     9,
       9,     9,    13,    13,    13,    13,    13,    13,    13,    13,
      13,     0,     1,     1,     2,     1,     2
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

#line 2060 "synt_analyzer.tab.cpp"

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

#line 488 "synt_analyzer.y"

//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}




















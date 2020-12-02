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
  YYSYMBOL_optVisibilityModifier = 118,    /* optVisibilityModifier  */
  YYSYMBOL_optFormalParams = 119,          /* optFormalParams  */
  YYSYMBOL_formalParams = 120,             /* formalParams  */
  YYSYMBOL_memberModifier = 121,           /* memberModifier  */
  YYSYMBOL_visibilityModifier = 122,       /* visibilityModifier  */
  YYSYMBOL_inheritanceModifier = 123,      /* inheritanceModifier  */
  YYSYMBOL_func = 124,                     /* func  */
  YYSYMBOL_funcDeclaration = 125,          /* funcDeclaration  */
  YYSYMBOL_block = 126,                    /* block  */
  YYSYMBOL_varDeclaration = 127,           /* varDeclaration  */
  YYSYMBOL_valDeclaration = 128,           /* valDeclaration  */
  YYSYMBOL_type = 129,                     /* type  */
  YYSYMBOL_templateType = 130,             /* templateType  */
  YYSYMBOL_type_seq = 131,                 /* type_seq  */
  YYSYMBOL_stmts = 132,                    /* stmts  */
  YYSYMBOL_stmt = 133,                     /* stmt  */
  YYSYMBOL_expr = 134,                     /* expr  */
  YYSYMBOL_optFactParams = 135,            /* optFactParams  */
  YYSYMBOL_factParams = 136,               /* factParams  */
  YYSYMBOL_assignment = 137,               /* assignment  */
  YYSYMBOL_whileLoop = 138,                /* whileLoop  */
  YYSYMBOL_doWhileLoop = 139,              /* doWhileLoop  */
  YYSYMBOL_forLoop = 140,                  /* forLoop  */
  YYSYMBOL_ifStmt = 141,                   /* ifStmt  */
  YYSYMBOL_optNewLines = 142,              /* optNewLines  */
  YYSYMBOL_newLines = 143,                 /* newLines  */
  YYSYMBOL_semis = 144                     /* semis  */
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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  514

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
     209,   210,   211,   214,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   266,   270,
     271,   272,   273,   274,   275,   278,   279,   283,   284,   288,
     289,   293,   297,   298,   299,   300,   304,   305,   306,   310,
     311,   315,   319,   320,   321,   322,   326,   327,   328,   332,
     333,   334,   337,   338,   341,   342,   345,   346,   349,   350,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   413,   414,   417,   418,
     421,   422,   423,   424,   425,   426,   429,   430,   431,   434,
     435,   438,   439,   440,   441,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   459,   460,   463,
     464,   467,   468
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
      91,    93,   123,   125,    58,    59,    44,    61
};
#endif

#define YYPACT_NINF (-367)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-208)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     559,  -367,    29,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,   510,  -367,    29,    29,     6,  -367,   150,   173,
    -367,    59,    46,   -44,    80,    46,  -367,  -367,     6,  -367,
      46,   -44,   -31,    -6,    46,   -44,    29,    29,    29,   192,
     222,  -367,    15,  -367,  -367,    13,   192,    62,   222,    62,
      62,  -367,  -367,  -367,    46,   -44,    29,    29,    29,   104,
     109,   112,   137,  -367,    17,  -367,  -367,   137,  -367,    19,
    -367,  -367,  -367,    10,    29,   137,  -367,    21,  -367,  -367,
     137,   137,  -367,    22,  -367,  -367,   137,    29,   945,   119,
     945,    29,    29,    29,  -367,    25,  -367,  -367,  -367,  -367,
      27,  -367,  -367,  -367,     6,    29,  -367,   154,  -367,    35,
    -367,  -367,  -367,  -367,    36,  -367,  -367,  -367,    39,  -367,
    -367,  -367,  -367,    42,  -367,  -367,   163,    29,   885,     6,
    -367,  -367,  -367,   150,   191,    46,   -44,  -367,   897,    71,
       2,    53,  -367,  -367,  1262,   970,   925,    29,  -367,  -367,
    -367,  -367,    29,    76,  -367,     6,    29,    29,    29,    46,
     -44,    46,   -44,   174,  -367,    29,    29,    29,    29,    29,
     102,  -367,   114,    29,    29,    29,    29,     6,     6,   841,
    -367,  -367,  -367,  -367,  -367,  -367,   925,   925,   925,   925,
    -367,     6,   155,   173,   191,  1191,  -367,   780,     6,     6,
       6,     6,     6,  -367,  1333,  1522,   209,   213,  -367,    46,
     -44,  -367,  -367,  -367,    29,   218,   218,   219,   218,   219,
      29,   220,   118,  1404,   127,   130,    46,   -44,    46,   -44,
     667,    46,   -44,   -14,   -14,   -14,  1399,    46,   -44,   230,
      79,   230,    62,    79,    62,  -367,   131,    29,    29,    29,
      29,    29,   925,   925,   925,   925,   925,   925,   925,   925,
     925,   925,   925,   925,   925,   925,   925,   925,   229,   925,
      29,    46,   -44,    46,   -44,    46,   -44,    46,   -44,    46,
     -44,    46,   -44,  -367,  -367,  -367,   142,    29,    29,     4,
      29,    28,     0,  -367,    29,     0,   925,   143,    29,    29,
      29,    29,    29,    46,   -44,  -367,    65,    65,    65,    65,
      65,    65,  -367,   925,   925,   925,   925,   925,  1544,  1565,
     611,   611,   611,   611,   184,   184,   184,   184,   339,   212,
     212,   -14,   -14,   -14,   145,  1452,   925,    29,   140,   151,
     148,   -58,   177,   152,   -24,   157,  1522,    29,     4,    29,
     925,   224,   235,   925,    23,  1522,  1522,  1522,  1522,  1522,
      29,  -367,  1522,   218,    29,    29,    29,    29,    29,    29,
      29,    29,   166,   160,   925,  1429,   185,   193,  1429,    29,
      29,   925,    29,   219,   207,   309,   208,   310,   925,   210,
     925,  -367,    29,    29,   217,   925,   925,   226,   223,   218,
      29,   227,  -367,    29,    29,    29,    28,    29,    29,  1522,
      29,  1522,   925,   231,    29,  1476,  1499,    29,    29,    29,
     232,    34,   219,   228,   925,   241,   -43,   925,  1522,  -367,
    1045,  -367,  -367,  1118,   219,   -18,  -367,    33,  -367,    29,
    1522,  -367,  -367,    29,  1522,    37,    37,    43,  -367,  -367,
    -367,    29,    29,    29,  -367,   219,   329,   291,   293,   295,
     287,   288,   128,  -367,  -367,    29,    29,    29,    29,    29,
      29,    29,  1045,  1045,  1045,   925,   925,   243,   246,  -367,
    -367,   -44,  -367,  -367,   -44,  -367,  -367,   -44,  1429,  1429,
      29,    29,   250,   251,   925,   925,    29,    29,    29,    29,
    1404,  1404,   252,   253,  -367,  -367,  -367,  -367,    56,    56,
      76,    76,  -367,  -367
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      85,   209,   207,    92,    93,    95,    94,    91,    96,    98,
      97,   211,    85,     4,   207,   207,     0,     5,     0,    85,
      86,    85,     3,     2,     0,   208,     1,     8,     0,     9,
      12,    13,     0,     0,     7,     6,   207,   207,   207,     0,
       0,    57,   207,    35,    34,     0,     0,    85,     0,    85,
      85,   210,   212,    32,    11,    10,   207,   207,   207,     0,
       0,     0,     0,    75,   207,    53,    55,     0,    59,   207,
      37,    36,    56,     0,   207,     0,    74,   207,    52,    54,
       0,     0,    61,   207,    39,    38,     0,   207,    85,     0,
      85,   207,   207,   207,    66,   207,    44,    41,    77,    67,
     207,    45,    42,    58,   207,   207,    99,     0,    65,   207,
      43,    40,    76,    71,   207,    49,    46,    73,   207,    51,
      48,    60,    72,   207,    50,    47,     0,   207,    85,     0,
      18,    22,    21,   207,    85,    17,    16,    33,    85,     0,
       0,     0,    63,    64,    85,    85,     0,   207,    62,    68,
      70,    69,   207,     0,    15,     0,   207,   207,   207,    26,
      29,    20,    19,     0,    14,   207,   207,   207,   207,   207,
     142,   143,     0,   207,   207,   207,   207,     0,     0,     0,
     145,   146,   149,   147,   148,   150,     0,     0,     0,     0,
     105,     0,     0,    85,    85,    85,   118,     0,     0,     0,
       0,     0,     0,   104,    85,   100,     0,     0,    78,    25,
      24,    23,    28,    27,   207,    87,     0,     0,     0,     0,
     207,     0,     0,    85,     0,     0,   135,   134,   137,   136,
       0,   139,   138,   153,   154,   152,     0,   121,   120,     0,
       0,     0,    85,     0,    85,   119,     0,   207,   207,   207,
     207,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,   132,   133,   123,   122,   125,   124,   129,   128,   127,
     126,   131,   130,   103,    31,    30,     0,   207,   207,    88,
     207,   112,   106,   113,   207,   109,   176,   173,   207,   207,
     207,   207,   207,   140,   141,   151,     0,     0,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   160,   161,   175,   155,
     156,   158,   157,   159,   170,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   207,   177,   207,
       0,     0,     0,     0,     0,   181,   182,   183,   184,   185,
     207,   172,   180,    87,   207,   207,   207,   207,   207,   207,
     207,   207,     0,     0,   176,   207,     0,     0,   207,   207,
     207,   176,   207,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   207,   207,     0,     0,     0,     0,     0,     0,
     207,     0,    89,   207,   207,   207,   116,   207,   207,   107,
     207,   110,     0,     0,   207,     0,     0,   207,   207,   207,
       0,    80,     0,     0,     0,     0,     0,     0,   179,   174,
      85,   190,   189,    85,     0,     0,   171,     0,   101,   207,
     108,   115,   114,   207,   111,   196,   195,   207,   188,   187,
     186,   207,   207,   207,    79,     0,     0,     0,     0,     0,
       0,     0,     0,    90,   117,   207,   207,   207,   207,   207,
     207,   207,    85,    85,    85,     0,     0,     0,     0,   202,
     199,   205,   201,   198,   204,   203,   200,   206,   207,   207,
     207,   207,     0,     0,   176,   176,   207,   207,   207,   207,
      85,    85,     0,     0,   192,   191,   194,   193,    82,    81,
       0,     0,    84,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -367,  -367,   342,   265,  -367,  -367,    11,    14,   -85,   -81,
     538,    -4,  -214,   579,  -367,   592,   606,   749,   -77,    12,
     262,  -213,   -30,  -367,   216,  -194,   267,  -366,  -367,  -367,
    -367,  -367,  -367,  -367,    -2,   649,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,   128,    14,    15,   191,   130,   131,   132,
     192,   288,   289,   193,    20,   194,    41,    42,   106,    43,
      44,   292,   293,   408,   195,   196,   197,   347,   348,   198,
     199,   200,   201,   202,    73,    25,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   245,   290,     1,   294,    23,   295,     1,   393,     1,
     245,    16,    32,    33,    17,   400,    45,    31,     1,    50,
       1,    35,     1,    28,     1,     1,    29,   379,     1,   300,
       1,     1,     1,    55,    59,    60,    61,     1,     1,     1,
       1,   367,     1,   157,   442,     1,     1,   158,   366,    51,
       8,    65,    70,   157,    88,    89,    90,   158,    78,     1,
      84,    52,     1,   443,  -207,     3,     4,     5,     3,     4,
       5,    56,   107,    57,    96,   370,   208,     9,    10,   101,
    -207,   452,   366,   268,    53,   126,   269,   110,   366,   139,
     140,   141,   115,   119,     6,     7,    58,     6,   124,   129,
     166,   129,   144,   146,    37,    38,   167,  -207,    91,   145,
    -207,    11,   104,    92,  -207,     7,    93,   105,    37,    38,
      72,   380,    98,   137,   103,   153,   112,   121,   498,   499,
     142,   163,   143,   160,   162,   104,  -207,   453,  -207,   155,
     148,   149,   156,   160,   150,   206,   299,   151,    52,   155,
     207,   168,   156,     1,   211,   212,   213,   169,  -207,   147,
     210,   470,   471,   215,   216,   217,   218,   219,   152,   165,
     402,   222,   223,   224,   225,    36,    37,    38,   104,     3,
       4,     5,   227,   229,   232,   419,     7,     8,    36,    37,
      38,     7,     8,   246,    37,    38,   238,     3,     4,     5,
     220,   214,   272,   274,   276,   278,   280,   282,     6,   438,
       8,   221,   286,   284,     9,    10,   298,   285,   296,     9,
      10,   451,   287,   291,   297,   301,     6,     7,   302,     8,
      36,    37,    38,   334,   312,   304,   446,     9,    10,   450,
     337,   349,   463,   360,   364,   313,   314,   315,   316,   317,
     365,    65,    70,    78,   366,    84,     9,    10,     7,   369,
      36,    37,    38,   368,   371,   391,   392,     8,   336,    37,
      38,   376,   262,   263,   264,   265,   266,   267,   480,   483,
     486,   268,   377,   395,   269,   338,   339,   340,   341,   342,
     343,   396,   344,   345,     9,    10,   350,   351,   352,   353,
     354,    66,    71,   265,   266,   267,   505,   507,    79,   268,
      85,   403,   269,   404,   406,   405,   414,   410,    96,   101,
     110,   115,   119,   124,    97,   417,   421,   418,   441,   102,
     429,   436,   439,   464,   465,   363,   466,   111,   467,   468,
     469,   490,   116,   120,   491,   372,   373,   374,   125,   496,
     497,   508,   509,   445,    27,   138,   449,   407,   381,   382,
     454,   204,   383,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,   394,     0,     0,   397,   398,   399,     0,
     401,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,   413,     0,     0,     0,   479,   482,   485,   420,     0,
       0,   422,   423,   424,   342,   425,   426,     0,   427,     0,
       0,     0,   430,   205,     0,   433,   434,   435,     0,   437,
       0,     0,     0,   504,   506,     0,     0,  -208,   263,   264,
     265,   266,   267,   512,   513,   447,   268,   455,     0,   269,
       0,   456,     0,   457,   458,   459,   230,     0,     0,   460,
     461,   462,     0,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,   472,   473,   474,   475,   476,   477,   478,
       0,     0,     0,     0,     0,     0,     0,   481,   484,   487,
       0,     0,     0,     0,     0,     0,   492,   493,   494,   495,
       0,     0,     0,     0,   500,   501,   502,   503,     0,     0,
       0,    66,    71,    79,     0,    85,   510,   511,     0,     0,
      26,     0,     0,     1,     0,     2,     3,     4,     5,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,     0,   335,     0,    18,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     0,     0,
      18,     0,     0,     0,     0,     0,     0,    46,     0,    48,
       0,     0,     1,   346,     2,     3,     4,     5,    97,   102,
     111,   116,   120,   125,     9,    10,     0,     0,     0,    19,
     355,   356,   357,   358,   359,    80,     0,    86,    87,     0,
       0,    19,    21,     0,     6,     7,     8,    39,     0,     0,
      49,     0,     0,   362,    21,     0,     0,     0,     0,     0,
      40,    47,     0,     0,     0,    11,     0,   375,     0,    67,
     378,     0,     0,     9,    10,     0,   133,    81,   133,     0,
       0,    62,     0,     0,     0,     0,     0,    74,    75,     0,
       0,   346,     0,     0,     0,    63,    68,     0,   346,    22,
       0,     0,    76,     0,    82,   409,     0,   411,     0,     0,
       0,    30,   415,   416,    11,    34,   133,    19,    94,    19,
       1,     0,    48,    99,     0,     0,   133,    54,     0,   428,
     134,   108,   134,     0,     0,     0,   113,   117,     0,     0,
       0,   440,   122,     0,   444,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,     0,    19,   268,     0,
       0,   269,    39,    49,     0,     0,     0,    19,     0,     0,
     134,     0,     0,     0,     0,    40,     0,     0,     0,     0,
     134,   241,   243,     0,     0,     0,     0,   135,     0,   135,
       0,     0,   488,   489,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   346,   346,     0,   268,     0,     0,   269,     0,     0,
       0,   239,    11,   244,     0,     0,     0,   159,   161,     0,
     309,     0,   311,     1,   240,   242,     0,   159,    64,    69,
       0,     0,     0,     0,     0,    77,     0,    83,     0,     0,
       0,     0,     0,     0,   209,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,   100,     0,     0,   307,
       0,     0,   310,     0,   109,     0,   226,   228,   231,   114,
     118,   306,     0,   308,     0,   123,     0,     0,     0,     0,
     237,     0,     0,     0,     1,   170,   271,   273,   275,   277,
     279,   281,     0,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   171,   172,     0,   268,     0,   303,
     269,     0,     0,     0,     0,    11,     0,   270,     1,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     3,     4,     5,     0,     0,   180,   181,
     182,   183,   184,   185,     0,   127,     0,     0,     0,     0,
       6,     7,     8,     0,     0,     0,     0,   127,     0,   170,
     186,   187,     6,     7,     8,     0,     0,   188,     0,   189,
       0,     0,     0,     0,     0,     0,    11,     0,     1,     9,
      10,     3,     4,     5,     0,     0,     0,     0,   171,   172,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   127,     3,     4,     5,     0,
       6,     7,     8,     0,     0,     0,     0,     0,   154,     0,
      11,     0,   180,   181,   182,   183,   184,   185,     0,     0,
     164,     0,    11,   171,   172,     6,     7,     8,     0,     9,
      10,     0,   173,     0,   186,   187,   174,   175,   176,   177,
     178,   188,     0,   189,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    10,     0,   180,   181,   182,
     183,   184,   185,     0,     0,     0,     0,     0,     0,   170,
      11,     3,     4,     5,     0,     0,     0,     0,     0,   186,
     187,     0,     0,     0,     0,     0,   188,     0,   189,     0,
       0,     0,     0,   203,     0,    52,     0,     0,   171,   172,
       6,     7,     8,     0,     0,     0,     0,   173,     0,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,     0,   180,   181,   182,   183,   184,   185,     0,     0,
       0,     0,   170,     0,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,   186,   187,     0,     0,     0,     0,
       0,   188,     0,   189,     0,     0,     0,   104,     0,     0,
      11,   171,   172,     6,     7,     8,     0,     0,     0,     0,
     173,     0,     0,     0,   174,   175,   176,   177,   178,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     0,   180,   181,   182,   183,   184,
     185,     0,     0,     0,     1,   170,     0,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,   186,   187,     0,
       0,     0,     0,     0,   188,     0,   189,     0,     0,     0,
     104,     0,     0,   448,   171,   172,     6,     7,     8,     0,
       0,     0,     0,   173,     0,     0,     0,   174,   175,   176,
     177,   178,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,     0,   180,   181,
     182,   183,   184,   185,     0,     0,   170,     0,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   187,     0,     0,     0,     0,     0,   188,     0,   189,
       0,     0,     0,     0,  -207,   171,   172,     6,     7,     8,
       0,     0,     0,     0,   173,     0,     0,     0,   174,   175,
     176,   177,   178,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    10,     0,   180,
     181,   182,   183,   184,   185,     0,     0,   170,     0,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   187,     0,     0,     0,     0,     0,   188,     0,
     189,     0,     0,     0,     0,   190,   171,   172,     6,     7,
       8,     0,     0,     0,     0,   173,     0,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
     180,   181,   182,   183,   184,   185,     0,     0,   170,     0,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,   187,     0,     0,     0,     0,     0,   188,
       0,   189,     1,     0,     0,     0,   283,   171,   172,     6,
       7,     8,     0,     0,     0,     0,   173,     0,     0,     0,
     174,   175,   176,   177,   178,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
       0,   180,   181,   182,   183,   184,   185,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   186,   187,     0,   268,     0,   305,   269,
     188,     0,   189,     0,     0,     0,   104,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,     0,     0,     0,   268,     0,     0,   269,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,     0,     0,   268,
       0,     0,   269,   361,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,     0,     0,   268,     0,   431,   269,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,     0,     0,     0,   268,     0,   432,   269,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,     0,     0,   268,
       0,     0,   269,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,     0,
       0,   268,     0,     0,   269,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,     0,
       0,     0,   268,     0,     0,   269
};

static const yytype_int16 yycheck[] =
{
       2,   195,   216,     3,   218,     0,   219,     3,   374,     3,
     204,     0,    14,    15,     0,   381,    18,    12,     3,    21,
       3,    16,     3,    12,     3,     3,    12,     4,     3,   223,
       3,     3,     3,    28,    36,    37,    38,     3,     3,     3,
       3,    99,     3,   128,    87,     3,     3,   128,   106,     3,
      37,    39,    40,   138,    56,    57,    58,   138,    46,     3,
      48,   105,     3,   106,     5,     6,     7,     8,     6,     7,
       8,   102,    74,   104,    62,    99,   153,    64,    65,    67,
      43,    99,   106,    97,     4,    87,   100,    75,   106,    91,
      92,    93,    80,    81,    35,    36,   102,    35,    86,    88,
      98,    90,   104,   105,    39,    40,   104,   107,     4,   104,
     106,   105,   102,     4,    86,    36,     4,   107,    39,    40,
     105,    98,   105,     4,   105,   127,   105,   105,   494,   495,
     105,   133,   105,   128,   129,   102,   102,   104,   104,   128,
     105,   105,   128,   138,   105,   147,   223,   105,   105,   138,
     152,    98,   138,     3,   156,   157,   158,   104,   102,     5,
     155,    33,    34,   165,   166,   167,   168,   169,     5,    98,
     383,   173,   174,   175,   176,    38,    39,    40,   102,     6,
       7,     8,   177,   178,   179,   399,    36,    37,    38,    39,
      40,    36,    37,   195,    39,    40,   191,     6,     7,     8,
      98,    27,   197,   198,   199,   200,   201,   202,    35,   422,
      37,    97,   214,     4,    64,    65,    98,     4,   220,    64,
      65,   434,     4,     4,     4,    98,    35,    36,    98,    37,
      38,    39,    40,     4,   103,   230,   430,    64,    65,   433,
      98,    98,   455,    98,   104,   247,   248,   249,   250,   251,
      99,   239,   240,   241,   106,   243,    64,    65,    36,   107,
      38,    39,    40,    86,   107,    99,   106,    37,   270,    39,
      40,    47,    88,    89,    90,    91,    92,    93,   472,   473,
     474,    97,    47,    98,   100,   287,   288,   289,   290,   291,
     292,    98,   294,   295,    64,    65,   298,   299,   300,   301,
     302,    39,    40,    91,    92,    93,   500,   501,    46,    97,
      48,   104,   100,     4,     4,   107,    99,   107,   306,   307,
     308,   309,   310,   311,    62,    99,    99,   104,    87,    67,
      99,    99,   104,     4,    43,   337,    43,    75,    43,    52,
      52,    98,    80,    81,    98,   347,   348,   349,    86,    99,
      99,    99,    99,   430,    12,    90,   433,   387,   360,   363,
     437,   145,   364,   365,   366,   367,   368,   369,   370,   371,
      -1,    -1,    -1,   375,    -1,    -1,   378,   379,   380,    -1,
     382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,   393,    -1,    -1,    -1,   472,   473,   474,   400,    -1,
      -1,   403,   404,   405,   406,   407,   408,    -1,   410,    -1,
      -1,    -1,   414,   146,    -1,   417,   418,   419,    -1,   421,
      -1,    -1,    -1,   500,   501,    -1,    -1,    88,    89,    90,
      91,    92,    93,   510,   511,   430,    97,   439,    -1,   100,
      -1,   443,    -1,   445,   446,   447,   179,    -1,    -1,   451,
     452,   453,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,   467,   468,   469,   470,   471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,   473,   474,
      -1,    -1,    -1,    -1,    -1,    -1,   488,   489,   490,   491,
      -1,    -1,    -1,    -1,   496,   497,   498,   499,    -1,    -1,
      -1,   239,   240,   241,    -1,   243,   508,   509,    -1,    -1,
       0,    -1,    -1,     3,    -1,     5,     6,     7,     8,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,    -1,   269,    -1,     0,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      -1,    -1,     3,   296,     5,     6,     7,     8,   306,   307,
     308,   309,   310,   311,    64,    65,    -1,    -1,    -1,     0,
     313,   314,   315,   316,   317,    47,    -1,    49,    50,    -1,
      -1,    12,     0,    -1,    35,    36,    37,    18,    -1,    -1,
      21,    -1,    -1,   336,    12,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,   105,    -1,   350,    -1,    40,
     353,    -1,    -1,    64,    65,    -1,    88,    48,    90,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,   374,    -1,    -1,    -1,    39,    40,    -1,   381,     0,
      -1,    -1,    46,    -1,    48,   388,    -1,   390,    -1,    -1,
      -1,    12,   395,   396,   105,    16,   128,    88,    62,    90,
       3,    -1,   134,    67,    -1,    -1,   138,    28,    -1,   412,
      88,    75,    90,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,   424,    86,    -1,   427,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,   128,    97,    -1,
      -1,   100,   133,   134,    -1,    -1,    -1,   138,    -1,    -1,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   193,   194,    -1,    -1,    -1,    -1,    88,    -1,    90,
      -1,    -1,   475,   476,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   494,   495,    -1,    97,    -1,    -1,   100,    -1,    -1,
      -1,   192,   105,   194,    -1,    -1,    -1,   128,   129,    -1,
     242,    -1,   244,     3,   192,   193,    -1,   138,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   240,
      -1,    -1,   243,    -1,    75,    -1,   177,   178,   179,    80,
      81,   239,    -1,   241,    -1,    86,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,     3,     4,   197,   198,   199,   200,
     201,   202,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    33,    34,    -1,    97,    -1,   230,
     100,    -1,    -1,    -1,    -1,   105,    -1,   107,     3,    -1,
      -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,     7,     8,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    30,    -1,     4,
      89,    90,    35,    36,    37,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,     3,    64,
      65,     6,     7,     8,    -1,    -1,    -1,    -1,    33,    34,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    30,     6,     7,     8,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,   103,    -1,
     105,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
     103,    -1,   105,    33,    34,    35,    36,    37,    -1,    64,
      65,    -1,    42,    -1,    89,    90,    46,    47,    48,    49,
      50,    96,    -1,    98,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,     4,
     105,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,   103,    -1,   105,    -1,    -1,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,     4,    -1,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,   105,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,     4,    -1,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,   103,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,     4,    -1,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,    -1,   103,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,     4,    -1,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,     3,    -1,    -1,    -1,   103,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    89,    90,    -1,    97,    -1,    99,   100,
      96,    -1,    98,    -1,    -1,    -1,   102,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,   101,    78,    79,    80,    81,    82,    83,
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
       0,     3,     5,     6,     7,     8,    35,    36,    37,    64,
      65,   105,   109,   110,   112,   113,   114,   115,   118,   121,
     122,   123,   143,   144,   142,   143,     0,   110,   114,   115,
     143,   144,   142,   142,   143,   144,    38,    39,    40,   121,
     123,   124,   125,   127,   128,   142,   118,   123,   118,   121,
     142,     3,   105,     4,   143,   144,   102,   104,   102,   142,
     142,   142,   123,   124,   125,   127,   128,   121,   124,   125,
     127,   128,   105,   142,   123,   123,   124,   125,   127,   128,
     118,   121,   124,   125,   127,   128,   118,   118,   142,   142,
     142,     4,     4,     4,   124,   125,   127,   128,   105,   124,
     125,   127,   128,   105,   102,   107,   126,   142,   124,   125,
     127,   128,   105,   124,   125,   127,   128,   124,   125,   127,
     128,   105,   124,   125,   127,   128,   142,    30,   111,   114,
     115,   116,   117,   118,   123,   143,   144,     4,   111,   142,
     142,   142,   105,   105,   142,   144,   142,     5,   105,   105,
     105,   105,     5,   142,   103,   114,   115,   116,   117,   143,
     144,   143,   144,   142,   103,    98,    98,   104,    98,   104,
       4,    33,    34,    42,    46,    47,    48,    49,    50,    55,
      67,    68,    69,    70,    71,    72,    89,    90,    96,    98,
     103,   114,   118,   121,   123,   132,   133,   134,   137,   138,
     139,   140,   141,   103,   132,   134,   142,   142,   126,   143,
     144,   142,   142,   142,    27,   142,   142,   142,   142,   142,
      98,    97,   142,   142,   142,   142,   143,   144,   143,   144,
     134,   143,   144,   134,   134,   134,   134,   143,   144,   121,
     123,   118,   123,   118,   121,   133,   142,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    97,   100,
     107,   143,   144,   143,   144,   143,   144,   143,   144,   143,
     144,   143,   144,   103,     4,     4,   142,     4,   119,   120,
     120,     4,   129,   130,   120,   129,   142,     4,    98,   126,
     133,    98,    98,   143,   144,    99,   123,   121,   123,   118,
     121,   118,   103,   142,   142,   142,   142,   142,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,     4,   134,   142,    98,   142,   142,
     142,   142,   142,   142,   142,   142,   134,   135,   136,    98,
     142,   142,   142,   142,   142,   134,   134,   134,   134,   134,
      98,   101,   134,   142,   104,    99,   106,    99,    86,   107,
      99,   107,   142,   142,   142,   134,    47,    47,   134,     4,
      98,   142,   119,   142,   142,   142,   142,   142,   142,   142,
     142,    99,   106,   135,   142,    98,    98,   142,   142,   142,
     135,   142,   129,   104,     4,   107,     4,   130,   131,   134,
     107,   134,   142,   142,    99,   134,   134,    99,   104,   120,
     142,    99,   142,   142,   142,   142,   142,   142,   134,    99,
     142,    99,    99,   142,   142,   142,    99,   142,   129,   104,
     134,    87,    87,   106,   134,   126,   133,   144,   105,   126,
     133,   129,    99,   104,   126,   142,   142,   142,   142,   142,
     142,   142,   142,   129,     4,    43,    43,    43,    52,    52,
      33,    34,   142,   142,   142,   142,   142,   142,   142,   126,
     133,   144,   126,   133,   144,   126,   133,   144,   134,   134,
      98,    98,   142,   142,   142,   142,    99,    99,   135,   135,
     142,   142,   142,   142,   126,   133,   126,   133,    99,    99,
     142,   142,   126,   126
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   117,
     117,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   122,   122,   122,   122,   123,   123,   123,   124,
     124,   125,   126,   126,   126,   126,   127,   127,   127,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   137,   137,   137,   138,   138,   138,   139,
     139,   140,   140,   140,   140,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   142,   142,   143,
     143,   144,   144
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     2,     2,     6,     6,     1,     1,     1,     2,
       2,     1,     1,     3,     3,     3,     2,     3,     3,     2,
       7,     7,     3,     5,     2,     2,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     3,     2,     4,     3,
       4,     3,     5,     5,     5,     4,     4,     4,     5,     5,
       5,     4,     4,     4,     3,     3,     4,     4,     3,    11,
       9,    19,    19,    21,    21,     0,     1,     0,     1,     5,
       9,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,    13,     5,     4,     3,     3,     7,    11,    13,     7,
      11,    13,     1,     1,     7,     7,     1,     5,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     1,     1,     6,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     8,     4,     3,     8,     3,     0,     1,     1,     5,
       4,     4,     4,     4,     4,     4,     9,     9,     9,     8,
       8,    17,    17,    17,    17,     9,     9,     9,    13,    13,
      13,    13,    13,    13,    13,    13,    13,     0,     1,     1,
       2,     1,     2
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

#line 2056 "synt_analyzer.tab.cpp"

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

#line 473 "synt_analyzer.y"

//Секция пользовательского кода


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}




















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
  YYSYMBOL_STR = 5,                        /* STR  */
  YYSYMBOL_CLASS = 6,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 7,                     /* PUBLIC  */
  YYSYMBOL_PRIVATE = 8,                    /* PRIVATE  */
  YYSYMBOL_PROTECTED = 9,                  /* PROTECTED  */
  YYSYMBOL_FIELD = 10,                     /* FIELD  */
  YYSYMBOL_PARAM = 11,                     /* PARAM  */
  YYSYMBOL_SETPARAM = 12,                  /* SETPARAM  */
  YYSYMBOL_DELEGATE = 13,                  /* DELEGATE  */
  YYSYMBOL_INTERFACE = 14,                 /* INTERFACE  */
  YYSYMBOL_OBJECT = 15,                    /* OBJECT  */
  YYSYMBOL_PROPERTY = 16,                  /* PROPERTY  */
  YYSYMBOL_DYNAMIC = 17,                   /* DYNAMIC  */
  YYSYMBOL_ENUM = 18,                      /* ENUM  */
  YYSYMBOL_SEALED = 19,                    /* SEALED  */
  YYSYMBOL_SUSPEND = 20,                   /* SUSPEND  */
  YYSYMBOL_INNER = 21,                     /* INNER  */
  YYSYMBOL_EXTERNAL = 22,                  /* EXTERNAL  */
  YYSYMBOL_ACTUAL = 23,                    /* ACTUAL  */
  YYSYMBOL_ANNOTATION = 24,                /* ANNOTATION  */
  YYSYMBOL_GET = 25,                       /* GET  */
  YYSYMBOL_SET = 26,                       /* SET  */
  YYSYMBOL_RECEIVER = 27,                  /* RECEIVER  */
  YYSYMBOL_CONSTRUCTOR = 28,               /* CONSTRUCTOR  */
  YYSYMBOL_BY = 29,                        /* BY  */
  YYSYMBOL_COMPANION = 30,                 /* COMPANION  */
  YYSYMBOL_INIT = 31,                      /* INIT  */
  YYSYMBOL_LATEINIT = 32,                  /* LATEINIT  */
  YYSYMBOL_VARARG = 33,                    /* VARARG  */
  YYSYMBOL_THIS = 34,                      /* THIS  */
  YYSYMBOL_SUPER = 35,                     /* SUPER  */
  YYSYMBOL_INTERNAL = 36,                  /* INTERNAL  */
  YYSYMBOL_OVERRIDE = 37,                  /* OVERRIDE  */
  YYSYMBOL_ABSTRACT = 38,                  /* ABSTRACT  */
  YYSYMBOL_FUN = 39,                       /* FUN  */
  YYSYMBOL_VAR = 40,                       /* VAR  */
  YYSYMBOL_VAL = 41,                       /* VAL  */
  YYSYMBOL_TYPEOF = 42,                    /* TYPEOF  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_ELSE = 44,                      /* ELSE  */
  YYSYMBOL_WHERE = 45,                     /* WHERE  */
  YYSYMBOL_WHEN = 46,                      /* WHEN  */
  YYSYMBOL_DO = 47,                        /* DO  */
  YYSYMBOL_WHILE = 48,                     /* WHILE  */
  YYSYMBOL_FOR = 49,                       /* FOR  */
  YYSYMBOL_BREAK = 50,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 51,                  /* CONTINUE  */
  YYSYMBOL_AS = 52,                        /* AS  */
  YYSYMBOL_IN = 53,                        /* IN  */
  YYSYMBOL_OUT = 54,                       /* OUT  */
  YYSYMBOL_DATA = 55,                      /* DATA  */
  YYSYMBOL_RETURN = 56,                    /* RETURN  */
  YYSYMBOL_TAILREC = 57,                   /* TAILREC  */
  YYSYMBOL_OPERATOR = 58,                  /* OPERATOR  */
  YYSYMBOL_INLINE = 59,                    /* INLINE  */
  YYSYMBOL_NOINLINE = 60,                  /* NOINLINE  */
  YYSYMBOL_CROSSINLINE = 61,               /* CROSSINLINE  */
  YYSYMBOL_REIFIED = 62,                   /* REIFIED  */
  YYSYMBOL_EXPECT = 63,                    /* EXPECT  */
  YYSYMBOL_INFIX = 64,                     /* INFIX  */
  YYSYMBOL_OPEN = 65,                      /* OPEN  */
  YYSYMBOL_FINAL = 66,                     /* FINAL  */
  YYSYMBOL_CONST = 67,                     /* CONST  */
  YYSYMBOL_INT = 68,                       /* INT  */
  YYSYMBOL_FLOAT = 69,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 70,                    /* DOUBLE  */
  YYSYMBOL_CHR = 71,                       /* CHR  */
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
  YYSYMBOL_105_ = 105,                     /* ','  */
  YYSYMBOL_106_ = 106,                     /* '='  */
  YYSYMBOL_107_ = 107,                     /* ';'  */
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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1576

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  419

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
      98,    99,    92,    89,   105,    90,    97,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,   107,
      86,   106,    87,     2,     2,     2,     2,     2,     2,     2,
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
       0,   193,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   209,   210,   211,   212,
     213,   214,   215,   216,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   231,   232,   233,   234,   237,   238,
     239,   240,   243,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   261,   262,   265,   266,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   325,   327,   329,   331,   333,   335,
     336,   337,   339,   343,   344,   345,   346,   350,   351,   354,
     355,   359,   363,   364,   365,   366,   370,   371,   372,   376,
     377,   378,   381,   382,   385,   388,   389,   390,   391,   394,
     395,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   448,   449,   452,
     453,   456,   457,   458,   459,   460,   461,   464,   465,   466,
     469,   470,   471,   474,   475,   476,   477,   478,   479,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   499,   500,   501,   502
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
  "STR", "CLASS", "PUBLIC", "PRIVATE", "PROTECTED", "FIELD", "PARAM",
  "SETPARAM", "DELEGATE", "INTERFACE", "OBJECT", "PROPERTY", "DYNAMIC",
  "ENUM", "SEALED", "SUSPEND", "INNER", "EXTERNAL", "ACTUAL", "ANNOTATION",
  "GET", "SET", "RECEIVER", "CONSTRUCTOR", "BY", "COMPANION", "INIT",
  "LATEINIT", "VARARG", "THIS", "SUPER", "INTERNAL", "OVERRIDE",
  "ABSTRACT", "FUN", "VAR", "VAL", "TYPEOF", "IF", "ELSE", "WHERE", "WHEN",
  "DO", "WHILE", "FOR", "BREAK", "CONTINUE", "AS", "IN", "OUT", "DATA",
  "RETURN", "TAILREC", "OPERATOR", "INLINE", "NOINLINE", "CROSSINLINE",
  "REIFIED", "EXPECT", "INFIX", "OPEN", "FINAL", "CONST", "INT", "FLOAT",
  "DOUBLE", "CHR", "BOOLEAN", "ASUM", "ASUB", "ADIV", "AMUL", "AMOD", "OR",
  "AND", "EQ", "AEQ", "NEQ", "NAEQ", "LOEQ", "MOEQ", "'<'", "'>'", "RANGE",
  "'+'", "'-'", "'/'", "'*'", "'%'", "UMINUS", "UPLUS", "'!'", "'.'",
  "'('", "')'", "'['", "']'", "':'", "'{'", "'}'", "','", "'='", "';'",
  "$accept", "program", "class", "classBody", "property", "method",
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
      91,    93,    58,   123,   125,    44,    61,    59
};
#endif

#define YYPACT_NINF (-311)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1041,  -311,    56,  -311,  -311,  -311,  -311,   289,   421,    58,
       6,    21,  -311,  -311,  -311,   415,  -311,  -311,    33,    42,
     221,  -311,     3,     9,     9,    24,   -62,    28,   203,    79,
      28,    32,   199,   -48,   -26,    77,   -10,    77,  -311,  -311,
    -311,    42,     9,     9,    24,   101,  -311,     3,   212,    85,
     115,     9,     9,   178,   266,   155,   549,   374,  -311,    24,
      24,    24,  -311,  -311,   107,   764,   129,    37,   129,    90,
      37,    95,   129,    37,   129,   100,    37,   142,    77,   140,
     102,   -67,   140,   -42,     9,     9,    24,    24,   123,    24,
     129,   159,   129,   180,   182,   185,    24,    24,    37,   189,
      37,   197,   206,   215,   162,  -311,  -311,   173,   188,   609,
     196,   208,     9,     9,  1004,  -311,  -311,  -311,  -311,  -311,
     374,   374,   374,   374,  -311,     9,     9,  1081,  -311,   458,
       9,  -311,     9,  -311,  -311,   620,  1076,   201,   211,   207,
    -311,   804,     9,  -311,  -311,  -311,   143,   153,  -311,  -311,
      24,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,   216,   171,   225,   214,  -311,   140,   218,
     310,   220,   222,    24,    24,   313,   818,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,   374,
     314,   374,   223,   274,  1246,   374,    29,    24,    24,   488,
      24,    46,    46,    46,  1293,    24,    24,  -311,  -311,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     325,   374,   374,    24,    24,    24,  -311,  1140,   858,    77,
    -311,  -311,     9,  -311,  -311,  -311,    24,    24,  -311,  -311,
     232,   229,   330,   374,  -311,   374,   235,   374,   374,   239,
    -311,   898,  1076,   244,   233,   249,  1316,   374,   251,   252,
    1339,   255,    77,    24,  -311,  1076,  1076,  1076,  1076,  1076,
    1476,  1215,   788,   788,   788,   788,   385,   385,   385,   385,
     540,   192,   192,    46,    46,    46,   253,  1269,  1076,  -311,
    -311,   912,   259,    24,    77,   140,   225,  -311,   -57,  1076,
    1076,   140,  1076,  1076,   952,  -311,  -311,   374,   374,   691,
    1362,   374,   374,   691,   140,    -4,   374,  -311,  -311,   130,
     261,  -311,  -311,   359,  -311,  -311,   992,  1076,   267,    14,
     321,   423,    17,  -311,  1385,  1408,     9,  -311,    24,   315,
     318,   268,   204,  -311,   177,   225,  -311,  -311,  -311,   691,
      24,   691,   691,  1220,  -311,  -311,    24,   374,   374,  -311,
     283,   284,   256,  -311,     9,  -311,    24,     9,  -311,    24,
       9,  -311,    24,     9,  -311,  1431,  1454,   374,   374,   286,
     287,    24,    24,    24,    24,   691,   691,   288,   290,   374,
     374,     9,  -311,    24,     9,  -311,    24,   207,   207,   291,
     293,    24,    24,  -311,  -311,   207,   207,  -311,  -311
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   234,     0,   123,   124,   126,   125,    59,    62,     0,
       0,     0,   128,   127,   233,     0,     3,     4,     0,    60,
      61,    41,     0,     0,     0,     2,     0,    65,    63,    64,
      72,    73,    74,     0,     0,     0,     0,     0,     1,     9,
      10,    60,     0,     0,    15,     0,    39,     0,    66,    68,
      67,     0,     0,    69,    71,    70,     0,     0,   129,    40,
       6,     5,   236,   235,     0,     0,    79,    80,    76,    75,
      78,    77,    94,    93,    95,    96,    97,    98,    55,     0,
       0,     0,     0,     0,     0,     0,    12,    11,     0,    38,
      82,    81,    86,    85,    83,    84,     8,     7,    88,    87,
      92,    91,    90,    89,   164,   163,   165,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   170,   169,   171,
       0,     0,     0,     0,   135,     0,     0,     0,   149,     0,
       0,   154,     0,   156,   157,     0,   130,     0,     0,     0,
      23,     0,     0,    25,    28,    27,     0,    60,    37,    36,
      24,   103,   104,   100,    99,   102,   101,   118,   117,   119,
     120,   121,   122,     0,    56,   142,   136,   143,     0,     0,
       0,   139,     0,    14,    13,     0,     0,   106,   105,   110,
     109,   107,   108,   112,   111,   116,   115,   114,   113,   197,
       0,     0,     0,     0,     0,     0,     0,   159,   160,     0,
     161,   174,   175,   173,     0,   152,   151,   134,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   153,   155,   133,     0,     0,    55,
      42,    19,     0,    29,    32,    31,    33,    26,    35,    34,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
      21,     0,   199,     0,   198,   194,     0,     0,     0,     0,
       0,     0,     0,   162,   172,   202,   203,   204,   205,   206,
     183,   184,   185,   186,   187,   188,   189,   190,   181,   182,
     196,   176,   177,   179,   178,   180,   191,     0,   201,   132,
      22,     0,     0,    30,    55,     0,   145,   146,     0,   137,
     138,     0,   140,   141,     0,    17,   166,     0,   197,     0,
       0,     0,     0,     0,     0,     0,   197,   193,    18,    50,
       0,   131,   144,     0,    58,    20,     0,   200,     0,     0,
     219,     0,   220,   212,     0,     0,     0,   207,   209,     0,
       0,     0,     0,    49,    44,   147,   148,    16,   195,     0,
     221,     0,     0,     0,   211,   210,   208,     0,     0,   192,
       0,     0,     0,    43,     0,   224,   232,     0,   223,   231,
       0,   222,   230,     0,   225,     0,     0,   197,   197,     0,
       0,   228,   227,   226,   229,     0,     0,     0,     0,   197,
     197,     0,   213,   215,     0,   216,   218,    52,    51,     0,
       0,   214,   217,    54,    53,    46,    45,    48,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -311,  -311,   373,  -167,  -123,     4,  -113,  -112,  -213,   -32,
     103,  1186,   345,   -11,    -7,  -108,    34,    55,   -68,  -231,
    -311,   262,  -114,   -55,  -310,  -311,  -311,  -311,  -311,  -311,
    -311,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,   141,   142,   143,   144,   145,   163,   164,
     146,   147,    20,    21,    22,    58,   125,   126,   166,   167,
     308,   127,   128,   129,   263,   264,   130,   131,   132,   133,
     134,   150
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   193,   136,    81,    17,    83,     1,    46,   338,   261,
      34,    47,     1,   208,   171,    44,   351,     1,   242,    40,
      62,   307,    59,    60,    61,    36,   302,    62,   244,   245,
     332,   240,   169,   271,    23,     3,     4,     5,   170,    45,
      64,    65,    86,    87,     3,     4,     5,    89,   333,    42,
      78,    96,    97,    51,   194,    24,   135,   172,   359,   199,
      26,   363,    33,   170,     6,   201,   202,   203,   204,    74,
      43,   301,     9,     6,    52,    84,    79,   397,   398,    48,
      49,    80,    10,    11,   173,   174,     3,     4,     5,   409,
     410,   330,    82,    12,    13,   350,    85,    12,    13,   148,
     254,   170,   356,    18,    35,    88,    56,    12,    13,    57,
      14,   137,   197,   198,   200,     6,    14,    70,    18,    37,
     149,    14,    92,   208,    63,   205,   206,   272,   154,   233,
     234,    63,   235,   156,   262,    46,   266,   160,   242,    47,
     270,   246,   247,   230,   165,   243,   231,   336,   244,   245,
      12,    13,    94,    95,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   148,   297,   298,   242,   162,
     248,   250,     9,    10,    11,     3,     4,     5,   244,   245,
      48,    49,   102,   103,    12,    13,   149,   178,   309,   273,
     310,   249,   312,   313,   168,   340,     3,     4,     5,   347,
     148,   339,   320,   242,     6,   346,    98,   180,    12,    13,
     181,   353,   182,   244,   245,   175,   176,   184,     3,     4,
       5,   149,   352,    56,   186,     6,    76,   331,   370,   371,
     325,    68,   303,   334,   187,   375,   373,   378,   381,   384,
      90,   374,   188,   377,   380,   383,   349,     6,    53,    54,
     189,   246,   337,   262,   341,   243,   344,   345,    12,    13,
     190,   262,   148,     3,     4,     5,   170,    12,    13,   372,
      56,   402,   405,   227,   228,   229,   191,   401,   404,   230,
     389,   390,   231,   149,   195,   148,     3,     4,     5,   413,
     414,   246,     6,   100,   238,   243,   196,   417,   418,   239,
      56,   252,   385,   386,   256,   251,   149,   259,   265,   342,
     253,   267,   268,   348,   255,     6,   257,    27,   258,   296,
     304,   305,   262,   262,   306,   148,   246,   311,   317,   360,
     243,   233,   314,   316,   262,   262,   366,   318,   148,   321,
     322,   326,    29,    32,    12,    13,   149,   324,   329,   376,
     354,   379,   382,   355,    50,   361,   358,   369,   367,   149,
     148,   368,    67,    69,   391,    73,    75,   392,   104,   105,
     393,   387,   388,   394,   399,   400,    50,   407,    39,   408,
     415,   149,   416,    91,    93,   403,   406,   237,     0,     0,
       0,   411,     0,     0,   412,     0,     0,     0,   106,   107,
       0,   151,     0,   153,     0,    38,     0,   157,     1,   159,
       0,     2,     3,     4,     5,     0,     1,     0,     3,     4,
       5,     0,     0,     0,     0,   177,     0,   179,     0,     0,
       0,     0,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,     6,    30,     0,
       0,     1,     0,   120,   121,     0,     0,   362,     0,     0,
     122,     0,   123,   224,   225,   226,   227,   228,   229,     0,
      12,    13,   230,     0,     0,   231,    12,    13,     0,     0,
       0,     1,    50,     0,     0,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
     230,     0,    14,   231,     0,     0,     0,     0,     0,   232,
      14,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     1,   104,   105,   230,     0,     0,   231,     0,
       0,     0,     0,     0,   232,    14,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   106,   107,   230,     0,     0,   231,    10,
      11,     0,   108,     0,     0,    14,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   115,   116,   117,
     118,   119,     0,    62,   104,   105,     0,     0,    -1,   225,
     226,   227,   228,   229,     0,     0,     0,   230,   120,   121,
     231,     0,     0,   106,   107,   122,     0,   123,     0,     0,
       0,     0,     0,   124,   106,   107,    14,   192,     0,     0,
      10,    11,     0,   108,     0,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,     0,     1,   104,   105,     0,   120,   121,
       0,     0,     0,     0,     0,   122,     0,   123,     0,   120,
     121,     0,    56,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,   236,   106,   107,    63,     0,     0,
       0,    10,    11,     0,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,     0,     0,     0,     1,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,     0,     0,     0,   122,     0,   123,
       0,     0,   138,     0,    56,   139,     0,     0,    14,     0,
       6,     7,     8,     9,    10,    11,     0,     1,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     3,     4,     5,     0,    12,
      13,     0,   138,     0,     0,   139,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,   138,     0,     0,   139,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
       0,     1,     0,     0,     0,     3,     4,     5,   140,    12,
      13,    14,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,    12,    13,   230,   138,     0,   231,   139,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
       0,     1,     0,     0,     0,     3,     4,     5,   241,     0,
       0,    14,     0,     0,     0,     1,     0,     0,     0,     3,
       4,     5,   260,    12,    13,    14,   138,     0,     0,   139,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
     138,     0,     0,   139,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     1,     0,     0,     0,     3,
       4,     5,   300,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,     0,
     138,     0,     0,   139,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     1,     0,     0,     0,     3,
       4,     5,   315,     0,     0,    14,     0,     1,   104,   105,
       0,     0,     0,     0,     0,     0,   328,    12,    13,    14,
     138,     0,     0,   139,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,     1,     0,     0,     2,     3,     4,
       5,     0,     0,     0,     0,     0,   335,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,     6,     7,     8,
       9,    10,    11,     0,     0,   104,   105,     0,     0,     0,
       0,     0,     0,   120,   121,     0,   357,     0,     0,    14,
     122,     0,   123,     0,     0,     0,    12,    13,     0,     0,
       0,    14,     0,     0,     0,   106,   107,     0,     0,     0,
       0,    10,    11,     0,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,    14,   115,
     116,   117,   118,   119,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     120,   121,     0,   230,   106,   107,   231,   122,     0,   123,
      10,    11,     0,   108,     0,   207,    19,   109,   110,   111,
     112,   113,     0,    28,    31,     0,   114,     0,     0,     0,
       0,    41,     0,     0,     0,     0,    55,     0,   115,   116,
     117,   118,   119,    66,     0,    71,    72,     0,    77,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,   120,
     121,     0,     0,     0,     0,     0,   122,     0,   123,    99,
     101,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   106,   107,   155,     0,     0,   158,
      10,    11,   161,   108,     0,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,   183,     0,   185,     0,   115,   116,
     117,   118,   119,     0,   269,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   120,
     121,     0,   230,     0,     0,   231,   122,     0,   123,     0,
       0,     0,     0,    56,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,     0,     0,   230,     0,     0,   231,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,     0,     0,   230,     0,     0,   231,
     327,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
     230,     0,   274,   231,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,     0,     0,   230,     0,   319,   231,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,     0,     0,   230,     0,   323,   231,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,   230,
       0,   343,   231,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,     0,
       0,     0,   230,     0,   364,   231,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,   230,     0,   365,   231,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,     0,     0,     0,   230,     0,
     395,   231,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,     0,
       0,   230,     0,   396,   231,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,     0,     0,   230,     0,     0,   231
};

static const yytype_int16 yycheck[] =
{
       0,   109,    57,    35,     0,    37,     3,    18,   318,   176,
       4,    18,     3,   127,    82,    15,   326,     3,   141,    15,
       3,   252,    22,    23,    24,     4,   239,     3,   141,   141,
      87,   139,    99,     4,     0,     7,     8,     9,   105,     6,
     102,   103,    42,    43,     7,     8,     9,    47,   105,    15,
      98,    51,    52,    19,   109,     0,    56,    99,    44,   114,
       4,    44,     4,   105,    36,   120,   121,   122,   123,    37,
      15,   238,    39,    36,    19,    41,   102,   387,   388,    37,
      38,     4,    40,    41,    84,    85,     7,     8,     9,   399,
     400,   304,   102,    65,    66,    99,    41,    65,    66,    65,
     168,   105,   333,     0,    98,     4,   103,    65,    66,   106,
     107,     4,   112,   113,   114,    36,   107,    38,    15,    98,
      65,   107,    37,   237,   107,   125,   126,    98,    38,   129,
     130,   107,   132,    38,   189,   146,   191,    37,   261,   146,
     195,   141,   142,    97,     4,   141,   100,   314,   261,   261,
      65,    66,    37,    38,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   141,   231,   232,   301,    37,
     146,    28,    39,    40,    41,     7,     8,     9,   301,   301,
      37,    38,    37,    38,    65,    66,   141,    38,   253,   199,
     255,   146,   257,   258,   102,   319,     7,     8,     9,   323,
     176,   319,   267,   336,    36,   323,    38,    37,    65,    66,
      38,   329,    37,   336,   336,   102,   103,    38,     7,     8,
       9,   176,   102,   103,    37,    36,    37,   305,    34,    35,
     272,    38,   242,   311,    38,   359,   354,   361,   362,   363,
      38,   359,    37,   361,   362,   363,   324,    36,    37,    38,
      98,   261,   317,   318,   319,   261,   321,   322,    65,    66,
      97,   326,   238,     7,     8,     9,   105,    65,    66,   102,
     103,   395,   396,    91,    92,    93,    98,   395,   396,    97,
      34,    35,   100,   238,    98,   261,     7,     8,     9,   407,
     408,   301,    36,    37,   103,   301,    98,   415,   416,    98,
     103,    86,   367,   368,     4,    99,   261,     4,     4,   319,
     106,    98,    48,   323,   106,    36,   106,    38,   106,     4,
      98,   102,   387,   388,     4,   301,   336,   102,   105,   339,
     336,   341,   103,    99,   399,   400,   346,    98,   314,    98,
      98,    98,     7,     8,    65,    66,   301,   102,    99,   359,
      99,   361,   362,     4,    19,    44,    99,    99,    53,   314,
     336,    53,    27,    28,   374,    30,    31,   377,     4,     5,
     380,    98,    98,   383,    98,    98,    41,    99,    15,    99,
      99,   336,    99,    48,    49,   395,   396,   135,    -1,    -1,
      -1,   401,    -1,    -1,   404,    -1,    -1,    -1,    34,    35,
      -1,    66,    -1,    68,    -1,     0,    -1,    72,     3,    74,
      -1,     6,     7,     8,     9,    -1,     3,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    36,    37,    -1,
      -1,     3,    -1,    89,    90,    -1,    -1,    44,    -1,    -1,
      96,    -1,    98,    88,    89,    90,    91,    92,    93,    -1,
      65,    66,    97,    -1,    -1,   100,    65,    66,    -1,    -1,
      -1,     3,   147,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,   107,   100,    -1,    -1,    -1,    -1,    -1,   106,
     107,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     3,     4,     5,    97,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,   106,   107,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    34,    35,    97,    -1,    -1,   100,    40,
      41,    -1,    43,    -1,    -1,   107,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    68,    69,    70,
      71,    72,    -1,     3,     4,     5,    -1,    -1,    88,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    89,    90,
     100,    -1,    -1,    34,    35,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,   104,    34,    35,   107,    48,    -1,    -1,
      40,    41,    -1,    43,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    56,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    -1,     3,     4,     5,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,    89,
      90,    -1,   103,    -1,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,   104,    34,    35,   107,    -1,    -1,
      -1,    40,    41,    -1,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    -1,    -1,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
      -1,    -1,    28,    -1,   103,    31,    -1,    -1,   107,    -1,
      36,    37,    38,    39,    40,    41,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,     7,     8,     9,    -1,    65,
      66,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    28,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      -1,     3,    -1,    -1,    -1,     7,     8,     9,   104,    65,
      66,   107,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    65,    66,    97,    28,    -1,   100,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      -1,     3,    -1,    -1,    -1,     7,     8,     9,   104,    -1,
      -1,   107,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
       8,     9,   104,    65,    66,   107,    28,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,     3,    -1,    -1,    -1,     7,
       8,     9,   104,    65,    66,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,     3,    -1,    -1,    -1,     7,
       8,     9,   104,    -1,    -1,   107,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    65,    66,   107,
      28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,   104,    65,    66,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    36,    37,    38,
      39,    40,    41,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,   104,    -1,    -1,   107,
      96,    -1,    98,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    40,    41,    -1,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,   107,    68,
      69,    70,    71,    72,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      89,    90,    -1,    97,    34,    35,   100,    96,    -1,    98,
      40,    41,    -1,    43,    -1,   104,     0,    47,    48,    49,
      50,    51,    -1,     7,     8,    -1,    56,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    68,    69,
      70,    71,    72,    27,    -1,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    89,
      90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    53,
      54,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    34,    35,    70,    -1,    -1,    73,
      40,    41,    76,    43,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,   100,    -1,    68,    69,
      70,    71,    72,    -1,    48,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    89,
      90,    -1,    97,    -1,    -1,   100,    96,    -1,    98,    -1,
      -1,    -1,    -1,   103,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    78,    79,    80,
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
      -1,    99,   100,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    99,   100,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    97,    -1,    99,   100,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      99,   100,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    99,   100,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    36,    37,    38,    39,
      40,    41,    65,    66,   107,   109,   110,   113,   118,   119,
     120,   121,   122,   124,   125,   139,     4,    38,   119,   120,
      37,   119,   120,     4,     4,    98,     4,    98,     0,   110,
     113,   119,   124,   125,   139,     6,   121,   122,    37,    38,
     120,   124,   125,    37,    38,   119,   103,   106,   123,   139,
     139,   139,     3,   107,   102,   103,   119,   120,    38,   120,
      38,   119,   119,   120,    37,   120,    37,   119,    98,   102,
       4,   117,   102,   117,   124,   125,   139,   139,     4,   139,
      38,   120,    37,   120,    37,    38,   139,   139,    38,   119,
      37,   119,    37,    38,     4,     5,    34,    35,    43,    47,
      48,    49,    50,    51,    56,    68,    69,    70,    71,    72,
      89,    90,    96,    98,   104,   124,   125,   129,   130,   131,
     134,   135,   136,   137,   138,   139,   131,     4,    28,    31,
     104,   111,   112,   113,   114,   115,   118,   119,   124,   125,
     139,   120,   119,   120,    38,   119,    38,   120,   119,   120,
      37,   119,    37,   116,   117,     4,   126,   127,   102,    99,
     105,   126,    99,   139,   139,   102,   103,   120,    38,   120,
      37,    38,    37,   119,    38,   119,    37,    38,    37,    98,
      97,    98,    48,   123,   131,    98,    98,   139,   139,   131,
     139,   131,   131,   131,   131,   139,   139,   104,   130,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      97,   100,   106,   139,   139,   139,   104,   129,   103,    98,
     123,   104,   112,   113,   114,   115,   139,   139,   124,   125,
      28,    99,    86,   106,   126,   106,     4,   106,   106,     4,
     104,   111,   131,   132,   133,     4,   131,    98,    48,    48,
     131,     4,    98,   139,    99,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,     4,   131,   131,   104,
     104,   111,   116,   139,    98,   102,     4,   127,   128,   131,
     131,   102,   131,   131,   103,   104,    99,   105,    98,    99,
     131,    98,    98,    99,   102,   117,    98,   101,   104,    99,
     116,   126,    87,   105,   126,   104,   111,   131,   132,   123,
     130,   131,   139,    99,   131,   131,   123,   130,   139,   126,
      99,   132,   102,   123,    99,     4,   127,   104,    99,    44,
     139,    44,    44,    44,    99,    99,   139,    53,    53,    99,
      34,    35,   102,   123,   123,   130,   139,   123,   130,   139,
     123,   130,   139,   123,   130,   131,   131,    98,    98,    34,
      35,   139,   139,   139,   139,    99,    99,   132,   132,    98,
      98,   123,   130,   139,   123,   130,   139,    99,    99,   132,
     132,   139,   139,   123,   123,    99,    99,   123,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   123,   123,   124,   124,   124,   125,
     125,   125,   126,   126,   127,   128,   128,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   134,   134,   135,   135,   135,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   139,   139,   139,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     3,     3,     2,
       2,     3,     3,     4,     4,     2,     8,     6,     7,     5,
       7,     5,     6,     4,     1,     1,     2,     1,     1,     2,
       3,     2,     2,     2,     2,     2,     1,     1,     3,     2,
       2,     1,     2,     6,     5,    10,    10,    11,    11,     5,
       4,     9,     9,    10,    10,     0,     1,     3,     5,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     2,
       3,     7,     4,     3,     3,     2,     4,     6,     6,     4,
       6,     6,     1,     1,     4,     1,     1,     3,     3,     1,
       2,     2,     2,     2,     1,     2,     1,     1,     2,     2,
       2,     2,     3,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     4,     3,     6,     3,     0,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     5,     6,     5,
       6,     6,     5,     9,    10,     9,     9,    10,     9,     5,
       5,     6,     7,     7,     7,     7,     8,     8,     8,     8,
       7,     7,     7,     1,     1,     2,     2
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
#line 193 "synt_analyzer.y"
                {root = createProgram(); puts("program created");}
#line 2014 "synt_analyzer.tab.cpp"
    break;

  case 3: /* program: class  */
#line 194 "synt_analyzer.y"
        {root = createProgram((yyvsp[0].classU));puts("program created");}
#line 2020 "synt_analyzer.tab.cpp"
    break;

  case 4: /* program: method  */
#line 195 "synt_analyzer.y"
                {root = createProgram((yyvsp[0].methodU));puts("program created");}
#line 2026 "synt_analyzer.tab.cpp"
    break;

  case 5: /* program: valDeclaration semis  */
#line 196 "synt_analyzer.y"
                        {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2032 "synt_analyzer.tab.cpp"
    break;

  case 6: /* program: varDeclaration semis  */
#line 197 "synt_analyzer.y"
                        {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2038 "synt_analyzer.tab.cpp"
    break;

  case 7: /* program: visibilityModifier valDeclaration semis  */
#line 198 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2044 "synt_analyzer.tab.cpp"
    break;

  case 8: /* program: visibilityModifier varDeclaration semis  */
#line 199 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2050 "synt_analyzer.tab.cpp"
    break;

  case 9: /* program: program class  */
#line 200 "synt_analyzer.y"
                {root = addToProgram(root, (yyvsp[0].classU));puts("class added to prog");}
#line 2056 "synt_analyzer.tab.cpp"
    break;

  case 10: /* program: program method  */
#line 201 "synt_analyzer.y"
                        {root = addToProgram(root, (yyvsp[0].methodU));puts("meth added to prog");}
#line 2062 "synt_analyzer.tab.cpp"
    break;

  case 11: /* program: program valDeclaration semis  */
#line 202 "synt_analyzer.y"
                                {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2068 "synt_analyzer.tab.cpp"
    break;

  case 12: /* program: program varDeclaration semis  */
#line 203 "synt_analyzer.y"
                                {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2074 "synt_analyzer.tab.cpp"
    break;

  case 13: /* program: program visibilityModifier valDeclaration semis  */
#line 204 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2080 "synt_analyzer.tab.cpp"
    break;

  case 14: /* program: program visibilityModifier varDeclaration semis  */
#line 205 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2086 "synt_analyzer.tab.cpp"
    break;

  case 15: /* program: program semis  */
#line 206 "synt_analyzer.y"
                {root = root;}
#line 2092 "synt_analyzer.tab.cpp"
    break;

  case 16: /* class: modifiers CLASS ID ':' ID '{' classBody '}'  */
#line 209 "synt_analyzer.y"
                                                        {(yyval.classU) = createClass((yyvsp[-7].modifiersU), (yyvsp[-5].IdOrString), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU));puts("class created");}
#line 2098 "synt_analyzer.tab.cpp"
    break;

  case 17: /* class: modifiers CLASS ID '{' classBody '}'  */
#line 210 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].modifiersU), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2104 "synt_analyzer.tab.cpp"
    break;

  case 18: /* class: CLASS ID ':' ID '{' classBody '}'  */
#line 211 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].IdOrString), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2110 "synt_analyzer.tab.cpp"
    break;

  case 19: /* class: CLASS ID '{' classBody '}'  */
#line 212 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2116 "synt_analyzer.tab.cpp"
    break;

  case 20: /* class: modifiers CLASS ID ':' ID '{' '}'  */
#line 213 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-6].modifiersU), (yyvsp[-4].IdOrString), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2122 "synt_analyzer.tab.cpp"
    break;

  case 21: /* class: modifiers CLASS ID '{' '}'  */
#line 214 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].modifiersU), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2128 "synt_analyzer.tab.cpp"
    break;

  case 22: /* class: CLASS ID ':' ID '{' '}'  */
#line 215 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].IdOrString), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2134 "synt_analyzer.tab.cpp"
    break;

  case 23: /* class: CLASS ID '{' '}'  */
#line 216 "synt_analyzer.y"
                        {(yyval.classU) = createClass((yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2140 "synt_analyzer.tab.cpp"
    break;

  case 24: /* classBody: semis  */
#line 219 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2146 "synt_analyzer.tab.cpp"
    break;

  case 25: /* classBody: method  */
#line 220 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].methodU));  puts("class body created");}
#line 2152 "synt_analyzer.tab.cpp"
    break;

  case 26: /* classBody: property semis  */
#line 221 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2158 "synt_analyzer.tab.cpp"
    break;

  case 27: /* classBody: constructor  */
#line 222 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].constructorU));  puts("class body created");}
#line 2164 "synt_analyzer.tab.cpp"
    break;

  case 28: /* classBody: initializer  */
#line 223 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].initializerU));  puts("class body created");}
#line 2170 "synt_analyzer.tab.cpp"
    break;

  case 29: /* classBody: classBody method  */
#line 224 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].methodU));  puts("meth added to class body");}
#line 2176 "synt_analyzer.tab.cpp"
    break;

  case 30: /* classBody: classBody property semis  */
#line 225 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2182 "synt_analyzer.tab.cpp"
    break;

  case 31: /* classBody: classBody constructor  */
#line 226 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].constructorU)); puts("constr added to class body");}
#line 2188 "synt_analyzer.tab.cpp"
    break;

  case 32: /* classBody: classBody initializer  */
#line 227 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].initializerU)); puts("init added to class body");}
#line 2194 "synt_analyzer.tab.cpp"
    break;

  case 33: /* classBody: classBody semis  */
#line 228 "synt_analyzer.y"
                        {(yyval.classBodyU) = (yyvsp[-1].classBodyU); puts("semis added to class body");}
#line 2200 "synt_analyzer.tab.cpp"
    break;

  case 34: /* property: modifiers valDeclaration  */
#line 231 "synt_analyzer.y"
                                        {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2206 "synt_analyzer.tab.cpp"
    break;

  case 35: /* property: modifiers varDeclaration  */
#line 232 "synt_analyzer.y"
                                {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2212 "synt_analyzer.tab.cpp"
    break;

  case 36: /* property: valDeclaration  */
#line 233 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2218 "synt_analyzer.tab.cpp"
    break;

  case 37: /* property: varDeclaration  */
#line 234 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2224 "synt_analyzer.tab.cpp"
    break;

  case 38: /* method: modifiers funcDeclaration semis  */
#line 237 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2230 "synt_analyzer.tab.cpp"
    break;

  case 39: /* method: modifiers func  */
#line 238 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].modifiersU), (yyvsp[0].funcU)); puts("meth created");}
#line 2236 "synt_analyzer.tab.cpp"
    break;

  case 40: /* method: funcDeclaration semis  */
#line 239 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2242 "synt_analyzer.tab.cpp"
    break;

  case 41: /* method: func  */
#line 240 "synt_analyzer.y"
        {(yyval.methodU) = createMethod((yyvsp[0].funcU)); puts("meth created");}
#line 2248 "synt_analyzer.tab.cpp"
    break;

  case 42: /* initializer: INIT block  */
#line 243 "synt_analyzer.y"
                        {(yyval.initializerU) = createInit((yyvsp[0].stmtListU)); puts("init created");}
#line 2254 "synt_analyzer.tab.cpp"
    break;

  case 43: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' block  */
#line 247 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-5].visibilityModU), (yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2260 "synt_analyzer.tab.cpp"
    break;

  case 44: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')'  */
#line 248 "synt_analyzer.y"
                                                                {(yyval.constructorU) = createConstructor((yyvsp[-4].visibilityModU), (yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2266 "synt_analyzer.tab.cpp"
    break;

  case 45: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 249 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2272 "synt_analyzer.tab.cpp"
    break;

  case 46: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 250 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2278 "synt_analyzer.tab.cpp"
    break;

  case 47: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 251 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2284 "synt_analyzer.tab.cpp"
    break;

  case 48: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 252 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2290 "synt_analyzer.tab.cpp"
    break;

  case 49: /* constructor: CONSTRUCTOR '(' optFormalParams ')' block  */
#line 253 "synt_analyzer.y"
                                                {(yyval.constructorU) = createConstructor((yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2296 "synt_analyzer.tab.cpp"
    break;

  case 50: /* constructor: CONSTRUCTOR '(' optFormalParams ')'  */
#line 254 "synt_analyzer.y"
                                        {(yyval.constructorU) = createConstructor((yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2302 "synt_analyzer.tab.cpp"
    break;

  case 51: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 255 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2308 "synt_analyzer.tab.cpp"
    break;

  case 52: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 256 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2314 "synt_analyzer.tab.cpp"
    break;

  case 53: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 257 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2320 "synt_analyzer.tab.cpp"
    break;

  case 54: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 258 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2326 "synt_analyzer.tab.cpp"
    break;

  case 55: /* optFormalParams: %empty  */
#line 261 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = 0; puts("opt formal params created");}
#line 2332 "synt_analyzer.tab.cpp"
    break;

  case 56: /* optFormalParams: formalParams  */
#line 262 "synt_analyzer.y"
                {(yyval.formalParamsListU) = (yyvsp[0].formalParamsListU); puts("opt formal params created");}
#line 2338 "synt_analyzer.tab.cpp"
    break;

  case 57: /* formalParams: ID ':' type  */
#line 265 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = createFormalParamsList((yyvsp[-2].IdOrString), (yyvsp[0].typeU)); puts("formal params created");}
#line 2344 "synt_analyzer.tab.cpp"
    break;

  case 58: /* formalParams: formalParams ',' ID ':' type  */
#line 266 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = addToFormalParamsList((yyvsp[-4].formalParamsListU), (yyvsp[-2].IdOrString), (yyvsp[0].typeU)); puts("formal params created");}
#line 2350 "synt_analyzer.tab.cpp"
    break;

  case 59: /* modifiers: OVERRIDE  */
#line 269 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, None); puts("mods created");}
#line 2356 "synt_analyzer.tab.cpp"
    break;

  case 60: /* modifiers: visibilityModifier  */
#line 270 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2362 "synt_analyzer.tab.cpp"
    break;

  case 61: /* modifiers: inheritanceModifier  */
#line 271 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2368 "synt_analyzer.tab.cpp"
    break;

  case 62: /* modifiers: ABSTRACT  */
#line 272 "synt_analyzer.y"
                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, None); puts("mods created");}
#line 2374 "synt_analyzer.tab.cpp"
    break;

  case 63: /* modifiers: OVERRIDE visibilityModifier  */
#line 273 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2380 "synt_analyzer.tab.cpp"
    break;

  case 64: /* modifiers: OVERRIDE inheritanceModifier  */
#line 274 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2386 "synt_analyzer.tab.cpp"
    break;

  case 65: /* modifiers: OVERRIDE ABSTRACT  */
#line 275 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2392 "synt_analyzer.tab.cpp"
    break;

  case 66: /* modifiers: visibilityModifier OVERRIDE  */
#line 276 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2398 "synt_analyzer.tab.cpp"
    break;

  case 67: /* modifiers: visibilityModifier inheritanceModifier  */
#line 277 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2404 "synt_analyzer.tab.cpp"
    break;

  case 68: /* modifiers: visibilityModifier ABSTRACT  */
#line 278 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2410 "synt_analyzer.tab.cpp"
    break;

  case 69: /* modifiers: inheritanceModifier OVERRIDE  */
#line 279 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2416 "synt_analyzer.tab.cpp"
    break;

  case 70: /* modifiers: inheritanceModifier visibilityModifier  */
#line 280 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2422 "synt_analyzer.tab.cpp"
    break;

  case 71: /* modifiers: inheritanceModifier ABSTRACT  */
#line 281 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2428 "synt_analyzer.tab.cpp"
    break;

  case 72: /* modifiers: ABSTRACT OVERRIDE  */
#line 282 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2434 "synt_analyzer.tab.cpp"
    break;

  case 73: /* modifiers: ABSTRACT visibilityModifier  */
#line 283 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2440 "synt_analyzer.tab.cpp"
    break;

  case 74: /* modifiers: ABSTRACT inheritanceModifier  */
#line 284 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2446 "synt_analyzer.tab.cpp"
    break;

  case 75: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier  */
#line 285 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2452 "synt_analyzer.tab.cpp"
    break;

  case 76: /* modifiers: OVERRIDE visibilityModifier ABSTRACT  */
#line 286 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2458 "synt_analyzer.tab.cpp"
    break;

  case 77: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier  */
#line 287 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2464 "synt_analyzer.tab.cpp"
    break;

  case 78: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT  */
#line 288 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2470 "synt_analyzer.tab.cpp"
    break;

  case 79: /* modifiers: OVERRIDE ABSTRACT visibilityModifier  */
#line 289 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2476 "synt_analyzer.tab.cpp"
    break;

  case 80: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier  */
#line 290 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2482 "synt_analyzer.tab.cpp"
    break;

  case 81: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier  */
#line 291 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2488 "synt_analyzer.tab.cpp"
    break;

  case 82: /* modifiers: visibilityModifier OVERRIDE ABSTRACT  */
#line 292 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2494 "synt_analyzer.tab.cpp"
    break;

  case 83: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE  */
#line 293 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2500 "synt_analyzer.tab.cpp"
    break;

  case 84: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT  */
#line 294 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2506 "synt_analyzer.tab.cpp"
    break;

  case 85: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier  */
#line 295 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2512 "synt_analyzer.tab.cpp"
    break;

  case 86: /* modifiers: visibilityModifier ABSTRACT OVERRIDE  */
#line 296 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2518 "synt_analyzer.tab.cpp"
    break;

  case 87: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier  */
#line 297 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2524 "synt_analyzer.tab.cpp"
    break;

  case 88: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT  */
#line 298 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2530 "synt_analyzer.tab.cpp"
    break;

  case 89: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT  */
#line 299 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2536 "synt_analyzer.tab.cpp"
    break;

  case 90: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE  */
#line 300 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2542 "synt_analyzer.tab.cpp"
    break;

  case 91: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier  */
#line 301 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2548 "synt_analyzer.tab.cpp"
    break;

  case 92: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE  */
#line 302 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2554 "synt_analyzer.tab.cpp"
    break;

  case 93: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier  */
#line 303 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2560 "synt_analyzer.tab.cpp"
    break;

  case 94: /* modifiers: ABSTRACT OVERRIDE visibilityModifier  */
#line 304 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2566 "synt_analyzer.tab.cpp"
    break;

  case 95: /* modifiers: ABSTRACT visibilityModifier OVERRIDE  */
#line 305 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2572 "synt_analyzer.tab.cpp"
    break;

  case 96: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier  */
#line 306 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2578 "synt_analyzer.tab.cpp"
    break;

  case 97: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE  */
#line 307 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2584 "synt_analyzer.tab.cpp"
    break;

  case 98: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier  */
#line 308 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2590 "synt_analyzer.tab.cpp"
    break;

  case 99: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier ABSTRACT  */
#line 309 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2596 "synt_analyzer.tab.cpp"
    break;

  case 100: /* modifiers: OVERRIDE visibilityModifier ABSTRACT inheritanceModifier  */
#line 310 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2602 "synt_analyzer.tab.cpp"
    break;

  case 101: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier ABSTRACT  */
#line 311 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2608 "synt_analyzer.tab.cpp"
    break;

  case 102: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT visibilityModifier  */
#line 312 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2614 "synt_analyzer.tab.cpp"
    break;

  case 103: /* modifiers: OVERRIDE ABSTRACT visibilityModifier inheritanceModifier  */
#line 313 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2620 "synt_analyzer.tab.cpp"
    break;

  case 104: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier visibilityModifier  */
#line 314 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2626 "synt_analyzer.tab.cpp"
    break;

  case 105: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier ABSTRACT  */
#line 315 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2632 "synt_analyzer.tab.cpp"
    break;

  case 106: /* modifiers: visibilityModifier OVERRIDE ABSTRACT inheritanceModifier  */
#line 316 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2638 "synt_analyzer.tab.cpp"
    break;

  case 107: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE ABSTRACT  */
#line 317 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2644 "synt_analyzer.tab.cpp"
    break;

  case 108: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT OVERRIDE  */
#line 318 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2650 "synt_analyzer.tab.cpp"
    break;

  case 109: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier OVERRIDE  */
#line 319 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2656 "synt_analyzer.tab.cpp"
    break;

  case 110: /* modifiers: visibilityModifier ABSTRACT OVERRIDE inheritanceModifier  */
#line 320 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2662 "synt_analyzer.tab.cpp"
    break;

  case 111: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier ABSTRACT  */
#line 321 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2668 "synt_analyzer.tab.cpp"
    break;

  case 112: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT visibilityModifier  */
#line 322 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2674 "synt_analyzer.tab.cpp"
    break;

  case 113: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT OVERRIDE  */
#line 324 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2680 "synt_analyzer.tab.cpp"
    break;

  case 114: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE ABSTRACT  */
#line 326 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2686 "synt_analyzer.tab.cpp"
    break;

  case 115: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier OVERRIDE  */
#line 328 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2692 "synt_analyzer.tab.cpp"
    break;

  case 116: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE visibilityModifier  */
#line 330 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2698 "synt_analyzer.tab.cpp"
    break;

  case 117: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier visibilityModifier  */
#line 332 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2704 "synt_analyzer.tab.cpp"
    break;

  case 118: /* modifiers: ABSTRACT OVERRIDE visibilityModifier inheritanceModifier  */
#line 334 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2710 "synt_analyzer.tab.cpp"
    break;

  case 119: /* modifiers: ABSTRACT visibilityModifier OVERRIDE inheritanceModifier  */
#line 335 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2716 "synt_analyzer.tab.cpp"
    break;

  case 120: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier OVERRIDE  */
#line 336 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2722 "synt_analyzer.tab.cpp"
    break;

  case 121: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE visibilityModifier  */
#line 338 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2728 "synt_analyzer.tab.cpp"
    break;

  case 122: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier OVERRIDE  */
#line 340 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2734 "synt_analyzer.tab.cpp"
    break;

  case 123: /* visibilityModifier: PUBLIC  */
#line 343 "synt_analyzer.y"
                                {(yyval.visibilityModU) = Public;}
#line 2740 "synt_analyzer.tab.cpp"
    break;

  case 124: /* visibilityModifier: PRIVATE  */
#line 344 "synt_analyzer.y"
                {(yyval.visibilityModU) = Private;}
#line 2746 "synt_analyzer.tab.cpp"
    break;

  case 125: /* visibilityModifier: INTERNAL  */
#line 345 "synt_analyzer.y"
                {(yyval.visibilityModU) = Internal;}
#line 2752 "synt_analyzer.tab.cpp"
    break;

  case 126: /* visibilityModifier: PROTECTED  */
#line 346 "synt_analyzer.y"
                {(yyval.visibilityModU) = Protected;}
#line 2758 "synt_analyzer.tab.cpp"
    break;

  case 127: /* inheritanceModifier: FINAL  */
#line 350 "synt_analyzer.y"
                           {(yyval.inheritanceModU) = Final;}
#line 2764 "synt_analyzer.tab.cpp"
    break;

  case 128: /* inheritanceModifier: OPEN  */
#line 351 "synt_analyzer.y"
       {(yyval.inheritanceModU) = Open;}
#line 2770 "synt_analyzer.tab.cpp"
    break;

  case 129: /* func: funcDeclaration block  */
#line 354 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-1].funcDeclU), (yyvsp[0].stmtListU)); puts("func created");}
#line 2776 "synt_analyzer.tab.cpp"
    break;

  case 130: /* func: funcDeclaration '=' expr  */
#line 355 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-2].funcDeclU), (yyvsp[0].exprU)); puts("func created");}
#line 2782 "synt_analyzer.tab.cpp"
    break;

  case 131: /* funcDeclaration: FUN ID '(' optFormalParams ')' ':' type  */
#line 359 "synt_analyzer.y"
                                                                {(yyval.funcDeclU) = createFuncDecl((yyvsp[-5].IdOrString), (yyvsp[-3].formalParamsListU), (yyvsp[0].typeU));  puts("func decl created");}
#line 2788 "synt_analyzer.tab.cpp"
    break;

  case 132: /* block: '{' semis stmts '}'  */
#line 363 "synt_analyzer.y"
                                {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2794 "synt_analyzer.tab.cpp"
    break;

  case 133: /* block: '{' semis '}'  */
#line 364 "synt_analyzer.y"
                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2800 "synt_analyzer.tab.cpp"
    break;

  case 134: /* block: '{' stmts '}'  */
#line 365 "synt_analyzer.y"
                {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2806 "synt_analyzer.tab.cpp"
    break;

  case 135: /* block: '{' '}'  */
#line 366 "synt_analyzer.y"
                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2812 "synt_analyzer.tab.cpp"
    break;

  case 136: /* varDeclaration: VAR ID ':' type  */
#line 370 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].IdOrString), (yyvsp[0].typeU), 0); puts("var created");}
#line 2818 "synt_analyzer.tab.cpp"
    break;

  case 137: /* varDeclaration: VAR ID ':' type '=' expr  */
#line 371 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].IdOrString), (yyvsp[-2].typeU), (yyvsp[0].exprU), 0); puts("var created");}
#line 2824 "synt_analyzer.tab.cpp"
    break;

  case 138: /* varDeclaration: VAR '(' formalParams ')' '=' expr  */
#line 372 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 0); puts("var created"); }
#line 2830 "synt_analyzer.tab.cpp"
    break;

  case 139: /* valDeclaration: VAL ID ':' type  */
#line 376 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].IdOrString), (yyvsp[0].typeU), 1); puts("val created"); }
#line 2836 "synt_analyzer.tab.cpp"
    break;

  case 140: /* valDeclaration: VAL ID ':' type '=' expr  */
#line 377 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].IdOrString), (yyvsp[-2].typeU), (yyvsp[0].exprU), 1); puts("val created"); }
#line 2842 "synt_analyzer.tab.cpp"
    break;

  case 141: /* valDeclaration: VAL '(' formalParams ')' '=' expr  */
#line 378 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 1); puts("val created"); }
#line 2848 "synt_analyzer.tab.cpp"
    break;

  case 142: /* type: ID  */
#line 381 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].IdOrString)); puts("type created"); }
#line 2854 "synt_analyzer.tab.cpp"
    break;

  case 143: /* type: templateType  */
#line 382 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].templateTypeU)); puts("type created"); }
#line 2860 "synt_analyzer.tab.cpp"
    break;

  case 144: /* templateType: ID '<' type_seq '>'  */
#line 385 "synt_analyzer.y"
                                        {(yyval.templateTypeU) = createTemplateType((yyvsp[-3].IdOrString), (yyvsp[-1].typesListU)); puts("template type created"); }
#line 2866 "synt_analyzer.tab.cpp"
    break;

  case 145: /* type_seq: ID  */
#line 388 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].IdOrString)); puts("type seq created"); }
#line 2872 "synt_analyzer.tab.cpp"
    break;

  case 146: /* type_seq: templateType  */
#line 389 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].templateTypeU)); puts("type seq created"); }
#line 2878 "synt_analyzer.tab.cpp"
    break;

  case 147: /* type_seq: type_seq ',' ID  */
#line 390 "synt_analyzer.y"
                        {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].IdOrString));  puts("type seq created"); }
#line 2884 "synt_analyzer.tab.cpp"
    break;

  case 148: /* type_seq: type_seq ',' templateType  */
#line 391 "synt_analyzer.y"
                                {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].templateTypeU));  puts("type seq created"); }
#line 2890 "synt_analyzer.tab.cpp"
    break;

  case 149: /* stmts: stmt  */
#line 394 "synt_analyzer.y"
                {(yyval.stmtListU) = createStmtList((yyvsp[0].stmtU));  puts("stmts created"); }
#line 2896 "synt_analyzer.tab.cpp"
    break;

  case 150: /* stmts: stmts stmt  */
#line 395 "synt_analyzer.y"
                {(yyval.stmtListU) = addToStmtList((yyvsp[-1].stmtListU), (yyvsp[0].stmtU));  puts("stmts created"); }
#line 2902 "synt_analyzer.tab.cpp"
    break;

  case 151: /* stmt: valDeclaration semis  */
#line 398 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 2908 "synt_analyzer.tab.cpp"
    break;

  case 152: /* stmt: varDeclaration semis  */
#line 399 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 2914 "synt_analyzer.tab.cpp"
    break;

  case 153: /* stmt: assignment semis  */
#line 400 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 2920 "synt_analyzer.tab.cpp"
    break;

  case 154: /* stmt: whileLoop  */
#line 401 "synt_analyzer.y"
            {(yyval.stmtU) = createStmt((yyvsp[0].whileLoopU), WhileLoop);  puts("stmt created"); }
#line 2926 "synt_analyzer.tab.cpp"
    break;

  case 155: /* stmt: doWhileLoop semis  */
#line 402 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 2932 "synt_analyzer.tab.cpp"
    break;

  case 156: /* stmt: forLoop  */
#line 403 "synt_analyzer.y"
          {(yyval.stmtU) = createStmt((yyvsp[0].forLoopU), ForLoop);  puts("stmt created"); }
#line 2938 "synt_analyzer.tab.cpp"
    break;

  case 157: /* stmt: ifStmt  */
#line 404 "synt_analyzer.y"
         {(yyval.stmtU) = createStmt((yyvsp[0].ifStmtU), IfStmt);  puts("stmt created"); }
#line 2944 "synt_analyzer.tab.cpp"
    break;

  case 158: /* stmt: expr semis  */
#line 405 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 2950 "synt_analyzer.tab.cpp"
    break;

  case 159: /* stmt: BREAK semis  */
#line 406 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 2956 "synt_analyzer.tab.cpp"
    break;

  case 160: /* stmt: CONTINUE semis  */
#line 407 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 2962 "synt_analyzer.tab.cpp"
    break;

  case 161: /* stmt: RETURN semis  */
#line 408 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 2968 "synt_analyzer.tab.cpp"
    break;

  case 162: /* stmt: RETURN expr semis  */
#line 409 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 2974 "synt_analyzer.tab.cpp"
    break;

  case 163: /* expr: STR  */
#line 412 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].IdOrString), String);  puts("expr created"); }
#line 2980 "synt_analyzer.tab.cpp"
    break;

  case 164: /* expr: ID  */
#line 413 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].IdOrString), Identificator);  puts("expr created"); }
#line 2986 "synt_analyzer.tab.cpp"
    break;

  case 165: /* expr: THIS  */
#line 414 "synt_analyzer.y"
        {(yyval.exprU) = createExpr(0, This);  puts("expr created"); }
#line 2992 "synt_analyzer.tab.cpp"
    break;

  case 166: /* expr: ID '(' optFactParams ')'  */
#line 415 "synt_analyzer.y"
                                {(yyval.exprU) = createExpr((yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), MethodCall);  puts("expr created"); }
#line 2998 "synt_analyzer.tab.cpp"
    break;

  case 167: /* expr: INT  */
#line 416 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Int_v), Int);  puts("expr created"); }
#line 3004 "synt_analyzer.tab.cpp"
    break;

  case 168: /* expr: FLOAT  */
#line 417 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Float_v), Float);  puts("expr created"); }
#line 3010 "synt_analyzer.tab.cpp"
    break;

  case 169: /* expr: CHR  */
#line 418 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Char_v), Char);  puts("expr created"); }
#line 3016 "synt_analyzer.tab.cpp"
    break;

  case 170: /* expr: DOUBLE  */
#line 419 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Double_v), Double);  puts("expr created"); }
#line 3022 "synt_analyzer.tab.cpp"
    break;

  case 171: /* expr: BOOLEAN  */
#line 420 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Bool_v), Boolean);  puts("expr created"); }
#line 3028 "synt_analyzer.tab.cpp"
    break;

  case 172: /* expr: '(' expr ')'  */
#line 421 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-1].exprU), ExprInBrackets);  puts("expr created"); }
#line 3034 "synt_analyzer.tab.cpp"
    break;

  case 173: /* expr: '!' expr  */
#line 422 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].exprU), LogicalNot);}
#line 3040 "synt_analyzer.tab.cpp"
    break;

  case 174: /* expr: '+' expr  */
#line 423 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryPlusExpr);  puts("expr created"); }
#line 3046 "synt_analyzer.tab.cpp"
    break;

  case 175: /* expr: '-' expr  */
#line 424 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryMinusExpr);  puts("expr created"); }
#line 3052 "synt_analyzer.tab.cpp"
    break;

  case 176: /* expr: expr '+' expr  */
#line 425 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sum);  puts("expr created"); }
#line 3058 "synt_analyzer.tab.cpp"
    break;

  case 177: /* expr: expr '-' expr  */
#line 426 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sub);  puts("expr created"); }
#line 3064 "synt_analyzer.tab.cpp"
    break;

  case 178: /* expr: expr '*' expr  */
#line 427 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mul);  puts("expr created"); }
#line 3070 "synt_analyzer.tab.cpp"
    break;

  case 179: /* expr: expr '/' expr  */
#line 428 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Div);  puts("expr created"); }
#line 3076 "synt_analyzer.tab.cpp"
    break;

  case 180: /* expr: expr '%' expr  */
#line 429 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mod);  puts("expr created"); }
#line 3082 "synt_analyzer.tab.cpp"
    break;

  case 181: /* expr: expr '<' expr  */
#line 430 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Less);  puts("expr created"); }
#line 3088 "synt_analyzer.tab.cpp"
    break;

  case 182: /* expr: expr '>' expr  */
#line 431 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), More);  puts("expr created"); }
#line 3094 "synt_analyzer.tab.cpp"
    break;

  case 183: /* expr: expr OR expr  */
#line 432 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Or);  puts("expr created"); }
#line 3100 "synt_analyzer.tab.cpp"
    break;

  case 184: /* expr: expr AND expr  */
#line 433 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), And);  puts("expr created"); }
#line 3106 "synt_analyzer.tab.cpp"
    break;

  case 185: /* expr: expr EQ expr  */
#line 434 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Eq);  puts("expr created"); }
#line 3112 "synt_analyzer.tab.cpp"
    break;

  case 186: /* expr: expr AEQ expr  */
#line 435 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Aeq);}
#line 3118 "synt_analyzer.tab.cpp"
    break;

  case 187: /* expr: expr NEQ expr  */
#line 436 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Neq);  puts("expr created"); }
#line 3124 "synt_analyzer.tab.cpp"
    break;

  case 188: /* expr: expr NAEQ expr  */
#line 437 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Naeq);  puts("expr created"); }
#line 3130 "synt_analyzer.tab.cpp"
    break;

  case 189: /* expr: expr LOEQ expr  */
#line 438 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Loeq);  puts("expr created"); }
#line 3136 "synt_analyzer.tab.cpp"
    break;

  case 190: /* expr: expr MOEQ expr  */
#line 439 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Moeq);  puts("expr created"); }
#line 3142 "synt_analyzer.tab.cpp"
    break;

  case 191: /* expr: expr '.' ID  */
#line 440 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].IdOrString), FieldCalcExpr);  puts("expr created"); }
#line 3148 "synt_analyzer.tab.cpp"
    break;

  case 192: /* expr: expr '.' ID '(' optFactParams ')'  */
#line 441 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr((yyvsp[-5].exprU), (yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), MethodCalcExpr);  puts("expr created"); }
#line 3154 "synt_analyzer.tab.cpp"
    break;

  case 193: /* expr: expr '[' expr ']'  */
#line 442 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-3].exprU), (yyvsp[-1].exprU), ArrayElementCall);  puts("expr created"); }
#line 3160 "synt_analyzer.tab.cpp"
    break;

  case 194: /* expr: SUPER '.' ID  */
#line 443 "synt_analyzer.y"
                {(yyval.exprU) = createExpr(0, (yyvsp[0].IdOrString), ParentFieldCall);  puts("expr created"); }
#line 3166 "synt_analyzer.tab.cpp"
    break;

  case 195: /* expr: SUPER '.' ID '(' optFactParams ')'  */
#line 444 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr(0, (yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), ParentMethodCall);  puts("expr created"); }
#line 3172 "synt_analyzer.tab.cpp"
    break;

  case 196: /* expr: expr RANGE expr  */
#line 445 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Range);  puts("expr created"); }
#line 3178 "synt_analyzer.tab.cpp"
    break;

  case 197: /* optFactParams: %empty  */
#line 448 "synt_analyzer.y"
                                {(yyval.factParamsListU) = 0;   puts("opt fact params created"); }
#line 3184 "synt_analyzer.tab.cpp"
    break;

  case 198: /* optFactParams: factParams  */
#line 449 "synt_analyzer.y"
                {(yyval.factParamsListU) = (yyvsp[0].factParamsListU);   puts("opt fact params created"); }
#line 3190 "synt_analyzer.tab.cpp"
    break;

  case 199: /* factParams: expr  */
#line 452 "synt_analyzer.y"
                        {(yyval.factParamsListU) = createFactParamsList((yyvsp[0].exprU));   puts("fact params created"); }
#line 3196 "synt_analyzer.tab.cpp"
    break;

  case 200: /* factParams: factParams ',' expr  */
#line 453 "synt_analyzer.y"
                        {(yyval.factParamsListU) = addToFactParamsList((yyvsp[-2].factParamsListU), (yyvsp[0].exprU));   puts("fact params created"); }
#line 3202 "synt_analyzer.tab.cpp"
    break;

  case 201: /* assignment: expr '=' expr  */
#line 456 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Assign); puts("assignment created"); }
#line 3208 "synt_analyzer.tab.cpp"
    break;

  case 202: /* assignment: expr ASUM expr  */
#line 457 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asum); puts("assignment created"); }
#line 3214 "synt_analyzer.tab.cpp"
    break;

  case 203: /* assignment: expr ASUB expr  */
#line 458 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asub); puts("assignment created"); }
#line 3220 "synt_analyzer.tab.cpp"
    break;

  case 204: /* assignment: expr ADIV expr  */
#line 459 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Adiv); puts("assignment created"); }
#line 3226 "synt_analyzer.tab.cpp"
    break;

  case 205: /* assignment: expr AMUL expr  */
#line 460 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amul); puts("assignment created"); }
#line 3232 "synt_analyzer.tab.cpp"
    break;

  case 206: /* assignment: expr AMOD expr  */
#line 461 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amod); puts("assignment created"); }
#line 3238 "synt_analyzer.tab.cpp"
    break;

  case 207: /* whileLoop: WHILE '(' expr ')' stmt  */
#line 464 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[0].stmtU), 0); puts("whileLoop created"); }
#line 3244 "synt_analyzer.tab.cpp"
    break;

  case 208: /* whileLoop: WHILE '(' expr ')' block semis  */
#line 465 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), (yyvsp[-1].stmtListU), 0); puts("whileLoop created"); }
#line 3250 "synt_analyzer.tab.cpp"
    break;

  case 209: /* whileLoop: WHILE '(' expr ')' semis  */
#line 466 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 0); puts("whileLoop created"); }
#line 3256 "synt_analyzer.tab.cpp"
    break;

  case 210: /* doWhileLoop: DO expr WHILE '(' expr ')'  */
#line 469 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].exprU), 1); puts("doWhileLoop created"); }
#line 3262 "synt_analyzer.tab.cpp"
    break;

  case 211: /* doWhileLoop: DO block WHILE '(' expr ')'  */
#line 470 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].stmtListU), 1); puts("doWhileLoop created"); }
#line 3268 "synt_analyzer.tab.cpp"
    break;

  case 212: /* doWhileLoop: DO WHILE '(' expr ')'  */
#line 471 "synt_analyzer.y"
                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), 1); puts("doWhileLoop created"); }
#line 3274 "synt_analyzer.tab.cpp"
    break;

  case 213: /* forLoop: FOR '(' ID ':' type IN expr ')' stmt  */
#line 474 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].IdOrString), (yyvsp[-4].typeU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3280 "synt_analyzer.tab.cpp"
    break;

  case 214: /* forLoop: FOR '(' ID ':' type IN expr ')' block semis  */
#line 475 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-7].IdOrString), (yyvsp[-5].typeU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3286 "synt_analyzer.tab.cpp"
    break;

  case 215: /* forLoop: FOR '(' ID ':' type IN expr ')' semis  */
#line 476 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].IdOrString), (yyvsp[-4].typeU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3292 "synt_analyzer.tab.cpp"
    break;

  case 216: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' stmt  */
#line 477 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3298 "synt_analyzer.tab.cpp"
    break;

  case 217: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block semis  */
#line 478 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].formalParamsListU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3304 "synt_analyzer.tab.cpp"
    break;

  case 218: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' semis  */
#line 479 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3310 "synt_analyzer.tab.cpp"
    break;

  case 219: /* ifStmt: IF '(' expr ')' stmt  */
#line 482 "synt_analyzer.y"
                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3316 "synt_analyzer.tab.cpp"
    break;

  case 220: /* ifStmt: IF '(' expr ')' semis  */
#line 483 "synt_analyzer.y"
                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3322 "synt_analyzer.tab.cpp"
    break;

  case 221: /* ifStmt: IF '(' expr ')' block semis  */
#line 484 "synt_analyzer.y"
                              {(yyval.ifStmtU) = createIfStmt((yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3328 "synt_analyzer.tab.cpp"
    break;

  case 222: /* ifStmt: IF '(' expr ')' expr ELSE stmt  */
#line 485 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3334 "synt_analyzer.tab.cpp"
    break;

  case 223: /* ifStmt: IF '(' expr ')' stmt ELSE stmt  */
#line 486 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3340 "synt_analyzer.tab.cpp"
    break;

  case 224: /* ifStmt: IF '(' expr ')' block ELSE stmt  */
#line 487 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3346 "synt_analyzer.tab.cpp"
    break;

  case 225: /* ifStmt: IF '(' expr ')' semis ELSE stmt  */
#line 488 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3352 "synt_analyzer.tab.cpp"
    break;

  case 226: /* ifStmt: IF '(' expr ')' expr ELSE block semis  */
#line 489 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3358 "synt_analyzer.tab.cpp"
    break;

  case 227: /* ifStmt: IF '(' expr ')' stmt ELSE block semis  */
#line 490 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3364 "synt_analyzer.tab.cpp"
    break;

  case 228: /* ifStmt: IF '(' expr ')' block ELSE block semis  */
#line 491 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtListU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3370 "synt_analyzer.tab.cpp"
    break;

  case 229: /* ifStmt: IF '(' expr ')' semis ELSE block semis  */
#line 492 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3376 "synt_analyzer.tab.cpp"
    break;

  case 230: /* ifStmt: IF '(' expr ')' expr ELSE semis  */
#line 493 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3382 "synt_analyzer.tab.cpp"
    break;

  case 231: /* ifStmt: IF '(' expr ')' stmt ELSE semis  */
#line 494 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU)); puts("ifStmt created"); }
#line 3388 "synt_analyzer.tab.cpp"
    break;

  case 232: /* ifStmt: IF '(' expr ')' block ELSE semis  */
#line 495 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU)); puts("ifStmt created"); }
#line 3394 "synt_analyzer.tab.cpp"
    break;

  case 233: /* semis: ';'  */
#line 499 "synt_analyzer.y"
                { puts("semis created"); }
#line 3400 "synt_analyzer.tab.cpp"
    break;

  case 234: /* semis: NEW_LINE  */
#line 500 "synt_analyzer.y"
                { puts("semis created"); }
#line 3406 "synt_analyzer.tab.cpp"
    break;

  case 235: /* semis: semis ';'  */
#line 501 "synt_analyzer.y"
                { puts("semis created"); }
#line 3412 "synt_analyzer.tab.cpp"
    break;

  case 236: /* semis: semis NEW_LINE  */
#line 502 "synt_analyzer.y"
                        { puts("semis created"); }
#line 3418 "synt_analyzer.tab.cpp"
    break;


#line 3422 "synt_analyzer.tab.cpp"

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

#line 506 "synt_analyzer.y"

//Секция пользовательского кода



void main(int argc, char **argv ){
	//yyin = fopen(argv[1], "r");
	yyin = fopen("types.txt", "r");
	FILE * file = fopen("tree.dot", "w");
	root = 0;
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);

    return;
}

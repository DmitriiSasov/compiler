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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1876

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  282
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  472

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
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   219,   220,   221,   222,
     223,   224,   225,   226,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   245,   246,
     247,   248,   251,   252,   253,   254,   255,   256,   259,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   277,   278,   281,   282,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     341,   343,   345,   347,   349,   351,   352,   353,   355,   359,
     360,   361,   362,   366,   367,   370,   371,   375,   379,   380,
     381,   382,   383,   384,   388,   389,   390,   394,   395,   396,
     399,   400,   403,   406,   407,   408,   409,   412,   413,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   476,   477,   480,   481,   484,   485,
     486,   487,   488,   489,   492,   493,   494,   495,   496,   499,
     500,   501,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   542,   543,   546,   547,
     550,   551,   552
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
      91,    93,    58,   123,   125,    44,    61,    59
};
#endif

#define YYPACT_NINF (-321)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-278)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     660,  -321,    46,  -321,  -321,  -321,  -321,    31,   348,    64,
      15,    28,  -321,  -321,  -321,   734,  -321,  -321,    23,   212,
     152,  -321,     8,    14,    14,    42,    24,   -43,   173,     9,
     189,   173,    33,    56,   -46,   -30,    96,     2,    96,  -321,
    -321,  -321,   212,    14,    14,    42,    24,   113,  -321,     8,
      40,   118,   106,    14,    14,   292,   166,   133,   996,  -321,
       7,     5,    24,    42,    24,    42,    24,  -321,  -321,    42,
     135,  1136,   154,   297,   154,   103,   297,   115,   154,   297,
     154,   120,   297,   126,    96,   183,    89,     4,   183,    59,
      14,    14,    42,    24,    42,    24,   138,     5,    24,   154,
     157,   154,   169,   170,   174,    42,    24,    42,    24,   297,
     185,   297,   191,   188,   195,   136,  -321,  -321,   159,  -321,
    -321,  -321,  -321,  -321,   996,   996,   996,   996,  1434,   865,
     148,   162,   183,  -321,  1150,    14,  -321,  -321,  -321,   283,
     139,  -321,  -321,    42,    24,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,   137,   176,   168,
     279,    42,   183,   178,   286,   181,   201,    42,    24,    42,
      24,   298,  1190,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,   996,   305,   -14,   -14,   -14,
     804,   996,   996,   996,   996,   996,   996,   996,   996,   996,
     996,   996,   996,   996,   996,   996,   996,   307,   996,   214,
     925,   218,   219,    14,    14,   196,  -321,    14,    14,  1439,
    -321,   774,    14,  -321,    14,  -321,  -321,  1367,   936,  1230,
      96,  -321,  -321,    14,  -321,  -321,  -321,    42,    24,    42,
      24,  -321,  -321,   227,   225,   996,    30,   183,  -321,   996,
     229,   996,   996,   231,  -321,  1244,  1434,   233,   236,   238,
    -321,  1493,   411,   484,   484,   484,   484,   343,   343,   343,
     343,   431,   246,   246,   -14,   -14,   -14,   242,  1637,   996,
     244,   296,   704,   996,    38,    42,    24,    42,    24,  1041,
      42,    24,    42,    24,    42,    24,  -321,  -321,   996,   996,
     996,   996,   996,   996,    42,    24,    42,    24,    42,    24,
    -321,  1498,  -321,  1557,  -321,  1284,   254,    42,    24,    96,
     183,  1434,   354,  -321,  -321,  1434,   183,  1434,  1434,  1324,
    -321,  -321,   996,   996,   996,  -321,  1611,   996,   261,   262,
    1661,   259,    96,    42,    24,  1434,  1434,  1434,  1434,  1434,
    1434,  -321,  -321,  -321,    25,   264,  -321,   278,  -321,   -50,
    -321,  -321,  1338,  1434,   268,   270,  1007,  1684,   996,   996,
    1007,   183,    80,   210,  -321,    48,  -321,   368,  -321,  -321,
    -321,    13,   330,   732,    43,    17,  -321,  1707,  1730,    14,
    -321,     5,    24,   323,   324,   282,   284,   235,  -321,   278,
    -321,  1007,    42,    24,  1007,  1007,  1616,  1616,  -321,  -321,
      42,    24,   996,   996,   996,   996,   288,   289,    14,  -321,
       5,    24,    14,  -321,     5,    24,    14,  -321,     5,    24,
     183,  -321,   281,  -321,  1753,  1776,   291,   299,   996,   996,
      42,    24,    42,    24,    42,    24,    42,    24,  1007,  1007,
      27,    27,   300,   303,    14,  -321,     5,    24,    14,  -321,
       5,    24,  -321,  -321,    27,    27,    42,    24,    42,    24,
    -321,  -321
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   278,     0,   139,   140,   142,   141,    75,    78,     0,
       0,     0,   144,   143,   280,     0,     4,     5,     0,    76,
      77,    57,   276,     0,     0,     3,     2,     0,    81,    79,
      80,    88,    89,    90,     0,     0,     0,     0,     0,     1,
      14,    15,    76,     0,     0,    25,    24,     0,    54,   276,
      82,    84,    83,     0,     0,    85,    87,    86,     0,   145,
       0,    56,    55,    11,     7,    10,     6,   279,   281,   282,
       0,     0,    95,    96,    92,    91,    94,    93,   110,   109,
     111,   112,   113,   114,    71,   276,     0,     0,   276,     0,
       0,     0,    21,    17,    20,    16,     0,    53,    52,    98,
      97,   102,   101,    99,   100,    13,     9,    12,     8,   104,
     103,   108,   107,   106,   105,   191,   190,   192,     0,   194,
     195,   197,   196,   198,     0,     0,     0,     0,   146,     0,
       0,     0,   276,    33,     0,     0,    36,    40,    39,     0,
      76,    51,    50,    35,    34,   119,   120,   116,   115,   118,
     117,   134,   133,   135,   136,   137,   138,     0,    72,   154,
       0,   277,   276,     0,     0,   157,     0,    23,    19,    22,
      18,     0,     0,   122,   121,   126,   125,   123,   124,   128,
     127,   132,   131,   130,   129,   224,     0,   201,   202,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,     0,     0,   153,     0,     0,     0,
     167,     0,     0,   172,     0,   174,   175,     0,     0,     0,
      71,    58,    29,     0,    41,    45,    44,    47,    46,    38,
      37,    49,    48,     0,     0,     0,   276,   276,    73,     0,
       0,     0,     0,     0,    31,     0,   226,     0,   225,   221,
     199,   210,   211,   212,   213,   214,   215,   216,   217,   208,
     209,   223,   203,   204,   206,   205,   207,   218,     0,     0,
       0,     0,     0,     0,     0,   186,   177,   187,   178,     0,
     188,   179,   182,   170,   181,   169,   150,   168,     0,     0,
       0,     0,     0,     0,   185,   176,   183,   171,   184,   173,
     152,     0,   149,     0,    32,     0,     0,    43,    42,    71,
     276,   155,     0,   160,   161,   156,   276,   158,   159,     0,
      27,   193,     0,   224,   224,   220,     0,     0,     0,     0,
       0,     0,     0,   189,   180,   229,   230,   231,   232,   233,
     228,   151,   148,    28,    66,     0,   147,   163,   164,     0,
      74,    30,     0,   227,     0,     0,   276,     0,     0,     0,
     276,   276,     0,     0,    65,    60,   162,     0,    26,   222,
     219,     0,   252,     0,   266,   253,   241,     0,     0,     0,
     234,   238,   236,     0,     0,     0,     0,     0,    59,   165,
     166,   276,   267,   254,   276,   276,   276,   276,   240,   239,
     237,   235,     0,     0,   224,   224,     0,     0,     0,   257,
     275,   265,     0,   256,   274,   264,     0,   255,   273,   263,
       0,   268,     0,   258,     0,     0,     0,     0,   224,   224,
     271,   261,   270,   260,   269,   259,   272,   262,   276,   276,
      68,    67,     0,     0,     0,   242,   249,   244,     0,   245,
     251,   247,    70,    69,    62,    61,   248,   243,   250,   246,
      64,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -321,  -321,   376,  -163,  -108,     3,  -103,   -99,  -194,   -34,
      41,   657,   582,   -17,    -6,   -56,     6,   123,   -83,  -288,
    -321,    69,   160,   342,  -320,  -321,  -321,  -321,  -321,  -321,
    -321,   -78,     0,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,   134,   135,   136,   137,   138,   157,   158,
     139,   140,    20,    21,    22,    59,   217,   218,   159,   247,
     359,   219,   220,   221,   257,   258,   222,   223,   224,   225,
     226,    60,    69,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    48,    87,    17,    89,   165,    23,   160,    67,   255,
     160,     1,    49,   364,   365,    45,     1,     1,    41,    35,
       1,    43,    61,    63,    65,    53,   233,     1,     1,    47,
       1,   235,    37,     1,   358,   236,   316,   376,     3,     4,
       5,    18,   341,    92,    94,    67,    67,    74,    90,    97,
      27,     1,    84,   105,   107,   377,    18,   401,    26,    70,
      71,   407,     9,     3,     4,     5,   315,     6,    34,    28,
      80,   143,    85,    46,    12,    13,   231,   141,    99,   248,
      62,    64,    66,   207,   160,   161,   208,   406,   161,   400,
     167,   169,     6,    82,   436,   437,    12,    13,    12,    13,
      86,    93,    95,   163,    88,    12,    13,    98,  -277,   164,
     129,   106,   108,    36,    58,    14,   322,    96,   452,   453,
      14,    14,    48,    24,    68,   355,    38,   373,  -276,   227,
    -276,    68,   161,    49,   237,   239,   342,   234,    44,   130,
     141,   148,    54,   103,   104,   241,  -277,   233,   168,   170,
     397,  -276,   235,   150,   281,   101,   236,   154,   166,     3,
       4,     5,   161,   156,   164,    91,   362,   243,   323,   324,
     113,   114,   143,     3,     4,     5,    50,    51,   141,   394,
       3,     4,     5,    12,    13,   164,     1,   228,     6,    55,
      56,   162,   238,   240,   142,   174,     3,     4,     5,     1,
     115,   116,     6,   111,    12,    13,   176,   233,   177,     6,
     161,   178,   235,   285,   287,   290,   236,   292,   294,    12,
      13,   304,   306,   180,   308,     6,   183,    76,   182,   143,
     117,   118,   184,   317,   185,   141,   244,   356,    12,    13,
     171,   172,   160,   360,   395,   396,   161,   161,   160,    50,
      51,   229,    10,    11,   233,   237,   186,   142,   234,   235,
     230,   141,   242,   236,   119,   120,   121,   122,   123,   416,
     417,   286,   288,   291,   245,   293,   295,    12,    13,   305,
     307,   164,   309,   246,   249,   124,   125,   251,   393,   343,
     250,   318,   126,   160,   127,   142,   311,   313,   374,     3,
       4,     5,   253,    14,     3,     4,     5,   252,   372,   259,
     381,   277,   279,   238,   389,   237,   283,   284,   234,   398,
     161,   141,     9,    10,    11,   319,   161,   320,     6,   143,
     109,   326,   331,     6,   329,   141,   333,   204,   205,   206,
     334,   332,   337,   207,   338,   418,   208,   344,   422,   426,
     430,   432,   142,   354,   161,     3,     4,     5,   357,   368,
     369,   371,   237,   375,   322,   234,   384,   379,   141,   380,
     391,   161,   399,   238,   404,   161,   412,   413,   142,   297,
     414,   402,   415,   304,     6,    31,   438,   439,    14,   410,
     450,    40,   454,   458,   462,   463,     0,     0,   451,   464,
     128,   420,   465,     0,   424,   428,   161,   161,   470,   471,
       0,     0,     0,    12,    13,     0,     0,     0,   440,     0,
     238,     0,   442,     0,   385,     0,   444,     0,   392,     0,
     446,   201,   202,   203,   204,   205,   206,     0,   142,   403,
     207,   305,     0,   208,     0,     0,     0,   411,   456,   460,
     161,   161,   142,     0,   466,     0,     0,     0,   468,   421,
       0,     0,   425,   429,   161,   161,   187,   188,   189,   190,
       0,   297,     0,   297,     0,     0,   441,     0,     0,     0,
     443,     0,     0,     0,   445,   142,     0,     0,     0,     0,
     447,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   457,   461,   207,     0,
       0,   208,   467,     0,     0,     0,   469,     0,     0,  -278,
     202,   203,   204,   205,   206,     0,   382,   256,   207,     0,
     390,   208,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,     0,
     278,     0,   282,     0,     0,     0,     0,   289,     0,     0,
       0,   419,     0,     0,   423,   427,   431,   433,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,     0,
       0,   207,     0,     0,   208,     0,     0,   321,     0,    30,
      33,   325,     0,   327,   328,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,   455,   459,
      73,    75,     0,    79,    81,     0,     0,     0,     0,     0,
       0,   336,     0,     0,    52,   340,     0,     0,     0,     0,
       0,     0,   100,   102,     0,     0,     0,     0,     0,     0,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,   147,    19,     0,     0,
     151,     0,   153,     1,    29,    32,     2,     3,     4,     5,
       0,     0,    42,     0,   363,   256,   256,    57,     0,   367,
       0,   173,     0,   175,     0,    72,     0,    77,    78,     0,
      83,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,     0,     0,   383,     0,
     387,   388,   110,   112,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,    12,    13,     0,     0,     0,
     146,     0,     0,   149,    39,     1,   152,     1,     0,   155,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,   339,     0,   434,   435,   256,   256,     0,     0,
       0,     0,     0,     0,     0,     0,   179,    14,   181,     0,
       6,     7,     8,     9,    10,    11,   405,     1,     0,     0,
     256,   256,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,    12,
      13,   207,     0,     0,   208,   298,   299,   300,   301,   302,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,     0,     0,   207,
       0,     0,   208,     0,     0,     0,     0,     0,   303,    14,
       0,    14,     0,     0,     0,     0,     0,   298,   299,   300,
     301,   302,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     1,   115,
     116,   207,     0,     0,   208,     0,     0,     0,     0,     0,
     303,    14,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   117,
     118,   207,     0,   260,   208,    10,    11,     0,   209,     0,
       0,     0,   210,   211,   212,   213,   214,     0,     0,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     1,   115,
     116,     0,     0,   119,   120,   121,   122,   123,     0,     1,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,     0,     0,     0,   117,
     118,   126,     0,   127,     0,     0,     0,     0,     0,   216,
     117,   118,    14,   280,     0,     0,    10,    11,     0,   209,
       0,     0,     0,   210,   211,   212,   213,   214,     0,     0,
       0,     0,   215,   119,   120,   121,   122,   123,     0,     0,
     115,   116,     0,     0,   119,   120,   121,   122,   123,     0,
       1,   115,   116,     0,   124,   125,     0,     0,     0,     0,
       0,   126,     0,   127,     0,   124,   125,     0,     0,     0,
     117,   118,   126,     0,   127,     0,     0,     0,     0,     0,
     312,   117,   118,    68,     1,     0,     0,    10,    11,     0,
     209,     0,     0,     0,   210,   211,   212,   213,   214,     0,
       0,     0,     0,   215,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   124,   125,     0,     0,
       0,     0,     0,   126,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,     0,     0,   207,     1,
       0,   208,     0,     3,     4,     5,     0,     0,    14,     0,
       0,     0,     0,     1,     0,     0,     0,     3,     4,     5,
       0,     0,     0,     0,   131,     0,     0,   132,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    11,   131,     0,
       0,   132,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,     0,     1,     0,     0,     0,     3,     4,     5,
       0,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,   131,     0,
       0,   132,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,     0,     1,     0,     0,     0,     3,     4,     5,
     133,     0,     0,    14,     0,     0,     0,     1,     0,     0,
       0,     3,     4,     5,   232,    12,    13,    14,   131,     0,
       0,   132,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,   131,     0,     0,   132,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,     1,     0,     0,
       0,     3,     4,     5,   254,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,     0,   131,     0,     0,   132,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,     0,     1,     0,     0,
       0,     3,     4,     5,   314,     0,     0,    14,     0,     0,
       0,     1,     0,     0,     0,     3,     4,     5,   330,    12,
      13,    14,   131,     0,     0,   132,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,   131,     0,     0,   132,
      67,   115,   116,     0,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,   353,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   118,    12,    13,     0,     0,    10,    11,     0,
     209,     0,     0,     0,   210,   211,   212,   213,   214,     0,
       0,     0,     0,   215,     0,     0,     0,     0,   361,     0,
       0,    14,     0,     0,     0,   119,   120,   121,   122,   123,
       0,     0,   378,   115,   116,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,     0,     0,
       0,     0,     0,   126,     0,   127,     0,     0,     0,     0,
       0,   310,     0,   117,   118,     0,     0,     0,     0,    10,
      11,     0,   209,     0,     0,     0,   210,   211,   212,   213,
     214,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,   115,   116,     0,     0,     0,   119,   120,   121,
     122,   123,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   124,   125,
       0,   207,   117,   118,   208,   126,     0,   127,    10,    11,
       0,   209,     0,   296,     0,   210,   211,   212,   213,   214,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,   115,   116,     0,     0,     0,   119,   120,   121,   122,
     123,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   124,   125,     0,
     207,   117,   118,   208,   126,     0,   127,    10,    11,     0,
     209,     0,   351,     0,   210,   211,   212,   213,   214,     0,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     1,
     115,   116,     0,     0,     0,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,     0,     0,
     117,   118,     0,   126,     0,   127,    10,    11,     0,   209,
       0,   352,     0,   210,   211,   212,   213,   214,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   124,   125,     0,   207,     0,
     366,   208,   126,     0,   127,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,     0,     0,   207,     0,     0,   208,   335,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,     0,     0,   207,     0,
     370,   208,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,     0,
       0,   207,     0,   386,   208,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,     0,     0,   207,     0,   408,   208,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,     0,     0,   207,     0,   409,
     208,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     207,     0,   448,   208,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,     0,     0,   207,     0,   449,   208
};

static const yytype_int16 yycheck[] =
{
       0,    18,    36,     0,    38,    88,     0,    85,     3,   172,
      88,     3,    18,   333,   334,    15,     3,     3,    15,     4,
       3,    15,    22,    23,    24,    19,   134,     3,     3,     6,
       3,   134,     4,     3,   322,   134,   230,    87,     7,     8,
       9,     0,     4,    43,    44,     3,     3,    38,    42,    49,
       4,     3,    98,    53,    54,   105,    15,    44,     0,   102,
     103,    44,    39,     7,     8,     9,   229,    36,     4,    38,
      37,    71,   102,    15,    65,    66,   132,    71,    38,   162,
      22,    23,    24,    97,   162,    85,   100,    44,    88,   377,
      90,    91,    36,    37,   414,   415,    65,    66,    65,    66,
       4,    43,    44,    99,   102,    65,    66,    49,   103,   105,
     103,    53,    54,    98,   106,   107,    86,     4,   438,   439,
     107,   107,   139,     0,   107,   319,    98,   102,   103,   129,
     103,   107,   132,   139,   134,   135,    98,   134,    15,     4,
     134,    38,    19,    37,    38,   139,   103,   255,    90,    91,
     102,   103,   255,    38,   210,    37,   255,    37,    99,     7,
       8,     9,   162,    37,   105,    42,   329,    28,   246,   247,
      37,    38,   172,     7,     8,     9,    37,    38,   172,    99,
       7,     8,     9,    65,    66,   105,     3,   129,    36,    37,
      38,   102,   134,   135,    71,    38,     7,     8,     9,     3,
       4,     5,    36,    37,    65,    66,    37,   315,    38,    36,
     210,    37,   315,   213,   214,   215,   315,   217,   218,    65,
      66,   221,   222,    38,   224,    36,    38,    38,    37,   229,
      34,    35,    37,   233,    98,   229,    99,   320,    65,    66,
     102,   103,   320,   326,    34,    35,   246,   247,   326,    37,
      38,   103,    40,    41,   362,   255,    97,   134,   255,   362,
      98,   255,   139,   362,    68,    69,    70,    71,    72,    34,
      35,   213,   214,   215,   106,   217,   218,    65,    66,   221,
     222,   105,   224,     4,   106,    89,    90,   106,   371,   289,
       4,   233,    96,   371,    98,   172,   227,   228,   354,     7,
       8,     9,     4,   107,     7,     8,     9,   106,   342,     4,
     366,     4,    98,   255,   370,   315,    98,    98,   315,   375,
     320,   315,    39,    40,    41,    98,   326,   102,    36,   329,
      38,   102,    99,    36,   103,   329,    98,    91,    92,    93,
      98,   105,    98,    97,    48,   401,   100,   289,   404,   405,
     406,   407,   229,    99,   354,     7,     8,     9,     4,    98,
      98,   102,   362,    99,    86,   362,   366,    99,   362,    99,
     370,   371,     4,   315,    44,   375,    53,    53,   255,   219,
      98,   381,    98,   383,    36,    37,    98,    98,   107,   389,
      99,    15,   448,   449,   450,   451,    -1,    -1,    99,    99,
      58,   401,    99,    -1,   404,   405,   406,   407,   464,   465,
      -1,    -1,    -1,    65,    66,    -1,    -1,    -1,   418,    -1,
     362,    -1,   422,    -1,   366,    -1,   426,    -1,   370,    -1,
     430,    88,    89,    90,    91,    92,    93,    -1,   315,   381,
      97,   383,    -1,   100,    -1,    -1,    -1,   389,   448,   449,
     450,   451,   329,    -1,   454,    -1,    -1,    -1,   458,   401,
      -1,    -1,   404,   405,   464,   465,   124,   125,   126,   127,
      -1,   311,    -1,   313,    -1,    -1,   418,    -1,    -1,    -1,
     422,    -1,    -1,    -1,   426,   362,    -1,    -1,    -1,    -1,
     432,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,   448,   449,    97,    -1,
      -1,   100,   454,    -1,    -1,    -1,   458,    -1,    -1,    88,
      89,    90,    91,    92,    93,    -1,   366,   185,    97,    -1,
     370,   100,    -1,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
     208,    -1,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   401,    -1,    -1,   404,   405,   406,   407,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,    -1,   245,    -1,     7,
       8,   249,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,   448,   449,
      28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,   279,    -1,    -1,    42,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
     298,   299,   300,   301,   302,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,     0,    -1,    -1,
      78,    -1,    80,     3,     7,     8,     6,     7,     8,     9,
      -1,    -1,    15,    -1,   332,   333,   334,    20,    -1,   337,
      -1,    99,    -1,   101,    -1,    28,    -1,    30,    31,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,
     368,   369,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    65,    66,    -1,    -1,    -1,
      73,    -1,    -1,    76,     0,     3,    79,     3,    -1,    82,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,   412,   413,   414,   415,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   107,   111,    -1,
      36,    37,    38,    39,    40,    41,    44,     3,    -1,    -1,
     438,   439,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    65,
      66,    97,    -1,    -1,   100,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,   106,   107,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     3,     4,
       5,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
     106,   107,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    34,
      35,    97,    -1,    99,   100,    40,    41,    -1,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    68,    69,    70,    71,    72,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    34,
      35,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,   104,
      34,    35,   107,    48,    -1,    -1,    40,    41,    -1,    43,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    68,    69,    70,    71,    72,    -1,    -1,
       4,     5,    -1,    -1,    68,    69,    70,    71,    72,    -1,
       3,     4,     5,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,    -1,    89,    90,    -1,    -1,    -1,
      34,    35,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
     104,    34,    35,   107,     3,    -1,    -1,    40,    41,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,     3,
      -1,   100,    -1,     7,     8,     9,    -1,    -1,   107,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    28,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    28,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
     104,    -1,    -1,   107,    -1,    -1,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,   104,    65,    66,   107,    28,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,   104,    65,    66,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,   104,    -1,    -1,   107,    -1,    -1,
      -1,     3,    -1,    -1,    -1,     7,     8,     9,   104,    65,
      66,   107,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    28,    -1,    -1,    31,
       3,     4,     5,    -1,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    65,
      66,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    65,    66,    -1,    -1,    40,    41,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,   104,    -1,
      -1,   107,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      -1,    -1,   104,     4,     5,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    89,    90,
      -1,    97,    34,    35,   100,    96,    -1,    98,    40,    41,
      -1,    43,    -1,   104,    -1,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    89,    90,    -1,
      97,    34,    35,   100,    96,    -1,    98,    40,    41,    -1,
      43,    -1,   104,    -1,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      34,    35,    -1,    96,    -1,    98,    40,    41,    -1,    43,
      -1,   104,    -1,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    89,    90,    -1,    97,    -1,
      99,   100,    96,    -1,    98,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    -1,   100,   101,    78,
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
       0,     3,     6,     7,     8,     9,    36,    37,    38,    39,
      40,    41,    65,    66,   107,   109,   110,   113,   118,   119,
     120,   121,   122,   124,   125,   140,   141,     4,    38,   119,
     120,    37,   119,   120,     4,     4,    98,     4,    98,     0,
     110,   113,   119,   124,   125,   140,   141,     6,   121,   122,
      37,    38,   120,   124,   125,    37,    38,   119,   106,   123,
     139,   140,   141,   140,   141,   140,   141,     3,   107,   140,
     102,   103,   119,   120,    38,   120,    38,   119,   119,   120,
      37,   120,    37,   119,    98,   102,     4,   117,   102,   117,
     124,   125,   140,   141,   140,   141,     4,   140,   141,    38,
     120,    37,   120,    37,    38,   140,   141,   140,   141,    38,
     119,    37,   119,    37,    38,     4,     5,    34,    35,    68,
      69,    70,    71,    72,    89,    90,    96,    98,   131,   103,
       4,    28,    31,   104,   111,   112,   113,   114,   115,   118,
     119,   124,   125,   140,   141,   120,   119,   120,    38,   119,
      38,   120,   119,   120,    37,   119,    37,   116,   117,   126,
     139,   140,   102,    99,   105,   126,    99,   140,   141,   140,
     141,   102,   103,   120,    38,   120,    37,    38,    37,   119,
      38,   119,    37,    38,    37,    98,    97,   131,   131,   131,
     131,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    97,   100,    43,
      47,    48,    49,    50,    51,    56,   104,   124,   125,   129,
     130,   131,   134,   135,   136,   137,   138,   140,   141,   103,
      98,   123,   104,   112,   113,   114,   115,   140,   141,   140,
     141,   124,   125,    28,    99,   106,     4,   127,   126,   106,
       4,   106,   106,     4,   104,   111,   131,   132,   133,     4,
      99,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,     4,   131,    98,
      48,   123,   131,    98,    98,   140,   141,   140,   141,   131,
     140,   141,   140,   141,   140,   141,   104,   130,    73,    74,
      75,    76,    77,   106,   140,   141,   140,   141,   140,   141,
     104,   129,   104,   129,   104,   111,   116,   140,   141,    98,
     102,   131,    86,   139,   139,   131,   102,   131,   131,   103,
     104,    99,   105,    98,    98,   101,   131,    98,    48,    48,
     131,     4,    98,   140,   141,   131,   131,   131,   131,   131,
     131,   104,   104,   104,    99,   116,   126,     4,   127,   128,
     126,   104,   111,   131,   132,   132,    99,   131,    98,    98,
      99,   102,   117,   102,   123,    99,    87,   105,   104,    99,
      99,   123,   130,   131,   140,   141,    99,   131,   131,   123,
     130,   140,   141,   126,    99,    34,    35,   102,   123,     4,
     127,    44,   140,   141,    44,    44,    44,    44,    99,    99,
     140,   141,    53,    53,    98,    98,    34,    35,   123,   130,
     140,   141,   123,   130,   140,   141,   123,   130,   140,   141,
     123,   130,   123,   130,   131,   131,   132,   132,    98,    98,
     140,   141,   140,   141,   140,   141,   140,   141,    99,    99,
      99,    99,   132,   132,   123,   130,   140,   141,   123,   130,
     140,   141,   123,   123,    99,    99,   140,   141,   140,   141,
     123,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   123,   123,
     123,   123,   123,   123,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   134,   134,   134,   135,   135,   135,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     3,     3,
       2,     2,     3,     3,     2,     2,     3,     3,     4,     4,
       3,     3,     4,     4,     2,     2,     8,     6,     7,     5,
       7,     5,     6,     4,     1,     1,     1,     2,     2,     1,
       1,     2,     3,     3,     2,     2,     2,     2,     2,     2,
       1,     1,     3,     3,     2,     2,     2,     1,     2,     6,
       5,    10,    10,    11,    11,     5,     4,     9,     9,    10,
      10,     0,     1,     3,     5,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     1,     2,     3,     7,     5,     4,
       4,     5,     4,     3,     4,     6,     6,     4,     6,     6,
       3,     3,     4,     1,     1,     3,     3,     1,     2,     2,
       2,     2,     1,     2,     1,     1,     2,     2,     2,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       4,     3,     6,     3,     0,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     5,     6,     5,     6,     5,     6,
       6,     5,     9,    10,     9,     9,    10,     9,    10,     9,
      10,     9,     5,     5,     6,     7,     7,     7,     7,     8,
       8,     8,     8,     7,     7,     7,     5,     6,     7,     8,
       8,     8,     8,     7,     7,     7,     0,     1,     1,     2,
       1,     2,     2
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
#line 2109 "synt_analyzer.tab.cpp"
    break;

  case 3: /* program: newLines  */
#line 194 "synt_analyzer.y"
           {root = createProgram(); puts("program created");}
#line 2115 "synt_analyzer.tab.cpp"
    break;

  case 4: /* program: class  */
#line 195 "synt_analyzer.y"
        {root = createProgram((yyvsp[0].classU));puts("program created");}
#line 2121 "synt_analyzer.tab.cpp"
    break;

  case 5: /* program: method  */
#line 196 "synt_analyzer.y"
                {root = createProgram((yyvsp[0].methodU));puts("program created");}
#line 2127 "synt_analyzer.tab.cpp"
    break;

  case 6: /* program: valDeclaration semis  */
#line 197 "synt_analyzer.y"
                        {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2133 "synt_analyzer.tab.cpp"
    break;

  case 7: /* program: varDeclaration semis  */
#line 198 "synt_analyzer.y"
                        {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2139 "synt_analyzer.tab.cpp"
    break;

  case 8: /* program: visibilityModifier valDeclaration semis  */
#line 199 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2145 "synt_analyzer.tab.cpp"
    break;

  case 9: /* program: visibilityModifier varDeclaration semis  */
#line 200 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2151 "synt_analyzer.tab.cpp"
    break;

  case 10: /* program: valDeclaration newLines  */
#line 201 "synt_analyzer.y"
                                {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2157 "synt_analyzer.tab.cpp"
    break;

  case 11: /* program: varDeclaration newLines  */
#line 202 "synt_analyzer.y"
                                {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2163 "synt_analyzer.tab.cpp"
    break;

  case 12: /* program: visibilityModifier valDeclaration newLines  */
#line 203 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2169 "synt_analyzer.tab.cpp"
    break;

  case 13: /* program: visibilityModifier varDeclaration newLines  */
#line 204 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2175 "synt_analyzer.tab.cpp"
    break;

  case 14: /* program: program class  */
#line 205 "synt_analyzer.y"
                {root = addToProgram(root, (yyvsp[0].classU));puts("class added to prog");}
#line 2181 "synt_analyzer.tab.cpp"
    break;

  case 15: /* program: program method  */
#line 206 "synt_analyzer.y"
                        {root = addToProgram(root, (yyvsp[0].methodU));puts("meth added to prog");}
#line 2187 "synt_analyzer.tab.cpp"
    break;

  case 16: /* program: program valDeclaration semis  */
#line 207 "synt_analyzer.y"
                                {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2193 "synt_analyzer.tab.cpp"
    break;

  case 17: /* program: program varDeclaration semis  */
#line 208 "synt_analyzer.y"
                                {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2199 "synt_analyzer.tab.cpp"
    break;

  case 18: /* program: program visibilityModifier valDeclaration semis  */
#line 209 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2205 "synt_analyzer.tab.cpp"
    break;

  case 19: /* program: program visibilityModifier varDeclaration semis  */
#line 210 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2211 "synt_analyzer.tab.cpp"
    break;

  case 20: /* program: program valDeclaration newLines  */
#line 211 "synt_analyzer.y"
                                        {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2217 "synt_analyzer.tab.cpp"
    break;

  case 21: /* program: program varDeclaration newLines  */
#line 212 "synt_analyzer.y"
                                        {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2223 "synt_analyzer.tab.cpp"
    break;

  case 22: /* program: program visibilityModifier valDeclaration newLines  */
#line 213 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2229 "synt_analyzer.tab.cpp"
    break;

  case 23: /* program: program visibilityModifier varDeclaration newLines  */
#line 214 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2235 "synt_analyzer.tab.cpp"
    break;

  case 24: /* program: program semis  */
#line 215 "synt_analyzer.y"
                {root = root;}
#line 2241 "synt_analyzer.tab.cpp"
    break;

  case 25: /* program: program newLines  */
#line 216 "synt_analyzer.y"
                   {root = root;}
#line 2247 "synt_analyzer.tab.cpp"
    break;

  case 26: /* class: modifiers CLASS ID ':' ID '{' classBody '}'  */
#line 219 "synt_analyzer.y"
                                                        {(yyval.classU) = createClass((yyvsp[-7].modifiersU), (yyvsp[-5].IdOrString), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU));puts("class created");}
#line 2253 "synt_analyzer.tab.cpp"
    break;

  case 27: /* class: modifiers CLASS ID '{' classBody '}'  */
#line 220 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].modifiersU), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2259 "synt_analyzer.tab.cpp"
    break;

  case 28: /* class: CLASS ID ':' ID '{' classBody '}'  */
#line 221 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].IdOrString), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2265 "synt_analyzer.tab.cpp"
    break;

  case 29: /* class: CLASS ID '{' classBody '}'  */
#line 222 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2271 "synt_analyzer.tab.cpp"
    break;

  case 30: /* class: modifiers CLASS ID ':' ID '{' '}'  */
#line 223 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-6].modifiersU), (yyvsp[-4].IdOrString), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2277 "synt_analyzer.tab.cpp"
    break;

  case 31: /* class: modifiers CLASS ID '{' '}'  */
#line 224 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].modifiersU), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2283 "synt_analyzer.tab.cpp"
    break;

  case 32: /* class: CLASS ID ':' ID '{' '}'  */
#line 225 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].IdOrString), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2289 "synt_analyzer.tab.cpp"
    break;

  case 33: /* class: CLASS ID '{' '}'  */
#line 226 "synt_analyzer.y"
                        {(yyval.classU) = createClass((yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2295 "synt_analyzer.tab.cpp"
    break;

  case 34: /* classBody: semis  */
#line 229 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2301 "synt_analyzer.tab.cpp"
    break;

  case 35: /* classBody: newLines  */
#line 230 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2307 "synt_analyzer.tab.cpp"
    break;

  case 36: /* classBody: method  */
#line 231 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].methodU));  puts("class body created");}
#line 2313 "synt_analyzer.tab.cpp"
    break;

  case 37: /* classBody: property semis  */
#line 232 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2319 "synt_analyzer.tab.cpp"
    break;

  case 38: /* classBody: property newLines  */
#line 233 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2325 "synt_analyzer.tab.cpp"
    break;

  case 39: /* classBody: constructor  */
#line 234 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].constructorU));  puts("class body created");}
#line 2331 "synt_analyzer.tab.cpp"
    break;

  case 40: /* classBody: initializer  */
#line 235 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody((yyvsp[0].initializerU));  puts("class body created");}
#line 2337 "synt_analyzer.tab.cpp"
    break;

  case 41: /* classBody: classBody method  */
#line 236 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].methodU));  puts("meth added to class body");}
#line 2343 "synt_analyzer.tab.cpp"
    break;

  case 42: /* classBody: classBody property semis  */
#line 237 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2349 "synt_analyzer.tab.cpp"
    break;

  case 43: /* classBody: classBody property newLines  */
#line 238 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2355 "synt_analyzer.tab.cpp"
    break;

  case 44: /* classBody: classBody constructor  */
#line 239 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].constructorU)); puts("constr added to class body");}
#line 2361 "synt_analyzer.tab.cpp"
    break;

  case 45: /* classBody: classBody initializer  */
#line 240 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].initializerU)); puts("init added to class body");}
#line 2367 "synt_analyzer.tab.cpp"
    break;

  case 46: /* classBody: classBody semis  */
#line 241 "synt_analyzer.y"
                        {(yyval.classBodyU) = (yyvsp[-1].classBodyU); puts("semis added to class body");}
#line 2373 "synt_analyzer.tab.cpp"
    break;

  case 47: /* classBody: classBody newLines  */
#line 242 "synt_analyzer.y"
                        {(yyval.classBodyU) = (yyvsp[-1].classBodyU); puts("newLines added to class body");}
#line 2379 "synt_analyzer.tab.cpp"
    break;

  case 48: /* property: modifiers valDeclaration  */
#line 245 "synt_analyzer.y"
                                        {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2385 "synt_analyzer.tab.cpp"
    break;

  case 49: /* property: modifiers varDeclaration  */
#line 246 "synt_analyzer.y"
                                {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2391 "synt_analyzer.tab.cpp"
    break;

  case 50: /* property: valDeclaration  */
#line 247 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2397 "synt_analyzer.tab.cpp"
    break;

  case 51: /* property: varDeclaration  */
#line 248 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2403 "synt_analyzer.tab.cpp"
    break;

  case 52: /* method: modifiers funcDeclaration semis  */
#line 251 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2409 "synt_analyzer.tab.cpp"
    break;

  case 53: /* method: modifiers funcDeclaration newLines  */
#line 252 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2415 "synt_analyzer.tab.cpp"
    break;

  case 54: /* method: modifiers func  */
#line 253 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].modifiersU), (yyvsp[0].funcU)); puts("meth created");}
#line 2421 "synt_analyzer.tab.cpp"
    break;

  case 55: /* method: funcDeclaration semis  */
#line 254 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2427 "synt_analyzer.tab.cpp"
    break;

  case 56: /* method: funcDeclaration newLines  */
#line 255 "synt_analyzer.y"
                                {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2433 "synt_analyzer.tab.cpp"
    break;

  case 57: /* method: func  */
#line 256 "synt_analyzer.y"
        {(yyval.methodU) = createMethod((yyvsp[0].funcU)); puts("meth created");}
#line 2439 "synt_analyzer.tab.cpp"
    break;

  case 58: /* initializer: INIT block  */
#line 259 "synt_analyzer.y"
                        {(yyval.initializerU) = createInit((yyvsp[0].stmtListU)); puts("init created");}
#line 2445 "synt_analyzer.tab.cpp"
    break;

  case 59: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' block  */
#line 263 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-5].visibilityModU), (yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2451 "synt_analyzer.tab.cpp"
    break;

  case 60: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')'  */
#line 264 "synt_analyzer.y"
                                                                {(yyval.constructorU) = createConstructor((yyvsp[-4].visibilityModU), (yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2457 "synt_analyzer.tab.cpp"
    break;

  case 61: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 265 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2463 "synt_analyzer.tab.cpp"
    break;

  case 62: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 266 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-9].visibilityModU), (yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2469 "synt_analyzer.tab.cpp"
    break;

  case 63: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 267 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2475 "synt_analyzer.tab.cpp"
    break;

  case 64: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 268 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2481 "synt_analyzer.tab.cpp"
    break;

  case 65: /* constructor: CONSTRUCTOR '(' optFormalParams ')' block  */
#line 269 "synt_analyzer.y"
                                                {(yyval.constructorU) = createConstructor((yyvsp[-2].formalParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2487 "synt_analyzer.tab.cpp"
    break;

  case 66: /* constructor: CONSTRUCTOR '(' optFormalParams ')'  */
#line 270 "synt_analyzer.y"
                                        {(yyval.constructorU) = createConstructor((yyvsp[-1].formalParamsListU)); puts("constr created");}
#line 2493 "synt_analyzer.tab.cpp"
    break;

  case 67: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')'  */
#line 271 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "super", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2499 "synt_analyzer.tab.cpp"
    break;

  case 68: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')'  */
#line 272 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].formalParamsListU), "this", (yyvsp[-1].factParamsListU)); puts("constr created");}
#line 2505 "synt_analyzer.tab.cpp"
    break;

  case 69: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block  */
#line 273 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2511 "synt_analyzer.tab.cpp"
    break;

  case 70: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block  */
#line 274 "synt_analyzer.y"
                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU), (yyvsp[0].stmtListU)); puts("constr created");}
#line 2517 "synt_analyzer.tab.cpp"
    break;

  case 71: /* optFormalParams: %empty  */
#line 277 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = 0; puts("opt formal params created");}
#line 2523 "synt_analyzer.tab.cpp"
    break;

  case 72: /* optFormalParams: formalParams  */
#line 278 "synt_analyzer.y"
                {(yyval.formalParamsListU) = (yyvsp[0].formalParamsListU); puts("opt formal params created");}
#line 2529 "synt_analyzer.tab.cpp"
    break;

  case 73: /* formalParams: ID ':' type  */
#line 281 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = createFormalParamsList((yyvsp[-2].IdOrString), (yyvsp[0].typeU)); puts("formal params created");}
#line 2535 "synt_analyzer.tab.cpp"
    break;

  case 74: /* formalParams: formalParams ',' ID ':' type  */
#line 282 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = addToFormalParamsList((yyvsp[-4].formalParamsListU), (yyvsp[-2].IdOrString), (yyvsp[0].typeU)); puts("formal params created");}
#line 2541 "synt_analyzer.tab.cpp"
    break;

  case 75: /* modifiers: OVERRIDE  */
#line 285 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, None); puts("mods created");}
#line 2547 "synt_analyzer.tab.cpp"
    break;

  case 76: /* modifiers: visibilityModifier  */
#line 286 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2553 "synt_analyzer.tab.cpp"
    break;

  case 77: /* modifiers: inheritanceModifier  */
#line 287 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2559 "synt_analyzer.tab.cpp"
    break;

  case 78: /* modifiers: ABSTRACT  */
#line 288 "synt_analyzer.y"
                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, None); puts("mods created");}
#line 2565 "synt_analyzer.tab.cpp"
    break;

  case 79: /* modifiers: OVERRIDE visibilityModifier  */
#line 289 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2571 "synt_analyzer.tab.cpp"
    break;

  case 80: /* modifiers: OVERRIDE inheritanceModifier  */
#line 290 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2577 "synt_analyzer.tab.cpp"
    break;

  case 81: /* modifiers: OVERRIDE ABSTRACT  */
#line 291 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2583 "synt_analyzer.tab.cpp"
    break;

  case 82: /* modifiers: visibilityModifier OVERRIDE  */
#line 292 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2589 "synt_analyzer.tab.cpp"
    break;

  case 83: /* modifiers: visibilityModifier inheritanceModifier  */
#line 293 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2595 "synt_analyzer.tab.cpp"
    break;

  case 84: /* modifiers: visibilityModifier ABSTRACT  */
#line 294 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2601 "synt_analyzer.tab.cpp"
    break;

  case 85: /* modifiers: inheritanceModifier OVERRIDE  */
#line 295 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2607 "synt_analyzer.tab.cpp"
    break;

  case 86: /* modifiers: inheritanceModifier visibilityModifier  */
#line 296 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2613 "synt_analyzer.tab.cpp"
    break;

  case 87: /* modifiers: inheritanceModifier ABSTRACT  */
#line 297 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2619 "synt_analyzer.tab.cpp"
    break;

  case 88: /* modifiers: ABSTRACT OVERRIDE  */
#line 298 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2625 "synt_analyzer.tab.cpp"
    break;

  case 89: /* modifiers: ABSTRACT visibilityModifier  */
#line 299 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2631 "synt_analyzer.tab.cpp"
    break;

  case 90: /* modifiers: ABSTRACT inheritanceModifier  */
#line 300 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2637 "synt_analyzer.tab.cpp"
    break;

  case 91: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier  */
#line 301 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2643 "synt_analyzer.tab.cpp"
    break;

  case 92: /* modifiers: OVERRIDE visibilityModifier ABSTRACT  */
#line 302 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2649 "synt_analyzer.tab.cpp"
    break;

  case 93: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier  */
#line 303 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2655 "synt_analyzer.tab.cpp"
    break;

  case 94: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT  */
#line 304 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2661 "synt_analyzer.tab.cpp"
    break;

  case 95: /* modifiers: OVERRIDE ABSTRACT visibilityModifier  */
#line 305 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2667 "synt_analyzer.tab.cpp"
    break;

  case 96: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier  */
#line 306 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2673 "synt_analyzer.tab.cpp"
    break;

  case 97: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier  */
#line 307 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2679 "synt_analyzer.tab.cpp"
    break;

  case 98: /* modifiers: visibilityModifier OVERRIDE ABSTRACT  */
#line 308 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2685 "synt_analyzer.tab.cpp"
    break;

  case 99: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE  */
#line 309 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2691 "synt_analyzer.tab.cpp"
    break;

  case 100: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT  */
#line 310 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2697 "synt_analyzer.tab.cpp"
    break;

  case 101: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier  */
#line 311 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2703 "synt_analyzer.tab.cpp"
    break;

  case 102: /* modifiers: visibilityModifier ABSTRACT OVERRIDE  */
#line 312 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2709 "synt_analyzer.tab.cpp"
    break;

  case 103: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier  */
#line 313 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2715 "synt_analyzer.tab.cpp"
    break;

  case 104: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT  */
#line 314 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2721 "synt_analyzer.tab.cpp"
    break;

  case 105: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT  */
#line 315 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2727 "synt_analyzer.tab.cpp"
    break;

  case 106: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE  */
#line 316 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2733 "synt_analyzer.tab.cpp"
    break;

  case 107: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier  */
#line 317 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2739 "synt_analyzer.tab.cpp"
    break;

  case 108: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE  */
#line 318 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2745 "synt_analyzer.tab.cpp"
    break;

  case 109: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier  */
#line 319 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2751 "synt_analyzer.tab.cpp"
    break;

  case 110: /* modifiers: ABSTRACT OVERRIDE visibilityModifier  */
#line 320 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2757 "synt_analyzer.tab.cpp"
    break;

  case 111: /* modifiers: ABSTRACT visibilityModifier OVERRIDE  */
#line 321 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2763 "synt_analyzer.tab.cpp"
    break;

  case 112: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier  */
#line 322 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2769 "synt_analyzer.tab.cpp"
    break;

  case 113: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE  */
#line 323 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2775 "synt_analyzer.tab.cpp"
    break;

  case 114: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier  */
#line 324 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2781 "synt_analyzer.tab.cpp"
    break;

  case 115: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier ABSTRACT  */
#line 325 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2787 "synt_analyzer.tab.cpp"
    break;

  case 116: /* modifiers: OVERRIDE visibilityModifier ABSTRACT inheritanceModifier  */
#line 326 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2793 "synt_analyzer.tab.cpp"
    break;

  case 117: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier ABSTRACT  */
#line 327 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2799 "synt_analyzer.tab.cpp"
    break;

  case 118: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT visibilityModifier  */
#line 328 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2805 "synt_analyzer.tab.cpp"
    break;

  case 119: /* modifiers: OVERRIDE ABSTRACT visibilityModifier inheritanceModifier  */
#line 329 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2811 "synt_analyzer.tab.cpp"
    break;

  case 120: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier visibilityModifier  */
#line 330 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2817 "synt_analyzer.tab.cpp"
    break;

  case 121: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier ABSTRACT  */
#line 331 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2823 "synt_analyzer.tab.cpp"
    break;

  case 122: /* modifiers: visibilityModifier OVERRIDE ABSTRACT inheritanceModifier  */
#line 332 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2829 "synt_analyzer.tab.cpp"
    break;

  case 123: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE ABSTRACT  */
#line 333 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2835 "synt_analyzer.tab.cpp"
    break;

  case 124: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT OVERRIDE  */
#line 334 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2841 "synt_analyzer.tab.cpp"
    break;

  case 125: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier OVERRIDE  */
#line 335 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2847 "synt_analyzer.tab.cpp"
    break;

  case 126: /* modifiers: visibilityModifier ABSTRACT OVERRIDE inheritanceModifier  */
#line 336 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2853 "synt_analyzer.tab.cpp"
    break;

  case 127: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier ABSTRACT  */
#line 337 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2859 "synt_analyzer.tab.cpp"
    break;

  case 128: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT visibilityModifier  */
#line 338 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2865 "synt_analyzer.tab.cpp"
    break;

  case 129: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT OVERRIDE  */
#line 340 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2871 "synt_analyzer.tab.cpp"
    break;

  case 130: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE ABSTRACT  */
#line 342 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2877 "synt_analyzer.tab.cpp"
    break;

  case 131: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier OVERRIDE  */
#line 344 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2883 "synt_analyzer.tab.cpp"
    break;

  case 132: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE visibilityModifier  */
#line 346 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2889 "synt_analyzer.tab.cpp"
    break;

  case 133: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier visibilityModifier  */
#line 348 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2895 "synt_analyzer.tab.cpp"
    break;

  case 134: /* modifiers: ABSTRACT OVERRIDE visibilityModifier inheritanceModifier  */
#line 350 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2901 "synt_analyzer.tab.cpp"
    break;

  case 135: /* modifiers: ABSTRACT visibilityModifier OVERRIDE inheritanceModifier  */
#line 351 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2907 "synt_analyzer.tab.cpp"
    break;

  case 136: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier OVERRIDE  */
#line 352 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2913 "synt_analyzer.tab.cpp"
    break;

  case 137: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE visibilityModifier  */
#line 354 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2919 "synt_analyzer.tab.cpp"
    break;

  case 138: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier OVERRIDE  */
#line 356 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2925 "synt_analyzer.tab.cpp"
    break;

  case 139: /* visibilityModifier: PUBLIC  */
#line 359 "synt_analyzer.y"
                                {(yyval.visibilityModU) = Public;}
#line 2931 "synt_analyzer.tab.cpp"
    break;

  case 140: /* visibilityModifier: PRIVATE  */
#line 360 "synt_analyzer.y"
                {(yyval.visibilityModU) = Private;}
#line 2937 "synt_analyzer.tab.cpp"
    break;

  case 141: /* visibilityModifier: INTERNAL  */
#line 361 "synt_analyzer.y"
                {(yyval.visibilityModU) = Internal;}
#line 2943 "synt_analyzer.tab.cpp"
    break;

  case 142: /* visibilityModifier: PROTECTED  */
#line 362 "synt_analyzer.y"
                {(yyval.visibilityModU) = Protected;}
#line 2949 "synt_analyzer.tab.cpp"
    break;

  case 143: /* inheritanceModifier: FINAL  */
#line 366 "synt_analyzer.y"
                           {(yyval.inheritanceModU) = Final;}
#line 2955 "synt_analyzer.tab.cpp"
    break;

  case 144: /* inheritanceModifier: OPEN  */
#line 367 "synt_analyzer.y"
       {(yyval.inheritanceModU) = Open;}
#line 2961 "synt_analyzer.tab.cpp"
    break;

  case 145: /* func: funcDeclaration block  */
#line 370 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-1].funcDeclU), (yyvsp[0].stmtListU)); puts("func created");}
#line 2967 "synt_analyzer.tab.cpp"
    break;

  case 146: /* func: funcDeclaration '=' expr  */
#line 371 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-2].funcDeclU), (yyvsp[0].exprU)); puts("func created");}
#line 2973 "synt_analyzer.tab.cpp"
    break;

  case 147: /* funcDeclaration: FUN ID '(' optFormalParams ')' ':' type  */
#line 375 "synt_analyzer.y"
                                                                {(yyval.funcDeclU) = createFuncDecl((yyvsp[-5].IdOrString), (yyvsp[-3].formalParamsListU), (yyvsp[0].typeU));  puts("func decl created");}
#line 2979 "synt_analyzer.tab.cpp"
    break;

  case 148: /* block: optNewLines '{' semis stmts '}'  */
#line 379 "synt_analyzer.y"
                                        {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2985 "synt_analyzer.tab.cpp"
    break;

  case 149: /* block: optNewLines '{' semis '}'  */
#line 380 "synt_analyzer.y"
                                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2991 "synt_analyzer.tab.cpp"
    break;

  case 150: /* block: optNewLines '{' stmts '}'  */
#line 381 "synt_analyzer.y"
                                {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2997 "synt_analyzer.tab.cpp"
    break;

  case 151: /* block: optNewLines '{' newLines stmts '}'  */
#line 382 "synt_analyzer.y"
                                        {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 3003 "synt_analyzer.tab.cpp"
    break;

  case 152: /* block: optNewLines '{' newLines '}'  */
#line 383 "synt_analyzer.y"
                                {(yyval.stmtListU) = 0;  puts("block created");}
#line 3009 "synt_analyzer.tab.cpp"
    break;

  case 153: /* block: optNewLines '{' '}'  */
#line 384 "synt_analyzer.y"
                        {(yyval.stmtListU) = 0;  puts("block created");}
#line 3015 "synt_analyzer.tab.cpp"
    break;

  case 154: /* varDeclaration: VAR ID ':' type  */
#line 388 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].IdOrString), (yyvsp[0].typeU), 0); puts("var created");}
#line 3021 "synt_analyzer.tab.cpp"
    break;

  case 155: /* varDeclaration: VAR ID ':' type '=' expr  */
#line 389 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].IdOrString), (yyvsp[-2].typeU), (yyvsp[0].exprU), 0); puts("var created");}
#line 3027 "synt_analyzer.tab.cpp"
    break;

  case 156: /* varDeclaration: VAR '(' formalParams ')' '=' expr  */
#line 390 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 0); puts("var created"); }
#line 3033 "synt_analyzer.tab.cpp"
    break;

  case 157: /* valDeclaration: VAL ID ':' type  */
#line 394 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].IdOrString), (yyvsp[0].typeU), 1); puts("val created"); }
#line 3039 "synt_analyzer.tab.cpp"
    break;

  case 158: /* valDeclaration: VAL ID ':' type '=' expr  */
#line 395 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].IdOrString), (yyvsp[-2].typeU), (yyvsp[0].exprU), 1); puts("val created"); }
#line 3045 "synt_analyzer.tab.cpp"
    break;

  case 159: /* valDeclaration: VAL '(' formalParams ')' '=' expr  */
#line 396 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 1); puts("val created"); }
#line 3051 "synt_analyzer.tab.cpp"
    break;

  case 160: /* type: optNewLines ID optNewLines  */
#line 399 "synt_analyzer.y"
                                        {(yyval.typeU) = createType((yyvsp[-1].IdOrString)); puts("type created"); }
#line 3057 "synt_analyzer.tab.cpp"
    break;

  case 161: /* type: optNewLines templateType optNewLines  */
#line 400 "synt_analyzer.y"
                                        {(yyval.typeU) = createType((yyvsp[-1].templateTypeU)); puts("type created"); }
#line 3063 "synt_analyzer.tab.cpp"
    break;

  case 162: /* templateType: ID '<' type_seq '>'  */
#line 403 "synt_analyzer.y"
                                        {(yyval.templateTypeU) = createTemplateType((yyvsp[-3].IdOrString), (yyvsp[-1].typesListU)); puts("template type created"); }
#line 3069 "synt_analyzer.tab.cpp"
    break;

  case 163: /* type_seq: ID  */
#line 406 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].IdOrString)); puts("type seq created"); }
#line 3075 "synt_analyzer.tab.cpp"
    break;

  case 164: /* type_seq: templateType  */
#line 407 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].templateTypeU)); puts("type seq created"); }
#line 3081 "synt_analyzer.tab.cpp"
    break;

  case 165: /* type_seq: type_seq ',' ID  */
#line 408 "synt_analyzer.y"
                        {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].IdOrString));  puts("type seq created"); }
#line 3087 "synt_analyzer.tab.cpp"
    break;

  case 166: /* type_seq: type_seq ',' templateType  */
#line 409 "synt_analyzer.y"
                                {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].templateTypeU));  puts("type seq created"); }
#line 3093 "synt_analyzer.tab.cpp"
    break;

  case 167: /* stmts: stmt  */
#line 412 "synt_analyzer.y"
                {(yyval.stmtListU) = createStmtList((yyvsp[0].stmtU));  puts("stmts created"); }
#line 3099 "synt_analyzer.tab.cpp"
    break;

  case 168: /* stmts: stmts stmt  */
#line 413 "synt_analyzer.y"
                {(yyval.stmtListU) = addToStmtList((yyvsp[-1].stmtListU), (yyvsp[0].stmtU));  puts("stmts created"); }
#line 3105 "synt_analyzer.tab.cpp"
    break;

  case 169: /* stmt: valDeclaration semis  */
#line 416 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3111 "synt_analyzer.tab.cpp"
    break;

  case 170: /* stmt: varDeclaration semis  */
#line 417 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3117 "synt_analyzer.tab.cpp"
    break;

  case 171: /* stmt: assignment semis  */
#line 418 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 3123 "synt_analyzer.tab.cpp"
    break;

  case 172: /* stmt: whileLoop  */
#line 419 "synt_analyzer.y"
            {(yyval.stmtU) = createStmt((yyvsp[0].whileLoopU), WhileLoop);  puts("stmt created"); }
#line 3129 "synt_analyzer.tab.cpp"
    break;

  case 173: /* stmt: doWhileLoop semis  */
#line 420 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 3135 "synt_analyzer.tab.cpp"
    break;

  case 174: /* stmt: forLoop  */
#line 421 "synt_analyzer.y"
          {(yyval.stmtU) = createStmt((yyvsp[0].forLoopU), ForLoop);  puts("stmt created"); }
#line 3141 "synt_analyzer.tab.cpp"
    break;

  case 175: /* stmt: ifStmt  */
#line 422 "synt_analyzer.y"
         {(yyval.stmtU) = createStmt((yyvsp[0].ifStmtU), IfStmt);  puts("stmt created"); }
#line 3147 "synt_analyzer.tab.cpp"
    break;

  case 176: /* stmt: expr semis  */
#line 423 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 3153 "synt_analyzer.tab.cpp"
    break;

  case 177: /* stmt: BREAK semis  */
#line 424 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 3159 "synt_analyzer.tab.cpp"
    break;

  case 178: /* stmt: CONTINUE semis  */
#line 425 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 3165 "synt_analyzer.tab.cpp"
    break;

  case 179: /* stmt: RETURN semis  */
#line 426 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 3171 "synt_analyzer.tab.cpp"
    break;

  case 180: /* stmt: RETURN expr semis  */
#line 427 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 3177 "synt_analyzer.tab.cpp"
    break;

  case 181: /* stmt: valDeclaration newLines  */
#line 428 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3183 "synt_analyzer.tab.cpp"
    break;

  case 182: /* stmt: varDeclaration newLines  */
#line 429 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3189 "synt_analyzer.tab.cpp"
    break;

  case 183: /* stmt: assignment newLines  */
#line 430 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 3195 "synt_analyzer.tab.cpp"
    break;

  case 184: /* stmt: doWhileLoop newLines  */
#line 431 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 3201 "synt_analyzer.tab.cpp"
    break;

  case 185: /* stmt: expr newLines  */
#line 432 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 3207 "synt_analyzer.tab.cpp"
    break;

  case 186: /* stmt: BREAK newLines  */
#line 433 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 3213 "synt_analyzer.tab.cpp"
    break;

  case 187: /* stmt: CONTINUE newLines  */
#line 434 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 3219 "synt_analyzer.tab.cpp"
    break;

  case 188: /* stmt: RETURN newLines  */
#line 435 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 3225 "synt_analyzer.tab.cpp"
    break;

  case 189: /* stmt: RETURN expr newLines  */
#line 436 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 3231 "synt_analyzer.tab.cpp"
    break;

  case 190: /* expr: STR  */
#line 440 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].IdOrString), String);  puts("expr created"); }
#line 3237 "synt_analyzer.tab.cpp"
    break;

  case 191: /* expr: ID  */
#line 441 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].IdOrString), Identificator);  puts("expr created"); }
#line 3243 "synt_analyzer.tab.cpp"
    break;

  case 192: /* expr: THIS  */
#line 442 "synt_analyzer.y"
        {(yyval.exprU) = createExpr(0, This);  puts("expr created"); }
#line 3249 "synt_analyzer.tab.cpp"
    break;

  case 193: /* expr: ID '(' optFactParams ')'  */
#line 443 "synt_analyzer.y"
                                {(yyval.exprU) = createExpr((yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), MethodCall);  puts("expr created"); }
#line 3255 "synt_analyzer.tab.cpp"
    break;

  case 194: /* expr: INT  */
#line 444 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Int_v), Int);  puts("expr created"); }
#line 3261 "synt_analyzer.tab.cpp"
    break;

  case 195: /* expr: FLOAT  */
#line 445 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Float_v), Float);  puts("expr created"); }
#line 3267 "synt_analyzer.tab.cpp"
    break;

  case 196: /* expr: CHR  */
#line 446 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Char_v), Char);  puts("expr created"); }
#line 3273 "synt_analyzer.tab.cpp"
    break;

  case 197: /* expr: DOUBLE  */
#line 447 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Double_v), Double);  puts("expr created"); }
#line 3279 "synt_analyzer.tab.cpp"
    break;

  case 198: /* expr: BOOLEAN  */
#line 448 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Bool_v), Boolean);  puts("expr created"); }
#line 3285 "synt_analyzer.tab.cpp"
    break;

  case 199: /* expr: '(' expr ')'  */
#line 449 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-1].exprU), ExprInBrackets);  puts("expr created"); }
#line 3291 "synt_analyzer.tab.cpp"
    break;

  case 200: /* expr: '!' expr  */
#line 450 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].exprU), LogicalNot);}
#line 3297 "synt_analyzer.tab.cpp"
    break;

  case 201: /* expr: '+' expr  */
#line 451 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryPlusExpr);  puts("expr created"); }
#line 3303 "synt_analyzer.tab.cpp"
    break;

  case 202: /* expr: '-' expr  */
#line 452 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryMinusExpr);  puts("expr created"); }
#line 3309 "synt_analyzer.tab.cpp"
    break;

  case 203: /* expr: expr '+' expr  */
#line 453 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sum);  puts("expr created"); }
#line 3315 "synt_analyzer.tab.cpp"
    break;

  case 204: /* expr: expr '-' expr  */
#line 454 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sub);  puts("expr created"); }
#line 3321 "synt_analyzer.tab.cpp"
    break;

  case 205: /* expr: expr '*' expr  */
#line 455 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mul);  puts("expr created"); }
#line 3327 "synt_analyzer.tab.cpp"
    break;

  case 206: /* expr: expr '/' expr  */
#line 456 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Div);  puts("expr created"); }
#line 3333 "synt_analyzer.tab.cpp"
    break;

  case 207: /* expr: expr '%' expr  */
#line 457 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mod);  puts("expr created"); }
#line 3339 "synt_analyzer.tab.cpp"
    break;

  case 208: /* expr: expr '<' expr  */
#line 458 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Less);  puts("expr created"); }
#line 3345 "synt_analyzer.tab.cpp"
    break;

  case 209: /* expr: expr '>' expr  */
#line 459 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), More);  puts("expr created"); }
#line 3351 "synt_analyzer.tab.cpp"
    break;

  case 210: /* expr: expr OR expr  */
#line 460 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Or);  puts("expr created"); }
#line 3357 "synt_analyzer.tab.cpp"
    break;

  case 211: /* expr: expr AND expr  */
#line 461 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), And);  puts("expr created"); }
#line 3363 "synt_analyzer.tab.cpp"
    break;

  case 212: /* expr: expr EQ expr  */
#line 462 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Eq);  puts("expr created"); }
#line 3369 "synt_analyzer.tab.cpp"
    break;

  case 213: /* expr: expr AEQ expr  */
#line 463 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Aeq);}
#line 3375 "synt_analyzer.tab.cpp"
    break;

  case 214: /* expr: expr NEQ expr  */
#line 464 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Neq);  puts("expr created"); }
#line 3381 "synt_analyzer.tab.cpp"
    break;

  case 215: /* expr: expr NAEQ expr  */
#line 465 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Naeq);  puts("expr created"); }
#line 3387 "synt_analyzer.tab.cpp"
    break;

  case 216: /* expr: expr LOEQ expr  */
#line 466 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Loeq);  puts("expr created"); }
#line 3393 "synt_analyzer.tab.cpp"
    break;

  case 217: /* expr: expr MOEQ expr  */
#line 467 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Moeq);  puts("expr created"); }
#line 3399 "synt_analyzer.tab.cpp"
    break;

  case 218: /* expr: expr '.' ID  */
#line 468 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].IdOrString), FieldCalcExpr);  puts("expr created"); }
#line 3405 "synt_analyzer.tab.cpp"
    break;

  case 219: /* expr: expr '.' ID '(' optFactParams ')'  */
#line 469 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr((yyvsp[-5].exprU), (yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), MethodCalcExpr);  puts("expr created"); }
#line 3411 "synt_analyzer.tab.cpp"
    break;

  case 220: /* expr: expr '[' expr ']'  */
#line 470 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-3].exprU), (yyvsp[-1].exprU), ArrayElementCall);  puts("expr created"); }
#line 3417 "synt_analyzer.tab.cpp"
    break;

  case 221: /* expr: SUPER '.' ID  */
#line 471 "synt_analyzer.y"
                {(yyval.exprU) = createExpr(0, (yyvsp[0].IdOrString), ParentFieldCall);  puts("expr created"); }
#line 3423 "synt_analyzer.tab.cpp"
    break;

  case 222: /* expr: SUPER '.' ID '(' optFactParams ')'  */
#line 472 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr(0, (yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), ParentMethodCall);  puts("expr created"); }
#line 3429 "synt_analyzer.tab.cpp"
    break;

  case 223: /* expr: expr RANGE expr  */
#line 473 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Range);  puts("expr created"); }
#line 3435 "synt_analyzer.tab.cpp"
    break;

  case 224: /* optFactParams: %empty  */
#line 476 "synt_analyzer.y"
                                {(yyval.factParamsListU) = 0;   puts("opt fact params created"); }
#line 3441 "synt_analyzer.tab.cpp"
    break;

  case 225: /* optFactParams: factParams  */
#line 477 "synt_analyzer.y"
                {(yyval.factParamsListU) = (yyvsp[0].factParamsListU);   puts("opt fact params created"); }
#line 3447 "synt_analyzer.tab.cpp"
    break;

  case 226: /* factParams: expr  */
#line 480 "synt_analyzer.y"
                        {(yyval.factParamsListU) = createFactParamsList((yyvsp[0].exprU));   puts("fact params created"); }
#line 3453 "synt_analyzer.tab.cpp"
    break;

  case 227: /* factParams: factParams ',' expr  */
#line 481 "synt_analyzer.y"
                        {(yyval.factParamsListU) = addToFactParamsList((yyvsp[-2].factParamsListU), (yyvsp[0].exprU));   puts("fact params created"); }
#line 3459 "synt_analyzer.tab.cpp"
    break;

  case 228: /* assignment: expr '=' expr  */
#line 484 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Assign); puts("assignment created"); }
#line 3465 "synt_analyzer.tab.cpp"
    break;

  case 229: /* assignment: expr ASUM expr  */
#line 485 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asum); puts("assignment created"); }
#line 3471 "synt_analyzer.tab.cpp"
    break;

  case 230: /* assignment: expr ASUB expr  */
#line 486 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asub); puts("assignment created"); }
#line 3477 "synt_analyzer.tab.cpp"
    break;

  case 231: /* assignment: expr ADIV expr  */
#line 487 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Adiv); puts("assignment created"); }
#line 3483 "synt_analyzer.tab.cpp"
    break;

  case 232: /* assignment: expr AMUL expr  */
#line 488 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amul); puts("assignment created"); }
#line 3489 "synt_analyzer.tab.cpp"
    break;

  case 233: /* assignment: expr AMOD expr  */
#line 489 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amod); puts("assignment created"); }
#line 3495 "synt_analyzer.tab.cpp"
    break;

  case 234: /* whileLoop: WHILE '(' expr ')' stmt  */
#line 492 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), (yyvsp[0].stmtU), 0); puts("whileLoop created"); }
#line 3501 "synt_analyzer.tab.cpp"
    break;

  case 235: /* whileLoop: WHILE '(' expr ')' block semis  */
#line 493 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), (yyvsp[-1].stmtListU), 0); puts("whileLoop created"); }
#line 3507 "synt_analyzer.tab.cpp"
    break;

  case 236: /* whileLoop: WHILE '(' expr ')' semis  */
#line 494 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 0); puts("whileLoop created"); }
#line 3513 "synt_analyzer.tab.cpp"
    break;

  case 237: /* whileLoop: WHILE '(' expr ')' block newLines  */
#line 495 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), (yyvsp[-1].stmtListU), 0); puts("whileLoop created"); }
#line 3519 "synt_analyzer.tab.cpp"
    break;

  case 238: /* whileLoop: WHILE '(' expr ')' newLines  */
#line 496 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 0); puts("whileLoop created"); }
#line 3525 "synt_analyzer.tab.cpp"
    break;

  case 239: /* doWhileLoop: DO expr WHILE '(' expr ')'  */
#line 499 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].exprU), 1); puts("doWhileLoop created"); }
#line 3531 "synt_analyzer.tab.cpp"
    break;

  case 240: /* doWhileLoop: DO block WHILE '(' expr ')'  */
#line 500 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-4].stmtListU), 1); puts("doWhileLoop created"); }
#line 3537 "synt_analyzer.tab.cpp"
    break;

  case 241: /* doWhileLoop: DO WHILE '(' expr ')'  */
#line 501 "synt_analyzer.y"
                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), 1); puts("doWhileLoop created"); }
#line 3543 "synt_analyzer.tab.cpp"
    break;

  case 242: /* forLoop: FOR '(' ID ':' type IN expr ')' stmt  */
#line 504 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].IdOrString), (yyvsp[-4].typeU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3549 "synt_analyzer.tab.cpp"
    break;

  case 243: /* forLoop: FOR '(' ID ':' type IN expr ')' block semis  */
#line 505 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-7].IdOrString), (yyvsp[-5].typeU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3555 "synt_analyzer.tab.cpp"
    break;

  case 244: /* forLoop: FOR '(' ID ':' type IN expr ')' semis  */
#line 506 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].IdOrString), (yyvsp[-4].typeU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3561 "synt_analyzer.tab.cpp"
    break;

  case 245: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' stmt  */
#line 507 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3567 "synt_analyzer.tab.cpp"
    break;

  case 246: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block semis  */
#line 508 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].formalParamsListU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3573 "synt_analyzer.tab.cpp"
    break;

  case 247: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' semis  */
#line 509 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3579 "synt_analyzer.tab.cpp"
    break;

  case 248: /* forLoop: FOR '(' ID ':' type IN expr ')' block newLines  */
#line 510 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-7].IdOrString), (yyvsp[-5].typeU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3585 "synt_analyzer.tab.cpp"
    break;

  case 249: /* forLoop: FOR '(' ID ':' type IN expr ')' newLines  */
#line 511 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].IdOrString), (yyvsp[-4].typeU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3591 "synt_analyzer.tab.cpp"
    break;

  case 250: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block newLines  */
#line 512 "synt_analyzer.y"
                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].formalParamsListU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3597 "synt_analyzer.tab.cpp"
    break;

  case 251: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' newLines  */
#line 513 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3603 "synt_analyzer.tab.cpp"
    break;

  case 252: /* ifStmt: IF '(' expr ')' stmt  */
#line 516 "synt_analyzer.y"
                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3609 "synt_analyzer.tab.cpp"
    break;

  case 253: /* ifStmt: IF '(' expr ')' semis  */
#line 517 "synt_analyzer.y"
                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3615 "synt_analyzer.tab.cpp"
    break;

  case 254: /* ifStmt: IF '(' expr ')' block semis  */
#line 518 "synt_analyzer.y"
                              {(yyval.ifStmtU) = createIfStmt((yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3621 "synt_analyzer.tab.cpp"
    break;

  case 255: /* ifStmt: IF '(' expr ')' expr ELSE stmt  */
#line 519 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3627 "synt_analyzer.tab.cpp"
    break;

  case 256: /* ifStmt: IF '(' expr ')' stmt ELSE stmt  */
#line 520 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3633 "synt_analyzer.tab.cpp"
    break;

  case 257: /* ifStmt: IF '(' expr ')' block ELSE stmt  */
#line 521 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3639 "synt_analyzer.tab.cpp"
    break;

  case 258: /* ifStmt: IF '(' expr ')' semis ELSE stmt  */
#line 522 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3645 "synt_analyzer.tab.cpp"
    break;

  case 259: /* ifStmt: IF '(' expr ')' expr ELSE block semis  */
#line 523 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3651 "synt_analyzer.tab.cpp"
    break;

  case 260: /* ifStmt: IF '(' expr ')' stmt ELSE block semis  */
#line 524 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3657 "synt_analyzer.tab.cpp"
    break;

  case 261: /* ifStmt: IF '(' expr ')' block ELSE block semis  */
#line 525 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtListU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3663 "synt_analyzer.tab.cpp"
    break;

  case 262: /* ifStmt: IF '(' expr ')' semis ELSE block semis  */
#line 526 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3669 "synt_analyzer.tab.cpp"
    break;

  case 263: /* ifStmt: IF '(' expr ')' expr ELSE semis  */
#line 527 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3675 "synt_analyzer.tab.cpp"
    break;

  case 264: /* ifStmt: IF '(' expr ')' stmt ELSE semis  */
#line 528 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU)); puts("ifStmt created"); }
#line 3681 "synt_analyzer.tab.cpp"
    break;

  case 265: /* ifStmt: IF '(' expr ')' block ELSE semis  */
#line 529 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU)); puts("ifStmt created"); }
#line 3687 "synt_analyzer.tab.cpp"
    break;

  case 266: /* ifStmt: IF '(' expr ')' newLines  */
#line 530 "synt_analyzer.y"
                           {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3693 "synt_analyzer.tab.cpp"
    break;

  case 267: /* ifStmt: IF '(' expr ')' block newLines  */
#line 531 "synt_analyzer.y"
                                 {(yyval.ifStmtU) = createIfStmt((yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3699 "synt_analyzer.tab.cpp"
    break;

  case 268: /* ifStmt: IF '(' expr ')' newLines ELSE stmt  */
#line 532 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3705 "synt_analyzer.tab.cpp"
    break;

  case 269: /* ifStmt: IF '(' expr ')' expr ELSE block newLines  */
#line 533 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3711 "synt_analyzer.tab.cpp"
    break;

  case 270: /* ifStmt: IF '(' expr ')' stmt ELSE block newLines  */
#line 534 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3717 "synt_analyzer.tab.cpp"
    break;

  case 271: /* ifStmt: IF '(' expr ')' block ELSE block newLines  */
#line 535 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtListU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3723 "synt_analyzer.tab.cpp"
    break;

  case 272: /* ifStmt: IF '(' expr ')' newLines ELSE block newLines  */
#line 536 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3729 "synt_analyzer.tab.cpp"
    break;

  case 273: /* ifStmt: IF '(' expr ')' expr ELSE newLines  */
#line 537 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3735 "synt_analyzer.tab.cpp"
    break;

  case 274: /* ifStmt: IF '(' expr ')' stmt ELSE newLines  */
#line 538 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtU)); puts("ifStmt created"); }
#line 3741 "synt_analyzer.tab.cpp"
    break;

  case 275: /* ifStmt: IF '(' expr ')' block ELSE newLines  */
#line 539 "synt_analyzer.y"
                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-4].exprU), (yyvsp[-2].stmtListU)); puts("ifStmt created"); }
#line 3747 "synt_analyzer.tab.cpp"
    break;

  case 280: /* semis: ';'  */
#line 550 "synt_analyzer.y"
                { puts("semis created"); }
#line 3753 "synt_analyzer.tab.cpp"
    break;

  case 281: /* semis: semis ';'  */
#line 551 "synt_analyzer.y"
                { puts("; added to semis"); }
#line 3759 "synt_analyzer.tab.cpp"
    break;

  case 282: /* semis: semis newLines  */
#line 552 "synt_analyzer.y"
                 { puts("newLines added to semis"); }
#line 3765 "synt_analyzer.tab.cpp"
    break;


#line 3769 "synt_analyzer.tab.cpp"

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

#line 556 "synt_analyzer.y"

//Секция пользовательского кода



void main(int argc, char **argv ){
	//yyin = fopen(argv[1], "r");
	yyin = fopen("easy_test.txt", "r");
	FILE * file = fopen("tree.dot", "w");
	root = 0;
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);

    return;
}

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
	#include "transform_root.h"
	void yyerror(const char* message) {
		fprintf(stderr, message);
	}
	int yylex();
	int yyparse();
	extern FILE* yyin;
	
	struct programS * root;
	list<ClassFile> classesFiles;

	

#line 88 "synt_analyzer.tab.cpp"

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
#define YYLAST   1751

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

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
       0,   194,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   218,   219,   220,   221,   222,   223,
     224,   225,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   242,   243,   244,   245,   248,   249,
     250,   251,   252,   253,   256,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   274,   275,   278,
     279,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   338,   340,   342,   344,
     346,   348,   349,   350,   352,   356,   357,   358,   359,   363,
     364,   367,   368,   372,   376,   377,   378,   379,   380,   381,
     385,   386,   387,   391,   392,   393,   396,   397,   400,   403,
     404,   405,   406,   409,   410,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     472,   473,   476,   477,   480,   481,   482,   483,   484,   485,
     488,   489,   490,   491,   494,   495,   496,   499,   500,   501,
     502,   503,   504,   505,   506,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   531,   532,   535,   536,   539,
     540,   541
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

#define YYPACT_NINF (-281)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-267)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     579,  -281,    29,  -281,  -281,  -281,  -281,   217,   230,    38,
      22,    35,  -281,  -281,  -281,   663,    37,  -281,    24,   272,
      57,    37,     9,    15,    15,    59,    20,    -2,   255,   116,
     157,   255,    21,   290,   -46,   -35,    68,   -17,    68,  -281,
      37,  -281,   272,    15,    15,  -281,    59,    88,    37,     9,
     281,   105,    66,    15,    15,   294,   299,    73,  -281,  1373,
    -281,    52,    18,    20,    59,    20,    59,    20,  -281,  -281,
    -281,   137,   711,    94,   223,    94,   124,   223,   129,    94,
     223,    94,   143,   223,   153,    68,   170,    90,   -64,   170,
     -55,  -281,    15,    15,    59,    20,    59,    20,    70,  -281,
      18,    20,    94,   158,    94,   177,   180,   182,    59,    20,
      59,    20,   223,   183,   223,   186,   191,   203,   146,  -281,
    -281,   150,  -281,  -281,  -281,  -281,  -281,  1373,  1373,  1373,
    1373,  1630,   801,   145,   174,    37,  -281,  1145,    15,  -281,
      37,  -281,    49,    43,  -281,  -281,    59,    20,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
     169,   151,   190,   175,  -281,   170,   178,   282,   181,   187,
      59,    20,    59,    20,   284,   944,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  1373,   288,
     -69,   -69,   -69,  1446,  1373,  1373,  1373,  1373,  1373,  1373,
    1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,
     301,  1373,   220,    37,   224,   225,    15,    15,    79,  -281,
      15,    15,  1099,  -281,   421,    15,  -281,    15,  -281,  -281,
    1027,   872,   984,    68,  -281,  -281,    15,  -281,    37,  -281,
      59,    20,  -281,  -281,  -281,   227,   213,   329,  1373,  -281,
    1373,   238,  1373,  1373,   245,  -281,  1345,  1630,   242,   246,
     254,  -281,   740,  1651,   795,   795,   795,   795,   392,   392,
     392,   392,   442,   287,   287,   -69,   -69,   -69,   257,  1422,
    1373,    37,  1266,  1373,    42,    59,    20,    59,    20,   120,
      59,    20,    59,    20,    59,    20,  -281,  -281,  1373,  1373,
    1373,  1373,  1373,  1373,    59,    20,    59,    20,    59,    20,
    -281,  1158,  -281,  1217,  -281,  1381,   258,    59,    20,  -281,
      68,   170,   190,  -281,   -60,  1630,  1630,   170,  1630,  1630,
     998,  -281,  -281,  1373,  1373,  1373,  -281,  1469,   305,   261,
    1153,  1492,   260,    68,    59,    20,  1630,  1630,  1630,  1630,
    1630,  1630,  -281,  -281,  -281,    10,   266,  -281,  -281,   352,
    -281,  -281,  1395,  1630,   268,   269,    15,   271,  1373,   322,
      15,   170,     0,   144,    37,    52,    34,   190,  -281,  -281,
    -281,  -281,    15,  1276,    26,    12,  1373,  1515,   273,    15,
    1276,    20,   323,   324,   292,   295,  -281,   149,    37,    52,
     341,    20,   342,   710,    37,    37,  1538,  -281,  1373,    59,
      20,  -281,  1373,  1373,  1373,  1373,   296,   298,  -281,    15,
      15,    15,    37,  1276,   285,  1276,  -281,  1561,  1584,  1607,
     300,   302,  1373,  1373,    15,  1276,    20,    15,  1276,    20,
      15,  1276,    20,    59,  -281,    20,  -281,  -281,    15,    15,
      37,    37,   303,   307,    59,    20,  -281,    59,    20,  -281,
      59,    20,  -281,    15,  1276,    20,    15,  1276,    20,    37,
      52,    37,    52,    37,    37,    59,    20,  -281,    59,    20,
    -281,  -281,  -281,    37,    52,    37,    52,  -281,  -281
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   267,     0,   135,   136,   138,   137,    71,    74,     0,
       0,     0,   140,   139,   269,     0,   265,     5,     0,    72,
      73,   265,   265,     0,     0,     3,     2,     0,    77,    75,
      76,    84,    85,    86,     0,     0,     0,     0,     0,     1,
     265,    15,    72,     0,     0,     4,   266,     0,   265,   265,
      78,    80,    79,     0,     0,    81,    83,    82,    53,     0,
     141,     0,    52,    51,    11,     7,    10,     6,   268,   271,
     270,     0,     0,    91,    92,    88,    87,    90,    89,   106,
     105,   107,   108,   109,   110,    67,     0,     0,     0,     0,
       0,    14,     0,     0,    21,    17,    20,    16,     0,    50,
      49,    48,    94,    93,    98,    97,    95,    96,    13,     9,
      12,     8,   100,    99,   104,   103,   102,   101,   187,   186,
     188,     0,   190,   191,   193,   192,   194,     0,     0,     0,
       0,   142,     0,     0,     0,   265,    31,     0,     0,    34,
     265,    37,     0,    72,    47,    46,    33,    32,   115,   116,
     112,   111,   114,   113,   130,   129,   131,   132,   133,   134,
       0,    68,   156,   150,   157,     0,     0,     0,   153,     0,
      23,    19,    22,    18,     0,     0,   118,   117,   122,   121,
     119,   120,   124,   123,   128,   127,   126,   125,   220,     0,
     197,   198,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   163,     0,     0,   168,     0,   170,   171,
       0,     0,     0,    67,    54,    27,     0,    39,   265,    42,
      36,    35,    38,    45,    44,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,    29,     0,   222,     0,   221,
     217,   195,   206,   207,   208,   209,   210,   211,   212,   213,
     204,   205,   219,   199,   200,   202,   201,   203,   214,     0,
       0,   265,     0,     0,     0,   182,   173,   183,   174,     0,
     184,   175,   178,   166,   177,   165,   146,   164,     0,     0,
       0,     0,     0,     0,   181,   172,   179,   167,   180,   169,
     148,     0,   145,     0,    30,     0,     0,    41,    40,    43,
      67,     0,   159,   160,     0,   151,   152,     0,   154,   155,
       0,    25,   189,     0,   220,   220,   216,     0,     0,     0,
     265,     0,     0,     0,   185,   176,   225,   226,   227,   228,
     229,   224,   147,   144,    26,   265,     0,   143,   158,     0,
      70,    28,     0,   223,     0,     0,   265,     0,     0,     0,
     265,     0,     0,     0,   265,    62,   265,   161,   162,    24,
     218,   215,   265,     0,   266,   246,     0,     0,     0,     0,
       0,   232,     0,     0,     0,     0,    61,     0,   265,    56,
     259,   247,   245,     0,   265,   265,     0,   236,     0,   233,
     231,   230,     0,     0,   220,   220,     0,     0,    55,   265,
     265,   265,     0,     0,     0,     0,   235,     0,     0,     0,
       0,     0,   220,   220,     0,     0,   258,     0,     0,   257,
       0,     0,   256,   264,   260,   255,   251,   234,   265,   265,
     265,   265,     0,     0,   263,   254,   250,   262,   253,   249,
     261,   252,   248,     0,     0,   239,     0,     0,   242,   265,
      64,   265,    63,   265,   265,   243,   238,   237,   244,   241,
     240,    66,    65,   265,    58,   265,    57,    60,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -281,  -281,   385,  -172,  -128,     2,  -127,  -126,  -176,   -32,
      36,   660,   562,   -11,   -10,   -76,     1,    19,   -67,  -233,
    -281,   -15,   139,   349,  -280,  -281,  -281,  -281,  -281,  -281,
    -281,   -16,    53,    25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,   137,   138,   139,   140,   141,   160,   161,
     142,   143,    20,    21,    22,    60,   220,   221,   163,   164,
     324,   222,   223,   224,   258,   259,   225,   226,   227,   228,
     229,    61,    46,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    23,    17,   256,    88,    58,    90,    48,    49,   236,
     238,   239,     1,     1,   323,    69,    43,    41,     1,    24,
      53,    68,   168,    69,    91,    26,    35,   358,   210,    68,
      47,   211,    99,    27,    44,   166,    18,     1,    54,    37,
       1,   167,    34,    92,   169,   359,   342,    63,    65,    67,
     167,    18,    85,    25,   364,   365,   405,   316,    81,   234,
     315,    93,    68,     9,     3,     4,     5,    86,    95,    97,
     404,   245,    87,   144,   101,    62,    64,    66,   109,   111,
      50,    51,     1,   118,   119,    89,    12,    13,     9,    10,
      11,   145,    98,     6,    55,    56,    94,    96,   249,   393,
      71,    72,   100,   106,   107,   167,   108,   110,    12,    13,
     116,   117,   373,   120,   121,    59,    14,   171,   173,    70,
      36,  -266,    14,     1,   242,   146,   378,    70,   236,   238,
     239,    48,    49,    38,   430,   431,   397,   281,   144,   237,
     343,   133,   104,   243,   356,   170,   172,   122,   123,   124,
     125,   126,   452,   453,    75,   132,   145,   231,   362,    12,
      13,   244,   151,   241,     3,     4,     5,   153,   127,   128,
      12,    13,   174,   175,   162,   129,   144,   130,   394,   395,
     157,    12,    13,   416,   417,   230,    14,   236,   238,   239,
     159,   240,   165,     6,   145,    77,   177,   282,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   179,   311,   313,   210,   180,   181,
     211,   183,   319,   185,     3,     4,     5,    14,   146,   186,
       3,     4,     5,   144,   236,   238,   239,     3,     4,     5,
     187,   286,   288,   291,   188,   293,   295,   189,   232,   305,
     307,   145,   309,     6,   357,    28,   167,   144,   237,     6,
     360,   318,     3,     4,     5,   338,     6,    31,   246,   285,
     287,   290,   233,   292,   294,   145,   247,   304,   306,   374,
     308,   248,    12,    13,   250,   146,   251,   252,   254,   317,
     382,     6,   260,   253,   389,    12,    13,     3,     4,     5,
     398,     3,     4,     5,   392,   278,     3,     4,     5,    50,
      51,   372,    10,    11,   345,   321,   144,   237,   280,   102,
      12,    13,   283,   284,   369,   320,     6,    83,   422,   424,
       6,   144,   112,   322,   145,     6,   114,    12,    13,   375,
     327,   332,   344,   434,   437,   440,    12,    13,   330,   145,
     383,   333,   334,   367,   390,   335,   377,   355,   396,   368,
     399,   297,   371,   144,   237,   376,   400,   380,   381,   386,
     388,   408,   463,   466,   469,   471,   412,   413,   207,   208,
     209,   145,   418,   146,   210,   419,   420,   211,   423,   425,
     414,   385,    14,   415,   432,   391,   433,   483,   485,   450,
      40,   451,   473,   435,   438,   441,   474,   401,   131,     0,
       0,     0,     0,     0,   410,     0,     0,     0,     0,   384,
       0,     0,     0,     0,     1,     0,     0,     0,   305,     0,
       0,     0,   464,   467,   470,   472,     0,     0,     0,     0,
       0,     0,   409,     0,   436,   439,   442,     0,     0,   445,
     297,     0,   297,   481,     0,   482,   304,   484,   486,   455,
       0,     0,   458,     0,     0,   461,     0,   487,     0,   488,
       0,     0,     0,   465,   468,   443,   190,   191,   192,   193,
     204,   205,   206,   207,   208,   209,     0,   454,   476,   210,
     457,   479,   211,   460,   298,   299,   300,   301,   302,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   475,     0,   210,   478,
       0,   211,   402,     0,     0,     0,     0,   303,    14,   411,
    -267,   205,   206,   207,   208,   209,     0,   257,     0,   210,
       0,     0,   211,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
     279,     0,   444,     0,   446,     0,     0,   289,     0,    30,
      33,     0,     0,     0,   456,     0,     0,   459,     0,     0,
     462,    52,     1,     0,     0,     2,     3,     4,     5,     0,
      74,    76,     0,    80,    82,     0,     0,   325,     0,   326,
       0,   328,   329,   477,    52,     0,   480,     0,     0,     0,
       0,     0,   103,   105,     0,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,   337,
       0,   340,   341,     0,     0,   148,     0,   150,     0,     0,
       0,   154,     0,   156,    12,    13,     0,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,    39,   176,     0,   178,    29,    32,     2,
       3,     4,     5,     0,     0,    42,     0,     0,     0,     0,
      57,     0,   363,   257,   257,     0,    14,     0,    73,     0,
      78,    79,     0,    84,     0,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    52,     0,     0,     0,     0,
       0,     0,     0,     1,     1,   113,   115,   387,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,     0,   403,     0,   149,   406,     0,   152,     0,   134,
     155,     0,   135,   158,     0,     0,     0,     6,     7,     8,
       9,    10,    11,     0,   421,     0,     0,   427,     0,     0,
       0,   428,   429,   257,   257,     0,     0,     0,     0,     0,
       0,     0,   182,     0,   184,     0,    12,    13,     0,     0,
       0,   257,   257,   298,   299,   300,   301,   302,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     1,   118,   119,   210,     0,     0,
     211,     0,     0,     0,     0,   136,   303,    14,    14,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   120,   121,   210,     0,     0,
     211,    10,    11,     0,   212,     0,     0,     0,   213,   214,
     215,   216,   217,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   126,     0,    69,   118,   119,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     127,   128,   210,     0,     0,   211,     0,   129,     0,   130,
       0,     0,     0,     0,     0,   219,   120,   121,    14,     0,
       0,     0,    10,    11,     0,   212,     0,     0,     0,   213,
     214,   215,   216,   217,     0,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,     0,     0,     1,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,   129,     0,
     130,     0,   134,     0,     0,   135,   312,     0,     0,    70,
       6,     7,     8,     9,    10,    11,     0,     1,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     3,     4,     5,     0,    12,
      13,     0,   134,     0,     0,   135,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,   134,     0,     0,   135,
      68,   118,   119,     0,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,   255,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,    12,    13,     0,     0,    10,    11,     0,
     212,     0,     0,     0,   213,   214,   215,   216,   217,     0,
       0,     0,     0,   218,     0,     0,     0,     0,   314,     0,
       0,    14,     0,     0,     0,   122,   123,   124,   125,   126,
       0,     0,   361,   118,   119,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,   129,     0,   130,     0,     0,     0,     0,
       0,   310,     0,   120,   121,     0,     0,     0,     0,    10,
      11,     0,   212,     0,     0,     0,   213,   214,   215,   216,
     217,     0,     3,     4,     5,   218,     1,     0,     0,     0,
       0,     0,   118,   119,     0,     0,     0,   122,   123,   124,
     125,   126,     0,   134,     0,     0,   135,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,     0,   127,   128,
       0,     0,   120,   121,     0,   129,     0,   130,    10,    11,
       0,   212,     0,   296,     0,   213,   214,   215,   216,   217,
      12,    13,     0,     0,   218,     0,     0,     0,     0,     0,
       0,   118,   119,     0,     0,     0,   122,   123,   124,   125,
     126,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   127,   128,   235,
     210,   120,   121,   211,   129,     0,   130,    10,    11,     0,
     212,     0,   352,     0,   213,   214,   215,   216,   217,     0,
     118,   119,     0,   218,     0,     0,     0,     0,     0,     0,
     118,   119,     0,     0,     0,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,     0,     0,   127,   128,     0,     0,
     120,   121,     0,   129,   339,   130,    10,    11,     0,   212,
       0,   353,     0,   213,   214,   215,   216,   217,     0,     0,
       0,     0,   218,     0,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,     0,
       0,     0,     3,     4,     5,   127,   128,     0,     0,     0,
       0,     0,   129,     0,   130,   127,   128,     0,     0,   132,
       0,     0,   129,   134,   130,     0,   135,   118,   119,   132,
       0,     6,     7,     8,     9,    10,    11,     0,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     0,     0,   120,   121,   134,
      12,    13,   135,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,   134,     0,     0,   135,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
       0,   122,   123,   124,   125,   126,    12,    13,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,   127,   128,     0,     0,     0,     0,     0,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,   210,
       0,     0,   211,   336,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,     0,     0,   210,     0,   261,   211,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,     0,     0,   210,     0,   366,   211,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,   210,
       0,   370,   211,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
       0,     0,   210,     0,   407,   211,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,     0,     0,   210,     0,   426,   211,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,     0,     0,   210,     0,
     447,   211,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,     0,
       0,   210,     0,   448,   211,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,     0,     0,   210,     0,   449,   211,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,     0,     0,   210,     0,     0,
     211,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,     0,     0,   210,     0,
       0,   211
};

static const yytype_int16 yycheck[] =
{
      16,     0,     0,   175,    36,    21,    38,    18,    18,   137,
     137,   137,     3,     3,   247,     3,    15,    15,     3,     0,
      19,     3,    89,     3,    40,     0,     4,    87,    97,     3,
       6,   100,    48,     4,    15,    99,     0,     3,    19,     4,
       3,   105,     4,    42,    99,   105,     4,    22,    23,    24,
     105,    15,    98,     0,   334,   335,    44,   233,    37,   135,
     232,    42,     3,    39,     7,     8,     9,   102,    43,    44,
      44,    28,     4,    72,    49,    22,    23,    24,    53,    54,
      37,    38,     3,     4,     5,   102,    65,    66,    39,    40,
      41,    72,     4,    36,    37,    38,    43,    44,   165,    99,
     102,   103,    49,    37,    38,   105,    53,    54,    65,    66,
      37,    38,   102,    34,    35,   106,   107,    92,    93,   107,
      98,   103,   107,     3,   140,    72,   359,   107,   256,   256,
     256,   142,   142,    98,   414,   415,   102,   213,   137,   137,
      98,     4,    37,   142,   320,    92,    93,    68,    69,    70,
      71,    72,   432,   433,    38,   103,   137,   132,   330,    65,
      66,   142,    38,   138,     7,     8,     9,    38,    89,    90,
      65,    66,   102,   103,     4,    96,   175,    98,    34,    35,
      37,    65,    66,    34,    35,   132,   107,   315,   315,   315,
      37,   138,   102,    36,   175,    38,    38,   213,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    37,   230,   231,    97,    38,    37,
     100,    38,   238,    37,     7,     8,     9,   107,   175,    38,
       7,     8,     9,   232,   362,   362,   362,     7,     8,     9,
      37,   216,   217,   218,    98,   220,   221,    97,   103,   224,
     225,   232,   227,    36,   321,    38,   105,   256,   256,    36,
     327,   236,     7,     8,     9,   281,    36,    37,    99,   216,
     217,   218,    98,   220,   221,   256,    86,   224,   225,   355,
     227,   106,    65,    66,   106,   232,     4,   106,     4,   236,
     366,    36,     4,   106,   370,    65,    66,     7,     8,     9,
     376,     7,     8,     9,   371,     4,     7,     8,     9,    37,
      38,   343,    40,    41,   289,   102,   315,   315,    98,    38,
      65,    66,    98,    98,   340,    98,    36,    37,   404,   405,
      36,   330,    38,     4,   315,    36,    37,    65,    66,   355,
     102,    99,   289,   419,   420,   421,    65,    66,   103,   330,
     366,   105,    98,    48,   370,    98,     4,    99,   374,    98,
     376,   222,   102,   362,   362,    99,   382,    99,    99,    98,
      48,    98,   448,   449,   450,   451,    53,    53,    91,    92,
      93,   362,   398,   330,    97,    44,    44,   100,   404,   405,
      98,   366,   107,    98,    98,   370,    98,   473,   474,    99,
      15,    99,    99,   419,   420,   421,    99,   382,    59,    -1,
      -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,   403,    -1,
      -1,    -1,   448,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    -1,   389,    -1,   419,   420,   421,    -1,    -1,   424,
     311,    -1,   313,   469,    -1,   471,   403,   473,   474,   434,
      -1,    -1,   437,    -1,    -1,   440,    -1,   483,    -1,   485,
      -1,    -1,    -1,   448,   449,   422,   127,   128,   129,   130,
      88,    89,    90,    91,    92,    93,    -1,   434,   463,    97,
     437,   466,   100,   440,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,   463,    -1,    97,   466,
      -1,   100,   383,    -1,    -1,    -1,    -1,   106,   107,   390,
      88,    89,    90,    91,    92,    93,    -1,   188,    -1,    97,
      -1,    -1,   100,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,    -1,   423,    -1,   425,    -1,    -1,   218,    -1,     7,
       8,    -1,    -1,    -1,   435,    -1,    -1,   438,    -1,    -1,
     441,    19,     3,    -1,    -1,     6,     7,     8,     9,    -1,
      28,    29,    -1,    31,    32,    -1,    -1,   248,    -1,   250,
      -1,   252,   253,   464,    42,    -1,   467,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,
      -1,   282,   283,    -1,    -1,    73,    -1,    75,    -1,    -1,
      -1,    79,    -1,    81,    65,    66,    -1,   298,   299,   300,
     301,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,    -1,    -1,     0,   102,    -1,   104,     7,     8,     6,
       7,     8,     9,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    -1,   333,   334,   335,    -1,   107,    -1,    28,    -1,
      30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     3,    55,    56,   368,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    -1,   383,    -1,    74,   386,    -1,    77,    -1,    28,
      80,    -1,    31,    83,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    44,    -1,    -1,   408,    -1,    -1,
      -1,   412,   413,   414,   415,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,   114,    -1,    65,    66,    -1,    -1,
      -1,   432,   433,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     3,     4,     5,    97,    -1,    -1,
     100,    -1,    -1,    -1,    -1,   104,   106,   107,   107,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    34,    35,    97,    -1,    -1,
     100,    40,    41,    -1,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    -1,     3,     4,     5,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      89,    90,    97,    -1,    -1,   100,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,   104,    34,    35,   107,    -1,
      -1,    -1,    40,    41,    -1,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    -1,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    -1,    28,    -1,    -1,    31,   104,    -1,    -1,   107,
      36,    37,    38,    39,    40,    41,    -1,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,     7,     8,     9,    -1,    65,
      66,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
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
      51,    -1,     7,     8,     9,    56,     3,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    89,    90,
      -1,    -1,    34,    35,    -1,    96,    -1,    98,    40,    41,
      -1,    43,    -1,   104,    -1,    47,    48,    49,    50,    51,
      65,    66,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    89,    90,   104,
      97,    34,    35,   100,    96,    -1,    98,    40,    41,    -1,
      43,    -1,   104,    -1,    47,    48,    49,    50,    51,    -1,
       4,     5,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      34,    35,    -1,    96,    48,    98,    40,    41,    -1,    43,
      -1,   104,    -1,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,
      -1,    -1,     7,     8,     9,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    89,    90,    -1,    -1,   103,
      -1,    -1,    96,    28,    98,    -1,    31,     4,     5,   103,
      -1,    36,    37,    38,    39,    40,    41,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,     8,     9,    -1,    -1,    34,    35,    28,
      65,    66,    31,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    28,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    65,    66,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,   101,    78,    79,    80,    81,    82,    83,
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
      -1,    97,    -1,    99,   100,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    99,   100,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
     100,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    36,    37,    38,    39,
      40,    41,    65,    66,   107,   109,   110,   113,   118,   119,
     120,   121,   122,   124,   125,   140,   141,     4,    38,   119,
     120,    37,   119,   120,     4,     4,    98,     4,    98,     0,
     110,   113,   119,   124,   125,   139,   140,     6,   121,   122,
      37,    38,   120,   124,   125,    37,    38,   119,   139,   106,
     123,   139,   140,   141,   140,   141,   140,   141,     3,     3,
     107,   102,   103,   119,   120,    38,   120,    38,   119,   119,
     120,    37,   120,    37,   119,    98,   102,     4,   117,   102,
     117,   139,   124,   125,   140,   141,   140,   141,     4,   139,
     140,   141,    38,   120,    37,   120,    37,    38,   140,   141,
     140,   141,    38,   119,    37,   119,    37,    38,     4,     5,
      34,    35,    68,    69,    70,    71,    72,    89,    90,    96,
      98,   131,   103,     4,    28,    31,   104,   111,   112,   113,
     114,   115,   118,   119,   124,   125,   140,   141,   120,   119,
     120,    38,   119,    38,   120,   119,   120,    37,   119,    37,
     116,   117,     4,   126,   127,   102,    99,   105,   126,    99,
     140,   141,   140,   141,   102,   103,   120,    38,   120,    37,
      38,    37,   119,    38,   119,    37,    38,    37,    98,    97,
     131,   131,   131,   131,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      97,   100,    43,    47,    48,    49,    50,    51,    56,   104,
     124,   125,   129,   130,   131,   134,   135,   136,   137,   138,
     140,   141,   103,    98,   123,   104,   112,   113,   114,   115,
     140,   141,   139,   124,   125,    28,    99,    86,   106,   126,
     106,     4,   106,   106,     4,   104,   111,   131,   132,   133,
       4,    99,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,     4,   131,
      98,   123,   139,    98,    98,   140,   141,   140,   141,   131,
     140,   141,   140,   141,   140,   141,   104,   130,    73,    74,
      75,    76,    77,   106,   140,   141,   140,   141,   140,   141,
     104,   129,   104,   129,   104,   111,   116,   140,   141,   139,
      98,   102,     4,   127,   128,   131,   131,   102,   131,   131,
     103,   104,    99,   105,    98,    98,   101,   131,   139,    48,
     131,   131,     4,    98,   140,   141,   131,   131,   131,   131,
     131,   131,   104,   104,   104,    99,   116,   126,    87,   105,
     126,   104,   111,   131,   132,   132,    99,    48,    98,   139,
      99,   102,   117,   102,   123,   139,    99,     4,   127,   104,
      99,    99,   123,   139,   140,   141,    98,   131,    48,   123,
     139,   141,   126,    99,    34,    35,   139,   102,   123,   139,
     139,   141,   130,   131,    44,    44,   131,    99,    98,   140,
     141,   130,    53,    53,    98,    98,    34,    35,   139,    44,
      44,    44,   123,   139,   123,   139,    99,   131,   131,   131,
     132,   132,    98,    98,   123,   139,   141,   123,   139,   141,
     123,   139,   141,   140,   130,   141,   130,    99,    99,    99,
      99,    99,   132,   132,   140,   141,   130,   140,   141,   130,
     140,   141,   130,   123,   139,   141,   123,   139,   141,   123,
     139,   123,   139,    99,    99,   140,   141,   130,   140,   141,
     130,   139,   139,   123,   139,   123,   139,   139,   139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   113,   113,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   125,   126,   126,   127,   128,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   139,   139,   140,   140,   141,
     141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     3,     3,
       2,     2,     3,     3,     3,     2,     3,     3,     4,     4,
       3,     3,     4,     4,     8,     6,     7,     5,     7,     5,
       6,     4,     1,     1,     1,     2,     2,     1,     2,     2,
       3,     3,     2,     3,     2,     2,     1,     1,     3,     3,
       3,     2,     2,     2,     2,     7,     6,    11,    11,    12,
      12,     6,     5,    10,    10,    11,    11,     0,     1,     3,
       5,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     2,     3,     7,     5,     4,     4,     5,     4,     3,
       4,     6,     6,     4,     6,     6,     1,     1,     4,     1,
       1,     3,     3,     1,     2,     2,     2,     2,     1,     2,
       1,     1,     2,     2,     2,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     4,     3,     6,     3,
       0,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       6,     6,     5,     6,     8,     7,     6,    10,    10,     9,
      10,    10,     9,    10,    10,     6,     5,     6,     9,     9,
       9,     8,     9,     9,     9,     8,     8,     8,     8,     6,
       8,     9,     9,     9,     8,     0,     1,     1,     2,     1,
       2,     2
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
#line 2086 "synt_analyzer.tab.cpp"
    break;

  case 3: /* program: newLines  */
#line 195 "synt_analyzer.y"
           {root = createProgram(); puts("program created");}
#line 2092 "synt_analyzer.tab.cpp"
    break;

  case 4: /* program: class optNewLines  */
#line 196 "synt_analyzer.y"
                        {root = createProgram((yyvsp[-1].classU));puts("program created");}
#line 2098 "synt_analyzer.tab.cpp"
    break;

  case 5: /* program: method  */
#line 197 "synt_analyzer.y"
                {root = createProgram((yyvsp[0].methodU));puts("program created");}
#line 2104 "synt_analyzer.tab.cpp"
    break;

  case 6: /* program: valDeclaration semis  */
#line 198 "synt_analyzer.y"
                        {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2110 "synt_analyzer.tab.cpp"
    break;

  case 7: /* program: varDeclaration semis  */
#line 199 "synt_analyzer.y"
                        {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2116 "synt_analyzer.tab.cpp"
    break;

  case 8: /* program: visibilityModifier valDeclaration semis  */
#line 200 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2122 "synt_analyzer.tab.cpp"
    break;

  case 9: /* program: visibilityModifier varDeclaration semis  */
#line 201 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2128 "synt_analyzer.tab.cpp"
    break;

  case 10: /* program: valDeclaration newLines  */
#line 202 "synt_analyzer.y"
                                {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2134 "synt_analyzer.tab.cpp"
    break;

  case 11: /* program: varDeclaration newLines  */
#line 203 "synt_analyzer.y"
                                {root = createProgram(createProperty((yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2140 "synt_analyzer.tab.cpp"
    break;

  case 12: /* program: visibilityModifier valDeclaration newLines  */
#line 204 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2146 "synt_analyzer.tab.cpp"
    break;

  case 13: /* program: visibilityModifier varDeclaration newLines  */
#line 205 "synt_analyzer.y"
                                                {root = createProgram(createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("program created");}
#line 2152 "synt_analyzer.tab.cpp"
    break;

  case 14: /* program: program class optNewLines  */
#line 206 "synt_analyzer.y"
                                {root = addToProgram(root, (yyvsp[-1].classU));puts("class added to prog");}
#line 2158 "synt_analyzer.tab.cpp"
    break;

  case 15: /* program: program method  */
#line 207 "synt_analyzer.y"
                        {root = addToProgram(root, (yyvsp[0].methodU));puts("meth added to prog");}
#line 2164 "synt_analyzer.tab.cpp"
    break;

  case 16: /* program: program valDeclaration semis  */
#line 208 "synt_analyzer.y"
                                {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2170 "synt_analyzer.tab.cpp"
    break;

  case 17: /* program: program varDeclaration semis  */
#line 209 "synt_analyzer.y"
                                {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2176 "synt_analyzer.tab.cpp"
    break;

  case 18: /* program: program visibilityModifier valDeclaration semis  */
#line 210 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2182 "synt_analyzer.tab.cpp"
    break;

  case 19: /* program: program visibilityModifier varDeclaration semis  */
#line 211 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2188 "synt_analyzer.tab.cpp"
    break;

  case 20: /* program: program valDeclaration newLines  */
#line 212 "synt_analyzer.y"
                                        {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2194 "synt_analyzer.tab.cpp"
    break;

  case 21: /* program: program varDeclaration newLines  */
#line 213 "synt_analyzer.y"
                                        {root = addToProgram(root, createProperty((yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2200 "synt_analyzer.tab.cpp"
    break;

  case 22: /* program: program visibilityModifier valDeclaration newLines  */
#line 214 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2206 "synt_analyzer.tab.cpp"
    break;

  case 23: /* program: program visibilityModifier varDeclaration newLines  */
#line 215 "synt_analyzer.y"
                                                        {root = addToProgram(root, createProperty(createModifiers(0, 0, (yyvsp[-2].visibilityModU), None), (yyvsp[-1].varOrValDeclU)));puts("prop added to prog");}
#line 2212 "synt_analyzer.tab.cpp"
    break;

  case 24: /* class: modifiers CLASS ID ':' ID '{' classBody '}'  */
#line 218 "synt_analyzer.y"
                                                        {(yyval.classU) = createClass((yyvsp[-7].modifiersU), (yyvsp[-5].IdOrString), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU));puts("class created");}
#line 2218 "synt_analyzer.tab.cpp"
    break;

  case 25: /* class: modifiers CLASS ID '{' classBody '}'  */
#line 219 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].modifiersU), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2224 "synt_analyzer.tab.cpp"
    break;

  case 26: /* class: CLASS ID ':' ID '{' classBody '}'  */
#line 220 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-5].IdOrString), (yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2230 "synt_analyzer.tab.cpp"
    break;

  case 27: /* class: CLASS ID '{' classBody '}'  */
#line 221 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-3].IdOrString), (yyvsp[-1].classBodyU)); puts("class created");}
#line 2236 "synt_analyzer.tab.cpp"
    break;

  case 28: /* class: modifiers CLASS ID ':' ID '{' '}'  */
#line 222 "synt_analyzer.y"
                                        {(yyval.classU) = createClass((yyvsp[-6].modifiersU), (yyvsp[-4].IdOrString), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2242 "synt_analyzer.tab.cpp"
    break;

  case 29: /* class: modifiers CLASS ID '{' '}'  */
#line 223 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].modifiersU), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2248 "synt_analyzer.tab.cpp"
    break;

  case 30: /* class: CLASS ID ':' ID '{' '}'  */
#line 224 "synt_analyzer.y"
                                {(yyval.classU) = createClass((yyvsp[-4].IdOrString), (yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2254 "synt_analyzer.tab.cpp"
    break;

  case 31: /* class: CLASS ID '{' '}'  */
#line 225 "synt_analyzer.y"
                        {(yyval.classU) = createClass((yyvsp[-2].IdOrString), createClassBody()); puts("class created");}
#line 2260 "synt_analyzer.tab.cpp"
    break;

  case 32: /* classBody: semis  */
#line 228 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2266 "synt_analyzer.tab.cpp"
    break;

  case 33: /* classBody: newLines  */
#line 229 "synt_analyzer.y"
                {(yyval.classBodyU) = createClassBody(); puts("class body created");}
#line 2272 "synt_analyzer.tab.cpp"
    break;

  case 34: /* classBody: method  */
#line 230 "synt_analyzer.y"
         {(yyval.classBodyU) = createClassBody((yyvsp[0].methodU));  puts("class body created");}
#line 2278 "synt_analyzer.tab.cpp"
    break;

  case 35: /* classBody: property semis  */
#line 231 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2284 "synt_analyzer.tab.cpp"
    break;

  case 36: /* classBody: property newLines  */
#line 232 "synt_analyzer.y"
                        {(yyval.classBodyU) = createClassBody((yyvsp[-1].propertyU));  puts("class body created");}
#line 2290 "synt_analyzer.tab.cpp"
    break;

  case 37: /* classBody: constructor  */
#line 233 "synt_analyzer.y"
              {(yyval.classBodyU) = createClassBody((yyvsp[0].constructorU));  puts("class body created");}
#line 2296 "synt_analyzer.tab.cpp"
    break;

  case 38: /* classBody: initializer optNewLines  */
#line 234 "synt_analyzer.y"
                                {(yyval.classBodyU) = createClassBody((yyvsp[-1].initializerU));  puts("class body created");}
#line 2302 "synt_analyzer.tab.cpp"
    break;

  case 39: /* classBody: classBody method  */
#line 235 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].methodU));  puts("meth added to class body");}
#line 2308 "synt_analyzer.tab.cpp"
    break;

  case 40: /* classBody: classBody property semis  */
#line 236 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2314 "synt_analyzer.tab.cpp"
    break;

  case 41: /* classBody: classBody property newLines  */
#line 237 "synt_analyzer.y"
                                {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].propertyU)); puts("prop added to class body");}
#line 2320 "synt_analyzer.tab.cpp"
    break;

  case 42: /* classBody: classBody constructor  */
#line 238 "synt_analyzer.y"
                        {(yyval.classBodyU) = addToClassBody((yyvsp[-1].classBodyU), (yyvsp[0].constructorU)); puts("constr added to class body");}
#line 2326 "synt_analyzer.tab.cpp"
    break;

  case 43: /* classBody: classBody initializer optNewLines  */
#line 239 "synt_analyzer.y"
                                        {(yyval.classBodyU) = addToClassBody((yyvsp[-2].classBodyU), (yyvsp[-1].initializerU)); puts("init added to class body");}
#line 2332 "synt_analyzer.tab.cpp"
    break;

  case 44: /* property: modifiers valDeclaration  */
#line 242 "synt_analyzer.y"
                                        {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2338 "synt_analyzer.tab.cpp"
    break;

  case 45: /* property: modifiers varDeclaration  */
#line 243 "synt_analyzer.y"
                                {(yyval.propertyU) = createProperty((yyvsp[-1].modifiersU), (yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2344 "synt_analyzer.tab.cpp"
    break;

  case 46: /* property: valDeclaration  */
#line 244 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2350 "synt_analyzer.tab.cpp"
    break;

  case 47: /* property: varDeclaration  */
#line 245 "synt_analyzer.y"
                        {(yyval.propertyU) = createProperty((yyvsp[0].varOrValDeclU)); puts("prop created");}
#line 2356 "synt_analyzer.tab.cpp"
    break;

  case 48: /* method: modifiers funcDeclaration semis  */
#line 248 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2362 "synt_analyzer.tab.cpp"
    break;

  case 49: /* method: modifiers funcDeclaration newLines  */
#line 249 "synt_analyzer.y"
                                        {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2368 "synt_analyzer.tab.cpp"
    break;

  case 50: /* method: modifiers func optNewLines  */
#line 250 "synt_analyzer.y"
                                {(yyval.methodU) = createMethod((yyvsp[-2].modifiersU), (yyvsp[-1].funcU)); puts("meth created");}
#line 2374 "synt_analyzer.tab.cpp"
    break;

  case 51: /* method: funcDeclaration semis  */
#line 251 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2380 "synt_analyzer.tab.cpp"
    break;

  case 52: /* method: funcDeclaration newLines  */
#line 252 "synt_analyzer.y"
                                {(yyval.methodU) = createMethod((yyvsp[-1].funcDeclU)); puts("meth created");}
#line 2386 "synt_analyzer.tab.cpp"
    break;

  case 53: /* method: func optNewLines  */
#line 253 "synt_analyzer.y"
                        {(yyval.methodU) = createMethod((yyvsp[-1].funcU)); puts("meth created");}
#line 2392 "synt_analyzer.tab.cpp"
    break;

  case 54: /* initializer: INIT block  */
#line 256 "synt_analyzer.y"
                        {(yyval.initializerU) = createInit((yyvsp[0].stmtListU)); puts("init created");}
#line 2398 "synt_analyzer.tab.cpp"
    break;

  case 55: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' block optNewLines  */
#line 260 "synt_analyzer.y"
                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-6].visibilityModU), (yyvsp[-3].formalParamsListU), (yyvsp[-1].stmtListU)); puts("constr created");}
#line 2404 "synt_analyzer.tab.cpp"
    break;

  case 56: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' optNewLines  */
#line 261 "synt_analyzer.y"
                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-5].visibilityModU), (yyvsp[-2].formalParamsListU)); puts("constr created");}
#line 2410 "synt_analyzer.tab.cpp"
    break;

  case 57: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' optNewLines  */
#line 262 "synt_analyzer.y"
                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU)); puts("constr created");}
#line 2416 "synt_analyzer.tab.cpp"
    break;

  case 58: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' optNewLines  */
#line 263 "synt_analyzer.y"
                                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-10].visibilityModU), (yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU)); puts("constr created");}
#line 2422 "synt_analyzer.tab.cpp"
    break;

  case 59: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block optNewLines  */
#line 264 "synt_analyzer.y"
                                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-11].visibilityModU), (yyvsp[-8].formalParamsListU), "super", (yyvsp[-3].factParamsListU), (yyvsp[-1].stmtListU)); puts("constr created");}
#line 2428 "synt_analyzer.tab.cpp"
    break;

  case 60: /* constructor: visibilityModifier CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block optNewLines  */
#line 265 "synt_analyzer.y"
                                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-11].visibilityModU), (yyvsp[-8].formalParamsListU), "this", (yyvsp[-3].factParamsListU), (yyvsp[-1].stmtListU)); puts("constr created");}
#line 2434 "synt_analyzer.tab.cpp"
    break;

  case 61: /* constructor: CONSTRUCTOR '(' optFormalParams ')' block optNewLines  */
#line 266 "synt_analyzer.y"
                                                        {(yyval.constructorU) = createConstructor((yyvsp[-3].formalParamsListU), (yyvsp[-1].stmtListU)); puts("constr created");}
#line 2440 "synt_analyzer.tab.cpp"
    break;

  case 62: /* constructor: CONSTRUCTOR '(' optFormalParams ')' optNewLines  */
#line 267 "synt_analyzer.y"
                                                        {(yyval.constructorU) = createConstructor((yyvsp[-2].formalParamsListU)); puts("constr created");}
#line 2446 "synt_analyzer.tab.cpp"
    break;

  case 63: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' optNewLines  */
#line 268 "synt_analyzer.y"
                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "super", (yyvsp[-2].factParamsListU)); puts("constr created");}
#line 2452 "synt_analyzer.tab.cpp"
    break;

  case 64: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' optNewLines  */
#line 269 "synt_analyzer.y"
                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-7].formalParamsListU), "this", (yyvsp[-2].factParamsListU)); puts("constr created");}
#line 2458 "synt_analyzer.tab.cpp"
    break;

  case 65: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' SUPER '(' optFactParams ')' block optNewLines  */
#line 270 "synt_analyzer.y"
                                                                                                {(yyval.constructorU) = createConstructor((yyvsp[-8].formalParamsListU), "super", (yyvsp[-3].factParamsListU), (yyvsp[-1].stmtListU)); puts("constr created");}
#line 2464 "synt_analyzer.tab.cpp"
    break;

  case 66: /* constructor: CONSTRUCTOR '(' optFormalParams ')' ':' THIS '(' optFactParams ')' block optNewLines  */
#line 271 "synt_analyzer.y"
                                                                                        {(yyval.constructorU) = createConstructor((yyvsp[-8].formalParamsListU), "this", (yyvsp[-3].factParamsListU), (yyvsp[-1].stmtListU)); puts("constr created");}
#line 2470 "synt_analyzer.tab.cpp"
    break;

  case 67: /* optFormalParams: %empty  */
#line 274 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = 0; puts("opt formal params created");}
#line 2476 "synt_analyzer.tab.cpp"
    break;

  case 68: /* optFormalParams: formalParams  */
#line 275 "synt_analyzer.y"
                {(yyval.formalParamsListU) = (yyvsp[0].formalParamsListU); puts("opt formal params created");}
#line 2482 "synt_analyzer.tab.cpp"
    break;

  case 69: /* formalParams: ID ':' type  */
#line 278 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = createFormalParamsList((yyvsp[-2].IdOrString), (yyvsp[0].typeU)); puts("formal params created");}
#line 2488 "synt_analyzer.tab.cpp"
    break;

  case 70: /* formalParams: formalParams ',' ID ':' type  */
#line 279 "synt_analyzer.y"
                                {(yyval.formalParamsListU) = addToFormalParamsList((yyvsp[-4].formalParamsListU), (yyvsp[-2].IdOrString), (yyvsp[0].typeU)); puts("formal params created");}
#line 2494 "synt_analyzer.tab.cpp"
    break;

  case 71: /* modifiers: OVERRIDE  */
#line 282 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 1, Unknown, None); puts("mods created");}
#line 2500 "synt_analyzer.tab.cpp"
    break;

  case 72: /* modifiers: visibilityModifier  */
#line 283 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2506 "synt_analyzer.tab.cpp"
    break;

  case 73: /* modifiers: inheritanceModifier  */
#line 284 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(0, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2512 "synt_analyzer.tab.cpp"
    break;

  case 74: /* modifiers: ABSTRACT  */
#line 285 "synt_analyzer.y"
                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, None); puts("mods created");}
#line 2518 "synt_analyzer.tab.cpp"
    break;

  case 75: /* modifiers: OVERRIDE visibilityModifier  */
#line 286 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2524 "synt_analyzer.tab.cpp"
    break;

  case 76: /* modifiers: OVERRIDE inheritanceModifier  */
#line 287 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2530 "synt_analyzer.tab.cpp"
    break;

  case 77: /* modifiers: OVERRIDE ABSTRACT  */
#line 288 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2536 "synt_analyzer.tab.cpp"
    break;

  case 78: /* modifiers: visibilityModifier OVERRIDE  */
#line 289 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2542 "synt_analyzer.tab.cpp"
    break;

  case 79: /* modifiers: visibilityModifier inheritanceModifier  */
#line 290 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2548 "synt_analyzer.tab.cpp"
    break;

  case 80: /* modifiers: visibilityModifier ABSTRACT  */
#line 291 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), None); puts("mods created"); }
#line 2554 "synt_analyzer.tab.cpp"
    break;

  case 81: /* modifiers: inheritanceModifier OVERRIDE  */
#line 292 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(0, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2560 "synt_analyzer.tab.cpp"
    break;

  case 82: /* modifiers: inheritanceModifier visibilityModifier  */
#line 293 "synt_analyzer.y"
                                                {(yyval.modifiersU) = createModifiers(0, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2566 "synt_analyzer.tab.cpp"
    break;

  case 83: /* modifiers: inheritanceModifier ABSTRACT  */
#line 294 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2572 "synt_analyzer.tab.cpp"
    break;

  case 84: /* modifiers: ABSTRACT OVERRIDE  */
#line 295 "synt_analyzer.y"
                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, None); puts("mods created");}
#line 2578 "synt_analyzer.tab.cpp"
    break;

  case 85: /* modifiers: ABSTRACT visibilityModifier  */
#line 296 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2584 "synt_analyzer.tab.cpp"
    break;

  case 86: /* modifiers: ABSTRACT inheritanceModifier  */
#line 297 "synt_analyzer.y"
                                {(yyval.modifiersU) = createModifiers(1, 0, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2590 "synt_analyzer.tab.cpp"
    break;

  case 87: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier  */
#line 298 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2596 "synt_analyzer.tab.cpp"
    break;

  case 88: /* modifiers: OVERRIDE visibilityModifier ABSTRACT  */
#line 299 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2602 "synt_analyzer.tab.cpp"
    break;

  case 89: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier  */
#line 300 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2608 "synt_analyzer.tab.cpp"
    break;

  case 90: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT  */
#line 301 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2614 "synt_analyzer.tab.cpp"
    break;

  case 91: /* modifiers: OVERRIDE ABSTRACT visibilityModifier  */
#line 302 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2620 "synt_analyzer.tab.cpp"
    break;

  case 92: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier  */
#line 303 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2626 "synt_analyzer.tab.cpp"
    break;

  case 93: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier  */
#line 304 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2632 "synt_analyzer.tab.cpp"
    break;

  case 94: /* modifiers: visibilityModifier OVERRIDE ABSTRACT  */
#line 305 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2638 "synt_analyzer.tab.cpp"
    break;

  case 95: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE  */
#line 306 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2644 "synt_analyzer.tab.cpp"
    break;

  case 96: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT  */
#line 307 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2650 "synt_analyzer.tab.cpp"
    break;

  case 97: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier  */
#line 308 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2656 "synt_analyzer.tab.cpp"
    break;

  case 98: /* modifiers: visibilityModifier ABSTRACT OVERRIDE  */
#line 309 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), None); puts("mods created");}
#line 2662 "synt_analyzer.tab.cpp"
    break;

  case 99: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier  */
#line 310 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2668 "synt_analyzer.tab.cpp"
    break;

  case 100: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT  */
#line 311 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2674 "synt_analyzer.tab.cpp"
    break;

  case 101: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT  */
#line 312 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2680 "synt_analyzer.tab.cpp"
    break;

  case 102: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE  */
#line 313 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(0, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2686 "synt_analyzer.tab.cpp"
    break;

  case 103: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier  */
#line 314 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2692 "synt_analyzer.tab.cpp"
    break;

  case 104: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE  */
#line 315 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2698 "synt_analyzer.tab.cpp"
    break;

  case 105: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier  */
#line 316 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2704 "synt_analyzer.tab.cpp"
    break;

  case 106: /* modifiers: ABSTRACT OVERRIDE visibilityModifier  */
#line 317 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), None); puts("mods created");}
#line 2710 "synt_analyzer.tab.cpp"
    break;

  case 107: /* modifiers: ABSTRACT visibilityModifier OVERRIDE  */
#line 318 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), None); puts("mods created");}
#line 2716 "synt_analyzer.tab.cpp"
    break;

  case 108: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier  */
#line 319 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2722 "synt_analyzer.tab.cpp"
    break;

  case 109: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE  */
#line 320 "synt_analyzer.y"
                                        {(yyval.modifiersU) = createModifiers(1, 1, Unknown, (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2728 "synt_analyzer.tab.cpp"
    break;

  case 110: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier  */
#line 321 "synt_analyzer.y"
                                                        {(yyval.modifiersU) = createModifiers(1, 0, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2734 "synt_analyzer.tab.cpp"
    break;

  case 111: /* modifiers: OVERRIDE visibilityModifier inheritanceModifier ABSTRACT  */
#line 322 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2740 "synt_analyzer.tab.cpp"
    break;

  case 112: /* modifiers: OVERRIDE visibilityModifier ABSTRACT inheritanceModifier  */
#line 323 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2746 "synt_analyzer.tab.cpp"
    break;

  case 113: /* modifiers: OVERRIDE inheritanceModifier visibilityModifier ABSTRACT  */
#line 324 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2752 "synt_analyzer.tab.cpp"
    break;

  case 114: /* modifiers: OVERRIDE inheritanceModifier ABSTRACT visibilityModifier  */
#line 325 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2758 "synt_analyzer.tab.cpp"
    break;

  case 115: /* modifiers: OVERRIDE ABSTRACT visibilityModifier inheritanceModifier  */
#line 326 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2764 "synt_analyzer.tab.cpp"
    break;

  case 116: /* modifiers: OVERRIDE ABSTRACT inheritanceModifier visibilityModifier  */
#line 327 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2770 "synt_analyzer.tab.cpp"
    break;

  case 117: /* modifiers: visibilityModifier OVERRIDE inheritanceModifier ABSTRACT  */
#line 328 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2776 "synt_analyzer.tab.cpp"
    break;

  case 118: /* modifiers: visibilityModifier OVERRIDE ABSTRACT inheritanceModifier  */
#line 329 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2782 "synt_analyzer.tab.cpp"
    break;

  case 119: /* modifiers: visibilityModifier inheritanceModifier OVERRIDE ABSTRACT  */
#line 330 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2788 "synt_analyzer.tab.cpp"
    break;

  case 120: /* modifiers: visibilityModifier inheritanceModifier ABSTRACT OVERRIDE  */
#line 331 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2794 "synt_analyzer.tab.cpp"
    break;

  case 121: /* modifiers: visibilityModifier ABSTRACT inheritanceModifier OVERRIDE  */
#line 332 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2800 "synt_analyzer.tab.cpp"
    break;

  case 122: /* modifiers: visibilityModifier ABSTRACT OVERRIDE inheritanceModifier  */
#line 333 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-3].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2806 "synt_analyzer.tab.cpp"
    break;

  case 123: /* modifiers: inheritanceModifier OVERRIDE visibilityModifier ABSTRACT  */
#line 334 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2812 "synt_analyzer.tab.cpp"
    break;

  case 124: /* modifiers: inheritanceModifier OVERRIDE ABSTRACT visibilityModifier  */
#line 335 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2818 "synt_analyzer.tab.cpp"
    break;

  case 125: /* modifiers: inheritanceModifier visibilityModifier ABSTRACT OVERRIDE  */
#line 337 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2824 "synt_analyzer.tab.cpp"
    break;

  case 126: /* modifiers: inheritanceModifier visibilityModifier OVERRIDE ABSTRACT  */
#line 339 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2830 "synt_analyzer.tab.cpp"
    break;

  case 127: /* modifiers: inheritanceModifier ABSTRACT visibilityModifier OVERRIDE  */
#line 341 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2836 "synt_analyzer.tab.cpp"
    break;

  case 128: /* modifiers: inheritanceModifier ABSTRACT OVERRIDE visibilityModifier  */
#line 343 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-3].inheritanceModU)); puts("mods created");}
#line 2842 "synt_analyzer.tab.cpp"
    break;

  case 129: /* modifiers: ABSTRACT OVERRIDE inheritanceModifier visibilityModifier  */
#line 345 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2848 "synt_analyzer.tab.cpp"
    break;

  case 130: /* modifiers: ABSTRACT OVERRIDE visibilityModifier inheritanceModifier  */
#line 347 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2854 "synt_analyzer.tab.cpp"
    break;

  case 131: /* modifiers: ABSTRACT visibilityModifier OVERRIDE inheritanceModifier  */
#line 348 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[0].inheritanceModU)); puts("mods created");}
#line 2860 "synt_analyzer.tab.cpp"
    break;

  case 132: /* modifiers: ABSTRACT visibilityModifier inheritanceModifier OVERRIDE  */
#line 349 "synt_analyzer.y"
                                                                {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-2].visibilityModU), (yyvsp[-1].inheritanceModU)); puts("mods created");}
#line 2866 "synt_analyzer.tab.cpp"
    break;

  case 133: /* modifiers: ABSTRACT inheritanceModifier OVERRIDE visibilityModifier  */
#line 351 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[0].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2872 "synt_analyzer.tab.cpp"
    break;

  case 134: /* modifiers: ABSTRACT inheritanceModifier visibilityModifier OVERRIDE  */
#line 353 "synt_analyzer.y"
        {(yyval.modifiersU) = createModifiers(1, 1, (yyvsp[-1].visibilityModU), (yyvsp[-2].inheritanceModU)); puts("mods created");}
#line 2878 "synt_analyzer.tab.cpp"
    break;

  case 135: /* visibilityModifier: PUBLIC  */
#line 356 "synt_analyzer.y"
                                {(yyval.visibilityModU) = Public;}
#line 2884 "synt_analyzer.tab.cpp"
    break;

  case 136: /* visibilityModifier: PRIVATE  */
#line 357 "synt_analyzer.y"
                {(yyval.visibilityModU) = Private;}
#line 2890 "synt_analyzer.tab.cpp"
    break;

  case 137: /* visibilityModifier: INTERNAL  */
#line 358 "synt_analyzer.y"
                {(yyval.visibilityModU) = Internal;}
#line 2896 "synt_analyzer.tab.cpp"
    break;

  case 138: /* visibilityModifier: PROTECTED  */
#line 359 "synt_analyzer.y"
                {(yyval.visibilityModU) = Protected;}
#line 2902 "synt_analyzer.tab.cpp"
    break;

  case 139: /* inheritanceModifier: FINAL  */
#line 363 "synt_analyzer.y"
                           {(yyval.inheritanceModU) = Final;}
#line 2908 "synt_analyzer.tab.cpp"
    break;

  case 140: /* inheritanceModifier: OPEN  */
#line 364 "synt_analyzer.y"
       {(yyval.inheritanceModU) = Open;}
#line 2914 "synt_analyzer.tab.cpp"
    break;

  case 141: /* func: funcDeclaration block  */
#line 367 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-1].funcDeclU), (yyvsp[0].stmtListU)); puts("func created");}
#line 2920 "synt_analyzer.tab.cpp"
    break;

  case 142: /* func: funcDeclaration '=' expr  */
#line 368 "synt_analyzer.y"
                                {(yyval.funcU) = createFunc((yyvsp[-2].funcDeclU), (yyvsp[0].exprU)); puts("func created");}
#line 2926 "synt_analyzer.tab.cpp"
    break;

  case 143: /* funcDeclaration: FUN ID '(' optFormalParams ')' ':' type  */
#line 372 "synt_analyzer.y"
                                                                {(yyval.funcDeclU) = createFuncDecl((yyvsp[-5].IdOrString), (yyvsp[-3].formalParamsListU), (yyvsp[0].typeU));  puts("func decl created");}
#line 2932 "synt_analyzer.tab.cpp"
    break;

  case 144: /* block: optNewLines '{' semis stmts '}'  */
#line 376 "synt_analyzer.y"
                                        {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2938 "synt_analyzer.tab.cpp"
    break;

  case 145: /* block: optNewLines '{' semis '}'  */
#line 377 "synt_analyzer.y"
                                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2944 "synt_analyzer.tab.cpp"
    break;

  case 146: /* block: optNewLines '{' stmts '}'  */
#line 378 "synt_analyzer.y"
                                {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2950 "synt_analyzer.tab.cpp"
    break;

  case 147: /* block: optNewLines '{' newLines stmts '}'  */
#line 379 "synt_analyzer.y"
                                        {(yyval.stmtListU) = (yyvsp[-1].stmtListU);  puts("block created");}
#line 2956 "synt_analyzer.tab.cpp"
    break;

  case 148: /* block: optNewLines '{' newLines '}'  */
#line 380 "synt_analyzer.y"
                                {(yyval.stmtListU) = 0;  puts("block created");}
#line 2962 "synt_analyzer.tab.cpp"
    break;

  case 149: /* block: optNewLines '{' '}'  */
#line 381 "synt_analyzer.y"
                        {(yyval.stmtListU) = 0;  puts("block created");}
#line 2968 "synt_analyzer.tab.cpp"
    break;

  case 150: /* varDeclaration: VAR ID ':' type  */
#line 385 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].IdOrString), (yyvsp[0].typeU), 0); puts("var created");}
#line 2974 "synt_analyzer.tab.cpp"
    break;

  case 151: /* varDeclaration: VAR ID ':' type '=' expr  */
#line 386 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].IdOrString), (yyvsp[-2].typeU), (yyvsp[0].exprU), 0); puts("var created");}
#line 2980 "synt_analyzer.tab.cpp"
    break;

  case 152: /* varDeclaration: VAR '(' formalParams ')' '=' expr  */
#line 387 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 0); puts("var created"); }
#line 2986 "synt_analyzer.tab.cpp"
    break;

  case 153: /* valDeclaration: VAL ID ':' type  */
#line 391 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-2].IdOrString), (yyvsp[0].typeU), 1); puts("val created"); }
#line 2992 "synt_analyzer.tab.cpp"
    break;

  case 154: /* valDeclaration: VAL ID ':' type '=' expr  */
#line 392 "synt_analyzer.y"
                                {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-4].IdOrString), (yyvsp[-2].typeU), (yyvsp[0].exprU), 1); puts("val created"); }
#line 2998 "synt_analyzer.tab.cpp"
    break;

  case 155: /* valDeclaration: VAL '(' formalParams ')' '=' expr  */
#line 393 "synt_analyzer.y"
                                        {(yyval.varOrValDeclU) = createVarOrValDecl((yyvsp[-3].formalParamsListU), (yyvsp[0].exprU), 1); puts("val created"); }
#line 3004 "synt_analyzer.tab.cpp"
    break;

  case 156: /* type: ID  */
#line 396 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].IdOrString)); puts("type created"); }
#line 3010 "synt_analyzer.tab.cpp"
    break;

  case 157: /* type: templateType  */
#line 397 "synt_analyzer.y"
                {(yyval.typeU) = createType((yyvsp[0].templateTypeU)); puts("type created"); }
#line 3016 "synt_analyzer.tab.cpp"
    break;

  case 158: /* templateType: ID '<' type_seq '>'  */
#line 400 "synt_analyzer.y"
                                        {(yyval.templateTypeU) = createTemplateType((yyvsp[-3].IdOrString), (yyvsp[-1].typesListU)); puts("template type created"); }
#line 3022 "synt_analyzer.tab.cpp"
    break;

  case 159: /* type_seq: ID  */
#line 403 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].IdOrString)); puts("type seq created"); }
#line 3028 "synt_analyzer.tab.cpp"
    break;

  case 160: /* type_seq: templateType  */
#line 404 "synt_analyzer.y"
                {(yyval.typesListU) = createTypesList((yyvsp[0].templateTypeU)); puts("type seq created"); }
#line 3034 "synt_analyzer.tab.cpp"
    break;

  case 161: /* type_seq: type_seq ',' ID  */
#line 405 "synt_analyzer.y"
                        {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].IdOrString));  puts("type seq created"); }
#line 3040 "synt_analyzer.tab.cpp"
    break;

  case 162: /* type_seq: type_seq ',' templateType  */
#line 406 "synt_analyzer.y"
                                {(yyval.typesListU) = addToTypesList((yyvsp[-2].typesListU), (yyvsp[0].templateTypeU));  puts("type seq created"); }
#line 3046 "synt_analyzer.tab.cpp"
    break;

  case 163: /* stmts: stmt  */
#line 409 "synt_analyzer.y"
                {(yyval.stmtListU) = createStmtList((yyvsp[0].stmtU));  puts("stmts created"); }
#line 3052 "synt_analyzer.tab.cpp"
    break;

  case 164: /* stmts: stmts stmt  */
#line 410 "synt_analyzer.y"
                {(yyval.stmtListU) = addToStmtList((yyvsp[-1].stmtListU), (yyvsp[0].stmtU));  puts("stmts created"); }
#line 3058 "synt_analyzer.tab.cpp"
    break;

  case 165: /* stmt: valDeclaration semis  */
#line 413 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3064 "synt_analyzer.tab.cpp"
    break;

  case 166: /* stmt: varDeclaration semis  */
#line 414 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3070 "synt_analyzer.tab.cpp"
    break;

  case 167: /* stmt: assignment semis  */
#line 415 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 3076 "synt_analyzer.tab.cpp"
    break;

  case 168: /* stmt: whileLoop  */
#line 416 "synt_analyzer.y"
            {(yyval.stmtU) = createStmt((yyvsp[0].whileLoopU), WhileLoop);  puts("stmt created"); }
#line 3082 "synt_analyzer.tab.cpp"
    break;

  case 169: /* stmt: doWhileLoop semis  */
#line 417 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 3088 "synt_analyzer.tab.cpp"
    break;

  case 170: /* stmt: forLoop  */
#line 418 "synt_analyzer.y"
          {(yyval.stmtU) = createStmt((yyvsp[0].forLoopU), ForLoop);  puts("stmt created"); }
#line 3094 "synt_analyzer.tab.cpp"
    break;

  case 171: /* stmt: ifStmt  */
#line 419 "synt_analyzer.y"
         {(yyval.stmtU) = createStmt((yyvsp[0].ifStmtU), IfStmt);  puts("stmt created"); }
#line 3100 "synt_analyzer.tab.cpp"
    break;

  case 172: /* stmt: expr semis  */
#line 420 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 3106 "synt_analyzer.tab.cpp"
    break;

  case 173: /* stmt: BREAK semis  */
#line 421 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 3112 "synt_analyzer.tab.cpp"
    break;

  case 174: /* stmt: CONTINUE semis  */
#line 422 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 3118 "synt_analyzer.tab.cpp"
    break;

  case 175: /* stmt: RETURN semis  */
#line 423 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 3124 "synt_analyzer.tab.cpp"
    break;

  case 176: /* stmt: RETURN expr semis  */
#line 424 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 3130 "synt_analyzer.tab.cpp"
    break;

  case 177: /* stmt: valDeclaration newLines  */
#line 425 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3136 "synt_analyzer.tab.cpp"
    break;

  case 178: /* stmt: varDeclaration newLines  */
#line 426 "synt_analyzer.y"
                                {(yyval.stmtU) = createStmt((yyvsp[-1].varOrValDeclU), VarOrVal);  puts("stmt created"); }
#line 3142 "synt_analyzer.tab.cpp"
    break;

  case 179: /* stmt: assignment newLines  */
#line 427 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].assignmentU), Assignment);  puts("stmt created"); }
#line 3148 "synt_analyzer.tab.cpp"
    break;

  case 180: /* stmt: doWhileLoop newLines  */
#line 428 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].whileLoopU), DoWhileLoop);  puts("stmt created"); }
#line 3154 "synt_analyzer.tab.cpp"
    break;

  case 181: /* stmt: expr newLines  */
#line 429 "synt_analyzer.y"
                {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), Expr);  puts("stmt created"); }
#line 3160 "synt_analyzer.tab.cpp"
    break;

  case 182: /* stmt: BREAK newLines  */
#line 430 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Break);  puts("stmt created"); }
#line 3166 "synt_analyzer.tab.cpp"
    break;

  case 183: /* stmt: CONTINUE newLines  */
#line 431 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Continue);  puts("stmt created"); }
#line 3172 "synt_analyzer.tab.cpp"
    break;

  case 184: /* stmt: RETURN newLines  */
#line 432 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt(Return);  puts("stmt created"); }
#line 3178 "synt_analyzer.tab.cpp"
    break;

  case 185: /* stmt: RETURN expr newLines  */
#line 433 "synt_analyzer.y"
                        {(yyval.stmtU) = createStmt((yyvsp[-1].exprU), ReturnValue);  puts("stmt created"); }
#line 3184 "synt_analyzer.tab.cpp"
    break;

  case 186: /* expr: STR  */
#line 436 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].IdOrString), String);  puts("expr created"); }
#line 3190 "synt_analyzer.tab.cpp"
    break;

  case 187: /* expr: ID  */
#line 437 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].IdOrString), Identificator);  puts("expr created"); }
#line 3196 "synt_analyzer.tab.cpp"
    break;

  case 188: /* expr: THIS  */
#line 438 "synt_analyzer.y"
        {(yyval.exprU) = createExpr(0, This);  puts("expr created"); }
#line 3202 "synt_analyzer.tab.cpp"
    break;

  case 189: /* expr: ID '(' optFactParams ')'  */
#line 439 "synt_analyzer.y"
                                {(yyval.exprU) = createExpr((yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), MethodCall);  puts("expr created"); }
#line 3208 "synt_analyzer.tab.cpp"
    break;

  case 190: /* expr: INT  */
#line 440 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Int_v), Int);  puts("expr created"); }
#line 3214 "synt_analyzer.tab.cpp"
    break;

  case 191: /* expr: FLOAT  */
#line 441 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Float_v), Float);  puts("expr created"); }
#line 3220 "synt_analyzer.tab.cpp"
    break;

  case 192: /* expr: CHR  */
#line 442 "synt_analyzer.y"
        {(yyval.exprU) = createExpr((yyvsp[0].Char_v), Char);  puts("expr created"); }
#line 3226 "synt_analyzer.tab.cpp"
    break;

  case 193: /* expr: DOUBLE  */
#line 443 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Double_v), Double);  puts("expr created"); }
#line 3232 "synt_analyzer.tab.cpp"
    break;

  case 194: /* expr: BOOLEAN  */
#line 444 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].Bool_v), Boolean);  puts("expr created"); }
#line 3238 "synt_analyzer.tab.cpp"
    break;

  case 195: /* expr: '(' expr ')'  */
#line 445 "synt_analyzer.y"
                {(yyval.exprU) = (yyvsp[-1].exprU); puts("expr created"); }
#line 3244 "synt_analyzer.tab.cpp"
    break;

  case 196: /* expr: '!' expr  */
#line 446 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[0].exprU), LogicalNot);}
#line 3250 "synt_analyzer.tab.cpp"
    break;

  case 197: /* expr: '+' expr  */
#line 447 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryPlusExpr);  puts("expr created"); }
#line 3256 "synt_analyzer.tab.cpp"
    break;

  case 198: /* expr: '-' expr  */
#line 448 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[0].exprU), UnaryMinusExpr);  puts("expr created"); }
#line 3262 "synt_analyzer.tab.cpp"
    break;

  case 199: /* expr: expr '+' expr  */
#line 449 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sum);  puts("expr created"); }
#line 3268 "synt_analyzer.tab.cpp"
    break;

  case 200: /* expr: expr '-' expr  */
#line 450 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Sub);  puts("expr created"); }
#line 3274 "synt_analyzer.tab.cpp"
    break;

  case 201: /* expr: expr '*' expr  */
#line 451 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mul);  puts("expr created"); }
#line 3280 "synt_analyzer.tab.cpp"
    break;

  case 202: /* expr: expr '/' expr  */
#line 452 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Div);  puts("expr created"); }
#line 3286 "synt_analyzer.tab.cpp"
    break;

  case 203: /* expr: expr '%' expr  */
#line 453 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Mod);  puts("expr created"); }
#line 3292 "synt_analyzer.tab.cpp"
    break;

  case 204: /* expr: expr '<' expr  */
#line 454 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Less);  puts("expr created"); }
#line 3298 "synt_analyzer.tab.cpp"
    break;

  case 205: /* expr: expr '>' expr  */
#line 455 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), More);  puts("expr created"); }
#line 3304 "synt_analyzer.tab.cpp"
    break;

  case 206: /* expr: expr OR expr  */
#line 456 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Or);  puts("expr created"); }
#line 3310 "synt_analyzer.tab.cpp"
    break;

  case 207: /* expr: expr AND expr  */
#line 457 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), And);  puts("expr created"); }
#line 3316 "synt_analyzer.tab.cpp"
    break;

  case 208: /* expr: expr EQ expr  */
#line 458 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Eq);  puts("expr created"); }
#line 3322 "synt_analyzer.tab.cpp"
    break;

  case 209: /* expr: expr AEQ expr  */
#line 459 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Aeq);}
#line 3328 "synt_analyzer.tab.cpp"
    break;

  case 210: /* expr: expr NEQ expr  */
#line 460 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Neq);  puts("expr created"); }
#line 3334 "synt_analyzer.tab.cpp"
    break;

  case 211: /* expr: expr NAEQ expr  */
#line 461 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Naeq);  puts("expr created"); }
#line 3340 "synt_analyzer.tab.cpp"
    break;

  case 212: /* expr: expr LOEQ expr  */
#line 462 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Loeq);  puts("expr created"); }
#line 3346 "synt_analyzer.tab.cpp"
    break;

  case 213: /* expr: expr MOEQ expr  */
#line 463 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Moeq);  puts("expr created"); }
#line 3352 "synt_analyzer.tab.cpp"
    break;

  case 214: /* expr: expr '.' ID  */
#line 464 "synt_analyzer.y"
                {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].IdOrString), FieldCalcExpr);  puts("expr created"); }
#line 3358 "synt_analyzer.tab.cpp"
    break;

  case 215: /* expr: expr '.' ID '(' optFactParams ')'  */
#line 465 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr((yyvsp[-5].exprU), (yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), MethodCalcExpr);  puts("expr created"); }
#line 3364 "synt_analyzer.tab.cpp"
    break;

  case 216: /* expr: expr '[' expr ']'  */
#line 466 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-3].exprU), (yyvsp[-1].exprU), ArrayElementCall);  puts("expr created"); }
#line 3370 "synt_analyzer.tab.cpp"
    break;

  case 217: /* expr: SUPER '.' ID  */
#line 467 "synt_analyzer.y"
                {(yyval.exprU) = createExpr(0, (yyvsp[0].IdOrString), ParentFieldCall);  puts("expr created"); }
#line 3376 "synt_analyzer.tab.cpp"
    break;

  case 218: /* expr: SUPER '.' ID '(' optFactParams ')'  */
#line 468 "synt_analyzer.y"
                                        {(yyval.exprU) = createExpr(0, (yyvsp[-3].IdOrString), (yyvsp[-1].factParamsListU), ParentMethodCall);  puts("expr created"); }
#line 3382 "synt_analyzer.tab.cpp"
    break;

  case 219: /* expr: expr RANGE expr  */
#line 469 "synt_analyzer.y"
                        {(yyval.exprU) = createExpr((yyvsp[-2].exprU), (yyvsp[0].exprU), Range);  puts("expr created"); }
#line 3388 "synt_analyzer.tab.cpp"
    break;

  case 220: /* optFactParams: %empty  */
#line 472 "synt_analyzer.y"
                                {(yyval.factParamsListU) = 0;   puts("opt fact params created"); }
#line 3394 "synt_analyzer.tab.cpp"
    break;

  case 221: /* optFactParams: factParams  */
#line 473 "synt_analyzer.y"
                {(yyval.factParamsListU) = (yyvsp[0].factParamsListU);   puts("opt fact params created"); }
#line 3400 "synt_analyzer.tab.cpp"
    break;

  case 222: /* factParams: expr  */
#line 476 "synt_analyzer.y"
                        {(yyval.factParamsListU) = createFactParamsList((yyvsp[0].exprU));   puts("fact params created"); }
#line 3406 "synt_analyzer.tab.cpp"
    break;

  case 223: /* factParams: factParams ',' expr  */
#line 477 "synt_analyzer.y"
                        {(yyval.factParamsListU) = addToFactParamsList((yyvsp[-2].factParamsListU), (yyvsp[0].exprU));   puts("fact params created"); }
#line 3412 "synt_analyzer.tab.cpp"
    break;

  case 224: /* assignment: expr '=' expr  */
#line 480 "synt_analyzer.y"
                                {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Assign); puts("assignment created"); }
#line 3418 "synt_analyzer.tab.cpp"
    break;

  case 225: /* assignment: expr ASUM expr  */
#line 481 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asum); puts("assignment created"); }
#line 3424 "synt_analyzer.tab.cpp"
    break;

  case 226: /* assignment: expr ASUB expr  */
#line 482 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Asub); puts("assignment created"); }
#line 3430 "synt_analyzer.tab.cpp"
    break;

  case 227: /* assignment: expr ADIV expr  */
#line 483 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Adiv); puts("assignment created"); }
#line 3436 "synt_analyzer.tab.cpp"
    break;

  case 228: /* assignment: expr AMUL expr  */
#line 484 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amul); puts("assignment created"); }
#line 3442 "synt_analyzer.tab.cpp"
    break;

  case 229: /* assignment: expr AMOD expr  */
#line 485 "synt_analyzer.y"
                        {(yyval.assignmentU) = createAssignment((yyvsp[-2].exprU), (yyvsp[0].exprU), Amod); puts("assignment created"); }
#line 3448 "synt_analyzer.tab.cpp"
    break;

  case 230: /* whileLoop: WHILE '(' expr ')' optNewLines stmt  */
#line 488 "synt_analyzer.y"
                                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), (yyvsp[0].stmtU), 0); puts("whileLoop created"); }
#line 3454 "synt_analyzer.tab.cpp"
    break;

  case 231: /* whileLoop: WHILE '(' expr ')' block semis  */
#line 489 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), (yyvsp[-1].stmtListU), 0); puts("whileLoop created"); }
#line 3460 "synt_analyzer.tab.cpp"
    break;

  case 232: /* whileLoop: WHILE '(' expr ')' semis  */
#line 490 "synt_analyzer.y"
                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-2].exprU), 0); puts("whileLoop created"); }
#line 3466 "synt_analyzer.tab.cpp"
    break;

  case 233: /* whileLoop: WHILE '(' expr ')' block newLines  */
#line 491 "synt_analyzer.y"
                                        {(yyval.whileLoopU) = createWhileLoop((yyvsp[-3].exprU), (yyvsp[-1].stmtListU), 0); puts("whileLoop created"); }
#line 3472 "synt_analyzer.tab.cpp"
    break;

  case 234: /* doWhileLoop: DO optNewLines expr optNewLines WHILE '(' expr ')'  */
#line 494 "synt_analyzer.y"
                                                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-5].exprU), 1); puts("doWhileLoop created"); }
#line 3478 "synt_analyzer.tab.cpp"
    break;

  case 235: /* doWhileLoop: DO block optNewLines WHILE '(' expr ')'  */
#line 495 "synt_analyzer.y"
                                                {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), (yyvsp[-5].stmtListU), 1); puts("doWhileLoop created"); }
#line 3484 "synt_analyzer.tab.cpp"
    break;

  case 236: /* doWhileLoop: DO optNewLines WHILE '(' expr ')'  */
#line 496 "synt_analyzer.y"
                                    {(yyval.whileLoopU) = createWhileLoop((yyvsp[-1].exprU), 1); puts("doWhileLoop created"); }
#line 3490 "synt_analyzer.tab.cpp"
    break;

  case 237: /* forLoop: FOR '(' ID ':' type IN expr ')' optNewLines stmt  */
#line 499 "synt_analyzer.y"
                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-7].IdOrString), (yyvsp[-5].typeU), (yyvsp[-3].exprU), (yyvsp[0].stmtU)); puts("forLoop created"); }
#line 3496 "synt_analyzer.tab.cpp"
    break;

  case 238: /* forLoop: FOR '(' ID ':' type IN expr ')' block semis  */
#line 500 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-7].IdOrString), (yyvsp[-5].typeU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3502 "synt_analyzer.tab.cpp"
    break;

  case 239: /* forLoop: FOR '(' ID ':' type IN expr ')' semis  */
#line 501 "synt_analyzer.y"
                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].IdOrString), (yyvsp[-4].typeU), (yyvsp[-2].exprU)); puts("forLoop created"); }
#line 3508 "synt_analyzer.tab.cpp"
    break;

  case 240: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' optNewLines stmt  */
#line 502 "synt_analyzer.y"
                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].formalParamsListU), (yyvsp[-3].exprU), (yyvsp[0].stmtU), true); puts("forLoop created"); }
#line 3514 "synt_analyzer.tab.cpp"
    break;

  case 241: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block semis  */
#line 503 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-6].formalParamsListU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU), true); puts("forLoop created"); }
#line 3520 "synt_analyzer.tab.cpp"
    break;

  case 242: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' semis  */
#line 504 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-5].formalParamsListU), (yyvsp[-2].exprU), true); puts("forLoop created"); }
#line 3526 "synt_analyzer.tab.cpp"
    break;

  case 243: /* forLoop: FOR '(' ID ':' type IN expr ')' block newLines  */
#line 505 "synt_analyzer.y"
                                                        {(yyval.forLoopU) = createForLoop((yyvsp[-7].IdOrString), (yyvsp[-5].typeU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("forLoop created"); }
#line 3532 "synt_analyzer.tab.cpp"
    break;

  case 244: /* forLoop: FOR '(' '(' formalParams ')' IN expr ')' block newLines  */
#line 506 "synt_analyzer.y"
                                                                {(yyval.forLoopU) = createForLoop((yyvsp[-6].formalParamsListU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU), true); puts("forLoop created"); }
#line 3538 "synt_analyzer.tab.cpp"
    break;

  case 245: /* ifStmt: IF '(' expr ')' optNewLines stmt  */
#line 509 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-3].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3544 "synt_analyzer.tab.cpp"
    break;

  case 246: /* ifStmt: IF '(' expr ')' semis  */
#line 510 "synt_analyzer.y"
                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3550 "synt_analyzer.tab.cpp"
    break;

  case 247: /* ifStmt: IF '(' expr ')' block semis  */
#line 511 "synt_analyzer.y"
                              {(yyval.ifStmtU) = createIfStmt((yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3556 "synt_analyzer.tab.cpp"
    break;

  case 248: /* ifStmt: IF '(' expr ')' optNewLines expr ELSE optNewLines stmt  */
#line 512 "synt_analyzer.y"
                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-3].exprU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3562 "synt_analyzer.tab.cpp"
    break;

  case 249: /* ifStmt: IF '(' expr ')' optNewLines stmt ELSE optNewLines stmt  */
#line 513 "synt_analyzer.y"
                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-3].stmtU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3568 "synt_analyzer.tab.cpp"
    break;

  case 250: /* ifStmt: IF '(' expr ')' block optNewLines ELSE optNewLines stmt  */
#line 514 "synt_analyzer.y"
                                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-4].stmtListU), (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3574 "synt_analyzer.tab.cpp"
    break;

  case 251: /* ifStmt: IF '(' expr ')' semis ELSE optNewLines stmt  */
#line 515 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3580 "synt_analyzer.tab.cpp"
    break;

  case 252: /* ifStmt: IF '(' expr ')' optNewLines expr ELSE block semis  */
#line 516 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3586 "synt_analyzer.tab.cpp"
    break;

  case 253: /* ifStmt: IF '(' expr ')' optNewLines stmt ELSE block semis  */
#line 517 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-3].stmtU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3592 "synt_analyzer.tab.cpp"
    break;

  case 254: /* ifStmt: IF '(' expr ')' block optNewLines ELSE block semis  */
#line 518 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-4].stmtListU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3598 "synt_analyzer.tab.cpp"
    break;

  case 255: /* ifStmt: IF '(' expr ')' semis ELSE block semis  */
#line 519 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3604 "synt_analyzer.tab.cpp"
    break;

  case 256: /* ifStmt: IF '(' expr ')' optNewLines expr ELSE semis  */
#line 520 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-2].exprU)); puts("ifStmt created"); }
#line 3610 "synt_analyzer.tab.cpp"
    break;

  case 257: /* ifStmt: IF '(' expr ')' optNewLines stmt ELSE semis  */
#line 521 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-2].stmtU)); puts("ifStmt created"); }
#line 3616 "synt_analyzer.tab.cpp"
    break;

  case 258: /* ifStmt: IF '(' expr ')' block optNewLines ELSE semis  */
#line 522 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), (yyvsp[-3].stmtListU)); puts("ifStmt created"); }
#line 3622 "synt_analyzer.tab.cpp"
    break;

  case 259: /* ifStmt: IF '(' expr ')' block optNewLines  */
#line 523 "synt_analyzer.y"
                                    {(yyval.ifStmtU) = createIfStmt((yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3628 "synt_analyzer.tab.cpp"
    break;

  case 260: /* ifStmt: IF '(' expr ')' newLines ELSE optNewLines stmt  */
#line 524 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[0].stmtU)); puts("ifStmt created"); }
#line 3634 "synt_analyzer.tab.cpp"
    break;

  case 261: /* ifStmt: IF '(' expr ')' optNewLines expr ELSE block newLines  */
#line 525 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-3].exprU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3640 "synt_analyzer.tab.cpp"
    break;

  case 262: /* ifStmt: IF '(' expr ')' optNewLines stmt ELSE block newLines  */
#line 526 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-3].stmtU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3646 "synt_analyzer.tab.cpp"
    break;

  case 263: /* ifStmt: IF '(' expr ')' block optNewLines ELSE block newLines  */
#line 527 "synt_analyzer.y"
                                                        {(yyval.ifStmtU) = createIfStmt((yyvsp[-6].exprU), (yyvsp[-4].stmtListU), (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3652 "synt_analyzer.tab.cpp"
    break;

  case 264: /* ifStmt: IF '(' expr ')' newLines ELSE block newLines  */
#line 528 "synt_analyzer.y"
                                                {(yyval.ifStmtU) = createIfStmt((yyvsp[-5].exprU), 0, (yyvsp[-1].stmtListU)); puts("ifStmt created"); }
#line 3658 "synt_analyzer.tab.cpp"
    break;

  case 269: /* semis: ';'  */
#line 539 "synt_analyzer.y"
                { puts("semis created"); }
#line 3664 "synt_analyzer.tab.cpp"
    break;

  case 270: /* semis: semis ';'  */
#line 540 "synt_analyzer.y"
                { puts("; added to semis"); }
#line 3670 "synt_analyzer.tab.cpp"
    break;

  case 271: /* semis: semis NEW_LINE  */
#line 541 "synt_analyzer.y"
                 { puts("newLines added to semis"); }
#line 3676 "synt_analyzer.tab.cpp"
    break;


#line 3680 "synt_analyzer.tab.cpp"

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

#line 545 "synt_analyzer.y"

//Секция пользовательского кода



void main(int argc, char **argv )
{

	if (argc == 2) yyin = fopen(argv[1], "r");
	else yyin = fopen("easy_test.txt", "r");

	FILE * file = fopen("tree.dot", "w");
	root = 0;
    yyparse();

	fprintf(file, "digraph G {\n");
	print(root, file);
	fprintf(file, "\n}");

	fclose(file);
	try
	{
		root = transformProgram(classesFiles ,root);
		file = fopen("tree_after_semantic.dot", "w");
		fprintf(file, "digraph G {\n");
		print(root, file);
		fprintf(file, "\n}");
		fclose(file);
	}
	catch(exception& e)
	{
		printf("%s", e.what());
		return;
	}
	
	file = fopen("const_table.txt", "w");
	for (auto i : classesFiles)
	{
		fprintf(file, "%s", i.constsTableToStr().c_str());
	}
	fclose(file);


    return;
}

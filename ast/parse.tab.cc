/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

    #include<stdio.h>
    #include<math.h>
    #include <iostream>
    #include "ast.h"
    void yyerror(const char *s);
    extern int yylineno;
    extern FILE* yyin;
    extern char* yytext;
    extern int yylex(void);
    extern int yylineno;
    int AST::order = 0;
    AST *head =new AST("translation unit");

#line 86 "parse.tab.cc"

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

#include "parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING_LITERAL = 3,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 4,                     /* SIZEOF  */
  YYSYMBOL_LE_OP = 5,                      /* LE_OP  */
  YYSYMBOL_GE_OP = 6,                      /* GE_OP  */
  YYSYMBOL_EQ_OP = 7,                      /* EQ_OP  */
  YYSYMBOL_NE_OP = 8,                      /* NE_OP  */
  YYSYMBOL_AND_OP = 9,                     /* AND_OP  */
  YYSYMBOL_OR_OP = 10,                     /* OR_OP  */
  YYSYMBOL_TYPEDEF = 11,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 12,                    /* EXTERN  */
  YYSYMBOL_STATIC = 13,                    /* STATIC  */
  YYSYMBOL_AUTO = 14,                      /* AUTO  */
  YYSYMBOL_CHAR = 15,                      /* CHAR  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_LONG = 17,                      /* LONG  */
  YYSYMBOL_SIGNED = 18,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 19,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 21,                    /* DOUBLE  */
  YYSYMBOL_CONST = 22,                     /* CONST  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_STRUCT = 24,                    /* STRUCT  */
  YYSYMBOL_UNION = 25,                     /* UNION  */
  YYSYMBOL_ENUM = 26,                      /* ENUM  */
  YYSYMBOL_CASE = 27,                      /* CASE  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_SWITCH = 31,                    /* SWITCH  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_DO = 33,                        /* DO  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_GOTO = 35,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 36,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_IDENTIFIER = 39,                /* IDENTIFIER  */
  YYSYMBOL_CONSTANTf = 40,                 /* CONSTANTf  */
  YYSYMBOL_CONSTANTi = 41,                 /* CONSTANTi  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '+'  */
  YYSYMBOL_47_ = 47,                       /* '-'  */
  YYSYMBOL_48_ = 48,                       /* '*'  */
  YYSYMBOL_49_ = 49,                       /* '/'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* '~'  */
  YYSYMBOL_59_ = 59,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_ssc = 61,                       /* ssc  */
  YYSYMBOL_external_declaration = 62,      /* external_declaration  */
  YYSYMBOL_declaration = 63,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 64,    /* declaration_specifiers  */
  YYSYMBOL_parameter_list = 65,            /* parameter_list  */
  YYSYMBOL_function_definition = 66,       /* function_definition  */
  YYSYMBOL_compound_statement = 67,        /* compound_statement  */
  YYSYMBOL_declaration_list = 68,          /* declaration_list  */
  YYSYMBOL_statement_list = 69,            /* statement_list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_expression_list = 71,           /* expression_list  */
  YYSYMBOL_expression_statement = 72,      /* expression_statement  */
  YYSYMBOL_selection_statement = 73,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 74,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 75,            /* jump_statement  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_type_qualifier = 77,            /* type_qualifier  */
  YYSYMBOL_type_specifier = 78             /* type_specifier  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   485

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,    59,     2,     2,     2,    50,     2,     2,
      52,    53,    48,    46,    42,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      45,    43,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,    58,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    54,    59,    64,    73,    74,    78,    79,
      94,    96,   102,   106,   110,   111,   112,   113,   117,   118,
     122,   123,   127,   128,   129,   130,   131,   135,   136,   140,
     141,   145,   146,   147,   151,   153,   154,   158,   159,   160,
     161,   162,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   194,   198,   199,   200,   201,   202,   203,   204,
     205
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING_LITERAL",
  "SIZEOF", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "CHAR", "INT", "LONG", "SIGNED",
  "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOID", "STRUCT", "UNION",
  "ENUM", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR",
  "GOTO", "CONTINUE", "BREAK", "RETURN", "IDENTIFIER", "CONSTANTf",
  "CONSTANTi", "','", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'~'", "'!'",
  "$accept", "ssc", "external_declaration", "declaration",
  "declaration_specifiers", "parameter_list", "function_definition",
  "compound_statement", "declaration_list", "statement_list", "statement",
  "expression_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "expression", "type_qualifier",
  "type_specifier", YY_NULLPTR
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
     295,   296,    44,    61,    62,    60,    43,    45,    42,    47,
      37,    59,    40,    41,   123,   125,    91,    93,   126,    33
};
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     419,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     462,   -91,   -91,   -35,   -91,   449,   -91,   -91,   -91,    46,
     -91,    80,   -91,   252,   -91,   -18,   -91,   -91,    80,   327,
     -44,    -4,   -39,    80,    80,   184,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,   -91,
      30,   -91,   -91,   419,   -44,    -6,   383,   139,   -91,    68,
      68,   320,   320,   412,   406,   400,    68,    68,   -40,   -40,
     -91,   -91,   -13,     4,     5,     8,    33,    22,    25,   170,
     -91,   -91,   -91,    41,   -91,    72,    99,   -91,   -91,   -91,
     -91,   -91,   336,    57,   -91,    80,   -91,   -91,    80,    80,
      80,   173,    48,   -91,   -91,   -91,   353,   -11,   -91,   -91,
     126,   -91,   -91,   -91,   -91,   383,   233,   244,   255,   173,
     -91,   -91,   -91,   166,   166,   166,     2,    70,   -91,   -91,
     166,   304,   166,   -91,   166,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    70,    64,    65,    69,    68,    66,    67,    62,    63,
       0,     2,     5,     0,     4,     0,     9,     1,     3,     0,
       8,     0,     6,     0,    60,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,    13,    10,     0,     0,     0,    28,     0,    61,    48,
      50,    51,    49,    46,    47,    54,    53,    52,    42,    43,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    14,    18,     0,    22,     0,     0,    20,    23,    24,
      25,    26,     0,     0,    12,     0,    56,    55,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,    16,    19,
       0,    15,    21,    30,    11,    27,     0,     0,     0,     0,
      37,    41,    17,     0,     0,     0,     0,    32,    33,    34,
       0,     0,     0,    35,     0,    31,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   108,   -48,   -22,   -91,   -91,   -24,   -91,    37,
     197,   -91,   -90,   -91,   -91,   -91,   -21,   -91,   110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    32,    14,    84,    85,    86,
      87,    55,    88,    89,    90,    91,    92,    15,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    31,    82,    53,    19,    24,    51,    35,    47,    48,
      50,   119,    56,    57,    54,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    83,   126,
      94,    93,    21,    24,    33,    52,    95,   109,    34,    98,
      22,    25,    26,    27,     1,     2,     3,    96,     4,     5,
       6,     7,     8,     9,    28,   130,    99,   100,   106,    72,
     101,    73,    74,    83,    75,    76,    77,    78,    79,    25,
      26,    27,   102,   103,   115,    24,   104,   116,   117,   118,
     107,    80,    28,    24,    50,    81,     1,     2,     3,    21,
       4,     5,     6,     7,     8,     9,   114,    22,    23,   120,
     132,    72,    24,    73,    74,   131,    75,    76,    77,    78,
      79,    25,    26,    27,    45,    46,    47,    48,    18,    25,
      26,    27,   110,    80,    28,    20,    50,   108,    72,    24,
      73,    74,    28,    75,    76,    77,    78,    79,    25,    26,
      27,     0,     0,     0,    36,    37,    38,    39,    40,    41,
      80,    28,     0,    50,   111,    72,     0,    73,    74,     0,
      75,    76,    77,    78,    79,    25,    26,    27,     0,    24,
       0,     0,     0,    24,     0,     0,    24,    80,    28,     0,
      50,   122,    42,    43,    44,    45,    46,    47,    48,    36,
      37,    38,    39,    40,    41,    72,    97,    73,    74,     0,
      75,    76,    77,    78,    79,    25,    26,    27,     0,    25,
      26,    27,    25,    26,    27,     0,     0,    80,    28,     0,
      50,   105,    28,     0,    80,    28,     0,    42,    43,    44,
      45,    46,    47,    48,     0,     0,     0,    58,    36,    37,
      38,    39,    40,    41,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,    41,     1,     2,     3,     0,
       4,     5,     6,     7,     8,     9,    42,    43,    44,    45,
      46,    47,    48,   112,     0,     0,   123,    42,    43,    44,
      45,    46,    47,    48,     0,     0,     0,   124,    42,    43,
      44,    45,    46,    47,    48,    30,     0,   112,   125,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,     0,
     127,   128,   129,     0,     0,    36,    37,   133,     0,   135,
       0,   136,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,     0,     0,   134,    36,    37,
      38,    39,    40,    41,    43,    44,    45,    46,    47,    48,
      42,    43,    44,    45,    46,    47,    48,     0,    49,    42,
      43,    44,    45,    46,    47,    48,     0,   113,    36,    37,
      38,    39,    40,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,     0,   121,    36,    37,    38,    39,    40,
      41,    36,    37,    38,    39,    40,     0,    36,    37,    38,
      39,     0,     0,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    48,     1,     2,     3,     0,     4,     5,     6,
       7,     8,     9,     0,    43,    44,    45,    46,    47,    48,
      43,    44,    45,    46,    47,    48,    43,    44,    45,    46,
      47,    48,    17,     1,     2,     3,     0,     4,     5,     6,
       7,     0,     9,     0,     0,     0,     1,     2,     3,     0,
       4,     5,     6,     7,     8,     9
};

static const yytype_int16 yycheck[] =
{
      21,    23,    50,    42,    39,     3,    30,    28,    48,    49,
      54,   101,    33,    34,    53,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    50,   119,
      54,    53,    43,     3,    52,    39,    42,    85,    56,    52,
      51,    39,    40,    41,    14,    15,    16,    53,    18,    19,
      20,    21,    22,    23,    52,    53,    52,    52,    79,    29,
      52,    31,    32,    85,    34,    35,    36,    37,    38,    39,
      40,    41,    39,    51,    95,     3,    51,    98,    99,   100,
      39,    51,    52,     3,    54,    55,    14,    15,    16,    43,
      18,    19,    20,    21,    22,    23,    39,    51,    52,    51,
      30,    29,     3,    31,    32,   126,    34,    35,    36,    37,
      38,    39,    40,    41,    46,    47,    48,    49,    10,    39,
      40,    41,    85,    51,    52,    15,    54,    55,    29,     3,
      31,    32,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      51,    52,    -1,    54,    55,    29,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,     3,
      -1,    -1,    -1,     3,    -1,    -1,     3,    51,    52,    -1,
      54,    55,    43,    44,    45,    46,    47,    48,    49,     5,
       6,     7,     8,     9,    10,    29,    57,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    39,
      40,    41,    39,    40,    41,    -1,    -1,    51,    52,    -1,
      54,    51,    52,    -1,    51,    52,    -1,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    43,    44,    45,    46,
      47,    48,    49,    86,    -1,    -1,    53,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    43,    44,
      45,    46,    47,    48,    49,    53,    -1,   110,    53,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,    -1,    -1,     5,     6,   130,    -1,   132,
      -1,   134,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,     5,     6,
       7,     8,     9,    10,    44,    45,    46,    47,    48,    49,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,     5,     6,
       7,     8,     9,    10,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,     5,     6,     7,     8,     9,
      10,     5,     6,     7,     8,     9,    -1,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    44,    45,    46,    47,    48,    49,
      44,    45,    46,    47,    48,    49,    44,    45,    46,    47,
      48,    49,     0,    14,    15,    16,    -1,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    -1,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    16,    18,    19,    20,    21,    22,    23,
      61,    62,    63,    64,    66,    77,    78,     0,    62,    39,
      78,    43,    51,    52,     3,    39,    40,    41,    52,    76,
      53,    64,    65,    52,    56,    76,     5,     6,     7,     8,
       9,    10,    43,    44,    45,    46,    47,    48,    49,    51,
      54,    67,    39,    42,    53,    71,    76,    76,    53,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    29,    31,    32,    34,    35,    36,    37,    38,
      51,    55,    63,    64,    67,    68,    69,    70,    72,    73,
      74,    75,    76,    64,    67,    42,    53,    57,    52,    52,
      52,    52,    39,    51,    51,    51,    76,    39,    55,    63,
      69,    55,    70,    51,    39,    76,    76,    76,    76,    72,
      51,    51,    55,    53,    53,    53,    72,    70,    70,    70,
      53,    76,    30,    70,    53,    70,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     5,     2,     1,
       2,     4,     6,     5,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     7,     5,     5,     5,     6,     7,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  case 2: /* ssc: external_declaration  */
#line 53 "parse.y"
                               {head->insert((yyvsp[0].node));}
#line 1323 "parse.tab.cc"
    break;

  case 3: /* ssc: ssc external_declaration  */
#line 54 "parse.y"
                                   {head->insert((yyvsp[0].node));}
#line 1329 "parse.tab.cc"
    break;

  case 4: /* external_declaration: function_definition  */
#line 59 "parse.y"
                              {
                (yyval.node) = new AST("FunctionDecl"); 
                (yyval.node)->child = (yyvsp[0].node)->child; // para和compound statement 孩子
                (yyval.node)->ID = (yyvsp[0].node)->ID; (yyval.node)->dtype = (yyvsp[0].node)->dtype; // 函数名 返回类型
                }
#line 1339 "parse.tab.cc"
    break;

  case 5: /* external_declaration: declaration  */
#line 64 "parse.y"
                      {
                (yyval.node) =new AST("VarDecl");(yyval.node)->dtype = (yyvsp[0].node)->dtype; 
                (yyval.node)->ID = (yyvsp[0].node)->ID;(yyval.node)->child = (yyvsp[0].node)->child; // expr 孩子
                // std::cout<<$$->child->size();  
                }
#line 1349 "parse.tab.cc"
    break;

  case 6: /* declaration: declaration_specifiers IDENTIFIER ';'  */
#line 73 "parse.y"
                                                {(yyval.node) = new AST("VarDecl"); (yyval.node)->dtype = (yyvsp[-2].node)->tokentype;(yyval.node)->ID = (yyvsp[-1].str); }
#line 1355 "parse.tab.cc"
    break;

  case 7: /* declaration: declaration_specifiers IDENTIFIER '=' expression ';'  */
#line 74 "parse.y"
                                                               {(yyval.node) = new AST("VarDecl"); (yyval.node)->dtype = (yyvsp[-4].node)->tokentype;(yyval.node)->ID = (yyvsp[-3].str);(yyval.node)->insert((yyvsp[-1].node));}
#line 1361 "parse.tab.cc"
    break;

  case 8: /* declaration_specifiers: type_qualifier type_specifier  */
#line 78 "parse.y"
                                        {}
#line 1367 "parse.tab.cc"
    break;

  case 9: /* declaration_specifiers: type_specifier  */
#line 79 "parse.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 1373 "parse.tab.cc"
    break;

  case 10: /* parameter_list: declaration_specifiers IDENTIFIER  */
#line 94 "parse.y"
                                            {(yyval.node) = new AST("ParmVarDecl"); AST* temp = new AST("ParmVarDecl");
                temp->ID = (yyvsp[0].str); temp->dtype = (yyvsp[-1].node)->tokentype; (yyval.node)->insert(temp);}
#line 1380 "parse.tab.cc"
    break;

  case 11: /* parameter_list: parameter_list ',' declaration_specifiers IDENTIFIER  */
#line 96 "parse.y"
                                                               {(yyval.node) = (yyvsp[-3].node); AST* temp = new AST("ParmVarDecl");
                temp->ID = (yyvsp[0].str); temp->dtype = (yyvsp[-1].node)->tokentype; (yyval.node)->insert(temp);}
#line 1387 "parse.tab.cc"
    break;

  case 12: /* function_definition: declaration_specifiers IDENTIFIER '(' parameter_list ')' compound_statement  */
#line 102 "parse.y"
                                                                                      {
                (yyval.node) = new AST("test"); (yyval.node)->ID = (yyvsp[-4].str); (yyval.node)->dtype=(yyvsp[-5].node)->tokentype; // 同下
                (yyval.node)->child = (yyvsp[-2].node)->child; (yyval.node)->insert((yyvsp[0].node)); 
                }
#line 1396 "parse.tab.cc"
    break;

  case 13: /* function_definition: declaration_specifiers IDENTIFIER '(' ')' compound_statement  */
#line 106 "parse.y"
                                                                       {(yyval.node) = new AST("test"); (yyval.node)->ID = (yyvsp[-3].str); (yyval.node)->dtype=(yyvsp[-4].node)->tokentype;(yyval.node)->insert((yyvsp[0].node));}
#line 1402 "parse.tab.cc"
    break;

  case 14: /* compound_statement: '{' '}'  */
#line 110 "parse.y"
                  {(yyval.node) = new AST("CompoundStmt"); }
#line 1408 "parse.tab.cc"
    break;

  case 15: /* compound_statement: '{' statement_list '}'  */
#line 111 "parse.y"
                                 {(yyval.node) = new AST("CompoundStmt"); (yyval.node)->child = (yyvsp[-1].node)->child; }
#line 1414 "parse.tab.cc"
    break;

  case 16: /* compound_statement: '{' declaration_list '}'  */
#line 112 "parse.y"
                                   {(yyval.node) = new AST("CompoundStmt"); (yyval.node)->child = (yyvsp[-1].node)->child;}
#line 1420 "parse.tab.cc"
    break;

  case 17: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 113 "parse.y"
                                                  {(yyval.node) = new AST("CompoundStmt"); (yyval.node)->child = (yyvsp[-2].node)->child;(yyval.node)->copy_child((yyvsp[-1].node));}
#line 1426 "parse.tab.cc"
    break;

  case 18: /* declaration_list: declaration  */
#line 117 "parse.y"
                      {(yyval.node) = new AST("test"); (yyval.node)->insert((yyvsp[0].node));}
#line 1432 "parse.tab.cc"
    break;

  case 19: /* declaration_list: declaration_list declaration  */
#line 118 "parse.y"
                                        {(yyval.node) = (yyvsp[-1].node); (yyval.node)->insert((yyvsp[0].node));}
#line 1438 "parse.tab.cc"
    break;

  case 20: /* statement_list: statement  */
#line 122 "parse.y"
                    {(yyval.node) = new AST("test"); (yyval.node)->insert((yyvsp[0].node));}
#line 1444 "parse.tab.cc"
    break;

  case 21: /* statement_list: statement_list statement  */
#line 123 "parse.y"
                                   {(yyval.node) = (yyvsp[-1].node); (yyval.node)->insert((yyvsp[0].node));}
#line 1450 "parse.tab.cc"
    break;

  case 22: /* statement: compound_statement  */
#line 127 "parse.y"
                             {(yyval.node) = (yyvsp[0].node); }
#line 1456 "parse.tab.cc"
    break;

  case 23: /* statement: expression_statement  */
#line 128 "parse.y"
                               {(yyval.node) = (yyvsp[0].node); }
#line 1462 "parse.tab.cc"
    break;

  case 24: /* statement: selection_statement  */
#line 129 "parse.y"
                              {(yyval.node) = (yyvsp[0].node); }
#line 1468 "parse.tab.cc"
    break;

  case 25: /* statement: iteration_statement  */
#line 130 "parse.y"
                              {(yyval.node) = (yyvsp[0].node); }
#line 1474 "parse.tab.cc"
    break;

  case 26: /* statement: jump_statement  */
#line 131 "parse.y"
                         {(yyval.node) = (yyvsp[0].node); }
#line 1480 "parse.tab.cc"
    break;

  case 27: /* expression_list: expression_list ',' expression  */
#line 135 "parse.y"
                                         {(yyval.node) = (yyvsp[-2].node); (yyval.node)->insert((yyvsp[0].node));}
#line 1486 "parse.tab.cc"
    break;

  case 28: /* expression_list: expression  */
#line 136 "parse.y"
                     {(yyval.node) = new AST("test"); (yyval.node)->insert((yyvsp[0].node));}
#line 1492 "parse.tab.cc"
    break;

  case 29: /* expression_statement: ';'  */
#line 140 "parse.y"
              {(yyval.node) = new AST("NullStmt");}
#line 1498 "parse.tab.cc"
    break;

  case 30: /* expression_statement: expression ';'  */
#line 141 "parse.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 1504 "parse.tab.cc"
    break;

  case 31: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 145 "parse.y"
                                                         {(yyval.node) = new AST("IfStmt");(yyval.node)->insert((yyvsp[-4].node));(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1510 "parse.tab.cc"
    break;

  case 32: /* selection_statement: IF '(' expression ')' statement  */
#line 146 "parse.y"
                                          {(yyval.node) = new AST("IfStmt");}
#line 1516 "parse.tab.cc"
    break;

  case 33: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 147 "parse.y"
                                              {}
#line 1522 "parse.tab.cc"
    break;

  case 34: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 151 "parse.y"
                                             {(yyval.node) = new AST("WhileStmt"); (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1528 "parse.tab.cc"
    break;

  case 35: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 153 "parse.y"
                                                                          {(yyval.node) = new AST("ForStmt"); (yyval.node)->insert((yyvsp[-3].node));(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1534 "parse.tab.cc"
    break;

  case 36: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 154 "parse.y"
                                                                                     {(yyval.node) = new AST("ForStmt");(yyval.node)->insert((yyvsp[-4].node));(yyval.node)->insert((yyvsp[-3].node));(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1540 "parse.tab.cc"
    break;

  case 37: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 158 "parse.y"
                              {}
#line 1546 "parse.tab.cc"
    break;

  case 38: /* jump_statement: CONTINUE ';'  */
#line 159 "parse.y"
                       {(yyval.node) =  new AST("ContinueStmt");}
#line 1552 "parse.tab.cc"
    break;

  case 39: /* jump_statement: BREAK ';'  */
#line 160 "parse.y"
                    {(yyval.node) = new AST("BreakStmt");}
#line 1558 "parse.tab.cc"
    break;

  case 40: /* jump_statement: RETURN ';'  */
#line 161 "parse.y"
                     {(yyval.node) = new AST("ReturnStmt");}
#line 1564 "parse.tab.cc"
    break;

  case 41: /* jump_statement: RETURN expression ';'  */
#line 162 "parse.y"
                                {(yyval.node) = new AST("ReturnStmt"); (yyval.node)->insert((yyvsp[-1].node)); }
#line 1570 "parse.tab.cc"
    break;

  case 42: /* expression: expression '+' expression  */
#line 166 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="+"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1576 "parse.tab.cc"
    break;

  case 43: /* expression: expression '-' expression  */
#line 167 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="-"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1582 "parse.tab.cc"
    break;

  case 44: /* expression: expression '*' expression  */
#line 168 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="*"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1588 "parse.tab.cc"
    break;

  case 45: /* expression: expression '/' expression  */
#line 169 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="/"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1594 "parse.tab.cc"
    break;

  case 46: /* expression: expression AND_OP expression  */
#line 170 "parse.y"
                                       {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="&&"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1600 "parse.tab.cc"
    break;

  case 47: /* expression: expression OR_OP expression  */
#line 171 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="||"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1606 "parse.tab.cc"
    break;

  case 48: /* expression: expression LE_OP expression  */
#line 172 "parse.y"
                                       {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="<="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1612 "parse.tab.cc"
    break;

  case 49: /* expression: expression NE_OP expression  */
#line 173 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="!="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1618 "parse.tab.cc"
    break;

  case 50: /* expression: expression GE_OP expression  */
#line 174 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop=">="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1624 "parse.tab.cc"
    break;

  case 51: /* expression: expression EQ_OP expression  */
#line 175 "parse.y"
                                        {(yyval.node) = new AST("BinaryOperator"); (yyval.node)->binaryop="==";(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1630 "parse.tab.cc"
    break;

  case 52: /* expression: expression '<' expression  */
#line 176 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator"); (yyval.node)->binaryop="<";(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1636 "parse.tab.cc"
    break;

  case 53: /* expression: expression '>' expression  */
#line 177 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator"); (yyval.node)->binaryop=">";(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1642 "parse.tab.cc"
    break;

  case 54: /* expression: expression '=' expression  */
#line 178 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1648 "parse.tab.cc"
    break;

  case 55: /* expression: IDENTIFIER '[' expression ']'  */
#line 179 "parse.y"
                                        {}
#line 1654 "parse.tab.cc"
    break;

  case 56: /* expression: IDENTIFIER '(' expression_list ')'  */
#line 180 "parse.y"
                                             {(yyval.node) = new AST("CallExpr"); (yyval.node)->ID = (yyvsp[-3].str); (yyval.node)->child = (yyvsp[-1].node)->child;}
#line 1660 "parse.tab.cc"
    break;

  case 57: /* expression: IDENTIFIER  */
#line 181 "parse.y"
                     {(yyval.node) = new AST("Identifier"); (yyval.node)->ID = (yyvsp[0].str); }
#line 1666 "parse.tab.cc"
    break;

  case 58: /* expression: CONSTANTf  */
#line 182 "parse.y"
                    {(yyval.node) = new AST("Constant"); (yyval.node)->dvalue = (yyvsp[0].numf); (yyval.node)->dtype = "float"; }
#line 1672 "parse.tab.cc"
    break;

  case 59: /* expression: CONSTANTi  */
#line 183 "parse.y"
                    {(yyval.node) = new AST("Constant"); (yyval.node)->dvalue = (yyvsp[0].numi); (yyval.node)->dtype = "int";}
#line 1678 "parse.tab.cc"
    break;

  case 60: /* expression: STRING_LITERAL  */
#line 184 "parse.y"
                         {}
#line 1684 "parse.tab.cc"
    break;

  case 61: /* expression: '(' expression ')'  */
#line 185 "parse.y"
                             {(yyval.node) = new AST("ParenExpr"); (yyval.node)->insert((yyvsp[-1].node));}
#line 1690 "parse.tab.cc"
    break;

  case 62: /* type_qualifier: CONST  */
#line 194 "parse.y"
                {(yyval.node) = new AST("const");}
#line 1696 "parse.tab.cc"
    break;

  case 63: /* type_specifier: VOID  */
#line 198 "parse.y"
               {(yyval.node) = new AST("void");}
#line 1702 "parse.tab.cc"
    break;

  case 64: /* type_specifier: CHAR  */
#line 199 "parse.y"
               {(yyval.node) = new AST("char");}
#line 1708 "parse.tab.cc"
    break;

  case 65: /* type_specifier: INT  */
#line 200 "parse.y"
              {(yyval.node) = new AST("int");}
#line 1714 "parse.tab.cc"
    break;

  case 66: /* type_specifier: FLOAT  */
#line 201 "parse.y"
                {(yyval.node) = new AST("float");}
#line 1720 "parse.tab.cc"
    break;

  case 67: /* type_specifier: DOUBLE  */
#line 202 "parse.y"
                 {(yyval.node) = new AST("double");}
#line 1726 "parse.tab.cc"
    break;

  case 68: /* type_specifier: UNSIGNED  */
#line 203 "parse.y"
                   {(yyval.node) = new AST("unsigned");}
#line 1732 "parse.tab.cc"
    break;

  case 69: /* type_specifier: SIGNED  */
#line 204 "parse.y"
                  {(yyval.node) = new AST("signed");}
#line 1738 "parse.tab.cc"
    break;

  case 70: /* type_specifier: AUTO  */
#line 205 "parse.y"
               {(yyval.node) = new AST("auto");}
#line 1744 "parse.tab.cc"
    break;


#line 1748 "parse.tab.cc"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
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

  return yyresult;
}

#line 217 "parse.y"





void yyerror(const char *s) {
    fprintf(stderr, "line %d: %s at %s\n",yylineno, s,yytext);
}

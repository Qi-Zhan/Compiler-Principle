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
    void yyerror(char *s);
    extern int yylineno;
    extern FILE* yyin;
    extern char* yytext;
    extern int yylex(void);
    extern int yylineno;
    int AST::order = 0;
    AST head = AST("translation unit");

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

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
       0,    51,    51,    52,    57,    58,    67,    68,    72,    73,
      88,    89,    94,    95,    99,   100,   101,   102,   105,   106,
     110,   111,   115,   116,   117,   118,   119,   123,   124,   128,
     129,   133,   134,   135,   139,   140,   141,   142,   146,   147,
     148,   149,   150,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   180,   184,   185,   186,   187,   188,   189,   190
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

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     470,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   458,
     -89,   -89,   -30,   -89,   479,   -89,   -89,   -89,     0,   -89,
      29,   -89,   434,   -89,   -22,   -89,   -89,    29,   340,   -52,
      -6,    -3,    29,    29,   213,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,   -89,    77,   -89,   -89,
     470,   -52,    19,   387,   168,   -89,    18,    18,   399,   399,
     420,   393,   414,   -12,   -12,   -89,   -89,     6,    21,    30,
     197,    31,    45,    34,    36,     5,   -89,   -89,   -89,    50,
     -89,   104,   131,   -89,   -89,   -89,   -89,   -89,   360,    51,
     -89,    29,   -89,   -89,    29,    29,    29,    62,     8,    52,
     -89,   -89,   -89,   367,   -37,   -89,   -89,   158,   -89,   -89,
     -89,   -89,   387,   234,   262,   283,    49,     8,   -89,   -89,
     -89,   197,   197,   197,    29,     1,    72,   -89,   -89,   291,
     197,   311,   197,    70,   -89,   197,   -89,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    63,    64,    68,    67,    65,    66,    61,    62,     0,
       2,     5,     0,     4,     0,     9,     1,     3,     0,     8,
       0,     6,     0,    59,    56,    57,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,    13,    10,
       0,     0,     0,    28,     0,    60,    49,    51,    52,    50,
      47,    48,    53,    43,    44,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    14,    18,     0,
      22,     0,     0,    20,    23,    24,    25,    26,     0,     0,
      12,     0,    55,    54,     0,     0,     0,     0,     0,     0,
      39,    40,    41,     0,     0,    16,    19,     0,    15,    21,
      30,    11,    27,     0,     0,     0,     0,     0,    38,    42,
      17,     0,     0,     0,     0,     0,    32,    33,    34,     0,
       0,     0,     0,     0,    36,     0,    31,    35,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   121,   -46,   -19,   -89,   -89,   -24,   -89,    65,
     -44,   -89,   -88,   -89,   -89,   -89,   -20,   -89,   133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    31,    13,    80,    81,    82,
      83,    52,    84,    85,    86,    87,    88,    14,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    78,    47,    30,    23,    48,    20,    34,    23,    18,
     117,    23,    53,    54,    21,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    97,    90,    79,   125,
      32,    89,    23,    49,    33,   106,    44,    45,   109,    50,
      24,    25,    26,    20,    24,    25,    26,    24,    25,    26,
      51,    21,    22,    27,   130,   103,   102,    27,    94,    76,
      27,    91,    79,   109,    42,    43,    44,    45,    24,    25,
      26,   112,    92,    95,   113,   114,   115,   126,   127,   128,
      23,    27,    96,    98,    99,   100,   134,   101,   136,   104,
     111,   138,     1,     2,   116,     3,     4,     5,     6,     7,
       8,   124,   132,   118,   129,   131,    67,    23,    68,    69,
      70,    71,    72,    73,    74,    75,    24,    25,    26,     1,
       2,   137,     3,     4,     5,     6,     7,     8,    76,    27,
      17,    47,    77,    67,    23,    68,    69,    70,    71,    72,
      73,    74,    75,    24,    25,    26,   107,    19,     0,     0,
       0,     0,     0,     0,     0,    76,    27,     0,    47,   105,
      67,    23,    68,    69,    70,    71,    72,    73,    74,    75,
      24,    25,    26,    35,    36,    37,    38,    39,    40,     0,
       0,     0,    76,    27,     0,    47,   108,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    24,    25,    26,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      27,    41,    47,   120,    42,    43,    44,    45,    35,    36,
      37,    38,    39,    40,     0,    93,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    24,    25,    26,    35,
      36,    37,    38,    39,    40,     0,     0,     0,    76,    27,
       0,    47,     0,     0,     0,     0,    41,     0,     0,    42,
      43,    44,    45,     0,     0,     0,    55,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,    41,     0,     0,
      42,    43,    44,    45,     0,     0,     0,   121,    35,    36,
      37,    38,    39,    40,     0,     0,    35,    36,    37,    38,
      39,    40,     0,     0,     0,    41,     0,     0,    42,    43,
      44,    45,     0,     0,     0,   122,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,    41,     0,     0,    42,
      43,    44,    45,     0,    41,     0,   123,    42,    43,    44,
      45,     0,     0,     0,   133,    35,    36,    37,    38,    39,
      40,     0,     0,     0,    41,     0,     0,    42,    43,    44,
      45,     0,     0,     0,   135,    35,    36,    37,    38,    39,
      40,     0,    35,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,    41,     0,     0,    42,    43,    44,    45,
       0,    46,    35,    36,    37,    38,    39,    40,    35,    36,
      37,    38,    39,    41,    35,    36,    42,    43,    44,    45,
      41,   110,     0,    42,    43,    44,    45,     0,   119,    35,
      36,    37,    38,    39,    40,    35,    36,    37,    38,     0,
      41,     0,     0,    42,    43,    44,    45,     0,     0,    42,
      43,    44,    45,     0,     0,    42,    43,    44,    45,     1,
       2,     0,     3,     4,     5,     6,     7,     8,    16,     0,
      42,    43,    44,    45,     0,     0,    42,    43,    44,    45,
       0,     0,     0,     1,     2,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     1,     2,    29,     3,     4,
       5,     6,     7,     8,     1,     2,     0,     3,     4,     5,
       6,     0,     8
};

static const yytype_int16 yycheck[] =
{
      20,    47,    54,    22,     3,    29,    43,    27,     3,    39,
      98,     3,    32,    33,    51,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    70,    51,    47,   117,
      52,    50,     3,    39,    56,    81,    48,    49,    82,    42,
      39,    40,    41,    43,    39,    40,    41,    39,    40,    41,
      53,    51,    52,    52,    53,    75,    51,    52,    52,    51,
      52,    42,    81,   107,    46,    47,    48,    49,    39,    40,
      41,    91,    53,    52,    94,    95,    96,   121,   122,   123,
       3,    52,    52,    52,    39,    51,   130,    51,   132,    39,
      39,   135,    15,    16,    32,    18,    19,    20,    21,    22,
      23,    52,    30,    51,   124,   125,    29,     3,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    15,
      16,    51,    18,    19,    20,    21,    22,    23,    51,    52,
       9,    54,    55,    29,     3,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    81,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,    55,
      29,     3,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    43,    54,    55,    46,    47,    48,    49,     5,     6,
       7,     8,     9,    10,    -1,    57,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    51,    52,
      -1,    54,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    -1,    53,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    53,     5,     6,
       7,     8,     9,    10,    -1,    -1,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    53,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    -1,    43,    -1,    53,    46,    47,    48,
      49,    -1,    -1,    -1,    53,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    53,     5,     6,     7,     8,     9,
      10,    -1,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,    49,
      -1,    51,     5,     6,     7,     8,     9,    10,     5,     6,
       7,     8,     9,    43,     5,     6,    46,    47,    48,    49,
      43,    51,    -1,    46,    47,    48,    49,    -1,    51,     5,
       6,     7,     8,     9,    10,     5,     6,     7,     8,    -1,
      43,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    46,    47,    48,    49,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,     0,    -1,
      46,    47,    48,    49,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    15,    16,    53,    18,    19,
      20,    21,    22,    23,    15,    16,    -1,    18,    19,    20,
      21,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    18,    19,    20,    21,    22,    23,    61,
      62,    63,    64,    66,    77,    78,     0,    62,    39,    78,
      43,    51,    52,     3,    39,    40,    41,    52,    76,    53,
      64,    65,    52,    56,    76,     5,     6,     7,     8,     9,
      10,    43,    46,    47,    48,    49,    51,    54,    67,    39,
      42,    53,    71,    76,    76,    53,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    29,    31,    32,
      33,    34,    35,    36,    37,    38,    51,    55,    63,    64,
      67,    68,    69,    70,    72,    73,    74,    75,    76,    64,
      67,    42,    53,    57,    52,    52,    52,    70,    52,    39,
      51,    51,    51,    76,    39,    55,    63,    69,    55,    70,
      51,    39,    76,    76,    76,    76,    32,    72,    51,    51,
      55,    53,    53,    53,    52,    72,    70,    70,    70,    76,
      53,    76,    30,    53,    70,    53,    70,    51,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    78,    78,    78,    78,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     5,     2,     1,
       2,     4,     6,     5,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     7,     5,     5,     5,     7,     6,     7,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 51 "parse.y"
                               {head.insert((yyvsp[0].node));}
#line 1324 "parse.tab.cc"
    break;

  case 3: /* ssc: ssc external_declaration  */
#line 52 "parse.y"
                                   {head.insert((yyvsp[0].node));}
#line 1330 "parse.tab.cc"
    break;

  case 4: /* external_declaration: function_definition  */
#line 57 "parse.y"
                              {(yyval.node) = new AST("FunctionDecl"); }
#line 1336 "parse.tab.cc"
    break;

  case 5: /* external_declaration: declaration  */
#line 58 "parse.y"
                      {
                (yyval.node) =new AST("VarDecl");(yyval.node)->dtype = (yyvsp[0].node)->dtype; 
                (yyval.node)->ID = (yyvsp[0].node)->ID;(yyval.node)->child = (yyvsp[0].node)->child;
                // std::cout<<$$->child->size();  
                }
#line 1346 "parse.tab.cc"
    break;

  case 6: /* declaration: declaration_specifiers IDENTIFIER ';'  */
#line 67 "parse.y"
                                                {(yyval.node) = new AST("test"); (yyval.node)->dtype = (yyvsp[-2].node)->tokentype;(yyval.node)->ID = (yyvsp[-1].str); }
#line 1352 "parse.tab.cc"
    break;

  case 7: /* declaration: declaration_specifiers IDENTIFIER '=' expression ';'  */
#line 68 "parse.y"
                                                               {(yyval.node) = new AST("test"); (yyval.node)->dtype = (yyvsp[-4].node)->tokentype;(yyval.node)->ID = (yyvsp[-3].str);(yyval.node)->insert((yyvsp[-1].node));}
#line 1358 "parse.tab.cc"
    break;

  case 8: /* declaration_specifiers: type_qualifier type_specifier  */
#line 72 "parse.y"
                                        {}
#line 1364 "parse.tab.cc"
    break;

  case 9: /* declaration_specifiers: type_specifier  */
#line 73 "parse.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 1370 "parse.tab.cc"
    break;

  case 12: /* function_definition: declaration_specifiers IDENTIFIER '(' parameter_list ')' compound_statement  */
#line 94 "parse.y"
                                                                                      {}
#line 1376 "parse.tab.cc"
    break;

  case 13: /* function_definition: declaration_specifiers IDENTIFIER '(' ')' compound_statement  */
#line 95 "parse.y"
                                                                       {}
#line 1382 "parse.tab.cc"
    break;

  case 29: /* expression_statement: ';'  */
#line 128 "parse.y"
              {}
#line 1388 "parse.tab.cc"
    break;

  case 30: /* expression_statement: expression ';'  */
#line 129 "parse.y"
                         {}
#line 1394 "parse.tab.cc"
    break;

  case 31: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 133 "parse.y"
                                                         {}
#line 1400 "parse.tab.cc"
    break;

  case 32: /* selection_statement: IF '(' expression ')' statement  */
#line 134 "parse.y"
                                          {}
#line 1406 "parse.tab.cc"
    break;

  case 33: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 135 "parse.y"
                                              {}
#line 1412 "parse.tab.cc"
    break;

  case 43: /* expression: expression '+' expression  */
#line 154 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="+"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1418 "parse.tab.cc"
    break;

  case 44: /* expression: expression '-' expression  */
#line 155 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="-"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1424 "parse.tab.cc"
    break;

  case 45: /* expression: expression '*' expression  */
#line 156 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="*"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1430 "parse.tab.cc"
    break;

  case 46: /* expression: expression '/' expression  */
#line 157 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="/"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1436 "parse.tab.cc"
    break;

  case 47: /* expression: expression AND_OP expression  */
#line 158 "parse.y"
                                       {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="&&"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1442 "parse.tab.cc"
    break;

  case 48: /* expression: expression OR_OP expression  */
#line 159 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="||"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1448 "parse.tab.cc"
    break;

  case 49: /* expression: expression LE_OP expression  */
#line 160 "parse.y"
                                       {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="<="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1454 "parse.tab.cc"
    break;

  case 50: /* expression: expression NE_OP expression  */
#line 161 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="!="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1460 "parse.tab.cc"
    break;

  case 51: /* expression: expression GE_OP expression  */
#line 162 "parse.y"
                                      {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop=">="; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1466 "parse.tab.cc"
    break;

  case 52: /* expression: expression EQ_OP expression  */
#line 163 "parse.y"
                                        {(yyval.node) = new AST("BinaryOperator"); (yyval.node)->binaryop="==";(yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1472 "parse.tab.cc"
    break;

  case 53: /* expression: expression '=' expression  */
#line 164 "parse.y"
                                    {(yyval.node) = new AST("BinaryOperator");(yyval.node)->binaryop="+"; (yyval.node)->insert((yyvsp[-2].node));(yyval.node)->insert((yyvsp[0].node));}
#line 1478 "parse.tab.cc"
    break;

  case 54: /* expression: IDENTIFIER '[' expression ']'  */
#line 165 "parse.y"
                                        {}
#line 1484 "parse.tab.cc"
    break;

  case 55: /* expression: IDENTIFIER '(' expression_list ')'  */
#line 166 "parse.y"
                                             {}
#line 1490 "parse.tab.cc"
    break;

  case 56: /* expression: IDENTIFIER  */
#line 167 "parse.y"
                     {(yyval.node) = new AST("Identifier"); (yyval.node)->ID = (yyvsp[0].str);}
#line 1496 "parse.tab.cc"
    break;

  case 57: /* expression: CONSTANTf  */
#line 168 "parse.y"
                    {(yyval.node) = new AST("Constant"); (yyval.node)->dvaule = (yyvsp[0].numf); (yyval.node)->dtype = "float"; }
#line 1502 "parse.tab.cc"
    break;

  case 58: /* expression: CONSTANTi  */
#line 169 "parse.y"
                    {(yyval.node) = new AST("Constant"); (yyval.node)->dvaule = (yyvsp[0].numi); (yyval.node)->dtype = "int";}
#line 1508 "parse.tab.cc"
    break;

  case 59: /* expression: STRING_LITERAL  */
#line 170 "parse.y"
                         {}
#line 1514 "parse.tab.cc"
    break;

  case 60: /* expression: '(' expression ')'  */
#line 171 "parse.y"
                             {(yyval.node) = new AST("ParenExpr"); (yyval.node)->insert((yyvsp[-1].node));}
#line 1520 "parse.tab.cc"
    break;

  case 61: /* type_qualifier: CONST  */
#line 180 "parse.y"
                {(yyval.node) = new AST("const");}
#line 1526 "parse.tab.cc"
    break;

  case 62: /* type_specifier: VOID  */
#line 184 "parse.y"
               {(yyval.node) = new AST("void");}
#line 1532 "parse.tab.cc"
    break;

  case 63: /* type_specifier: CHAR  */
#line 185 "parse.y"
               {(yyval.node) = new AST("char");}
#line 1538 "parse.tab.cc"
    break;

  case 64: /* type_specifier: INT  */
#line 186 "parse.y"
              {(yyval.node) = new AST("int");}
#line 1544 "parse.tab.cc"
    break;

  case 65: /* type_specifier: FLOAT  */
#line 187 "parse.y"
                {(yyval.node) = new AST("float");}
#line 1550 "parse.tab.cc"
    break;

  case 66: /* type_specifier: DOUBLE  */
#line 188 "parse.y"
                 {(yyval.node) = new AST("double");}
#line 1556 "parse.tab.cc"
    break;

  case 67: /* type_specifier: UNSIGNED  */
#line 189 "parse.y"
                   {(yyval.node) = new AST("unsigned");}
#line 1562 "parse.tab.cc"
    break;

  case 68: /* type_specifier: SIGNED  */
#line 190 "parse.y"
                  {(yyval.node) = new AST("signed");}
#line 1568 "parse.tab.cc"
    break;


#line 1572 "parse.tab.cc"

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

#line 202 "parse.y"





void yyerror(char *s) {
    fprintf(stderr, "line %d: %s at %s\n",yylineno, s,yytext);
}

#pragma once

/*
** Using printf, strlen and isprint
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
** Ignore warnings thrown by GCC on casts of different size.
** The whole goal of this is to NOT know the size at compile time.
*/
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"


/*
** All supported types
** char, int, _Bool, int *, char *, char ** and long
*/
typedef enum type_s
{
  UNKNOWN,
  CHAR,
  INT,
  BOOL,
  PINT,
  STRING,
  PSTRING,
  LONG,
  ULONG
}            type_t;


/*
** Prints an int *
*/
static void dump_pint(int *x)
{
  int i;

  for (i = 0; x[i] != -1; i++);
  printf("int*(%i) [", i);
  for (i = 0; x[i] != -1; i++)
    printf("%i%s", x[i], x[i + 1] != -1 ? ", " : "");
  printf("]");
}

/*
** Prints a char **
*/
static void dump_pstring(char **x)
{
  int i;

  for (i = 0; x[i]; i++);
  printf("char**(%i) [", i);
  for (i = 0; x[i]; i++)
    printf("\"%s\"%s", x[i], x[i + 1] ? ", " : "");
  printf("]");
}

/*
** Switch case on all supported types
** Prints <unsupported type> in case the type is not supported or not known
*/

// break; at each case clutters the code so using my own version :)
#define case    break; case
#define default break; default

static void dump_var(type_t type, void *x)
{
  switch (type)
    {
      case CHAR:    printf("char('%s') ascii(%d)", isprint((char)x) ? ((char *)&x) : "<not printable>", (char)x);
      case INT:     printf("int(%i)", (int)x);
      case BOOL:    printf("bool(%s)", (_Bool)x ? "true" : "false");
      case STRING:  printf("string(%i) \"%s\"", strlen((char *)x), (char *)x);
      case LONG:    printf("long(%ld)", (long)x);
      case ULONG:   printf("unsigned long(%lu)", (unsigned long)x);
      case PSTRING: dump_pstring((char **)x);
      case PINT:    dump_pint((int *)x);
      default:      printf("<unsupported type>");
    }
}

// Don't mess up with others code
#undef case
#undef default

/*
** The public macro to dump a variable content
*/
#define DUMP(x)                                      \
    printf("%s:%d - %s - ", __FILE__, __LINE__, #x); \
    {                                                \
      type_t type;                                   \
      _Generic((x),                                  \
        char         : type = CHAR,                  \
        int          : type = INT,                   \
        _Bool        : type = BOOL,                  \
        char *       : type = STRING,                \
        const char * : type = STRING,                \
        long         : type = LONG,                  \
        unsigned long: type = ULONG,                 \
        char **      : type = PSTRING,               \
        const char **: type = PSTRING,               \
        int *        : type = PINT,                  \
        const int *  : type = PINT,                  \
        default      : type = UNKNOWN);              \
      dump_var(type, (void *)x);                     \
    }                                                \
  printf("\n");

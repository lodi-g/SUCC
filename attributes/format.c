#include <stdio.h>
#include <stdarg.h>

// Enable warnings on wrong format string
// Not necessarry if compiling with -Wformat or -Wall
#pragma GCC diagnostic warning "-Wformat"

// Declare a function as using a printf like format string
// First argument is the format string, second arg is the first vararg
#define __printf_attr(fidx, farg) __attribute__((format(printf, fidx, farg)))

int __printf_attr(1, 2) xprintf(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  int n = vprintf(fmt, ap);
  va_end(ap);
  return n;
}

int main(void)
{
  int i = 1;
  char c[] = "Hello!";
  float f = 2.3;

  // Valid
  xprintf("int: %i, char*: %s, float: %f\n", i, c, f);

  // Not valid
  xprintf("int: %s, char*: %i, float: %f\n", i, c, f);

  // Not valid
  xprintf("int: %i, char*: %s, float: %i\n", i, c, f);
}

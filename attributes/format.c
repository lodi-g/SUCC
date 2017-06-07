#include <stdio.h>
#include <stdarg.h>
#include "attributes.h"

#pragma GCC diagnostic warning "-Wformat"

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

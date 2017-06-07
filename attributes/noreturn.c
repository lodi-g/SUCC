#include <stdlib.h>
#include <stdio.h>
#include "attributes.h"

// Compile with clang -Wunreachable-code noreturn.c
// GCC doesn't throw a warning for an unknown reason

static void __noreturn die()
{
  abort();
}

int main(void)
{
  puts("Dying...");
  die();

  // GCC should throw a warning because this will never be reached
  exit(0);
}

// Uses GCC builtin '&&'
// Probaably causes UB - use with care

#include <stdio.h>

#define jump(label) asm("jmp *%0"::"r"(label):)

int f(void *label)
{
  jump(label);
}

int main(void)
{
  lbl:  puts("Hey, listen!");

  void *label = &&lbl;
  f(label);
}

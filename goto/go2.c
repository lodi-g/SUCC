#include <stdio.h>

#define go2(label) asm("jmp *%0"::"r"(label):)

int so6(void *label)
{
  go2(label);
}

int main(void)
{
 so6:printf("lol\n");

  void *label = &&so6;
  so6(label);
}

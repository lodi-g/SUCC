#include <unistd.h>
#include <stdio.h>

void foo(int *val)
{
  for (int i = 0; val[i] != -1; i++)
    printf("%i ", val[i]);
  printf("\n");
}

int main(void)
{
  int (*ptr)[] = &(int[5]){ 1, 2, 3, 4, -1};

  foo(*ptr);
  foo((int[]){5, 6, 7, 8, -1});

  write(STDOUT_FILENO, (char[]){'H', 'i', '!', 10}, 4);
}

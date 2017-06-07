#include <stdlib.h>
#include <stdio.h>

#define lambda(T, fn) ({T lfn fn lfn; })

int main(int ac, char **av)
{
  if (ac != 3)
    return !!printf("Usage: %s x y\n", av[0]);

  int x = atoi(av[1]);
  int y = atoi(av[2]);
  printf("%i > %i: %s", x, y, lambda(char *, (int x, int y) {
    return x > y ? "true" : "false";
  })(x, y));
}

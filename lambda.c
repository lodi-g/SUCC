#include <stdlib.h>
#include <stdio.h>

#define lambda(T, fn) ({T lfn fn lfn; })

int main(int ac, char **av)
{
  if (ac != 3)
    return !!printf("Usage: %s x y\n", av[0]);

  char *s = calloc(10, sizeof(char));

  s = lambda(char *, (int x, int y) {
    return x > y ? "true" : "false";
  })(atoi(av[1]), atoi(av[2]));

  printf("%i > %i: %s\n", atoi(av[1]), atoi(av[2]), s);
}

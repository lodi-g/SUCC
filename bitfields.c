#include <stdio.h>

typedef struct type_s
{
  unsigned int x : 1;
  unsigned int y : 4;
} type_t;

int main(void)
{
  type_t t = { 0 };

  do {
    printf("x: %i, y: %i\n", t.x++, t.y++);
  } while (t.y);
}

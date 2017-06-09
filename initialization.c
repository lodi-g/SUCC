#include <stdio.h>

typedef struct type_s
{
  unsigned int x;
  unsigned int y;
} type_t;

int main(void)
{
  int arr[10] = { 0 };
  for (int i = 0; i < 10; i++)
    printf("arr[%i] = %i\n", i, arr[i]);

  puts("\n");

  type_t t = { .y = 1, .x = 2};
  printf("t.x = %d, t.y = %d\n", t.x, t.y);

  puts("\n");

  int arr2[] = {[0 ... 3] = 1, [4 ... 7] = 2, [8 ... 10] = 0};
  for (int i = 0; i < 10; i++)
    printf("arr[%i] = %i\n", i, arr2[i]);
}

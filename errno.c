#include <errno.h>
#include <stdio.h>

int main(void)
{
  printf("errno: %m\n");
  errno = ENOMEM;
  printf("errno: %m\n");
}

#include <stdio.h>

#define exit_success() __asm__("movq $60, %rax\nmovq $0, %rdi\nsyscall")
#define exit_error() __asm__("movq $60, %rax\nmovq $1, %rdi\nsyscall")

int main(int ac, const char* av[])
{
  puts("Entry point.");
  if (ac == 1)
    exit_success();
  else
    exit_error();
  puts("Should never be displayed.");
}

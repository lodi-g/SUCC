#include <stdio.h>

#define exit_success __asm__("movl $1, %eax\n\tmovl $0, %ebx\n\t int $0x80");
#define exit_error __asm__("movl $1, %eax\n\tmovl $84, %ebx\n\tint $0x80");

int main(int ac, const char* av[])
{
    puts("Entry point.\n");
    if (ac == 1)
        exit_success
    else
        exit_error
    puts("Should never be displayed.\n");
}

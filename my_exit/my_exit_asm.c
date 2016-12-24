#include <stdio.h>

#define exit_success __asm__("movl $1, %eax\n\tmovl $0, %ebx\n\t int $0x80");
#define exit_error __asm__("movl $1, %eax\n\tmovl $84, %ebx\n\tint $0x80");

/*
** exit_success
** "movl $1, %eax       -> 1 is the code for the exit() system call. System calls should be in the %eax register.
** movl $0, %ebx        -> 0 is the exit status, in the %ebx register
** int $0x80"           -> int stands for interrupt. 0x80 is the correct interrupt number, see here: https://i.stack.imgur.com/hIg8n.png
*/

int main(int ac, const char* av[])
{
    puts("Entry point.\n");
    if (ac == 1)
        exit_success
    else
        exit_error
    puts("Should never be displayed.\n");
}

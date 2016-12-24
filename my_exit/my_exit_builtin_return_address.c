/*
** Take in consideration that __builtin_return_address is a GCC built-in.
*/
#include <stdio.h>

int main(int ac, const char* av[])
{
    puts("Entry point.\n");
    // Get the return address of 0 function before this one (here, the main)
    void (*my_exit)() = __builtin_return_address(0);
    my_exit();
    puts("This will not be displayed.");
    return 0;
}
/*
** Take in consideration that && is a GCC builtin and thus will not work on every compiler.
*/
#include <stdio.h>

int main(int ac, const char* av[])
{
    void (*my_exit)();
    puts("Entry point.\n");
    if (ac == 1)
         my_exit = &&error;
    else
        my_exit = &&success;
    my_exit();
    puts("This will not be displayed.");
    error: return 84;
    success: return 0;
}

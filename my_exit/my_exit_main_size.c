#include <stdio.h>

void init(int ac, const char* av[]);
void my_exit();

int main(int ac, const char* av[])
{
    init(ac, av);
    return 0;
}

void my_exit()
{
    // Thanks GDB for the main size. Although it shouldn't change so no need to get it dynamically.
    int addr = &main + 34;
    printf("%p\n", addr);
    void (*fptr)() = addr;
    fptr();
}

void init(int ac, const char *av[])
{
    // Do main stuff here...
    my_exit();
    puts("This will never be displayed.");
}

/*
** Take in consideration that __builtin_return_address is a GCC built-in.
*/

#include <stdio.h>

int main(int ac, const char* av[])
{
  puts("Entry point.");
  void (*_exit)() = __builtin_return_address(0);
  _exit();
  puts("This will not be displayed.");
}

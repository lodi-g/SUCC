#include <stdio.h>

// Compile with gcc -D DEBUG

#ifdef DEBUG
#define WHERE() fprintf(stderr, "[LOG] %s:%d (%d)\n", __FILE__, __LINE__, __COUNTER__)
#else
#define WHERE()
#endif

int main(void)
{
  puts("Where am I?");
  WHERE();
  puts("Thanks.");
  puts("Now?");
  WHERE();
}

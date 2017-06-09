#include <stdio.h>

// Allow GCC to predict branches and optimize them

#define likely(x) __builtin_expect(x, 1)
#define unlikely(x) __builtin_expect(x, 0)

int main(int ac)
{
  if (unlikely(ac <= 0))
    return 1;
  return 0;
}

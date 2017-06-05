#include <unistd.h>
#include <stdbool.h>

#include "dump.h"

int main(void)
{
  char *a[] = { "abc", "def", "ghi", "jkl", NULL };
  int b[] = {1, 2, 3, 4, -1};
  bool c = true;
  char d = 'a';

  DUMP(1);
  DUMP("abcde");
  DUMP(a);
  DUMP(b);
  DUMP(c);
  DUMP(d);
  DUMP(9223372036854775804L);

  printf("\n\n\n");

  const int e = 1;
  const char f[] = "abcde";
  const bool g = false;
  const char *h[] = { "mno", "pqr", "rst", NULL };
  const char i = 10;
  const int j[] = {1, 2, 3, 4, -1};
  const long k = 9223372036854775804L;

  DUMP(e);
  DUMP(f);
  DUMP(g);
  DUMP(h);
  DUMP(i);
  DUMP(j);
  DUMP(k);

  printf("\n\n\n");

  size_t l = 1;
  ssize_t m = -1;
  DUMP(l);
  DUMP(m);
}

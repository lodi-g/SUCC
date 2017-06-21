#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include "string.h"

#define lambda(T, fn) ({ T lfn fn lfn; })

int main(void)
{
  string *str = String("hi");
  str->dump(str);

  str->set(str, "    Hello, world!   ");
  str->dump(str);

  str->map(str, lambda(char, (char c) {
    return isupper(c) ? c + 32 : islower(c) ? c - 32 : c;
  }));
  str->dump(str);

  str->concat(str, "\t, Hello!   \t  ");
  str->dump(str);

  str->trimws(str);
  str->dump(str);

  char **r = str->split(str, ",");
  for (int i = 0; r[i]; i++)
    {
      string *s = String(r[i]);
      s->dump(s);
      s->free(s);
      free(r[i]);
    }
  free(r);

  str->free(str);
}

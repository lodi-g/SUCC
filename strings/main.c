#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

#include "string.h"

#define lambda(T, fn) ({ T lfn fn lfn; })

#define GRE "\e[32m"
#define RED "\e[31m"
#define RES "\e[0m"

static void validate(char *title, string *str, char *s, unsigned int len)
{
  printf("%s: ", title);

  if (!strcmp(str->_value, s) && str->_length == len)
    {
      printf(GRE"OK\t\t"RES);
      str->dump(str);
    }
  else
    {
      printf(RED"KO "RES);
      printf("=> expected '%s' (%u), got '%s' (%u)\n", s, len, str->_value, str->_length);
    }
}

static void valgrind_it()
{
  char *av[] = { "valgrind", "./string", NULL };
  pid_t pid;

  if (getenv("LD_PRELOAD"))
    return;
  pid = fork();
  if (!pid)
    execvp("valgrind", av);
  else
    wait(NULL);
  exit(0);
}

int main(void)
{

  valgrind_it();

  string *str = String("hi");
  validate("constructor", str, "hi", 2);

  str->set(str, "    Hello, world!   ");
  validate("set ", str, "    Hello, world!   ", 20);

  str->concat(str, "\t, Hello?!   \t  ");
  validate("concat", str, "    Hello, world!   \t, Hello?!   \t  ", 36);

  str->trimws(str);
  validate("trim ws", str, "Hello, world! , Hello?!", 23);

  char **r = str->split(str, ",");
  for (int i = 0; r[i]; i++)
    {
      string *s = String(r[i]);
      validate("split", s, r[i], strlen(r[i]));
      s->free(s);
      free(r[i]);
    }
  free(r);

  str->map(str, lambda(char, (char c) {
    return isupper(c) ? c + 32 : islower(c) ? c - 32 : c;
  }));
  validate("map ", str, "hELLO, WORLD! , hELLO?!", 23);

  string *c = String(str->chr(str, '?'));
  validate("strchr", c, "?!", 2);
  c->free(c);

  c = String(str->str(str, "WORLD!"));
  validate("strstr", c, "WORLD! , hELLO?!", 16);
  c->free(c);

  str->set(str, "test 1 2 3 viva algeria");
  validate("set again", str, "test 1 2 3 viva algeria", 23);

  char *tmp = str->slice(str, 0, 3);
  c = String(tmp);
  validate("slice", c, "test", 4);
  c->free(c);
  free(tmp);

  tmp = str->slice(str, 11, 0);
  c = String(tmp);
  validate("slice", c, "viva algeria", 12);
  c->free(c);
  free(tmp);

  c = Stringh(str->slice(str, 0, 3));
  validate("heap cons", c, "test", 4);
  c->free(c);

  c = Stringh(str->slice(str, 2, 7));
  validate("heap cons2", c, "st 1 2", 6);
  c->free(c);

  c = str->cpy(str);
  validate("copy", c, str->_value, str->_length);
  c->free(c);

  str->free(str);
}

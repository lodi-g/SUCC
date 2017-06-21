/*
** string.c for strings in /home/lodi_g/perso/C/SUCC/strings/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Wed Jun 21 01:10:24 2017 Gregoire Lodi
** Last update Wed Jun 21 17:00:58 2017 Gregoire Lodi
*/

#include "string.h"

/*
** Setters
*/
static char *set(string *self, char *str)
{
  if (self->_value)
    free(self->_value);
  self->_value = strdup(str);
  self->_length = strlen(str);
  return (self->_value);
}

/*
** Getters
*/
static inline char *get(string *self)
{
  return (self->_value);
}

static inline unsigned int len(string *self)
{
  return (self->_length);
}

/*
** Methods
*/
static void map(string *self, char (*lambda)(char c))
{
  char *tmp;

  tmp = self->_value;
  while (*tmp)
    {
      *tmp = lambda(*tmp);
      tmp++;
    }
}

static char *concat(string *self, char *s)
{
  self->_length += strlen(s);
  if (!self->_value)
    self->set(self, s);
  else
    {
      self->_value = realloc(self->_value, self->_length + 1);
      strcat(self->_value, s);
    }
  return (self->_value);
}

static char **split(string *self, char *delim)
{
  char **r;
  char *s;
  char *token;
  ssize_t i;

  i = 1;
  s = strdup(self->_value);
  strtok(s, delim);
  while (strtok(NULL, delim))
    i++;
  r = malloc(sizeof(char *) * (i + 1));
  free(s);
  s = strdup(self->_value);
  token = strtok(s, delim);
  i = 0;
  r[i] = strdup(token);
  while ((token = strtok(NULL, delim)))
    r[++i] = strdup(token);
  r[++i] = NULL;
  free(s);
  return (r);
}

static char *trimws(string *self)
{
  bool ws;
  char *rp;
  char *wp;

  ws = true;
  rp = self->_value;
  wp = self->_value;
  while (*rp)
    {
      if (!isspace(*rp) || !ws)
        *wp++ = *rp;
      ws = isspace(*rp);
      rp++;
    }
  if (ws && wp != self->_value)
    wp--;
  *wp = 0;
  self->_length = strlen(self->_value);
  return (self->_value);
}

static char *chr(string *self, int c)
{
  return (strchr(self->_value, c));
}

static char *chrdup(string *self, int c)
{
  return (self->chrndup(self, c, self->_length));
}

static char *chrndup(string *self, int c, unsigned int n)
{
  char *tmp;

  tmp = strchr(self->_value, c);
  return (tmp ? strndup(tmp, n) : NULL);
}

static char *str(string *self, char *needle)
{
  return (strstr(self->_value, needle));
}

static char *slice(string *self, unsigned int x, unsigned int y)
{
  char *tmp;
  unsigned int size;

  if (x > self->_length || y > self->_length)
    return (self->_value);
  if (y == 0)
    y = self->_length;
  size = y + 1 - x;
  tmp = self->_value;
  while (x)
    {
      tmp++;
      x--;
    }
  return (strndup(tmp, size));
}

static string *sslice(string *self, unsigned int x, unsigned int y)
{
  string *s;
  char *tmp;

  tmp = self->slice(self, x, y);
  s = String(tmp);
  free(tmp);
  return (s);
}

static string *cpy(string *self)
{
  string *s;

  s = String(self->_value);
  return (s);
}

/*
** Prints
*/
static int print(string *self)
{
  return (printf("%s\n", self->_value));
}

static int dump(string *self)
{
  return (printf("=> '%s', length: %u\n", self->get(self), self->len(self)));
}

/*
** Constructors and destructor
*/
static void _free(string *self)
{
  if (self)
    {
      if (self->_value)
        {
          free(self->_value);
          self->_value = NULL;
        }
      free(self);
      self = NULL;
    }
}

static void set_methods(string *self)
{
  self->set = set;
  self->get = get;
  self->len = len;
  self->map = map;
  self->concat = concat;
  self->split = split;
  self->trimws = trimws;
  self->chr = chr;
  self->chrdup = chrdup;
  self->chrndup = chrndup;
  self->str = str;
  self->slice = slice;
  self->sslice = sslice;
  self->cpy = cpy;
  self->print = print;
  self->dump = dump;
  self->free = _free;
}

string *String(char *s)
{
  string *self;

  self = malloc(sizeof(string));
  set_methods(self);
  self->_value = NULL;
  self->_length = 0;
  if (s)
    self->set(self, s);
  return (self);
}

string *Stringh(char *s)
{
  string *self;

  self = String(NULL);
  self->set(self, s);
  free(s);
  return (self);
}

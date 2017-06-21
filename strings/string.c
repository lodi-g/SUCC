/*
** string.c for strings in /home/lodi_g/perso/C/SUCC/strings/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Wed Jun 21 01:10:24 2017 Gregoire Lodi
** Last update Wed Jun 21 02:01:13 2017 Gregoire Lodi
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

int print(string *self)
{
  return (printf("%s\n", self->_value));
}

int dump(string *self)
{
  return (printf("=> '%s', length: %u\n", self->get(self), self->len(self)));
}

/*
** Constructor and destructor
*/
static void _free(string *self)
{
  if (self->_value)
    {
      free(self->_value);
      self->_value = NULL;
    }
  free(self);
  self = NULL;
}

string *String(char *s)
{
  string *self;

  self = malloc(sizeof(string));
  self->set = set;
  self->get = get;
  self->len = len;
  self->map = map;
  self->concat = concat;
  self->split = split;
  self->trimws = trimws;
  self->print = print;
  self->dump = dump;
  self->free = _free;
  self->_value = NULL;
  self->_length = 0;
  if (s)
    self->set(self, s);
  return (self);
}

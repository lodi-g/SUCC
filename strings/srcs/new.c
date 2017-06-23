/*
** new.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Fri Jun 23 11:29:47 2017 Gregoire Lodi
** Last update Fri Jun 23 11:29:49 2017 Gregoire Lodi
*/

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

/*
** self.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Fri Jun 23 11:26:38 2017 Gregoire Lodi
** Last update Fri Jun 23 11:27:37 2017 Gregoire Lodi
*/

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

static char *upper(string *self)
{
  char *tmp;

  tmp = self->_value;
  while (*tmp)
    {
      if (islower(*tmp))
        *tmp += 'A' - 'a';
      tmp++;
    }
  return (self->_value);
}

static char *lower(string *self)
{
  char *tmp;

  tmp = self->_value;
  while (*tmp)
    {
      if (isupper(*tmp))
        *tmp += 'a' - 'A';
      tmp++;
    }
  return (self->_value);
}

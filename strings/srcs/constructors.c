/*
** constructors.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
** 
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
** 
** Started on  Fri Jun 23 11:23:47 2017 Gregoire Lodi
** Last update Fri Jun 23 11:23:51 2017 Gregoire Lodi
*/

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
  self->lower = lower;
  self->upper = upper;
  self->at = at;
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

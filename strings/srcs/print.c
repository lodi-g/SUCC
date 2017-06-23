/*
** print.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Fri Jun 23 11:24:29 2017 Gregoire Lodi
** Last update Fri Jun 23 11:24:32 2017 Gregoire Lodi
*/

static int print(string *self)
{
  return (printf("%s\n", self->_value));
}

static int dump(string *self)
{
  return (printf("=> '%s', length: %u\n", self->get(self), self->len(self)));
}

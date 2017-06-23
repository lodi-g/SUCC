/*
** setters.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
** 
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
** 
** Started on  Fri Jun 23 11:24:56 2017 Gregoire Lodi
** Last update Fri Jun 23 11:25:00 2017 Gregoire Lodi
*/

static char *set(string *self, char *str)
{
  if (self->_value)
    free(self->_value);
  self->_value = strdup(str);
  self->_length = strlen(str);
  return (self->_value);
}
/*
** getters.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
** 
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
** 
** Started on  Fri Jun 23 11:25:14 2017 Gregoire Lodi
** Last update Fri Jun 23 11:27:57 2017 Gregoire Lodi
*/

static inline char *get(string *self)
{
  return (self->_value);
}

static inline unsigned int len(string *self)
{
  return (self->_length);
}

static inline char at(string *self, unsigned int pos)
{
  if (pos > self->_length)
    return (0);
  return (self->_value[pos]);
}
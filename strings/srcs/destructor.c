/*
** destructor.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
** 
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
** 
** Started on  Fri Jun 23 11:24:10 2017 Gregoire Lodi
** Last update Fri Jun 23 11:24:13 2017 Gregoire Lodi
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
/*
** others.c for strings in /home/lodi_g/perso/C/SUCC/strings/srcs/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Fri Jun 23 11:30:52 2017 Gregoire Lodi
** Last update Fri Jun 23 11:30:53 2017 Gregoire Lodi
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

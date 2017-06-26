/*
** sbmlparser.h for sbmlparser in /home/lodi_g/perso/C/SUCC/sbmlparser/incs/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Mon Jun 26 16:56:06 2017 Gregoire Lodi
** Last update Mon Jun 26 22:38:02 2017 Gregoire Lodi
*/

#ifndef SBMLPARSER_H_
#define SBMLPARSER_H_

typedef struct s_node t_node;

typedef struct s_attrs
{
  char *name;
  char **values;
} t_attrs;

struct s_node
{
  t_node *childs[32];
  t_node *parent;
  char *name;
  t_attrs *attrs[10];
};

int yyparse(void);

#endif

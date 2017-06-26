/*
** main.c for sbmlparser in /home/lodi_g/perso/C/SUCC/sbmlparser/srcs/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Mon Jun 26 16:58:43 2017 Gregoire Lodi
** Last update Mon Jun 26 22:35:11 2017 Gregoire Lodi
*/

#include <unistd.h>
#include <malloc.h>
#include "sbmlparser.h"

t_node *root = NULL;

int main(void)
{
  root = calloc(1, sizeof(t_node));
  yyparse();
}

/*
** string.h for string in /home/lodi_g/perso/C/SUCC/strings/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Wed Jun 21 02:01:24 2017 Gregoire Lodi
** Last update Wed Jun 21 16:58:36 2017 Gregoire Lodi
*/

#pragma once

#ifndef STRING_H_
#define STRING_H_

#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _string string;

struct _string
{
  /* variables */
  char *_value;
  unsigned int _length;
  /* methods */
  char *(*set)(string *self, char *s);
  char *(*get)(string *self);
  unsigned int (*len)(string *self);
  void (*map)(string *self, char (*lambda)(char c));
  char *(*concat)(string *self, char *s);
  char **(*split)(string *self, char *delim);
  char *(*trimws)(string *self);
  char *(*chr)(string *self, int c);
  char *(*chrdup)(string *self, int c);
  char *(*chrndup)(string *self, int c, unsigned int n);
  char *(*str)(string *self, char *needle);
  char *(*slice)(string *self, unsigned int x, unsigned int y);
  string *(*sslice)(string *self, unsigned int x, unsigned int y);
  string *(*cpy)(string *self);
  int (*print)(string *self);
  int (*dump)(string *self);
  void (*free)(string *self);
};

string *String(char *s);
string *Stringh(char *s);

#endif

/*
** string.h for string in /home/lodi_g/perso/C/SUCC/strings/
**
** Made by Gregoire Lodi
** Login   <gregoire.lodi@epitech.eu@epitech.eu>
**
** Started on  Wed Jun 21 02:01:24 2017 Gregoire Lodi
** Last update Fri Jun 23 11:18:52 2017 Gregoire Lodi
*/

#ifndef STRING_H_
#define STRING_H_

typedef struct _string string;

struct _string
{
  char *_value;
  unsigned int _length;
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
  char *(*upper)(string *self);
  char *(*lower)(string *self);
  char (*at)(string *self, unsigned int pos);
  int (*print)(string *self);
  int (*dump)(string *self);
  void (*free)(string *self);
};

string *String(char *s);
string *Stringh(char *s);

#endif

#include <stdio.h>
#include "attributes.h"

// Priority starts at 100, below is reserved to libc

int __constructor__(101) first()
{
  puts("First constructor called!");
}

int __constructor second()
{
  puts("Hey, I'm called before the function called before the main!");
}

int __constructor third()
{
  puts("Hey, I'm called right before the main!");
}

int __destructor penultimate()
{
  puts("Leaving :(");
}

int __destructor antepenultimate()
{
  puts("Just left main!");
}

int __destructor__(101) last()
{
  puts("Definetely leaving...");
}

int main(void)
{
  puts("In the main!");
}

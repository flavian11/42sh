/*
** my_xmalloc.c for  in /home/hugo/PSU_2016_42sh/src/misc
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 14:44:00 2017 Hugo
** Last update Mon May 15 21:51:03 2017 Hugo
*/

#include <stdlib.h>
#include "proto.h"

char    *my_xmalloc(size_t x)
{
  char  *str;

  if ((str = malloc(sizeof(char) * (x + 1))) == NULL)
    exit(84);
  while (x > 0)
    {
      str[x] = '\0';
      x--;
    }
  str[x] = '\0';
  return (str);
}

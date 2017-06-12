/*
** my_realloc.c for  in /home/hugo/PSU_2016_42sh/src/misc
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 14:46:49 2017 Hugo
** Last update Mon May 15 14:51:46 2017 Hugo
*/

#include <stdlib.h>
#include <string.h>
#include "proto.h"

char    *my_realloc(char *str, size_t x, int is_free)
{
  char  *str2;
  int   i;

  i = 0;
  str2 = my_xmalloc(strlen(str) + x + 1);
  if (str2 == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i++;
    }
  str2[i] = '\0';
  if (is_free == 1)
    if (str != NULL)
      free(str);
  return (str2);
}

/*
** my_strcat.c for  in /home/hugo/PSU_2016_42sh/src/misc
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 14:45:09 2017 Hugo
** Last update Mon May 15 14:45:24 2017 Hugo
*/

#include "proto.h"
#include <stdlib.h>

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   y;

  i = y = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (dest[i] != '\0')
    i++;
  while (src[y] != '\0')
    {
      dest[i + y] = src[y];
      y++;
    }
  dest[i + y] = '\0';
  return (dest);
}

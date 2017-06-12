/*
** insert_char.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Fri May 19 18:24:12 2017 Hugo
** Last update Fri May 19 18:40:47 2017 Hugo
*/

#include <string.h>
#include <stdlib.h>
#include "proto.h"

char		*insert_char(char *str, char c, size_t i)
{
  char		*new;
  size_t	i_new;

  i_new = 0;
  new = my_xmalloc(strlen(str) + 2);
  while (i_new != i)
    {
      new[i_new] = str[i_new];
      i_new++;
    }
  new[i_new++] = c;
  while (str[i] != '\0')
    {
      new[i + 1] = str[i];
      i++;
    }
  new[i + 1] = '\0';
  free(str);
  return (new);
}

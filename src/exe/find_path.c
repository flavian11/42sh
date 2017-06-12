/*
** find_path.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 18:51:23 2017 Hugo
** Last update Sun May 21 18:51:47 2017 Hugo
*/

#include "proto.h"

int             find_absolute_path(char *str)
{
  size_t        i;

  i = 0;
  if (str[0] == '.')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

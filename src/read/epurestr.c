/*
** epurestr.c for  in /home/hugo/PSU_2016_42sh/src/read
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 21:30:44 2017 Hugo
** Last update Sun May 21 16:15:48 2017 Hugo
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "proto.h"

char		*epurestr(char *str)
{
  char          *buf;
  size_t        i;

  i = 0;
  buf = my_xmalloc(1);
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == '\t' || str[i] == ' ') && str[i + 1] != ' '
	  && str[i + 1] != '\t' && str[i + 1] != 0)
	buf = my_addchar(my_realloc(buf, 1, 1), ' ');
      else if (str[i] != '\t' && str[i] != ' ')
	buf = my_addchar(my_realloc(buf, 1, 1), str[i]);
      i++;
    }
  free(str);
  return (buf);
}

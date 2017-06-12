/*
** get_next_line.c for  in /home/hugo/PSU_2016_42sh/src/read
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 13:40:06 2017 Hugo
** Last update Mon May 15 21:35:53 2017 Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

int     check_tamp(char *tamp)
{
  int   i;

  i = 0;
  while (tamp[i] != '\0')
    {
      if (tamp[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

char    *free_tamp(char *tamp, char *s)
{
  if (tamp != NULL)
    free(tamp);
  return (s);
}

char    *free_all(char *tamp, char *s)
{
  if (tamp != NULL)
    free(tamp);
  if (s != NULL)
    free(s);
  return (NULL);
}

char    *get_next_line(const int fd)
{
  char  *s;
  char  *tamp;
  int   ret;

  ret = 0;
  s = my_xmalloc(READ_SIZE);
  tamp = my_xmalloc(READ_SIZE + 1);
  if (s == NULL || tamp == NULL)
    return (NULL);
  s[0] = tamp[0] = '\0';
  while (check_tamp(tamp) != 1)
    {
      if ((ret = read(fd, tamp, READ_SIZE)) == 0)
	{
	  if (s[0] == '\0')
	    return (free_all(tamp, s));
	  else
	    return (free_tamp(tamp, s));
	}
      (tamp[0] < '\0') ? exit(84) : 0;
      tamp[ret] = '\0';
      (tamp[0] != '\n') ? (s = my_strcat(my_realloc(s, 1, 1), tamp)) : 0;
    }
  free(tamp);
  return (s);
}

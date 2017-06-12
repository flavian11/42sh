/*
** my_str_to_wordtab.c for  in /home/flav/epitech/PSU/PSU_2016_42sh/src
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Fri May 12 15:33:01 2017 flav
** Last update Tue May 16 22:33:15 2017 Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

int     how_many_lines(char *str, char c)
{
  int   i;
  int   nbr;

  i = nbr = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	nbr++;
      i++;
    }
  return (nbr + 1);
}

int     get_current_col(char *str, int x, char c)
{
  int   i;
  int   nbr;
  int   loop;

  i = nbr = loop = 0;
  while (str[i] != '\0' && loop <= x)
    {
      if (str[i] == c)
	loop++;
      i++;
    }
  i = i - 2;
  while (i > 0 && str[i] != c)
    {
      i--;
      nbr++;
    }
  return (nbr + 1);
}

char    **my_str_to_wordtab(char *str, char c)
{
  char  **map;
  int   i;
  int   x;
  int   y;

  i = x = y = 0;
  if ((map = malloc(sizeof(char *) * (how_many_lines(str, c) + 1))) == NULL)
    exit(84);
  map[x] = my_xmalloc(get_current_col(str, x, c) + 1);
  if (str[0] == '\0')
    map[x++][0] = '\0';
  while (str[i] != '\0')
    {
      while (str[i] != c && str[i] != '\0')
	map[x][y++] = str[i++];
      map[x][y] = '\0';
      if (str[i] != '\0')
	i++;
      y = 0;
      x++;
      if (str[i] != '\0')
	map[x] = my_xmalloc(get_current_col(str, x, c) + 1);
    }
  map[x] = NULL;
  return (map);
}

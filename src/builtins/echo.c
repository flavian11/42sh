/*
** echo.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Wed May 17 22:21:24 2017 Hugo
** Last update Sun May 21 22:55:18 2017 Hugo
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

void	my_echo(char **tab, t_data *data, bool print)
{
  int	x;

  x = 1;
  if (print == false)
    return ;
  while (tab[x] != NULL)
    {
      printf("%s", tab[x]);
      if (tab[x + 1] != NULL)
	printf(" ");
      x++;
    }
  printf("\n");
  data->ret = 0;
}

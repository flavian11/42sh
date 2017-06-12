/*
** free_tab.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Wed May 17 16:52:25 2017 Hugo
** Last update Wed May 17 16:55:51 2017 Hugo
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    free(tab[x++]);
  free(tab);
}

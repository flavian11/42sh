/*
** my_unsetenv.c for  in /home/hugo/PSU_2016_42sh/src/builtins
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Wed May 17 15:50:24 2017 Hugo
** Last update Fri May 19 21:53:45 2017 Hugo
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proto.h"

char    *fill_that_line(char **envp, char **tab, int x)
{
  envp[x] = strdup(tab[1]);
  envp[x] = my_strcat(my_realloc(envp[x], 1, 1), "=");
  if (tab[2] != NULL)
    {
      envp[x] = my_realloc(envp[x], strlen(tab[2]), 1);
      envp[x] = my_strcat(envp[x], tab[2]);
    }
  return (envp[x]);
}

char    **add_line_to_env(char **envp, char **tab)
{
  int   x;
  char  **envp2;

  x = 0;
  while (envp[x] != NULL)
    x++;
  if ((envp2 = malloc(sizeof(char*) * (x + 2))) == NULL)
    exit(84);
  x = 0;
  while (envp[x] != NULL)
    {
      envp2[x] = strdup(envp[x]);
      x++;
    }
  envp2[x] = fill_that_line(envp2, tab, x);
  envp2[x + 1] = NULL;
  free_tab(envp);
  return (envp2);
}

char	**remove_line(char **envp, int goal)
{
  char	**new;
  int	x;
  int	y;

  x = y = 0;
  while (envp[x] != NULL)
    x++;
  if ((new = malloc(sizeof(char *) * x)) == NULL)
    exit(84);
  x = 0;
  while (envp[x] != NULL)
    {
      if (x != goal)
	new[y] = strdup(envp[x]);
      else
	y--;
      x++;
      y++;
    }
  new[y] = NULL;
  return (new);
}

int	unset_value(char *name, t_data *data)
{
  int	x;

  x = 0;
  while (data->envp[x] != NULL)
    {
      if (strncmp(data->envp[x], name, strlen(name)) == 0)
	{
	  if (strncmp(name, HOME, strlen(name)) == 0)
	    data->home = strdup(&data->envp[x][5]);
	  data->envp = remove_line(data->envp, x);
	  data->ret = 0;
	  return (0);
	}
      x++;
    }
  return (1);
}

void	my_unsetenv(char **tab, t_data *data, bool print)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    x++;
  if (x < 2)
    {
      if (print == true)
	dprintf(STD_ERR, "unsetenv: Too few arguments.\n");
      data->ret = 1;
    }
  else
    {
      x = 0;
      while (tab[x] != NULL)
	{
	  if (unset_value(tab[x], data) == 0)
	    break;
	  x++;
	}
    }
  free_tab(tab);
}

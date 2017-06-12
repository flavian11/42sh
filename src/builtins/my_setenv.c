/*
** setenv.c for  in /home/hugo/PSU_2016_42sh/src/builtins
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Wed May 17 12:13:15 2017 Hugo
** Last update Sun May 21 16:42:28 2017 Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "proto.h"

int     check_valid_name(char *str, bool print)
{
  int   i;

  i = 1;
  if ((str[0] < 'a' || str[0] > 'z') &&
      (str[0] < 'A' || str[0] > 'Z') && str[0] != '_')
    {
      if (print == true)
	dprintf(STD_ERR, "setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z') &&
	  (str[i] < 'A' || str[i] > 'Z') && str[i] != '_')
	{
	  if (print == true)
	    {
	      dprintf(STD_ERR, "setenv: Variable name must contain ");
	      dprintf(STD_ERR, "alphanumeric characters.\n");
	    }
	  return (1);
	}
      i++;
    }
  return (0);
}

void	modify_env_value(char **tab, t_data *data)
{
  int	x;

  x = 0;
  while (data->envp[x] != NULL &&
	 strncmp(data->envp[x], tab[1], strlen(tab[1])) != 0)
    x++;
  if (data->envp[x] == NULL)
    data->envp = add_line_to_env(data->envp, tab);
  else
    {
      if (strncmp(data->envp[x], HOME, strlen(HOME)) == 0)
	data->home = get_current_dir_name();
      free(data->envp[x]);
      data->envp[x] = strdup(tab[1]);
      data->envp[x] = my_strcat(my_realloc(data->envp[x], 1, 1), "=");
      if (tab[2] != NULL)
	data->envp[x] = my_strcat(my_realloc(data->envp[x],
					     strlen(tab[2]), 1), tab[2]);
    }
}

void	disp_env(t_data *data, bool print)
{
  int	x;

  x = 0;
  if (print == false)
    return ;
  while (data->envp[x] != NULL)
    {
      dprintf(STD_OUT, "%s\n", data->envp[x]);
      x++;
    }
}

int	get_nb_args(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    x++;
  return (x - 1);
}

void	my_setenv(char **tab, t_data *data, bool print)
{
  int	ret;

  ret = get_nb_args(tab);
  data->ret = 0;
  if (ret == 0)
    disp_env(data, print);
  else if (ret == 1 || ret == 2)
    {
      if ((data->ret = check_valid_name(tab[1], print)) != -1)
	modify_env_value(tab, data);
    }
  else
    {
      if (print == true)
	dprintf(STD_ERR, "setenv: Too many arguments.\n");
      data->ret = 1;
    }
  free_tab(tab);
}

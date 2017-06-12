/*
** cd.c for  in /home/hugo/PSU_2016_42sh/src/builtins
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Tue May 16 15:58:49 2017 Hugo
** Last update Sun May 21 21:48:55 2017 Hugo
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "proto.h"

t_data	*mod_pwd(t_data *data, bool print)
{
  char	*str;
  int	x;

  x = 0;
  while (data->envp[x] != NULL && strncmp(data->envp[x], "PWD", 3) != 0)
    x++;
  if (data->envp[x] == NULL)
    {
      my_setenv(my_str_to_wordtab(get_current_dir_name(), ' '), data, print);
      return (data);
    }
  str = strdup("PWD=");
  str[4] = '\0';
  str = my_realloc(str, strlen(data->cwd), 1);
  str = my_strcat(str, data->cwd);
  free(data->envp[x]);
  data->envp[x] = strdup(str);
  free(str);
  data->ret = 0;
  return (data);
}

char    *get_home(char **envp, char *old, bool print)
{
  char  *str;
  int   x;

  x = 0;
  while (envp[x] != NULL && strncmp(envp[x], "HOME", 4) != 0)
    x++;
  if (envp[x] == NULL)
    {
      (print == true) ? dprintf(STD_ERR, "cd: No home directory.\n") : 0;
      free(old);
      return (NULL);
    }
  str = strdup(envp[x]);
  x = 0;
  while (str[0] != '/')
    {
      while (str[x] != '\0')
	{
	  str[x] = str[x + 1];
	  x++;
	}
      x = 0;
    }
  free(old);
  return (str);
}

char	*get_history(t_data *data, char *str, bool print)
{
  free(str);
  if (data->owd == NULL)
    {
      if (print == true)
	dprintf(STD_ERR, "Hit end of history...\n");
      return ("./");
    }
  else
    return (data->owd);
}

char    *get_parsed(char *str, char **tab, t_data *data, bool print)
{
  int   x;
  int	i;

  x = i = 0;
  while (tab[x] != NULL)
    x++;
  if (x == 1)
    return (get_home(data->envp, str, print));
  else if (x > 2)
    {
      if (print == true)
	dprintf(STD_ERR, "cd: Too many arguments.\n");
      data->ret = 1;
      return (NULL);
    }
  else
    {
      if (tab[1][0] == '-' && (tab[1][1] == ' ' || tab[1][1] == '\0'))
	return (strdup(str = get_history(data, str, print)));
      while (tab[1][i] != '\0')
	str = my_addchar(my_realloc(str, 1, 1), tab[1][i++]);
    }
  return (str);
}

void	cd(char **tab, t_data *data, bool print)
{
  char	*oldtmp;
  char	*str;

  str = my_xmalloc(2);
  if ((str = get_parsed(str, tab, data, print)) == NULL)
    return ;
  oldtmp = strdup(data->cwd);
  if (chdir(str) == -1)
    {
      disp_no_file(str, errno, print);
      data->ret = 1;
    }
  else
    {
      free(data->owd);
      free(data->cwd);
      data->owd = strdup(oldtmp);
      data->cwd = get_current_dir_name();
      data = mod_pwd(data, print);
    }
  free(str);
  free(oldtmp);
  free_tab(tab);
}

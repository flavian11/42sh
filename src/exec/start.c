/*
** start.c for  in /home/hugo/PSU_2016_42sh/src/exec
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Tue May 16 11:53:27 2017 Hugo
** Last update Sun May 21 22:03:13 2017 flav
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "proto.h"

char	**my_tabdup(char **tab)
{
  char	**new;
  int	x;

  x = 0;
  while (tab[x] != NULL)
    x++;
  if ((new = malloc(sizeof(char *) * (x + 1))) == NULL)
    exit(84);
  x = 0;
  while (tab[x] != NULL)
    {
      new[x] = strdup(tab[x]);
      x++;
    }
  new[x] = NULL;
  return (new);
}

char	**set_default_envp(void)
{
  char	**envp;

  if ((envp = malloc(sizeof(char *) * ENVP)) == NULL)
    exit(84);
  envp[0] = strdup(PWD);
  envp[0] = my_strcat(my_realloc(envp[0], strlen(get_current_dir_name()), 1),
		      get_current_dir_name());
  envp[1] = strdup(PATH);
  envp[2] = NULL;
  return (envp);
}

t_data   *start(char **envp, int ac)
{
  t_data *data;

  if ((data = malloc(sizeof(t_data))) == NULL)
    exit(84);
  data->cwd = data->owd = NULL;
  if (envp[0] == NULL)
    data->envp = set_default_envp();
  else
    data->envp = my_tabdup(envp);
  data->ret = 0;
  data = get_cwd(data);
  data->do_exit = 1;
  if (ac == 1)
    disp_prompt(data);
  return (data);
}

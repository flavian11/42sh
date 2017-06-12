/*
** replace_env_value.c for  in /home/hugo/PSU_2016_42sh/src/exec
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 16:30:24 2017 Hugo
** Last update Sun May 21 16:45:03 2017 Hugo
*/

#include <string.h>
#include <stdlib.h>
#include "proto.h"

int             get_path_length(char *str)
{
  size_t        i;

  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    i++;
  return (i);
}

int             get_env_length(char *str)
{
  size_t        i;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  return (i);
}

char            *replace_env_variable(char *cmd, size_t i_cmd, char *envp)
{
  char          *new;
  int           new_size;
  int           i_envp;
  size_t        i_new;

  i_new = i_envp = 0;
  new_size = strlen(cmd) + strlen(envp) - get_env_length(&cmd[i_cmd]);
  if ((new = malloc(sizeof(char) * (new_size + 1))) == NULL)
    exit(84);
  while (i_new != i_cmd)
    {
      new[i_new] = cmd[i_new];
      i_new++;
    }
  while (envp[i_envp] != '\0')
    new[i_new++] = envp[i_envp++];
  while (cmd[i_cmd] != '\0' && cmd[i_cmd] != ' ' && cmd[i_cmd++] != '~');
  while (cmd[i_cmd] != '\0')
    new[i_new++] = cmd[i_cmd++];
  new[i_new] = '\0';
  free(cmd);
  return (new);
}

char    *replace_env_value(char *cmd, size_t i, t_data *data, bool print)
{
  int   x;
  int   y;

  x = y = 0;
  while (data->envp[x] != NULL &&
	 strncmp(&cmd[i + 1], data->envp[x], get_path_length(data->envp[x])) != 0)
    x++;
  if (data->envp[x] != NULL)
    {
      while (data->envp[x][y++] != '=');
      cmd = replace_env_variable(cmd, i, &data->envp[x][y]);
    }
  else
    {
      if (strncmp(&cmd[i], RET_VALUE, strlen(RET_VALUE)) == 0)
	return (cmd = replace_env_variable(cmd, i, int_to_array(data->ret)));
      if (print != false)
	print_var_name(&cmd[i + 1]);
      data->ret = 1;
      free(cmd);
      return (NULL);
    }
  return (cmd);
}

char    *replace_home(char *str, size_t i, t_data *data)
{
  int   x;
  int   y;

  x = y = 0;
  while (data->envp[x] != NULL &&
	 strncmp(data->envp[x], HOME, strlen(HOME)) != 0)
    x++;
  if (data->envp[x] != NULL)
    {
      while (data->envp[x][y] != '\0' && data->envp[x][y++] != '=');
      if (data->envp[x][y] != '\0')
	str = replace_env_variable(str, i, &data->envp[x][y]);
      else
	str = replace_env_variable(str, i, data->home);
    }
  else
    str = replace_env_variable(str, i, data->home);
  return (str);
}

/*
** env_variable.c for  in /home/hugo/PSU_2016_42sh/src/exec
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Tue May 16 11:58:23 2017 Hugo
** Last update Sun May 21 16:36:54 2017 Hugo
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <wordexp.h>
#include "proto.h"

void		print_var_name(char *cmd)
{
  size_t	i;

  i = 0;
  while (cmd[i] != '\0' && cmd[i] != ' ')
    dprintf(STD_ERR, "%c", cmd[i++]);
  dprintf(STD_ERR, ": Undefined variable.\n");
}

int	jump_to(char *str, int start, char goal, t_data *data)
{
  start++;
  while (str[start] != '\0' && str[start] != goal)
    start++;
  if (str[start] != '\0')
    start++;
  else
    {
      data->ret = 1;
      dprintf(STD_ERR, "Unmatched %c.", goal);
    }
  return (start);
}

char	*expand(char *str, size_t i)
{
  if (i != 0 && str[i - 1] != ' ' && str[i - 1] != str[i])
    str = insert_char(str, ' ', i);
  else if (str[i + 1] != ' ' && str[i + 1] != '\0' && str[i + 1] != str[i])
    str = insert_char(str, ' ', i + 1);
  return (str);
}

char		*shell_like_expansion(char *cmd, t_data *data)
{
  size_t	i;
  int		x;

  i = x = 0;
  cmd = epurestr(cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '\'' || cmd[i] == '\"')
	i = jump_to(cmd, i, cmd[i], data);
      while (op_tab[x].separator != 0 && cmd[i] != op_tab[x].separator[0])
	x++;
      if (op_tab[x].separator != 0)
	cmd = expand(cmd, i);
      x = 0;
      i++;
    }
  return (cmd);
}

char		*pre_processing(char *cmd, t_data *data, bool print)
{
  size_t	i;

  i = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '\'' || cmd[i] == '\"')
	i = jump_to(cmd, i, cmd[i], data);
      if (cmd[i] == '~')
	cmd = replace_home(cmd, i, data);
      if (cmd[i] == '$' && cmd[i + 1] != '\0' && cmd[i + 1] != ' ')
	if ((cmd = replace_env_value(cmd, i, data, print)) == NULL)
	  return (NULL);
      i++;
    }
  return (cmd);
}

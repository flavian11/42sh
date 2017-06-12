/*
** my_exe.c for  in /home/flav/epitech/PSU/PSU_2016_42sh/src/exe
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue May  9 16:54:57 2017 flav
** Last update Sun May 21 23:04:06 2017 Hugo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "proto.h"
#include "struct.h"

static int	find_path(char **envp)
{
  int	i;

  i = 0;
  while (strncmp(envp[i], "PATH=", 5) != 0)
    {
      i++;
      if (envp[i] == NULL)
	return (-1);
    }
  return (i);
}

static char	*my_new_path(char *cmd, char **str, t_data *data, int n)
{
  int	y;
  int	i;
  int	x;
  int	nb_p;

  i = nb_p = 0;
  if ((x = find_path(data->envp)) == -1)
    return (NULL);
  if ((str[0] = malloc(sizeof(char) * strlen(cmd) + strlen(data->envp[x]) + 1))
      == NULL)
    exit(84);
  y = 5;
  while (data->envp[x][y] != '\0' && nb_p < n)
    if (data->envp[x][y++] == ':')
      nb_p++;
  if (data->envp[x][y] == '\0')
    return (NULL);
  while (data->envp[x][y] != '\0' && data->envp[x][y] != ':')
    str[0][i++] = data->envp[x][y++];
  str[0][i++] = '/';
  y = 0;
  while (cmd[y] != '\0' && cmd[y] != '\n')
    str[0][i++] = cmd[y++];
  str[0][i] = '\0';
  return (str[0]);
}

void		exec(char **cmd, t_data *data)
{
  char		*tmp;
  int		n;
  int		absolute;

  n = absolute = 0;
  tmp = strdup(cmd[0]);
  absolute = find_absolute_path(tmp);
  signal(SIGTTOU, SIG_IGN);
  setpgid(0, 0);
  if (absolute == 0)
    cmd[0] = my_new_path(tmp, cmd, data, n++);
  while (access(cmd[0], X_OK) == -1)
    {
      if (absolute == 1)
	{
	  dprintf(STD_ERR, "%s: Command not found.\n", cmd[0]);
	  exit(1);
	}
      if ((cmd[0] = my_new_path(tmp, cmd, data, n++)) == NULL)
	{
	  dprintf(STD_ERR, "%s: Command not found.\n", tmp);
	  exit(1);
	}
    }
  disp_error(cmd, data);
}

void	change_ground(pid_t pid, t_data *data)
{
  tcsetpgrp(0, pid);
  signal(SIGTTOU, SIG_IGN);
  get_signal(data, pid);
  tcsetpgrp(0, getpid());
}

int	my_exec(char **cmd, t_data *data)
{
  pid_t	pid;
  int	i;

  i = 0;
  signal(SIGINT, SIG_DFL);
  while (built_tab[i].built_name != NULL &&
	 strcmp(cmd[0], built_tab[i].built_name) != 0)
    i++;
  if (built_tab[i].built_name != NULL)
    built_tab[i].exec_b(cmd, data, true);
  else
    {
      if ((pid = fork()) == -1)
	{
	  dprintf(STD_ERR, "fork error\n");
	  exit(84);
	}
      if (pid == 0)
	exec(cmd, data);
      else
	change_ground(pid, data);
    }
  return (0);
}

/*
** main.c for  in /home/flavian/epitech/PSU/PSU_2016_42sh
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Apr 10 21:08:22 2017 
** Last update Sun May 21 22:15:19 2017 flav
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "proto.h"
#include "macro.h"

void	child_process(t_graph *graph, t_data *data)
{
  setpgid(0, 0);
  exec_tree(graph, data);
  free_graph(graph);
  exit(data->ret);
}

void	parent_process(pid_t pid, t_data *data, t_graph *graph)
{
  signal(SIGINT, nothing);
  tcsetpgrp(0, pid);
  signal(SIGTTOU, SIG_IGN);
  get_signal(data, pid);
  tcsetpgrp(0, getpid());
  builtins(graph, data, 0);
}

void	main_fork(char *cmd, t_data *data)
{
  t_graph	*graph;
  pid_t		pid;

  if (strncmp(cmd, REPEAT, REPEATLEN) == 0)
    repeat(cmd, data);
  else
    if (cmd != NULL && (graph = binary_tree(cmd, data)) != NULL)
      {
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	pid = fork();
	if (pid == 0)
	  child_process(graph, data);
	else
	  parent_process(pid, data, graph);
      }
}

int		main(int ac, char **av, char **envp)
{
  char		*cmd;
  t_data	*data;

  data = start(envp, ac);
  if (ac != 1)
    cmd_in_file(av, data);
  else
    {
      while ((cmd = get_next_line(0)) != NULL)
	{
	  cmd = shell_like_expansion(cmd, data);
	  if (cmd[0] != '\0')
	    main_fork(cmd, data);
	  disp_prompt(data);
	}
      if (isatty(0) == 1)
	printf("exit\n");
    }
  return (free_and_exit(data, data->ret));
}

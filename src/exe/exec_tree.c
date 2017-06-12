/*
** exec_tree.c for  in /home/flav/epitech/PSU/PSU_2016_42sh
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Thu May 11 20:14:03 2017 flav
** Last update Sun May 21 22:16:46 2017 flav
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "proto.h"
#include "struct.h"

void	double_pipe(t_graph *btree, t_data *data)
{
  if (btree->left->type == ARGS)
    my_exec(my_str_to_wordtab(btree->left->cmd, ' '), data);
  else
    exec_tree(btree->left, data);
  if (data->ret != 0)
    {
      if (btree->right->type == ARGS)
	my_exec(my_str_to_wordtab(btree->right->cmd, ' '), data);
      else
	exec_tree(btree->right, data);
    }
}

void	esp_rec(t_graph *btree, t_data *data)
{
  if (btree->left->type == ARGS)
    my_exec(my_str_to_wordtab(btree->left->cmd, ' '), data);
  else
    exec_tree(btree->left, data);
  if (data->ret == 0)
    {
      if (btree->right->type == ARGS)
	my_exec(my_str_to_wordtab(btree->right->cmd, ' '), data);
      else
	exec_tree(btree->right, data);
    }
}

void	pip_child(t_graph *btree, int pipefd[2], t_data *data)
{
  setpgid(0, 0);
  close(pipefd[0]);
  if (dup2(pipefd[1], 1) == -1)
    {
      dprintf(STD_ERR, "error on dup2\n");
      exit(84);
    }
  if (btree->type == SYMBOLE)
    exec_tree(btree, data);
  else
    my_exec(my_str_to_wordtab(btree->cmd, ' '), data);
}

void	pipe_rec(t_graph *btree, t_data *data)
{
  int	pipefd[2];
  int	pid;

  if (pipe(pipefd) == -1)
    exit(84);
  if ((pid = fork()) == -1)
    exit(84);
  if (pid == 0)
    pip_child(btree->left, pipefd, data);
  else
    {
      signal(SIGINT, nothing);
      tcsetpgrp(0, pid);
      signal(SIGTTOU, SIG_IGN);
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	exit(84);
      if (btree->right->type != ARGS)
	exec_tree(btree->right, data);
      else
	my_exec(my_str_to_wordtab(btree->right->cmd, ' '), data);
      get_signal(data, pid);
      tcsetpgrp(0, getpid());
    }
}

void	exec_tree(t_graph *btree, t_data *data)
{
  int	i;

  i = 0;
  if (btree->type == ARGS)
    {
      if ((btree->cmd = pre_processing(btree->cmd, data, true)) != NULL)
	my_exec(my_str_to_wordtab(btree->cmd, ' '), data);
    }
  else
    {
      while (op_tab[i].separator != 0 &&
	     strcmp(btree->cmd, op_tab[i].separator) != 0)
	i++;
      if (op_tab[i].separator == 0 && btree->type != ARGS)
	return ;
      else
	op_tab[i].ex(btree, data);
    }
}

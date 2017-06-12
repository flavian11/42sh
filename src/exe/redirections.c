/*
** redirections.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 16:21:27 2017 Hugo
** Last update Sun May 21 16:25:16 2017 Hugo
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "proto.h"

void    double_red(t_graph *btree, t_data *data)
{
  int   fd;

  if (btree->right->type != ARGS)
    {
      dprintf(STD_ERR, "Missing name for redirect.");
      return ;
    }
  fd = open(btree->right->cmd, O_RDWR | O_TRUNC, S_IRWXU);
  if (fd < 0)
    exit(84);
  lseek(fd, 0, SEEK_END);
  if ((data->fd_save = dup(1)) == -1)
    exit(84);
  if (dup2(fd, 1) == -1)
    exit(84);
  exec_tree(btree->left, data);
  if (dup2(1, data->fd_save) == -1)
    exit(84);
}

void    simple_red(t_graph *btree, t_data *data)
{
  int   fd;

  if (btree->right->type != ARGS)
    {
      dprintf(STD_ERR, "Missing name for redirect.");
      return ;
    }
  fd = open(btree->right->cmd, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
  if (fd < 0)
    exit(84);
  if ((data->fd_save = dup(1)) == -1)
    exit(84);
  if (dup2(fd, 1) == -1)
    exit(84);
  exec_tree(btree->left, data);
  if (dup2(1, data->fd_save) == -1)
    exit(84);
}

void    inverse_red(t_graph *btree, t_data *data)
{
  int   fd;

  if (btree->right->type != ARGS)
    {
      dprintf(STD_ERR, "Missing name for redirect.");
      return ;
    }
  fd = open(btree->right->cmd, O_RDWR, S_IRWXU);
  if (fd < 0)
    exit(84);
  if ((data->fd_save = dup(0)) == -1)
    exit(84);
  if (dup2(fd, 0) == -1)
    exit(84);
  exec(my_str_to_wordtab(btree->left->cmd, ' '), data);
  if (dup2(0, data->fd_save) == -1)
    exit(84);
}

void    double_inverse_red(t_graph *btree, t_data *data)
{
  int   fd;

  if (btree->right->type != ARGS)
    {
      dprintf(STD_ERR, "Missing name for redirect.");
      return ;
    }
  fd = open(btree->right->cmd, O_RDWR, S_IRWXU);
  if (fd < 0)
    exit(84);
  if ((data->fd_save = dup(0)) == -1)
    exit(84);
  lseek(fd, 1, SEEK_END);
  if (dup2(fd, 0) == -1)
    exit(84);
  exec(my_str_to_wordtab(btree->left->cmd, ' '), data);
  if (dup2(0, data->fd_save) == -1)
    exit(84);
}

void    sep_rec(t_graph *btree, t_data *data)
{
  exec_tree(btree->left, data);
  exec_tree(btree->right, data);
}

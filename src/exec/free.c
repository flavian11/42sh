/*
** free.c for  in /home/hugo/PSU_2016_42sh/src
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 22:43:03 2017 Hugo
** Last update Sat May 20 23:34:37 2017 Hugo
*/

#include <stdlib.h>
#include "proto.h"

void	free_graph(t_graph *graph)
{
  if (graph != NULL)
    {
      if (graph->left != NULL)
	free_graph(graph->left);
      if (graph->right != NULL)
	free_graph(graph->right);
      free(graph->cmd);
      free(graph);
    }
}

void	free_data(t_data *data)
{
  int	x;

  x = 0;
  while (data->envp[x] != NULL)
    {
      free(data->envp[x]);
      x++;
    }
  free(data->envp);
  free(data->cwd);
  free(data->owd);
  free(data);
}

unsigned char	free_and_exit(t_data *data, int exit_value)
{
  free_data(data);
  return (exit_value);
}

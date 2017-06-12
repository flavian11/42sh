/*
** binary_tree.c for  in /home/hugo/PSU_2016_42sh/src/lexer
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 16:54:24 2017 Hugo
** Last update Sun May 21 21:58:38 2017 Hugo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proto.h"

t_graph		*parse(char *cmd, t_graph *graph)
{
  size_t	i;

  i = 0;
  while (cmd[i] != '\0')
    i++;
  if (i > 0)
    {
      graph = is_semicolon(cmd, graph);
      graph = is_double_pipes(cmd, graph);
      graph = is_redirections(cmd, graph);
      graph = is_pipe(cmd, graph);
      graph = is_args(cmd, graph);
    }
  else
    return (NULL);
  return (graph);
}

void	print_graph(t_graph *graph)
{
  if (graph != NULL)
    {
      printf("graph->cmd:%s\n", graph->cmd);
      printf("à pour left \n");
      print_graph(graph->left);
      printf("à pour right\n");
      print_graph(graph->right);
    }
}

int	how_many_flag(t_graph *graph, int nb, int flag)
{
  if (graph != NULL)
    {
      if (graph->type == flag)
	nb++;
      nb = how_many_flag(graph->left, nb, flag);
      nb = how_many_flag(graph->right, nb, flag);
    }
  return (nb);
}

t_graph		*binary_tree(char *cmd, t_data *data)
{
  t_graph	*graph;
  char		*tmp;
  int		args;
  int		symb;

  args = symb = 0;
  tmp = strdup(cmd);
  graph = set_default_graph();
  graph = parse(tmp, graph);
  args = how_many_flag(graph, args, ARGS);
  symb = how_many_flag(graph, symb, SYMBOLE);
  if (args <= symb)
    {
      printf("Invalid null command.\n");
      data->ret = 1;
      return (NULL);
    }
  return (graph);
}

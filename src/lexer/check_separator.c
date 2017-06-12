/*
** check_separator.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 21:56:14 2017 Hugo
** Last update Sun May 21 21:57:08 2017 Hugo
*/

#include "proto.h"

t_graph         *is_semicolon(char *cmd, t_graph *graph)
{
  size_t        i;

  i = 0;
  while (cmd[i] != '\0')
    {
      graph = try(cmd, i, SEMICOLON, graph);
      i++;
    }
  return (graph);
}

t_graph         *is_double_pipes(char *cmd, t_graph *graph)
{
  size_t        i;

  i = 0;
  while (cmd[i] != '\0')
    {
      graph = try(cmd, i, DBL_AND, graph);
      graph = try(cmd, i, DBL_PIPE, graph);
      i++;
    }
  return (graph);
}

t_graph         *is_redirections(char *cmd, t_graph *graph)
{
  size_t        i;

  i = 0;
  while (cmd[i] != '\0')
    {
      graph = try(cmd, i, LEFT_RED, graph);
      graph = try(cmd, i, DBL_LEFT_RED, graph);
      graph = try(cmd, i, RIGHT_RED, graph);
      graph = try(cmd, i, DBL_RIGHT_RED, graph);
      i++;
    }
  return (graph);
}

t_graph         *is_pipe(char *cmd, t_graph *graph)
{
  size_t      i;

  i = 0;
  while (cmd[i] != '\0')
    {
      graph = try(cmd, i, PIPE, graph);
      graph = try(cmd, i, AND, graph);
      i++;
    }
  return (graph);
}

t_graph         *is_args(char *cmd, t_graph *graph)
{
  size_t        i;

  i = 0;
  if (cmd[i] != '\0')
    {
      graph->type = ARGS;
      graph = try(cmd, i, cmd, graph);
      i++;
    }
  return (graph);
}

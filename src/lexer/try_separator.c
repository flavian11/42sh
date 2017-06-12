/*
** try_separator.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 21:58:07 2017 Hugo
** Last update Sun May 21 22:04:13 2017 Hugo
*/

#include <string.h>
#include <stdlib.h>
#include "proto.h"

t_graph         *set_default_graph(void)
{
  t_graph       *new;

  if ((new = malloc(sizeof(t_graph))) == NULL)
    exit(84);
  new->cmd = NULL;
  new->left = NULL;
  new->right = NULL;
  new->type = SYMBOLE;
  return (new);
}

void    free_left_right(t_graph *left, t_graph *right)
{
  free(left);
  free(right);
}

t_graph         *try(char *cmd, size_t i, char *separator, t_graph *graph)
{
  t_graph       *left;
  t_graph       *right;

  left = set_default_graph();
  right = set_default_graph();
  if (strncmp(&cmd[i], separator, strlen(separator)) == 0)
    {
      graph->cmd = strndup(&cmd[i], strlen(separator));
      cmd[i] = '\0';
      (i > 0) ? cmd[i - 1] = '\0' : 0;
      graph->left = parse(&cmd[0], left);
      if (cmd[i + strlen(separator)] == '\0')
	{
	  cmd[i + 1] = '\0';
	  graph->right = parse(&cmd[i + strlen(separator)], right);
	}
      else
	{
	  cmd[i + 1] = '\0';
	  graph->right = parse(&cmd[i + strlen(separator) + 1], right);
	}
    }
  else
    free_left_right(left, right);
  return (graph);
}

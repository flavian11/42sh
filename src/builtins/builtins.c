/*
** builtins.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Thu May 18 10:28:48 2017 Hugo
** Last update Sun May 21 16:48:26 2017 Hugo
*/

#include <string.h>
#include <stdlib.h>
#include "proto.h"

void    builtins(t_graph *graph, t_data *data, int do_exit)
{
  int   i;

  i = 0;
  if (graph->left != NULL && strcmp(graph->cmd, "|") == 0)
    builtins(graph->left, data, 1);
  else if (graph->left != NULL)
    builtins(graph->left, data, 0);
  while (built_tab[i].built_name != NULL &&
	 strncmp(built_tab[i].built_name,
		 graph->cmd, strlen(built_tab[i].built_name)) != 0)
    i++;
  if (built_tab[i].built_name != NULL &&
      (graph->cmd[strlen(built_tab[i].built_name)] == '\0' ||
       graph->cmd[strlen(built_tab[i].built_name)] == ' '))
    {
      if ((graph->cmd = pre_processing(graph->cmd, data, false)) != NULL)
	{
	  if (do_exit == 1)
	    data->do_exit = 0;
	  built_tab[i].exec_b(my_str_to_wordtab(graph->cmd, ' '), data, false);
	  data->do_exit = 1;
	}
    }
  if (graph->right != NULL)
    builtins(graph->right, data, 0);
}

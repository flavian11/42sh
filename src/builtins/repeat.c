/*
** repeat.c for  in /home/flav/epitech/PSU/PSU_2016_42sh
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sun May 21 03:20:59 2017 flav
** Last update Sun May 21 04:36:27 2017 Hugo
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"
#include "macro.h"

void		repeat(char *cmd, t_data *data)
{
  int		nb;
  int		i;
  t_graph	*graph;

  nb = i = 0;
  nb = atoi(&cmd[REPEATLEN + 1]);
  i = REPEATLEN + 1;
  while (cmd[i] != '\0' && cmd[i] != ' ')
    i++;
  if (cmd[i] != '\0')
    {
      i++;
      graph = binary_tree(&cmd[i], data);
      i = 0;
      while (i++ < nb)
	exec_tree(graph, data);
      free_graph(graph);
    }
}

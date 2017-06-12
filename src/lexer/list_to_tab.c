/*
** list_to_tab.c for  in /home/flavian/epitech/PSU/PSU_2016_42sh/src/lexer
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Apr 19 11:40:43 2017 
** Last update Wed Apr 19 15:01:55 2017 
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "macro.h"

int	count_node(t_lexer *ll)
{
  int	i;

  i = 0;
  while (ll != NULL && ll->type != SYMBOLE)
    {
      i++;
      ll = ll->next;
    }
  return (i);
}

char	**my_list_to_tab(t_lexer *ll)
{
  char	**res;
  int	i;

  i = 0;
  res = malloc(sizeof(char *) * (count_node(ll) + 1));
  if (res == NULL)
    exit(84);
  while (ll->next != NULL)
    {
      res[i] = strdup(ll->lexem);
      i++;
      ll = ll->next;
    }
  res[i++] = strdup(ll->lexem);
  res[i] = NULL;
  return (res);
}

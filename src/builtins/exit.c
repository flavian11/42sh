/*
** exit.c for  in /home/hugo/PSU_2016_42sh/src
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 22:11:32 2017 Hugo
** Last update Sun May 21 21:59:25 2017 Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proto.h"

int	check_next(const char *str, int i, char seen, bool print)
{
  if (str[i] != ' ' && str[i] != '+' && str[i] != '-' &&
      str[i] != '*' && str[i] != '/' && str[i] != '%')
    {
      if (print == true)
	dprintf(STD_ERR, (seen == 1) ? "exit: Badly formed number.\n"
		: "exit: Expression Syntax.\n");
      return (-1);
    }
  return (0);
}

int	check_exit_syntax(const char *str, bool print)
{
  int	i;
  char	seen;

  i = seen = 0;
  while (str[i] != '\0')
    {
      (str[i] == ' ') ? seen = 0 : 0;
      if (str[i] != ' ' && (str[i] < '0' || str[i] > '9')
	  && seen == 1 && str[i] != '-')
	{
	  if (print == true)
	    dprintf(STD_ERR, "exit: Badly formed number.\n");
	  return (-1);
	}
      else if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
	{
	  if (check_next(str, i, seen, print) == -1)
	    return (-1);
	}
      else
	seen = 1;
      i++;
    }
  return (0);
}

int		check_syntax(const char *str)
{
  size_t	i;

  i = 0;
  while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9') || str[i] == '-')
    i++;
  if (str[i] == '\0')
    return (0);
  if (str[i] != ' ')
    return (-1);
  i++;
  if (str[i] != '+' && str[i] != '-' && str[i] != '*'
      && str[i] != '/' && str[i] != '%')
    return (-1);
  i++;
  if (str[i] != ' ')
    return (-1);
  i++;
  while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9') || str[i] == '-')
    i++;
  return ((str[i] == '\0') ? 0 : -1);
}

char	*convert_in_string(char **tab)
{
  int	x;
  char	*str;

  str = my_xmalloc(1);
  x = 0;
  while (tab[x] != NULL)
    {
      str = my_strcat(my_realloc(str, strlen(tab[x]), 1), tab[x]);
      if (tab[x + 1] != NULL)
	str = my_addchar(my_realloc(str, 1, 1), ' ');
      x++;
    }
  free_tab(tab);
  return (str);
}

void	my_exit(char **tab, t_data *data, bool print)
{
  int	i;
  char	*str;

  str = convert_in_string(tab);;
  i = 0;
  while (str[i] != '\0' && str[i++] != ' ');
  if (check_exit_syntax(&str[i], print) == 0)
    {
      if (check_syntax(&str[i]) == 0)
	{
	  if (data->do_exit == 1)
	    {
	      free_data(data);
	      if (print == true)
		printf("exit\n");
	      exit(do_op(&str[i]));
	    }
	  else
	    data->ret = do_op(&str[i]);
	}
      else if (print == true)
	dprintf(STD_ERR, "exit: Expression Syntax.\n");
    }
}

/*
** do_op.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Tue May 16 14:03:17 2017 Hugo
** Last update Tue May 16 14:58:05 2017 Hugo
*/

#include "proto.h"

int		do_op(char *str)
{
  int		op1;
  int		op2;
  size_t	i;
  size_t	save;

  op1 = op2 = i = 0;
  op1 = my_getnbr(str);
  while (str[i] != '\0' && str[i++] != ' ');
  if (str[i] == '\0')
    return (op1);
  save = i;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  op2 = my_getnbr(&str[++i]);
  if (str[save] == '+')
    return (op1 + op2);
  else if (str[save] == '-')
    return (op1 - op2);
  else if (str[save] == '*')
    return (op1 * op2);
  else if (str[save] == '/')
    return (op1 / op2);
  else if (str[save] == '%')
    return (op1 % op2);
  return (0);
}

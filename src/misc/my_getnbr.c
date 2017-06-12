/*
** my_getnbr.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 21:57:41 2017 Hugo
** Last update Wed May 17 23:15:44 2017 Hugo
*/

#include "proto.h"

long    my_getnbr(const char *str)
{
  int   i;
  int   neg;
  long  res;
  int   quit;

  quit = neg = res = i = 0;
  while (str[i] != '\0' && str[i] != ' ' && quit != 1)
    {
      if (str[i] == '-' && (str[i + 1] < 58 || str[i] > 47))
	neg = 1;
      if (str[i] <= '9' && str[i] >= '0')
	res = res * 10 + (str[i] - 48);
      else if (res != 0)
	quit = 1;
      i++;
    }
  if (neg == 1)
    res = res * (-1);
  return (res);
}

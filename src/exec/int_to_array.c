/*
** int_to_array.c for  in /home/hugo/PSU_2016_42sh/src/exec
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 16:28:30 2017 Hugo
** Last update Sun May 21 16:34:45 2017 Hugo
*/

#include "proto.h"

char    *int_to_array(int nb)
{
  char  *str;
  int   nb_save;
  int   c;

  c = 0;
  nb_save = nb;
  while (nb_save != 0)
    {
      nb_save /= 10;
      c++;
    }
  if (nb == 0)
    c++;
  str = my_xmalloc(c + 1);
  str[c] = '\0';
  c--;
  if (nb == 0)
    str[c] = nb + '0';
  while (nb != 0)
    {
      str[c] = (nb % 10) + '0';
      nb /= 10;
      c--;
    }
  return (str);
}

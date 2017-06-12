/*
** add_char.c for  in /home/hugo/PSU_2016_42sh/src
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Tue May 16 16:55:38 2017 Hugo
** Last update Tue May 16 16:56:10 2017 Hugo
*/

#include "proto.h"

char    *my_addchar(char *str, char c)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  str[i] = c;
  str[i + 1] = '\0';
  return (str);
}

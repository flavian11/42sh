/*
** my_strncmp.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Mon May 15 21:59:05 2017 Hugo
** Last update Mon May 15 21:59:23 2017 Hugo
*/

#include "proto.h"

int             my_strncmp(const char *s1, const char *s2, size_t len)
{
  size_t        i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && i < len)
    i++;
  if (s1[i] == s2[i] || i >= len)
    return (0);
  return (1);
}

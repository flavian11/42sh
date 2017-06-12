/*
** cd2.c for  in /home/hugo/PSU_2016_42sh/src
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Tue May 16 16:50:10 2017 Hugo
** Last update Wed May 17 22:54:01 2017 Hugo
*/

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "proto.h"

void    disp_no_file(char *str, int err, bool print)
{
  if (print == false)
    return ;
  if (err == ENOTDIR)
    dprintf(STD_ERR, "%s: Not a directory.\n", str);
  else if (err == ENOENT)
    dprintf(STD_ERR, "%s: No such file or directory.\n", str);
  else
    dprintf(STD_ERR, "%s: Permission denied.\n", str);
}

/*
** sigjandler.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 21:36:38 2017 Hugo
** Last update Sun May 21 21:39:27 2017 Hugo
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "proto.h"

void    nothing(int sig)
{
  printf("\n");
  (void)sig;
}

void    no_sigquit(int sig)
{
  (void)sig;
}

void    no_sigint(int sig)
{
  char  *str;

  str = get_current_dir_name();
  if (isatty(0) == 1)
    dprintf(STD_OUT, "\n%s> ", str);
  free(str);
  (void)sig;
}

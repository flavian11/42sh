/*
** prompt.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 16:38:07 2017 Hugo
** Last update Sun May 21 21:37:59 2017 Hugo
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "proto.h"

t_data   *get_cwd(t_data *data)
{
  data->cwd = get_current_dir_name();
  return (data);
}

void    disp_prompt(t_data *data)
{
  if (isatty(0) == 1)
    dprintf(STD_OUT, "%s> ", data->cwd);
  signal(SIGINT, no_sigint);
  signal(SIGQUIT, no_sigquit);
}

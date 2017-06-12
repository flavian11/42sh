/*
** disp_error.c for  in /home/hugo/PSU_2016_42sh
** 
** Made by Hugo
** Login   <hugo.tallineau@epitech.eu>
** 
** Started on  Sun May 21 16:17:42 2017 Hugo
** Last update Sun May 21 16:20:49 2017 Hugo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

void            disp_error(char **cmd, t_data *data)
{
  struct stat   sb;

  execve(cmd[0], cmd, data->envp);
  if ((stat(cmd[0], &sb)) == -1)
    return ;
  if ((sb.st_mode & S_IFMT) == S_IFREG)
    dprintf(STD_ERR, "%s: Exec format error. Binary file not executable.\n",
	    cmd[0]);
  else
    dprintf(STD_ERR, "%s: Permission denied.\n", cmd[0]);
  exit(1);
}

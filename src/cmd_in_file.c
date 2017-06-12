/*
** cmd_in_file.c for  in /home/flav/epitech/PSU/PSU_2016_42sh
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sun May 21 21:52:29 2017 flav
** Last update Sun May 21 22:06:37 2017 flav
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "proto.h"

void	cmd_in_file(char **av, t_data *data)
{
  int	fd;
  char	*cmd;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    exit(84);
  while ((cmd = get_next_line(fd)) != NULL)
    {
      cmd = shell_like_expansion(cmd, data);
      if (cmd[0] != '\0')
	main_fork(cmd, data);
    }
}

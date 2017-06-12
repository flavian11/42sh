/*
** get_signal.c for 42sh in /home/ZephX/Documents/PSU/PSU_2016_42sh/src
** 
** Made by Marigonez Estéban
** Login   <esteban.marigonez@epitech.eu>
** 
** Started on  Mon May 15 16:35:35 2017 Marigonez Estéban
** Last update Sun May 21 19:12:25 2017 Hugo
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "proto.h"
#include "struct.h"
#include <string.h>
#include <stdio.h>

t_sig	sig_tab[] =
{
  {HANGUPRET, "Hangup"},
  {QUITRET, "Quit"},
  {ILLEGALRET, "Illegal instruction"},
  {TRACERET, "Trace/breakpoint trap"},
  {ABORTRET, "Abort"},
  {BUSRET, "Bus error"},
  {FLOATRET, "Floating exception"},
  {KILLRET, "Killed"},
  {USR1RET, "User defined signal 1"},
  {USR2RET, "User defined signal 2"},
  {BPIPERET, "Broken pipe"},
  {CLOCKRET, "Alarm clock"},
  {TERMRET, "Terminated"},
  {STACKLIMRET, "Stack limit exceeded"},
  {SIGSTOP, "\nSuspend (signal)"},
  {SIGTSTP, "\nSuspend"},
  {SIGTTIN, "\nSuspend (tty input)"},
  {SIGTTOU, "\nSuspend (tty output)"},
  {CPURET, "Cputime limit exceeded"},
  {FSZRET, "Filesize limit exceeded"},
  {VALARMRET, "Virtual time alarm"},
  {PROFRET, "Progiling time alarm"},
  {IORET, "Pollable event occured"},
  {POLLRET, "Pollable event occured"},
  {PWRRET, "Power failure"},
  {SYSRET, "Bad system call"},
  {SIGSEGVRET, "Segmentation fault"},
  {0, NULL}
};

void	get_signal(t_data *data, pid_t pid)
{
  int	i;
  int	status;

  i = 0;
  waitpid(pid, &status, WCONTINUED);
  if (!(WIFEXITED(status)))
    data->ret = status;
  else
    data->ret = WEXITSTATUS(status);
  while (sig_tab[i].sig != 0 && status != sig_tab[i].sig)
    i++;
  if (sig_tab[i].str != NULL)
    {
      dprintf(STD_ERR, "%s", sig_tab[i].str);
      if (WCOREDUMP(status))
	dprintf(STD_ERR, " (core dumped)");
      dprintf(STD_ERR, "\n");
    }
}

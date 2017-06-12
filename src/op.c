/*
** op.c for  in /home/flav/epitech/PSU/PSU_2016_42sh
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon May 15 15:17:25 2017 flav
** Last update Thu May 18 18:51:03 2017 flav
*/

#include <unistd.h>
#include "struct.h"
#include "proto.h"

t_op	op_tab[] =
  {
    {"|", pipe_rec},
    {"&&", esp_rec},
    {";", sep_rec},
    {">", simple_red},
    {">>", double_red},
    {"<", inverse_red},
    {"<<", double_inverse_red},
    {"||", double_pipe},
    {0, 0}
  };

t_builtin	built_tab[] =
  {
    {"cd", cd},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"exit", my_exit},
    {"echo", my_echo},
    {NULL, 0}
  };

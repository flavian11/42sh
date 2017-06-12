/*
** struct.h for  in /home/flavian/epitech/PSU/PSU_2016_42sh
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue Apr 18 16:25:31 2017 
** Last update Sat May 20 21:48:31 2017 Hugo
*/

#ifndef STRUCT_H
# define STRUCT_H
# include <stdbool.h>

typedef struct s_lexer		t_lexer;
typedef struct s_graph		t_graph;
typedef struct s_data		t_data;
typedef struct s_op		t_op;
typedef struct s_builtin	t_builtin;
typedef struct s_sig		t_sig;

struct			s_builtin
{
  char			*built_name;
  void			(*exec_b)(char **tab, t_data *data, bool print);
};

struct			s_op
{
  char			*separator;
  void			(*ex)(t_graph *btree, t_data *data);
};

struct s_lexer
{
  int		type;
  char		*lexem;
  t_lexer	*next;
};

struct		s_graph
{
  char		*cmd;
  t_graph	*left;
  t_graph	*right;
  int		type;
};

struct		s_data
{
  char		*cwd;
  char		*owd;
  char		*home;
  char		**envp;
  int		ret;
  int		fd_save;
  int		do_exit;
};

struct s_sig
{
  int   sig;
  char  *str;
};

extern t_op		op_tab[];
extern t_builtin	built_tab[];

#endif

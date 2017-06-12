/*
** proto.h for  in /home/flavian/epitech/PSU/PSU_2016_42sh
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon May  1 16:13:26 2017 
** Last update Sun May 21 22:09:57 2017 flav
*/

#include <sys/types.h>
#include "struct.h"
#include "macro.h"

#pragma once

t_lexer	*my_lexer(char *);

t_graph	*binary_tree(char *, t_data *);
t_graph	*parse(char *, t_graph *);
t_graph	*is_semicolon(char *, t_graph *);
t_graph	*is_double_pipes(char *, t_graph *);
t_graph	*is_redirections(char *, t_graph *);
t_graph	*is_pipe(char *, t_graph *);
t_graph	*is_args(char *, t_graph *);
t_graph	*set_default_graph();
t_graph *try(char *, size_t, char *, t_graph *);

t_data	*get_cwd(t_data *);
t_data	*start(char **, int);

char	*get_next_line(const int);
char	*my_realloc(char *, size_t, int);
char	*my_strcat(char *, char *);
char	*my_xmalloc(size_t);
char	*epurestr(char *);
char	*pre_processing(char *, t_data *, bool);
char	*my_addchar(char *, char);
char	*get_current_dir_name(void);
char	*shell_like_expansion(char *, t_data *);
char	*insert_char(char *, char, size_t);
char	*int_to_array(int);
char	*replace_home(char *, size_t, t_data *);
char	*replace_env_value(char *, size_t, t_data *, bool);

char	**my_list_to_tab(t_lexer *);
char	**my_str_to_wordtab(char *, char);
char	**add_line_to_env(char **, char **);

long	my_getnbr(const char *);

int	control_d(void);
int	check_exit(t_graph *);
int	do_op(char *);
int	my_exec(char **, t_data *);
int	find_absolute_path(char *);

void	print_list(t_lexer *);
void	free_graph(t_graph *);
void	free_tab(char **);
void	free_data(t_data *);
void	no_sigint(int);
void	no_sigquit(int);
void	nothing(int);
void	disp_prompt(t_data *);
void	disp_no_file(char *, int, bool);
void	disp_error(char **, t_data *);
void	exec_tree(t_graph *, t_data *);
void	esp_rec(t_graph *, t_data *);
void	sep_rec(t_graph *, t_data *);
void	red_rec(t_graph *, t_data *);
void	pipe_rec(t_graph *, t_data *);
void	double_pipe(t_graph *, t_data *);
void	exec(char **, t_data *);
void	cd(char **, t_data *, bool);
void	my_setenv(char **, t_data *, bool);
void	my_unsetenv(char **, t_data *, bool);
void	my_exit(char **, t_data *, bool);
void	my_echo(char **, t_data *, bool);
void	get_signal(t_data *, pid_t);
void	builtins(t_graph *, t_data *, int);
void	simple_red(t_graph *, t_data *);
void	double_red(t_graph *, t_data *);
void	inverse_red(t_graph *, t_data *);
void	double_inverse_red(t_graph *, t_data *);
void	repeat(char *, t_data *);
void	print_var_name(char *);
void	main_fork(char *, t_data *);
void	cmd_in_file(char **, t_data *);

unsigned char	free_and_exit(t_data *, int);

##
## Makefile for  in /home/flavian/epitech/PSU/PSU_2016_42sh
## 
## Made by 
## Login   <flavian.feugueur@epitech.eu>
## 
## Started on  Wed Apr 19 14:56:10 2017 
## Last update Mon Jun 12 13:23:38 2017 
##

ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"


CC	=	gcc

RM	=	rm -f

SRC	=	src/

READ	=	$(SRC)read/

LEXER	=	$(SRC)lexer/

MISC	=	$(SRC)misc/

EXE	=	$(SRC)exe/

EXEC	=	$(SRC)exec/

SIG	=	$(SRC)signal/

BUILT	=	$(SRC)builtins/

SRCS	=	$(SRC)main.c \
		$(SRC)op.c \
		$(SRC)my_str_to_wordtab.c \
		$(SRC)free_tab.c \
		$(SRC)cmd_in_file.c \
		$(SIG)get_signal.c \
		$(BUILT)exit.c \
		$(BUILT)my_setenv.c \
		$(BUILT)my_unsetenv.c \
		$(BUILT)cd.c \
		$(BUILT)cd2.c \
		$(BUILT)echo.c \
		$(BUILT)repeat.c \
		$(BUILT)builtins.c \
		$(EXEC)free.c \
		$(EXEC)prompt.c \
		$(EXEC)start.c \
		$(EXEC)pre_processing.c \
		$(EXEC)insert_char.c \
		$(EXEC)sighandler.c \
		$(EXEC)int_to_array.c \
		$(EXEC)replace_env_value.c \
		$(EXE)exec_tree.c \
		$(EXE)find_path.c \
		$(EXE)my_exe.c \
		$(EXE)disp_error.c \
		$(EXE)redirections.c \
		$(LEXER)list_to_tab.c \
		$(LEXER)binary_tree.c \
		$(LEXER)check_separator.c \
		$(LEXER)try_separator.c \
		$(MISC)do_op.c \
		$(MISC)my_strcat.c \
		$(MISC)my_realloc.c \
		$(MISC)my_xmalloc.c \
		$(MISC)add_char.c \
		$(MISC)my_getnbr.c \
		$(READ)get_next_line.c \
		$(READ)epurestr.c

OBJ	=	$(SRCS:.c=.o)

NAME	=	42sh

CFLAGS	+=	-I ./include -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.c=.c~)
	$(RM) $(SRCS:.c=.c#)

fclean: clean
	$(RM) $(NAME)

re: fclean all

flav: re
	make clean
	@echo $(TEAL)'   _____ ________         .__'
	@echo $(TEAL)'  /  |  |\_____  \   _____|  |__'
	@echo $(TEAL)' /   |  |_/  ____/  /  ___/  |  \\'
	@echo $(TEAL)'/    ^   /       \  \___ \|   Y  \\'
	@echo $(TEAL)'\____   |\_______ \/____  >___|  /'
	@echo $(TEAL)'     |__|        \/     \/     \/ '

.c.o:
		@gcc $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

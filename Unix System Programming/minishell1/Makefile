##
## EPITECH PROJECT, 2024
## Minishell 1
## File description:
## Makefile
##

NAME	=	mysh

SRC		=	src/main.c							\
			src/env_handling.c					\
			src/minishell.c						\
			src/parsing_args.c					\
			src/commands/exec.c					\
			src/builtins/cd.c					\
			src/builtins/exit.c					\
			src/builtins/env.c					\
			src/builtins/setenv.c				\
			src/builtins/unsetenv.c				\
			src/builtins/required_functions.c	\

OBJ		=	$(SRC:.c=.o)

INC		=    -I./include

LIBFLAGS=	-L./lib -lmy

CFLAGS	=	-W -Wall -Wextra -Werror $(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/
		$(CC) -o $(NAME) $(OBJ) $(LIBFLAGS) -g3

clean:
		make clean -C lib/
		$(RM) *~
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C lib/
		$(RM) $(NAME)

re:			fclean all

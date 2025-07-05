##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## bs
##

NAME=	my_executable

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) *~
	$(RM) $(OBJ)
	make -C tests/ clean

fclean:	clean
	$(RM) $(NAME)
	make -C tests/ fclean

re:	fclean all

tests_run:
		make -C tests/

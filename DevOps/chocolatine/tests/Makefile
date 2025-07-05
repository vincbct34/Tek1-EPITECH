##
## EPITECH PROJECT, 2024
## CHOCOLATINE
## File description:
## Makefile
##

NAME=	my_tests

SRC	=	test.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

LDFLAGS_TEST	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS_TEST)
		./$(NAME)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

tests_run:
		make -C tests/
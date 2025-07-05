##
## EPITECH PROJECT, 2024
## Fibonacci Checker
## File description:
## Makefile
##

NAME	=	fibonacci_checker

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) -f *~
	$(RM) -f src/*~
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Solo Stumper n°2
##

NAME	=	hidenp

SRC	=	src/main.c		\
		src/error_handling.c	\
		src/hidenp.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra -I./include/

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

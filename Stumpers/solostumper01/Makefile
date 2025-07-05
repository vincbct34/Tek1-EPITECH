##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Solo stumper n°1
##

NAME 	= 	clean_str

SRC 	= 	src/main.c	\
		src/my_strlen.c \
		src/my_putstr.c	\
		src/clean_str.c	\
		src/my_putchar.c\

OBJ	=	$(SRC:.c=.o)

INC	=	-I./include/

CFLAGS	=	-Wall -Wextra -Werror $(INC)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -g3

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Setting up Makefile
##

NAME=	organized

SRC	=	src/add.c				\
		src/del.c				\
		src/disp.c				\
		src/sort.c				\
		src/main.c				\
		lib.c					\
		lib2.c					\

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

LFLAGS	= -L./lib -lshell

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(LFLAGS)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

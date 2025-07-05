##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Setting up Makefile
##

NAME=	setting_up

SRC	=	src/solver.c			\
		src/main.c	 			\
		src/get_dimensions.c	\
		src/generator.c			\
		lib.c					\

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

CCFLAGS	= -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:
	cd ./tests/ && ./test
	cd ..

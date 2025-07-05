##
## EPITECH PROJECT, 2024
## my_sokoban
## File description:
## Makefile
##

NAME	=	my_sokoban

SRC		=	src/main.c			\
			src/my_sokoban.c	\
			src/map_handling.c	\
			src/positions.c		\
			src/move.c			\
			src/boxes.c			\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Werror -Wall -Wextra

LIBFLAGS=	-L./lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIBFLAGS) -lncurses -g3

clean:
	make clean -C lib/
	$(RM) *~
	$(RM) $(OBJ)

fclean:		clean
	make fclean -C lib/
	$(RM) $(NAME)

re:			fclean all

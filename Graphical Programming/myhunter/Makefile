##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_hunter
##

NAME=	my_hunter

SRC	=	src/all_sprites.c		\
		src/background_sprite.c	\
		src/events.c			\
		src/game_sprites.c		\
		src/second_bird.c		\
		src/third_bird.c		\
		src/game.c				\
		src/main.c				\
		src/menu_sprites.c		\
		src/menu.c				\
		src/lib.c				\
		src/settings.c			\
		src/score.c				\

OBJ	=	$(SRC:.c=.o)


CFLAGS	=	-Werror -Wall -Wextra

GRAPHS  =	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(GRAPHS)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

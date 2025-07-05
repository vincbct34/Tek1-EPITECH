##
## EPITECH PROJECT, 2024
## Solo Stumper 07
## File description:
## Makefile
##

NAME	=	snakecase_formatter

SRC	=	src/main.c		\
		src/snake_formatter.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS=	-I./include

LDFLAGS	=	-L./lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/
	$(RM) *~
	$(RM) $(OBJ)

fclean:		clean
	make fclean -C lib/
	$(RM) $(NAME)

re:		fclean all

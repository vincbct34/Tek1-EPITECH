##
## EPITECH PROJECT, 2024
## Fridge
## File description:
## Makefile
##

NAME	=	fridge

SRC	=	src/main.c		\
		src/addtofridge.c	\
		src/dispfridge.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS=	-I ./includes

CFLAGS	=	-W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) *~
	$(RM) src/*~
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

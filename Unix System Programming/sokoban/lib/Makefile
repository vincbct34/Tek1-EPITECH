##
## EPITECH PROJECT, 2024
## my_sokoban
## File description:
## Makefile
##

NAME	=	libmy.a

SRC		=	my_getnbr.c		\
			my_strcmp.c		\
			my_putstr.c		\
			my_putchar.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Werror -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../include/

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

##
## EPITECH PROJECT, 2024
## Solo Stumper 5
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	my_putchar.c	\
		my_strlen.c	\
		my_putstr.c	\
		my_getnbr.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS=	-I./../include

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

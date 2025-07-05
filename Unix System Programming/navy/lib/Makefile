##
## EPITECH PROJECT, 2024
## Navy
## File description:
## Makefile
##

NAME	=	libmy.a

SRC		=	my_putchar.c			\
			my_putstr.c				\
			my_putnbr.c				\
			my_strlen.c				\
			my_getnbr.c				\
			my_strcpy.c				\
			my_strcat.c				\
			my_str_isnum.c			\
			my_str_is_printable.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f *.o

re:	fclean all

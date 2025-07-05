##
## EPITECH PROJECT, 2024
## Corewar
## File description:
## Makefile
##

NAME		=		libmy.a

SRC 		=		my_putchar.c		\
					my_putstr.c			\
					my_strcmp.c			\
					my_getnbr.c			\

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-W -Wall -Wextra -Werror

CPPFLAGS	=		-I./../include

all:				$(NAME)

$(NAME):			$(OBJ)
		ar rc -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
		$(RM) *~

fclean:				clean
		$(RM) $(NAME)

re:					fclean all

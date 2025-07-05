##
## EPITECH PROJECT, 2024
## Stumper 7
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	return_error.c		\
		is_alphanum.c		\
		dup_arg.c		\
		check_and_dup_arg.c	\

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

re:		fclean all

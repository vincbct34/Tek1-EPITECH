##
## EPITECH PROJECT, 2024
## Cesar
## File description:
## Makefile
##

NAME	=	cesar

SRC	=	src/main.c		\
		src/encrypt_string.c	\
		src/encrypt_file.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3

CPPFLAGS=	-I./include

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) *~
	$(RM) src/*~
	$(RM) include/*~
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

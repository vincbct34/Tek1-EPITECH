##
## EPITECH PROJECT, 2024
## Duo stumper
## File description:
## Makefile
##

NAME	=	text_count

SRC	=	src/main.c		\
		src/basic_count.c	\
		src/three_args.c	\
		src/four_args.c		\
		src/five_args.c		\

OBJ	=	$(SRC:.c=.o)

CFFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS=	-I./includes

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) src/*~
	$(RM) includes/*~

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

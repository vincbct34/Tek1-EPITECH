##
## EPITECH PROJECT, 2024
## Corewar
## File description:
## Makefile
##

NAME		=		corewar

SRC 		=		src/main.c			\
					src/argument.c	 	\
					src/file.c			\
					src/flag.c			\
					src/init.c			\
					src/parser.c		\

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-W -Wall -Wextra -Werror

CPPFLAGS	=		-I./include

LDFLAGS		=		-L./lib -lmy

all:				$(NAME)

$(NAME):			$(OBJ)
		make -C lib
		$(CC) -o $(NAME) $(OBJ) -lncurses $(LDFLAGS)

clean:
		make clean -C lib
		make clean -C bonus
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) src/*~
		$(RM) include/*~

fclean:				clean
		make fclean -C lib
		make fclean -C bonus
		$(RM) $(NAME)

re:					fclean all

make_b:
		make -C bonus

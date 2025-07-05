##
## EPITECH PROJECT, 2024
## Corewar
## File description:
## Makefile
##

NAME		=		corewar_bonus

SRC 		=		src/main.c

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-W -Wall -Wextra -Werror

CPPFLAGS	=		-I./../include

LDFLAGS		=		-L./../lib -lmy

all:				$(NAME)

$(NAME):			$(OBJ)
		make -C ../lib
		$(CC) -o $(NAME) $(OBJ) -lncurses $(LDFLAGS)
		mv $(NAME) ../

clean:
		make clean -C ../lib
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) src/*~
		$(RM) include/*~

fclean:				clean
		make fclean -C ../lib
		$(RM) ../$(NAME)

re:					fclean all

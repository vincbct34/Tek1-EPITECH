##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## printf
##

NAME=	my_ls

SRC	=	my_ls.c		\
		l_options.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

LDFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS)

clean:
	$(RM) *~
	$(RM) $(OBJ)
	make clean -C ./lib/my/

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/

re:	fclean all

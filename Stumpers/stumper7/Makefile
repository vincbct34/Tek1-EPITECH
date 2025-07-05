##
## EPITECH PROJECT, 2024
## Stumper 7
## File description:
## Makefile
##

NAME	=	crocus

SRC	=	src/main.c			\
		src/logical_application.c	\
		src/disp.c			\
		src/disp_first_half.c		\
		src/disp_second_half.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Werror -Wextra

CPPFLAGS=	-I./include

LDFLAGS =	-L./lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/
	$(RM) *~
	$(RM) src/*~
	$(RM) include/*~
	$(RM) $(OBJ)

fclean:		clean
	make fclean -C lib/
	$(RM) $(NAME)

re:		fclean all

##
## EPITECH PROJECT, 2024
## B-CPE-200-MPL-2-1-amazed-vincent.bichat
## File description:
## Makefile
##

NAME        =		amazed

SRC         =		src/main.c							\
					src/init.c							\
					src/algo.c							\
					src/path.c							\
					src/parsing/init_parsing.c			\
					src/parsing/parsing.c				\
					src/matrix.c						\

OBJ         =		$(SRC:.c=.o)

CFLAGS      =		-W -Werror -Wall -Wextra -g3

CPPFLAGS    =		-I./include

LDFLAGS     =		-L./lib -lmy

all:				$(NAME)

$(NAME):			$(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib
	rm -f $(OBJ)
	make clean -C tests

fclean:	clean
	make fclean -C lib
	rm -f $(NAME)
	make fclean -C tests

tests_run:	re
	make tests_run -C tests

re:	fclean all

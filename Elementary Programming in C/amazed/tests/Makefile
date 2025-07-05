##
## EPITECH PROJECT, 2024
## B-CPE-200-MPL-2-1-amazed-vincent.bichat
## File description:
## Makefile
##

NAME        = unit_tests

SRC         = ../src/init.c \
              ../src/algo.c \
              ../src/path.c \
              ../src/parsing/init_parsing.c \
              ../src/matrix.c \
              init_test.c

OBJ         = $(SRC:.c=.o)

CFLAGS      = -W -Werror -Wall -Wextra --coverage
CPPFLAGS    = -I../include
LDFLAGS     = -L../lib -lmy -lcriterion -lgcov

tests_run: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	./$(NAME)

clean:
	make clean -C ../lib
	rm -f $(OBJ) *.gcno ../src/*.gcno ../src/parsing/*.gcno

fclean : clean
	make fclean -C ../lib
	rm -f $(NAME) *.gcda ../src/*.gcda ../src/parsing/*.gcda

re: fclean tests_run


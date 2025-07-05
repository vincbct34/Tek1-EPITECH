##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for Bootcamp Day 1
##

NAME  	=       unit_tests

SRCS    =       tests/test.c            \
				reverse_string.c        \
				show_alphabet.c         \
				show_combinations.c     \
				show_number.c           \
				show_string.c           \
				to_number.c             \

OBJS    =       $(SRCS:.c=.o)

CFLAGS  =       -Wall -Wextra -Werror --coverage

LDFLAGS =       -lcriterion -lgcov

all:            $(NAME)

$(NAME):        $(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
				rm -f $(OBJS)
				rm -f *.gcda
				rm -f *.gcno

fclean:         clean
				rm -f $(NAME)

re:             fclean all

tests_run:      $(NAME)
				./$(NAME)

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for Bootcamp Day 1
##

NAME  	=       unit_tests

SRCS    =       tests/test.c            \
				is_prime_number.c		\
				iterative_factorial.c	\
				my_strcapitalize.c		\
				my_strcpy.c				\
				my_strncmp.c			\
				my_strstr.c				\
				my_strupcase.c			\
				recursive_power.c		\

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

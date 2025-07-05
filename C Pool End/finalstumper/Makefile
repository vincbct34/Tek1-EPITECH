##
## EPITECH PROJECT, 2023
## makefile
## File description:
## task01 day10
##


SRCS	=	my_putstr.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		finalstumper.c	\

OBJS	=	$(SRCS:.c=.o)

NAME	=	rush3

TESTS	=	tests/test_finalstumper.c

NAME_TEST	=	unit-tests

CFLAGS	=	-Werror -Wall -Wextra -W

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

tests_run:	$(OBJS)
	$(CC) -o $(NAME_TEST) $(OBJS) $(TESTS) $(CPPFLAGS) --coverage -lcriterion
	./$(NAME_TEST)

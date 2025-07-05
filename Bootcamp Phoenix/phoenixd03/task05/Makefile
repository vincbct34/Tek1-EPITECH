##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for Bootcamp Day 1
##

NAME  	=       sorted_params

SRCS    =       sorted_params.c

OBJS    =       $(SRCS:.c=.o)

CFLAGS  =       -Wall -Wextra -Werror

CPPFLAGS =      -I../includes -L../lib/phoenix -lphoenix

all:            $(NAME)

$(NAME):        $(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
				rm -f $(OBJS)
				rm -f *.gcda
				rm -f *.gcno

fclean:         clean
				rm -f $(NAME)

re:             fclean all

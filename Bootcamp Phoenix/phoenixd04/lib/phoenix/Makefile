##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile of the Bootcamp Day 3
##

NAME	= 	libphoenix.a

SRCS	=	my_putchar.c		\
			show_number.c		\
			show_string.c		\
			reverse_string.c	\
			to_number.c			\
			is_prime_number.c	\
			my_strcpy.c			\
			my_strncmp.c		\
			my_strstr.c			\
			my_strlen.c			\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

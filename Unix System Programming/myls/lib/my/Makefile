##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	libmy.a

SRCS	=	my_first_basics.c		\
			my_second_basics.c		\
			my_third_basics.c		\
			my_advanced_functions.c	\
			my_first_flags.c			\
			my_second_flags.c		\
			my_third_flags.c			\
			my_printf.c				\
			long_percent.c			\
			format_percent_hashtag.c	\
			format_percent_plus.c	\
			format_percent_space.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *~
	rm -f .o

fclean: clean
	rm -f $(NAME)

re: fclean all

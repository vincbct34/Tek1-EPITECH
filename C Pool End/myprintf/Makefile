##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	libmy.a

SRCS	=	lib/my/my_first_basics.c		\
			lib/my/my_second_basics.c		\
			lib/my/my_advanced_functions.c	\
			lib/my/my_first_flags.c		\
			lib/my/my_second_flags.c		\
			lib/my/third_flags.c	\
			lib/my/my_printf.c				\
			lib/my/long_percent.c	\
			lib/my/format_percent_hashtag.c	\
			lib/my/format_percent_plus.c	\
			lib/my/format_percent_space.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

all:	$(NAME)
	cp lib/my/myprintf.h includes/
	cp libmy.a lib/my/

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *~
	rm -f .o

fclean: clean
	rm -f $(NAME)

re: fclean all

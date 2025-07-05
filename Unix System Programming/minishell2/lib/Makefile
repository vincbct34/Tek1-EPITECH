##
## EPITECH PROJECT, 2024
## Minishell 1
## File description:
## Makefile
##

NAME	=	libmy.a

SRC		=	my_getnbr.c				\
			my_strcmp.c				\
			my_putstr.c				\
			my_putchar.c			\
			my_strlen.c				\
			my_strcpy.c				\
			my_putnbr.c				\
			my_strncmp.c			\
			my_strcat.c				\
			my_strdup.c				\
			my_str_to_word_array.c	\
			my_strchr.c				\
			is_alpha_num.c			\
			my_strncpy.c			\
			my_puterror.c			\
			my_strarraylen.c		\
			my_realloc.c			\
			is_delim.c				\
			clean_str.c				\

OBJ		=	$(SRC:.c=.o)

INC		=	-I./../include

CFLAGS	=	-W -Werror -Wall -Wextra $(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

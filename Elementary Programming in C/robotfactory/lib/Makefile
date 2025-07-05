##
## EPITECH PROJECT, 2023
## B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
## File description:
## Makefile
##

NAME	=		libmy.a

SRC		=		my_getnbr.c				\
				my_putchar.c			\
				my_putstr.c				\
				my_strlen.c				\
				copy_array.c			\
				my_strncpy.c			\
				my_strcmp.c				\
				my_str_isalpha.c		\
				my_str_isnum.c			\
				my_str_to_line_array.c	\
				my_strcat.c				\
				my_strchr.c				\
				my_strcmp.c				\
				my_strdup.c				\
				my_strstr.c				\
				my_strtok.c				\
				my_strrchr.c			\

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-W -Wall -Wextra -Werror

CPPFLAGS	=	-I./../include

all:			$(NAME)

$(NAME):		$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:    		clean
	$(RM) $(NAME)

re:    			fclean all

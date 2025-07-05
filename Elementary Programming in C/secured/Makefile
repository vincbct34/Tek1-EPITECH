##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Secured
##

NAME	=	libhashtable.a

SRC		=	src/hash_function.c		\
			src/hashtable.c			\
			src/dump_function.c		\
			src/insert_function.c	\
			src/delete_function.c	\
			src/search_function.c	\
			src/lib.c				\

OBJ		=	$(SRC:.c=.o)

CFLAGS 	= 	-W -Wall -Werror -Wextra

all:		$(NAME)

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f .o

fclean: 	clean
	rm -f $(NAME)

re: 		fclean all

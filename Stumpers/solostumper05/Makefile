##
## EPITECH PROJECT, 2024
## Solo Stumper 5
## File description:
## Makefile
##

NAME	=	luhn_validator

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS=	-I./include

LIBFLAGS=	-L./lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIBFLAGS)

clean:
	make clean -C lib/
	$(RM) *~
	$(RM) src/*~
	$(RM) include/*~
	$(RM) $(OBJ)

fclean:		clean
	make fclean -C lib/
	$(RM) $(NAME)

re:		fclean all

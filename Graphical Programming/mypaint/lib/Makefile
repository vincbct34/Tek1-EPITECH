##
## EPITECH PROJECT, 2023
## B-MUL-200-MPL-2-1-mypaint-vincent.bichat
## File description:
## Makefile
##

##
## EPITECH PROJECT, 2023
## B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
## File description:
## Makefile
##

NAME	=		libmy.a

SRC		=		my_putchar.c			\
				my_putstr.c				\
				my_strdup.c				\
				my_strcat.c				\
				my_strlen.c				\
				my_strcmp.c				\

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

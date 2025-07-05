##
## EPITECH PROJECT, 2023
## B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
## File description:
## Makefile
##

NAME	=		asm

SRC    	=		src/parsing/read.c							\
				src/handling/parsing_error/header/header.c	\
				src/handling/parsing_error/body/index.c		\
				src/handling/parsing_error/body/params.c	\
				src/handling/parsing_error/body/count.c		\
				src/handling/parsing_error/body/compare.c	\
				src/handling/array/convert.c				\
				src/handling/array/label.c					\
				src/write.c									\
				src/main.c									\
				src/get.c									\
				src/op.c									\

OBJ    	=    	$(SRC:.c=.o)

CFLAGS  =    	-Werror -Wall -Wextra -g3

CPPFLAGS=    	-I ./include

LDFLAGS =    	-L lib/ -lmy

all:    		$(NAME)

$(NAME):		$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/
	$(RM) *~
	$(RM) $(OBJ)

fclean:    		clean
	make fclean -C lib/
	$(RM) $(NAME)

re:    			fclean all

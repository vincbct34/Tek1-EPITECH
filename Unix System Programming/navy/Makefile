##
## EPITECH PROJECT, 2023
## Navy
## File description:
## Makefile
##

NAME    =   my_navy

SRC     =	src/main.c 			\
        	src/engine.c 		\
        	src/check_fill.c 	\
        	src/display.c 		\
        	src/get.c 			\
        	src/handler.c 		\
        	src/packets.c 		\
        	src/parsing.c 		\
        	src/read.c 			\
        	src/signal.c 		\

OBJ    	=    $(SRC:.c=.o)

CFLAGS  =    -W -Wall -Werror -Wextra

all:    	$(NAME)

$(NAME): 	$(OBJ)
	make -C lib
	$(CC) $(SRC) -o $(NAME) -L./lib -lmy -g3

clean:
	make clean -C lib
	rm -f $(OBJ)
	rm -f *~
	rm -f .o

fclean: 	clean
	make fclean -C lib
	rm -f $(NAME)

re: 		fclean all

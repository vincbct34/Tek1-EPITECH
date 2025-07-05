##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Day 12
##

NAME	=	cat

SRC	=	cat.c

OBJ	=	$(SRC:.c=.o)

LDFLAG = -L../lib/my/ -lmy
CFLAGS = -I../include/

all: $(NAME)

$(NAME): make_lib $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAG)

make_lib:
	make -C ../lib/my

clean:
	$(RM) $(OBJS)
	make clean -C ../lib/my

fclean: clean
	make fclean -C ../lib/my
	$(RM) $(NAME)

re: fclean all

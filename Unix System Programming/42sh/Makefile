##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## bsminishell
##

NAME=    42sh

SRC    =    src/main.c						\
			src/lib/lib.c					\
			src/lib/lib2.c					\
			src/lib/get_promte.c			\
			src/commands/cd_command.c		\
			src/verifications/analyse.c		\
			src/verifications/commands.c	\
			src/verifications/commands_bis.c\
			src/lib/get.c					\
			src/lib/clean_str.c				\
			src/lib/my_strchr.c				\
			src/free/free.c					\
			src/commands/env_commands.c		\
			src/lib/env_lib.c				\
			src/lib/env_lib2.c				\
			src/lib/handler.c				\
			src/lib/my_str_to_word_array.c	\
			src/lib/list_to_double_array.c	\
			src/lib/error.c					\
			src/lib/my_tabcat.c				\
			src/lib/my_tabdup.c				\
			src/lib/my_tablen.c				\
			src/lib/my_tabadd.c				\
			src/lib/array_to_str.c			\
			src/tree/build.c				\
			src/tree/build_bis.c			\
			src/tree/execute.c				\
			src/termios.c					\
			src/my_get_input.c				\
			src/my_get_input_2.c			\
			src/history.c					\
			src/aliases/alias.c				\
			src/aliases/exec_alias.c			\
			src/aliases/emi_get_path.c		\
			src/aliases/condition_aliases.c		\
			src/aliases/alias_param.c		\
			src/aliases/add_alias.c	\

OBJ    =    $(SRC:.c=.o)

CFLAGS    =    -W -Werror -Wall -Wextra -g3

CPPFLAGS    =    -I ./include

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	cp $(NAME) tests/

clean:
	$(RM) *~
	$(RM) $(OBJ)

fclean:    clean
	$(RM) $(NAME)
	$(RM) tests/$(NAME)
debug:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) -g3

re:    fclean all

tests_run:
	$(CC) -o unit-tests tests/test.c  \
	src/lib/lib.c src/lib/lib2.c src/lib/get_promte.c  \
	src/commands/cd_command.c src/verifications/analyse.c  \
	src/verifications/commands.c src/lib/get.c  \
	src/lib/clean_str.c src/lib/my_strchr.c  \
	src/free/free.c src/commands/env_commands.c  \
	src/lib/env_lib.c src/lib/env_lib2.c  \
	src/lib/handler.c src/lib/my_str_to_word_array.c  \
	src/lib/list_to_double_array.c src/lib/error.c  \
	src/lib/my_tabcat.c src/lib/my_tabdup.c  \
	src/lib/my_tablen.c src/lib/my_tabadd.c  \
	src/lib/array_to_str.c src/tree/build.c  \
	src/tree/build_bis.c src/tree/execute.c  \
	src/termios.c src/my_get_input.c  \
	src/my_get_input_2.c src/history.c  \
	src/aliases/alias.c src/aliases/exec_alias.c  \
	src/aliases/emi_get_path.c src/aliases/condition_aliases.c  \
	src/aliases/alias_param.c src/aliases/add_alias.c  \
	src/verifications/commands_bis.c -lcriterion --coverage
	./unit-tests

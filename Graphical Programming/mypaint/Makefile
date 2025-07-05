##
## EPITECH PROJECT, 2024
## B-MUL-200-MPL-2-1-mypaint-vincent.bichat
## File description:
## Makefile
##

NAME	=	my_paint

SRC		=	src/actions/buttons/all_buttons/eraser.c				\
			src/actions/buttons/all_buttons/pencil.c				\
			src/actions/buttons/all_buttons/pipette.c				\
			src/actions/buttons/other/area.c						\
			src/actions/buttons/other/ctrl_z.c						\
			src/actions/buttons/other/draw.c						\
			src/actions/buttons/other/mouse.c						\
			src/actions/buttons/other/tools.c						\
			src/actions/buttons/init_buttons.c						\
			src/actions/menus/all_drop_down/about_action.c			\
			src/actions/menus/all_drop_down/new_file.c				\
			src/actions/menus/all_drop_down/open_file.c				\
			src/actions/menus/all_drop_down/redo_action.c			\
			src/actions/menus/all_drop_down/save_file.c				\
			src/actions/menus/all_drop_down/undo_action.c			\
			src/actions/menus/all_drop_down/help_action.c			\
			src/actions/menus/drop_down.c							\
			src/actions/menus/init_menus.c							\
			src/actions/draw_all.c									\
			src/events/menus_states/actions_drop_down.c				\
			src/events/menus_states/menus_effects.c					\
			src/events/menus_states/mouse_handling.c				\
			src/events/buttons_states/buttons_effects.c				\
			src/events/buttons_states/buttons_handling.c			\
			src/events/buttons_states/actions_buttons.c				\
			src/events/init_events.c								\
			src/page/init_page.c									\
			src/main.c												\


OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3

LIB		=	-L./lib -lmy

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CPPFLAGS=	-I./include

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

clean:
		make clean -C lib/
		$(RM) *~
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C lib/
		$(RM) $(NAME)

re:			fclean all

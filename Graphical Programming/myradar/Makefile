##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Second graphical Project
##

NAME 		= 	my_radar

SRC			=   src/usage.c 									\
				src/simulation.c 								\
				src/main.c 										\
				src/draw/draw_plane.c 							\
				src/draw/draw_towers.c 							\
				src/draw/draw_background.c 						\
				src/draw/draw_timer.c 							\
				src/draw/disp_fps.c 							\
				src/events/poll_events.c 						\
				src/utilities/geometry.c 						\
				src/utilities/positions_checking.c 				\
				src/utilities/get_box_corners.c 				\
				src/collisions/box_collisions.c 				\
				src/collisions/plane_collisions.c 				\
				src/structures/tower.c 							\
				src/structures/window.c 						\
				src/structures/path.c 							\
				src/structures/plane/plane_create.c 			\
				src/structures/plane/plane_init.c 				\
				src/structures/plane/plane_move.c 				\
				src/structures/quadtree/quadtree.c 				\
				src/structures/quadtree/quadtree_query.c 		\
				src/structures/sim/sim.c 						\
				src/structures/sim/sim_textures.c 				\
				src/structures/sim/sim_states.c 				\
				src/file_manipulation/get_file_buffer.c 		\
				src/file_manipulation/get_entities_from_file.c 	\

OBJ			=	$(SRC:.c=.o)

INC			= 	-I./include/ -I./include/structures/	\
				-I./include/structures/simulation/		\

LDFLAGS 	=	-L./lib -lmy -lcsfml-graphics -lcsfml-system -lm

CFLAGS		= 	-Wall -Wextra -Werror $(INC) $(LDFLAGS)

all: $(NAME)

$(NAME):	makelib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -g3

makelib:
	make -C ./lib/my/ all

clean:
	$(RM) *~
	$(RM) $(OBJ)
	make -C ./lib/my/ clean

fclean:	clean
	$(RM) $(NAME)
	make -C ./lib/my/ fclean

re:	fclean all

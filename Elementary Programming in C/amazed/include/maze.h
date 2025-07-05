/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** maze
*/

#pragma once
#include "lib.h"
///////////////////////// STRUCTURES ///////////////////////////
typedef struct index_s {
    char *data;
    char **check_type;
    bool is_pipe;
    bool is_room;
    bool is_start;
    bool is_end;
    struct index_s *next;
} index_t;

typedef struct name_s {
    int name;
    struct name_s *next;
} name_t;

typedef struct robot_s {
    int id;
    int position;
    int next_position;
    int *path;
    bool is_arrived;
} robot_t;

typedef struct maze_s {
    char *file;
    char **tab;
    int **matrix;
    int nb_rooms;
    int nb_pipes;
    int nb_robots;
    int nb_start;
    int nb_end;
    int start;
    int end;
    int parse_stop;
    int wait;
    bool is_tunnel_passed;
    index_t *rooms;
    name_t *names;
} maze_t;

typedef struct dfs_params_s {
    int dest;
    bool *visited;
    int *path;
    int path_index;
    int **all_paths;
    int all_paths_index;
} dfs_params_t;

typedef struct data_robots_s {
    int *path;
    int id_in_path;
    int id_room;
    int last_id_room;
} data_robots_t;
///////////////////////// PROTOTYPES ///////////////////////////
void file_in_list(maze_t *maze);
int parsing(maze_t *maze);
void init_struct(maze_t *maze);
int **create_matrix(maze_t *maze);
void adjusting_values(maze_t *maze, index_t *current);
void print_needed(maze_t *maze);
void print_needed2(maze_t *maze);
void init_robots(maze_t *maze);
void dijkstra(maze_t *maze, int start, int dest);
void dfs(int pos, dfs_params_t *params, maze_t *maze);
dfs_params_t *find_all_paths(maze_t *maze, int pos, int dest);
int check_if_nb(maze_t *maze);

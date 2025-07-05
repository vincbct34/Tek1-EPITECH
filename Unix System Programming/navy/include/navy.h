/*
** EPITECH PROJECT, 2024
** Navy
** File description:
** navy.h
*/

#pragma once
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

extern struct request *req;

int check(int ac, char **as);
void usage_disp(void);
void end_game(void);
void process(void);
int process_game(void);
void process_client(void);
void process_server(void);
void process_attack(char *line);
struct request *get_request(int ac, char **as);
char *get_co(int index);
int *get_bin(int nbr);
int get_val(int *bin);
void fill_grids(void);
void fill_enemy_grid(void);
void fill_my_grid(void);
int check_grid_file(void);
int check_grid_line(char *content, int i);
void hand_start_connect(int data);
void hand_game_finished(int data);
void hand_turn_finished(int data);
void wait_enemy(void);
int attack_enemy(void);
void packet_div(int type, int data);
void hand_attack(int data);
void hand_attack_success(int data);
void hand_attack_fail(int data);
char *read_file(void);
void place_boat(int boat_size,
    char *begin_point_boat, char *end_point_boat);
int check_win(void);
int boat_left(void);
int contain_boat(int size, int *boats, int len);
void disp_positions(void);
void disp_my_positions(void);
void disp_enemy_positions(void);
void display(int *cells);
void my_putchar(char c);
void my_putstr(const char *str);
int my_putnbr(int nb);
char *read_line(void);
int my_getchar(void);
char *re_alloc(char *src, int pos);
void send_request(int type, int data);
int send_signal(int signal);
void prepare_signal(int id);
void receive_signal(int sig);
int get_bin_val(int sig);

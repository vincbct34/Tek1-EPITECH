/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** handler.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

void hand_start_connect(int data)
{
    req->enemy_pid = data;
    usleep(3000);
}

void hand_game_finished(int data)
{
    if (data == -1)
        return;
    req->running = 0;
    req->callback = 0;
    usleep(3000);
}

void hand_turn_finished(int data)
{
    req->enemy_len = data;
    req->turn = 1;
    usleep(3000);
}

void wait_enemy(void)
{
    my_putstr("waiting for enemy's attack...\n\n");
    req->turn = 0;
    while (req->turn != 1 && req->running == 1);
    usleep(100);
    req->tour = 1;
    if (req->state == 1)
        disp_positions();
    usleep(3000);
}

int attack_enemy(void)
{
    my_putstr("attack: ");
    req->line = read_line();
    if (req->line == NULL) {
        req->callback = 0;
        return (-2);
    }
    if (my_strlen(req->line) != 2 ||
    !(req->line[0] >= 'A' && req->line[0] <= 'H') ||
    !(req->line[1] >= '1' && req->line[1] <= '8')) {
        my_putstr("\nwrong position\n\n");
        return (-1);
    }
    my_putchar('\n');
    process_attack(req->line);
    if (req->state == 0)
        disp_positions();
    req->tour = 0;
    return (0);
}

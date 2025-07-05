/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_engine.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

void process(void)
{
    if (open(req->file_name, O_RDONLY) <= 0) {
        my_putstr("Can not open this file.\n");
        req->callback = 84;
        return;
    }
    my_putstr("my_pid: ");
    my_putnbr(req->player_pid);
    my_putstr("\n\n");
    prepare_signal(SIGUSR1);
    prepare_signal(SIGUSR2);
    fill_grids();
    disp_positions();
    end_game();
}

static int hand_attack_result(int result)
{
    if (result == -2)
        return -1;
    if (result == -1)
        return 1;
    return 0;
}

static int player_turn(void)
{
    int result = attack_enemy();

    return hand_attack_result(result);
}

static int decide_action(void)
{
    if (req->tour == 1)
        return player_turn();
    else {
        wait_enemy();
        return 0;
    }
}

int process_game(void)
{
    int action_result;

    while (req->running == 1 && check_win() == 0) {
        action_result = decide_action();
        if (action_result == -1)
            return -1;
        if (action_result == 1)
            continue;
    }
    return 0;
}

void process_client(void)
{
    my_putstr("successfully connected to enemy\n\n");
    send_request(0, req->player_pid);
}

void process_server(void)
{
    my_putstr("waiting for enemy...\n\n");
    while (req->enemy_pid == 0);
    usleep(100);
    my_putstr("enemy connected\n\n");
}

void process_attack(char *line)
{
    char nbr = line[1] - '0';
    int letter = (line[0] - 65);
    int index = -1;

    for (int i = letter; i < 64; i += 8) {
        if ((i - letter) / 8 >= nbr - 1 &&
            (i - letter) / 8 <= nbr - 1) {
            index = i;
        }
    }
    send_request(5, index);
    while (req->tour != 0);
    usleep(100);
}

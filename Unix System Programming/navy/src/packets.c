/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** packets.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

void packet_div(int type, int data)
{
    switch (type) {
        case 0:
            hand_start_connect(data);
            break;
        case 1:
            hand_game_finished(data);
            break;
        case 2:
            hand_turn_finished(data);
            break;
        case 3:
            hand_attack_success(data);
            break;
        case 4:
            hand_attack_fail(data);
            break;
        case 5:
            hand_attack(data);
            break;
    }
}

void hand_attack(int data)
{
    if (data < 0 || data > 64)
        return;
    my_putstr("result: ");
    my_putstr(get_co(data));
    if (req->my_grid[data] >= 2) {
        req->my_grid[data] = 0;
        send_request(3, data);
        my_putstr(":hit\n\n");
    } else {
        if (req->my_grid[data] != 0)
            req->my_grid[data] = 1;
        send_request(4, data);
        my_putstr(":missed\n\n");
    }
    if (boat_left() == 0) {
        req->callback = 1;
        req->running = 0;
    }
    req->tour = 1;
    usleep(3000);
}

void hand_attack_success(int data)
{
    if (data < 0 || data > 64)
        return;
    req->enemy_grid[data] = 0;
    my_putstr("result: ");
    my_putstr(get_co(data));
    my_putstr(":hit\n\n");
    usleep(10000);
    send_request(2, boat_left());
    if (req->enemy_len == 1) {
        req->callback = 0;
        req->running = 0;
    }
    req->tour = 0;
    usleep(3000);
}

void hand_attack_fail(int data)
{
    if (data < 0 || data > 64)
        return;
    if (req->enemy_grid[data] != 0)
        req->enemy_grid[data] = 1;
    my_putstr(get_co(data));
    my_putstr(":missed\n\n");
    usleep(8000);
    send_request(2, boat_left());
    req->tour = 0;
    usleep(3000);
}

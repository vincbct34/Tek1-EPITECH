/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_signal.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

void send_request(int type, int data)
{
    int *type_bin = get_bin(type);
    int *type_data = get_bin(data);

    usleep(7000);
    for (int j = 0; j < 16; j++) {
        if (type_bin[j] == 0)
            send_signal(SIGUSR1);
        if (type_bin[j] == 1)
            send_signal(SIGUSR2);
    }
    usleep(7000);
    for (int j = 0; j < 16; j++) {
        if (type_data[j] == 0)
            send_signal(SIGUSR1);
        if (type_data[j] == 1)
            send_signal(SIGUSR2);
    }
}

int send_signal(int signal)
{
    if (kill(req->enemy_pid, signal) == -1) {
        req->callback = 84;
        return (0);
    }
    usleep(10000);
    return (1);
}

void prepare_signal(int id)
{
    struct sigaction action;

    action.sa_flags = SA_SIGINFO;
    action.sa_handler = receive_signal;
    sigemptyset(&action.sa_mask);
    if (sigaction(id, &action, NULL) == -1)
        return;
}

void receive_signal(int sig)
{
    static int *msg_type = NULL;
    static int *msg_data = NULL;
    static int pos = 0;

    if (msg_type == NULL || msg_data == NULL) {
        msg_type = malloc(sizeof(int) * 16);
        msg_data = malloc(sizeof(int) * 16);
    }
    if (pos < 16)
        msg_type[pos] = get_bin_val(sig);
    else
        msg_data[pos - 16] = get_bin_val(sig);
    pos++;
    if (pos == 32)
        packet_div(get_val(msg_type), get_val(msg_data));
    if (pos >= 32) {
        msg_type = NULL;
        msg_data = NULL;
        pos = 0;
    }
}

int get_bin_val(int sig)
{
    if (sig == SIGUSR1)
    return (0);
    else if (sig == SIGUSR2)
        return (1);
    return (-1);
}

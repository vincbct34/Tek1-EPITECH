/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <time.h>
#include "my_radar.h"
#include "usage.h"
#include "events.h"
#include "sim.h"
#include "my.h"

int main(int ac, char **av)
{
    win_t *window = NULL;
    int exit_code = 0;

    exit_code = check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (exit_code);
    srand(time(NULL));
    window = create_win(W_WIDTH, W_HEIGHT, W_TITLE);
    if (window == NULL) {
        my_puterr("my_radar: Couldn't create window\n");
        return (MY_EXIT_FAILURE);
    }
    exit_code = start_simulation(window, av[1]);
    return (MY_EXIT_SUCCESS);
}

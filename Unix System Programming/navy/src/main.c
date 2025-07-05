/*
** EPITECH PROJECT, 2024
** Navy
** File description:
** main.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

struct request *req;

int main(int ac, char **av)
{
    int error;

    if (ac != 2 && ac != 3)
        return (84);
    error = check(ac, av);
    if (error != 42)
        return (error);
    req = get_request(ac, av);
    if (req == NULL)
        return (84);
    if (ac == 3 && kill(req->enemy_pid, 0) == -1) {
        my_putstr("Invalid pid.\n");
        return (84);
    }
    if (check_grid_file() == 0) {
        my_putstr("Bad map encodage.\n");
        return (84);
    }
    process();
    return (req->callback);
}

int check(int ac, char **av)
{
    if (ac == 2) {
        if ((my_strlen(av[1]) == 1 && av[1][0] == 'h') ||
            (my_strlen(av[1]) == 2 && av[1][1] == 'h')) {
            usage_disp();
            return (0);
        }
    } else if (my_str_isnum(av[1]) == 0)
        return (84);
    if (ac == 3 && my_getnbr(av[1]) <= 0)
        return (84);
    return (42);
}

void usage_disp(void)
{
    const char *usage = "USAGE\n           "
        "./navy [first_player_pid] navy_positions\n\n";
    const char *description = "DESCRIPTION\n";
    const char *description_content = "           first_player_pid   "
        "only for the 2nd player.  pid of the first player.\n"
        "           navy_positions     file representing "
        "the positions of the ships.\n";

    my_putstr(usage);
    my_putstr(description);
    my_putstr(description_content);
}

void end_game(void)
{
    req->running = 1;
    if (process_game() == -1)
        req->callback = 0;
    else {
        if (req->callback == 0)
            my_putstr("I won\n");
        if (req->callback == 1)
            my_putstr("Enemy won\n");
    }
}

/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include "corewar.h"

int print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_putstr("[-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after the ");
    my_putstr("nbr_cycle execution (if the round isn’t\n");
    my_putstr("already over) with the following format: 32 ");
    my_putstr("bytes/line in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program’s number. ");
    my_putstr("By default, the first free number in the\n");
    my_putstr("parameter order\n");
    my_putstr("-a load_address sets the next program’s loading ");
    my_putstr("address. When no address is specified,\n");
    my_putstr("optimize the addresses so that the processes ");
    my_putstr("are as far away from each other as\n");
    my_putstr("possible. The addresses are MEM_SIZE modulo\n");
    return 0;
}

void display_array_in_ncurses(void)
{
    int **arr = malloc(MEM_SIZE * sizeof(int *));
    int max_y = 0;
    int max_x = 0;

    for (int i = 0; i < MEM_SIZE; ++i)
        arr[i] = calloc(MEM_SIZE, sizeof(int));
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    getmaxyx(stdscr, max_y, max_x);
    for (int i = 0; i < max_y - 1 && i < MEM_SIZE; ++i)
        for (int j = 0; j < (max_x / 2) && j < MEM_SIZE; ++j)
            mvprintw(i, j * 2, "%d ", arr[i][j]);
    refresh();
    getch();
    endwin();
    for (int i = 0; i < MEM_SIZE; ++i)
        free(arr[i]);
    free(arr);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_usage());
    display_array_in_ncurses();
    return (0);
}

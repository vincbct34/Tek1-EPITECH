/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** file_handling.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

static int is_game_won_bis(sokoban_struct *sokoban, int i, int j, int count)
{
    if (sokoban->map[i][j] == 'O')
        count++;
    return count;
}

static int is_game_won(sokoban_struct *sokoban)
{
    int count = 0;

    for (int i = 0; sokoban->map[i] != NULL; i++)
        for (int j = 0; sokoban->map[i][j] != '\0'; j++)
            count = is_game_won_bis(sokoban, i, j, count);
    if (count == 0)
        return 1;
    return 0;
}

static int is_game_lost_bis(sokoban_struct *sokoban, int i, int j, int count)
{
    if (sokoban->map[i][j] == 'X' && ((sokoban->map[i + 1][j] == '#'
        && sokoban->map[i][j + 1] == '#')
        || (sokoban->map[i - 1][j] == '#' && sokoban->map[i][j - 1] == '#')
        || (sokoban->map[i + 1][j] == '#' && sokoban->map[i][j - 1] == '#')
        || (sokoban->map[i - 1][j] == '#' && sokoban->map[i][j + 1] == '#')))
        count++;
    return count;
}

static int is_game_lost(sokoban_struct *sokoban)
{
    int count = 0;

    for (int i = 0; sokoban->map[i] != NULL; i++)
        for (int j = 0; sokoban->map[i][j] != '\0'; j++)
            count = is_game_lost_bis(sokoban, i, j, count);
    if (count == sokoban->object->nb_x)
        return 1;
    return 0;
}

static int analyse_events(sokoban_struct *sokoban)
{
    int ch = getch();

    if (ch == 27)
        return 1;
    if (ch == KEY_UP)
        move_up(sokoban);
    if (ch == KEY_DOWN)
        move_down(sokoban);
    if (ch == KEY_LEFT)
        move_left(sokoban);
    if (ch == KEY_RIGHT)
        move_right(sokoban);
    return 0;
}

static void game_loop(sokoban_struct *sokoban)
{
    while (1) {
        if (analyse_events(sokoban) == 1)
            break;
        if (is_game_lost(sokoban) == 1) {
            endwin();
            free_all(sokoban);
            exit(1);
        }
        if (is_game_won(sokoban) == 1) {
            endwin();
            free_all(sokoban);
            exit(0);
        }
    }
}

int my_sokoban(char *filepath, sokoban_struct *sokoban)
{
    sokoban->object = NULL;
    sokoban->storage = NULL;
    sokoban->player = malloc(sizeof(player));
    fill_map(sokoban, load_file_in_mem(filepath));
    get_pos(sokoban);
    if (error_handling(sokoban) == 84)
        return 84;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    display_map(sokoban);
    game_loop(sokoban);
    endwin();
    return 0;
}

static void replace_storage(sokoban_struct *sokoban)
{
    storage *temp = sokoban->storage;

    while (temp != NULL) {
        if (sokoban->map[temp->storage_x][temp->storage_y] != 'X'
            && sokoban->map[temp->storage_x][temp->storage_y] != 'P')
            sokoban->map[temp->storage_x][temp->storage_y] = 'O';
        temp = temp->next;
    }
}

int display_map(sokoban_struct *sokoban)
{
    refresh();
    clear();
    replace_storage(sokoban);
    for (int i = 0; sokoban->map[i] != NULL; i++)
        printw("%s\n", sokoban->map[i]);
    return 0;
}

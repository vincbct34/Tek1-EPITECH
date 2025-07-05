/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

static void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, containing");
    my_putstr(" '#' for walls,\n");
    my_putstr("         'P' for the player, 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
}

static int is_file_valid(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat st;

    if (fd == -1)
        return 84;
    stat(file, &st);
    if (st.st_size == 0)
        return 84;
    close(fd);
    return 0;
}

int main(int ac, char **av)
{
    sokoban_struct *sokoban = malloc(sizeof(sokoban_struct));

    if (ac != 2)
        return (84);
    if (is_file_valid(av[1]) == 84) {
        free_all_before_fill(sokoban);
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_usage();
        free_all(sokoban);
        return (0);
    } else {
        if (my_sokoban(av[1], sokoban) == 84) {
            free_all(sokoban);
            return (84);
        }
    }
    free_all(sokoban);
    return (0);
}

void free_object(object *head)
{
    object *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void free_storage(storage *head)
{
    storage *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void free_all(sokoban_struct *sokoban)
{
    free(sokoban->player);
    free(sokoban->object);
    free(sokoban->storage);
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        free(sokoban->map[i]);
    }
    free(sokoban->map);
    free(sokoban);
}

void free_all_before_fill(sokoban_struct *sokoban)
{
    free(sokoban->player);
    free(sokoban->object);
    free(sokoban->storage);
    free(sokoban->map);
    free(sokoban);
}

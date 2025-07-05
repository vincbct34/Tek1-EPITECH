/*
** EPITECH PROJECT, 2024
** Duo Stumper 4
** File description:
** main.c
*/

#include "my.h"
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *get_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == - 1) {
        free(line);
        return NULL;
    }
    return line;
}

int check_commands(char *input)
{
    ingredients_t *ingredients = malloc(sizeof(ingredients_t));

    init_struct(ingredients);
    if (strncmp(input, "exit\n", 5) == 0) {
        free(ingredients);
        return 1;
    }
    if (strncmp(input, "disp fridge\n", 12) == 0)
        if (disp_fridge(ingredients) == 0)
            return 0;
    if (printf("'%s': Invalid operation\n", input) < 0)
        return 84;
    return 2;
}

int main(int ac, char **)
{
    int return_value = 0;
    char *input = NULL;

    if (ac != 1)
        return 84;
    while (1) {
        input = get_input();
        if (input == NULL)
            return 84;
        else
            return_value = check_commands(input);
        free(input);
        if (return_value == 1)
            return 0;
        if (return_value == 0)
            continue;
        if (return_value == 84)
            return 84;
    }
    return 0;
}

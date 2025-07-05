/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** open_file.c
*/

#include "paint.h"

static void open_action(Paint *paint, char *filepath)
{
    sfImage_destroy(AREA->image);
    AREA->image = sfImage_createFromFile(filepath);
}

void listen_for_input_open(Paint *paint)
{
    char *filepath = NULL;
    size_t len = 0;
    ssize_t read;

    my_putstr("Enter the path to an image file: ");
    read = getline(&filepath, &len, stdin);
    while (read != -1) {
        if (read > 0 && filepath[read - 1] == '\n')
            filepath[read - 1] = '\0';
        open_action(paint, filepath);
        break;
    }
    free(filepath);
}

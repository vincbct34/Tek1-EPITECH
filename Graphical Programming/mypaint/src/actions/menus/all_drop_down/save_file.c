/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** save_file.c
*/

#include "paint.h"

void listen_for_input_save(Paint *paint)
{
    char *filepath = NULL;
    size_t len = 0;
    ssize_t read;

    my_putstr("Enter the path to save the image: ");
    read = getline(&filepath, &len, stdin);
    while (read != -1) {
        if (read > 0 && filepath[read - 1] == '\n')
            filepath[read - 1] = '\0';
        sfImage_saveToFile(AREA->image, filepath);
        new_action(paint);
        break;
    }
    free(filepath);
}

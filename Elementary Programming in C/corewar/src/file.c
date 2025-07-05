/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** file.c
*/

#include "corewar.h"

static int size_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    char content;

    while (read(fd, &content, 1))
        size++;
    close(fd);
    return size;
}

int check_file(char *filepath, corewar_t *corewar, args_t *data)
{
    char *content;

    if (file_verification(filepath, &content) == 84)
        return 84;
    robot_parser(data->nb_robots, data->address, content, corewar);
    return 0;
}

int file_verification(char *filepath, char **content)
{
    int fd = open(filepath, O_RDONLY);
    int size = size_file(filepath);
    char *buffer;

    if (fd == -1)
        return 84;
    buffer = malloc(sizeof(char) * size + 1);
    read(fd, buffer, size);
    buffer[size] = '\0';
    *content = buffer;
    close(fd);
    return 0;
}

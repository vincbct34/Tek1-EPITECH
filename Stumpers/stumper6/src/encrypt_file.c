/*
** EPITECH PROJECT, 2024
** César
** File description:
** encrypt_file.c
*/

#include "my.h"

int encrypt_file(char *str, int key)
{
    char *buffer;
    size_t size;
    int fd = open(str, O_RDONLY);

    if (fd == -1)
        return 84;
    buffer = read(fd, buffer, size);
    close(fd);
    return 0;
}

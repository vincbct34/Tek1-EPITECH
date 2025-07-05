/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "file_manipulation.h"
#include "my.h"

char *file_buff(char const *filepath)
{
    int fd = 0;
    unsigned int file_size = size_file(filepath);
    char *buffer = malloc(sizeof(char) * (file_size + 1));

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_puterr(OPEN_FAILURE_MSG);
        return (NULL);
    }
    if (read(fd, buffer, file_size) == -1) {
        my_puterr(READ_FAILURE_MSG);
        return (NULL);
    }
    buffer[file_size] = '\0';
    close(fd);
    return (buffer);
}

unsigned int size_file(char const *filepath)
{
    struct stat stats;

    if (stat(filepath, &stats) != 0)
        return (-1);
    return (stats.st_size);
}

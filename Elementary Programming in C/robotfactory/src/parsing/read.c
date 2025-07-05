/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** read.c
*/

#include "robot.h"

char *read_file(char *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    char *buffer = NULL;

    stat(filepath, &st);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (buffer == NULL)
        return (NULL);
    size = read(fd, buffer, st.st_size);
    if (size == -1) {
        free(buffer);
        close(fd);
        return (NULL);
    }
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

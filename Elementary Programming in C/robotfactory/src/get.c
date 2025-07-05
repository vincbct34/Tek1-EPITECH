/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** main.c
*/

#include "robot.h"

int my_getlen_filename(char *file_name)
{
    int len = 0;
    int i = 0;

    for (; file_name[i] != '\0'; i++) {
        if (file_name[i] == '/')
            len = 0;
        else
            len++;
        if (file_name[i] == '.')
            return len - 1;
    }
    return 0;
}

char *my_get_file_name(char *file)
{
    int len = my_getlen_filename(file);
    int i = my_strlen(file) - 1;
    int j;
    char *filename = malloc(sizeof(char) * (len + 1));

    for (; i >= 0; i--)
        if (file[i] == '.')
            break;
    for (j = i - 1; j >= 0; j--)
        if (file[j] == '/')
            break;
    my_strncpy(filename, file + j + 1, len);
    filename[len] = '\0';
    return filename;
}

/*
** EPITECH PROJECT, 2023
** get_dimensions.c
** File description:
** Get the dimensions of the map
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int my_getcolons(char *buffer, int k)
{
    int i = 0;

    for (; buffer[k + i] && buffer[k + i] != '\n'; i++);
    return i;
}

/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** my_strarraylen
*/

#include "lib.h"

int my_strarraylen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

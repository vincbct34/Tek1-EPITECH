/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strlen.c
*/

#include "robot.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

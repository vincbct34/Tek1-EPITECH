/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** my_str_isalpha.c
*/

#include "robot.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
        i++;
    }
    return (1);
}

/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** my_putstr.c
*/

#include "robot.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

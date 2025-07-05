/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** my_puterror.c
*/

#include <unistd.h>
#include "my.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}

/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** Library
*/

#include "my.h"
#include <stdio.h>

char *my_strcapitalize(char *str)
{
    int i = 1;

    my_strlowcase(str);
    while (str[i] != '\0') {
        if ((str[i - 1] < '0' || str[i - 1] > '9') &&
            (str[i - 1] < 'A' || str[i - 1] > 'Z') &&
            (str[i - 1] < 'a' || str[i - 1] > 'z') &&
            (str[i] <= 'z' && str[i] >= 'a'))
            str[i] = str[i] - 32;
        if (str[0] < 'z' && str[0] > 'a')
            str[0] = str[0] - 32;
        i++;
    }
    return (str);
}

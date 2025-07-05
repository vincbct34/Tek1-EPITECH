/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalizes the first letter of each word
*/

#include "include/my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = my_strlowcase(str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        if (((str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z')) &&
            (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
            str[i + 1] -= 32;
    }
    return (str);
}

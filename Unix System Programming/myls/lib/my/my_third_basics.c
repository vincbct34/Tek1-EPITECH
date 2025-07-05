/*
** EPITECH PROJECT, 2023
** my_third_basics
** File description:
** All the basics of LibC
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
    return (s1[i] - s2[i]);
}

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 90 && str[i] >= 65)
            str[i] += 32;
    }
    return str;
}

char *my_strrchr(const char *str, int character)
{
    const char *last_occurrence = NULL;

    while (*str != '\0') {
        if (*str == character) {
            last_occurrence = str;
        }
        str++;
    }
    if (character == '\0')
        return (char *)str;
    return (char *)last_occurrence;
}

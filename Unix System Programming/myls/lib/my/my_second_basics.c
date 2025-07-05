/*
** EPITECH PROJECT, 2023
** my_second_basics
** File description:
** All the basics of LibC
*/

#include "my.h"
#include <unistd.h>

int my_intlen(long long n)
{
    int count = 0;

    if (n == 0)
        return 1;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return 0;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return 0;
}

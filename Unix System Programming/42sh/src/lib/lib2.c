/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** lib.c
*/

#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return s1[i] - s2[i];
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n; i++);
    if (i == n)
        return 0;
    return s1[i] - s2[i];
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat2(char *dest, char *src)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(dest) +
        my_strlen(src) + 1));
    int i = 0;
    int j = 0;

    if (new_str == NULL)
        return NULL;
    while (dest[i]) {
        new_str[i] = dest[i];
        i++;
    }
    while (src[j]) {
        new_str[i] = src[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return new_str;
}

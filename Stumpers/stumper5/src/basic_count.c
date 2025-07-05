/*
** EPITECH PROJECT, 2024
** basic count
** File description:
** duo
*/

#include "my.h"

int count(char c, char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    return count;
}

int is_passed(char c, char *str, int index)
{
    for (int i = 0; i != index; i++)
        if (c == str[i])
            return 1;
    return 0;
}

int basic_count(char *str)
{
    int count_passed = 0;
    char *passed = malloc(sizeof(char) * strlen(str));

    for (int i = 0; str[i] != '\0'; i++)
        if (!is_passed(str[i], passed, i)) {
            printf("%c:%d\n", str[i], count(str[i], str));
            passed[count_passed] = str[i];
            count_passed++;
        }
    free(passed);
    return 0;
}

int search_count(char *str, char *search)
{
    int count_passed = 0;
    int counter = 0;
    char *passed = malloc(sizeof(char *) * strlen(search));

    for (int y = 0; search[y] != '\0'; y++) {
        if (!is_passed(search[y], passed, y)) {
            printf("%c:%d\n", search[y], count(search[y], str));
            passed[count_passed] = search[y];
            count_passed++;
        }
        counter++;
    }
    free(passed);
    return 0;
}

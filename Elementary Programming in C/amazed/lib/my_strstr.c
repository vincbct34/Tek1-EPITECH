/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strstr.c
*/

#include "maze.h"

int my_strstr_2(char *str, int i, char const *to_find, int len_tofind)
{
    int y;

    for (y = 0; y < len_tofind; y++) {
        if (str[i + y] != to_find[y]) {
            break;
        }
    }
    return y;
}

int my_strstr(char *str, char *to_find)
{
    int len_str = my_strlen(str);
    int len_tofind = my_strlen(to_find);
    int y;
    int i;

    for (i = 0; i <= (len_str - len_tofind); i++) {
        y = my_strstr_2(str, i, to_find, len_tofind);
        if (y == len_tofind) {
            return 0;
        }
    }
    return 84;
}

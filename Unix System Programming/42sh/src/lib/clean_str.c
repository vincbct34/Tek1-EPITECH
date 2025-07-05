/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** clean_str
*/

#include "../../include/my.h"

void clean_str2(bool *space_encountered, char *str, int *j)
{
    if (!*space_encountered) {
        str[*j] = ' ';
        *j += 1;
        *space_encountered = true;
    }
}

void clean_str(char *str, int i)
{
    int j = 0;
    bool space_encountered = false;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t') {
            clean_str2(&space_encountered, str, &j);
        } else {
            space_encountered = false;
            str[j] = str[i];
            j++;
        }
        i++;
    }
    if (j > 0 && str[j - 1] == ' ')
        j--;
    str[j] = '\0';
}

int is_empty_or_space(const char *str)
{
    if (str == NULL) {
        return 1;
    }
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

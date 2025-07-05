/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** clean_str
*/

#include "lib.h"

static void clean_str_bis(bool *space_encountered, char *str, int *j)
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
            clean_str_bis(&space_encountered, str, &j);
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

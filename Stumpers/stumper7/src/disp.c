/*
** EPITECH PROJECT, 2024
** crocus
** File description:
** display
*/

#include "crocus.h"

int display_string(char *str, char c)
{
    char *dup = malloc(sizeof(char) * (strlen(str) + 1));
    int len = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            dup[i] = c;
            continue;
        }
        dup[i] = str[i];
    }
    dup[i] = '\0';
    len = printf("%s", dup);
    free(dup);
    return len;
}

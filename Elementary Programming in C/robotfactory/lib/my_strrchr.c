/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strrchr.c
*/

#include "robot.h"

char *my_strrchr(const char *str, char character)
{
    int i = my_strlen((char *)str);

    while (i >= 0) {
        if (str[i] == character) {
            return (char *)&str[i];
        }
        i--;
    }
    return NULL;
}

/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** my_strdup
*/

#include "lib.h"

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}

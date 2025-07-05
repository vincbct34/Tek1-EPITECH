/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** my_puterror
*/

#include "lib.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}

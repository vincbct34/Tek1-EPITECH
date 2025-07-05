/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** return_error.c
*/

#include "crocus.h"

int return_error(int error)
{
    if (fprintf(stderr, "%s%d%s\n", "Argument", error, "is not a flag.") <= 0)
        return 1;
    return 1;
}

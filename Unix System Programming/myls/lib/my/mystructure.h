/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The structures needeed for the my_printf function
*/

#include "my.h"
#pragma once

struct type_flags{
    char *c;
    int (*ptr)(char const *format, int i, int *count, va_list list);
};

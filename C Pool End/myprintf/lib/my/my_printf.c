/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** ..
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "myprintf.h"
#include "mystructure.h"

struct type_flags array[] = {
    {"d", percent_d},
    {"i", percent_i},
    {"s", percent_s},
    {"c", percent_c},
    {"o", percent_o},
    {"x", percent_x},
    {"X", percent_uppercase_x},
    {"u", percent_u},
    {"f", percent_f},
    {"F", percent_f},
    {"e", percent_e},
    {"E", percent_uppercase_e},
    {"ld", long_percent_d},
    {"li", long_percent_i},
    {"#x", format_percent_x},
    {"#o", format_percent_o},
    {"#X", format_percent_uppercase_x},
    {"#d", format_percent_d},
    {"+d", format_percent_d2},
    {" d", format_percent_d3},
    {"-d", percent_d},
    {"p", percent_p},
    {"%", simple_percent},
    {0, NULL}
};

int my_printf(char const *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
            i += 1;
            count += parcours_array((char *)(format), &i, &count, list);
        } else {
            my_putchar(format[i]);
            count += 1;
        }
    }
    va_end(list);
    return (count + 1);
}

int parcours_array(char const *format, int *i, int *count, va_list list)
{
    for (int j = 0; array[j].c != 0; j++) {
        if (strncmp(array[j].c, format + *i, my_strlen(array[j].c)) == 0) {
            array[j].ptr(format, *i, count, list);
            parcours_array2(&j, i);
            break;
        }
    }
    return 0;
}

int parcours_array2(int *j, int *i)
{
    if (my_strlen(array[*j].c) > 1)
        (*i) += my_strlen(array[*j].c) - 1;
    return 0;
}
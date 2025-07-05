/*
** EPITECH PROJECT, 2023
** my_advanced_functions
** File description:
** All the necessary of my_printf
*/

#include "myprintf.h"

int format_percent_d3(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar(' ');
        my_putchar('0');
        *count += 1;
    }
    if (arg != 0) {
        if (arg > 0) {
            my_putchar(' ');
            *count += my_put_nbr(arg);
        } else
            *count += my_put_nbr(arg);
    }
    return 0;
}

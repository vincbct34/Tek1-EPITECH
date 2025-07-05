/*
** EPITECH PROJECT, 2023
** my_first_flags
** File description:
** All the flags of my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "myprintf.h"

int percent_d(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, int);

    (void)format;
    (void)i;
    if (arg == 0 || arg == -0) {
        my_putchar('0');
        *count += 1;
    } else{
    *count += my_put_nbr(arg);
    }
    return 0;
}

int percent_i(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, int);

    (void)format;
    (void)i;
    if (arg == 0 || arg == -0) {
        my_putchar('0');
        *count += 1;
    } else{
    *count += my_put_nbr(arg);
    }
    return 0;
}

int percent_s(char const *format, int i, int *count, va_list list)
{
    char *arg = va_arg(list, char *);

    (void)format;
    (void)i;
    if (my_strlen(arg) == 0) {
        my_putstr("");
    }
    *count += my_putstr(arg);
    return 0;
}

int simple_percent(char const *format, int i, int *count, va_list list)
{
    (void)list;
    (void)format;
    (void)i;
    my_putchar('%');
    *count += 1;
    return 0;
}

int percent_c(char const *format, int i, int *count, va_list list)
{
    char arg = va_arg(list, int);

    (void)format;
    (void)i;
    my_putchar(arg);
    *count += 1;
    return 0;
}

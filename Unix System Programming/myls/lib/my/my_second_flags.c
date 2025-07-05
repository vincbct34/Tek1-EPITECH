/*
** EPITECH PROJECT, 2023
** my_second_flags
** File description:
** All the flags of my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int percent_o(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar('0');
        *count += 1;
    }
    *count += my_putnbr_base(arg, "01234567");
    return 0;
}

int percent_x(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar('0');
        *count += 1;
    }
    *count += my_putnbr_base(arg, "0123456789abcdef");
    return 0;
}

int percent_uppercase_x(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar('0');
        *count += 1;
    }
    *count += my_putnbr_base(arg, "0123456789ABCDEF");
    return 0;
}

int percent_u(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    *count += my_put_nbr(arg);
    return 0;
}

int percent_f(char const *format, int i, int *count, va_list list)
{
    double arg = va_arg(list, double);

    (void)format;
    (void)i;
    *count += my_put_float(arg);
    return 0;
}

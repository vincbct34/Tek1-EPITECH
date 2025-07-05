/*
** EPITECH PROJECT, 2023
** my_advanced_functions
** File description:
** All the necessary of my_printf
*/

#include "myprintf.h"

int format_percent_o(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar('0');
        *count += 1;
    }
    if (arg != 0)
        my_putchar('0');
    *count += my_putnbr_base(arg, "01234567");
    return 0;
}

int format_percent_x(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar('0');
        *count += 1;
    }
    if (arg != 0)
        my_putstr("0x");
    *count += my_putnbr_base(arg, "0123456789abcdef");
    return 0;
}

int format_percent_uppercase_x
(char const *format, int i, int *count, va_list list)
{
    int arg = va_arg(list, unsigned int);

    (void)format;
    (void)i;
    if (arg == 0) {
        my_putchar('0');
        *count += 1;
    }
    if (arg != 0)
        my_putstr("0X");
    *count += my_putnbr_base(arg, "0123456789ABCDEF");
    return 0;
}

int format_percent_d(char const *format, int i, int *count, va_list list)
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

/*
** EPITECH PROJECT, 2023
** my_advanced_functions
** File description:
** All the necessary of my_printf
*/

#include "my.h"
#include <unistd.h>

int long_percent_d(char const *format, int i, int *count, va_list list)
{
    long int arg = va_arg(list, long int);

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

int long_percent_i(char const *format, int i, int *count, va_list list)
{
    long int arg = va_arg(list, long int);

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

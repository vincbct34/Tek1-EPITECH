/*
** EPITECH PROJECT, 2023
** my_third_flags
** File description:
** All the flags of my_printf
*/
#include <stdarg.h>
#include <stdio.h>
#include "myprintf.h"

int percent_e(char const *format, int i, int *count, va_list list)
{
    double arg = va_arg(list, double);

    (void)format;
    (void)i;
    *count += my_put_scientific_low(arg);
    return 0;
}

int percent_uppercase_e(char const *format, int i, int *count, va_list list)
{
    double arg = va_arg(list, double);

    (void)format;
    (void)i;
    *count += my_put_scientific_up(arg);
    return 0;
}

int percent_p_adresse(void *nb)
{
    unsigned long long int adresse_p = (unsigned long long int)nb;

    my_putstr("0x");
    my_putnbr_base(adresse_p, "0123456789abcdef");
    return 0;
}

int percent_p(char const *format, int i, int *count, va_list list)
{
    (void)format;
    (void)i;
    *count += percent_p_adresse(va_arg(list, void *));
    return 0;
}

int my_putnbr_base_p(unsigned long long int nbr, char const *base)
{
    unsigned long long int i = nbr;
    unsigned long long int pow = my_strlen(base);
    int count = 0;

    while (i != 0) {
        i = i / pow;
        count ++;
    }
    i = nbr;
    while (count != 0) {
        for (int j = 0; j != count - 1; j++) {
            i = i / pow;
        }
        my_putchar(base[i % pow]);
        i = nbr;
        count--;
    }
    return (0);
}
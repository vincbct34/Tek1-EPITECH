/*
** EPITECH PROJECT, 2023
** B-CPE-101-MPL-1-1-miniprintf-vincent.bichat
** File description:
** miniprintf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

static void no_lines(char const *format, va_list ap, int i)
{
    if (format[i] == '%') {
        my_putchar('%');
        return;
    }
    if (format[i] == 'd' || format[i] == 'i') {
        my_put_nbr(va_arg(ap, int));
        return;
    }
    if (format[i] == 's') {
        my_putstr(va_arg(ap, char *));
        return;
    }
    if (format[i] == 'c') {
        my_putchar((char) va_arg(ap, int));
        return;
    }
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int count;

    va_start(ap, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            no_lines(format, ap, i);
            continue;
        }
        my_putchar(format[i]);
    }
    va_end(ap);
    return 0;
}

void main(void)
{
    char str[8];
    my_strcpy(str, "Epitech");
    mini_printf("The word %%%s%% has %i characters.\n", str, my_strlen(str));
}
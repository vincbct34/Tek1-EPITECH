/*
** EPITECH PROJECT, 2023
** my_first_basics
** File description:
** All the basics of LibC
*/

#include "myprintf.h"
#include <unistd.h>
#include <stdbool.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int	my_put_nbr(long long int nb)
{
    long long int b;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            b = nb % 10;
            my_put_nbr(nb / 10);
            my_putchar(48 + b);
        } else
            my_putchar(48 + nb % 10);
    }
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}

int my_putnbr_base(long long int nbr, char const *base)
{
    long long int i = nbr;
    long long int pow = my_strlen(base);
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

static void check_minus(int min_cnt, long *number)
{
    if ( min_cnt % 2 == 1 ) {
        *number = *number * (-1);
    }
}

static bool is_digit(char to_test)
{
    if ( to_test >= '0' && to_test <= '9') {
        return true;
    }
    return false;
}

static int on_num(int num_strt, char const *str)
{
    int len = 0;
    int result = 0;
    int mult = 1;

    for (int i = num_strt ; str[i] >= 48 && str[i] < 58 ; i++) {
        len++;
    }
    if (len > 10) {
        return result;
    }
    for (int n = num_strt + len - 1 ; n >= num_strt; n--) {
        result += ( str[n] - 48 ) * mult;
        mult = mult * 10;
    }
    return result;
}

static void chck_int(long *number)
{
    if (*number > 2147483647 || *number < -2147483648) {
        *number = 0;
    }
}

int my_getnbr(char const *str)
{
    long number;
    int min_cnt = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (is_digit(str[i])) {
            number = on_num(i, str);
            check_minus(min_cnt, &number);
            chck_int(&number);
            return number;
        }
        if (str[i] == 45) {
            min_cnt++;
        }
    }
    return (int)number;
}

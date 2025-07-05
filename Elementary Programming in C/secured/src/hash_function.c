/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hash function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int str_to_int(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        nb = nb * 10;
        nb = nb + (str[i] - 48);
        i++;
    }
    return nb;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (i > j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
    return str;
}

static int count_digits(int nb)
{
    int count = 0;

    while (nb != 0) {
        nb /= 10;
        count++;
    }
    return count;
}

char *int_to_str(int nb)
{
    int i = 0;
    int length = 0;
    char *str = NULL;

    length = count_digits(nb);
    str = malloc(sizeof(char) * (length + 1));
    while (nb != 0) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}

static int recursive_power(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0)
        result = nb * recursive_power(nb, p - 1);
    return (result);
}

static int get_nth_digit(long int nb, int pos)
{
    int digit = 0;
    int fraction = 0;
    int length;

    length = count_digits(nb);
    fraction = nb / recursive_power(10, (length - pos));
    digit = fraction % 10;
    return digit;
}

int get_digits_range(long int num, int start_pos, int count)
{
    int i = 0;
    int digit = 0;
    int range = 0;

    while (i < count) {
        digit = get_nth_digit(num, start_pos);
        range = range * 10;
        range = range + digit;
        start_pos++;
        i++;
    }
    return range;
}

static long long int mid_square_random(long long int seed)
{
    long long int square = seed * seed;

    if (square % 2 == 0) {
        square /= 100;
        square %= 10000;
    } else {
        square /= 10;
        square %= 10000;
    }
    return square;
}

int hash(char *key, int len)
{
    long long int seed = str_to_int(key);

    for (int i = 0; i < len; i++)
        seed = mid_square_random(seed);
    return seed;
}

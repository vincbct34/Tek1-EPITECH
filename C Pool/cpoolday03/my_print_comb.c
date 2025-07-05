/*
** EPITECH PROJECT, 2023
** my_print_comb.c
** File description:
** task05 day 3
*/

#include <unistd.h>

void my_putchar(char c);
int my_print_comb(void);
void test_display(char x, char y, char z);

void test_display(char x, char y, char z)
{
    if (z < y && y < x) {
        my_putchar(z);
        my_putchar(y);
        my_putchar(x);
        if (z != 55 || y != 56 || x != 57) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb(void)
{
    char x = 48;
    char y = 48;
    char z = 48;

    for (int i = 0; i <= 789; i++) {
        x++;
        test_display(x, y, z);
        if (x == 57) {
            x = 47;
            y++;
            test_display(x, y, z);
        }
        if (y == 57) {
            y = 47;
            z++;
            test_display(x, y, z);
        }
    }
    return (0);
}

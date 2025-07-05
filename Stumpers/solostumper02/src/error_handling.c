/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** Solo Stumper n°2
*/

#include <unistd.h>

void print_usage(void)
{
    write(2, "Usage: ./hidenp needle haystack\n", 33);
}

int error_handling(int nb)
{
    if (nb != 3) {
        print_usage();
        return 84;
    }
    return 0;
}

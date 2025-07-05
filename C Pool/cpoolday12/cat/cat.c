/*
** EPITECH PROJECT, 2023
** cat
** File description:
** Day 12
*/

#include <unistd.h>
#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int cat_error(char *name, int er_type)
{
    my_putstr("cat: ");
    my_putstr(name);
    if (er_type == 2)
        my_putstr(": No such file or directory\n");
    if (er_type == 21)
        my_putstr(": Is a directory\n");
    return (84);
}

int read_f(int ac, char **av)
{
    int file;
    char buf[100000];

    for (int i = 1; i < ac; i++) {
        file = open(av[i], O_RDONLY);
        if (errno != 0)
            return (cat_error(av[i], errno));
        read(file, buf, 100000);
        if (errno != 0)
            return (cat_error(av[i], errno));
        my_putstr(buf);
        my_putchar('\n');
    }
    close(file);
    return (0);
}

int main(int ac, char **av)
{
    int file;
    char buf[100000];

    if (ac == 1) {
        while ((read(0, buf, 100000)) > 0)
            my_putstr(buf);
    } else
        return (read_f(ac, av));
    return (0);
}

/*
** EPITECH PROJECT, 2023
** my_ls.c
** File description:
** Projet My_ls
*/

#include "includes/my.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <linux/limits.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>

void basic_ls(int ac, char **av)
{
    const char *filename = (ac > 1) ? av[1] : ".";
    DIR *dir = opendir(filename);
    struct dirent *entry;

    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
    }
}

void manage_flags(char **av, char *path)
{
    DIR *dir = opendir(path);

    if (dir == NULL)
        exit(EXIT_FAILURE);
    if (av[1][1] == 'l')
        l_call(path);
}

int main(int ac, char **av)
{
    DIR *dir;
    char *path;

    if (ac > 1 && av[1][0] != '-')
        path = av[1];
    else if (ac > 2)
        path = av[2];
    else
        path = ".";
    dir = opendir(path);
    if (dir == NULL)
        exit(EXIT_FAILURE);
    if ((ac <= 2 && path == av[1]) || (ac == 1))
        basic_ls(ac, av);
    if (ac > 1) {
        if (av[1][0] == '-')
            manage_flags(av, path);
    }
    closedir(dir);
    return 0;
}

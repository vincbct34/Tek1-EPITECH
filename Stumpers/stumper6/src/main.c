/*
** EPITECH PROJECT, 2024
** duo
** File description:
** stumper
*/

#include "my.h"

int check_return(char **av, int key)
{
    if (strcmp(av[1], "-s") == 0) {
        if (encrypt_string(av[2], key, fd) == 84)
            return 84;
        close(fd);
        return 0;
    }
    if (strcmp(av[1], "-f") == 0) {
        if (encrypt_file(av[2], key, fd) == 84)
            return 84;
        close(fd);
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int key = 0;
    int fd = open("crypt", O_CREAT | O_RDWR, S_IRUSR);

    if (ac < 3 || ac > 4)
        return 84;
    if (ac != 3)     
        key = atoi(av[3]);
    if (ac == 4) {
        if (strcmp(av[3], "0") != 0 && key == 0)
            return 84;
    }
    if (check_return(av, key, fd) == 0)
        return 0;
    return 84;
}

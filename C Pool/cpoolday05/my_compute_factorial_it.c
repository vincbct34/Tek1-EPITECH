/*
** EPITECH PROJECT, 2023
** my_compute_factorial_it
** File description:
** Task01
*/

int my_compute_factorial_it(int nb)
{
    int i = nb;

    if (nb == 0) {
        return 1;
    }
    if (nb < 0 || nb > 12) {
        return 0;
    }
    while (i > 1) {
        i--;
        nb = i * nb;
    }
    return nb;
}

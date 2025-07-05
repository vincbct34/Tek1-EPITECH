/*
** EPITECH PROJECT, 2023
** my_compute_power_it
** File description:
** Task03
*/

int my_compute_power_it(int nb, int p)
{
    int i = nb;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    while (p > 1) {
        nb = i * nb;
        p--;
    }
    return nb;
}

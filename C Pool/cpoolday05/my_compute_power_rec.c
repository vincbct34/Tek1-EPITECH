/*
** EPITECH PROJECT, 2023
** my_compute_power_it
** File description:
** Task03
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    if (p < 2) {
        return nb;
    }
    return nb * my_compute_power_rec(nb, p - 1);
}

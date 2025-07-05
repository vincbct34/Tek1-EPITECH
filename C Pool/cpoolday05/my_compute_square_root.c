/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Task05
*/

int my_compute_square_root(int nb)
{
    int var = nb;

    if (nb < 0) {
        return 0;
    }
    while (var * var != nb) {
        var--;
        if (nb % var != 0) {
            return 0;
        }
    }
    return var;
}

/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Library
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int i_result = 0;

    while (i_result < nb) {
        i_result = i * i;
        if (i_result == nb)
            return (i);
        if (i < 0 || i > 46340)
            return 0;
        i = i + 1;
    }
    return (0);
}

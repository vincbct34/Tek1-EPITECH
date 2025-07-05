/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** library
*/

int my_compute_square_root(unsigned int nb)
{
    unsigned int i = 1;
    unsigned int i_result = 0;

    while (i_result < nb) {
        i_result = i * i;
        if (i_result == nb)
            return (i);
        else
            i = i + 1
    }
    return (0);
}

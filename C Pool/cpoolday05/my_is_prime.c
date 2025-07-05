/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Task06
*/

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1) {
        return 0;
    }
    if (nb == 2 || nb == 3 || nb == 5 || nb == 7) {
        return 1;
    }
    if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0) {
        return 0;
    } else {
        return 1;
    }
}

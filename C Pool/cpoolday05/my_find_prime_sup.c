/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Task07
*/

int my_find_prime_sup(int nb)
{
    int var = nb;

    if (var == 0 || var == 1)
        return 2;
    if (var == 2)
        return 2;
    if (var == 3)
        return 3;
    if (var == 4 || var == 5)
        return 5;
    if (var == 6 || var == 7)
        return 7;
    while (var % 2 == 0 || var % 3 == 0 || var % 5 == 0 || var % 7 == 0) {
        var++;
    }
    return var;
}

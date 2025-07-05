/*
** EPITECH PROJECT, 2023
** Testeur
** File description:
** Test des tasks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_compute_power_rec(int nb, int p);

Test(day5, Task04)
{
    my_compute_power_rec(6, 3);
    int var = my_compute_power_rec(6, 3);
    cr_assert_eq(216, var);
}

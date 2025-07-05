/*
** EPITECH PROJECT, 2023
** Testeur
** File description:
** Test des tasks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_compute_power_it(int nb, int p);

Test(day5, Task03)
{
    my_compute_power_it(6, 3);
    int var = my_compute_power_it(6, 3);
    cr_assert_eq(216, var);
}

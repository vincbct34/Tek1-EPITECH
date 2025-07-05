/*
** EPITECH PROJECT, 2023
** Testeur
** File description:
** Test des tasks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_compute_factorial_rec(int nb);

Test(day5, Task02)
{
    my_compute_factorial_rec(5);
    int var = my_compute_factorial_rec(5);
    cr_assert_eq(120, var);
}

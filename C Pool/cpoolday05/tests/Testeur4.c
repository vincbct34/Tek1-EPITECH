/*
** EPITECH PROJECT, 2023
** Testeur
** File description:
** Test des tasks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_compute_square_root(int nb);

Test(day5, Task05)
{
    cr_assert_eq(my_compute_square_root(55), 0);
}

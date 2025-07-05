/*
** EPITECH PROJECT, 2023
** Testeur
** File description:
** Test des tasks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_find_prime_sup(int nb);

Test(day5, Task06)
{
    cr_assert_eq(my_find_prime_sup(50), 53);
}

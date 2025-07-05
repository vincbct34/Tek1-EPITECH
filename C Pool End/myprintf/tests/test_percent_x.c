/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std11(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_x_nbr, .init=redirect_all_std11)
{
my_printf("hello %xworld", 14);
cr_assert_stdout_eq_str("hello eworld");
}

Test(my_printf, percent_x_max, .init=redirect_all_std11)
{
my_printf("hello %xworld", 2147483647);
cr_assert_stdout_eq_str("hello 7fffffffworld");
}

Test(my_printf, percent_x_zero, .init=redirect_all_std11)
{
my_printf("hello %xworld", 0);
cr_assert_stdout_eq_str("hello 0world");
}

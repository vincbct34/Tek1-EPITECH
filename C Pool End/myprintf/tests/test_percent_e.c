/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std13(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_e_nbr, .init=redirect_all_std13)
{
my_printf("hello %eworld", 14.7);
cr_assert_stdout_eq_str("hello 1.470000e+01world");
}

Test(my_printf, percent_e_zero, .init=redirect_all_std13)
{
my_printf("hello %eworld", 0.005);
cr_assert_stdout_eq_str("hello 5.000000e-03world");
}

Test(my_printf, percent_e_neg, .init=redirect_all_std13)
{
my_printf("hello %eworld", -14.7);
cr_assert_stdout_eq_str("hello -1.470000e+01world");
}
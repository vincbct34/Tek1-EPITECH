/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std3(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_d_nbr, .init=redirect_all_std3)
{
my_printf("hello %dworld", 69);
cr_assert_stdout_eq_str("hello 69world");
}

Test(my_printf, percent_d_nbr_max_pos, .init=redirect_all_std3)
{
my_printf("hello %dworld", 2147483647);
cr_assert_stdout_eq_str("hello 2147483647world");
}

Test(my_printf, percent_d_nbr_max_neg, .init=redirect_all_std3)
{
my_printf("hello %dworld", -2147483647);
cr_assert_stdout_eq_str("hello -2147483647world");
}

Test(my_printf, percent_d_zero_neg, .init=redirect_all_std3)
{
my_printf("hello %dworld", -0);
cr_assert_stdout_eq_str("hello 0world");
}

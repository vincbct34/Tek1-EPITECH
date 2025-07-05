/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include<criterion/redirect.h>
#include"../includes/myprintf.h"

void redirect_all_std5(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_i_nbr, .init=redirect_all_std5)
{
my_printf("hello %iworld", 69);
cr_assert_stdout_eq_str("hello 69world");
}

Test(my_printf, percent_i_nbr_max_pos, .init=redirect_all_std5)
{
my_printf("hello %iworld", 2147483647);
cr_assert_stdout_eq_str("hello 2147483647world");
}

Test(my_printf, percent_i_nbr_max_neg, .init=redirect_all_std5)
{
my_printf("hello %iworld", -2147483647);
cr_assert_stdout_eq_str("hello -2147483647world");
}

Test(my_printf, percent_i_zero_neg, .init=redirect_all_std5)
{
my_printf("hello %iworld", -0);
cr_assert_stdout_eq_str("hello 0world");
}

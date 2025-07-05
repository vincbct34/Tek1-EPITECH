/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include<criterion/redirect.h>
#include"../includes/myprintf.h"

void redirect_all_std4(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_f_zero_one_pos, .init=redirect_all_std4)
{
my_printf("hello %fworld", 3.001);
cr_assert_stdout_eq_str("hello 3.001000world");
}

Test(my_printf, percent_f_zero_one_neg, .init=redirect_all_std4)
{
my_printf("hello %fworld", -3.001);
cr_assert_stdout_eq_str("hello -3.001000world");
}

Test(my_printf, percent_f_nbr, .init=redirect_all_std4)
{
my_printf("hello %fworld", 12.5678918);
cr_assert_stdout_eq_str("hello 12.567892world");
}

Test(my_printf, percent_f_zero_float, .init=redirect_all_std4)
{
my_printf("hello %fworld", 0.005);
cr_assert_stdout_eq_str("hello 0.005000world");
}
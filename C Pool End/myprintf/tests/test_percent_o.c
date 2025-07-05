/*
** EPITECH PROJECT, 2023
** test_percent_o
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include<criterion/redirect.h>
#include"../includes/myprintf.h"

void redirect_all_std6(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_o_nbr, .init=redirect_all_std6)
{
my_printf("hello %oworld", 11);
cr_assert_stdout_eq_str("hello 13world");
}

Test(my_printf, percent_o_max, .init=redirect_all_std6)
{
my_printf("hello %oworld", 2147483647);
cr_assert_stdout_eq_str("hello 17777777777world");
}

Test(my_printf, percent_o_zero, .init=redirect_all_std6)
{
my_printf("hello %oworld", 0);
cr_assert_stdout_eq_str("hello 0world");
}

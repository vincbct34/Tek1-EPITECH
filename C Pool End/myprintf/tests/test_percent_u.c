/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include<criterion/redirect.h>
#include"../includes/myprintf.h"

void redirect_all_std9(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_u_nbr, .init=redirect_all_std9)
{
my_printf("hello %uworld", 11);
cr_assert_stdout_eq_str("hello 11world");
}

Test(my_printf, percent_u_max, .init=redirect_all_std9)
{
my_printf("hello %uworld", 2147483647);
cr_assert_stdout_eq_str("hello 2147483647world");
}

Test(my_printf, percent_u_zero, .init=redirect_all_std9)
{
my_printf("hello %uworld", 0);
cr_assert_stdout_eq_str("hello 0world");
}
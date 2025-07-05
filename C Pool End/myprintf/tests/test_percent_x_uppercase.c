/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std10(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_X_nbr, .init=redirect_all_std10)
{
my_printf("hello %Xworld", 14);
cr_assert_stdout_eq_str("hello Eworld");
}

Test(my_printf, percent_X_max, .init=redirect_all_std10)
{
my_printf("hello %Xworld", 2147483647);
cr_assert_stdout_eq_str("hello 7FFFFFFFworld");
}

Test(my_printf, percent_X_zero, .init=redirect_all_std10)
{
my_printf("hello %Xworld", 0);
cr_assert_stdout_eq_str("hello 0world");
}
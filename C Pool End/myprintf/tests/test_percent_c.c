/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std2(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_c_low, .init=redirect_all_std2)
{
my_printf("he%clo world", 'l');
cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, percent_c_up, .init=redirect_all_std2)
{
my_printf("he%clo world", 'L');
cr_assert_stdout_eq_str("heLlo world");
}

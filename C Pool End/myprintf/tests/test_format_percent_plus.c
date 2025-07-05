/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h> //o x X d
#include "../includes/myprintf.h"

void redirect_all_std20(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, format_percent_plus_d, .init=redirect_all_std20)
{
    my_printf("%+d", 10050);
    cr_assert_stdout_eq_str("+10050");
}

Test(my_printf, format_percent_plus_d2, .init=redirect_all_std20)
{
    my_printf("%+d", -10050);
    cr_assert_stdout_eq_str("-10050");
}

Test(my_printf, format_percent_plus_d3, .init=redirect_all_std20)
{
    my_printf("%+d", -0);
    cr_assert_stdout_eq_str("+0");
}

Test(my_printf, format_percent_plus_d4, .init=redirect_all_std20)
{
    my_printf("%+d", 0);
    cr_assert_stdout_eq_str("+0");
}

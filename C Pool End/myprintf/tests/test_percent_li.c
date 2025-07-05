/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include<criterion/redirect.h>
#include"../includes/myprintf.h"

void redirect_all_std16(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_li_nbr, .init=redirect_all_std16)
{
my_printf("hello %liworld", 69);
cr_assert_stdout_eq_str("hello 69world");
}

Test(my_printf, percent_li_nbr_max_pos, .init=redirect_all_std16)
{
my_printf("hello %liworld", 9223372036854775807);
cr_assert_stdout_eq_str("hello 9223372036854775807world");
}

Test(my_printf, percent_li_nbr_max_neg, .init=redirect_all_std16)
{
my_printf("hello %liworld", -9223372036854775807);
cr_assert_stdout_eq_str("hello -9223372036854775807world");
}

Test(my_printf, percent_li_zero_neg, .init=redirect_all_std16)
{
my_printf("hello %liworld", -0);
cr_assert_stdout_eq_str("hello 0world");
}

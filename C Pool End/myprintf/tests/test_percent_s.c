/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include<criterion/redirect.h>
#include"../includes/myprintf.h"

void redirect_all_std8(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_s_string, .init=redirect_all_std8)
{
my_printf ("%s world", "hello to all the");
cr_assert_stdout_eq_str ("hello to all the world");
}

Test(my_printf, percent_s_char, .init=redirect_all_std8)
{
my_printf ("World %s", "!");
cr_assert_stdout_eq_str ("World !");
}

Test(my_printf, percent_s_nothing, .init=redirect_all_std8)
{
my_printf ("hello world%s", "");
cr_assert_stdout_eq_str ("hello world");
}

Test(my_printf, percent_s_space, .init=redirect_all_std8)
{
my_printf ("hello world%s!", " ");
cr_assert_stdout_eq_str ("hello world !");
}

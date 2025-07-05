/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std7(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, simple_percent, .init=redirect_all_std7)
{
my_printf("he%%lo world");
cr_assert_stdout_eq_str("he%lo world");
}

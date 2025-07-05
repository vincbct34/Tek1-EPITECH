/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/myprintf.h"

void redirect_all_std(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(my_printf, percent_all, .init=redirect_all_std)
{
my_printf("a%d%i %s%%%c",100,50,"wo",'p');
cr_assert_stdout_eq_str("a10050 wo%p");
}

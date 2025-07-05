/*
** EPITECH PROJECT, 2024
** CHOCOLATINE
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int function(void)
{
    return (0);
}

Test(test, test_return, .init = redirect_all_std)
{
    cr_assert_eq(function(), 0);
}

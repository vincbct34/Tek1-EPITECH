/*
** EPITECH PROJECT, 2023
** test
** File description:
** All the tests of my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h> //o x X d
#include "../includes/myprintf.h"

void redirect_all_std18(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, format_percent_hashtag_d, .init=redirect_all_std18)
{
    my_printf("hello %#dworld", 10050);
    cr_assert_stdout_eq_str("hello 10050world");
}

Test(my_printf, format_percent_hashtag_d2, .init=redirect_all_std18)
{
    my_printf("hello %#dworld", -10050);
    cr_assert_stdout_eq_str("hello -10050world");
}

Test(my_printf, format_percent_hashtag_d3, .init=redirect_all_std18)
{
    my_printf("hello %#dworld", 2147483647);
    cr_assert_stdout_eq_str("hello 2147483647world");
}

Test(my_printf, format_percent_hashtag_d4, .init=redirect_all_std18)
{
    my_printf("hello %#dworld", -2147483647);
    cr_assert_stdout_eq_str("hello -2147483647world");
}

Test(my_printf, format_percent_hashtag_d5, .init=redirect_all_std18)
{
    my_printf("hello %#dworld", 0);
    cr_assert_stdout_eq_str("hello 0world");
}

Test(my_printf, format_percent_hashtag_o, .init=redirect_all_std18)
{
    my_printf("hello %#oworld", 0);
    cr_assert_stdout_eq_str("hello 0world");
}

Test(my_printf, format_percent_hashtag_o2, .init=redirect_all_std18)
{
    my_printf("hello %#oworld", 2147483647);
    cr_assert_stdout_eq_str("hello 017777777777world");
}

Test(my_printf, format_percent_hashtag_o3, .init=redirect_all_std18)
{
    my_printf("hello %#oworld", 11);
    cr_assert_stdout_eq_str("hello 013world");
}

Test(my_printf, format_percent_hashtag_x, .init=redirect_all_std18)
{
    my_printf("hello %#xworld", 0);
    cr_assert_stdout_eq_str("hello 0world");
}

Test(my_printf, format_percent_hashtag_x2, .init=redirect_all_std18)
{
    my_printf("hello %#xworld", 2147483647);
    cr_assert_stdout_eq_str("hello 0x7fffffffworld");
}

Test(my_printf, format_percent_hashtag_x3, .init=redirect_all_std18)
{
    my_printf("hello %#xworld", 11);
    cr_assert_stdout_eq_str("hello 0xbworld");
}

Test(my_printf, format_percent_hashtag_X, .init=redirect_all_std18)
{
    my_printf("hello %#Xworld", 0);
    cr_assert_stdout_eq_str("hello 0world");
}

Test(my_printf, format_percent_hashtag_X2, .init=redirect_all_std18)
{
    my_printf("hello %#Xworld", 2147483647);
    cr_assert_stdout_eq_str("hello 0X7FFFFFFFworld");
}

Test(my_printf, format_percent_hashtag_X3, .init=redirect_all_std18)
{
    my_printf("hello %#Xworld", 11);
    cr_assert_stdout_eq_str("hello 0XBworld");
}

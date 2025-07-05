/*
** EPITECH PROJECT, 2023
** test.c
** File description:
** Criterion's tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void show_alphabet(void);
void show_string(char const *str);
void show_combinations(void);
void show_number(int nb);
int to_number(char const *str);
char *reverse_string(char *str);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(show_alphabet, should_print_alphabet, .init = redirect_all_std)
{
    show_alphabet();
    cr_assert_stdout_eq_str("abcdefghijklmnopqrstuvwxyz");
}

Test(show_string, should_print_string, .init = redirect_all_std)
{
    show_string("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(show_combinations, should_print_combinations, .init = redirect_all_std)
{
    show_combinations();
    cr_assert_stdout_eq_str("012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789");
}

Test(show_number, should_print_number, .init = redirect_all_std)
{
    show_number(42);
    cr_assert_stdout_eq_str("42");
}

Test(show_number, should_print_number2, .init = redirect_all_std)
{
    show_number(-42);
    cr_assert_stdout_eq_str("-42");
}

Test(to_number, should_print_number, .init = redirect_all_std)
{
    to_number("42");
    cr_assert_eq(to_number("42"), 42);
}

Test(to_number, should_print_number2, .init = redirect_all_std)
{
    to_number("-42");
    cr_assert_eq(to_number("-42"), -42);
}

Test(to_number, should_print_number3, .init = redirect_all_std)
{
    to_number("42a43");
    cr_assert_eq(to_number("42a43"), 42);
}

Test(to_number, should_print_number4, .init = redirect_all_std)
{
    to_number("2147483648");
    cr_assert_eq(to_number("2147483648"), 0);
}

Test(to_number, should_print_number5, .init = redirect_all_std)
{
    to_number("-2147483649");
    cr_assert_eq(to_number("-2147483649"), 0);
}

Test(reverse_string, should_print_reverse_string, .init = redirect_all_std)
{
    char str[] = "Hello World!";

    reverse_string(str);
    cr_assert_eq(strcmp(str, "!dlroW olleH"), 0);
}

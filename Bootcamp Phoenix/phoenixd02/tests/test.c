/*
** EPITECH PROJECT, 2023
** test.c
** File description:
** Criterion's tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int is_prime_number(int nb);
int iterative_factorial(int nb);
char *my_strcapitalize(char *str);
char *my_strlowcase(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int recursive_power(int nb, int p);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_prime_number, should_return_1)
{
    int nb = 5;
    int result = is_prime_number(nb);

    cr_assert_eq(result, 1);
}

Test(is_prime_number, should_return_0)
{
    int nb = 6;
    int result = is_prime_number(nb);

    cr_assert_eq(result, 0);
}

Test(is_prime_number, should_return_0_with_0)
{
    int nb = 0;
    int result = is_prime_number(nb);

    cr_assert_eq(result, 0);
}

Test(iterative_factorial, should_return_120)
{
    int nb = 5;
    int result = iterative_factorial(nb);
    printf("%d\n", result);

    cr_assert_eq(result, 120);
}

Test(iterative_factorial, should_return_0)
{
    int nb = -5;
    int result = iterative_factorial(nb);

    cr_assert_eq(result, 0);
}

Test(iterative_factorial, should_return_1)
{
    int nb = 0;
    int result = iterative_factorial(nb);

    cr_assert_eq(result, 1);
}

Test(my_strcapitalize, should_return_Hello_World)
{
    char str[] = "hello world";
    char *result = my_strcapitalize(str);

    cr_assert_str_eq(result, "Hello World");
}

Test(my_strcapitalize, should_return_Hello_World_With_Numbers)
{
    char str[] = "hello world 123";
    char *result = my_strcapitalize(str);

    cr_assert_str_eq(result, "Hello World 123");
}

Test(my_strlowcase, should_return_hello_world)
{
    char str[] = "HELLO WORLD";
    char *result = my_strlowcase(str);

    cr_assert_str_eq(result, "hello world");
}

Test(my_strcpy, should_return_Hello_World)
{
    char dest[12];
    char src[] = "Hello World";
    char *result = my_strcpy(dest, src);

    cr_assert_str_eq(result, "Hello World");
}

Test(my_strncmp, should_return_0)
{
    char s1[] = "Hello World";
    char s2[] = "Hello World";
    int n = 5;
    int result = my_strncmp(s1, s2, n);

    cr_assert_eq(result, 0);
}

Test(my_strncmp, should_return_1)
{
    char s1[] = "Hello World";
    char s2[] = "Hello-";
    int n = 6;
    int result = my_strncmp(s1, s2, n);

    cr_assert_eq(result, -1);
}

Test(my_strncmp, should_return_minus_1)
{
    char s1[] = "HelloA";
    char s2[] = "Hello World";
    int n = 6;
    int result = my_strncmp(s1, s2, n);

    cr_assert_eq(result, 1);
}

Test(my_strncmp, should_return_0_with_0)
{
    char s1[] = "";
    char s2[] = "Hello World";
    int n = 1;
    int result = my_strncmp(s1, s2, n);

    cr_assert_eq(result, -1);
}

Test(my_strncmp, should_return_0_with_0_2)
{
    char s1[] = "Hello World";
    char s2[] = "";
    int n = 1;
    int result = my_strncmp(s1, s2, n);

    cr_assert_eq(result, 1);
}

Test(my_strstr, should_return_ello_World)
{
    char str[] = "Hello World";
    char to_find[] = "ello";
    char *result = my_strstr(str, to_find);

    cr_assert_str_eq(result, "ello World");
}

Test(my_strstr, should_return_null)
{
    char str[] = "Hello World";
    char to_find[] = "foo";
    char *result = my_strstr(str, to_find);

    cr_assert_eq(result, 0);
}

Test(my_strstr, should_return_Hello_World)
{
    char str[] = "Hello World";
    char to_find[] = "";
    char *result = my_strstr(str, to_find);

    cr_assert_str_eq(result, "Hello World");
}

Test(my_strupcase, should_return_HELLO_WORLD)
{
    char str[] = "Hello World";
    char *result = my_strupcase(str);

    cr_assert_str_eq(result, "HELLO WORLD");
}

Test(recursive_power, should_return_125)
{
    int nb = 5;
    int p = 3;
    int result = recursive_power(nb, p);

    cr_assert_eq(result, 125);
}

Test(recursive_power, should_return_1)
{
    int nb = 5;
    int p = -1;
    int result = recursive_power(nb, p);

    cr_assert_eq(result, 0);
}
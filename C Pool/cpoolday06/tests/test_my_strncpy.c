/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** 
*/

#include <criterion/criterion.h>

Test(my_revstr, copy_characters_in_empty_array)
{
    char dest[6] = {0};
    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

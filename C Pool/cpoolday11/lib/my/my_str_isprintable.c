/*
** EPITECH PROJECT, 2023
** my_str_isprintable
** File description:
** Library
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32)
            return (0);
        i++;
    }
    return (1);
}

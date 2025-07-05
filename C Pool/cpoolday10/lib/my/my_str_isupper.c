/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** Library
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            return (0);
        i++;
    }
    return (1);
}

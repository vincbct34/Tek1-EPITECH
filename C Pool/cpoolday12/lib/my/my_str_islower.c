/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** Library
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            return (0);
        i++;
    }
    return (1);
}

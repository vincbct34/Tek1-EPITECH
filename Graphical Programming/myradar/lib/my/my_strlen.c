/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

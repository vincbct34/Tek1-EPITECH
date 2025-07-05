/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

int nb_char(char const *str, char const to_count)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == to_count)
            count++;
    return (count);
}

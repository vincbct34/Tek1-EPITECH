/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** One by one
*/

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
    return (0);
}

/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** my_strcmp.c
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

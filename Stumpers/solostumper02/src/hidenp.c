/*
** EPITECH PROJECT, 2024
** hidenp.c
** File description:
** Solo Stumper n°2
*/

int is_in(char is_hidden, char *str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (is_hidden == str[j])
            return 1;
    }
    return 0;
}

int hidenp(char *is_hidden, char *str)
{
    int i = 0;

    while (is_hidden[i] != '\0') {
        if (is_in(is_hidden[i], str) == 1)
            i++;
        else
            return 0;
    }
    return 1;
}

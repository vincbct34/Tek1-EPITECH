/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** is_alpha_num
*/

int is_alpha_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'Z')
            && (str[i] < 'a' || str[i] > 'z') && (str[i] != '_'))
            return 0;
    }
    return 1;
}

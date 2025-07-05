/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** is_delim
*/

int is_delim(char c)
{
    if (c == '|' || c == '<' || c == '>' || c == ';')
        return 1;
    return 0;
}

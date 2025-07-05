/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** is_delim.c
*/

int is_delim(char c)
{
    if (c == '|' || c == '<' || c == '>' || c == ';')
        return 1;
    return 0;
}

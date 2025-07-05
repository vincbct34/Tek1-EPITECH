/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** env_lib.c
*/

#include "../../include/my.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}

void check_error_delim(char *delimiter, char *leftExpr, char *rightExpr)
{
    if (strcmp(delimiter, "|") == 0 || strcmp(delimiter, "||") == 0) {
        if (is_empty_or_space(leftExpr) || is_empty_or_space(rightExpr)) {
        my_puterror("Invalid null command.\n");
        exit(1);
        }
    }
    if (strcmp(delimiter, ">") == 0 || strcmp(delimiter, "<") == 0 ||
        strcmp(delimiter, ">>") == 0) {
        if (is_empty_or_space(leftExpr) || is_empty_or_space(rightExpr)) {
        my_puterror("Missing name for redirect.\n");
        exit(1);
        }
    }
}

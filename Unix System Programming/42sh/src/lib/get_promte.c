/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** print.c
*/

#include "../../include/my.h"

char *get_prompte(void)
{
    char cwd[1024];
    char *prompt = getcwd(cwd, sizeof(cwd));
    size_t total_length = strlen(prompt) + strlen(" $> ") + 1;
    char *result = malloc(total_length);

    strcpy(result, prompt);
    strcat(result, " $> ");
    return result;
}

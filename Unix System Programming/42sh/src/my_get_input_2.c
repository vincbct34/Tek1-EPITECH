/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** my_get_input
*/

#include "../include/my.h"

char *my_realloc(char *str)
{
    int len = 0;
    char *new_str;

    if (str != NULL)
        len = my_strlen(str);
    new_str = malloc(sizeof(char) * (len + 2));
    if (new_str == NULL)
        return NULL;
    if (str != NULL)
        for (int i = 0; i < len; i++)
            new_str[i] = str[i];
    new_str[len] = '\0';
    if (str != NULL)
        free(str);
    return new_str;
}

void cut_line(minishell_t shell, int *ind, int *cursor_ind)
{
    char *buffer = shell.data_termios->buffer;
    char *prompt = shell.data_termios->prompt;
    char *tmp = malloc(sizeof(char) * (strlen(&buffer[*cursor_ind]) + 1));

    if (tmp == NULL)
        return;
    strcpy(tmp, &buffer[*cursor_ind]);
    buffer[*cursor_ind] = '\0';
    *ind = *cursor_ind;
    printf("\033[s");
    printf("\033[34m\033[2K\r%s\033[0m%s", prompt, buffer);
    printf("\033[u");
    printf("\033[%ldG", strlen(prompt) + *cursor_ind + 1);
    *cursor_ind = *ind;
    shell.data_termios->clipboard = strdup(tmp);
    return;
}

void paste(minishell_t shell, int *ind, int *cursor_ind)
{
    char *buffer = shell.data_termios->buffer;
    char *prompt = shell.data_termios->prompt;
    char *tmp = shell.data_termios->clipboard;

    if (tmp == NULL)
        return;
    buffer = strdup(my_realloc(buffer));
    memmove(&buffer[*cursor_ind + strlen(tmp)],
        &buffer[*cursor_ind], strlen(&buffer[*cursor_ind]) + 1);
    memmove(&buffer[*cursor_ind], tmp, strlen(tmp));
    *ind += strlen(tmp);
    *cursor_ind += strlen(tmp);
    printf("\033[s");
    printf("\033[34m\033[2K\r%s\033[0m%s", prompt, buffer);
    printf("\033[u");
    printf("\033[%ldG", strlen(prompt) + *cursor_ind + 1);
    return;
}

void copy(minishell_t shell, int *cursor_ind)
{
    char *buffer = shell.data_termios->buffer;
    char *tmp = malloc(sizeof(char) * (strlen(&buffer[*cursor_ind]) + 1));

    if (tmp == NULL)
        return;
    strcpy(tmp, &buffer[*cursor_ind]);
    shell.data_termios->clipboard = strdup(tmp);
    return;
}

/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** history
*/

#include "../include/my.h"

void up_arrow(minishell_t *shell, int *ind, int *cursor_ind)
{
    char *prompt = NULL;

    if (shell->history_list == NULL)
        return;
    prompt = shell->history_list->prompt;
    if (shell->data_termios->buffer != NULL)
        free(shell->data_termios->buffer);
    shell->data_termios->buffer = malloc(sizeof(char) * (strlen(prompt) + 1));
    shell->data_termios->buffer = strcpy(shell->data_termios->buffer, prompt);
    shell->data_termios->buffer[strlen(prompt)] = '\0';
    *ind = strlen(shell->data_termios->buffer);
    *cursor_ind = *ind;
    printf("\033[34m\033[2K\r%s\033[0m%s",
        shell->data_termios->prompt, shell->data_termios->buffer);
    if (shell->history_list->next == NULL)
        return;
    shell->history_list = shell->history_list->next;
}

static void down_arrow2(minishell_t *shell, int *ind, int *cursor_ind)
{
    char *prompt = shell->history_list->prev->prompt;

    shell->data_termios->buffer = malloc(sizeof(char) * (strlen(prompt) + 1));
    shell->data_termios->buffer = strcpy(shell->data_termios->buffer, prompt);
    shell->data_termios->buffer[strlen(prompt)] = '\0';
    *ind = strlen(shell->data_termios->buffer);
    *cursor_ind = *ind;
    printf("\033[2K\r%s%s",
        shell->data_termios->prompt, shell->data_termios->buffer);
    shell->history_list = shell->history_list->prev;
}

void down_arrow(minishell_t *shell, int *ind, int *cursor_ind)
{
    if (shell->history_list == NULL)
        return;
    if (shell->data_termios->buffer != NULL) {
        free(shell->data_termios->buffer);
        shell->data_termios->buffer = NULL;
    }
    if (shell->history_list->prev == NULL) {
        printf("\033[2K\r%s", shell->data_termios->prompt);
        free(shell->data_termios->buffer);
        shell->data_termios->buffer = NULL;
        *ind = 0;
        *cursor_ind = 0;
        return;
    }
    down_arrow2(shell, ind, cursor_ind);
}

static void display_list(history_t *history_list)
{
    int i = 1;
    history_t *tmp = history_list;

    if (tmp == NULL)
        return;
    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        printf("\t%d %s %s\n", i, tmp->time, tmp->prompt);
        i++;
        tmp = tmp->prev;
    }
}

static void display_returned_history(history_t *history_list)
{
    history_t *tmp = history_list;
    int i = 0;

    if (tmp == NULL)
        return;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    tmp = history_list;
    while (tmp != NULL) {
        printf("\t%d %s %s\n", i, tmp->time, tmp->prompt);
        i--;
        tmp = tmp->next;
    }
}

static void delete_history(history_t *history_list)
{
    history_t *tmp = history_list;
    history_t *tmp2 = NULL;

    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        tmp2 = tmp->prev;
        free(tmp->prompt);
        free(tmp->time);
        free(tmp);
        tmp = tmp2;
    }
}

static void display_normal_list(history_t *history_list)
{
    int i = 1;
    history_t *tmp = history_list;

    if (tmp == NULL)
        return;
    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        printf("%s\n", tmp->prompt);
        i++;
        tmp = tmp->prev;
    }
}

char *history_command(minishell_t *shell)
{
    history_t *tmp = shell->history_list;
    char *str = malloc(sizeof(char) * (strlen(shell->args[0]) - 1));

    str = strcpy(str, shell->args[0] + 1);
    str[strlen(tmp->prompt) + 1] = '\0';
    tmp = tmp->next;
    if (tmp == NULL)
        return NULL;
    while (tmp != NULL) {
        if (strstr(tmp->prompt, str) != NULL)
            return tmp->prompt;
        tmp = tmp->next;
    }
    return NULL;
}

void print_history(minishell_t *shell, char **args)
{
    if (args[1] == NULL)
        return display_list(shell->history_list);
    if (strcmp(args[1], "-C") == 0) {
        delete_history(shell->history_list);
        shell->history_list = NULL;
        return;
    }
    if (strcmp(args[1], "-r") == 0) {
        return display_returned_history(shell->history_list);
    }
    if (strcmp(args[1], "-h") == 0)
        return display_normal_list(shell->history_list);
}

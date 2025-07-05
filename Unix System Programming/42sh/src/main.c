/*
** EPITECH PROJECT, 2024
** B-PSU-200
** File description:
** main
*/


#include "my.h"
#include <time.h>

void init_struct(minishell_t *minishell, char **env)
{
    INPUT = NULL;
    minishell->args = NULL;
    ENV = env;
    minishell->return_value = 0;
    minishell->size = 0;
    minishell->history_list = NULL;
    minishell->data_termios = malloc(sizeof(termios_t));
    minishell->data_termios->buffer = NULL;
    array_to_list(minishell);
    minishell->alias = NULL;
}

int handler(void)
{
    return 0;
}

static char *get_time(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *time = malloc(sizeof(char) * 20);

    if (tm.tm_hour < 10 && tm.tm_min < 10) {
        sprintf(time, "0%d:0%d", tm.tm_hour, tm.tm_min);
        return time;
    }
    if (tm.tm_hour < 10) {
        sprintf(time, "0%d:%d", tm.tm_hour, tm.tm_min);
        return time;
    }
    if (tm.tm_min < 10) {
        sprintf(time, "%d:0%d", tm.tm_hour, tm.tm_min);
        return time;
    }
    sprintf(time, "%d:%d", tm.tm_hour, tm.tm_min);
    return time;
}

static void add_history(history_t **history_list, char *prompt)
{
    history_t *new_node = malloc(sizeof(history_t));

    new_node->prompt = my_strdup(prompt);
    new_node->time = my_strdup(get_time());
    new_node->prev = NULL;
    if (*history_list == NULL) {
        new_node->next = NULL;
        *history_list = new_node;
        return;
    }
    (*history_list)->prev = new_node;
    new_node->next = *history_list;
    *history_list = new_node;
}

void tty_function(minishell_t minishell)
{
    while (1) {
        MINPUT = get_input();
        if (MINPUT == NULL) {
            continue;
        }
        add_history(&(minishell).history_list, MINPUT);
        minishell.args = my_str_to_word_array(MINPUT, ";");
        free(MINPUT);
        minishell.return_value = build_tree_to_array_and_execute(minishell.args
        , &minishell);
    }
}

void not_tty_function(minishell_t minishell)
{
    while (1) {
        MINPUT = my_get_input(minishell);
        if (MINPUT == NULL)
            continue;
        add_history(&(minishell).history_list, MINPUT);
        minishell.args = my_str_to_word_array(MINPUT, ";");
        free(MINPUT);
        minishell.return_value = build_tree_to_array_and_execute(minishell.args
        , &minishell);
    }
}

int main(int ac, char **av, char **env)
{
    minishell_t minishell;

    (void)ac;
    (void)av;
    minishell.no_builtin = 0;
    signal(SIGINT, (void *)handler);
    init_struct(&minishell, env);
    if (isatty(0)) {
        not_tty_function(minishell);
    } else {
        tty_function(minishell);
    }
    return minishell.return_value;
}

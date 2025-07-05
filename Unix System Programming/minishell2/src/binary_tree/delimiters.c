/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** delimiters.c
*/

#include "my.h"
#include "minishell.h"

void add_right(tree *head, char *command, int is_pipe)
{
    tree *cur = head;
    tree *pipe_cur = NULL;

    while (cur->next != NULL)
        cur = cur->next;
    if (is_pipe == 1) {
        pipe_cur = cur->pipe;
        while (pipe_cur->next != NULL)
            pipe_cur = pipe_cur->next;
        pipe_cur->redirect_r = my_strdup(command);
        return;
    }
    cur->redirect_r = my_strdup(command);
}

void add_left(tree *head, char *command, int is_pipe)
{
    tree *cur = head;
    tree *pipe_cur = NULL;

    while (cur->next != NULL)
        cur = cur->next;
    if (is_pipe == 1) {
        pipe_cur = cur->pipe;
        while (pipe_cur->next != NULL)
            pipe_cur = pipe_cur->next;
        pipe_cur->redirect_l = my_strdup(command);
        return;
    }
    cur->redirect_l = my_strdup(command);
}

void add_double_left(tree *head, char *command, int is_pipe)
{
    tree *cur = head;
    tree *pipe_cur = NULL;

    while (cur->next != NULL)
        cur = cur->next;
    if (is_pipe == 1) {
        pipe_cur = cur->pipe;
        while (pipe_cur->next != NULL)
            pipe_cur = pipe_cur->next;
        pipe_cur->redirect_l_l = my_strdup(command);
        return;
    }
    cur->redirect_l_l = my_strdup(command);
}

void add_double_right(tree *head, char *command, int is_pipe)
{
    tree *cur = head;
    tree *pipe_cur = NULL;

    while (cur->next != NULL)
        cur = cur->next;
    if (is_pipe == 1) {
        pipe_cur = cur->pipe;
        while (pipe_cur->next != NULL)
            pipe_cur = pipe_cur->next;
        pipe_cur->redirect_r_r = my_strdup(command);
        return;
    }
    cur->redirect_r_r = my_strdup(command);
}

void add_pipe(tree *head, char *command)
{
    tree *cur = head;
    tree *pipe_cur = NULL;

    while (cur->next != NULL)
        cur = cur->next;
    if (cur->pipe == NULL) {
        cur->pipe = create_node();
        cur->pipe->command = my_str_to_word_array(command, ' ');
        return;
    }
    pipe_cur = cur->pipe;
    while (pipe_cur->next != NULL)
        pipe_cur = pipe_cur->next;
    pipe_cur->next = create_node();
    pipe_cur->next->command = my_str_to_word_array(command, ' ');
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** build_tree.c
*/

#include "my.h"
#include "minishell.h"

tree *create_node(void)
{
    tree *node = malloc(sizeof(tree));

    node->command = NULL;
    node->pipe = NULL;
    node->redirect_l = NULL;
    node->redirect_r = NULL;
    node->redirect_r_r = NULL;
    node->redirect_l_l = NULL;
    node->next = NULL;
    return node;
}

static int get_last(char *tmp, int i)
{
    if (i > 1)
        i -= 2;
    else
        return 0;
    for (; i >= 0; i--) {
        if (tmp[i] == ';')
            return 1;
        if (tmp[i] == '|')
            return 2;
        if (tmp[i] == '<' && tmp[i - 1] && tmp[i - 1] == '<')
            return 3;
        if (tmp[i] == '<')
            return 4;
        if (tmp[i] == '>' && tmp[i - 1] && tmp[i - 1] == '>')
            return 5;
        if (tmp[i] == '>')
            return 6;
    }
    return 0;
}

static void push_back(tree *head, char *tmp)
{
    tree *cur = head;

    if (head == NULL) {
        head = create_node();
        head->command = malloc(sizeof(char *) * 2);
        head->command[0] = my_strdup(tmp);
        head->command[1] = NULL;
        return;
    }
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = create_node();
    cur->next->command = my_str_to_word_array(tmp, ' ');
}

static void sort_command(tree *head, char *tmp, char *input, int i)
{
    static int is_pipe = 0;
    int last = get_last(input, i);

    clean_str(tmp, 0);
    if (last == 0 || last == 1) {
        push_back(head, tmp);
        is_pipe = 0;
    }
    if (last == 2) {
        add_pipe(head, tmp);
        is_pipe = 1;
    }
    if (last == 3)
        add_double_left(head, tmp, is_pipe);
    if (last == 4)
        add_left(head, tmp, is_pipe);
    if (last == 5)
        add_double_right(head, tmp, is_pipe);
    if (last == 6)
        add_right(head, tmp, is_pipe);
}

static void final_tmp(tree *head, char *tmp, char *input, int i)
{
    if (tmp != NULL) {
        sort_command(head, tmp, input, i);
        free(tmp);
        tmp = NULL;
    }
}

tree *build_binary_tree(minishell *msh)
{
    char *tmp = NULL;
    tree *head = create_node();
    int i = 0;

    for (; msh->input[i]; i++) {
        if (is_delim(msh->input[i]) == 0) {
            tmp = my_realloc(tmp, msh->input[i]);
            continue;
        }
        if (tmp != NULL) {
            sort_command(head, tmp, msh->input, i);
            free(tmp);
            tmp = NULL;
        }
    }
    final_tmp(head, tmp, msh->input, i);
    return head;
}

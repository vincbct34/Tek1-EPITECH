/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** minishell.c
*/

#include "my.h"
#include "minishell.h"

static void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
        my_putstr("B-PSU-200> ");
}

static int handler(void)
{
    my_putstr("\n");
    display_prompt();
    return 0;
}

static void commands(minishell *msh)
{
    if ((my_strcmp(msh->basic_args[0], "exit") == 0)
        || (my_strcmp(msh->basic_args[0], "cd") == 0)
        || (my_strcmp(msh->basic_args[0], "env") == 0)
        || (my_strcmp(msh->basic_args[0], "setenv") == 0)
        || (my_strcmp(msh->basic_args[0], "unsetenv") == 0))
        my_builtin(msh);
    else
        my_exec(msh);
}

static int check_if_binary_tree_needed(minishell *msh)
{
    for (int i = 0; msh->input[i] != '\0'; i++) {
        if (msh->input[i] == '|' || msh->input[i] == '<'
            || msh->input[i] == '>' || msh->input[i] == ';') {
            msh->tree = build_binary_tree(msh);
            return 0;
        }
    }
    return 1;
}

void free_command(char **command)
{
    if (command != NULL) {
        for (int i = 0; command[i] != NULL; i++)
            free(command[i]);
        free(command);
    }
}

void free_redirection(tree *tree)
{
    if (tree->redirect_l)
        free(tree->redirect_l);
    if (tree->redirect_r)
        free(tree->redirect_r);
    if (tree->redirect_l_l)
        free(tree->redirect_l_l);
    if (tree->redirect_r_r)
        free(tree->redirect_r_r);
}

void free_list(tree *head)
{
    tree *current = head;
    tree *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free_command(temp->command);
        free_redirection(temp);
        free(temp);
    }
}

static void execute_binary_tree(minishell *msh)
{
    tree *current = msh->tree;

    current = current->next;
    while (current != NULL) {
        if (current->command)
            commands_for_tree(current, msh);
        free_list(current->pipe);
        current = current->next;
    }
}

void my_minishell(minishell *msh)
{
    signal(SIGINT, (void *)handler);
    while (1) {
        display_prompt();
        get_input(msh);
        if (msh->input == NULL)
            continue;
        if (my_strcmp(msh->input, "|") == 0) {
            my_putstr("Invalid null command.\n");
            continue;
        }
        if (check_if_binary_tree_needed(msh) == 0) {
            execute_binary_tree(msh);
        } else {
            msh->basic_args = parsing(msh);
            commands(msh);
        }
        free_list(msh->tree);
        msh->tree = create_node();
    }
}

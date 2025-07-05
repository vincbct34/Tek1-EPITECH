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
    if ((my_strcmp(msh->args[0], "exit") == 0)
        || (my_strcmp(msh->args[0], "cd") == 0)
        || (my_strcmp(msh->args[0], "env") == 0)
        || (my_strcmp(msh->args[0], "setenv") == 0)
        || (my_strcmp(msh->args[0], "unsetenv") == 0))
        my_builtin(msh);
    else
        my_exec(msh);
}

void my_minishell(minishell *msh)
{
    signal(SIGINT, (void *)handler);
    while (1) {
        display_prompt();
        get_input(msh);
        if (msh->input == NULL)
            continue;
        msh->args = parsing(msh);
        commands(msh);
    }
}

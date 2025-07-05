/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** parsing.c
*/

#include "minishell.h"
#include "my.h"

static void is_ctrl_d(void)
{
    if (isatty(0))
        my_putstr("exit\n");
    exit(0);
}

void get_input(minishell *msh)
{
    size_t len = 0;
    ssize_t read;

    msh->input = NULL;
    read = getline(&msh->input, &len, stdin);
    if (read == -1)
        is_ctrl_d();
    for (int i = 0; msh->input[i] != '\0'; i++) {
        if (msh->input[i] == '\t')
            msh->input[i] = ' ';
    }
    if (msh->input[0] == '\n') {
        free(msh->input);
        msh->input = NULL;
        return;
    }
    msh->input[my_strlen(msh->input) - 1] = '\0';
}

static int get_nb_space(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            nb++;
    return nb + 2;
}

char **parsing(minishell *msh)
{
    char **parsing = NULL;
    char *str = my_strdup(msh->input);
    int nb_space = get_nb_space(str);
    char *token = strtok(str, " ");
    int i = 0;

    parsing = malloc(sizeof(char *) * nb_space);
    while (token != NULL) {
        parsing[i] = my_strdup(token);
        token = strtok(NULL, " ");
        i++;
    }
    parsing[i] = NULL;
    free(str);
    return parsing;
}

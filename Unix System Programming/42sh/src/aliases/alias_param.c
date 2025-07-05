/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-vincent.bichat
** File description:
** alias_param.c
*/

#include "../../include/my.h"

void emi_exec_alias_com(minishell_t *minishell, char **args_emi)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        status = check_directory(minishell);
        if (status == 1) {
            exit(EXIT_FAILURE);
        }
        INPUT = emi_get_path(minishell, args_emi[0]);
        emi_write_error(minishell, args_emi);
    } else {
        waitpid(pid, &status, 0);
        analyse_status(status);
    }
}

int alias_with_flags(minishell_t *minishell, char **args_emi, alias_t *tmp)
{
    if (flags_or_not_two(tmp) == 0) {
        args_emi = my_str_to_word_array(tmp->command, " '");
        emi_exec_alias_com(minishell, args_emi);
        return 0;
    }
    return 1;
}

static void write_param(int k, int *l, char **args_emi)
{
    if (args_emi[k][*l] == '$') {
        for (; args_emi[k][*l] != '\0'; (*l)++);
    }
    write(1, &args_emi[k][*l], 1);
}

static void count_param_bis(char **args_emi, int i, int *count_param, int j)
{
    if (args_emi[i][j] == '$')
        (*count_param)++;
}

static int count_param(char **args_emi)
{
    int count_param = 0;

    for (int i = 0; args_emi[i] != NULL; i++) {
        for (int j = 0; args_emi[i][j] != '\0'; j++) {
            count_param_bis(args_emi, i, &count_param, j);
        }
    }
    return count_param;
}

void assign_parameter_bis(int m, int a_l, minishell_t *minishell, char **prm)
{
    for (int i = m; i < a_l; i++)
        prm[i] = my_strdup(ARGS[i]);
}

static void assign_parameter(char **args_emi, minishell_t *minishell)
{
    int args_len = 1;
    char **param = malloc(sizeof(char *) * 1064);

    for (int i = 0; i < 1064; i++)
        param[i] = NULL;
    param[0] = my_strdup(args_emi[0]);
    for (; ARGS[args_len] != NULL; args_len++);
    for (int m = 1; m <= count_param(args_emi); m++) {
        if (args_len > count_param(args_emi)) {
            assign_parameter_bis(m, args_len, minishell, param);
            break;
        }
        if (args_len == m)
            break;
        param[m] = my_strdup(ARGS[m]);
    }
    emi_exec_alias_com(minishell, param);
    free_array(param);
}

int alias_with_param(minishell_t *minishell, char **args_emi, alias_t *tmp)
{
    args_emi = my_str_to_word_array(tmp->command, " '\t");
    if (count_param(args_emi) == 0)
        return 1;
    for (int k = 1; args_emi[k + 1] != NULL; k++) {
        for (int l = 0; args_emi[k][l] != '\0'; l++) {
            write_param(k, &l, args_emi);
        }
        write(1, " ", 1);
    }
    assign_parameter(args_emi, minishell);
    return 0;
}

/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** analyse.c
*/

#include "../../include/my.h"

int analyse_status(int status)
{
    if (WIFSIGNALED(status) && WCOREDUMP(status)) {
        my_puterror("Segmentation fault (core dumped)\n");
        return 84;
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == 8 && WCOREDUMP(status)) {
        my_puterror("Floating point exception (core dumped)\n");
        return 136;
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == 8) {
        my_puterror("Floating point exception\n");
        exit(136);
    }
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status)) {
        my_puterror("Segmentation fault\n");
        exit(1);
    }
    return 0;
}

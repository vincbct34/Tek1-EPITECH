/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** logical_application.c
*/

#include "crocus.h"

int check_flags(int ac, char **av)
{
    if (av[1][0] != '-') {
        if (fprintf(stderr, "First argument is not a flag.\n") <= 0)
            return 84;
        return 1;
    }
    if (ac == 5 && av[3][0] != '-') {
        if (fprintf(stderr, "Third argument is not a flag.\n") <= 0)
            return 84;
        return 1;
    }
    return 0;
}

int choose_method(stumper_t *stumper, int ac, char **av)
{
    if (strcmp(av[1], "-s") == 0) {
        stumper->flag_s = true;
        stumper->str = dup_arg(av[2]);
    } else if (strcmp(av[1], "-n") == 0) {
        stumper->flag_n = true;
        stumper->argument = check_and_dup_arg(av[2]);
    } else
        return return_error(1);
    if (ac == 3)
        return stumper->flag_n == true ? false : true;
    if (strcmp(av[3], "-s") == 0) {
        stumper->flag_s = true;
        stumper->str = dup_arg(av[4]);
    } else if (strcmp(av[3], "-n") == 0) {
        stumper->flag_n = true;
        stumper->argument = check_and_dup_arg(av[4]);
    } else
        return return_error(3);
    return 0;
}

static int which_to_display_bis(int line, int i_letter, char a)
{
    if (i_letter == 5)
        return draw_5(line, a);
    if (i_letter == 6)
        return draw_6(line, a);
    if (i_letter == 7)
        return draw_7(line, a);
    if (i_letter == 8)
        return draw_8(line, a);
    if (i_letter == 9)
        return draw_9(line, a);
    return 84;
}

static int which_to_display(int line, char letter, char a)
{
    int i_letter = letter - 48;

    if (i_letter == 0)
        return draw_0(line, a);
    if (i_letter == 1)
        return draw_1(line, a);
    if (i_letter == 2)
        return draw_2(line, a);
    if (i_letter == 3)
        return draw_3(line, a);
    if (i_letter == 4)
        return draw_4(line, a);
    return which_to_display_bis(line, i_letter, a);
}

static char which_char(stumper_t *stumper, char letter)
{
    int char_a = 0;
    int i_letter = letter - 48;
    int len;

    if (stumper->flag_s == false)
        return '0';
    len = strlen(stumper->str);
    for (int i = 0; i < i_letter; i++) {
        if (char_a + 1 > len) {
            char_a = 0;
            continue;
        }
        char_a++;
    }
    if (char_a + 1 > len)
        char_a = 0;
    return stumper->str[char_a];
}

int logical_application_bis(stumper_t *stumper, int line)
{
    int len = 0;
    char a;

    for (int i = 0; stumper->argument[i] != '\0'; i++) {
        a = which_char(stumper, stumper->argument[i]);
        which_to_display(line, stumper->argument[i], a);
        len = (int)strlen(stumper->argument) - 1;
        if (i != len && printf(" ") == 0)
            exit_all(stumper);
    }
    return 0;
}

void free_remaining_elements(stumper_t *stumper)
{
    if (stumper->str != NULL)
        free(stumper->str);
    free(stumper);
}

int logical_application(stumper_t *stumper)
{
    for (int i = 1; i < 6; i++) {
        if (logical_application_bis(stumper, i) == 84)
            exit_all(stumper);
        if (printf("\n") <= 0)
            exit_all(stumper);
    }
    free_remaining_elements(stumper);
    return 0;
}

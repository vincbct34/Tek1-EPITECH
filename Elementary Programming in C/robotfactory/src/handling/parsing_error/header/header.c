/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** header.c
*/

#include "robot.h"

static int check_quotes(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            count++;
    }
    if (count % 2 != 0)
        return 84;
    return 0;
}

static int check_char_after_quotes(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t'
            && str[i] != '\n' && str[i] != '\r') {
            return 84;
        }
    }
    return 0;
}

static int process_name_directive_bis(int name_length)
{
    if (name_length > PROG_NAME_LENGTH)
        return 84;
    if (name_length == 0)
        return 84;
    return 0;
}

static int process_name_directive(char *directive, all_t *all)
{
    char const *start_quotes = my_strchr(directive, '"');
    char const *end_quotes = my_strrchr(directive, '"');
    int name_length = end_quotes - start_quotes - 1;

    if (check_quotes(directive) == 84)
        return 84;
    if (start_quotes != NULL && end_quotes != NULL
        && start_quotes + 1 < end_quotes) {
        if (check_char_after_quotes(end_quotes + 1) == 84)
            return 84;
        all->status->name = true;
        if (process_name_directive_bis(name_length) == 84)
            return 84;
        my_strncpy(all->header->prog_name, start_quotes + 1,
            end_quotes - start_quotes - 1);
        all->header->prog_name[name_length] = '\0';
    } else
        return 84;
    return 0;
}

static int check_name_bis(char **array, all_t *all, int i)
{
    if (my_strstr(array[i], ".name") != NULL) {
        if (all->status->name) {
            return 84;
        }
        return process_name_directive(array[i], all);
    }
    return 0;
}

static int check_name(char **array, all_t *all)
{
    all->status->name = false;
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][0] != '#') {
            return (check_name_bis(array, all, i) == 84) ? 84 : 0;
        }
    }
    if (!all->status->name) {
        return 84;
    }
    return 0;
}

static int process_comment_directive(char *directive, all_t *all)
{
    char const *start_quotes = my_strchr(directive, '"');
    char const *end_quotes = my_strrchr(directive, '"');
    int comment_length;

    if (!start_quotes || !end_quotes || start_quotes == end_quotes)
        return 84;
    comment_length = end_quotes - start_quotes - 1;
    if (check_quotes(directive) == 84)
        return 84;
    if (check_char_after_quotes(end_quotes + 1) == 84)
        return 84;
    if (comment_length > COMMENT_LENGTH)
        return 84;
    all->status->comment = true;
    my_strncpy(all->header->comment, start_quotes + 1, comment_length);
    all->header->comment[comment_length] = '\0';
    return 0;
}

static int process_comment_line(char *line, all_t *all)
{
    if (line[0] != '#' && my_strstr(line, ".comment") != NULL) {
        if (all->status->comment)
            return 84;
        if (process_comment_directive(line, all) == 84) {
            return 84;
        }
    }
    return 0;
}

static int check_comment(char **array, all_t *all)
{
    all->status->comment = false;
    for (int i = 0; array[i] != NULL; i++) {
        if (process_comment_line(array[i], all) == 84)
            return 84;
    }
    if (!all->status->comment)
        return 84;
    return 0;
}

int handling_parsing_error(char **array, all_t *all)
{
    all->header = malloc(sizeof(header_t));
    all->status = malloc(sizeof(status_t));
    all->header->magic = COREWAR_EXEC_MAGIC;
    if (check_name(array, all) == 84)
        return 84;
    if (check_comment(array, all) == 84)
        return 84;
    return 0;
}

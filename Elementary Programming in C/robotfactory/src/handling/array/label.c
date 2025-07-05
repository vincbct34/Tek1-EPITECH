/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** label.c
*/

#include "robot.h"

static int is_label_char(char c)
{
    return (my_strchr(LABEL_CHARS, c) != NULL);
}

static void remove_leading_spaces(char *str)
{
    int i;
    int leading_spaces = 0;

    if (str == NULL || *str == '\0') {
        return;
    }
    while (str[leading_spaces] == ' ' || str[leading_spaces] == '\t') {
        leading_spaces++;
    }
    if (leading_spaces > 0) {
        for (i = 0; str[i + leading_spaces] != '\0'; ++i) {
            str[i] = str[i + leading_spaces];
        }
        str[i] = '\0';
    }
}

char *find_label_end(char *ptr)
{
    while (*ptr != '\0' && *ptr != ' ' && *ptr != '\t' && *ptr != ':') {
        ptr++;
    }
    return ptr;
}

void remove_label_prefix(char *line, char *ptr)
{
    char *dest;

    if (*ptr == ':') {
        dest = line;
        ptr++;
        while (*ptr != '\0') {
            *dest = *ptr;
            dest++;
            ptr++;
        }
        *dest = '\0';
    }
}

void remove_label_lines(char **lines, int num_lines)
{
    char *line;
    char *ptr;

    for (int i = 0; i < num_lines; i++) {
        line = lines[i];
        ptr = line;
        while (*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }
        if (*ptr != '\0' && is_label_char(*ptr)) {
            ptr = find_label_end(ptr);
            remove_label_prefix(line, ptr);
        }
        remove_leading_spaces(line);
    }
}

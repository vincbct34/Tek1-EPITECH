/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** lib.c
*/

#include "../../include/my.h"

bool is_delim(char c, char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return true;
    return false;
}

static int count_words(char *str, char *delim)
{
    quote_info_t info = {false, '\0', delim, 0, 0};

    for (int i = 0; str[i]; i++)
        handle_char(str[i], &info);
    if (!is_delim(str[0], delim))
        info.count++;
    return info.count;
}

static char *check_tab(char *token)
{
    while (*token == ' ' || *token == '\t')
        token++;
    return token;
}

static char **my_str_to_word_array_bis(char **tab, int i)
{
    tab[i] = NULL;
    return tab;
}

char *extract_token(char *str, int *index, char *delim)
{
    static char buffer[4096];
    token_info_t info = {0, false, '\0', buffer};

    while (str[*index] && (info.in_quotes || !is_delim(str[*index], delim))) {
        handle_quoted_char(str[*index], &info);
        (*index)++;
    }
    buffer[info.buf_idx] = '\0';
    while (str[*index] && is_delim(str[*index], delim))
        (*index)++;
    return buffer;
}

static bool check_balanced_quotes(char *str)
{
    int single_quotes = 0;
    int double_quotes = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\'))
            single_quotes++;
        if (str[i] == '"' && (i == 0 || str[i - 1] != '\\'))
            double_quotes++;
    }
    if (single_quotes % 2 != 0) {
        fprintf(stderr, "Unmatched '''.\n");
        return false;
    }
    if (double_quotes % 2 != 0) {
        fprintf(stderr, "Unmatched '\"'.\n");
        return false;
    }
    return true;
}

char **create_empty_tab(void)
{
    char **empty_tab = malloc(sizeof(char *));

    if (empty_tab != NULL)
        empty_tab[0] = NULL;
    return empty_tab;
}

int fill_tokens(char **tab, char *str, char *separator)
{
    int i = 0;
    int index = 0;
    char *token;

    while (str[index] && is_delim(str[index], separator))
        index++;
    while (str[index]) {
        token = my_strdup(extract_token(str, &index, separator));
        token = check_tab(token);
        tab[i] = token;
        if (tab[i] == NULL)
            return -1;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char *str, char *separator)
{
    char **tab;
    int num_tokens;

    if (!check_balanced_quotes(str))
        return create_empty_tab();
    tab = malloc(sizeof(char *) * (count_words(str, separator) + 1));
    if (tab == NULL)
        return NULL;
    num_tokens = fill_tokens(tab, str, separator);
    if (num_tokens == -1) {
        free(tab);
        return NULL;
    }
    return my_str_to_word_array_bis(tab, num_tokens);
}

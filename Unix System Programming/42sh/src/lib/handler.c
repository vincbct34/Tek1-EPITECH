/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** lib.c
*/

#include "../../include/my.h"

void handle_quotes(char c, quote_info_t *info)
{
    if ((c == '"' || c == '\'') && !info->in_quotes) {
        info->in_quotes = true;
        info->quote_char = c;
    } else if (c == info->quote_char && info->in_quotes)
        info->in_quotes = false;
}

void handle_token_count(char c, quote_info_t *info)
{
    if (!info->in_quotes && is_delim(c, info->delim) &&
    (info->prev_index == 0 || !is_delim(c - 1, info->delim)))
        info->count++;
}

void handle_char(char c, quote_info_t *info)
{
    handle_quotes(c, info);
    handle_token_count(c, info);
    info->prev_index++;
}

void handle_quoted_char(char c, token_info_t *info)
{
    if ((c == '"' || c == '\'') && !info->in_quotes) {
        info->in_quotes = true;
        info->quote_char = c;
    } else if (c == info->quote_char && info->in_quotes) {
        info->in_quotes = false;
    } else {
        info->buffer[info->buf_idx] = c;
        info->buf_idx++;
    }
}

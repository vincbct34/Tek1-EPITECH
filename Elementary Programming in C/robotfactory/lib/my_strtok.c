/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strtok.c
*/

#include "robot.h"

static char *allocate_word(const char *start, const char *end)
{
    int word_length = end - start;
    char *word = (char *)malloc((word_length + 1) * sizeof(char));

    my_strncpy(word, start, word_length);
    word[word_length] = '\0';
    return word;
}

static void add_word(char **words, int *word_count,
    const char *start, const char *end)
{
    words[(*word_count)] = allocate_word(start, end);
    (*word_count)++;
}

static const char *find_word_start(const char *str, const char *delim)
{
    const char *start = str;

    while (*start != '\0' && my_strchr(delim, *start) != NULL) {
        start++;
    }
    return start;
}

static const char *find_word_end(const char *str, const char *delim)
{
    const char *end = str;

    while (*end != '\0' && my_strchr(delim, *end) == NULL) {
        end++;
    }
    return end;
}

static char **split_string_bis(char **words, int word_count)
{
    if (word_count % 2 == 0) {
        words = (char **)realloc(words, sizeof(char *) * (word_count + 2));
    }
    return words;
}

char **split_string(const char *str, const char *delim, int *num_words)
{
    const char *token_start = str;
    const char *token_end = str;
    int word_count = 0;
    char **words = (char **)malloc(sizeof(char *) * (2));

    while (*token_end != '\0') {
        token_start = find_word_start(token_end, delim);
        token_end = find_word_end(token_start, delim);
        if (token_end != token_start) {
            add_word(words, &word_count, token_start, token_end);
            words = split_string_bis(words, word_count);
        }
    }
    if (word_count == 0) {
        words[word_count + 1] = NULL;
    }
    words[word_count] = NULL;
    (*num_words) = word_count;
    return words;
}

char **my_strtok(const char *str, const char *delim)
{
    int num_words;

    return split_string(str, delim, &num_words);
}

/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** my_str_to_word_array
*/

#include "lib.h"

static int get_word_c(char *str, char separator)
{
    int word_count = 0;

    for (int i = 0; str[i] && str[i] != '\0'; i++)
        if (str[i] == separator)
            word_count++;
    word_count++;
    return word_count;
}

char **my_str_to_word_array(char *str, char separator)
{
    int word_count;
    char **result;
    int word_i = 0;
    int start_index = 0;

    word_count = get_word_c(str, separator);
    result = malloc((word_count + 1) * sizeof(char *));
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == separator) {
            result[word_i] = malloc((i - start_index + 1) * sizeof(char));
            my_strncpy(result[word_i], &str[start_index], i - start_index);
            result[word_i][i - start_index] = '\0';
            word_i++;
            start_index = i + 1;
        }
    result[word_i] = malloc((my_strlen(&str[start_index]) + 1) * sizeof(char));
    my_strcpy(result[word_i], &str[start_index]);
    result[word_count] = NULL;
    return result;
}

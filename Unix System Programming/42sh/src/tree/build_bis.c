/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** build_bis
*/

#include "../../include/my.h"

static int update_min_priority(int priority, int minPriority)
{
    if (minPriority == -1 || priority < minPriority) {
        return priority;
    }
    return minPriority;
}

static void update_delimiter_index(int *delimiterIndex, int tmpIndex)
{
    *delimiterIndex = tmpIndex;
}

static void update_delimiter(char **delimiter, char *currentDelimiter)
{
    *delimiter = currentDelimiter;
}

int find_main_delimiter(char *expr, int *delimiterIndex, char **delimiter)
{
    char *delimiters[] = {">", ">>", "<", "<<", "|", "&&", "||"};
    int minPriority = -1;
    char *tmp;

    *delimiterIndex = -1;
    for (size_t priority = 0; priority < sizeof(delimiters) /
        sizeof(delimiters[0]); priority++) {
        tmp = expr;
        while ((my_strstr(tmp, delimiters[priority])) != NULL) {
            minPriority = update_min_priority(priority, minPriority);
            update_delimiter_index(delimiterIndex, tmp - expr);
            update_delimiter(delimiter, delimiters[priority]);
            tmp++;
        }
    }
    return (minPriority != -1);
}

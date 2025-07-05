/*
** EPITECH PROJECT, 2023
** my_params_to_array
** File description:
** Task03
*/

#include <stdlib.h>
#include "my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *result;
    int i = 0;

    result = malloc(sizeof(struct info_param) * ac);
    while (i < ac) {
        result[i].length = my_strlen(av[i]);
        result[i].str = av[i];
        result[i].copy = my_strdup(av[i]);
        result[i].word_array = my_str_to_word_array(concat_params(ac, av));
        i++;
    }
    return (result);
}

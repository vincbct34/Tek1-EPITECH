/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** verif_params.c
*/

#include "robot.h"

static char *remove_trainling_bis(char *param)
{
    int len = my_strlen(param);

    if (len > 0 && param[len - 1] == ',') {
        param[len - 1] = '\0';
    }
    return param;
}

void remove_trailing_commas(char ***output)
{
    for (int i = 0; output[i] != NULL; i++) {
        for (int j = 1; output[i][j] != NULL; j++) {
            output[i][j] = remove_trainling_bis(output[i][j]);
        }
    }
}

bool is_a_register(char *str)
{
    if (str[0] == 'r' && my_str_isnum(str + 1) && my_getnbr(str + 1) > 0
        && my_getnbr(str + 1) <= REG_NUMBER)
        return (true);
    return (false);
}

bool is_a_direct(char *str)
{
    if (str[0] == DIRECT_CHAR && (my_str_isnum(str + 1) ||
        str[1] == LABEL_CHAR))
        return (true);
    return (false);
}

bool is_an_indirect(char *str)
{
    if (my_str_isnum(str) || (str[0] == LABEL_CHAR && my_str_isalpha(str + 1)))
        return (true);
    return (false);
}

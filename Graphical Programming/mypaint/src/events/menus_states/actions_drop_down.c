/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** actions_drop_down.c
*/

#include "paint.h"

void call_action_menu(char *name, Paint *paint)
{
    if (my_strcmp(name, "New") == 0)
        new_action(paint);
    if (my_strcmp(name, "Open") == 0)
        listen_for_input_open(paint);
    if (my_strcmp(name, "Save") == 0)
        listen_for_input_save(paint);
    if (my_strcmp(name, "Undo") == 0)
        undo_last_action(paint);
    if (my_strcmp(name, "About") == 0)
        about_action();
    if (my_strcmp(name, "Help") == 0)
        help_action();
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** ctrl_z
*/

#include "paint.h"

void undo_last_action(Paint* paint)
{
    ImageHistory* toRemove;

    if (paint->History == NULL)
        return;
    toRemove = paint->History;
    paint->History = paint->History->next;
    sfImage_destroy(paint->Area->image);
    paint->Area->image = sfImage_copy(toRemove->image);
    sfImage_destroy(toRemove->image);
    free(toRemove);
}

void save_image_state(Paint* paint)
{
    ImageHistory* newHistory = malloc(sizeof(ImageHistory));

    if (!newHistory)
        return;
    if (paint->Mouse->mouse_in_area == sfFalse)
        return;
    newHistory->image = sfImage_copy(paint->Area->image);
    newHistory->next = paint->History;
    paint->History = newHistory;
}

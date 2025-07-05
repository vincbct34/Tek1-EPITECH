/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** area
*/

#include "paint.h"

sfBool check_if_is_in_area(sfVector2i pos)
{
    if (pos.x < 585 || pos.x > 1335)
        return (sfFalse);
    if (pos.y < 265 || pos.y > 1015)
        return (sfFalse);
    return (sfTrue);
}

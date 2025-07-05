/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** new_file.c
*/

#include "paint.h"

void new_action(Paint *paint)
{
    for (int i = 0; i < 750; i++)
        for (int j = 0; j < 750; j++)
            sfImage_setPixel(AREA->image, i, j,
                sfColor_fromRGB(255, 255, 255));
}

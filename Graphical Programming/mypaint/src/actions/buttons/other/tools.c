/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** tools
*/

#include "paint.h"

void tools(Paint *paint)
{
    if (paint->Mode == MODE_PENCIL){
        check_drawing_mode(paint, sfRed);
    }
    if (paint->Mode == MODE_ERASER){
        check_drawing_mode(paint, sfWhite);
    }
    if (paint->Mode == MODE_PIPETTE){
        check_drawing_mode(paint, sfBlack);
    }
}

void mode_tools(Paint *paint, Buttons *btn)
{
    if (my_strcmp(btn->name, "pencil") == 0) {
        paint->Mode = MODE_PENCIL;
    }
    if (my_strcmp(btn->name, "eraser") == 0) {
        paint->Mode = MODE_ERASER;
    }
    if (my_strcmp(btn->name, "pipette") == 0) {
        paint->Mode = MODE_PIPETTE;
    }
}

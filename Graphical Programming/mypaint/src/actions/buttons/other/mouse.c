/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** mouse
*/

#include "paint.h"

void update_and_check_mouse(Paint *paint)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(paint->window);
    sfBool isMouseInDrawingArea = check_if_is_in_area(mousePos);

    sfRenderWindow_setMouseCursorVisible(paint->window, !isMouseInDrawingArea);
    paint->Mouse->mouse_in_area = isMouseInDrawingArea;
}

void draw_mouse_circle(Paint *paint)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2f mousePosF = {(float)mousePos.x, (float)mousePos.y};

    paint->cursorCircle = sfCircleShape_create();
    sfCircleShape_setRadius(paint->cursorCircle, paint->Mouse->thickness);
    sfCircleShape_setFillColor(paint->cursorCircle, sfTransparent);
    sfCircleShape_setOutlineColor(paint->cursorCircle, sfBlack);
    sfCircleShape_setOutlineThickness(paint->cursorCircle, 1);
    sfCircleShape_setPosition(paint->cursorCircle,
        (sfVector2f){mousePosF.x - paint->Mouse->thickness,
            mousePosF.y - paint->Mouse->thickness});
    sfRenderWindow_drawCircleShape(paint->window, paint->cursorCircle, NULL);
}

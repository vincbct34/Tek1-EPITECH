/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** init_events.c
*/

#include "paint.h"

static void onmousebuttondown(Paint *paint, sfEvent event,
    sfVector2f imageStartPos)
{
    save_image_state(paint);
    paint->Mouse->is_mouse_clicked = sfTrue;
    paint->Mouse->mouse_pos = (sfVector2f){
        event.mouseButton.x - imageStartPos.x,
        event.mouseButton.y - imageStartPos.y
    };
}

static void onmousebuttonup(Paint *paint)
{
    paint->Mouse->is_mouse_clicked = sfFalse;
}

static void onmousemove(Paint *paint, sfVector2f imageStartPos,
    sfColor color)
{
    sfVector2f currentPos;

    if (!paint->Mouse->is_mouse_clicked)
        return;
    currentPos = (sfVector2f){
        paint->event.mouseMove.x - imageStartPos.x,
        paint->event.mouseMove.y - imageStartPos.y
    };
    if (check_if_is_in_area((sfVector2i){
        (int)currentPos.x + (int)imageStartPos.x,
        (int)currentPos.y + (int)imageStartPos.y
    })) {
        draw_line_on_image(paint, paint->Mouse->mouse_pos,
            currentPos, color);
        paint->Mouse->mouse_pos = currentPos;
    }
}

void handle_mouse_events(Paint *paint, sfColor color)
{
    sfVector2f imageStartPos = {585, 265};

    switch (paint->event.type) {
        case sfEvtMouseButtonPressed:
            if (paint->event.mouseButton.button == sfMouseLeft) {
                onmousebuttondown(paint, paint->event, imageStartPos);
            }
            break;
        case sfEvtMouseButtonReleased:
            if (paint->event.mouseButton.button == sfMouseLeft) {
                onmousebuttonup(paint);
            }
            break;
        case sfEvtMouseMoved:
            onmousemove(paint, imageStartPos, color);
            break;
        default:
            break;
    }
}

static void apply_drop_down_bis(Drop_down *currentItem, sfFloatRect rect,
    sfVector2f click, Paint *paint)
{
    if (currentItem->rect != NULL) {
        rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
        click = (sfVector2f){paint->event.mouseButton.x,
            paint->event.mouseButton.y};
        if (sfFloatRect_contains(&rect, click.x, click.y))
            call_action_menu(currentItem->name, paint);
    }
}

void apply_drop_down_actions(Drop_down *drop_down, Paint *paint)
{
    Drop_down *currentItem = drop_down;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        apply_drop_down_bis(currentItem, rect, click, paint);
        currentItem = currentItem->next;
    }
}

static void events_menus(Paint *paint)
{
    if (is_hover_menu(paint) != sfFalse)
        apply_hover_menu(paint);
    if (is_not_hover_menu(paint) != sfFalse)
        apply_not_hover_menu(paint);
    if (paint->event.type == sfEvtMouseButtonPressed)
        if (is_clicked_menu(paint) != sfFalse)
            apply_click_menu(paint);
    if (paint->event.type == sfEvtMouseButtonReleased)
        if (is_release_menu(paint) != sfFalse)
            apply_release_menu(paint);
    if (paint->event.type == sfEvtMouseButtonPressed)
        if (MENU->is_open == sfTrue)
            apply_drop_down_actions(MENU->drop_down, paint);
}

static void events_buttons(Paint *paint)
{
    if (is_hover_button(paint) != sfFalse)
        apply_hover_button(paint);
    if (is_not_hover_button(paint) != sfFalse)
        apply_not_hover_button(paint);
    if (paint->event.type == sfEvtMouseButtonPressed)
        if (is_clicked_button(paint) != sfFalse)
            apply_click_button(paint);
    if (paint->event.type == sfEvtMouseButtonReleased)
        if (is_release_button(paint) != sfFalse)
            apply_release_button(paint);
    if (paint->event.type == sfEvtMouseButtonPressed)
        if (BUTTON->is_active == sfTrue)
            apply_button_actions(paint);
}

void events_handling(Paint *paint)
{
    if (paint->event.type == sfEvtClosed)
        sfRenderWindow_close(paint->window);
    if (paint->event.type == sfEvtKeyPressed
        && paint->event.key.code == sfKeyZ && paint->event.key.control) {
        undo_last_action(paint);
    }
    events_menus(paint);
    events_buttons(paint);
}

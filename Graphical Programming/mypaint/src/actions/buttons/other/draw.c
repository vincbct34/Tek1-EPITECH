/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** draw
*/

#include "paint.h"

void draw_thick_pixel_bis(sfImage* image, sfColor color, int x, int y)
{
    if (x >= 0 && x < (int)sfImage_getSize(image).x &&
        y >= 0 && y < (int)sfImage_getSize(image).y) {
        sfImage_setPixel(image, x, y, color);
    }
}

void draw_thick_pixel(sfImage* image, sfVector2f point,
    sfColor color, int thickness)
{
    int start_x = (int)(point.x - thickness / 2);
    int start_y = (int)(point.y - thickness / 2);

    for (int y = start_y; y < start_y + thickness; ++y) {
        for (int x = start_x; x < start_x + thickness; ++x) {
            draw_thick_pixel_bis(image, color, x, y);
        }
    }
}

static void init_draw_context(Draw_context *context, sfVector2f from,
    sfVector2f to)
{
    context->dx = abs((int)to.x - (int)from.x);
    context->sx = from.x < to.x ? 1 : -1;
    context->dy = -abs((int)to.y - (int)from.y);
    context->sy = from.y < to.y ? 1 : -1;
    context->err = context->dx + context->dy;
}

void draw_line_on_image(Paint *paint, sfVector2f from,
    sfVector2f to, sfColor color)
{
    Draw_context context;

    init_draw_context(&context, from, to);
    while (true) {
        draw_thick_pixel(paint->Area->image, from, color,
            paint->Mouse->thickness);
        if ((int)from.x == (int)to.x && (int)from.y == (int)to.y)
            break;
        context.e2 = 2 * context.err;
        if (context.e2 >= context.dy) {
            context.err += context.dy;
            from.x += context.sx;
        }
        if (context.e2 <= context.dx) {
            context.err += context.dx;
            from.y += context.sy;
        }
    }
}

void check_drawing_mode(Paint *paint, sfColor color)
{
    if (paint->Mode == MODE_PENCIL) {
        if (paint->Mouse->has_selected_color)
            color = paint->Mouse->selected_color;
        handle_mouse_events(paint, color);
        update_and_check_mouse(paint);
    }
    if (paint->Mode == MODE_ERASER) {
        handle_mouse_events(paint, color);
        update_and_check_mouse(paint);
    }
    if (paint->Mode == MODE_PIPETTE) {
        handle_mouse_events(paint, color);
        update_and_check_mouse(paint);
    }
}

void display_image(sfRenderWindow *window, sfImage *image)
{
    sfTexture* texture = sfTexture_createFromImage(image, NULL);
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){585, 265});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

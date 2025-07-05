/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include "usage.h"
#include "my_radar.h"
#include "draw.h"
#include "events.h"
#include "utils.h"
#include "collisions.h"
#include "my.h"
#include "sim_fonts.h"

static void draw_text(sfRenderWindow *window, char *str, sfVector2f pos,
    unsigned int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void draw_digit(sfRenderWindow *window, char digit,
    sfVector2f pos, unsigned int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);
    char str[2] = {digit, '\0'};

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void draw_timer(sfRenderWindow *window, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    uint seconds = sfTime_asSeconds(time);
    uint minutes = seconds / 60;
    uint hours = minutes / 60;

    minutes -= hours * 60;
    seconds -= minutes * 60 + hours * 3600;
    draw_digit(window, '0' + (hours / 10), (sfVector2f){1770.0f, 10.0f}, 20);
    draw_digit(window, '0' + (hours % 10), (sfVector2f){1785.0f, 10.0f}, 20);
    draw_text(window, "h", (sfVector2f){1800.0f, 10.0f}, 20);
    draw_digit(window, '0' + (minutes / 10), (sfVector2f){1820.0f, 10.0f},
        20);
    draw_digit(window, '0' + (minutes % 10), (sfVector2f){1835.0f, 10.0f},
        20);
    draw_text(window, "m", (sfVector2f){1850.0f, 10.0f}, 20);
    draw_digit(window, '0' + (seconds / 10), (sfVector2f){1870.0f, 10.0f},
        20);
    draw_digit(window, '0' + (seconds % 10), (sfVector2f){1885.0f, 10.0f},
        20);
    draw_text(window, "s", (sfVector2f){1900.0f, 10.0f}, 20);
}

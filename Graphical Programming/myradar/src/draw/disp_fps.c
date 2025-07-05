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

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        my_putstr("FPS: ");
        my_putnbr(fps);
        my_putchar('\n');
        fps = 0;
        sfClock_restart(clock);
    } else
        fps ++;
}

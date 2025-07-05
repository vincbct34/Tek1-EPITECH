/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <SFML/Graphics.h>
#include "events.h"
#include "draw.h"
#include "sim.h"
#include <stdbool.h>

void sim_events(sfRenderWindow *render, states_t *state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(render, &event)) {
        quit_win(&event, render);
        if (event.type == sfEvtKeyReleased)
            disp_options(&event, state);
    }
}

void quit_win(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

void disp_options(sfEvent *event, states_t *states)
{
    switch (event->key.code) {
    case sfKeyL:
        states->show_hitbox = (states->show_hitbox) ? false : true;
        break;
    case sfKeyS:
        states->show_sprites = (states->show_sprites) ? false : true;
        break;
    default:
        break;
    }
}

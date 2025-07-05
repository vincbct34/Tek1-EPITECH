/*
** EPITECH PROJECT, 2023
** events.c
** File description:
** Events needed for the my_hunter project
*/

#include "../header/structure.h"
#include "../header/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

static void play_pressed(global_t *all)
{
    if (all->parameters.event.mouseButton.button == sfMouseLeft) {
        if (XPOS >= 800 && XPOS <= 1100 && YPOS >= 540 && YPOS <= 710)
            all->status = 1;
    }
}

static void settings_pressed(global_t *all)
{
    if (all->parameters.event.mouseButton.button == sfMouseLeft)
        if (XPOS >= 1690 && XPOS <= 1831 && YPOS >= 180 && YPOS <= 319)
            all->status = 2;
}

static void quit_pressed(global_t *all)
{
    if (all->parameters.event.mouseButton.button == sfMouseLeft) {
        if (XPOS >= 1680 && XPOS <= 1841 && YPOS >= 370 && YPOS <= 490)
            sfRenderWindow_close(WIN);
    }
}

static void score_pressed(global_t *all)
{
    if (all->parameters.event.mouseButton.button == sfMouseLeft) {
        if (XPOS >= 1700 && XPOS <= 1824 && YPOS >= 30 && YPOS <= 153)
            all->status = 3;
    }
}

static void kill_birds(global_t *all)
{
    if (all->parameters.event.type == sfEvtMouseButtonPressed)
        if (all->parameters.event.mouseButton.button == sfMouseLeft) {
            sfMusic_play(SHOOTMUSIC);
            kill_bird(all);
            kill_second_bird(all);
            kill_third_bird(all);
        }
}

void events(global_t *all)
{
    if (all->parameters.event.type == sfEvtClosed)
        sfRenderWindow_close(WIN);
    if (all->parameters.event.type == sfEvtMouseButtonPressed) {
        play_pressed(all);
        settings_pressed(all);
        quit_pressed(all);
        score_pressed(all);
    }
    if (all->parameters.event.type == sfEvtMouseMoved) {
        CURSORX = all->parameters.event.mouseMove.x - 100;
        CURSORY = all->parameters.event.mouseMove.y - 60;
        sfSprite_setPosition(SHOOTERSPRITE, (sfVector2f){CURSORX, CURSORY});
    }
    kill_birds(all);
    if (all->parameters.event.type == sfEvtKeyPressed)
        if (all->parameters.event.key.code == sfKeyEscape) {
            all->status = 0;
            sfMusic_play(MUSIC);
        }
}

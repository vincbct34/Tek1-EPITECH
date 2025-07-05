/*
** EPITECH PROJECT, 2023
** menu_sprites.c
** File description:
** Menu sprites of the project my_hunter
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

void titlesprite(global_t *all)
{
    all->images[1].texture = sfTexture_createFromFile(TITLE, NULL);
    TITLESPRITE = sfSprite_create();
    sfSprite_setTexture(TITLESPRITE, all->images[1].texture, sfTrue);
    sfSprite_setScale(TITLESPRITE, (sfVector2f){1, 1});
    sfSprite_setPosition(TITLESPRITE, (sfVector2f){550, 100});
}

void playsprite(global_t *all)
{
    all->images[2].texture = sfTexture_createFromFile(PLAY, NULL);
    PLAYSPRITE = sfSprite_create();
    sfSprite_setTexture(PLAYSPRITE, all->images[2].texture, sfTrue);
    sfSprite_setScale(PLAYSPRITE, (sfVector2f){1.2, 1.2});
    sfSprite_setPosition(PLAYSPRITE, (sfVector2f){800, 540});
}

void settingsprite(global_t *all)
{
    all->images[3].texture = sfTexture_createFromFile(SETTING, NULL);
    SETTINGSPRITE = sfSprite_create();
    sfSprite_setTexture(SETTINGSPRITE, all->images[3].texture, sfTrue);
    sfSprite_setScale(SETTINGSPRITE, (sfVector2f){2.1, 2.1});
    sfSprite_setPosition(SETTINGSPRITE, (sfVector2f){1690, 180});
}

void quitsprite(global_t *all)
{
    all->images[4].texture = sfTexture_createFromFile(QUIT, NULL);
    QUITSPRITE = sfSprite_create();
    sfSprite_setTexture(QUITSPRITE, all->images[4].texture, sfTrue);
    sfSprite_setScale(QUITSPRITE, (sfVector2f){1.8, 1.8});
    sfSprite_setPosition(QUITSPRITE, (sfVector2f){1680, 370});
}

void scoresprite(global_t *all)
{
    all->images[5].texture = sfTexture_createFromFile(SCORE, NULL);
    SCORESPRITE = sfSprite_create();
    sfSprite_setTexture(SCORESPRITE, all->images[5].texture, sfTrue);
    sfSprite_setScale(SCORESPRITE, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(SCORESPRITE, (sfVector2f){1700, 30});
}

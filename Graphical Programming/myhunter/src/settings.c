/*
** EPITECH PROJECT, 2023
** settings_sprite.c
** File description:
** Settings sprite of the my_hunter project
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

void set_sprite(global_t *all)
{
    all->images[10].texture = sfTexture_createFromFile(SET, NULL);
    SETSPRITE = sfSprite_create();
    sfSprite_setTexture(SETSPRITE, all->images[10].texture, sfTrue);
    sfSprite_setPosition(SETSPRITE, (sfVector2f){420, 100});
    sfSprite_setScale(SETSPRITE, (sfVector2f){2, 2});
}

void troll_sprite(global_t *all)
{
    all->images[11].texture = sfTexture_createFromFile(TROLL, NULL);
    TROLLSPRITE = sfSprite_create();
    sfSprite_setTexture(TROLLSPRITE, all->images[11].texture, sfTrue);
    sfSprite_setPosition(TROLLSPRITE, (sfVector2f){450, 250});
    sfSprite_setScale(TROLLSPRITE, (sfVector2f){1.5, 1.5});
}

/*
** EPITECH PROJECT, 2023
** score.c
** File description:
** Score of the my_hunter project
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

void score_sprite(global_t *all)
{
    all->images[12].texture = sfTexture_createFromFile(SET, NULL);
    SETTINGSPRITE = sfSprite_create();
    sfSprite_setTexture(SETTINGSPRITE, all->images[12].texture, sfTrue);
    sfSprite_setPosition(SETTINGSPRITE, (sfVector2f){420, 100});
    sfSprite_setScale(SETTINGSPRITE, (sfVector2f){2, 2});
}

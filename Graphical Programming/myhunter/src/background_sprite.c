/*
** EPITECH PROJECT, 2023
** background_sprite.c
** File description:
** Background' sprites of the project my_hunter
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

void background_sprite(global_t *all)
{
    all->images[0].texture = sfTexture_createFromFile(BACKGROUND, NULL);
    all->images[0].sprite = sfSprite_create();
    sfSprite_setTexture(all->images[0].sprite, all->images[0].texture, sfTrue);
    sfSprite_setScale(all->images[0].sprite, (sfVector2f){0.8, 0.8});
}

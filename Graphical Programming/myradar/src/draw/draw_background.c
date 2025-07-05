/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <SFML/Graphics.h>

void draw_back(sfRenderWindow *window, sfSprite *background)
{
    sfRenderWindow_drawSprite(window, background, NULL);
}

/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy_menu
*/

#include "my_rpg.h"

void destroy_main_menu(main_menu_t *main_menu)
{
    sfTexture_destroy(main_menu->back_texture);
    sfSprite_destroy(main_menu->background);
    sfTexture_destroy(main_menu->texture);
    sfSprite_destroy(main_menu->spt_mid_button[0]);
    sfSprite_destroy(main_menu->spt_mid_button[1]);
    sfText_destroy(main_menu->txt_mid_button[0]);
    sfText_destroy(main_menu->txt_mid_button[1]);
    sfText_destroy(main_menu->txt_title);
    sfFont_destroy(main_menu->font);
}

void destroy_menu(menu_t *menu)
{
    destroy_main_menu(menu->main_menu);
    free(menu);
}

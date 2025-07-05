/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_textures.h"

sim_textures_t *create_sim_textures(void)
{
    sim_textures_t *textures = malloc(sizeof(sim_textures_t));

    if (!textures)
        return (NULL);
    textures->plane = sfTexture_createFromFile(PL_TEXTURE_PATH, NULL);
    textures->tower = sfTexture_createFromFile(TOW_TEXTURE_PATH, NULL);
    textures->sim_bg = sfTexture_createFromFile(SIM_BG_TEXTURE_PATH, NULL);
    if (!(textures->sim_bg) || !(textures->plane) || !(textures->tower))
        return (NULL);
    return (textures);
}

void destroy_sim_textures(sim_textures_t *textures)
{
    if (textures->plane)
        sfTexture_destroy(textures->plane);
    if (textures->tower)
        sfTexture_destroy(textures->tower);
    if (textures->sim_bg)
        sfTexture_destroy(textures->sim_bg);
    if (textures)
        free(textures);
}

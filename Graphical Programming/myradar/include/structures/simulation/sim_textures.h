/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for structure sim_textures
*/

#pragma once
#include <SFML/Graphics.h>
#define SIM_BG_TEXTURE_PATH        "content/sprites/world_map.png"
#define PL_TEXTURE_PATH         "content/sprites/plane.png"
#define TOW_TEXTURE_PATH         "content/sprites/tower.png"

typedef sfTexture texture_t;

typedef struct sim_textures {
    texture_t *sim_bg;
    texture_t *plane;
    texture_t *tower;
} sim_textures_t;

typedef sim_textures_t textures_t;
sim_textures_t *create_sim_textures(void);
void destroy_sim_textures(sim_textures_t *);

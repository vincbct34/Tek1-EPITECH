/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** Second graphical project
*/

#pragma once

#include <SFML/Graphics.h>
#include "window.h"
#include "sim_fonts.h"
#define FONT "content/fonts/Milk Mango.otf"

typedef sfFont font_t;

typedef struct sim_fonts {
    font_t *monga;
} sim_fonts_t;
typedef sim_fonts_t fonts_t;

sim_fonts_t *sim_fonts_create(void);
void sim_fonts_destroy(sim_fonts_t *);

typedef sfText text_t;

typedef struct sim_texts {
    text_t *timer;
} sim_texts_t;

typedef sim_texts_t texts_t;
sim_texts_t *sim_texts_create(sim_fonts_t *fonts, win_t *window);
void sim_texts_destroy(sim_texts_t *);

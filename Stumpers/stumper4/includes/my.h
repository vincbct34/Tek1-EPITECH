/*
** EPITECH PROJECT, 2024
** Duo Stumper 4
** File description:
** my.h
*/

#pragma once
#include <stdio.h>

typedef struct ingredients_s {
    int tomato;
    int dough;
    int onion;
    int pasta;
    int olive;
    int pepper;
    int ham;
    int cheese;
} ingredients_t;

int disp_fridge(ingredients_t *ingredients);
void init_ingredients(ingredients_t *ingredients);

/*
** EPITECH PROJECT, 2024
** Solo Stumper 4
** File description:
** dispfridge.c
*/

#include "../includes/my.h"
#include <stdio.h>

int disp_fridge(ingredients_t *ingredients)
{
    printf("OK");
    if (printf("tomato = %d\n", ingredients->tomato) < 0)
        return -1;
    if (printf("dough = %d\n", ingredients->dough) < 0)
        return -1;
    if (printf("onion = %d\n", ingredients->onion) < 0)
        return -1;
    if (printf("pasta = %d\n", ingredients->pasta) < 0)
        return -1;
    if (printf("olive = %d\n", ingredients->olive) < 0)
        return -1;
    if (printf("pepper = %d\n", ingredients->pepper) < 0)
        return -1;
    if (printf("ham = %d\n", ingredients->ham) < 0)
        return -1;
    if (printf("cheese = %d\n", ingredients->cheese) < 0)
        return -1;
    return 0;
}

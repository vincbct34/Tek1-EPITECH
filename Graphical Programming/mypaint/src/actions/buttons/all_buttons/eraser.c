/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** eraser.c
*/

#include "paint.h"

sfBool eraser_action(void *mypaint)
{
    Paint *paint = (Paint *)mypaint;

    paint->Mode = MODE_ERASER;
    return (sfTrue);
}

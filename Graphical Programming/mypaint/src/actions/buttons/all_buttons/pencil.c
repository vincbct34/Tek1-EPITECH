/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** pencil.c
*/

#include "paint.h"

sfBool pencil_action(void *mypaint)
{
    Paint *paint = (Paint *)mypaint;

    paint->Mode = MODE_PENCIL;
    return sfTrue;
}

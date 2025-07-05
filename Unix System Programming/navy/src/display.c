/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_positions.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

void disp_positions(void)
{
    disp_my_positions();
    disp_enemy_positions();
}

void disp_my_positions(void)
{
    my_putstr("my navy:\n");
    display(req->my_grid);
    my_putstr("\n");
}

void disp_enemy_positions(void)
{
    my_putstr("enemy navy:\n");
    display(req->enemy_grid);
    my_putchar('\n');
}

void disp_cell(int cell)
{
    if (cell == -1)
        my_putchar('.');
    if (cell == 1)
        my_putchar('o');
    if (cell == 0)
        my_putchar('x');
    if (cell >= 2)
        my_putnbr(cell);
}

static void disp_bis(int *cells, int i, int n)
{
    disp_cell(cells[n]);
    if (n + 1 < (i * 8) + 8)
        my_putchar(' ');
}

void display(int *cells)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_putnbr(i + 1);
        my_putchar('|');
        for (int n = (i * 8); n < (i * 8) + 8; n++)
            disp_bis(cells, i, n);
        my_putchar('\n');
    }
}

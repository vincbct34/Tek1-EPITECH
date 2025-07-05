/*
** EPITECH PROJECT, 2023
** star
** File description:
** 
*/

void top_star(unsigned int size)
{
    unsigned int i, j;
    for (i = 1; i <= size - 1; i++) {
        for (j = 1; j <= size; j++) {
            my_putchar(' ');
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            if (i == size || j == 1 || j == (2 * i - 1))
                my_putchar('*');
            else
                my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void line(unsigned int size)
{
    for (unsigned int l = 1; l <= size * 2 + 1; l++)
        my_putchar('*');
}

void star(unsigned int size)
{
    if (size == 0);
    else {
    top_star(size);
    line(size);
 /* middle_star(size);
    line(size);
    bottom_star(size);*/
    }
}

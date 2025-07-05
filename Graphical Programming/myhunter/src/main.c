/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** Main of the project my_hunter
*/

#include "../header/structure.h"
#include "../header/my.h"
#include <stdlib.h>

static void helper(void)
{
    my_putstr("My Hunter\n\n");
    my_putstr("USAGE\n");
    my_putstr("    ./my_hunter\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    A game where you have to shoot birds\n");
    my_putstr("    You have 3 lifes\n");
    my_putstr("    You can shoot by clicking on the LMB\n");
    my_putstr("    You can move your crosshair by moving your mouse\n");
    my_putstr("    Try to survive as long as possible\n");
    my_putstr("    Enjoy !\n");
}

static void initialize_game(global_t *all)
{
    MODE = (sfVideoMode){1920, 1080, 32};
    WIN = sfRenderWindow_create(MODE, "My Hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 120);
    MUSIC = sfMusic_createFromFile(THEME);
    BACKMUSIC = sfMusic_createFromFile(BACKM);
    TROLLMUSIC = sfMusic_createFromFile(TROLLM);
    SHOOTMUSIC = sfMusic_createFromFile(SHOOT);
    if (all->status == 0) {
        sfMusic_play(MUSIC);
        sfMusic_play(BACKMUSIC);
        sfMusic_play(TROLLMUSIC);
    }
}

static void manage_time(global_t *all)
{
    all->images[7].time = sfClock_getElapsedTime(all->images[7].clock);
    all->images[8].time = sfClock_getElapsedTime(all->images[8].clock);
    all->images[9].time = sfClock_getElapsedTime(all->images[9].clock);
    all->images[7].seconds = all->images[7].time.microseconds / 1000000.0;
    all->images[8].seconds = all->images[8].time.microseconds / 1000000.0;
    all->images[9].seconds = all->images[9].time.microseconds / 1000000.0;
    if (all->images[7].seconds > 0.1) {
        sfClock_restart(all->images[7].clock);
        sfClock_restart(all->images[8].clock);
        sfClock_restart(all->images[9].clock);
        move_rect(all, 110, 330);
        move_rect2(all, 110, 330);
        move_rect3(all, 110, 330);
    }
}

static void destroy_all(global_t *all)
{
    sfMusic_destroy(MUSIC);
    sfMusic_destroy(BACKMUSIC);
    sfMusic_destroy(TROLLMUSIC);
    sfMusic_destroy(SHOOTMUSIC);
    sfRenderWindow_destroy(WIN);
    for (int i = 0; i < 12; i++) {
        sfSprite_destroy(all->images[i].sprite);
        sfTexture_destroy(all->images[i].texture);
    }
    sfClock_destroy(all->images[7].clock);
    sfClock_destroy(all->images[8].clock);
    sfClock_destroy(all->images[9].clock);
    free(all);
}

static void status_music(global_t *all)
{
    if (all->status == 0) {
        sfMusic_setVolume(BACKMUSIC, 0);
        sfMusic_setVolume(TROLLMUSIC, 0);
    }
    if (all->status == 1) {
        sfMusic_setVolume(BACKMUSIC, 100);
        sfMusic_setVolume(TROLLMUSIC, 0);
        sfMusic_pause(MUSIC);
        game(all);
    }
    if (all->status == 2) {
        sfMusic_pause(MUSIC);
        sfMusic_setVolume(TROLLMUSIC, 100);
        sfMusic_setVolume(BACKMUSIC, 0);
    }
    if (all->status == 3) {
        sfMusic_setVolume(TROLLMUSIC, 0);
        sfMusic_setVolume(BACKMUSIC, 0);
    }
}

static void game_over(global_t *all)
{
    sfRenderWindow_close(WIN);
    my_putstr("You lost ! EZ\n");
    my_putstr("Your score was: ");
    my_put_nbr(all->count);
    my_putstr("\nYou're a noob !\n");
}

int main(int ac, char **av)
{
    global_t *all = malloc(sizeof(global_t));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        helper();
        return (0);
    } else if (ac != 1)
        return (84);
    all->life = 3;
    initialize_game(all);
    initialize_sprites(all);
    while (sfRenderWindow_isOpen(WIN)) {
        main_menu(all);
        manage_time(all);
        status_music(all);
        if (all->life == 0)
            game_over(all);
    }
    destroy_all(all);
    return (0);
}

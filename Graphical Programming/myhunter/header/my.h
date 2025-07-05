/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Header of projet my_hunter
*/

#pragma once
#include "structure.h"
#define MODE all->parameters.mode
#define WIN all->parameters.window
#define BACKGROUND "content/pictures/background.png"
#define TITLE "content/pictures/title.png"
#define PLAY "content/pictures/play.png"
#define SETTING "content/pictures/settings.png"
#define QUIT "content/pictures/quit.png"
#define SCORE "content/pictures/score.png"
#define THEME "content/musics/music.ogg"
#define BACKM "content/musics/game_music.ogg"
#define TROLLM "content/musics/troll.ogg"
#define SHOOTER "content/pictures/shooter.png"
#define BIRD "content/pictures/bird.png"
#define SCNDBIRD "content/pictures/bird.png"
#define THRBIRD "content/pictures/bird.png"
#define SET "content/pictures/set_menu.png"
#define TROLL "content/pictures/troll.png"
#define SHOOT "content/musics/troll_sound.ogg"
#define MUSIC all->music.theme
#define BACKMUSIC all->music.backmusic
#define TROLLMUSIC all->music.trollmusic
#define SHOOTMUSIC all->music.shootmusic
#define BACKSPRITE all->images[0].sprite
#define TITLESPRITE all->images[1].sprite
#define PLAYSPRITE all->images[2].sprite
#define SETTINGSPRITE all->images[3].sprite
#define QUITSPRITE all->images[4].sprite
#define SCORESPRITE all->images[5].sprite
#define SHOOTERSPRITE all->images[6].sprite
#define BIRDSPRITE all->images[7].sprite
#define SCNDBIRDSPRITE all->images[8].sprite
#define THRBIRDSPRITE all->images[9].sprite
#define SETSPRITE all->images[10].sprite
#define TROLLSPRITE all->images[11].sprite
#define XPOS all->parameters.event.mouseButton.x
#define YPOS all->parameters.event.mouseButton.y
#define CURSORX all->mouse.cursor_x
#define CURSORY all->mouse.cursor_y

void my_putstr(char const *str);
void initialize_sprites(global_t *all);
void draw_sprites(global_t *all);
void background_sprite(global_t *all);
void shooter_sprite(global_t *all);
void titlesprite(global_t *all);
void playsprite(global_t *all);
void settingsprite(global_t *all);
void quitsprite(global_t *all);
void scoresprite(global_t *all);
void bird_sprite(global_t *all);
void second_bird_sprite(global_t *all);
void third_bird_sprite(global_t *all);
void events(global_t *all);
void main_menu(global_t *all);
void game(global_t *all);
void move_rect(global_t *all, int offset, int max_value);
void move_rect2(global_t *all, int offset, int max_value);
void move_rect3(global_t *all, int offset, int max_value);
void kill_bird(global_t *all);
void move_bird(global_t *all);
void kill_second_bird(global_t *all);
void move_second_bird(global_t *all);
void kill_third_bird(global_t *all);
void move_third_bird(global_t *all);
void set_sprite(global_t *all);
void troll_sprite(global_t *all);
void settings(global_t *all);
void my_put_nbr(int nb);

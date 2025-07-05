/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** paint.h
*/

// DOUBLE INCLUSION

#pragma once

// STRUCTURES

#include "struct.h"
#include "my.h"

// DEFINES

#define WIN(mode) mode, "My Paint", sfClose | sfResize, NULL
#define AREA paint->Area
#define BUTTON paint->Buttons
#define MENU paint->Menus

// PROTOTYPES
// <<<Actions>>>

void draw_all(Paint *paint);

// <<Buttons>>

void draw_buttons(Paint *paint);
void add_button_to_list(Buttons **list, Buttons *button);
void set_position(Buttons *button);
void add_button(Paint *paint,
    char *name, sfVector2f pos, sfBool (*action)(void *));

// <All Buttons>

sfBool eraser_action(void *mypaint);
sfBool pencil_action(void *mypaint);
sfBool pipette_action(void *mypaint);

void init_window(Paint *paint);
void init_drawing_area(Paint *paint);
void draw_all(Paint *paint);

// Button

void init_buttons(Paint *paint);
void draw_buttons(Paint *paint);
void add_button_to_list(Buttons **list, Buttons *button);
void add_button(Paint *paint,
    char *name, sfVector2f pos, sfBool (*action)(void *));

// Other

sfBool check_if_is_in_area(sfVector2i pos);
void check_for_undo(Paint *paint, sfEvent event);
void save_image_state(Paint* paint);
void undo_last_action(Paint* paint);
void display_image(sfRenderWindow *window, sfImage *image);
void draw_line_on_image(Paint *paint, sfVector2f from,
    sfVector2f to, sfColor color);
void draw_thick_pixel(sfImage* image, sfVector2f point,
    sfColor color, int thickness);
void draw_mouse_circle(Paint *paint);
void update_and_check_mouse(Paint *paint);
void mode_tools(Paint *paint, Buttons *btn);
void tools(Paint *paint);

// <<Menus>>

void add_drop_down(Menus *menu, char *subutton);
void set_drop_down_position(Menus *menu, Drop_down *drop_down);
void draw_drop_down(sfRenderWindow *window, Drop_down *drop_down);
void draw_menus(Paint *paint);
void set_menu_position(Menus *menu);
void add_menu(Paint *paint, char *name, sfVector2f pos);
void init_drop_down(Paint *paint);
void init_menus(Paint *paint);

// <All Drop Down>

void new_action(Paint *paint);
void listen_for_input_save(Paint *paint);
void listen_for_input_open(Paint *paint);
void about_action(void);
void help_action(void);

// Actions BUTTONS

sfBool pencil_action(void *mypaint);
sfBool pipette_action(void *mypaint);
sfBool moins_action(void *mypaint);
sfBool plus_action(void *mypaint);
sfBool is_clicked_button(void *ptr);
void check_drawing_mode(Paint *paint, sfColor color);
sfColor get_pixel_color_from_sfimage(sfImage *image, sfVector2f pos);
void updateDrawingMode(Paint *paint);
sfBool eraser_action(void *mypaint);

// <<<Events>>>

void events_handling(Paint *paint);
void handle_mouse_events(Paint *paint, sfColor color);
sfBool is_clicked(void *ptr);

// <<Menus' States>>

void call_action_menu(char *name, Paint *paint);
void apply_not_hover_menu(Paint *paint);
void apply_hover_menu(Paint *paint);
void apply_click_menu(Paint *paint);
void apply_release_menu(Paint *paint);
sfBool is_release_menu(void *paint);
sfBool is_clicked_menu(void *paint);
sfBool is_not_hover_menu(void *paint);
sfBool is_hover_menu(void *paint);

// <<Buttons' States>>

void call_action_button(char *name, Paint *paint);
void apply_not_hover_button(Paint *paint);
void apply_hover_button(Paint *paint);
void apply_click_button(Paint *paint);
void apply_release_button(Paint *paint);
sfBool is_release_button(void *paint);
sfBool is_clicked_button(void *paint);
sfBool is_not_hover_button(void *paint);
sfBool is_hover_button(void *paint);
void apply_button_actions(Paint *paint);

// <<<Page>>>

void init_window(Paint *paint);
void draw_window(Paint *paint);
void init_drawing_area(Paint *paint);
void draw_shadow(Paint *paint);
void draw_circle(Paint *paint);
void draw_decoration(Paint *paint);

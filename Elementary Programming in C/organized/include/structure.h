/*
** EPITECH PROJECT, 2023
** structure.h
** File description:
** Structure of Organised
*/

#pragma once

typedef struct linked_list_s {
    char *name;
    char *type;
    int index;
    struct linked_list_s *next;
} linked_list_t;

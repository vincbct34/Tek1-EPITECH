/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** my.h
*/

#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
void my_putchar(char c);
void my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char const *str);

/*
** EPITECH PROJECT, 2024
** duo
** File description:
** stumper
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int gest_key(char c, int key);
int get_charkey(char c, int key);
int get_charnegkey(char c, int key);
char *get_buffer(char *str, int key);
int encrypt_string(char *str, int key, int fd);
int encrypt_file(char *str, int key, int fd);

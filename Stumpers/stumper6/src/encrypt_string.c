/*
** EPITECH PROJECT, 2024
** duo
** File description:
** stumper
*/

#include "my.h"

int get_charkey(char c, int key)
{
    int key_size = key / 26;

    if (key > 26)
        key -= 26 * key_size;
    if (c >= 'A' && c <= 'Z') {
        if (c + key > 'Z')
            return (c - 26 + key);
        return (c + key);
    }
    if (c >= 'a' && c <= 'z') {
        if (c + key > 'z')
            return (c - 26 + key);
        return (c + key);
    }
    return c;
}

int get_charnegkey(char c, int key)
{
    int key_size;

    key *= -1;
    key_size = key / 26;
    if (key > 26)
        key -= 26 * key_size;
    if (c >= 'A' && c <= 'Z') {
        if (c - key < 'A')
            return (c + 26 - key);
        return (c - key);
    }
    if (c >= 'a' && c <= 'z') {
        if (c - key < 'a')
            return (c + 26 - key);
        return (c - key);
    }
    return c;
}

int gest_key(char c, int key)
{
    if (key < 0)
        return (get_charnegkey(c, key));
    return (get_charkey(c, key));
}

int encrypt_string(char *str, int key)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (printf("%c", gest_key(str[i], key)) < 0)
            return 84;
    if (printf("\n") < 0)
        return 84;
    return 0;
}

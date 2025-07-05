/*
** EPITECH PROJECT, 2022
** secured
** File description:
** structure
*/

#pragma once
#include "structure.h"

int hash(char *key, int len);
void ht_dump(hashtable_t *hash);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void delete_hashtable(hashtable_t *ht);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
char *int_to_str(int nb);
int count_digits(int nb);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_putnbr(int nb);
void my_putstr(char *str);
void my_putchar(char c);

/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_get.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"
#include <stdbool.h>

struct request *get_request(int ac, char **as)
{
    req = malloc(sizeof(struct request));
    req->my_grid = malloc(sizeof(int) * 64);
    req->enemy_grid = malloc(sizeof(int) * 64);
    if (ac == 2) {
        req->state = 1;
        req->enemy_pid = 0;
        req->tour = 1;
    } else {
        req->state = 0;
        req->enemy_pid = my_getnbr(as[1]);
        req->tour = 0;
    }
    req->file_name = as[ac - 1];
    req->player_pid = getpid();
    req->callback = 0;
    req->enemy_len = 0;
    return (req);
}

static bool check_and_set_coordinates(char *result, int x, int y, int index)
{
    if (x + (8 * y) == index) {
        result[0] = 'A' + x;
        result[1] = '1' + y;
        result[2] = '\0';
        return true;
    }
    return false;
}

char *get_co(int index)
{
    char *result = malloc(3);

    if (index < 0 || index >= 64 || index % 8 == 0) {
        free(result);
        return NULL;
    }
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; i < 64; i++) {
        if (check_and_set_coordinates(result, i % 8, i / 8, index)) {
            return result;
        }
    }
    free(result);
    return NULL;
}

int *get_bin(int nbr)
{
    int numbers[16] = { 32768, 16384, 8192, 4096, 2048, 1024, 512, 256,
        128, 64, 32, 16, 8, 4, 2, 1 };
    int *array = malloc(sizeof(int) * 16);

    if (nbr < 0 || nbr > 65535 || array == NULL)
        return (NULL);
    for (int i = 0; i < 16; i++) {
        if (numbers[i] <= nbr) {
            nbr -= numbers[i];
            array[i] = 1;
        } else
            array[i] = 0;
    }
    return (array);
}

int get_val(int *bin)
{
    int numbers[16] = { 32768, 16384, 8192, 4096, 2048, 1024, 512, 256,
        128, 64, 32, 16, 8, 4, 2, 1 };
    int val = 0;

    for (int i = 0; i < 16; i++)
        if (bin[i] == 1)
            val += numbers[i];
    return (val);
}

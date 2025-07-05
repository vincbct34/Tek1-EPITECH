/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** parsing.c
*/

#include "../include/lib.h"
#include "../include/navy.h"
#include "../include/struct.h"

char *read_file(void)
{
    int fd = open(req->file_name, O_RDONLY);
    char *buff = malloc(sizeof(char) * 4096);
    int offset = 0;

    if (fd <= 0 || buff == NULL) {
        my_putstr("Can not open this file.\n");
        return (NULL);
    }
    while (read(fd, buff + offset, 1) > 0 && offset < 4095)
        offset += 1;
    buff[offset] = '\0';
    close(fd);
    return (buff);
}

static void write_boat_bis(int boat_size, placement_t placement)
{
    if (placement.is_horizontal) {
        for (int i = placement.start; i <= placement.end; i++)
            req->my_grid[placement.fixed * 8 + i] = boat_size;
    } else {
        for (int i = placement.start; i <= placement.end; i++)
            req->my_grid[i * 8 + placement.fixed] = boat_size;
    }
}

void place_boat(int boat_size, char *begin_point_boat, char *end_point_boat)
{
    placement_t placement;

    placement.start = begin_point_boat[1] - '1';
    placement.end = end_point_boat[1] - '1';
    placement.fixed = begin_point_boat[0] - 'A';
    if (begin_point_boat[0] == end_point_boat[0]) {
        placement.is_horizontal = false;
        write_boat_bis(boat_size, placement);
    } else if (begin_point_boat[1] == end_point_boat[1]) {
        placement.is_horizontal = true;
        placement.fixed = begin_point_boat[1] - '1';
        placement.start = begin_point_boat[0] - 'A';
        placement.end = end_point_boat[0] - 'A';
        write_boat_bis(boat_size, placement);
    }
}

int check_win(void)
{
    int contain = 0;

    for (int i = 0; i < 64; i++) {
        if (req->my_grid[i] >= 2) {
            contain = 1;
            break;
        }
    }
    if (contain == 0) {
        req->callback = 1;
        send_request(1, 0);
        req->running = 0;
        return (1);
    }
    return (0);
}

int boat_left(void)
{
    int len = 0;

    for (int i = 0; i < 64; i++)
        if (req->my_grid[i] >= 2)
            len++;
    return (len);
}

int contain_boat(int size, int *boats, int len)
{
    for (int i = 0; i < len; i++)
        if (boats[i] == size)
            return (1);
    return (0);
}

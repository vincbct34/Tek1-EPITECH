/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "quadtree.h"
#include "utils.h"

static void quadtr_rec(quadtree_t *quadtree, pl_t **planes,
    unsigned int *plane_index, sfIntRect const area)
{
    if (!(bound_over(quadtree->boundary, area)))
        return;
    if (quadtree->is_divided)
        for (unsigned int i = 0; i < 4; i++)
            quadtr_rec(quadtree->children[i], planes,
                plane_index, area);
    for (unsigned int i = 0; quadtree->planes[i]; i++)
        if (bound_have_pos(area, quadtree->planes[i]->path->pos)) {
            planes[*(plane_index)] = quadtree->planes[i];
            (*plane_index) += 1;
        }
}

pl_t **quadtr_qu(quadtree_t *quadtree, sfIntRect const area)
{
    unsigned int nb_planes = quadtr_nb_pl(quadtree, area);
    pl_t **planes = malloc(sizeof(pl_t *) * (nb_planes) + 1);
    unsigned int plane_index = 0;

    if (!planes)
        return (NULL);
    quadtr_rec(quadtree, planes, &plane_index, area);
    planes[plane_index] = NULL;
    return (planes);
}

unsigned int quadtr_nb_pl(quadtree_t *quadtree,
    sfIntRect const area)
{
    unsigned int nb_planes = 0;

    if (!(bound_over(quadtree->boundary, area)))
        return (0);
    if (quadtree->is_divided)
        for (unsigned int i = 0; i < 4; i++)
            nb_planes += quadtr_nb_pl(quadtree->children[i],
                                                        area);
    for (unsigned int i = 0; quadtree->planes[i]; i++)
        if (bound_have_pos(area, quadtree->planes[i]->path->pos))
            nb_planes++;
    return (nb_planes);
}

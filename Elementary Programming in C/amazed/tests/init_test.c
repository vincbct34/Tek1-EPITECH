/*
** EPITECH PROJECT, 2024
** B-CPE [WSL: Ubuntu-22.04]
** File description:
** init_test
*/

#include <criterion/criterion.h>
#include "maze.h"
#include "../include/test.h"

Test(push_back, test_push_back)
{
    index_t *list = NULL;
    index_t *element1 = malloc(sizeof(index_t));
    index_t *element2 = malloc(sizeof(index_t));

    element1->data = "Element 1";
    element1->check_type = NULL;
    element1->is_pipe = false;
    element1->is_room = true;
    element1->is_start = false;
    element1->is_end = false;
    element1->next = NULL;
    push_back(&list, element1);
    cr_assert_str_eq(list->data, "Element 1");
    cr_assert_null(list->check_type);
    cr_assert_eq(list->is_pipe, false);
    cr_assert_eq(list->is_room, true);
    cr_assert_eq(list->is_start, false);
    cr_assert_eq(list->is_end, false);
    cr_assert_null(list->next);
    element2->data = "Element 2";
    element2->check_type = NULL;
    element2->is_pipe = true;
    element2->is_room = false;
    element2->is_start = false;
    element2->is_end = true;
    element2->next = NULL;
    push_back(&list, element2);
    cr_assert_str_eq(list->next->data, "Element 2");
    cr_assert_null(list->next->check_type);
    cr_assert_eq(list->next->is_pipe, true);
    cr_assert_eq(list->next->is_room, false);
    cr_assert_eq(list->next->is_start, false);
    cr_assert_eq(list->next->is_end, true);
    cr_assert_null(list->next->next);
    free(element1);
    free(element2);
}

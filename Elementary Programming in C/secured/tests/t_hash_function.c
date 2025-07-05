/*
** EPITECH PROJECT, 2024
** secured
** File description:
** test_hash_function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../includes/my.h"

Test(hash, test_hash_function)
{
    hashtable_t *ht = new_hashtable(&hash, 1);
    char *str = "test";
    int result = 0;

    result = hash(str, ht->size);
    cr_assert_eq(result, 6254);
}

Test(hash, test_hash_function2)
{
    hashtable_t *ht = new_hashtable(&hash, 1);
    char *str = "test2";
    int result = 0;

    result = hash(str, ht->size);
    cr_assert_eq(result, 5059);
}

Test(hash, test_hash_function3)
{
    hashtable_t *ht = new_hashtable(&hash, 1);
    char *str = "test3";
    int result = 0;

    result = hash(str, ht->size);
    cr_assert_eq(result, 8668);
}


Test(my_program, basic_tests) {
    hashtable_t *ht = new_hashtable(&hash, 10);

    // Test d'insertion et de recherche
    ht_insert(ht, "test1", "value1");
    ht_insert(ht, "test2", "value2");
    ht_insert(ht, "test3", "value3");

    cr_assert_str_eq(ht_search(ht, "test1"), "value1");
    cr_assert_str_eq(ht_search(ht, "test2"), "value2");
    cr_assert_str_eq(ht_search(ht, "test3"), "value3");

    // Test de suppression et vérification de la recherche après suppression
    ht_delete(ht, "test2");
    cr_assert_eq(ht_search(ht, "test2"), NULL);

    // Test d'affichage
    ht_dump(ht);

    // Ajoutez d'autres tests au besoin

    // Suppression complète de hashtable
    delete_hashtable(ht);
}

Test(my_program, edge_cases) {
    // Testez avec une hashtable de taille 0
    hashtable_t *ht_zero_size = new_hashtable(&hash, 0);
    // Ajoutez des assertions pour vérifier le comportement avec une taille de hashtable de 0
    delete_hashtable(ht_zero_size);

    // Testez avec une clé ou une valeur très longue
    hashtable_t *ht_long_key = new_hashtable(&hash, 10);
    char long_key[1000];
    strcpy(long_key, "a");
    for (int i = 0; i < 990; i++) {
        strcat(long_key, "a");
    }
    ht_insert(ht_long_key, long_key, "long_key_test");
    cr_assert_eq(ht_search(ht_long_key, long_key), "long_key_test");
    delete_hashtable(ht_long_key);

    // Ajoutez d'autres tests edge cases selon vos besoins...
}

Test(my_program, stress_tests) {
    // Testez avec un grand nombre d'insertions et de recherches
    hashtable_t *ht_stress = new_hashtable(&hash, 10000);
    for (int i = 0; i < 10000; i++) {
        char key[10];
        char value[20];
        sprintf(key, "key%d", i);
        sprintf(value, "value%d", i);
        ht_insert(ht_stress, key, value);
    }
    // Ajoutez des assertions pour vérifier le comportement avec un grand nombre d'éléments
    // Vous pouvez également tester le temps d'exécution avec Criterion, si nécessaire
    delete_hashtable(ht_stress);

    // Ajoutez d'autres tests de stress selon vos besoins...
}
##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## my_cos.py
##

from math import *
from all_functions.matrixes_handling import *

def my_cos(matrix):
    tmp_matrix = identity_matrix(len(matrix))
    for i in range(1, 50):
        if i % 2 == 0:
            tmp_matrix = add_matrix(tmp_matrix, divide_matrix(pow_matrix(matrix, 2 * i), factorial(2 * i)))
        else:
            tmp_matrix = sub_matrix(tmp_matrix, divide_matrix(pow_matrix(matrix, 2 * i), factorial(2 * i)))
    return tmp_matrix
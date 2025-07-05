##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## my_sin.py
##

from math import *
from all_functions.matrixes_handling import *

def my_sin(matrix):
    tmp_matrix = [[0 for _ in row] for row in matrix]
    for i in range(1, 50):
        factor = pow_matrix(matrix, 2 * i - 1)
        if i % 2 == 0:
            tmp_matrix = sub_matrix(tmp_matrix, divide_matrix(factor, factorial(2 * i - 1)))
        else:
            tmp_matrix = add_matrix(tmp_matrix, divide_matrix(factor, factorial(2 * i - 1)))
    return tmp_matrix
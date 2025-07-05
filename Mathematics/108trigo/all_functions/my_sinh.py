##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## my_sinh.py
##

from math import *
from all_functions.matrixes_handling import *

def my_sinh(matrix):
    tmp_matrix = matrix
    for i in range(1, 50):
        tmp_matrix = add_matrix(tmp_matrix, divide_matrix(pow_matrix(matrix, 2 * i + 1), factorial(2 * i + 1)))
    return tmp_matrix
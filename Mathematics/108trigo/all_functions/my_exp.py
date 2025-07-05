##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## my_exp.py
##

from math import *
from all_functions.matrixes_handling import *

def my_exp(matrix):
    tmp_matrix = identity_matrix(len(matrix))
    for i in range(1, 50):
        tmp_matrix = add_matrix(tmp_matrix, divide_matrix(pow_matrix(matrix, i), factorial(i)))
    return tmp_matrix
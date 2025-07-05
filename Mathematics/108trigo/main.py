##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## main.py
##

from math import *
from sys import *
from error_handling import *
from all_functions.my_exp import my_exp
from all_functions.my_cos import my_cos
from all_functions.my_sin import my_sin
from all_functions.my_cosh import my_cosh
from all_functions.my_sinh import my_sinh

def get_matrix():
    size = int(sqrt(len(argv) - 2))
    matrix = []
    index = 2
    for i in range(size):
        row = []
        for j in range(size):
            number = float(argv[index])
            row.append(number)
            index += 1
        matrix.append(row)
    return matrix

def main():
    error_handling()
    matrix = get_matrix()
    if argv[1] == "EXP":
        matrix = my_exp(matrix)
    elif argv[1] == "COS":
        matrix = my_cos(matrix)
    elif argv[1] == "SIN":
        matrix = my_sin(matrix)
    elif argv[1] == "COSH":
        matrix = my_cosh(matrix)
    elif argv[1] == "SINH":
        matrix = my_sinh(matrix)
    else:
        print("Invalid function.")
        exit(84)
    for row in matrix:
        print('\t'.join(format(float(num), '.2f') for num in row))
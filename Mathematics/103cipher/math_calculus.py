##
## EPITECH PROJECT, 2023
## math_calculus.py
## File description:
## Some functions for the 103cipher project
##

from sys import *
from math import *

message = ""
key = ""
if (len(argv) >= 3):
    message = argv[1]
    key = argv[2]

def fill_key_matrix(matrix_key):
    print("Key matrix:")
    for i in range(matrix_side):
        for j in range(matrix_side):
            if i * matrix_side + j < key_len:
                matrix_key[i][j] = key_ascii[i * matrix_side + j]
            else:
                matrix_key[i][j] = 0
    return matrix_key

def str_to_ascii(string):
    result = []
    for i in range(len(string)):
        result.append(ord(string[i]))
    return result

def get_matrix_len(key_len):
    result = 0
    while result * result < key_len:
        result += 1
    return result

def multiply_matrices(matrix1, matrix2):
    num_rows1, num_cols1 = len(matrix1), len(matrix1[0])
    num_rows2, num_cols2 = len(matrix2), len(matrix2[0])
    result = [[0 for _ in range(num_cols2)] for _ in range(num_rows1)]
    for i in range(num_rows1):
        for j in range(num_cols2):
            for k in range(num_cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

key_len = 0
message_len = 0
message_ascii = []
key_ascii = []
matrix_side = 0
num_rows_message = 0
if (len(argv) >= 3):
    key_len = len(key)
    message_len = len(message)
    message_ascii = str_to_ascii(message)
    key_ascii = str_to_ascii(key)
    matrix_side = get_matrix_len(key_len)
    num_rows_message = (message_len + matrix_side - 1) // matrix_side
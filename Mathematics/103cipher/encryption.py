##
## EPITECH PROJECT, 2023
## encryption.c
## File description:
## Encryption of the 103cipher project
##

from sys import *
from math import *
from math_calculus import *

message = ""
key = ""
message_len = 0
key_len = 0
message_ascii = []
key_ascii = []
matrix_side = 0
num_rows_message = 0
if (len(argv) >= 3):
    message = argv[1]
    key = argv[2]
    key_len = len(key)
    message_len = len(message)
    message_ascii = str_to_ascii(message)
    key_ascii = str_to_ascii(key)
    matrix_side = get_matrix_len(key_len)
    num_rows_message = (message_len + matrix_side - 1) // matrix_side

def print_key_matrix_for_encryption(matrix_key):
    for i in range(matrix_side):
        for j in range(matrix_side):
            print(matrix_key[i][j], end="")
            if j < matrix_side - 1:
                print("\t", end="")
        print()
    print()

def fill_message_matrix_for_encryption(message_matrix):
    print("Encrypted message:")
    for i in range(num_rows_message):
        for j in range(matrix_side):
            if i * matrix_side + j < message_len:
                message_matrix[i][j] = message_ascii[i * matrix_side + j]
            else:
                message_matrix[i][j] = 0
    return message_matrix

def print_message_matrix_for_encryption(message_matrix):
    start = True
    for row in message_matrix:
        for elem in row:
            if start:
                start = False
                print(elem, end="")
            else:
                print(f" {elem}", end="")
    print()

def encrypt():
    matrix_key = [[0 for _ in range(matrix_side)] for _ in range(matrix_side)]
    message_matrix = [[0 for _ in range(matrix_side)] for _ in range(num_rows_message)]
    fill_key_matrix(matrix_key)
    print_key_matrix_for_encryption(matrix_key)
    fill_message_matrix_for_encryption(message_matrix)
    message_matrix = multiply_matrices(message_matrix, matrix_key)
    print_message_matrix_for_encryption(message_matrix)
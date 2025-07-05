##
## EPITECH PROJECT, 2023
## decryption.py
## File description:
## Decryption of the 103cipher project
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

def print_key_matrix_for_decryption(matrix_key):
    for i in range(matrix_side):
        for j in range(matrix_side):
            if matrix_key[i][j] == -0.0:
                matrix_key[i][j] = 0.0
            print(round(matrix_key[i][j], 3), end="")
            if j < matrix_side - 1:
                print("\t", end="")
        print()
    print()

def fill_message_matrix_for_decryption(chaine, nb_colonnes):
    nombres = list(map(int, chaine.split()))
    nb_lignes = -(-len(nombres) // nb_colonnes)
    matrice = [nombres[i * nb_colonnes:(i + 1) * nb_colonnes] for i in range(nb_lignes)]

    for ligne in matrice:
        while len(ligne) < nb_colonnes:
            ligne.append(0)
    return matrice

def print_message_matrix_for_decryption(message_matrix):
    text = ''.join([chr(int(round(value))) for row in message_matrix for value in row])
    print("Decrypted message:")
    for char in text:
        if ord(char) >= 32:
            print(char, end="")
    print()

def minor(matrix, row, col):
    result = []
    for i in range(len(matrix)):
        if i != row:
            result.append([])
            for j in range(len(matrix[i])):
                if j != col:
                    result[-1].append(matrix[i][j])
    return result

def cofactor(matrix, row, col):
    return (-1) ** (row + col) * determinant(minor(matrix, row, col))

def determinant(matrix):
    if len(matrix) == 1:
        return matrix[0][0]
    elif len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]
    else:
        result = 0
        for i in range(len(matrix)):
            result += matrix[0][i] * cofactor(matrix, 0, i)
        return result

def get_matrix_of_cofactors(matrix):
    result = []
    for i in range(len(matrix)):
        result.append([])
        for j in range(len(matrix[i])):
            result[-1].append(cofactor(matrix, i, j))
    return result

def get_transpose(matrix):
    result = []
    for i in range(len(matrix)):
        result.append([])
        for j in range(len(matrix[i])):
            result[-1].append(matrix[j][i])
    return result

def get_inverse_matrix(matrix):
    if len(matrix) == 1 and len(matrix[0]) == 1:
        det = matrix[0][0]
        if det == 0:
            print("Determinant is equal to 0, matrix is not invertible")
            exit(84)
        return [[1/det]]
    det = determinant(matrix)
    if det == 0:
        print("Determinant is equal to 0, matrix is not invertible")
        exit(84)
    cofactors = get_matrix_of_cofactors(matrix)
    cofactors = get_transpose(cofactors)
    for i in range(len(cofactors)):
        for j in range(len(cofactors[i])):
            cofactors[i][j] /= det
    return cofactors


def decrypt():
    matrix_key = [[0 for _ in range(matrix_side)] for _ in range(matrix_side)]
    message_matrix = [[0 for _ in range(matrix_side)] for _ in range(num_rows_message)]
    fill_key_matrix(matrix_key)
    matrix_key = get_inverse_matrix(matrix_key)
    print_key_matrix_for_decryption(matrix_key)
    message_matrix = fill_message_matrix_for_decryption(message, matrix_side)
    message_matrix = multiply_matrices(message_matrix, matrix_key)
    print_message_matrix_for_decryption(message_matrix)

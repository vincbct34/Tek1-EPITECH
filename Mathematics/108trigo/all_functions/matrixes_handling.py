##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## identity_matrix.py
##

def identity_matrix(size):
    matrix = []
    for i in range(size):
        row = []
        for j in range(size):
            if i == j:
                row.append(1)
            else:
                row.append(0)
        matrix.append(row)
    return matrix

def add_matrix(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1)):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def divide_matrix(matrix, number):
    result = []
    for i in range(len(matrix)):
        row = []
        for j in range(len(matrix)):
            row.append(matrix[i][j] / number)
        result.append(row)
    return result

def pow_matrix(matrix, power):
    result = matrix
    for i in range(1, power):
        result = multiply_matrix(result, matrix)
    return result

def multiply_matrix(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1)):
            row.append(0)
        result.append(row)
    for i in range(len(matrix1)):
        for j in range(len(matrix1)):
            for k in range(len(matrix1)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

def sub_matrix(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1)):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result
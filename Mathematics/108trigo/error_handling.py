##
## EPITECH PROJECT, 2024
## 108trigo
## File description:
## error_handling.py
##

from sys import *
from math import *

def usage():
    print("USAGE")
    print("\t./108trigo fun a0 a1 a2 ...#br")
    print("DESCRIPTION")
    print("\tfun\tfunction to be applied, among at least \"EXP\", \"COS\", \"SIN\", \"COSH\" and \"SINH\"")
    print("\tai\tcoeficients of the matrix")
    exit(0)

def error_handling():
    if len(argv) == 2 and argv[1] == "-h":
        usage()
        exit(84)
    if len(argv) < 3:
        print("Usage: script <elements of the matrix>")
        exit(84)
    if sqrt(len(argv) - 2) != int(sqrt(len(argv) - 2)):
        print("The number of elements in the matrix is not a perfect square.")
        exit(84)
    try:
        for i in range(2, len(argv)):
            float(argv[i])
    except ValueError:
        print("Invalid input, please enter only numbers.")
        exit(84)
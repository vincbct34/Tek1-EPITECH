##
## EPITECH PROJECT, 2024
## 107transfer
## File description:
## error_handling
##

from sys import *

def usage():
    print("USAGE")
    print("\t./107transfer [num den]+")
    print("\nDESCRIPTION")
    print("\tnum\tpolynomial numerator defined by its coefficients")
    print("\tden\tpolynomial denominator defined by its coefficients")
    exit(0)

def is_valid_number(str):
    try:
        int(str)
        return True
    except ValueError:
        return False

def error_handling():
    if len(argv) == 2 and argv[1] == "-h":
        usage()
    elif len(argv) < 3:
        print("Usage: ./107transfer [num den]+")
        exit(84)
    if len(argv) % 2 == 0:
        print("Usage: ./107transfer [num den]+")
        exit(84)
    for i in range(1, len(argv)):
        parts = argv[i].split('*')
        for part in parts:
            if not is_valid_number(part):
                print("Error: numbers only")
                exit(84)
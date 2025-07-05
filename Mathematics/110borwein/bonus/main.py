##
## EPITECH PROJECT, 2024
## 110borwein
## File description:
## main.py
##


from sys import *
from math import *
from borwein import borwein
from visuals.midpoint import borwein_midpoint
from visuals.trapezoidal import borwein_trapezoidal
from visuals.simpson import borwein_simpson


def print_usage():

    print("USAGE")
    print("\t./110borwein n")
    print("\nDESCRIPTION")
    print("\tn\tconstant defining the integral to be computed")
    exit(0)


def main():

    if len(argv) != 3:
        if len(argv) != 2:
            print("Error: invalid number of arguments")
            exit(84)
        elif argv[1] == "-h":
            print_usage()
        else:
            try:
                n = int(argv[1])
                if n < 0:
                    print("Error: invalid argument, n must be positive")
                    exit(84)
            except ValueError:
                print("Error: invalid argument, n must be an integer")
                exit(84)
            borwein(n)
    else:
        try:
            n = int(argv[1])
            if n < 0:
                print("Error: invalid argument, n must be positive")
                exit(84)
        except ValueError:
            print("Error: invalid argument, n must be an integer")
            exit(84)
        if argv[2] == "MIDPOINT":
            borwein_midpoint(n)
        elif argv[2] == "TRAPEZOIDAL":
            borwein_trapezoidal(n)
        elif argv[2] == "SIMPSON":
            borwein_simpson(n)
        else:
            print("Error: invalid method")
            exit(84)
    return 0
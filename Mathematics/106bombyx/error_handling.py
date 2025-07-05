from sys import *
from math import *
from growth_rate import *
from values import *

def handling_with_growth_rate():
    try:
        n = float(argv[1])
        k = float(argv[2])
        if k < 1 or k > 4:
            print("Error: k must be between 1 and 4")
            exit(84)
        if n < 0:
            print("Error: n must be positive")
            exit(84)
    except ValueError:
        print("Error: n and k must be float numbers")
        exit(84)
    by_growth_rate(n, k)

def handling_with_values():
    try:
        n = float(argv[1])
        i0 = int(argv[2])
        i1 = int(argv[3])
        if n < 0:
            print("Error: n must be positive")
            exit(84)
        if i0 < 0 or i1 < 0:
            print("Error: i0 and i1 must be positive")
            exit(84)
        if i0 > i1:
            print("Error: i0 must be lower than i1")
            exit(84)
    except ValueError:
        print("Error: n, i0 and i1 must be float / int numbers")
        exit(84)
    by_values(n, i0, i1)
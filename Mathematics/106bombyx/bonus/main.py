from sys import *
from math import *
from error_handling import *

def print_usage():
    print("USAGE")
    print("\t./106bombyx n [k | i0 i1]")
    print("\nDESCRIPTION")
    print("\tn\tnumber of first generation individuals")
    print("\tk\tgrowth rate from 1 to 4")
    print("\ti0\tinitial generation (included)")
    print("\ti1\tfinal generation (included)")
    
def main():
    if len(argv) < 2 or len(argv) > 4:
        print("Error: wrong number of arguments")
        exit(84)
    elif len(argv) == 2 and argv[1] == "-h":
        print_usage()
        return 0
    elif len(argv) == 3:
        handling_with_growth_rate()
    elif len(argv) == 4:
        handling_with_values()
    else:
        print("Error: wrong number of arguments")
        exit(84)
    return 0
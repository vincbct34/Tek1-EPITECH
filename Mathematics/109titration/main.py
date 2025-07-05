##
## EPITECH PROJECT, 2024
## 109titration
## File description:
## main.py
##


from sys import *
from math import *
from titration import titration


def print_usage():
    print("USAGE")
    print("\t./109titration file")
    print("DESCRIPTION")
    print("\tfile\ta csv file containing \"vol;ph\" lines")


def main():

    if len(argv) == 2:
        if argv[1] == "-h":
            print_usage()
            exit(0)
        else:
            try:
                with open(argv[1], "r") as file:
                    content = file.read()
                    if not content.strip():
                        print("Error: File is empty.")
                        exit(84)
                    file.seek(0)
                    titration(argv[1])
            except FileNotFoundError:
                print("Error: File not found.")
                exit(84)
    else:
        print_usage()
        exit(84)

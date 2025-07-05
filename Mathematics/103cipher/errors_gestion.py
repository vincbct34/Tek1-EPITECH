##
## EPITECH PROJECT, 2023
## errors_gestion.py
## File description:
## Errors gestion of the 103cipher project
##

from sys import *
from math import *
from encryption import *
from decryption import *
from main import *

def usage():
    print("USAGE:")
    print("\t./103cipher message key flag\n")
    print("DESCRIPTION:")
    print("\tmessage\ta message, made of ASCII characters")
    print("\tkey\tthe encryption key, made of ASCII characters")
    print("\tflag\t0 for the message to be encrypted, 1 to be decrypted")
    exit(84)

def check_args():
    if len(argv) != 4:
        usage()
    if argv[3] != "0" and argv[3] != "1":
        usage()
    for i in range(len(argv[1])):
        if ord(argv[1][i]) < 32 or ord(argv[1][i]) > 126:
            usage()
    for i in range(len(argv[2])):
        if ord(argv[2][i]) < 32 or ord(argv[2][i]) > 126:
            usage()
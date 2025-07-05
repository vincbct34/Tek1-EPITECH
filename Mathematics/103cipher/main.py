##
## EPITECH PROJECT, 2023
## main.py
## File description:
## Main of the 103cipher project
##

from sys import *
from math import *
from encryption import *
from decryption import *
from errors_gestion import check_args

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

def main():
    check_args()
    if int(argv[3]) == 0:
        encrypt()
    else:
        decrypt()
    exit(0)

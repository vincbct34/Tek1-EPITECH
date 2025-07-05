##
## EPITECH PROJECT, 2023
## 107transfer
## File description:
## main
##

from sys import *
from math import *
from error_handling import *
from fill_lists import *

def main():
    error_handling()
    num, den = fill_lists(argv)
    for j in range(0, 1001):
        res = 1.0
        for i in range(len(num)):
            num_res = 0.0
            den_res = 0.0
            power_num = 0
            power_den = 0
            for coef_num in num[i]:
                num_res += coef_num * pow(j / 1000, power_num)
                power_num += 1
            for coef_den in den[i]:
                den_res += coef_den * pow(j / 1000, power_den)
                power_den += 1
            if den_res == 0:
                print("Division by zero")
                exit(84)
            else:
                res *= num_res / den_res
        print("{:.3f} -> {:.5f}".format(j / 1000, res))
    return 0

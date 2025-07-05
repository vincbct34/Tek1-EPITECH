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
import matplotlib.pyplot as plt
import matplotlib.animation as animation

data = []

def main():
    error_handling()
    num, den = fill_lists(argv)
    for j in range(0, 10001):
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
            if den_res == 0 and num_res != 0 and num_res > 0:
                print("Inf")
                return 1
            elif den_res == 0 and num_res != 0 and num_res < 0:
                print("-Inf")
                return 1
            elif den_res == 0 and num_res == 0:
                print("NaN")
                return 1
            else:
                res *= num_res / den_res
        print("{:.3f} -> {:.5f}".format(j / 1000, res))
        data.append((j / 1000, res))
    fig, ax = plt.subplots()
    ax.grid(True, color='grey')
    ax.set_title('Frequency responses', color='black', fontsize=16, fontweight='bold', fontname='monospace', loc='center', pad=20)
    ax.set_facecolor('black')
    ax.plot(*zip(*data), '.', color='white', markersize=5)
    ax.set_xlim(0, 10)
    ax.set_ylim(min([y for x, y in data]), max([y for x, y in data]))
    plt.show()
    return 0
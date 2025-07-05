##
## EPITECH PROJECT, 2023
## 110borwein
## File description:
## midpoint.py
##

from math import *
import numpy as np
import matplotlib.patches as patches
import matplotlib.pyplot as plt


def f(x, n):

    res = 0
    if x == 0:
        return 1.0
    for i in range(n + 1):
        factor = 2 * i + 1
        res1 = sin(x / factor)
        res2 = x / factor
        if i != 0:
            res *= res1 / res2
        else:
            res = res1 / res2

    return res


def midpoint_method_visual(n, ax):

    total_integral = 0
    i = start

    while i < end:
        midpoint = i + dx / 2
        height = f(midpoint, n)
        total_integral += height * dx
        rect = patches.Rectangle((i, 0), dx, height, linewidth=1, edgecolor='r', facecolor='none')
        ax.add_patch(rect)
        i += dx

    print(f"I{int(n)} = {total_integral:.10f}")
    print(f"diff = {abs(total_integral - pi / 2):.10f}")

    return 0


def borwein_midpoint(n):

    global start, end, dx
    start, end, dx = 0, 50, 0.5
    
    x_values = np.linspace(start, end, 400)
    y_values = [f(x, n) for x in x_values]

    fig, ax = plt.subplots()
    ax.plot(x_values, y_values, label=f'f(x, {n})', color='blue')
    midpoint_method_visual(n, ax)
    
    ax.set_title('Function Plot of f(x, n) with Midpoint Integration')
    ax.set_xlabel('x')
    ax.set_ylabel('f(x, n)')
    ax.legend()

    plt.show()

    return 0
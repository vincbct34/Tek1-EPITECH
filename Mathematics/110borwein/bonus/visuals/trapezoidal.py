##
## EPITECH PROJECT, 2023
## 110borwein
## File description:
## trapezoidal.py
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


def plot_trapezoidal(ax, n, start, end, dx):

    x = np.arange(start, end, dx)

    for i in range(len(x)-1):
        x0, x1 = x[i], x[i+1]
        y0, y1 = f(x0, n), f(x1, n)
        ax.add_patch(patches.Polygon([[x0, 0], [x0, y0], [x1, y1], [x1, 0]], closed=True, fill=None, edgecolor='green'))

    return 0

def borwein_trapezoidal(n):

    global start, end, dx
    start, end, dx = 0, 50, 0.5
    x_values = np.linspace(start, end, 400)
    y_values = [f(x, n) for x in x_values]

    fig, ax = plt.subplots()
    ax.plot(x_values, y_values, label=f'f(x, {n})', color='blue')
    plot_trapezoidal(ax, n, start, end, dx)
    
    ax.set_title('Function Plot of f(x, n) with Trapezoidal Integration')
    ax.set_xlabel('x')
    ax.set_ylabel('f(x, n)')
    ax.legend()

    plt.show()
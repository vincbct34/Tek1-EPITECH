##
## EPITECH PROJECT, 2023
## 110borwein
## File description:
## simpson.py
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


def plot_simpson(ax, n, start, end, dx):

    x = np.arange(start, end, dx)

    for i in range(0, len(x)-2, 2):
        x0, x1, x2 = x[i], x[i+1], x[i+2]
        y0, y1, y2 = f(x0, n), f(x1, n), f(x2, n)
        vx = [x0, x1, x2]
        vy = [y0, y1, y2]
        coeffs = np.polyfit(vx, vy, 2)
        parabola = np.poly1d(coeffs)
        xs = np.linspace(x0, x2, 100)
        ys = parabola(xs)
        ax.plot(xs, ys, 'r-')

    return 0


def borwein_simpson(n):

    global start, end, dx
    start, end, dx = 0, 50, 0.5
    x_values = np.linspace(start, end, 400)
    y_values = [f(x, n) for x in x_values]

    fig, ax = plt.subplots()
    ax.plot(x_values, y_values, label=f'f(x, {n})', color='blue')
    plot_simpson(ax, n, start, end, dx)
    
    ax.set_title('Function Plot of f(x, n) with Numerical Integration')
    ax.set_xlabel('x')
    ax.set_ylabel('f(x, n)')
    ax.legend()

    plt.show()

    return 0
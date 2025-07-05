## EPITECH PROJECT, 2024
## 110borwein
## File description:
## borwein.py
##


from math import *


start = 0
end = 5000
dx = 0.5


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


def midpoint_method(n):

    total_integral = 0
    i = start

    while i < end:
        computed_value = f(i + dx / 2, n)
        integral_part = dx * computed_value
        total_integral += integral_part
        i += dx

    print(f"I{int(n)} = {total_integral:.10f}")
    print(f"diff = {abs(total_integral - pi / 2):.10f}")

    return 0


def trapezoidal_method(n):

    total_integral = 0
    i = start

    while i < end:
        computed_value = f(i, n) + f(i + dx, n)
        integral_part = dx * (computed_value / 2)
        total_integral += integral_part
        i += dx

    print(f"I{int(n)} = {total_integral:.10f}")
    print(f"diff = {abs(total_integral - pi / 2):.10f}")

    return total_integral


def simpson_method(n):
    
    total_integral = 0
    i = start

    while i < end:
        computed_value = f(i, n) + 4 * f(i + dx / 2, n) + f(i + dx, n)
        integral_part = (dx / 6) * computed_value
        total_integral += integral_part
        i += dx

    print(f"I{int(n)} = {total_integral:.10f}")
    print(f"diff = {abs(total_integral - pi / 2):.10f}")

    return 0


def borwein(n):

    print("Midpoint:")
    midpoint_method(n)
    print("\nTrapezoidal:")
    trapezoidal_method(n)
    print("\nSimpson:")
    simpson_method(n)

    return 0
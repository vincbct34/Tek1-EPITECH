##
## EPITECH PROJECT, 2024
## 109titration
## File description:
## derivation.py
##


from sys import *
from math import *


derivatives = []


def calculate_derivative(vol, ph):

    derivatives.clear()

    for i in range(1, len(vol) - 1):
        ph_forward = ph[i + 1] - ph[i]
        ph_backward = ph[i] - ph[i - 1]
        vol_forward = vol[i + 1] - vol[i]
        vol_backward = vol[i] - vol[i - 1]
        if vol_forward == 0 or vol_backward == 0:
            print("Division by zero.")
            exit(84)
        weight_forward = vol[i + 1] - vol[i]
        weight_backward = vol[i] - vol[i - 1]
        weight_total = weight_forward + weight_backward
        if weight_total == 0:
            print("Division by zero.")
            exit(84)
        centered_rate = (ph_forward / vol_forward * weight_backward + ph_backward / vol_backward * weight_forward) / weight_total
        derivatives.append((vol[i], centered_rate))

    return derivatives
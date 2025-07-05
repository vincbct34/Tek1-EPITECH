##
## EPITECH PROJECT, 2024
## 109titration
## File description:
## interpolation.py
##


from sys import *
from math import *


target_indices = []
target_values = []
interpolated_values = []


def interpolate_second_derivative():

    interpolated_values.clear()

    vol_before = target_indices[0]
    vol_now = target_indices[1]
    vol_after = target_indices[2]
    ph_before = target_values[0]
    ph_now = target_values[1]
    ph_after = target_values[2]

    current_vol = vol_before

    while current_vol <= vol_after:
        if current_vol < target_indices[1]:
            if vol_before == vol_now:
                print("Division by zero.")
                exit(84)
            else:
                interpolated_ph = ph_before + (ph_now - ph_before) * ((current_vol - vol_before) / (vol_now - vol_before))
        else:
            if vol_now == vol_after:
                print("Division by zero.")
                exit(84)
            else:
                interpolated_ph = ph_now + (ph_after - ph_now) * ((current_vol - vol_now) / (vol_after - vol_now))
        interpolated_values.append((current_vol, interpolated_ph))
        current_vol = round(current_vol + 0.1, 1)

    return interpolated_values


def find_in_list(target, second_derivatives):

    target_indices.clear()
    target_values.clear()

    for i in range(len(second_derivatives)):
        if second_derivatives[i][0] == target:
            target_values.append(second_derivatives[i - 1][1])
            target_indices.append(second_derivatives[i - 1][0])
            target_values.append(second_derivatives[i][1])
            target_indices.append(second_derivatives[i][0])
            target_values.append(second_derivatives[i + 1][1])
            target_indices.append(second_derivatives[i + 1][0])
            break
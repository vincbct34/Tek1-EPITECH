##
## EPITECH PROJECT, 2024
## 109titration
## File description:
## titration.py
##


from sys import *
from math import *
from interpolation import interpolate_second_derivative, find_in_list
from derivation import calculate_derivative


vol = []
ph = []


def fill_list(file):

    with open(file, "r") as file:
        lines = file.readlines()

        for line in lines:
            if not ';' in line:
                print("Error: Invalid file. Missing ';' separator.")
                exit(84)
            line = line.strip().split(";")
            try:
                float(line[0])
                float(line[1])
            except ValueError:
                print("Error: Invalid file. Only numbers are allowed.")
                exit(84)
            vol.append(float(line[0]))
            ph.append(float(line[1]))
    
    for i in range(len(vol)):
        if vol[i] < 0 or ph[i] < 0 or ph[i] > 14:
            print("Error: Invalid file. Volumes must be positive and pH must be between 0 and 14.")
            exit(84)


def find_equivalence_point(derivative):
    max_rate_index = derivative.index(max(derivative, key=lambda x: x[1]))
    return derivative[max_rate_index][0]


def find_closest_to_zero(derivative):
    closest_index = derivative.index(min(derivative, key=lambda x: abs(x[1])))
    return derivative[closest_index][0]


def titration(file):

    fill_list(file)

    print("Derivative:")
    first_derivatives = calculate_derivative(vol, ph)
    equivalence_point = find_equivalence_point(first_derivatives)
    tmp = equivalence_point

    for v, p in first_derivatives:
        print(f"{v:.1f} ml -> {p:.2f}")
    
    print("\nEquivalence point at {:.1f} ml".format(equivalence_point))
    print("\nSecond derivative:")
    second_derivatives = calculate_derivative([x[0] for x in first_derivatives], [x[1] for x in first_derivatives])

    for v, p in second_derivatives:
        print(f"{v:.1f} ml -> {p:.2f}")

    print("\nSecond derivative estimated:")
    equivalence_point = find_equivalence_point(first_derivatives)
    if equivalence_point == first_derivatives[0][0]:
        exit(0)
    equivalence_point = tmp
    find_in_list(equivalence_point, second_derivatives)
    interpolated_values = interpolate_second_derivative()

    for v, p in interpolated_values:
        print(f"{v:.1f} ml -> {p:.2f}")

    second_equivalence_point = find_closest_to_zero(interpolated_values)
    print(f"\nEquivalence point at {second_equivalence_point:.1f} ml")
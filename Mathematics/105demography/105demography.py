#!/usr/bin/python3

from sys import *
from math import *

csv_file = "105demography_data.csv"
country_data_by_code = {}

def print_usage():
    print("USAGE")
    print("\t./105demography [code]+\n")
    print("DESCRIPTION")
    print("\tcode\tcountry code")

def read_data(csv_file):
    with open(csv_file, 'r') as file:
        years = file.readline().strip().split(';')[2:]
        years = [int(year) for year in years]
        for line in file:
            elements = line.strip().split(';')
            country_code = elements[1]
            populations = []
            for pop in elements[2:]:
                try:
                    populations.append(float(pop))
                except ValueError:
                    populations.append(None)
            country_data_by_code[country_code] = dict(zip(years, populations))
    return country_data_by_code, years

def get_country_names(csv_file):
    with open(csv_file, 'r', encoding='utf-8') as file:
        headers = file.readline().strip().split(';')
        country_code_index = headers.index("Country Code")
        country_name_index = headers.index("Country Name")
        country_names_by_code = {}
        for line in file:
            elements = line.strip().split(';')
            country_code = elements[country_code_index]
            country_name = elements[country_name_index]
            country_names_by_code[country_code] = country_name
    return country_names_by_code

def linear_regression(x, y):
    n = len(x)
    sum_x = sum(x)
    sum_y = sum(y)
    sum_x2 = sum(xi**2 for xi in x)
    sum_xy = sum(xi*yi for xi, yi in zip(x, y))
    a = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x**2)
    b = (sum_y - a * sum_x) / n
    y_pred = [a * xi + b for xi in x]
    rmsd_Y = (sum((yi - yp) ** 2 for yi, yp in zip(y, y_pred)) / n) ** 0.5
    x_pred = [(yi - b) / a if a != 0 else 0 for yi in y]
    rmsd_X = (sum((xi - xp) ** 2 for xi, xp in zip(x, x_pred)) / n) ** 0.5
    correlation = (sum((xi - sum_x/n) * (yi - sum_y/n) for xi, yi in zip(x, y)) / 
                  ((sum((xi - sum_x/n) ** 2 for xi in x) * sum((yi - sum_y/n) ** 2 for yi in y)) ** 0.5))
    return a, b, rmsd_Y, correlation, y_pred, rmsd_X

def main(csv_file):
    if len(argv) < 2:
        print("Error: not enough arguments.")
        exit(84)
    if argv[1] == "-h":
        print_usage()
        exit(0)
    country_codes = argv[1:]
    data, years = read_data(csv_file)
    for code in country_codes:
        if code not in data:
            print(f"Error: Country code '{code}' not found.")
            exit(84)
    country_names_by_code = get_country_names(csv_file)
    valid_years = set(years)
    for code in country_codes:
        valid_years &= {year for year, pop in data[code].items() if pop is not None}
    aggregated_populations = []
    aggregated_years = sorted(list(valid_years))
    for year in aggregated_years:
        aggregated_populations.append(sum(data[code][year] for code in country_codes if code in data))
    aggregated_populations = [pop / 1e6 for pop in aggregated_populations]
    aX, bX, rmsd_Y, corr, _, _ = linear_regression(aggregated_years, aggregated_populations)
    aY, bY, _, _, _, rmsd_X = linear_regression(aggregated_populations, aggregated_years)
    country_names = [country_names_by_code[code] for code in country_codes if code in country_names_by_code]
    print(f"Country: {', '.join(country_names)}")
    print(f"Fit1\n    Y = {aX:.2f} X - {abs(bX):.2f}")
    print(f"    Root-mean-square deviation: {rmsd_Y:.2f}")
    print(f"    Population in 2050: {aX * 2050 + bX:.2f}")
    print(f"Fit2\n    X = {aY:.2f} Y + {abs(bY):.2f}")
    print(f"    Root-mean-square deviation: {rmsd_X:.2f}")
    print(f"    Population in 2050: {(2050 - bY) / aY:.2f}")
    print(f"Correlation: {corr:.4f}")

if __name__ == '__main__':
    main(csv_file)

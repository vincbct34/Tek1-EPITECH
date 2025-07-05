##
## EPITECH PROJECT, 2024
## 107transfer
## File description:
## fill_lists
##

def fill_lists(argv):
    num = []
    den = []
    for i in range(1, len(argv)):
        if i % 2 == 1:
            num.append(list(map(int, argv[i].split('*'))))
        else:
            den.append(list(map(int, argv[i].split('*'))))
    return num, den
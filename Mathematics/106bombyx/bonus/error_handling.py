from sys import *
from math import *
from growth_rate import *
from values import *
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def handling_with_growth_rate():
    try:
        n = float(argv[1])
        k = float(argv[2])
        if k < 1 or k > 4:
            print("Error: k must be between 1 and 4")
            exit(84)
        if n < 0:
            print("Error: n must be positive")
            exit(84)
    except ValueError:
        print("Error: n and k must be float numbers")
        exit(84)
    by_growth_rate(n, k)
    
def handling_with_values():
    try:
        n = float(argv[1])
        i0 = int(argv[2])
        i1 = int(argv[3])
        if n < 0:
            print("Error: n must be positive")
            exit(84)
        if i0 < 0 or i1 < 0:
            print("Error: i0 and i1 must be positive")
            exit(84)
        if i0 > i1:
            print("Error: i0 must be lower than i1")
            exit(84)
    except ValueError:
        print("Error: n, i0 and i1 must be float / int numbers")
        exit(84)
    by_values(n, i0, i1)
    fig, ax = plt.subplots()
    line, = ax.plot([], [], '.')
    def init():
        ax.grid(True, color='grey')
        ax.set_title('Synthetic scheme of the evolution of the population', color='black', fontsize=16, fontweight='bold', fontname='monospace', loc='center', pad=20)
        ax.set_facecolor('black')
        line.set_color('white')
        line.set_markersize(5)
        ax.set_xlim(1, 4)
        ax.set_ylim(min([y for x, y in data]), max([y for x, y in data]))
        return line,
    def update(frame):
        if frame == 0:
            line.set_data([], [])
        else:
            line.set_data(*zip(*data[:frame]))
        return line,
    ani = animation.FuncAnimation(fig, update, frames=range(len(data)), init_func=init, blit=True, interval=0.5, repeat=False)
    plt.show()
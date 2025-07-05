data = []

def by_values(n, i0, i1):
    k = float(1)
    temp = n
    while k < 4:
        n = float(temp)
        for _ in range(1, i0):
            n = k * n * ((1000 - n) / 1000)
            if n < 0:
                n = 0
        for _ in range(i0, i1 + 1):
            print(f"{k:.2f} {round(n, 2):.2f}")
            data.append((k, n))
            n = k * n * ((1000 - n) / 1000)
            if n < 0:
                n = 0
        k += 0.01
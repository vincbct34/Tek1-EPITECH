def by_growth_rate(n, k):
    for i in range(1, 101):
        if n < 0:
            n = 0
        print(f"{i} {n:.2f}")
        n = k * n * ((1000 - n) / 1000)
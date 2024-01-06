N = int(input())

for x in range(N + 1):
    for y in range(N - x + 1):
        z = N - x - y
        if z >= 0:
            print(f"({x}, {y}, {z})")

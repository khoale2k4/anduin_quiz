import math

MODULO = 10**9 + 7

def count_paths(p1, p2):
    total_steps = p2[0] - p1[0] + p2[1] - p1[1]
    x_steps = p2[0] - p1[0]
    return math.comb(total_steps, x_steps) % MODULO

n = 314159265
p1 = (-n, -2025)
p2 = (n, 2025)
O = (0, 0)

p1_p2 = count_paths(p1, p2)
print(f"Số đường đi từ {p1} đến {p2} là: {p1_p2}")

p1_O = count_paths(p1, O)
print(f"Số đường đi từ {p1} đến {O} là: {p1_O}")

print(f"Số đường đi từ {p1} đến {p2} không qua điểm {O} là: {(p1_p2 - p1_O) % MODULO}")
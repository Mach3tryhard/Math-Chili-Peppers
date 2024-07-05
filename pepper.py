import numpy as np
import matplotlib.pyplot as plt
from math import exp, pow, sin, cos, pi, fabs

def F(x):
    rez = 255 * pow(exp(1), pow(-exp(1), -1000 * x))
    rez *= pow(fabs(x), pow(exp(1), pow(-exp(1), 1000 * (x - 1))))
    return rez

def U(s, x, y):
    return cos(17 * x) + sin(17 * s) * y + 2 * sin(8 * s)

def V(s, x, y):
    return cos(17 * s) * y - sin(17 * s) * x + 2 * sin(9 * s)

def W(x, y):
    rez = 0
    for s in range(1, 41):
        frac1 = 11.0 / 10.0
        frac2 = 19.0 / 20.0
        a = pow(cos(pow(frac1, s) * 20 * (cos(2 * s) * x + sin(2 * s) * y) + 2 * sin(s * 5)), 2)
        b = pow(cos(pow(frac1, s) * 20 * (cos(2 * s) * y - sin(2 * s) * x) + 2 * sin(s * 6)), 2)
        rez += pow(exp(1), pow(-exp(1), -2 * a * b - frac2))
    return rez

def P(s, x, y):
    rez = 4 * V(s, x, y) + pow(10, -1) * pow(cos(3 * U(s, x, y) + 2 * V(s, x, y) + cos(4 * V(s, x, y)) + 2), 2)
    rez += pow(10, -1) * pow(cos(9 * U(s, x, y) - 2 * V(s, x, y) + cos(6 * V(s, x, y)) + 1), 2)
    rez += pow(100, -1) * 3 * pow(cos(29 * U(s, x, y) + 7 * V(s, x, y) + cos(5 * V(s, x, y) + 8 * U(s, x, y)) + 1), 4)
    rez += pow(100, -1) * pow(cos(79 * U(s, x, y) - 23 * V(s, x, y) + 2 * cos(15 * V(s, x, y) - 38 * U(s, x, y)) + 1), 4)
    return rez

def Q(s, x, y):
    rez = 2 * U(s, x, y) + pow(10, -1) * pow(cos(3 * V(s, x, y) + 2 * U(s, x, y) + cos(3 * U(s, x, y)) + 2), 2)
    rez += pow(2, -1) * pow(exp(1), pow(-exp(1), 100 * cos(P(s, x, y) - pow(sin(U(s, x, y) + pi / 4), 6))))
    return rez

def K(v, s, x, y):
    frac1 = 7.0 / 10.0
    frac2 = 1.0 / 2.0
    frac3 = 97.0 / 100.0
    frac4 = 1.0 / 50.0
    frac5 = 23.0 / 50.0
    frac6 = 7.0 / 20.0

    a = pow(cos(4 * V(s, x, y) + frac1 * pow(cos(frac2 * Q(s, x, y) + pi / 4), 30)), 12) - frac3
    b = frac4 * pow(cos(frac2 * Q(s, x, y) + pi / 4), 16)
    rez = pow(exp(1), pow(-exp(1), -v * a - b) * pow(-exp(1), 40 * (fabs(pow(cos(frac2 * Q(s, x, y) + pi / 4), 30) - frac5) - frac6)))
    return rez

def L(v, s, x, y):
    frac1 = 1.0 / 2.0
    frac2 = 4.0 / 5.0
    frac3 = 7.0 / 10.0

    a = fabs(cos(P(s, x, y) - pow(sin(frac1 * Q(s, x, y) + pi / 4), 6)))
    rez = pow(exp(1), pow(-exp(1), -v * pow(a, 10 + 9 * sin(Q(s, x, y))) * pow(fabs(cos(Q(s, x, y))), frac2) + frac3 * v))
    return rez

def J(v, s, x, y):
    rez = 1 - (1 - L(v, s, x, y)) * (1 - K(v, s, x, y))
    return rez

def N(s, x, y):
    frac1 = 1.0 / 2.0
    franc2 = 4.0 / 5.0
    franc3 = 96.0 / 25.0

    a = fabs(cos(P(s, x, y) - pow(sin(frac1 * Q(s, x, y) + pi / 4), 6)))
    rez = pow(exp(1), pow(-exp(1), -6 * pow(a, 10 + 9 * sin(Q(s, x, y))) * pow(fabs(cos(Q(s, x, y))), franc2) + franc3))
    return rez

def B(s, x, y):
    a = 1.0 / 2.0 * Q(s, x, y) + pi / 4 + 1.0 / 20.0 * pow(cos(10 * P(s, x, y) + cos(3 * s)), 4)
    rez = pow(exp(1), pow(-exp(1), -100 * (pow(cos(a), 20) - 1.0 / 10.0)))
    return rez

def C(s, v, x, y):
    a = fabs(cos(P(s, x, y)) - pow(sin(1.0 / 2.0 * Q(s, x, y) + pi / 2), 6))
    b = 10 + 9 * sin(Q(s, x, y))
    c = pow(fabs(Q(s, x, y)), 4.0 / 5.0)
    d = (30 + 10 * cos(4 * s)) * (Q(s, x, y) + 3.0 / 100.0 * cos(5 * P(s, x, y))) + 2 * cos(17 * Q(s, x, y) + P(s, x, y) + 2) + cos(27 * Q(s, x, y)) - 17 * P(s, x, y) + 2 * cos(5 * s)
    rez = pow(exp(1), pow(-exp(1), -v * pow(a, b) * c * (1.0 / 10.0 * cos(d) + 9.0 / 10.0) + 97.0 / 100.0 * v - 3.0 / 100.0 * v * W(x, y)))
    return rez

def R(s, x, y):
    a = (30 + 10 * cos(4 * s)) * (Q(s, x, y) + pow(100, -1) * 3 * cos(5 * P(s, x, y))) + 2 * cos(17 * Q(s, x, y) + P(s, x, y) + 2) + cos(27 * Q(s, x, y) - 17 * P(s, x, y) + 2) + 2 * cos(5 * s)
    rez = pow(exp(1), pow(-exp(1), -sin(a)))
    return rez

def A(v, s, x, y):
    rez = pow(10, -1) * (1 - B(s, x, y)) * (4 * v * v - 16 * v + 16 + pow(-1, s) * (11 * v - 5 * v * v - 2) + (5 * v - 3 * v * v + 2) * cos((7 + v) * s) + pow(20, -1) * (40 - s) * (6 * C(20, s, x, y) + 5 * C(5, s, x, y) - 2 * R(s, x, y)))
    rez += pow(10, -1) * (-9 * v * v + 13 * v + 10 + cos((v + 4) * s)) * B(s, x, y) + pow(20, -1) * 3 * W(x, y)
    return rez

def H(v, x, y):
    rez = 0
    for s in range(1, 71):
        produs = 1
        for u in range(0, s):
            produs *= (1 - pow(exp(1), -exp(1) * 1000 * (u - 1.0 / 2.0)) * J(200, u, x, y)) * (1 - 7.0 / 10.0 * pow(exp(1), -exp(1) * 1000 * (u - 1.0 / 2.0)) * N(u, x, y))
        rez += J(200, s, x, y) * A(v, s, x, y) * J(2, s, x, y) * (2.0 / 5.0 + 3.0 / 5.0 * J(20, s, x, y)) * produs
    return rez

# Generate the image
width, height = 2000, 1200
image = np.zeros((height, width, 3), dtype=np.uint8)

for m in range(1, width + 1):
    for n in range(1, height + 1):
        hx0 = H(0, (m - 1000) / 600.0, (601 - n) / 600.0)
        hx1 = H(1, (m - 1000) / 600.0, (601 - n) / 600.0)
        hx2 = H(2, (m - 1000) / 600.0, (601 - n) / 600.0)
        r = int(F(hx0))
        g = int(F(hx1))
        b = int(F(hx2))
        image[n - 1, m - 1] = [r, g, b]

plt.imshow(image)
plt.axis('off')  # Hide axes
plt.show()
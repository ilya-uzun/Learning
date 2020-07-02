number = 1000

def factorial(n):
    if n == 0:
        return 1

    f = 1
    i = 0

    while i < n:
        i += 1
        f = f * i

    return f

print("Факториал числа {n} равен {f}".format
(n=number, f = factorial(number)))
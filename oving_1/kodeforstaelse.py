def isFibonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    return b == n

n = int(input("Skriv inn verdi for n: "))
print(isFibonacciNumber(n))
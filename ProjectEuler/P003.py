n = 600851475143

c = 2
max_prime_factor = 0
while (n > 1):
    if (n % c == 0):
        n /= c
        max_prime_factor = c
    else:
        c += 1

print(max_prime_factor)

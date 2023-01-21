from math import factorial

t = int(input())
for _ in range(t):
    n = int(input())
    ans = (n * (n-1)) * factorial(n)

    print(int(ans % (1000000007)))
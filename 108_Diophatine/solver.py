# we are give n
# task: find how many distinct solution s.t
# 1/x + 1/y = 1/n
from collections import defaultdict

bigN = 2000001

primechk = [True for i in range(bigN+1)]
primes = []

def Sieve():
    for i in range(2, bigN+1):
        if primechk[i]:
            primes.append(i)
            j = 2
            while (i * j <= bigN):
                primechk[i*j] = False
                j += 1

def prime_factorization(n):
    factors = defaultdict(int)

    while (n % 2 == 0):
        n = n >> 1
        factors[2] += 1

    for prime in primes:
        while (n % prime == 0):
            factors[prime] += 1
            n //= prime
    
    i = primes[-1] + 2

    while (i**2 <= n):
        if (n % i == 0):
            factors[i] += 1
            n = n // i
        else:
            i += 2
    if (n > 1):
        factors[n] += 1
    return factors

def diophine(n):
    ps = prime_factorization(n)
    result = 1
    for a in ps.values():
        result *= (2 * a + 1)
    result = (result + 1) // 2
    return result


Sieve()
i = 2
while (diophine(i) < 1000):
    i += 1
    if (i % 1000 == 0): 
        print(i)
print(i)
#t = int(input())
#for _ in range(t):
#    print(diophine(int(input())))



from bisect import bisect_right

products = set()
palindromes = set()

def allproducts():
    for i in range(100, 1000):
        for j in range(100, 1000):
            products.add(i*j)

def allpalindromes():
    for a in range(1, 10):
        for b in range(0, 10):
            for c in range(0, 10):
                num = str(a) + str(b) + str(c) + str(c) + str(b) + str(a)
                palindromes.add(int(num))

allproducts()
allpalindromes()

both = list(products.intersection(palindromes))
both.sort()

def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError


T = int(input())

for t in range(T):
    N = int(input())
    if (N > 906609):
        print(906609)
    else:
        print(find_lt(both, N))


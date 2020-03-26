from math import gcd
import math

primes = []
product_prime = [1]
primorial_euler = [1]
number = 300
for i in range(2,number+1):
    primes.append(i)

i = 2
while(i <= int(math.sqrt(number))):
    if i in primes:
        for j in range(i*2, number+1, i):
            if j in primes:
                primes.remove(j)
    i = i+1

for prime in primes:
    product_prime.append(product_prime[-1] * prime)
    primorial_euler.append(primorial_euler[-1] * (prime-1))

def phi(n): 
    result = n;  
    p = 2;  
    while(p * p <= n): 
          
        if (n % p == 0):  
            while (n % p == 0): 
                n = int(n / p); 
            result -= int(result / p); 
        p += 1; 
  
    if (n > 1): 
        result -= int(result / n); 
    return result; 

def resillience(n):
    return phi(n) / float(n-1)


values = []
values.append([1.0, 2])

for i, product in enumerate(product_prime):
    if (i < 2):
        continue
    values.append([primorial_euler[i] / (product-1), product])
    if (primorial_euler[i] / product < 0.1):
        #print('only these many i', i)
        break

#print("\n".join(map(str,values)))

def findlstv(minn, maxx, delta, q):
    mid = (minn + maxx) // 2
    print(minn, maxx)
    if (mid == minn):
        return maxx * delta
    
    if (resillience(mid*delta) < q):
        return findlstv(minn, mid, delta, q)
    else:
        # mid >= q
        return findlstv(mid, maxx , delta, q)

    

T = int(input())
lastd = 1
for t in range(T):
    a, b = list(map(int, input().split()))
    #q = a / b
    q = 0.1710340400491191
    counter = 0
    for each in values:
        value, d = each
        if (value < q):
            print(findlstv(1,d//lastd,lastd,q))
            #findd = lastd
            #counter = 0
            #while(resillience(findd) >= q):
            #    findd += lastd
            #    counter += 1
            #    #print(lastd, d, d/lastd, counter)
            #print(findd)
            break
        lastd = d


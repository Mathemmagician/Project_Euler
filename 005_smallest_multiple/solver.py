
#T = int(input())
#N = int(input())

nums = [i for i in range(2,41)]
primechk = [True for i in range(41)]

def preprocess():
    primechk[0] = False
    primechk[1] = False
    x = 2
    while (x < 41):
        if (primechk[x]):
            for i in range(2*x, 41, x):
                primechk[i] = False
        x += 1

preprocess()

print(primechk)



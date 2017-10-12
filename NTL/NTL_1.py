import math
n = int(input())

def fac(m, p):
    step = 1 if p ==2 else 2
    for i in range(p, int(math.sqrt(m)+1), step):
        if m % i == 0:
            return i
    return m

result = str(n) + ':'
r = n
p = 2
while r > 1:
    p = fac(r,p)
    r = r//p
    result = result + " " + str(p)

print(result)


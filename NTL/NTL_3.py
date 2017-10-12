n = int(input())
a = [int(i) for i in input().split()]

def gcd(x, y):
    while(y):
        x, y = y, x%y
    return x

def lcm(x, y):
    lcm = (x*y)//gcd(x,y)
    return lcm

ans = 1
for i in a:
    ans = lcm(ans, i)
    
print(ans)


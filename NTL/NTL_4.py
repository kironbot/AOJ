n = int(input())
ans = n

i = 2
while i*i <= n:
    if n%i == 0:
        ans = ans//i*(i-1)
        while n%i == 0:
            n //= i
    i+=1
if n != 1:
    ans = ans//n*(n-1)

print(ans)


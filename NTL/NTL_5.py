r0, r1 = map(int, input().split())
a0, a1 = 1, 0
b0, b1 = 0, 1
while 0 < r1:
    q1 = r0 // r1
    a0, a1 = a1, a0 - q1 * a1
    b0, b1 = b1, b0 - q1 * b1    
    r0, r1 = r1, r0 % r1
 
print(a0, b0)


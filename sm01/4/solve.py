num = list(map(int, str(input()).split()))
sum1,sum2 = 0,0
for x in num:
    if x % 2 == 0:
        sum2 += x
    else:
        sum1 += x
print(sum2)
print(sum1)
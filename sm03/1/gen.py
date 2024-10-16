import sys
import random

t = int(sys.argv[1])
random.seed(t)

len = random.randint(0,200)

s = ""

for i in range(len):
    s += chr(i)
print(s)
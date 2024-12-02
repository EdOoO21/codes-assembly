import sys
import random

t = int(sys.argv[1])
random.seed(t)

a, b = random.randint(-1000000, 100000),random.randint(-1000000, 100000)
print(a)
print(b)
import sys
import random

t = int(sys.argv[1])
random.seed(t)

a,b = random.randint(-1000,1000),random.randint(-1000,1000)
print(a, b)
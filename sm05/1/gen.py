import sys
import random

t = int(sys.argv[1])
random.seed(t)

a,b = random.randint(0, 4294967295), random.randint(0, 4294967295)
print(a, '\n', b)
import sys
import random

t = int(sys.argv[1])
random.seed(t)

size = random.randint(0,100)
arr = [random.randint(-1000,1000) for _ in range(size)]
print(*arr)
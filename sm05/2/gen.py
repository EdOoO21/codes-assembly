import sys
import random

t = int(sys.argv[1])
random.seed(t)

a = random.randint(0, 20)
arr = [random.randint(1, 9223372036854775807) for _ in range(a)]
print(*arr)

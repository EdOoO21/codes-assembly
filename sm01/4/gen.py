import sys
import random

t = int(sys.argv[1])
random.seed(t)

amount_of_numbers = random.randint(0, 120)
arr = [random.randint(-10*6,10*6) for _ in range (amount_of_numbers)]
print(*arr)
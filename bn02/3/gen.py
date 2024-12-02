import sys
import random

t = int(sys.argv[1])
random.seed(t)
print( random.randint(0,1000))
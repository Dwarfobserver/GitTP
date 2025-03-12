# Step 1: Basic output
print("Welcome to the Git exercise!")

# Step 2: A simple calculation
def subtract(a, b):
    return a - b
print("5 - 2 =", subtract(5, 2))

from dev_A_tools import greet
print(greet("Dev.A"))

# Step 3: Random fun
import random
print("Lucky number:", random.randint(1, 100))
from dev_B_tools import square
print("Square of 4:", square(4))

# Step 4: Final message
# print("Great job completing the steps!")
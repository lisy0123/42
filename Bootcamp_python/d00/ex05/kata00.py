"""
- Using string formatting.
"""

NUM = (19, 42, 21)

print("t = {}".format(NUM))
print("The {} numbers are: ".format(len(NUM)), end="")
for i in NUM:
    if i is NUM[len(NUM)-1]:
        print("{}".format(i))
        continue
    print("{}, ".format(i), end="")

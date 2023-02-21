"""
Using string formatting.
"""

NUM = (19, 42, 21)

if __name__ == '__main__':
	print("t =", NUM)
	print("The {} numbers are: ".format(len(NUM)), end="")
	for i in NUM:
		if i is NUM[len(NUM)-1]:
			print("{}".format(i))
			continue
		print(i, end=" ")

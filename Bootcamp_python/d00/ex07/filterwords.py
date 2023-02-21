"""
Rmoves all the words in a string. 
Shorter than or equal to n letters. 
Returns the filtered list with no punctuation. 
Two parameters: a string, and an integer n
"""

import sys

if __name__ == '__main__':
	if sys.argv[1].isalpha() and sys.argv[2].isdigit():
		if len(sys.argv) == 3:
			num = (int)(sys.argv[2])
			STR = (str)(sys.argv[1]).split()
			LIST=[]
			for i in STR:
				if len(i) > num:
					LIST.append(i)
			print(LIST)
		else:
			print("ERROR: Wrong argvs")
	else:
		print("ERROR: Wrong values")

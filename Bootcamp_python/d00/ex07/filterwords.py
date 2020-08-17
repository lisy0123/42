"""
- Rmoves all the words in a string. 
- Shorter than or equal to n letters. 
- Returns the filtered list with no punctuation. 
- Two parameters: a string, and an integer n
"""

import sys

try:
	if len(sys.argv) == 3:
		NUM1 = (int)(sys.argv[2])
		STR1 = (str)(sys.argv[1]).split()
		if STR1[0].isalpha() == True:
			LIST=[]
			for i in range(len(STR1)):
				if len(STR1[i]) > NUM1:
					LIST.append(STR1[i])
			print("{}".format(LIST))
		else:
			print("ERROR1")
	else:
		print("ERROR2")
except:
	print("ERROR3")

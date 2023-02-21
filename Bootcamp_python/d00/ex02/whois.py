'''
Check if a number is odd, even, or zero
Accept only one parameter, an integer
'''

import sys

if __name__ == '__main__':
	if len(sys.argv) == 2:
		try:
			if (int)(sys.argv[1]) == 0:
				print("I'm Zero.")
			elif (int)(sys.argv[1]) % 2 == 0:
				print("I'm Even.")
			else:
				print("I'm Odd.")
		except ValueError:
			print("ERROR")
	elif len(sys.argv) == 1:
		sys.exit()
	else:
		print("ERROR")

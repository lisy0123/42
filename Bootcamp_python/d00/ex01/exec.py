'''
Reverses the order of a string and the case of its words.
More than one arg, merge them into a single string
    and sperate ech arg by a space char.
'''

import sys

if __name__ == '__main__':
	print(' '.join(sys.argv[1:])[::-1].swapcase())

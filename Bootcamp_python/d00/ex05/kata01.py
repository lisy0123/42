"""
Using the language dictionary.
"""

LAN = {
    'Python': 'Guido van Rossum',
    'Ruby': 'Yukihiro Matsumoto',
    'PHP': 'Rasmus Lerdorf',
    }

if __name__ == '__main__':
	print("language =", LAN)
	for i in LAN:
		print(i, "was created by", LAN[i])

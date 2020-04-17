"""
- Using the language dictionary.
"""

LAN = {
    'Python': 'Guido van Rossum',
    'Ruby': 'Yukihiro Matsumoto',
    'PHP': 'Rasmus Lerdorf',
    }

print("language = {}".format(LAN))
for i in LAN:
    print("{} was created by {}".format(i, LAN[i]))

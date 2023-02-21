import random
import unittest


def generator(text, sep = " ", option = None):
	'''Option is an optional arg, sep is mandatory'''
	if not isinstance(text, str) or not isinstance(sep, str) \
		   or option not in [None, 'shuffle', 'unittest', 'ordered']:
		yield("ERROR")
		return

	res = text.split(sep)

	if option == "shuffle":
		random.shuffle(res)
	elif option == "unique":
		tmp = []
		tmp = [word for word in res if word not in tmp]
	elif option == "ordered":
		res.sort()

	for words in res:
		yield(words)
		

class MyTests(unittest.TestCase):
	def test_errors(self):
		self.assertEqual(next(generator(123, sep = " ")), "ERROR")
		self.assertEqual(next(generator("testing", sep = 1.1)), "ERROR")
		self.assertEqual(next(generator("testing", option = "qqq")), "ERROR")

	def test_result(self):
		text = "Le Lorem Ipsum est simplement du faux texte."
		answer = {
			"None": ['Le', 'Lorem', 'Ipsum', 'est', 'simplement', 'du', 'faux', 'texte.'],
			"ordered": ["Ipsum", "Le", "Lorem", "du", "est", "faux", "simplement", "texte."]
		}
		self.assertEqual(list(generator(text)), answer["None"])
		self.assertEqual(list(generator(text, sep = " ", option = "ordered")), answer["ordered"])


if __name__ == '__main__':
	unittest.main()

import unittest


def check(coefs, words) -> bool:
	if len(coefs) != len(words):
		return(False)
	if not all([isinstance(obj, list) for obj in [coefs, words]]):
		return(False)
	if not all ([isinstance(obj, str) for obj in words]):
		return(False)
	if not all ([isinstance(obj, (int, float)) for obj in coefs]):
		return(False)
	return(True)


class Evaluator:
	@staticmethod
	def zip_evaluate(coefs, words) -> float or int:
		if check(coefs, words):
			res = 0
			for word, num in zip(words, coefs):
				res += len(word) * num
		else:
			res = -1
		return(res)
	

	@staticmethod
	def enumerate_evaluate(coefs, words) -> float or int:
		if check(coefs, words):
			res = 0
			for i, word in enumerate(words):
				res += len(word) * coefs[i]
		else:
			res = -1
		return(res)


class MyTests(unittest.TestCase):
	def test_errors(self):
		words = ["Le", "Lorem", "Ipsum", "n'", "est", "pas", "simple"]
		coefs = [0.0, -1.0, 1.0, -12.0, 0.0, 42.42]
		self.assertEqual(Evaluator.zip_evaluate(coefs, words), -1)
		self.assertEqual(Evaluator.enumerate_evaluate(coefs, words), -1)

		coefs = [0.0, -1.0, 1.0, -12.0, 0.0, "33", 42.42]
		self.assertEqual(Evaluator.enumerate_evaluate(coefs, words), -1)


	def test_answers(self):
		words = ["Le", "Lorem", "Ipsum", "est", "simple"]
		coefs = [1.0, 2.0, 1.0, 4, 0.5]
		self.assertEqual(Evaluator.zip_evaluate(coefs, words), 32.0)
		self.assertEqual(Evaluator.enumerate_evaluate(coefs, words), 32.0)


if __name__ == '__main__':
	unittest.main()

import unittest
from ft_filter import *
from ft_map import *
from ft_reduce import *
from functools import reduce


class MyTests(unittest.TestCase):
	@staticmethod
	def func_iterable(wrong_inputs):
		input_type = str(type(wrong_inputs)).split("'")[1]
		return(f"'{input_type}' object is not iterable")


	@staticmethod
	def func_callable(wrong_inputs):	
		input_type = str(type(wrong_inputs)).split("'")[1]
		return(f"'{input_type}' object is not callable")


	def test_error(self):
		func = lambda x: (x % 2 == 0)
		lst = range(10)
		arr = [ft_filter, ft_map, ft_reduce]
		for func in arr:
			with self.assertRaisesRegex(TypeError, self.func_iterable(3)):
				next(func(func, 3))
			with self.assertRaisesRegex(TypeError, self.func_callable("func")):
				next(func("func", lst))


	def test_answers(self):
		func1 = lambda x: (x % 2 == 0)
		func2 = lambda x, y: x + y
		lst = range(10)

		self.assertEqual(list(ft_filter(func1, lst)), list(filter(func1, lst)))
		self.assertEqual(list(ft_map(func1, lst)), list(map(func1, lst)))
		self.assertEqual(ft_reduce(func2, lst), reduce(func2, lst))


if __name__ == '__main__':
	unittest.main()

from utils import *
from vector import Vector
from unittest import  TestCase, main
import numpy as np


class MyTests(TestCase):
	@staticmethod
	def func_warn(index: int, warn_num = 0, ex_num1 = 0, ex_num2 = 1):
		if index == 2:
			return(WARNING[0]+WARNING[warn_num])
		elif index == 4:
			return(WARNING[0]+WARNING[warn_num]+EXAMPLE_TEST[ex_num1]+EXAMPLE_TEST[ex_num2])
		elif index == 12:
			return(WARN[warn_num]+WARN[1])
		elif index == 14:
			return(WARN[warn_num]+WARN[0]+EXAMPLE_TEST[ex_num1]+EXAMPLE_TEST[ex_num2])
		elif index == 13:
			return(WARN[7]+EXAMPLE_TEST[4]+EXAMPLE_TEST[6])


	def test_var_basic_int(self):
		with self.assertRaisesRegex(ValueError, self.func_warn(2, 1)):
			Vector("123")
		with self.assertRaisesRegex(ValueError, self.func_warn(2, 2)):
			Vector(-1)


	def test_var_tuple_range(self):
		arr = [[4, 3, (1,2,3)],
			[4, 4, (1.423, 5.23)],
			[4, 5, (9, 5)]]

		for warn1, warn2, vector_num in arr:
			with self.assertRaisesRegex(ValueError, self.func_warn(warn1, warn2)):
				Vector(vector_num)


	def test_var_list(self):
		arr = [[], 
			[1.3, 3], 
			[[]], 
			[[1.2, 3, 4.5]],
			[[], []], 
			[[1.2, 5.4], [], [5.6]], 
			[[1.2], [3.3], [5.4, 7]]]

		for res in arr:
			with self.assertRaisesRegex(ValueError, self.func_warn(4, 6, 2, 3)):
				Vector(res)


	def test_add(self):
		arr1 = [[Vector(3), "1.1"],
			[Vector([[5.5,1.1,2.2],[2.2,1.1,2.2]]), Vector([[1.1,2.2],[4.4,5.5]])]]
		arr2 = [[Vector([[2.2,6.6],[2.2,4.4],[1.1,2.2]]), Vector([1.1,2.2])],
			[Vector([2.2,6.6,2.2]), Vector([[1.1]])]]

		for num1, num2 in arr1:
			with self.assertRaisesRegex(ValueError, self.func_warn(14, 2, 4, 5)):
				num1 + num2
		for num1, num2 in arr2:
			with self.assertRaisesRegex(ValueError, self.func_warn(12, 2)):
				num1 + num2


	def test_sub(self):
		arr1 = [[Vector(3), "1.1"],
			[Vector([[5.5,1.1,2.2],[2.2,1.1,2.2]]), Vector([[1.1,2.2],[4.4,5.5]])]]
		arr2 = [[Vector([[2.2,6.6],[2.2,4.4],[1.1,2.2]]), Vector([1.1,2.2])],
			[Vector([2.2,6.6,2.2]), Vector([[1.1]])]]

		for num1, num2 in arr1:
			with self.assertRaisesRegex(ValueError, self.func_warn(14, 3, 4, 5)):
				num1 - num2
		for num1, num2 in arr2:
			with self.assertRaisesRegex(ValueError, self.func_warn(12, 3)):
				num1 - num2


	def test_div(self):
		arr = [[4, Vector([1.1, 2.4, 1.1]), "4"],
			[4, Vector([1.1, 2.4, 1.1]), Vector([1.1])],
			[5, Vector([1.1, 2.4, 1.1]), 0]]

		for warn, up, down in arr:
			with self.assertRaisesRegex(ValueError, WARN[warn]):
				up / down


	def test_mul(self):
		arr1 = [[Vector(3), "test"], 
			[Vector([[5.5,1.1,2.2],[2.2,1.1,2.2]]), Vector([[1.1,2.2],[4.4,5.5]])]]
		arr2 = [[Vector([[2.2,6.6],[2.2,4.4],[1.1,2.2]]), Vector([1.1,2.2])],
			[Vector([2.2,6.6,2.2]), Vector([[1.1]])]]

		for num1, num2 in arr1:
			with self.assertRaisesRegex(ValueError, self.func_warn(14, 6, 4, 5)):
				num1*num2
		for num1, num2 in arr2:
			with self.assertRaisesRegex(ValueError, self.func_warn(12, 6)):
				num1*num2


	def test_dot(self):
		arr = [[4, 3.3],
			[4, Vector([[2.0,1.0],[2.2,1.1]])],
			[4, Vector([4.4,3.3,2.2,1.1])],
			[3, Vector([2.0,3.0])]]

		for num, dot_vecotr in arr:
			with self.assertRaisesRegex(ValueError, self.func_warn(13)):
				Vector(num).dot(dot_vecotr)
			

	def test_result(self):
		v1 = [1.0]
		v2 = [1.0, 2.0, 3.0]
		v3 = [[1.0]]
		v4 = [[1.0],[2.0]]
		v5 = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]
		v6 = [[1.0], [2.0], [3.0]]
		v7 = [[1.0, 2.0],[3.0,4.0],[5.0,6.0]]

		def func_np(index, num1, num2):
			if index == "add":
				return(str((np.array(num1)+np.array(num2)).tolist()))
			elif index == "sub":
				return(str((np.array(num1)-np.array(num2)).tolist()))
			elif index == "mul":
				return(str((np.array(num1)*np.array(num2)).tolist()))

		arr = [[Vector((1, 4)), "[1.0, 2.0, 3.0]"],
			[Vector(4), "[0.0, 1.0, 2.0, 3.0]"],
			# add
			[Vector(v7)+3.3, str((np.array(v7)+3.3).tolist())],
			[Vector(v3)+Vector(v4), func_np("add", v3, v4)],
			[Vector(v3)+Vector(v7), func_np("add", v3, v7)],
			[Vector(v4)+Vector(v5), func_np("add", v4, v5)],
			[Vector(v6)+Vector(v7), func_np("add", v6, v7)],
			# sub
			[Vector(v2)-Vector(v1), func_np("sub", v2, v1)],
			[Vector(v3)-Vector(v7), func_np("sub", v3, v7)],
			# div
			[Vector(v7)/2, str((np.array(v7)/2).tolist())],
			[Vector(v7)/0.5, str((np.array(v7)/0.5).tolist())],
			# mul
			[Vector(v2)*Vector(v1), func_np("mul", v2, v1)],
			[Vector(v7)*Vector(v3), func_np("mul", v7, v3)],
			[Vector(v7)*Vector(v6), func_np("mul", v7, v6)],
			# T
			[Vector(v2).T(), str(np.array(v2).T.tolist())],
			[Vector(v7).T(), str(np.array(v7).T.tolist())]]
		
		for vec_str, res in arr:
			self.assertEqual(str(vec_str), res)

		# dot
		self.assertEqual(Vector(v2).dot(Vector(v6)), 
				np.dot(np.array(v2), np.array(v6)).tolist()[0])


if __name__ == '__main__':
	main()

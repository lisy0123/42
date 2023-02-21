from utils import *
from copy import deepcopy


class Vector:
	@staticmethod
	def check_list(arr: list) -> bool:
		if arr == []:
			return(False)
		if all(isinstance(obj, float) for obj in arr):
			return(True)
		if all(isinstance(obj, list) for obj in arr):
			index = []
			for elmnts in arr:
				if len(elmnts) == 0:
					return(False)
				elif len(elmnts) != 1:
					index.append(all(isinstance(obj, float) for obj in elmnts))
				else:
					index.append(isinstance(elmnts[0], float))
			return (all(index) and index != [])
		return(False)


	def __init__(self, variable):
		if isinstance(variable, (int, list, tuple)) == False:
			raise ValueError(WARNING[0]+WARNING[1]+EXAMPLE[1]+EXAMPLE[0])
		if isinstance(variable, int) and variable < 0:
			raise ValueError(WARNING[0]+WARNING[2])
		if isinstance(variable, tuple):
			if len(variable) != 2:
				raise ValueError(WARNING[0]+WARNING[3]+EXAMPLE[0])
			if not all(isinstance(var, int) for var in variable):
				raise ValueError(WARNING[0]+WARNING[4]+EXAMPLE[0])
			if variable[0] >= variable[1]:
				raise ValueError(WARNING[0]+WARNING[5]+EXAMPLE[0])

		values = []
		shape = ()
		if isinstance(variable, list):
			if self.check_list(variable):
				if isinstance(variable[0], float):
					shape = (1, len(variable))
				else:
					shape = (len(variable), len(variable[0]))
			else:
				raise ValueError(WARNING[0]+WARNING[6]+EXAMPLE[1])
			values = deepcopy(variable)
		elif isinstance(variable, int):
			values = [float(num) for num in range(variable)]
			shape = (variable, 1)
		elif isinstance(variable, tuple):
			values = [float(num) for num in range(*variable)]
			shape = (1, variable[1] - variable[0])
		else:
			raise Exception("SOMETHING IS WRONG!")

		self.values = values
		self.shape = shape
		self.size = shape[0] * shape[1]


	def func_same_shape(self, operation, front, back) -> list:
		res = []
		if front.shape[0] == 1:
			if operation == "div":
				for a in front.values:
					res.append(DIC_OP[operation](a, back))
			else:
				for a, b in zip(front.values, back.values):
					res.append(DIC_OP[operation](a, b))
		else:
			tmp = []
			if operation == "div":
				for a in front.values:
					for i in a:
						tmp.append(DIC_OP[operation](i, back))
					res.append(tmp)
					tmp = []
			else:
				for a, b in zip(front.values, back.values):
					for i, j in zip(a, b):
						tmp.append(DIC_OP[operation](i, j))
					res.append(tmp)
					tmp = []
		return(res)


	def func_1_1(self, base, sub, operation) -> list:
		tmp = []
		if base.shape[0] != 1:
			tmp = self.func_x_1(base, sub, operation)
		if base.shape[1] != 1:
			sub.values = deepcopy(tmp) if tmp != [] else sub.values
			tmp = [] if tmp == sub.values else tmp
			tmp = self.func_1_x(base, sub, tmp)
		return(tmp)

	
	@staticmethod
	def func_change(base, sub, index: int, operation):
		if sub.shape[index] != 1:
			if base.shape[index] == 1:
				base, sub = sub, base
			else:
				raise ValueError(WARN[DIC_WARN_NUM[operation]]+WARN[0]+EXAMPLE[2])
		return(base, sub)


	def func_1_x(self, base, sub, operation, tmp = None) -> list:
		base, sub = self.func_change(base, sub, 1, operation)
		tmp = [] if tmp is None else tmp

		if isinstance(sub.values[0], list):
			for obj in sub.values:
				tmp.append([obj[0] for i in range(base.shape[1])])
		else:
			for i in range(base.shape[1]):
				if isinstance(sub.values, list):
					tmp += sub.values
				else:
					tmp.append(sub.values)
		return(tmp)


	def func_x_1(self, base, sub, operation) -> list:
		base, sub = self.func_change(base, sub, 0, operation)

		tmp = []
		for i in range(base.shape[0]):
			if isinstance(sub.values, list):
				tmp += sub.values
			else:
				tmp.append(sub.values)
		return(tmp)


	def func(self, operation, base, sub, index, check = False) -> list:
		functions = [self.func_1_1, self.func_1_x, self.func_x_1]
		tmp = functions[index](base, sub, operation)
		tmp = Vector(tmp)
		if check:
			base, sub = sub, base

		if base.shape != (1, 1) and \
			(sub.shape == (1, 1) or sub.shape[0] == 1 or sub.shape[1] == 1):
			res = self.func_same_shape(operation, base, tmp)
		else:
			res = self.func_same_shape(operation, tmp, sub)
		return(res)


	def func_vector(self, other, operation: str) -> list:
		if (isinstance(self.values[0], list) \
				and isinstance(other.values[0], float)) \
			or (isinstance(self.values[0], float) \
				and isinstance(other.values[0], list)) :
			raise ValueError(WARN[DIC_WARN_NUM[operation]]+WARN[1])
		elif other.shape == self.shape:
			res = self.func_same_shape(operation, self, other)
		elif other.shape == (1,1):
			res = self.func(operation, self, other, 0)
		elif self.shape == (1,1):
			res = self.func(operation, other, self, 0, True)
		elif other.shape[0] == self.shape[0]:
			res = self.func(operation, self, other, 1)
		elif other.shape[1] == self.shape[1]:
			res = self.func(operation, self, other, 2)
		else:
			raise ValueError(WARN[DIC_WARN_NUM[operation]]+WARN[0]+EXAMPLE[2])
		return(res)


	def func_scalar(self, other, operation: str) -> list:
		if self.shape[0] == 1:
			res = [DIC_OP[operation](obj, other) for obj in self.values]
		else:
			res = []
			if isinstance(self.values[0], list):
				for objs in self.values:
					res.append([DIC_OP[operation](obj, other) for obj in objs])
			else:
				res = [DIC_OP[operation](obj, other) for obj in self.values]
		return(res)


	def func_add_sub_mul(self, other, operation: str) -> list:
		if isinstance(other, Vector):
			res = self.func_vector(other, operation)
		elif isinstance(other, (int, float)):
			res = self.func_scalar(other, operation)
		else:
			raise ValueError(WARN[DIC_WARN_NUM[operation]]+WARN[0]+EXAMPLE[2])
		return(res)


# add : scalars and vectors, can have errors with vectors.
	def __add__(self, other):
		res = self.func_add_sub_mul(other, "add")
		return(Vector(res))


	def __radd__(self, other):
		return(self.__add__(other))


# sub : scalars and vectors, can have errors with vectors.
	def __sub__(self, other):
		res = self.func_add_sub_mul(other, "sub")
		return(Vector(res))


	def __rsub__(self, other):
		return(__sub__(other))


# mul : scalars and vectors, can have errors with vectors,
# return a scalar if we perform Vector * Vector (dot product) 
	def __mul__(self, other):
		res = self.func_add_sub_mul(other, "mul")
		return(Vector(res))

	def __rmul__(self, other):
		return(__mul__(otherd))


	def dot(self, other) -> int or float:
		if isinstance(other, Vector):
			res = 0
			if self.shape[0] == 1 and other.shape[1] == 1 \
				and self.shape[1] == other.shape[0]:
				for i in range(other.shape[0]):
					res += other.values[i][0] * self.values[i]
			else:
				raise ValueError(WARN[7]+EXAMPLE[3])
		else:
			raise ValueError(WARN[7]+EXAMPLE[3])
		return(res)


	def T(self):
		res = []
		if isinstance(self.values[0], list):
			if self.shape[1] == 1:
				for objs in self.values:
					res.append(objs[0])
			else:
				tmp = deepcopy(self.values)
				for i in range(self.shape[1]):
					res.append([tmp[j][i] for j in range(self.shape[0])])
		else:
			for obj in self.values:
				res.append(obj)
		return(Vector(res))


# div : only scalars.
	def __truediv__(self, other):
		if not isinstance(other, (float, int)):
			raise ValueError(WARN[4])
		if float(other) == 0.0:
			raise ValueError(WARN[5])
		res = self.func_same_shape("div", self, other)
		return(Vector(res))


	def __rtruediv__(self, other):
		return(__truediv__(other))


# str: output for end user.
	def __str__(self) -> str:
		return(f"{self.values}")


# repr: debugging and development.
	def __repr__(self) -> str:
		return(f"Vector: {self.values} | Shape: {self.shape} | Size: {self.size}")

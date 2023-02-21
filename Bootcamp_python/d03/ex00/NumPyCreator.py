import numpy as np


class NumPyCreator:
	def _check(self, array, dtype: type) -> bool:
		if (not isinstance(array, dtype)):
			return(False)
		is_type = [isinstance(obj, dtype) for obj in array]
		# 1 dimension
		if not any(is_type):
			return(True)
		elif not all(is_type):
			return(False)

		size = None
		for element in array:
			if size is None:
				size = len(element)
			elif len(element) != size:
				return(False)
		return(True)


	def _check_shape(self, shape) -> bool:
		if not (isinstance(shape, tuple) and len(shape) == 2 and \
				all([(isinstance(obj, int) and obj >= 0) for obj in shape])):
			return(False)
		return(True)


	def from_list(self, lst):
		if self._check(lst, list):
			return(np.asarray(lst))
		return(None)


	def from_tuple(self, tpl):
		if self._check(tpl, tuple):
			return(np.asarray(tpl))
		return(None)


	def from_iterable(self, itr):
		if not hasattr(itr, '__iter__'):
			return(None)
		value = list(itr)
		if len(value) == 0:
			return(np.array([]))
		dtype = type(value[0])
		if not all([isinstance(obj, dtype) for obj in value]):
			return(None)
		return(np.array(value))


	def from_shape(self, shape, value=0):
		if not (self._check_shape(shape)):
			return(None)
		if not (isinstance(value, int) and value >= 0):
			return(None)
		return(np.full(shape, value))


	def random(self, shape):
		if not (self._check_shape(shape)):
			return(None)
		return(np.random.random(shape))


	def identity(self, n):
		if not (isinstance(n, int) and n >= 0):
			return(None)
		return(np.identity(n))


def main():
	display_repr = lambda x: print(repr(x))
	npc = NumPyCreator()

	display_repr(npc.from_list([[1,2.2,3],[6,3,4]]))
	display_repr(npc.from_tuple(("a", "b", "c")))
	display_repr(npc.from_iterable(range(5)))

	shape = (3,5)
	display_repr(npc.from_shape(shape))
	display_repr(npc.random(shape))
	display_repr(npc.identity(4))

	# 6 None
	display_repr(npc.from_list("1,2,3"))
	display_repr(npc.from_list([[1,2,3],[6,3,4],[8,5,6,7]]))
	display_repr(npc.from_tuple(1.1))
	display_repr(npc.from_tuple(((1,2,3),(3,1))))
	display_repr(npc.from_shape((-1, 0)))
	display_repr(npc.identity(-1))


if __name__ == '__main__':
	main()

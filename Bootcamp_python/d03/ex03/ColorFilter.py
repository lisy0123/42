from ImageProcessor import ImageProcessor
import numpy as np
from copy import deepcopy
from unittest import TestCase, main


class ColorFilter():
	def _check_ndarray(func):
		def wrap(*args, **kwargs):
			array = args[0]
			if not (isinstance(array, np.ndarray) and 
					('float' in str(array.dtype) or 'int' in str(array.dtype))):
				return(None)
			try:
				value = func(*args, **kwargs)
			except:
				return(None)
			return(value)
		return(wrap)


	@staticmethod
	@_check_ndarray
	def invert(array) -> np.ndarray:
		res = 1 - array
		res[..., 3:] = array[..., 3:]
		return(res)


	@staticmethod
	@_check_ndarray
	def to_blue(array) -> np.ndarray:
		res = np.zeros(array.shape)
		res[..., 2:] = array[..., 2:]
		return(res)


	@staticmethod
	@_check_ndarray
	def to_green(array) -> np.ndarray:
		res = deepcopy(array)
		res[..., ::2] = res[..., ::2] * 0
		return(res)


	@staticmethod
	@_check_ndarray
	def to_red(array) -> np.ndarray:
		only_blue_green = ColorFilter.to_blue(array) + ColorFilter.to_green(array)
		res = array - only_blue_green
		res[..., 3:] = array[..., 3:]
		return(res)


	@staticmethod
	@_check_ndarray
	def to_celluloid(array, tresholds=4) -> np.ndarray:
		bounds = np.linspace(array.min(), array.max(), tresholds)
		res = deepcopy(array)
		lower_bound = bounds[0]

		for upper_bound in bounds[1:]:
			mask = (res[..., :3] > lower_bound) & (res[..., :3] < upper_bound)
			res[..., :3][mask] = lower_bound
			lower_bound = upper_bound
		return(res)


	@staticmethod
	def _check_grayscale(filter: str, **kwargs) -> bool:
		weights = kwargs.pop('weights', None)
		hasWeights = weights is not None

		if ((len(kwargs) != 0) or
				(filter not in ['m', 'mean', 'w', 'weighted']) or
				(filter in ['m', 'mean'] and hasWeights) or
				(filter in ['w', 'weighted'] and
					(not isinstance(weights, list) or len(weights) != 3 or
					 not all([isinstance(obj, float) and obj >= 0 for obj in weights]) 
					 or np.sum(weights) != 1.))):
			return(False)
		return(True)


	@staticmethod
	@_check_ndarray
	def to_grayscale(array, filter: str, **kwargs) -> np.ndarray:
		if not ColorFilter._check_grayscale(filter, **kwargs):
			return(None)
		weights = kwargs.get('weights')
		res = None

		if (filter in ['m', 'mean']):
			mono = np.sum(array[..., :3], axis=2, keepdims=True) / 3
		elif (filter in ['w', 'weighted']):
			mono = np.sum(array[..., :3] * weights, axis=2, keepdims=True)
		res = np.dstack((np.tile(mono, 3), array[..., 3:]))
		return(res)


img_processor = ImageProcessor()
color_filter = ColorFilter()
image = img_processor.load("../resources/sample.png")


class MyTest(TestCase):
	def test_grayscale_errors(self):
		arr = [[['test'], {'weights': [.4, .3, .3]}],
				[['m'], {'test': 1}],
				[['m'], {'weights': 1}],
				[['m'], {'weights': [.4, .3, .3]}],
				[['w'], {'weights': [1., 1., 'a']}],
				[['w'], {'weights': [.4, .3, .3], 'test': 'testing...'}],
				[['w'], {'weights': (.4, .3, .3)}],
				[['w'], {'weights': [.7, -.1, .3]}],
				[['w'], {'weights': [.4, .3, .4]}],
				[['w'], {'weights': [.4, .3, .3, .0]}]]
		for args, kwargs in arr:
			self.assertEqual(img_processor.display(color_filter.to_grayscale(image, *args, **kwargs)), None)


def test_filters(image):
	arr = [["Base", lambda x: x, [], {}],
			["Inverted", color_filter.invert, [], {}],
			["Blue", color_filter.to_blue, [], {}],
			["Green", color_filter.to_green, [], {}],
			["Red", color_filter.to_red, [], {}],
			["Celluloid", color_filter.to_celluloid, [], {}],
			["Grayscale m", color_filter.to_grayscale, ['m'], {}],
			["Grayscale mean", color_filter.to_grayscale, ['mean'], {}],
			["Grayscale w .1 .4 .5", color_filter.to_grayscale, ['w'], {'weights': [.1, .4, .5]}],
			["Grayscale weight .5 .2 .3", color_filter.to_grayscale, ['weighted'], {'weights': [.5, .2, .3]}]]
	for label, func, args, kwargs in arr:
		print(label)
		img_processor.display(func(image, *args, **kwargs))
	

if __name__ == "__main__":
	test_filters(image)
	main()

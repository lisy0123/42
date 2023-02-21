import numpy as np
from ImageProcessor import ImageProcessor
from unittest import TestCase, main


class ScrapBooker:
	@staticmethod
	def _check_array(array) -> bool:
		if not (isinstance(array, np.ndarray)):
			return(False)
		return(True)


	@staticmethod
	def _check_shape(shape) -> bool:
		if not(isinstance(shape, tuple) and len(shape) == 2 \
				and all([(isinstance(obj, int) and obj >= 0) for obj in shape])):
			return(False)
		return(True)


	def crop(self, array, dimensions, position = (0, 0)) -> None or np.ndarray:
		if not (self._check_array(array) and \
				self._check_shape(dimensions) and self._check_shape(position)):
			return(None)
		border_max = (dimensions[0] + position[0], dimensions[1] + position[1])
		if array.shape[0] < border_max[0] or array.shape[1] < border_max[1]:
			return(None)
		res = array[position[0] : border_max[0], position[1] : border_max[1]]
		return(res)


	def thin(self, array, n, axis) -> None or np.ndarray:
		if not (self._check_array(array) and \
				isinstance(n, int) and n > 0 and \
				isinstance(axis, int) and axis in [0, 1]):
			return(None)
		axis = int(not axis)
		index = list(range(n-1, array.shape[axis], n))
		res = np.delete(array, index, axis=axis)
		return(res)


	def juxtapose(self, array, n, axis) -> None or np.ndarray:
		if not (self._check_array(array) and \
				isinstance(n, int) and n > 0 and \
				isinstance(axis, int) and axis in [0, 1]):
			return(None)
		res = np.copy(array)
		for i in range(n - 1):
			res = np.concatenate((res, array), axis=axis)
		return(res)


	def mosaic(self, array, dimensions) -> None or np.ndarray:
		if not (self._check_array(array) and self._check_shape(dimensions)):
			return(None)
		res = self.juxtapose(array, dimensions[0], 0)
		res = self.juxtapose(res, dimensions[1], 1)
		return(res)


arr1 = np.arange(0, 25).reshape(5,5)
arr2 = np.array([[1,2],[3,4],[5,6]])
arr3 = np.array([[var] * 10 for var in "ABCDEFGHI"])

image_processor = ImageProcessor()
scrap = ScrapBooker()
image = image_processor.load("../resources/42AI.png")


class MyTests(TestCase):
	def test_crop(self):
		self.assertEqual(scrap.crop(image, (1234,2), (15,3)), None)
		self.assertEqual(scrap.crop([[1, 2, 3],[4, 5, 6],[7, 8, 9]], (1,2)), None)
		self.assertEqual(scrap.crop(arr1, (3, 2), (2, 1)).tolist(), 
				np.array([[11,12],[16,17],[21,22]]).tolist())


	def test_thin(self):
		arr = [[arr1, 3, 0, 
				[[0,1,3,4],[5,6,8,9],[10,11,13,14],[15,16,18,19],[20,21,23,24]]],
			[arr1, 4, 1, 
				[[0,1,2,3,4],[5,6,7,8,9],[10,11,12,13,14],[20,21,22,23,24]]]]
		for array, n, axis, res in arr:
			self.assertEqual(scrap.thin(array, n, axis).tolist(), 
					np.array(res).tolist())


	def test_juxtapose(self):
		self.assertEqual(scrap.juxtapose(arr2, -2, 0), None)
		arr = [[arr2, 2, 0, 
				np.array([[1,2],[3,4],[5,6],[1,2],[3,4],[5,6]]).tolist()],
			[arr2, 3, 1, 
				np.array([[1,2,1,2,1,2],[3,4,3,4,3,4],[5,6,5,6,5,6]]).tolist()]]
		for array, n, axis, res in arr:
			self.assertEqual(scrap.juxtapose(array, n, axis).tolist(), res)


	def test_mosaic(self):
		self.assertEqual(scrap.mosaic(arr2, (1, 2, 3)), None)
		self.assertEqual(scrap.mosaic(arr2, (2, 3)).tolist(), 
				np.array([[1,2,1,2,1,2],[3,4,3,4,3,4],[5,6,5,6,5,6],
					[1,2,1,2,1,2],[3,4,3,4,3,4],[5,6,5,6,5,6]]).tolist())
		print("Image: 5 x 3")
		image_processor.display(scrap.mosaic(image, (5, 3)))


if __name__ == "__main__":
	main()

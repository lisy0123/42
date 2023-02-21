import numpy as np
from ImageProcessor import ImageProcessor


class AdvancedFilter():
	def make_tmp(self, tmp_array, div_kernel, x_size, y_size=None) -> np.ndarray:
		if y_size is None:
			y_size = x_size
		for i in range(1, div_kernel + 1):
			tmp1 = div_kernel - i + 1
			tmp2 = div_kernel + i
			tmp = 1 + 2 * (i - 1)
			tmp_array = np.concatenate((tmp_array[:tmp1, :] / 2, 
								tmp_array[tmp1:tmp2, :].reshape(tmp, y_size), 
								tmp_array[tmp2:, :] / 2), 
							axis=0)
			tmp_array = np.concatenate((tmp_array[:, :tmp1] / 2, 
								tmp_array[:, tmp1:tmp2].reshape(x_size, tmp), 
								tmp_array[:, tmp2:] / 2), 
							axis=1)
		return(tmp_array)


	def blur(self, array, res, div_kernel, 
			x, y, z, tmp_array, div_sum) -> np.ndarray:
		if div_sum is not None:
			kernel = array[x - div_kernel : x + div_kernel + 1, 
							y - div_kernel : y + div_kernel + 1, z] * tmp_array
		else:
			x_start = x - div_kernel
			x_end = x + div_kernel + 1
			y_start = y - div_kernel
			y_end = y + div_kernel + 1
			if x_start < 0:
				x_start = 0
			if x_end > array.shape[0]:
				x_end = array.shape[0] - 1
			if y_start < 0:
				y_start = 0
			if y_end > array.shape[1]:
				y_end = array.shape[1] - 1

			if isinstance(tmp_array, int):
				div_sum = (x_end - x_start)*(y_end - y_start)
			else:
				x_size = x_end - x_start
				y_size = y_end - y_start
				min_size = min(x_size, y_size)
				tmp_array = np.full((x_size, y_size), (x_size - 1) * (y_size - 1))
				div_kernel = min_size // 2

				tmp_array = self.make_tmp(tmp_array, div_kernel, x_size, y_size)
				div_sum = tmp_array.sum()
			kernel = array[x_start : x_end, y_start : y_end, z] * tmp_array
		total = np.sum(kernel) / div_sum
		res[x, y, z] = total
		return(res)


	def loop(self, x_range, y_range, z_range, 
			array, res, div_kernel, tmp_array=1, div_sum=None) -> np.ndarray:
		for x in x_range:
			for y in y_range:
				for z in z_range:
					res = self.blur(array, res, div_kernel, 
									x, y, z, tmp_array, div_sum)
		return(res)


	def perpare(self, array, kernel_size):
		height = array.shape[0]
		width = array.shape[1]
		depth = array.shape[2]

		if not kernel_size % 2:
			kernel_size -= 1
		div_kernel = kernel_size // 2
		return(height, width, depth, kernel_size, div_kernel)


	def mean_blur(self, array, kernel_size=3) -> np.ndarray:
		height, width, depth, kernel_size, div_kernel = self.perpare(array, kernel_size)
		res = array.copy()
		res = self.loop(range(height), range(width), range(depth), 
						array, res, div_kernel)
		return(res)


	def gaussian_blur(self, array, kernel_size=3) -> np.ndarray:
		height, width, depth, kernel_size, div_kernel = self.perpare(array, kernel_size)
		tmp_array = np.full((kernel_size, kernel_size), 2**(kernel_size - 1))
		tmp_array = self.make_tmp(tmp_array, div_kernel, kernel_size)
		res = array.copy()
		div_sum = tmp_array.sum()

		res = self.loop(range(div_kernel, height - div_kernel), 
						range(div_kernel, width - div_kernel), 
						range(depth), 
						array, res, div_kernel, tmp_array, div_sum)
		x_side = list(range(div_kernel))+list(range(height - div_kernel, height))
		res = self.loop(x_side, range(width), range(depth), 
						array, res, div_kernel, tmp_array)
		y_side = list(range(div_kernel))+list(range(width - div_kernel, width))
		res = self.loop(range(height), y_side, range(depth), 
						array, res, div_kernel, tmp_array)
		return(res)


def test_filters(image):
	img_processor = ImageProcessor()
	advanced_filter = AdvancedFilter()
	image = img_processor.load("../resources/42AI.png")

	img_processor.display(image)
	img_processor.display(advanced_filter.mean_blur(image, 3))
	img_processor.display(advanced_filter.mean_blur(image, 30))
	img_processor.display(advanced_filter.gaussian_blur(image, 30))
	

if __name__ == "__main__":
	test_filters(image)

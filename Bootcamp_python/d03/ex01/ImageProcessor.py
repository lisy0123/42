import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as img


class ImageProcessor():
	@staticmethod
	def load(path: str) -> np.ndarray or None:
		image = None
		try:
			image = img.imread(path)
			print(f"Loading image of dimensions {image.shape[0]} x {image.shape[1]}")
		except Exception as e:
			print(e)
		return(image)

	
	@staticmethod
	def display(array: np.ndarray):
		if not isinstance(array, np.ndarray):
			print("Not numpy array!")
			return
		plt.imshow(array)
		plt.axis("off")
		plt.show()

	
def main():
	image_processor = ImageProcessor()

	def test(path: str):
		print(f"Loading path: {path}")
		image_array = image_processor.load(path)
		print(f"Loading return: {image_array}")
		image_processor.display(image_array)

	test("../resources/42AI.png")


if __name__ == "__main__":
	main()

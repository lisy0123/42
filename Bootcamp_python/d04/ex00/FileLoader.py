import pandas as pd


class FileLoader():
	def load(self, path) -> None or pd.DataFrame:
		if not isinstance(path, str):
			return(None)
		df = None
		try:
			df = pd.read_csv(path)
			print(f"Loading dataset of dimensions {df.shape[0]} x {df.shape[1]}")
		except Exception as e:
			print(f"Exception: {e}")
		return(df)

	
	def display(self, df, n):
		if not (isinstance(df, pd.DataFrame) and isinstance(n, int)):
			print("Wrong pandas.DataFrame!")
			return
		res = df[:n] if (n >= 0) else df[n:]
		print(res)


def test():
	loader = FileLoader()
	data = loader.load("../resources/athlete_events.csv")
	loader.display(data, 3)
	print("=====")
	loader.display(data, 0)
	print("=====")
	loader.display(data, -3)


if __name__ == '__main__':
	test()

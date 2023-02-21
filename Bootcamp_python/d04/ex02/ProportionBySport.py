from FileLoader import FileLoader
import pandas as pd
from unittest import TestCase, main


def proportionBySport(df, year, sport, gender) -> None or float:
	if not (isinstance(df, pd.DataFrame) and isinstance(year, int) and
			isinstance(sport, str) and gender in ['F', 'M']):
		return(None)
	df = df[(df["Year"] == year) & (df["Sex"] == gender)]
	df_tmp = df[df["Sport"] == sport]
	df = len(df.drop_duplicates(subset=["Name"]))
	df_tmp = len(df_tmp.drop_duplicates(subset=["Name"]))
	res = df_tmp / df
	return(res)
	

loader = FileLoader()
data = loader.load('../resources/athlete_events.csv')


class MyTest(TestCase):
	def test_errors(self):
		arr = [["test", 2004, "Tennis", 'F'],
				[data, "test", "Tennis", 'F'],
				[data, 2004, 2004, 'F'],
				[data, 2004, "Tennis", 'D']]
		for df, year, sport, gender in arr:
			self.assertEqual(proportionBySport(df, year, sport, gender), None)
	
	def test_example(self):
		self.assertEqual(proportionBySport(data, 2004, 'Tennis', 'F'), 0.01935634328358209)


if __name__ == '__main__':
	main()

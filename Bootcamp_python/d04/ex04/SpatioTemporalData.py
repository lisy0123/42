from FileLoader import FileLoader
import pandas as pd


class SpatioTemporalData():
	def __init__(self, data):
		self.df = data


	def where(self, date) -> None or list:
		if not isinstance(date, int):
			return(None)
		res = self.df[(self.df['Year'] == date)]['City'].unique().tolist()
		return(res)

	def when(self, location) -> list:
		if not isinstance(location, str):
			return(None)
		res = self.df[(self.df['City'] == location)]['Year'].unique().tolist()
		return(res)


def test():
	loader = FileLoader()
	data = loader.load('../resources/athlete_events.csv')
	sp = SpatioTemporalData(data)
	print(sp.where(1896))
	print(sp.where(2016))
	print(sp.where('2132'))
	print(sp.when('Athina'))
	print(sp.when('Paris'))
	print(sp.when(1342))


if __name__ == '__main__':
	test()

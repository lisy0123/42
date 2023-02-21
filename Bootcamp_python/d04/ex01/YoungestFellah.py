from FileLoader import FileLoader
import pandas as pd


def youngestFellah(df, year) -> None or dict:
	if not (isinstance(df, pd.DataFrame) and isinstance(year, int)):
		return(None)
	dic = {}
	for gender in ['F', 'M']:
		tmp = df.loc[(df["Year"] == year) & (df["Sex"] == gender)]
		dic[gender.lower()] = tmp["Age"].min()
	return(dic)


def test():
	loader = FileLoader()
	data = loader.load('../resources/athlete_events.csv')
	res = youngestFellah(data, 2004)
	print(res)


if __name__ == '__main__':
	test()

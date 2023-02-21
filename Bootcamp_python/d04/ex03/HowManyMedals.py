from FileLoader import FileLoader
import pandas as pd


def howManyMedals(df, name) -> None or dict:
	if not (isinstance(df, pd.DataFrame) and isinstance(name, str)):
		return(None)
	res = {}
	name_df = df[(df['Name'] == name)]
	years = name_df.loc[:, 'Year'].drop_duplicates().sort_values()
	for year in years:
		res[year] = {}
		year_df = name_df[(name_df['Year'] == year)]
		res[year]['G'] = len(year_df[(year_df['Medal'] == 'Gold')])
		res[year]['S'] = len(year_df[(year_df['Medal'] == 'Silver')])
		res[year]['B'] = len(year_df[(year_df['Medal'] == 'Bronze')])
	return(res)


def test():
	loader = FileLoader()
	data = loader.load('../resources/athlete_events.csv')
	res = howManyMedals(data, 'Kjetil Andr Aamodt')
	print(res)


if __name__ == '__main__':
	test()

from FileLoader import FileLoader
import pandas as pd


def howManyMedalsByCountry(df, location) -> None or list:
	if not (isinstance(df, pd.DataFrame) and isinstance(location, str)):
		return(None)
	res = {}
	name_df = df[(df['Team'] == location)].drop_duplicates(subset=['Year', 'Event', 'Medal'])
	years = df.loc[:, 'Year'].drop_duplicates().sort_values()
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
	res = howManyMedalsByCountry(data, 'South Korea')
	print(res)


if __name__ == '__main__':
	test()

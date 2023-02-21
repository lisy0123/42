from FileLoader import FileLoader
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


class MyPlotLib():
	def histogram(self, data, features):
		num_features = len(features)
		fig, ax = plt.subplots(1, num_features)

		for i, feature in enumerate(features):
			ax[i].set_title(feature)
			ax[i].hist(data[feature].dropna())
			ax[i].grid()
		plt.show()


	def density(self, data, features):
		pd.DataFrame(data[features]).plot(kind='density')
		plt.show()


	def pair_plot(self, data, features):
		pd.plotting.scatter_matrix(data[features])
		plt.show()


	def box_plot(self, data, features):
		data.boxplot(column=features)
		plt.grid(False)
		plt.show()


def main():
	loader = FileLoader()
	data = loader.load('../resources/athlete_events.csv')
	mpl = MyPlotLib()

	mpl.histogram(data, ['Height', 'Weight'])
	mpl.density(data, ['Weight', 'Height'])
	mpl.pair_plot(data, ['Weight', 'Height'])
	mpl.box_plot(data, ['Weight', 'Height'])


if __name__ == '__main__':
	main()

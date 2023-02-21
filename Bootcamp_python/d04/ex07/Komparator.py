from FileLoader import FileLoader
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


class Komparator():
	def __init__(self, df):
		self.df = df


	def compare_box_plots(self, categorical_var, numerical_var):
		df = self.df[[categorical_var, numerical_var]].dropna()
		features = df[categorical_var].unique()

		fig, ax = plt.subplots(ncols=len(features))
		for i, feature in enumerate(features):
			ax[i].set_title(feature)
			ax[i].boxplot(df[df[categorical_var] == feature][numerical_var])
		plt.show()


	def density(self, categorical_var, numerical_var):
		df = self.df[[categorical_var, numerical_var]].dropna()
		features = df[categorical_var].unique().tolist()
		
		fig, ax = plt.subplots(ncols=len(features))
		for i, feature in enumerate(features):
			ax[i].set_title(feature)
			df[df[categorical_var] == feature][numerical_var].plot(kind='density', ax=ax[i])
			ax[i].legend()
		plt.show()


	def ompare_histograms(self, categorical_var, numerical_var):
		df = self.df[[categorical_var, numerical_var]].dropna()
		features = df[categorical_var].unique().tolist()
		
		fig, ax = plt.subplots(ncols=len(features))
		for i, feature in enumerate(features):
			ax[i].set_title(feature)
			ax[i].hist(df[df[categorical_var] == feature][numerical_var])
			ax[i].grid()
		plt.show()


def main():
	loader = FileLoader()
	data = loader.load('../resources/athlete_events.csv')
	kom = Komparator(data)

	kom.compare_box_plots('Sex', 'Height')
	kom.density('Sex', 'Height')
	kom.ompare_histograms('Sex', 'Height')



if __name__ == '__main__':
	main()

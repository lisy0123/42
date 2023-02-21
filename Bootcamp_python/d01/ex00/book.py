from recipe import Recipe
from datetime import datetime


class Book:
	'''
	args
		name (str)
		last_update (datetime)
		creation_date (datetime)
		recipes_list (dict): a dictionnary why 3 keys: “starter”, “lunch”, “dessert”.
	'''
	@staticmethod
	def get_current_time() -> str:
		return (datetime.now().strftime("%B %d, %Y %H:%M:%S"))


	def __init__(self, name="Book"):
		self.name = name
		self.creation_date = self.get_current_time()
		self.last_update = self.creation_date
		self.recipes_list = {"starter": [], "lunch": [], "dessert": []}


	def get_recipe_by_name(self, name: str) -> Recipe:
		"""Print a recipe with the name 'name' and return the instance"""
		for foods in self.recipes_list.values():
			for food in foods:
				if (food.name == name):
					return (food)
		print("'%s' is not in recipe book!" %(name))
		return (None)


	def get_recipes_by_types(self, recipe_type: str) -> list:
		"""Get all recipe names for a given recipe_type"""
		if recipe_type in self.recipes_list.keys():
			food_names = [food.name for food in self.recipes_list[recipe_type]]
			return (food_names)
		else:
			print("'%s' is not a recipe type!" %(recipe_type))
			return (None)


	def add_recipe(self, recipe: Recipe) -> None:
		"""Add a recipe to the book and update last_update"""
		if isinstance(recipe, Recipe):
			self.recipes_list[recipe.recipe_type].append(recipe)
			self.last_update = self.get_current_time()
		else:
			print("'%s' is not a recipe!" %(str(recipe)))

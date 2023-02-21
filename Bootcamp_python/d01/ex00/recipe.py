class Recipe:
	'''
	args
		name (str)
		cooking_lvl (int) : range 1 to 5
		cooking_time (int) : in minutes (no negative numbers)
		ingredients (list) : list of all ingredients each represented by a string
		description (str) : description of the recipe
		recipe_type (str) : can be “starter”, “lunch” or “dessert”.
	'''
	def __init__(self, name=None, cooking_lvl=None, cooking_time=None,
			ingredients=None, description=None, recipe_type=None):
		if None is locals().values():
			print("Null arument!")
			exit()

		try:
			self.name = str(name)
			self.cooking_lvl = int(cooking_lvl)
			self.cooking_time = int(cooking_time)
			self.ingredients = list(ingredients)
			self.description = str(description)
			self.recipe_type = str(recipe_type)

			if len(name) == 0:
				raise Exception("No name!")
			if cooking_lvl not in range(1, 6):
				raise Exception("Cooking level is not 1 - 5!")
			if cooking_time < 0:
				raise Exception("Cooking time can't be negative numbers!")
			if len(ingredients) == 0:
				raise Exception("No ingredients!")
			if recipe_type not in ["starter", "lunch", "dessert"]:
				raise Exception("Choose recipe type in 'starter, lunch, dessert'!")

		except (Exception, ValueError) as e:
			print("'%s' exception raised: " %(name), e)
			exit()


	def __str__(self):
		"""Return the string to print with the recipe info"""
		txt = ("This is a %s's recipe!\nCooking level: %d\nCooking time: %d\nRecipe type: %s\nIngredients: %s\n" 
				%(self.name, self.cooking_lvl, self.cooking_time, self.recipe_type, ", ".join(self.ingredients)))
		if self.description != None and len(self.description) != 0:
			txt += "Description: %s" %(self.description)
		return (txt)

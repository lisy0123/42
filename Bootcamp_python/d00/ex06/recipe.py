"""
Write a function to print a recipe from cookbook.
Write a function to delete a recipe from the dictionary.
Write a function to add a new recipe to cookbook with its ingredients, its meal type and its preparation time.
Write a function to print all recipe names from cookbook.
Last but not least, make a program using the four functions.
Prompt the user to make a choice between printing the cookbook, printing only one recipe, adding a recipe, deleting a recipe or quitting the cookbook.
"""


COOKBOOK = {'sandwich': {'ingredients': 'ham, bread, cheese and tomatoes',
                         'meal': 'lunch', 'prep_time': 10},
            'cake': {'ingredients': 'flour, sugar and eggs',
                     'meal': 'dessert', 'prep_time': 60},
            'salad': {'ingredients': 'avocado, arugula, tomatoes and spinach',
                      'meal': 'lunch', 'prep_time': 15}}

PRINTING = [
	"Please select an option by typing the corresponding number:",
	"1: Add a recipe\n2: Delete a recipe\n3: Print a recipe\n4: Print the cookbook\n5: Quit\n",
	"\nPlease enter the recipe's name to add:",
	"\nPlease enter the recipe's name to delete:",
	"\nPlease enter the recipe's name to get its details:",
	"\nThis option does not exist, please type the corresponding number.\nTo exit, enter 5.",
]

WARNING = [
	"\nWrite in number!",
	"Wrong recipe's name!",
]


def add_recipe():
	print(PRINTING[2])
	NAME = input("Name > ")
	INGRE = input("Ingredients > ")
	MEAL = input("Meal > ")
	while 1:
		TIME = input("prep_time > ")
		try:
			(int)(TIME)
			COOKBOOK[NAME] = {'ingredients': INGRE, 'meal':
							  MEAL, 'prep_time': (int)(TIME)}
			break
		except ValueError:
			print(WARNING[0])
	print("\n{}: {}".format(NAME, COOKBOOK[NAME]))


def delete_recipe():
	try:
		print(PRINTING[3])
		NAME = input("> ")
		del COOKBOOK[NAME]
		print("\nDelete", NAME)
	except KeyError:
		print("\nNO %s in COOKBOOK" %(NAME))


def print_recipe():
	print(PRINTING[4])
	NAME = input("> ")
	try:
		print("\nRecipe for "+NAME+":")
		print("Ingredients list: [%s]\nTo be eaten for %s.\nTakes %d minutes of cooking."
				%(COOKBOOK[NAME]['ingredients'],
					COOKBOOK[NAME]['meal'],
					COOKBOOK[NAME]['prep_time']))
	except KeyError:
		print(WARNING[1])


def check(NUM):
	if NUM == "1":
		add_recipe()
	if NUM == "2":
		delete_recipe()
	if NUM == "3":
		print_recipe()
	if NUM == "4":
		for i in COOKBOOK:
			print(i+": "+str(COOKBOOK[i]))
	elif NUM == "5":
		print("\nCookbook closed.")
		exit()


def loop():
	print(PRINTING[0])
	print(PRINTING[1])
	while 1:
		NUM = input(">> ")
		try:
			(int)(NUM)
			check(NUM)
		except ValueError:
			print(PRINTING[5])


if __name__ == '__main__':
	loop()

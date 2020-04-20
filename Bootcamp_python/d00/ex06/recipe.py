"""
- Write a function to print a recipe from cookbook.
    parameter: name of the recipe.
- Write a function to delete a recipe from the dictionary.
    parameter: name of the recipe.
- Write a function to add a new recipe to cookbook with its ingredients,
    its meal type and its preparation time.
    parameters: name of recipe, ingredients, meal and prep_time.
- Write a function to print all recipe names from cookbook.
- Last but not least, make a program using the four functions.
- Prompt the user to make a choice between printing the cookbook,
    printing only one recipe, adding a recipe,
    deleting a recipe or quitting the cookbook.
"""

import sys

COOKBOOK = {'sandwich': {'ingredients': 'ham, bread, cheese and tomatoes',
                         'meal': 'lunch', 'prep_time': 10},
            'cake': {'ingredients': 'flour, sugar and eggs',
                     'meal': 'dessert', 'prep_time': 60},
            'salad': {'ingredients': 'avocado, arugula, tomatoes and spinach',
                      'meal': 'lunch', 'prep_time': 15}}


def print_recipes(names):
    """
    Print recipes.
    """
    if names == "sandwich":
        print("Recipe for cake:\n")
        print("Ingredients list: [{}] To be eaten for {}.\n"
              .format(COOKBOOK[names][0], COOKBOOK[names][1]))
        print("Takes {} minutes of cooking.\n".format([][2]))


print("Please select an option by typing the corresponding number:\n")
print("1: Add a recipe\n2: Delete a recipe")
print("3: Print a recipe\n4: Print the cookbook\n5: Quit\n")
NUM = input(">> ")
if NUM == "3":
    print("Please enter the recipe's name to get its details:")
    NAME = input(">> ")
    try:
        print ("Recipe for {}".format(NAME))
        print("Ingredients list: [{}]\nTo be eaten for {}."
              .format(COOKBOOK[NAME]['ingredients'], COOKBOOK[NAME]['meal']))
        print("Takes {} minutes of cooking.".format(COOKBOOK[NAME]['prep_time']))
    except KeyError:
        print ("Wrong recipe's name!")
elif NUM == "5":
    print("Cookbook closed.")
    sys.exit()

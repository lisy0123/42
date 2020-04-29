"""
- Write a function to print a recipe from cookbook.
- Write a function to delete a recipe from the dictionary.
- Write a function to add a new recipe to cookbook with its ingredients,
    its meal type and its preparation time.
- Write a function to print all recipe names from cookbook.
- Last but not least, make a program using the four functions.
- Prompt the user to make a choice between printing the cookbook,
    printing only one recipe, adding a recipe,
    deleting a recipe or quitting the cookbook.
"""

COOKBOOK = {'sandwich': {'ingredients': 'ham, bread, cheese and tomatoes',
                         'meal': 'lunch', 'prep_time': 10},
            'cake': {'ingredients': 'flour, sugar and eggs',
                     'meal': 'dessert', 'prep_time': 60},
            'salad': {'ingredients': 'avocado, arugula, tomatoes and spinach',
                      'meal': 'lunch', 'prep_time': 15}}


print("Please select an option by typing the corresponding number:\n")
print("1: Add a recipe\n2: Delete a recipe")
print("3: Print a recipe\n4: Print the cookbook\n5: Quit\n")
while 1:
    NUM = input(">> ")
    try:
        (int)(NUM)
        if NUM == "1":
            print("\nPlease enter the recipe's name to add:")
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
                    print("\nWrite in number!")
            print("\n{}: {}".format(NAME, COOKBOOK[NAME]))
        if NUM == "2":
            try:
                print("\nPlease enter the recipe's name to delete:")
                NAME = input("> ")
                del COOKBOOK[NAME]
                print("\nDelete {}".format(NAME))
            except KeyError:
                print("\nNO {} in COOKBOOK".format(NAME))
        if NUM == "4":
            for i in COOKBOOK:
                print("{}: {}".format(i, COOKBOOK[i]))
        if NUM == "3":
            print("\nPlease enter the recipe's name to get its details:")
            NAME = input("> ")
            try:
                print("\nRecipe for {}:".format(NAME))
                print("Ingredients list: [{}]\nTo be eaten for {}."
                      .format(COOKBOOK[NAME]['ingredients'],
                              COOKBOOK[NAME]['meal']))
                print("Takes {} minutes of cooking."
                      .format(COOKBOOK[NAME]['prep_time']))
            except KeyError:
                print("Wrong recipe's name!")
        elif NUM == "5":
            print("\nCookbook closed.")
            break
    except ValueError:
        print("\nThis option does not exist", end='')
        print("please type the corresponding number.")
        print("To exit, enter 5.")

from book import Book
from recipe import Recipe


if __name__ == "__main__":
	book = Book()

	soup = Recipe("soup", 1, 321, ["apple, banana"], "Meal!", "lunch")
	testing = Recipe("testing", 1, 321, ["apple, banana"], "Meal!", "dessert")
	test = Recipe("test", 1, 321, ["apple, banana"], "Meal!", "dessert")
	error = [123, "asdf"]

	book.add_recipe(soup)
	book.add_recipe(testing)
	book.add_recipe(test)
	book.add_recipe(error)

	print("Get soup:", str(book.get_recipe_by_name("soup")))
	print("Get pizza:", str(book.get_recipe_by_name("pizza")))
	print("Lunch:", str(book.get_recipes_by_types("lunch")))
	print("Dessert:", str(book.get_recipes_by_types("dessert")))
	print("Error: ", str(book.get_recipes_by_types("error")))
	print(book.last_update)

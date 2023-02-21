class GotCharacter:
	'''
	A class representing a GoT House

	args
		first_name (str)
		is_alive (bool, by default is True)
	'''
	def __init__(self, first_name: str = None, is_alive: bool = True):
		self.first_name = first_name
		self.is_alive = is_alive


class Stark(GotCharacter):
	'''
	A class representing the Stark family. Or when bad things happen to good people.

	methods
		print_house_words: prints to screen the House words
		die: changes the value of is_alive to False
	'''
	def __init__(self, first_name=None, is_alive=True):
		super().__init__(first_name=first_name, is_alive=is_alive)
		self.family_name = "Stark"
		self.house_words = "Winter is Coming"

	def print_house_words(self):
		print(self.house_words)

	def die(self):
		self.is_alive = False


if __name__ == "__main__":
	arya = Stark("Arya")
	print(arya.__dict__)
	arya.print_house_words()
	print(arya.is_alive)
	arya.die()
	print(arya.is_alive)
	print(arya.__doc__)
	print(GotCharacter.__doc__)

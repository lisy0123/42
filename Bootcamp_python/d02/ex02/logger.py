import time
from random import randint
import os


def log(func):
	username = os.getenv("USER") or "USER"
	description = func.__name__.replace('_', ' ').title()

	def process(*args, **kwargs):
		with open("machine.log", 'a') as f:
			begin_time = time.time()
			values = func(*args, **kwargs)
			exec_time = time.time() - begin_time
			unit = 's '
			if exec_time < .5:
				unit = "ms"
				exec_time *= 1000
			f.write("(%s) Raunning: %-20s [ exec-time = %.3f %s ]\n" %(username, description, exec_time, unit))
		return(values)
	return(process)


class CoffeeMachine():
	water_level = 100

	@log
	def start_machine(self):
		if self.water_level > 20:
			return True
		else:
			print("Please add water!")
			return False

	@log
	def boil_water(self):
		return "boiling..."

	@log
	def make_coffee(self):
		if self.start_machine():
			for _ in range(20):
				time.sleep(0.1)
				self.water_level -= 1
			print(self.boil_water())
			print("Coffee is ready!")

	@log
	def add_water(self, water_level):
		time.sleep(randint(1, 5))
		self.water_level += water_level
		print("Blub blub blub...")


if __name__ == "__main__":
	machine = CoffeeMachine()
	for i in range(0, 5):
		machine.make_coffee()

	machine.make_coffee()
	machine.add_water(70)

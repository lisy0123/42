"""
Make a program that will be an interactive guessing game. 
Guess a number between 1 and 99. 
Tell the user if their input is too high or too low. 
Ends when the user finds out the secret number or types exit.
Count the number of trials. 
Print that number when the user wins.
Discovers the secret number on the first try, tell them. 
If the secret number is 42, make a reference to Douglas Adams.
"""

import random

NUM = random.randint(1,99)


def game():
	count = 0
	guess = 0

	while NUM != guess:
		print("What's your guess between 1 and 99?")
		try:
			guess = input(">> ")
			if guess == "exit":
				print("Goodbye!")
				exit(1)
			guess = (int)(guess)
			if guess > NUM:
				print("Too high!")
			if guess < NUM:
				print("Too low!")
		except ValueError:
			print("That's not a number.")
		count += 1
	if NUM == 42:
		print("The answer to the ultimate question of life, the universe and everything is 42.")
	if count == 1:
		print("Congratulations! You got it on your first try!")
	else:
		print("Congratulations, you've got it!")
		print("You won in", count, "attempts!")


if __name__ == '__main__':
	print("This is an interactive guessing game!")
	print("You have to enter a number between 1 and 99 to find out the secret number.")
	print("Type 'exit' to end the game.\nGood luck!\n")
	game()

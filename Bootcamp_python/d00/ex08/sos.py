"""
Make a function which encodes strings into Morse code. 
Accept all alphanumeric characters.
"""

import sys

DIC_MORSE = {
	'a' : ".-", 'b' : "-...", 'c' : "-.-.", 'd' : "-..",
    'e' : ".", 'f' : "..-.", 'g' : "--.", 'h' : "....",
	'i' : "..", 'j' : ".---", 'k' : "-.-", 'l' : ".-..",
	'm' : "--", 'n' : "-.", 'o' : "---", 'p' : ".--.",
	'q' : "--.-", 'r' : ".-.", 's' : "...", 't' : "-",
	'u' : "..-", 'v' : "...-", 'w' : ".--", 'x' : "-..-",
	'y' : "-.--", 'z' : "--..", 
	'0' : "-----", '1' : ".----", '2' : "..---", '3' : "...--", 
	'4' : "....-", '5' : ".....", '6' : "-....", '7' : "--...",
	'8' : "---..", '9' : "----."
}


if __name__ == '__main__':
	try:
		STR=[]
		STR1=""
		for i in range(1, len(sys.argv)):
			STR = STR + (str)(sys.argv[i]).split()
		for j in range(len(STR)):
			for c in STR[j].lower():
				STR1 = STR1 + "".join([DIC_MORSE[c]]) + " "
			if j != len(STR)-1:
				STR1 = STR1 + "/ "
		print(STR1)
	except:
		print("ERROR")

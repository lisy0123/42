"""
- Make a function which encodes strings into Morse code. 
- Accept all alphanumeric characters.
"""

import sys

dic_morse = {
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

try:
	STR=[]
	STR1=""
	for i in range(1, len(sys.argv)):
		STR = STR + (str)(sys.argv[i]).split()
#	print("{}".format(STR))
	for j in range(len(STR)):
		for c in STR[j].lower():
			STR1 = STR1 + "".join([dic_morse[c]]) + " "
		if j != len(STR)-1:
			STR1 = STR1 + "/ "
	print("{}".format(STR1))
except:
	print("ERROR")

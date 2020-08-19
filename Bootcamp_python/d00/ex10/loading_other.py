"""
- Make loading bar
"""

import sys
import time

def progressBar(value, endvalue, bar_length=20):
	percent = float(value) / endvalue
	arrow = '-' * int(round(percent * bar_length)-1) + '>'
	spaces = ' ' * (bar_length - len(arrow))
	sys.stdout.write("\rPercent: [{0}] {1}%".format(arrow + spaces, int(round(percent * 100))))
	time.sleep(0.05)
	sys.stdout.flush()

for i in range(0,101):
	progressBar(i,100)

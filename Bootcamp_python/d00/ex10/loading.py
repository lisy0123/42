"""
- Make loading bar, using yield operator. 
"""

from time import sleep
import time

def ft_progress(lst):
	start = time.time()
	for i in lst:
		percent = int(i / len(lst) * 100.9)
		if percent == 0:
			percent = 1
		bar = '=' * int(percent / 5) + '>'
		t = time.time() - start
		eta = t * (100 / percent) - t
		print("ETA: {0:5.2f}s [{1:3d}%][{2:20.20s}] {3}/{4} | elapsed time {5:5.2f}s".format(eta, percent, bar, i+1, len(lst), t), end='\r')
		yield i
	print("ETA: {0:5.2f}s [{1:3d}%][{2:20.20s}] {3}/{4} | elapsed time {5:5.2f}s".format(eta, percent, bar, i+1, len(lst), t))
	print("...", end='')

listy = range(1000)
ret = 0
for elem in ft_progress(listy):
	ret += (elem + 3) % 5
	sleep(0.01) 
print()
print(ret)

listy = range(3333)
ret = 0
for elem in ft_progress(listy):
	ret += elem
	sleep(0.005)
print()
print(ret)

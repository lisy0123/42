"""
Given the tuple above, whose values stand for: (hour, minutes, year, month, day).
"""

TIME = (3, 30, 2019, 9, 25)

if __name__ == '__main__':
	print("TIME =", TIME)
	print("{:02d}/{:02d}/{:04d} {:02d}:{:02d}".format((int)(TIME[3]),
                                                  (int)(TIME[4]),
                                                  (int)(TIME[2]),
                                                  (int)(TIME[0]),
                                                  (int)(TIME[1])))

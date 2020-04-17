"""
- Given the tuple above, whose values stand for:
    (hour, minutes, year, month, day)
"""

TIME = (3, 30, 2019, 9, 25)

print("TIME = {}".format(TIME))
print("{}/{}/{} {}:{}".format(TIME[3].rjust(2,'0'), TIME[4], TIME[2], TIME[0], TIME[1]))

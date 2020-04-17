"""
- make a program that prints the results of the four elementary mathematical
    operations of arithmetic (addition, subtraction, multiplication, division)
    and the modulo operation.
- Takes 2 numbers as parameters and returns 5 values.
"""

import sys


def usage():
    """
    Default message
    """
    print("Usage: python operations.py <number1> <number2>")
    print("Example:\n   python operations.py 10 3")


try:
    if len(sys.argv) == 3:
        NUM1 = (int)(sys.argv[1])
        NUM2 = (int)(sys.argv[2])
        print("Sum:         {}".format(NUM1+NUM2))
        print("Difference:  {}".format(abs(NUM1-NUM2)))
        print("Product:     {}".format(NUM1*NUM2))
        if NUM2 == 0:
            print("Quotient:    ERROR (div by zero)")
            print("Remainder:   ERROR (modulo by zero)")
        else:
            print("Quotient:    {}".format(NUM1 / NUM2))
            print("Remainder:   {}".format(NUM1 % NUM2))
        sys.exit()
    elif len(sys.argv) == 2:
        (int)(sys.argv[1])
        print("InputError: need one more arguments\n")
    elif len(sys.argv) > 3:
        for i in sys.argv:
            if i == "operations.py":
                continue
            (int)(i)
        print("InputError: too many arguments\n")
except ValueError:
    print("InputError: only numbers\n")
usage()

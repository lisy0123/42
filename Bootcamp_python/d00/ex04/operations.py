"""
- make a program that prints the results of the four elementary mathematical
    operations of arithmetic (addition, subtraction, multiplication, division)
    and the modulo operation.
- Takes 2 numbers as parameters and returns 5 values.
"""

import sys

def usage():
    print("Usage: python operations.py <number1> <number2>")
    print("Example:\n   python operations.py 10 3")

try:
    if len(sys.argv)==3:
        num1=(int)(sys.argv[1])
        num2=(int)(sys.argv[2])
        print("Sum:         {}".format(sum(num1, num2)))
        print("Difference:  {}".format(abs(num1-num2))
        print("Product:     {}".format(num1*num2))
        if num2==0:
            print("Quotient:     ERROR (div by zero)")
            print("Remainder:   ERROR (modulo by zero)")
        else:
            print("Quotient:    {}".format(num1 / num2))
            print("Remainder:   {}".format(num1 % num2))
    elif len(sys.argv)==1:
        usage()
    else:
        print("InputError: too many arguments\n")
        usage()
except ValueError:
    print("InputError: only numbers\n")
    usage()

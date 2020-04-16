'''
- Create a function called text_analyzer
    that dispplays the sums of upper characters, lower characters,
    puncuation characters and spaces in a given text.
- Takes 1 parameter, the text to analyze.
- If there is no text passed to the function,
    the user is prompted to give one.
'''

import string


def text_analyzer(argv=None):
    '''
    This function counts the number of upper characters, lower characters,
    punctuation and spaces in a given text. '''
    if argv is None:
        print("What is the text to analyse?")
        argv = input(">> ")
    print("The text contains {} characters:\n".format(len(argv)))
    upper = sum(i.isupper() for i in argv)
    lower = sum(i.islower() for i in argv)
    puncuation = sum((i in string.punctuation) for i in argv)
    space = sum(i.isspace() for i in argv)
    print("- {} upper letters\n".format(upper))
    print("- {} lower letters\n".format(lower))
    print("- {} punctuation marks\n".format(puncuation))
    print("- {} spaces".format(space))

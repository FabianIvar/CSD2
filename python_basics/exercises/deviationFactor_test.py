# code to test deviation factor

import random
import numpy as np
import math

# input: start, stop, amount
def listRange(**inp):
    """
    Returns a list of a given length with even steps between two given values

    parameter start: The starting value of the sequence
    parameter stop: The end value of the sequence
    parameter num: The amount of values
    """

    # Sets devault value if 'start' or 'num' argument aren't present in the inp (input) dictionary
    default = {'start':0, 'num':10}
    for i in default:
        if(not {True for key in inp.keys() if i in key}): # very hard to understand but very cool! dictionary comprehension!
            inp[i] = default[i]

    listRange = np.linspace(inp['start'], inp['stop'], num=inp['num'], endpoint=True)

    return listRange

sequence = [1]*11

def deviation(**inp):

    """
    Returns a list of a given length containing the deviation values to add to... maybe duration? *subject to change

    parameter list: list with duration values to dertermine the amount of notes and the total length
    parameter amt: maximum deviation
    (parameter min: minimum deviation) *not implemented yet
    """

    list = inp['list'] # For readability, 'list' represents the list thats given as an argument to the function
    amt = inp['amt'] # Also for readability, 'amt' represents the maximum deviation
    halfDuration = sum(list)/2

    # list <len(list)> values between -halfDuration and halfDuration in even steps
    savedRange = listRange(start = -halfDuration, stop = (halfDuration), num = len(list))

    # Convert the numpy array 'sanvedRange' to a list with rounded float values
    roundedRange = [round(float(value),10) for value in savedRange] # List comprehension!!!

    # Scale roundedRange to (min = -1 max = 1)
    scaledFactor = [value / halfDuration for value in roundedRange]

    # Shuffle scaledFactor
    shuffledFactor = random.sample(scaledFactor, len(scaledFactor)) # random.sample makes a copy, random.shuffle modifies list

    # Max amount
    deviation = [amt*shuffledFactor.pop() for value in scaledFactor]

    print('\nDeviation:',deviation)



deviation(list = sequence, amt = 20)


'''Sources
values between range:   https://stackoverflow.com/questions/64338441/how-to-get-the-values-between-a-range-in-python#64338552
multiply list:          https://www.geeksforgeeks.org/python/sum-function-python/
devide list:            https://www.geeksforgeeks.org/python/divide-all-elements-of-a-list-by-a-number-in-python/
list comprehension:     https://www.geeksforgeeks.org/python/python-list-comprehension/
check dict for item:    https://www.geeksforgeeks.org/python/check-if-dictionary-value-contains-certain-string-with-python/
dict comprehension:     https://www.geeksforgeeks.org/python/python-dictionary-comprehension
numer odd or even?:     https://stackoverflow.com/questions/21837208/check-if-a-number-is-odd-or-even-in-python#21837247
shuffle list:           https://www.geeksforgeeks.org/python/python-ways-to-shuffle-a-list/
random:                 https://www.w3schools.com/python/ref_module_random.asp
random.sample:          https://www.w3schools.com/python/ref_random_sample.asp
'''

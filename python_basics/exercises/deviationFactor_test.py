from random import randint as random

# code to test deviation_factor
# print(random(1,10))
sequence = []

for i in range(11):
    sequence.append(i)

def deviationFactor(**set):
    factor = []
    for i in range(len(set['seq'])-1):
        factor.append(((len(set['seq'])-i)-1) / (len(set['seq'])-1))
        print(i)
    factor.append(0)
    print(factor)
    print('factor length', len(factor))



""" Explanation for arguments in decreasing_deviation:

length is how many generations it takes before deviation is gone;
amount is how drastic the deviation is -> amount is constrained so that the cycle is still has the same length as before

"""
def deviation(list, deviation_length, relative_deviation_amount):
    '''creates dictionary with values that deviate less every generation'''
    deviationFactor(length = deviation_length)
    deviation = {}

decreasing_deviation(sequence, 4, 0.5)



# print(sequence)

# First with only one tracks



pulses = 16
notes = 5

def halve_values(values):
    """Halves the numeric values in the values list"""
    for i in range(len(values)):
        values[i] *= 0.5

def halve_values_alt(values):
    """Halves the numeric values in the values list"""
    for value in values:
        values[value-1] *= 0.5
        """this works somehow?? -> works because list = 1,2,3,4,5.
        Ik dacht dat als je 'in values' doet ipv 'in range(len(values))' dat het enige verschil was dat het begon bij de index 1 ipv 0.
        Maar dat kwam dus doordat ik toevallig een testlijst had gemaakt waarbij het 1,2,3,4,5 was,
        dat werkt natuurlijk want values[value-1] is gewoon 0,1,2,3,4"""

"""list = [0.5,2.5,3.8,4.6,5.1] # Won't work because the index of the array can't be a float"""

list = [1,2,3,4,5]

""" ?!!! """

test_list = [3,1,7,3,4]

def test(values):
    for value in values:
        print(value)

halve_values_alt(list)
test(test_list)

print(list)

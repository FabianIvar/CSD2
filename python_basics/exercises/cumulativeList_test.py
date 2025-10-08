"""
make a cumulative_list that for every index in input_list
adds the current index of input_list + all the values from the previous indexes."""

def cumulative(input_list):

    # Make empty list to store values in
    cumulative_list = []

    for i in range(len(input_list)):
        for j in range(i+1):
            cumulative_list.append(sum([input_list[j]]))

    print(cumulative_list)
    return cumulative_list

testList = [4,8,1,3]

# print(sumList(testList, 4))

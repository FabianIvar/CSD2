def cumulative(input_list):
    """
    make a list that for every index in input_list
    adds the current index of input_list + the previous value.
    """
    timestamps = []

    for i in range(len(input_list)):
        timestamps.append(sum([input_list[j] for j in range(i)]))

    return timestamps

testList = [4,8,1,3]

print(cumulative(testList))

"""
Given a list of integers, let's decide that two consecutive
items in the list are neighbours if their difference is 1.
So, items 1 and 2 would be neighbours, and so would items 56 and 55

Wirte a function named longest_series_of_neighbors, which looks
for the longest series of neighbours within the list, and returns its length

For example in the list [1, 2, 5, 4, 3, 4] the longest list of 
neighbours would be [5, 4, 3, 4] with a length of 4"""

def is_neighbor(num1, num2):
    if abs(num2 - num1) == 1:
        return True
    else:
        return False

def longest_series_of_neighbors(list):
    if not list: 
        return 0
    
    longest_current = 1
    current = 1
    for i in range(len(list)-1): 
        first = list[i]
        next = list[i+1]
        if is_neighbor(first, next):
            current += 1 
        else: 
            current = 1
        longest_current = max(longest_current, current)
    return longest_current

def test():
    testcases = [
        { 
            "list" : [1, 2, 5, 7, 6, 5, 6, 3, 4, 1, 0],
            "expected" : 4
        },
        {
            "list" : [1],
            "expected" : 1
        },
        {
            "list": [],
            "expected": 0
        },
        {
            "list": [1, 2, 5, 4, 3, 4],
            "expected": 4
        }
    ]
    for testcase in testcases:
        ret = longest_series_of_neighbors(testcase["list"])
        print(ret)
        assert ret == testcase["expected"]


if __name__ == '__main__':
    test()
# Name : Atherv Patil
# Github ID : ColonelAVP
# searching an element X in a array using Linear search
# Time Complexity = O(n) | Space Complexity = O(1)


def Linear_search(arr, n, x):
    for i in range(0, n):  # searching x element at every index in arr
        if arr[i] == x:
            return i  # this program returns index at which the element is present
    return -1  # if num doesnt exists, it returns -1


# driver code
arr = [10, 20, 35, 60, 70, 110, 120, 140]
x = 110
n = len(arr)

result = Linear_search(arr, n, x)  # our defined function is stored in var. result

if result == -1:
    print("Element doesn't exists !!")
else:
    print("Element is at index", result)

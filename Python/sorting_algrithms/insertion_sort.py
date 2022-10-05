# Name : Atherv Patil
# Github ID : ColonelAVP
# fn to Sort a array using Insertion Sort
# Time Complexity = O(n^2) and Space Complexity = O(1)


def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        temp = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > temp:
            arr[j + 1], arr[j] = arr[j], arr[j + 1]
            j -= 1
            # print(arr) To verify each itertion
    return arr


# Driver's Code
arr = [5, 4, 3, 2, 1]
print(insertion_sort(arr))

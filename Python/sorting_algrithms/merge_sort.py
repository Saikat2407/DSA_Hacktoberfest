# Name : Atherv Patil
# Github ID : ColonelAVP
# fn to sort array using merge Sort
# Time Complexity - O(nlogn) & Space Complexity - O(1)
def mergesort(arr):
    n = len(arr)
    if n > 1:
        mid = n // 2
        left = arr[:mid]
        right = arr[mid:]
        mergesort(left)
        mergesort(right)
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1
    return arr


# Driver's Code
arr = [10, 3, 4, 1, 17, 6, 19, 5, 223, 4, 6, 6, 75, 8, 5, 2, 59]
print(mergesort(arr))

# The Quick Sort Algorithm initially requires selecting a pivot element, based on which the array division will be implemented. This pivot element selection can be carried out in four ways:

#To pick the first element of the array
#To pick the last element of the array 
#To pick a random element from the array
#Here we implement the algorithm using the last element as the pivot in each of the sub-arrays.

#Then the array in question is partitioned into two halves by considering each element to be greater or lesser than the pivot element. Elements that are lesser than the pivot element are put on the left-hand side of the pivot, and the ones greater are put on the right. The pivot element is ultimately placed in the center.

#Thus all the elements on the left are smaller than the pivot element, and all the elements on the right are bigger. The Quick Sort algorithm is then applied on each of the sub-arrays created after division, individually.

def partition(array, left, right, pivot):
    while left < right:
        while left < right:
            if array[pivot] > array[right]:
                break
            right = right - 1
        while left < right:
            if array[pivot] < array[left]:
                break
            left = left + 1
        if left < right:
            array[left], array[right] = array[right], array[left]
    if array[left] > array[pivot]:
        array[left], array[pivot] = array[pivot], array[left]
        return left
    else:
        array[left + 1], array[pivot] = array[pivot], array[left + 1]
        return left + 1

def QuickSort(array, start, stop):
    if stop <= start:
        return
    else:
        part = partition(array, start, stop-1, stop)
        QuickSort(array, start, part-1)
        QuickSort(array, part+1, stop)

array1 = [8, 9, 2, 0, 7, 1, 6, 4, 3, 5]
QuickSort(array1, 0, len(array1)-1)
print(array1)

# Time Complexity: O(n^2) 
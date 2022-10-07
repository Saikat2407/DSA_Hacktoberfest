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
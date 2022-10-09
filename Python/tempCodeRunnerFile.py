def partition(a, lo, hi):
	pivot = a[hi]
	i = lo - 1
	for j in range(lo, hi):
		if a[j] <= pivot:
			i = i + 1
			(a[i], a[j]) = (a[j], a[i])
	(a[i + 1], a[hi]) = (a[hi], a[i + 1])
	return i + 1
def quickSort(a, lo, hi):
	if lo < hi:
		pi = partition(a, lo, hi)
		quickSort(a, lo, pi - 1)
		quickSort(a, pi + 1, hi)
data = [2, 6, 3, 78, -10, 19, -2]
print("Unsorted Array")
print(data)
size = len(data)
quickSort(data, 0, size - 1)
print('Sorted Array in Ascending Order:')
print(data)

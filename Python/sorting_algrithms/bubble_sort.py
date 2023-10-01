# Python3 program for Bubble Sort Algorithm Implementation
def bubbleSort(arr):
	
	n = len(arr)

	# For loop to traverse through all
	# element in an array
	for i in range(n):
		for j in range(0, n - i - 1):
			
			# Range of the array is from 0 to n-i-1
			# Swap the elements if the element found
			#is greater than the adjacent element
			if arr[j] > arr[j + 1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
				


# creating an empty list
arr = []

# number of elements as input
n = int(input("Enter number of elements : "))

# iterating till the range
for i in range(0, n):
	ele = int(input())
	# adding the element
	arr.append(ele)

print(arr)


bubbleSort(arr)

print("Sorted array is:")
for i in range(len(arr)):
	print("%d" % arr[i])

# Python program for implementation of Insertion Sort

# Function to do insertion sort
def insertionSort(arr):

	# Traverse through 1 to len(arr)
	for i in range(1, len(arr)):

		key = arr[i]

		# Move elements of arr[0..i-1], that are
		# greater than key, to one position ahead
		# of their current position
		j = i-1
		print("arra bef-",arr,'cursor at:',key)
		while j >= 0 and key < arr[j] :
				arr[j + 1] = arr[j]
				j -= 1
				print('after innser op',arr)
		arr[j + 1] = key
		print("arra after",arr)


# Driver code to test above
arr = [7,6,5,4,3,2]
insertionSort(arr)
for i in range(len(arr)):
	print ("% d" % arr[i])

# This code is contributed by Mohit Kumra

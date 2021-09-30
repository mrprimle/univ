# Sorting algorithms in python: Implementations, Time and Space complexeties, non-comparison sorts,
# sorts with keys and with multiple parameters

# Standart Build in sort takes O(Nlog(N)) time in worst case
def pythonBuildInSort(nums):
    return sorted(nums)


# O(n^2) worse case
def insertionSort(nums):
    # Traverse through 1 to len(nums)
    for i in range(1, len(nums)):

        key = nums[i]

        # Move elements of nums[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i - 1
        while j >= 0 and key < nums[j]:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = key


# O(Nlog(N)) guarantied
def mergeSort(nums):
    if len(nums) > 1:
        mid = len(nums) // 2

        # Dividing the array elements
        L = nums[:mid]
        R = nums[mid:]

        mergeSort(L)
        mergeSort(R)

        i = j = k = 0

        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                nums[k] = L[i]
                i += 1
            else:
                nums[k] = R[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(L):
            nums[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            nums[k] = R[j]
            j += 1
            k += 1


def partition(nums, low, high):
    i = (low - 1)  # index of smaller element
    pivot = nums[high]  # pivot

    for j in range(low, high):

        # If current element is smaller than or
        # equal to pivot
        if nums[j] <= pivot:
            # increment index of smaller element
            i = i + 1
            nums[i], nums[j] = nums[j], nums[i]

    nums[i + 1], nums[high] = nums[high], nums[i + 1]
    return (i + 1)


# The main function that implements QuickSort
# nums[] --> Array to be sorted,
# low  --> Starting index,
# high  --> Ending index

# Function to do Quick sort


# O(Nlog(N)) but if partitioning is bad could be O(N ^ 2)
def quickSort(nums, low, high):
    if len(nums) == 1:
        return nums
    if low < high:
        # pi is partitioning index, nums[p] is now
        # at right place
        pi = partition(nums, low, high)

        # Separately sort elements before
        # partition and after partition
        quickSort(nums, low, pi - 1)
        quickSort(nums, pi + 1, high)


# For large inputs recursive solution could cause stack overflow, therefore here is an iterative version with stack
def quickSortIterative(nums, l, h):
    # Create an auxiliary stack
    size = h - l + 1
    stack = [0] * (size)

    # initialize top of stack
    top = -1

    # push initial values of l and h to stack
    top = top + 1
    stack[top] = l
    top = top + 1
    stack[top] = h

    # Keep popping from stack while is not empty
    while top >= 0:

        # Pop h and l
        h = stack[top]
        top = top - 1
        l = stack[top]
        top = top - 1

        # Set pivot element at its correct position in
        # sorted array
        p = partition(nums, l, h)

        # If there are elements on left side of pivot,
        # then push left side to stack
        if p - 1 > l:
            top = top + 1
            stack[top] = l
            top = top + 1
            stack[top] = p - 1

        # If there are elements on right side of pivot,
        # then push right side to stack
        if p + 1 < h:
            top = top + 1
            stack[top] = p + 1
            top = top + 1
            stack[top] = h


# Non-comparison Radix sort
def countingSort(nums, exp1):
    n = len(nums)

    # The output array elements that will have sorted nums
    output = [0] * (n)

    # initialize count array as 0
    count = [0] * (10)

    # Store count of occurrences in count[]
    for i in range(0, n):
        index = nums[i] // exp1
        count[index % 10] += 1

    # Change count[i] so that count[i] now contains actual
    # position of this digit in output array
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    i = n - 1
    while i >= 0:
        index = nums[i] // exp1
        output[count[index % 10] - 1] = nums[i]
        count[index % 10] -= 1
        i -= 1

    # Copying the output array to nums[],
    # so that nums now contains sorted numbers
    i = 0
    for i in range(0, len(nums)):
        nums[i] = output[i]


# Method to do Radix Sort
# O((n+b) * logb(k)
def radixSort(nums):
    # Find the maximum number to know number of digits
    max1 = max(nums)

    # Do counting sort for every digit. Note that instead
    # of passing digit number, exp is passed. exp is 10^i
    # where i is current digit number
    exp = 1
    while max1 / exp > 0:
        countingSort(nums, exp)
        exp *= 10



# Sorts by second number in array of pairs
def sortBySecondElem(pair):
    return sorted(pair, key = lambda x: x[1])


# Sorts words by length or other function (comporator)
def sortBySecondElem(words):
    return sorted(words, key = len)





































# Sorting Algorithms Comparison

## Data Structures

long long comp = 0;   // Global counter for comparisons
long long swaps = 0;  // Global counter for swaps/movements


## Functions Implemented

**Utility Function:**

**1. void printArr(int a[], int n)**
- Prints all elements of the array
- Iterates through the array and displays each element

**Sorting Algorithms:**

**2. void bubble(int a[], int n)**
- Implements Bubble Sort algorithm
- Algorithm:
  - Compares adjacent elements and swaps if they are in wrong order
  - Repeats for n-1 passes
  - In each pass, largest unsorted element bubbles to its correct position
- Counts comparisons and swaps

**3. void selection(int a[], int n)**
- Implements Selection Sort algorithm
- Algorithm:
  - Finds the minimum element from unsorted portion
  - Swaps it with the first unsorted element
  - Repeats until entire array is sorted
- Counts comparisons and swaps

**4. void insertion(int a[], int n)**
- Implements Insertion Sort algorithm
- Algorithm:
  - Builds sorted array one element at a time
  - Takes each element and inserts it into its correct position in sorted portion
  - Shifts elements to make space for insertion
- Counts comparisons and swaps

**5. void merge(int a[], int l, int m, int r)**
- Merges two sorted subarrays into one sorted array
- Parameters:
  - l: Left index
  - m: Middle index
  - r: Right index
- Creates temporary arrays for left and right halves
- Merges them back into original array in sorted order
- Counts comparisons and movements

**6. void mergeSort(int a[], int l, int r)**
- Implements Merge Sort algorithm using divide-and-conquer
- Algorithm:
  - Divides array into two halves recursively
  - Sorts each half
  - Merges the sorted halves using merge() function
- Base case: when left index >= right index

## Main Method Organization

1. Prompts user to enter the size of array
2. Generates random array:
   - Seeds random number generator with current time
   - Fills array with random numbers between 1 and 1000
3. Displays the original unsorted array
4. Presents sorting algorithm menu:
   - 1. Bubble Sort
   - 2. Selection Sort
   - 3. Insertion Sort
   - 4. Merge Sort
5. Reads user's choice
6. Executes selected sorting algorithm:
   - Resets comparison and swap counters
   - Calls corresponding sorting function
7. Displays the sorted array
8. Displays performance metrics:
   - Total number of comparisons
   - Total number of swaps/movements
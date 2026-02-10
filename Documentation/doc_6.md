# Heap (Min and Max)

## Functions Implemented

**Helper Functions:**

**1. void swap(int *a, int *b)**
- Swaps the values of two integers
- Uses a temporary variable for the swap

**2. int left(int i)**
- Returns the index of the left child of node at index i
- Formula: `2*i + 1`

**3. int right(int i)**
- Returns the index of the right child of node at index i
- Formula: `2*i + 2`

**Heapify Functions:**

**4. void minHeapify(Heap *h, int i)**
- Maintains the min-heap property at index i
- Algorithm:
  - Compares node with its left and right children
  - Finds the smallest among node and its children
  - If smallest is not the current node, swaps and recursively heapifies

**5. void maxHeapify(Heap *h, int i)**
- Maintains the max-heap property at index i
- Algorithm:
  - Compares node with its left and right children
  - Finds the largest among node and its children
  - If largest is not the current node, swaps and recursively heapifies

**Heap Operations:**

**6. Heap* buildHeap(int arr[], int n, int isMin)**
- Builds a heap from an array
- Parameters:
  - `arr[]`: Input array
  - `n`: Size of array
  - `isMin`: 1 for min-heap, 0 for max-heap
- Algorithm:
  - Allocates memory for heap structure and array
  - Copies elements from input array
  - Heapifies from last non-leaf node to root (bottom-up)
- Returns pointer to the created heap

**7. int extractRoot(Heap *h, int isMin)**
- Removes and returns the root element (minimum or maximum)
- Algorithm:
  - Stores root value
  - Replaces root with last element
  - Decreases heap size
  - Heapifies from root to restore heap property
- Returns the extracted root value, or -1 if heap is empty

**8. void displayHeap(Heap *h, char *name)**
- Displays all elements in the heap in level-order
- Prints heap name followed by elements

## Main Method Organization

1. Defines an array of 12 integers: `{45, 12, 78, 34, 89, 23, 67, 11, 56, 90, 3, 44}`
2. Builds two heaps from the same array:
   - Min-heap using `buildHeap(arr, n, 1)`
   - Max-heap using `buildHeap(arr, n, 0)`
3. Displays both heaps
4. Extracts and prints the minimum element from min-heap
5. Displays the min-heap after extraction
6. Extracts and prints the maximum element from max-heap
7. Displays the max-heap after extraction
8. Frees allocated memory for both heaps
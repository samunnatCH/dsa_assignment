# Linked List Reverse Print 


## Functions Implemented

**1. void append(int val)**
- Adds a new node with value val at the end of the list
- If list is empty, new node becomes the head
- Otherwise, traverses to the last node and links the new node

**2. void prepend(int val)**
- Adds a new node with value val at the beginning of the list
- New node's link points to the current head
- Updates head to point to the new node

**3. void printForward()**
- Prints all nodes in the list from head to tail
- Traverses the list iteratively using a temporary pointer
- Output format: [ value1 value2 value3 ]

**4. void printReverseHelper(Node node)**
- Recursive helper function to print nodes in reverse order
- Base case: if node is NULL, return
- Recursive case: call itself with next node, then print current node's value
- Uses call stack to achieve reverse order printing

**5. void printReverse()**
- Prints all nodes in reverse order without modifying the list
- Calls printReverseHelper() starting from head
- Output format: [ valueN ... value2 value1 ]

## Main Method Organization

1. Prints program title
2. First test - Using append():
   - Adds values 5, 10, 15, 20, 25 to the list using append()
   - Prints list in forward order
   - Prints list in reverse order
3. Resets the list (head = NULL)
4. Second test - Using prepend():
   - Adds values 100, 80, 60, 40, 20 to the list using prepend()
   - Prints list in forward order
   - Prints list in reverse order
# Doubly Linked List 

## Functions Implemented

**1. void show()**
- Displays all nodes in the list from first to last
- If list is empty, prints "List is empty"
- Traverses using the `following` pointer
- Output format: `List: value1 value2 value3`

**2. void addBegin(int value)**
- Adds a new node with given value at the beginning of the list
- New node's `previous` is set to NULL
- New node's `following` points to current first node
- Updates first node's `previous` to point to new node
- Updates `first` to point to the new node

**3. void addEnd(int value)**
- Adds a new node with given value at the end of the list
- If list is empty, new node becomes the first node
- Otherwise, traverses to the last node and links the new node
- Sets bidirectional links between last node and new node

**4. void insertAfter(Node* prevNode, int value)**
- Inserts a new node with given value after the specified node
- Returns if `prevNode` is NULL
- Sets new node's `previous` to `prevNode` and `following` to `prevNode->following`
- Updates bidirectional links with adjacent nodes
- Prints confirmation message

**5. void deleteNode(int value)**
- Deletes the first node containing the specified value
- Searches for the node with the given value
- If not found, prints "Value not found" message
- Updates bidirectional links to bypass the deleted node
- Handles special cases: deleting first node, last node, or middle node
- Frees the memory of the deleted node
- Prints confirmation message

## Main Method Organization

1. Prints program title
2. Adds nodes at the beginning:
   - Adds 30, 20, 10 using `addBegin()` (resulting in: 10, 20, 30)
   - Displays the list
3. Adds nodes at the end:
   - Adds 40, 50 using `addEnd()`
   - Displays the list
4. Inserts a node in the middle:
   - Inserts 25 after the second node (20) using `insertAfter()`
   - Displays the list
5. Deletes nodes:
   - Deletes 25 (middle node)
   - Displays the list
   - Deletes 10 (first node)
   - Displays the list
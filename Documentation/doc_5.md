# Graph Traversal (BFS and DFS) 

**Constants:**
- `MAX_VERTICES`: Maximum number of vertices allowed (20)

## Functions Implemented

**Graph Operations:**

**1. void initGraph(Graph* g, int vertices)**
- Initializes a graph with specified number of vertices
- Sets all adjacency matrix values to 0 (no edges)

**2. void addEdge(Graph* g, int src, int dest)**
- Adds an undirected edge between source and destination vertices
- Sets both `adjMatrix[src][dest]` and `adjMatrix[dest][src]` to 1
- Validates vertex indices before adding edge

**3. void displayGraph(Graph* g)**
- Displays the adjacency matrix representation of the graph
- Shows vertex numbers as column and row headers
- Prints 1 for connected vertices, 0 for non-connected

**Queue Operations:**

**4. void initQueue(Queue* q)**
- Initializes queue by setting front and rear to -1

**5. bool isQueueEmpty(Queue* q)**
- Returns true if queue is empty (front == -1), false otherwise

**6. void enqueue(Queue* q, int val)**
- Adds element to the rear of the queue
- If queue is empty, sets front to 0

**7. int dequeue(Queue* q)**
- Removes and returns element from the front of the queue
- Resets front and rear to -1 if queue becomes empty
- Returns -1 if queue is empty

**Stack Operations:**

**8. void initStack(Stack* s)**
- Initializes stack by setting top to -1

**9. bool isStackEmpty(Stack* s)**
- Returns true if stack is empty (top == -1), false otherwise

**10. void push(Stack* s, int val)**
- Pushes element onto the stack
- Increments top and stores value

**11. int pop(Stack* s)**
- Pops and returns the top element from the stack
- Returns -1 if stack is empty

**Traversal Algorithms:**

**12. void BFS(Graph* g, int start)**
- Breadth-First Search traversal starting from given vertex
- Algorithm:
  - Uses a queue to process vertices level by level
  - Marks starting vertex as visited and enqueues it
  - Dequeues vertex, prints it, and enqueues all unvisited adjacent vertices
  - Continues until queue is empty

**13. void DFS(Graph* g, int start)**
- Depth-First Search traversal starting from given vertex
- Algorithm:
  - Uses a stack to process vertices depth-first
  - Pushes starting vertex onto stack
  - Pops vertex, marks as visited, prints it
  - Pushes all unvisited adjacent vertices onto stack (in reverse order)
  - Continues until stack is empty

## Main Method Organization

1. Prints program title
2. Creates a graph with 7 vertices (0 to 6)
3. Adds edges to form a connected graph:
   - Edges: (0,1), (0,2), (1,3), (1,4), (2,5), (2,6), (3,4), (5,6)
4. Displays the adjacency matrix representation
5. Performs traversals from vertex 0:
   - BFS starting from vertex 0
   - DFS starting from vertex 0
6. Performs traversals from vertex 3:
   - BFS starting from vertex 3
   - DFS starting from vertex 3
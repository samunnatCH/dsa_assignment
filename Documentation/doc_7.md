# Dijkstra's Shortest Path Algorithm 

**Constants:**
- MAX: Maximum number of vertices allowed (20)
- INF: Represents infinity (INT_MAX) for unreachable vertices

## Functions Implemented

**Graph Operations:**

**1. void initGraph(Graph *g, int n)**
- Initializes a graph with n vertices
- Sets all adjacency matrix values to 0 (no edges)

**2. void addEdge(Graph *g, int u, int v, int w)**
- Adds an undirected weighted edge between vertices u and v
- Sets weight w in both adj[u][v] and adj[v][u]

**Dijkstra's Algorithm Functions:**

**3. int minDistance(int dist[], bool visited[], int n)**
- Finds the vertex with minimum distance value from the set of unvisited vertices
- Algorithm:
  - Iterates through all vertices
  - Returns the index of unvisited vertex with smallest distance
  - Returns -1 if no unvisited vertex found

**4. void dijkstra(Graph *g, int src)**
- Finds shortest paths from source vertex to all other vertices using Dijkstra's algorithm
- Algorithm:
  - Initialize all distances to INF except source (set to 0)
  - Mark all vertices as unvisited
  - For each vertex:
    - Select unvisited vertex with minimum distance
    - Mark it as visited
    - Update distances of all adjacent unvisited vertices
    - New distance = min(current distance, distance through current vertex)
  - Prints shortest distance from source to each vertex

## Main Method Organization

1. Creates a graph with 6 vertices (0 to 5)
2. Adds weighted edges:
   - (0,1,4), (0,2,3), (1,2,1), (1,3,2), (2,3,4), (3,4,2), (4,5,6), (2,4,5)
3. Runs Dijkstra's algorithm from vertex 0:
   - Displays shortest distances from vertex 0 to all other vertices
4. Runs Dijkstra's algorithm from vertex 3:
   - Displays shortest distances from vertex 3 to all other vertices
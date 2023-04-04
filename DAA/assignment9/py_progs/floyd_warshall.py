// Apply Floyd Warshall algorithm to find out shortest
// path between every pairs of vertices of the graph
// shown below. The graph is stored in adjacency matrix.

//   ---               ---
//   | 0   3   8   ∞  -4 |
//   | ∞   0   ∞   1   7 |
//   | ∞   4   0   ∞   ∞ |
//   | 2   ∞  -5   0   ∞ |
//   | ∞   ∞   ∞   6   0 |
//   ---               ---

# define the graph as an adjacency matrix
graph = [
    [0, 3, 8, float('inf'), -4],
    [float('inf'), 0, float('inf'), 1, 7],
    [float('inf'), 4, 0, float('inf'), float('inf')],
    [2, float('inf'), -5, 0, float('inf')],
    [float('inf'), float('inf'), float('inf'), 6, 0]
]

# initialize the distance matrix
dist = graph

# apply the Floyd Warshall algorithm
for k in range(len(graph)):
    for i in range(len(graph)):
        for j in range(len(graph)):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

# print the shortest distance between every pair of vertices
print("Shortest distance between every pair of vertices:")
for row in dist:
    print(row)


//OUTPUT
//Shortest distance between every pair of vertices:
//[0, 1, -3, 2, -4]
//[3, 0, -4, 1, -1]
//[7, 4, 0, 5, 3]
//[2, -1, -5, 0, -2]
//[8, 5, 1, 6, 0]

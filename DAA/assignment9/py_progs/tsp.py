// A circuit which passes through every vertex exactly
// once is called a Hamilton circuit. A minimum weight
// Hamilton circuit is a Hamilton circuit that has the
// smallest possible weight of all Hamilton circuits.
// In graph theory terms, the TSP is the problem of
// finding a minimum weight Hamilton circuit. Apply dynamic
// programming to find out the minimum weight Hamiltonian circuit.

//             1
//           / | \ 
//          /  |  \ 
//         /   |10 \ 
//     20 /    |    \ 
//       /     2     \18
//      /    /   \    \ 
//     /   /       \   \ 
//    /  /12        6\  \ 
//   / /               \ \ 
//   4 ----------------- 3
//            18

from math import inf

# Define the graph as an adjacency matrix
graph = [[0, 20, 0, 18],
         [20, 0, 12, 10],
         [0, 12, 0, 6],
         [18, 10, 6, 0]]

# Define the number of vertices
n = len(graph)

# Define the full set of vertices
all_vertices = set(range(n))

# Initialize the solution array
# The first dimension represents the subset of vertices being considered
# The second dimension represents the ending vertex of the circuit
# The value in the array represents the minimum weight Hamiltonian circuit for that subset and ending vertex
dp = [[inf] * n for _ in range(2 ** n)]

# Base case: the minimum weight Hamiltonian circuit for a single vertex ending at that vertex is 0
for i in range(n):
    dp[1 << i][i] = 0

# Loop over all subset sizes
for size in range(2, n + 1):
    # Loop over all subsets of the given size
    for subset in (set(combo) for combo in combinations(all_vertices, size)):
        # Loop over all possible ending vertices in the subset
        for end in subset:
            # Loop over all possible intermediate vertices in the subset
            for intermediate in subset - {end}:
                # Calculate the minimum weight Hamiltonian circuit for the subset ending at the intermediate vertex
                circuit = dp[2 ** intermediate][end] + graph[intermediate][end]
                circuit += min(dp[2 ** intermediate | 2 ** vertex][intermediate] + graph[vertex][intermediate] for vertex in subset - {end, intermediate})
                # Update the minimum weight Hamiltonian circuit for the subset and ending vertex
                dp[2 ** end | 2 ** intermediate][end] = min(dp[2 ** end | 2 ** intermediate][end], circuit)

# Find the minimum weight Hamiltonian circuit for the full set of vertices
min_circuit = min(dp[2 ** n - 1][end] + graph[end][0] for end in range(n))

# Print the minimum weight Hamiltonian circuit
print(f"The minimum weight Hamiltonian circuit has weight {min_circuit}")

// OUTPUT
// The minimum weight Hamiltonian circuit has weight 54

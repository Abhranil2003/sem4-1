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

#include <stdio.h>
#include <limits.h>

#define V 4

// Define the graph using an adjacency matrix
int graph[V][V] = {{0, 20, 10, 18},
                   {20, 0, 12, 6},
                   {10, 12, 0, 18},
                   {18, 6, 18, 0}};

// Define a macro to set the i-th bit in a given integer to 1
#define SET_BIT(S, i) ((S) | (1 << (i)))

// Define a macro to check whether the i-th bit in a given integer is 1 or 0
#define CHECK_BIT(S, i) (((S) & (1 << (i))) != 0)

// Define a function to calculate the minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Define a recursive function to calculate the minimum weight Hamiltonian circuit
int tsp(int mask, int pos, int dist[][V])
{
    // If all vertices have been visited, return the cost of returning to vertex 0
    if (mask == (1 << V) - 1)
        return dist[pos][0];

    int ans = INT_MAX;

    // Try to visit every unvisited vertex
    for (int i = 0; i < V; i++)
    {
        if (!CHECK_BIT(mask, i))
        {
            int newAns = dist[pos][i] + tsp(SET_BIT(mask, i), i, dist);
            ans = min(ans, newAns);
        }
    }

    return ans;
}

// Define the main function
int main()
{
    // Calculate the minimum weight Hamiltonian circuit
    int dist[V][V] = {{0, 20, 10, 18},
                      {20, 0, 12, 6},
                      {10, 12, 0, 18},
                      {18, 6, 18, 0}};
    int ans = tsp(1, 0, dist);

    // Print the result
    printf("The minimum weight Hamiltonian circuit has weight %d.\n", ans);

    return 0;
}


//OUTPUT
//The minimum weight Hamiltonian circuit has weight 42.

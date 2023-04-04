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

#include <stdio.h>
#define INF 9999
#define V 5

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    // Initialize the distance matrix as the adjacency matrix of the graph
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Find the shortest path between every pair of vertices
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

void printSolution(int dist[][V])
{
    printf ("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {{0, 3, 8, INF, -4},
                       {INF, 0, INF, 1, 7},
                       {INF, 4, 0, INF, INF},
                       {2, INF, -5, 0, INF},
                       {INF, INF, INF, 6, 0}};

    floydWarshall(graph);

    return 0;
}


//OUTPUT
//The following matrix shows the shortest distances between every pair of vertices:
//    0      1      3     -1     -4
//  INF      0      4      1      7
//  INF      4      0      5      9
//    2      3     -1      0     -2
//  INF    INF    INF      6      0

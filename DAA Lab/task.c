 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a graph
struct Graph {
    int V;
    int** adjMatrix; // 2D array to represent the adjacency matrix
};

// Function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

// Function to print the minimum spanning tree
void printMST(int parent[], struct Graph* graph) {
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->V; i++) {
        int src = parent[i];
        int dest = i;
        int weight = graph->adjMatrix[src][dest];

        printf("(%d, %d) - %d\n", src + 1, dest + 1, weight);
    }
}

// Function to construct and find the minimum spanning tree
void findMinimumSpanningTree(struct Graph* graph) {
    int parent[graph->V]; // Array to store constructed MST
    int key[graph->V];    // Key values used to pick minimum weight edge
    bool mstSet[graph->V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < graph->V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;       // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;    // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < graph->V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u;
        int min = INT_MAX;
        for (int v = 0; v < graph->V; v++) {
            if (!mstSet[v] && key[v] < min) {
                u = v;
                min = key[v];
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->V; v++) {
            if (!mstSet[v] && graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);

    // Find and print the shortest path between user-input vertices
    int srcVertex, destVertex;
    printf("\nEnter the source vertex (1 to %d): ", graph->V);
    scanf("%d", &srcVertex);
    printf("Enter the destination vertex (1 to %d): ", graph->V);
    scanf("%d", &destVertex);

    // Convert to 0-based indices
    int src = srcVertex - 1;
    int dest = destVertex - 1;

    // Print the shortest path
    printf("\nShortest path between %d and %d:\n", srcVertex, destVertex);
    while (parent[dest] != -1) {
        printf("%d <- ", dest + 1);
        dest = parent[dest];
    }
    printf("%d\n", srcVertex);
}

int main() {
    // Create a graph with the given adjacency matrix
    int V = 8;
    struct Graph* graph = createGraph(V);

    int adjacencyMatrix[8][8] = {
        {0, 2, 12, 18, 4, 8, 12, 16},
        {2, 0, 2, 12, 8, 4, 8, 12},
        {12, 2, 0, 2, 12, 8, 4, 8},
        {18, 12, 2, 0, 16, 4, 8, 4},
        {4, 8, 12, 16, 0, 2, 12, 22},
        {8, 4, 8, 4, 2, 0, 2, 12},
        {12, 8, 4, 8, 12, 2, 0, 2},
        {16, 12, 8, 4, 22, 12, 2, 0}
    };

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            addEdge(graph, i, j, adjacencyMatrix[i][j]);
        }
    }

    // Find the minimum spanning tree and shortest path between user-input vertices
    findMinimumSpanningTree(graph);

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}

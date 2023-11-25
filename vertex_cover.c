#include <stdio.h>
#include <stdlib.h>
int i, u;
// Define a structure for a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the graph
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (assuming an undirected graph)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to find the vertex cover using a simple greedy algorithm
void findVertexCover(struct Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    printf("Vertex cover: ");

    int edgeCount = 0;

    for (u = 0; u < graph->numVertices; ++u) {
        if (!visited[u]) {
            struct Node* temp = graph->adjList[u];
            while (temp != NULL) {
                int v = temp->data;
                if (!visited[v]) {
                    printf("(%d, %d) ", u, v);
                    visited[u] = 1;
                    visited[v] = 1;
                    edgeCount++;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    printf("\nNumber of edges in the final vertex cover: %d\n", edgeCount);

    free(visited);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph graph;
    graph.numVertices = numVertices;
    graph.adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (i = 0; i < numVertices; ++i) {
        graph.adjList[i] = NULL;
    }

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    findVertexCover(&graph);

    // Free allocated memory for the graph
    for (i = 0; i < numVertices; ++i) {
        struct Node* current = graph.adjList[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph.adjList);
    printf("\nName: Krisha Dhakal\tRoll: 8");
    return 0;
}

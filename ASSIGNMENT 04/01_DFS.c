#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;
typedef struct Graph
{
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;
Node *createNode(int vertex)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void DFS(Graph *graph, int vertex)
{
    Node *adjList = graph->adjLists[vertex];
    Node *temp = adjList;
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
int main()
{
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    Graph *graph = createGraph(vertices);
    printf("Enter each edge in the format: source destination\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS traversal starting from vertex %d:\n", start);
    DFS(graph, start);
    printf("\n");
    for (int i = 0; i < vertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}
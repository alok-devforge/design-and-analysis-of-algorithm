#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int V, int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int c = 0; c < V - 1; c++)
    {
        int u = minDistance(dist, sptSet, V);
        if(u == -1)
            break;
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printf("Vertex\t\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main()
{
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the adjacency matrix of the graph (0 indicates no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    int src;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);
    dijkstra(V, graph, src);
    return 0;
}
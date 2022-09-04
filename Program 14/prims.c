#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int n;
int minKey(int key[], bool mst[])
{
    int min = 999, min_key;
    int i;
    for(i=0; i<n; i++)
    {
        if(mst[i]==false && key[i]<min)
        {
            min_key = key[i];
            min = i;
        }
    }
    return min;
}
int printMST(int parent[], int graph[n][n])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[][n])
{
    int mstset[n];
    int key[n];
    bool mst[n];
    int i, j;
    for(i=0; i<n; i++)
    {
        key[i] = 999;
        mst[i] = false;
    }
    key[0] = 0;
    mstset[0] = -1;
    for(i=0; i<n-1; i++)
    {
        int u = minKey(key, mst);
        mst[u] = true;
        for(j=0; j<n; j++)
        {
            if(graph[u][j] && mst[j] == false && key[j] > graph[u][j])
            {
                mstset[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printMST(mstset, graph);

}
int main()
{
    int i,j, v;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    int visited[n];
    printf("\nEnter the weight adjacency matrix: \n");
    for(i=0; i<n; i++)
    {
        visited[i] = 0;
        for(j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(graph);
}

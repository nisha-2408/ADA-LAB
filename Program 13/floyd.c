#include<stdio.h>
#include<stdlib.h>
int n;
void warshall(int graph[][n]){
    int i, j, k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(graph[i][j]==0 && i!=j){
                graph[i][j] = 999;
            }
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(graph[i][j] > graph[i][k]+graph[k][j])
                    graph[i][j] = graph[i][k]+graph[k][j];
            }
        }
    }
    printf("\nThe Transitive closure is: \n");
    printArray(graph, n);
}
printArray(int graph[][n])
{
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

}
void main(){
    int i, j;
    printf("\nEnter the no of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("\nEnter the weight adjacency matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    warshall(graph);
}

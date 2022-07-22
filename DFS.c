#include <stdio.h>
#include<time.h>

int a[20][20],reach[20],n;
void dfs(int v)
{
    int i;
    printf("%d\t",v);
    reach[v]=1;
    for (i=1; i<=n; i++)
        if(a[v][i] && !reach[i])
        {
            dfs(i);
        }
}
void main()
{
    clock_t start,end;
    int i,j,count=0;
    printf("\n Enter number of vertices:");
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        reach[i]=0;
        for (j=1; j<=n; j++)
            a[i][j]=0;
    }
    printf("\n Enter the adjacency matrix:\n");
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    start=clock();
    dfs(1);
    printf("\n");
    for (i=1; i<=n; i++)
    {
        if(reach[i])
            count++;
    }

    if(count==n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
    end=clock();
    printf("\ntime taken %f ", difftime(end,start)/CLOCKS_PER_SEC);
}

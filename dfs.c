#include<stdio.h>
#include<stdlib.h>
# define max 100
int graph[max][max];
int visited[max];
void dfs(int v,int n)
{
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && !visited[i])
        {
            dfs(i,n);
        }
    }
}
int main()
{
    int n,e;
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter number of edges:\n");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    printf("Enter %d edges (u,v):",e);
    for(int i=0;i<e;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int start;
    printf("Enter starting vertex:\n");
    scanf("%d",&start);
    dfs(start,n);
}
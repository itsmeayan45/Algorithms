#include<stdio.h>
#include<stdbool.h>
#define max 20
int graph[max][max];
int colour[max];

bool issafe(int v,int c,int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i] && colour[i]==c)
            return false;
    }
    return true;
}
bool graphcoloring(int m,int v,int n)
{
    if(v==n)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if(issafe(v,c,n))
        {
           colour[v]=c;
           if(graphcoloring(m,v+1,n))
           {
                return true;
           }
           colour[v] = 0;
        }
        
    }
    return false;
}
int main()
{
    int n,e,m;
    printf("Enter numebr of vertices:\n");
    scanf("%d",&n);
    printf("Enter number of edges:\n");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        colour[i]=0;
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
    printf("Enter number of colours:\n");
    scanf("%d",&m);
    if(graphcoloring(m,0,n))
    {
        printf("solution exist:\n");
        for(int i=0;i<n;i++)
        {
            printf("vertex %d is coloured with %d colour\n",i,colour[i]);
        }
        
    }
    else
    {
        printf("Graph colouring is not possible for this condition.");
    }
}
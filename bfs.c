#include<stdio.h>
#include<stdlib.h>
# define max 100
int graph[max][max];
int visited[max];
int queue[max];
int front=-1;
int rear=-1;
void enqueue(int item)
{
    if(rear==max-1)
        return;
    if(front==-1)
        front=0;
    queue[++rear]=item;
}
int dequeue()
{
    if(front==-1 || front>rear)
    {
        return-1;
    }
    return queue[front++];
}
void bfs(int start,int n)
{
    enqueue(start);
    visited[start]=1;
    printf("Bfs traversal is: ");
    while(front<=rear)
    {
        int curr=dequeue();
        printf("%d ",curr);
        for(int i=0;i<n;i++)
        {
            if(graph[curr][i]==1 && !visited[i])
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n, e;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    printf("Enter number of edges:\n");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("Enter %d edges (u,v):", e);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int start;
    printf("Enter starting vertex:\n");
    scanf("%d", &start);
    bfs(start, n);
}
// Online C compiler to run C program online
#include <stdio.h>
#define max 10
int queue[max], front=0, rear=-1,n=0, vis[max], adj[max][max];


void bfs( int start)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(adj[start][i]==1 && vis[i]==0)
        {
            queue[++rear]=i;
            vis[i]=1;
            printf("%d\t", i);
        }
    }
    if(front!=rear)
        bfs(queue[front++]);
}

void dfs(int start)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(adj[start][i]==1 && vis[i]==0)
        {
            printf("%d\t", i);
            vis[i]=1;
            dfs(i);
        }
    }
}

int main() {
    int i,j, start;
    printf("\nEnter Order of Adjacency Matrix (value less than 10): ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        vis[i]=0;
        for(j=0;j<n;j++)
        {
            scanf("%d", &adj[i][j]);
        }
        printf("\n");
    }
    printf("Enter start node: ");
    scanf("%d", &start);
    vis[start]=1;
    printf("%d\t", start);
    dfs(start);
    

    return 0;
}

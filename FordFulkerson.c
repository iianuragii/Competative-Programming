#include <stdio.h>
#include <math.h>
int bfs(int n, int s, int t, int parent[],int g1[n][n])
{
    int visited[n];
    int i,v,rear = 0,front = 0;
    for(i = 0;i < n;i++)
        visited[i] = 0; 
   int q[n];
   q[rear++] = s;
   visited[s] = 1;
   parent[s] = -1;
   while(front != rear)
   {
       int u;
       u = q[front];
       front++;
       for(v = 0;v < n;v++)
       {
           if(visited[v] == 0 && g1[u][v] > 0)
           {
               if(v == t)
               {
                   parent[v] = u;
                   return 1;
               }
               q[rear++] = v;
               parent[v] = u;
               visited[v] = 1;
           }
       }
   }
   return -1;
}
int fordFulkerson(int n,int graph[n][n], int s, int t)
{
        int u, v;
 
        int g1[n][n];

        for (u = 0; u < n; u++)
        {
            for (v = 0; v < n; v++)
                g1[u][v] = graph[u][v];
        }
        int parent[n];
        int max_flow = 0; 

        while (bfs(n,s, t, parent,g1)!= -1) 
        {
            int path_flow = 9999;

            for (v = t; v != s; v = parent[v]) 
            {
                u = parent[v];
                if(path_flow > g1[u][v])
                	path_flow = g1[u][v];
                else
                	path_flow = path_flow;
            }

            for (v = t; v != s; v = parent[v]) 
            {
                u = parent[v];
                g1[u][v] -= path_flow;
                g1[v][u] += path_flow;
            }
            max_flow += path_flow;
        }
        return max_flow;
}
 
int main()
{
    int n,i,j;
    printf("Enter the no. of vertices\n");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the Graph\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            scanf("%d",&graph[i][j]);
    }
        
    printf("The maximum possible flow is %d\n",fordFulkerson(n,graph,0,n-1));
     return 0;
}

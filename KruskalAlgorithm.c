// Kruskal's algorithm in C

#include <stdio.h>
#define MAX 30

int Graph[MAX][MAX], n;
typedef struct edge {
  int u, v, w;
}edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
}list;

list elist;
list span;

void kruskalAlgo() 
{
    int belongs[MAX], i, j, c1, c2;
    elist.n = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++) 
        {
            if (Graph[i][j] != 0) 
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }
    }
    sort();

    for (i = 0; i < n; i++)
        belongs[i] = i;
    
    span.n = 0;
    
    for (i = 0; i < elist.n; i++) 
    {
        c1 = find(belongs, elist.data[i].u);
        c2 = find(belongs, elist.data[i].v);
    
        if (c1 != c2) 
        {
            span.data[span.n] = elist.data[i];
            span.n = span.n + 1;
            applyUnion(belongs, c1, c2);
        }
    }
}

int find(int belongs[], int vertexno)
{
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2)
{
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Sorting algo
void sort() 
{
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < span.n; i++) {
    printf("\n%d - %d : %d", span.data[i].u, span.data[i].v, span.data[i].w);
    cost = cost + span.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main() 
{
  int i, j, total_cost;
  
  printf("Enter the number of edges\n");
  scanf("%d",&n);
  printf("Enter the adjancency\n");
  for(i = 0;i < n;i++)
  {
      for(j = 0;j < 7;j++)
        scanf("%d",&Graph[i][j]);
  }
  kruskalAlgo();
  print();
}

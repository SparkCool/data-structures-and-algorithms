#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 20
#define INF 20000  // 选一个比较大的值就可以，不要选65535，可能溢出？？

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

int PrintShortPath(int *parent, int e);

void DijkstraShortPath(MGraph G, int start)
{
    int numVexs = G.numVertexes;
    
    int visited[numVexs];
    int minDist[numVexs];
    int parent[numVexs];
    
    // 初始化
    for (int i = 0; i < G.numVertexes; i++)
    {
        visited[i] = 0;
        minDist[i] = INF;
        parent[i] = -1;
    }
    

    // 选择V0作为源点
    int i, j;
    int k = start;
    visited[k] = 1;
    minDist[k] = 0;
    
    for (i = 0; i < G.numVertexes; i++)
    {
        for (j = 0; j < G.numVertexes; j++)
        {
            if (!visited[j] && G.arc[k][j] + minDist[k] < minDist[j])
            {
                minDist[j] = G.arc[k][j] + minDist[k];
                parent[j] = k;
            }
        }
        
               
        int min = INF;
        for (j = 0; j < G.numVertexes; j++)
        {
            if (!visited[j] && minDist[j] < min)
            {
                min = minDist[j];
                k = j;
            }
        }
        
        visited[k] = 1;

    }
    
    PrintShortPath(parent, 4);
    
}

int PrintShortPath(int *parent, int e)
{
    if (e != -1)
    {
        PrintShortPath(parent, parent[e]);  // 通过递归的方式先打印源点最后打印终点
        printf("%d->", e);
    }
} 

int main(void)
{
    MGraph G = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {
            {0, 4, INF, INF, INF, INF, INF, 8, INF},
            {4, 0, 8, INF, INF, INF, INF, 3, INF},
            {INF, 8, 0, 7, INF, 4, INF, INF, 2},
            {INF, INF, 7, 0, 9, 14, INF, INF, INF},
            {INF, INF, INF, 9, 0, 10, INF, INF, INF},
            {INF, INF, 4, 14, 10, 0, 2, INF, INF},
            {INF, INF, INF, INF, INF, 2, 0, 6, 6},
            {8, 3, INF, INF, INF, INF, 6, 0, 1},
            {INF, INF, 2, INF, INF, INF, 6, 1, 0},
        },
        9, 14
    };
    
    DijkstraShortPath(G, 0);

    return 0;
}

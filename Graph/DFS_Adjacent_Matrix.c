#include <stdio.h>

#define MAXVEX 128
#define INF 65535

typedef struct
{
    int vexs[MAXVEX];  // 顶点表，存储顶点元素，这里顶点元素的数据类型选择int
    int arc[MAXVEX][MAXVEX];  // 邻接矩阵 数据代表权重
    int numVertexes, numEdges;  // 图中当前的顶点数和边数
}MGraph;

// 建立的邻接矩阵表示
void CreateMGraph(MGraph *G)
{
    int i, j, k;
    printf("输入顶点数和边数：");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();  // 清除掉输入的回车符
    
    
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INF;               // 初始化邻接矩阵
        
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("输入第%d个顶点的数据：", i+1);
        scanf("%d", &G->vexs[i]);
        getchar();
    }
    
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边<vi, vj>的下标（如：2 5）：");
        scanf("%d%d", &i, &j);
        getchar();
        G->arc[i][j] = 1;
        G->arc[j][i] = 1;
    }
}

void PrintMGraphMat(MGraph G)
{
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            printf("%8d", G.arc[i][j]);
        }
        printf("\n");
    }
}

int visited[MAXVEX];  // 用于标记已访问的顶点

void DFS(MGraph G, int i)
{
    visited[i] = 1;  // 到达顶点i，对其标记已访问
    
    printf("%d  ", G.vexs[i]);  // 对遍历到的顶点的操作，这里进行简单地打印数值操作
    
    int j;
    for (j = 0; j < G.numVertexes; j++)  // 对矩阵的第i行搜索，寻找与该顶点有联系且没有访问的下一个顶点
    {
        if (G.arc[i][j] == 1 && visited[j] == 0)
            DFS(G, j);
    }
}

void DFSTraverse(MGraph G)
{
    // 初始化visited数组元素为0
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = 0;
    
    // 从V0顶点开始遍历
    DFS(G, 0);
    printf("\n");
    
/* 更一般的形式：考虑到非连通图，则需要对每个连通子图进行遍历，如下：*/
/*
    for (int i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
            DFS(G, i);
    }
*/    
    
    
}

int main()
{
    MGraph G;
    
    CreateMGraph(&G);  // 建立无向图的邻接矩阵表示
    
    PrintMGraphMat(G);  // 打印邻接矩阵
    
    DFSTraverse(G); // 遍历所有顶点
    
    return 0;
}


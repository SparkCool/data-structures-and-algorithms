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
    int i, j, k, w;
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
        printf("输入边<vi, vj>的下标及其权重（如：2 5 20）：");
        scanf("%d%d%d", &i, &j, &w);
        getchar();
        G->arc[i][j] = w;
        G->arc[j][i] = w;
        
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

int main()
{
    MGraph G;
    
    CreateMGraph(&G);  // 建立无向图的邻接矩阵表示
    
    PrintMGraphMat(G);  // 打印邻接矩阵
    
    
    
    return 0;
}


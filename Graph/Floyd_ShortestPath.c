#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 5
#define INF 20000  

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void PrintMat(int mat[MAXVEX][MAXVEX], int n)  // 必须标明维数，且维数必须和传递进来的矩阵的维数相等，如果不等就会出错！！
{                                            // 这种传递二维数组的方式就有很大的局限性，用指针改进
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

void Floyd_ShortestPath(MGraph G)
{
    // 定义并初始化一个矩阵S由于指示前驱
    int P[G.numVertexes][G.numVertexes];
    
    for (int i = 0; i < G.numVertexes; i++)
        for (int j = 0; j < G.numVertexes; j++)
            P[i][j] = j;
        
    
    int i, j, k;  // 三层循环得到两个矩阵
    for (k = 0; k < G.numVertexes; k++)
    {
        for (i = 0; i < G.numVertexes; i++)
        {
            for (j = 0; j < G.numVertexes; j++)
            {
                if (G.arc[i][k] + G.arc[k][j] < G.arc[i][j])   //如果经过顶点k路径比原两点间路径更短，
                {
                    G.arc[i][j] = G.arc[i][k] + G.arc[k][j];  // 将当前两点间的路径修改为较小值
                    P[i][j] = P[i][k];  // 路径设置为经过顶点k
                }
            }
        }
    }
    
    // 直接打印两矩阵
    printf("最短路径矩阵\n");
    PrintMat(G.arc, G.numVertexes);
    
    printf("前驱矩阵\n");
    PrintMat(P, G.numVertexes); 
    
    // 以文字方式输出
    for (i = 0; i < G.numVertexes; i++)
    {
        for (j = 0; j <G.numVertexes; j++)
        {
            if (i != j)
            {
                printf("V%d->V%d的最短路径长度为：%d\n", i, j, G.arc[i][j]);
                printf("路径为：V%d->", i);
                k = i;
                while (P[k][j] != j)
                {
                    printf("V%d->", P[k][j]);
                    k = P[k][j];
                }
                printf("V%d\n", j);
            }
        }
        printf("\n");
    }
}

int main()
{
    MGraph G = 
    {
        {0, 1, 2, 3, 4},
        {
            {0, 3, 8, INF, -4},
            {INF, 0, INF, 1, 7},
            {INF, 4, 0, INF, INF},
            {2, INF, -5, 0, INF},
            {INF, INF, INF, 6, 0}
        },
        5, 9
    };
    
    Floyd_ShortestPath(G);
    
    return 0;
}

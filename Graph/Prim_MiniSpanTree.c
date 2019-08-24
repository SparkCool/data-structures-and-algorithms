// 为了代码简洁起见，使用已经生成的邻接矩阵G.arc[][]
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9
#define INF 65535

typedef struct
{
    int vexs[MAXVEX];  // 顶点表，存储顶点元素，这里顶点元素的数据类型选择int
    int arc[MAXVEX][MAXVEX];  // 邻接矩阵 数据代表权重
    int numVertexes, numEdges;  // 图中当前的顶点数和边数
}MGraph;

void PrimMiniSpanTree(MGraph G)
{
    int selected[MAXVEX];
    int minDist[MAXVEX];
    int parent[MAXVEX];
    
    // 初始化这些数组
    for (int i = 0; i < G.numVertexes; i++)
    {
        selected[i] = 0;
        minDist[i] = INF;
        parent[i] = -1;  
    }
    
    selected[0] = 1;  // 从V0开始，V0加入生成树
    
    int i;
    int k = 0;  // 初始化从0开始

    for (int n = 0; n < G.numVertexes - 1; n++)   // 当有n-1个点时，生成树创建完毕
    {
        // Update
        for (i = 0; i < G.numVertexes; i++) 
        {
            if (G.arc[k][i] < minDist[i]) // update：更新minDist，将依附于新增顶点k的边的权值写入minDist。且要排除掉已经在生成树之中的点
            {
                minDist[i] = G.arc[k][i];
                parent[i] = k;
            }
        }

        // Search 在minDist找最小值
        int min = INF;
         // k记录最小值的位置，用于在parent中确定是哪条边
        for (i = 0; i < G.numVertexes; i++)
        {
            if (!selected[i] && minDist[i] < min)
            {
                min = minDist[i];
                k = i;
            }
        }
        
        // Add
        selected[k] = 1;
        printf("(%d, %d)->", parent[k], k);
       
    }
}


int main(void)
{
    MGraph G = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {
            {0, 4, INF, INF, INF, INF, INF, 8, INF},
            {4, 0, 8, INF, INF, INF, INF, 11, INF},
            {INF, 8, 0, 7, INF, 4, INF, INF, 2},
            {INF, INF, 7, 0, 9, 14, INF, INF, INF},
            {INF, INF, INF, 9, 0, 10, INF, INF, INF},
            {INF, INF, 4, 14, 10, 0, 2, INF, INF},
            {INF, INF, INF, INF, INF, 2, 0, 1, 6},
            {8, 11, INF, INF, INF, INF, 1, 0, 7},
            {INF, INF, 2, INF, INF, INF, 6, 7, 0},
        },
        9, 14
    };
    
    PrimMiniSpanTree(G);

    return 0;
}

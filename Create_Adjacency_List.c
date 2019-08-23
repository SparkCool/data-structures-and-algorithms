#include <stdio.h>
#include <stdlib.h>


#define MAXVEX 128

typedef struct EdgeNode
{
    int adjvex;  // 边表节点的数据项，存储该边所依附的另一个顶点的下标
    int weight;  // 该边的权重
    struct EdgeNode *next;  // 指向下一个邻接点
}EdgeNode;

typedef struct VertexNode
{
    int data;
    EdgeNode *firstEdge;  // 指向第一个邻接点
}VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;
}AdjListGraph;


// 建立图的邻接表结构
void CreateAdjListGraph(AdjListGraph *G)
{
    int i, j, k;
    printf("输入顶点数和边数：");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();  // 清除掉输入的回车符
    
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("输入第%d个顶点的数据：", i+1);
        scanf("%d", &G->adjList[i].data); // 输入顶点信息
        getchar();
        G->adjList[i].firstEdge = NULL;  // 将边表置为空表
    }
    
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边<vi, vj>的下标（如：2 5）：");
        scanf("%d%d", &i, &j);
        getchar();
        
        EdgeNode *e; 
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;  // 顶点i指向顶点j
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;  // 顶点j指向顶点i
        e->next = G->adjList[j].firstEdge;
        G->adjList[j].firstEdge = e;
        
    }
    
}

void PrintAdjList(AdjListGraph G)
{
    
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("%d: ", i);
        EdgeNode *e = G.adjList[i].firstEdge;
        
        while (e)
        {
            printf("%d  ", e->adjvex);
            e = e->next;
        }
        
        printf("\n");
    }
}

int main()
{
    AdjListGraph G;
    
    CreateAdjListGraph(&G);
    
    PrintAdjList(G);
    
    
    return 0;
}
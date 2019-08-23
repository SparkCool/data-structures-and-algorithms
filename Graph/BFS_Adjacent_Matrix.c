#include <stdio.h>

#define MAXVEX 128
#define INF 65535

#define MAX 20  // 循环队列长度

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

/*--------------以下——队列相关的函数------------*/
typedef struct 
{
    int data[MAX];
    int front;
    int rear;
}SqQueue;

// 循环队列初始化
void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

int QueueEmpty(SqQueue *Q)
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

int QueueFull(SqQueue *Q)
{
    if ((Q->rear+1) % MAX == Q->front)
        return 1;
    else 
        return 0;
}

void EnQueue(SqQueue *Q, int e)
{
    if (QueueFull(Q))
        printf("队列已满！\n");
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % MAX;
}


void DeQueue(SqQueue *Q, int *e)
{
    if (QueueEmpty(Q))
        printf("队列已空！\n");
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % MAX;
}
/*--------------以上——队列相关的函数------------*/


int visited[MAXVEX] = {0};  // 用于标记已访问的顶点

void BFSTraverse(MGraph G)
{
    SqQueue Q;
    InitQueue(&Q);
    
    int i, j;
    
    // 以下四行只适用于连通图的情况，对于非连通图，需要构造一个外层循环
    // 当while因为一个连通子图遍历完毕退出后，需要使用外层的for循环重新进入一个未访问的连通子图的顶点
    // 具体代码如注释，就是加一个外层循环，内层完全一样
    
    ///*
    i = 0; // 从下标为0的顶点开始遍历
    visited[i] = 1;
    printf("%d  ", G.vexs[i]);
    
    EnQueue(&Q, i);
    
    while (!QueueEmpty(&Q))  // 当前队列不为空
    {
        DeQueue(&Q, &i);
        
        for (j = 0; j < G.numVertexes; j++)  // 该层循环是从队列中拿出一个顶点，通过搜索G中对应的一行，找出与该顶点相连的其他顶点，即下层节点
        // 从循环体中可能看不出如何能够一层一层的寻找，这一点其实是
        {
            if (G.arc[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                printf("%d  ", G.vexs[j]);
                
                EnQueue(&Q, j);
            }
        }
    }  
    //*/
    
    
   /*    
    for (i = 0; i < G.numVertexes; i++) // 从下标为0的顶点开始遍历
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%d  ", G.vexs[i]);
            
            EnQueue(&Q, i);
            
            while (!QueueEmpty(&Q))  // 当前队列不为空
            {
                DeQueue(&Q, &i);
                
                for (j = 0; j < G.numVertexes; j++)
                {
                    if (G.arc[i][j] == 1 && visited[j] == 0)
                    {
                        visited[j] = 1;
                        printf("%d  ", G.vexs[j]);
                        
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
    
    */
    
}

int main()
{
    MGraph G;
    
    CreateMGraph(&G);  // 建立无向图的邻接矩阵表示
    
    PrintMGraphMat(G);  // 打印邻接矩阵
    
    BFSTraverse(G); // DFS遍历所有顶点
    
    printf("\n");
    
    
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>


#define MAXVEX 128
#define MAX 20

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

int visited[MAXVEX] = {0};

void BFSTravers(AdjListGraph G)
{
    SqQueue Q;
    InitQueue(&Q);
    
    ///*
    
    // 同样的，为了适应非连通图的情况，需要修改代码，在最外层加一个for循环，确保每个连通子图都能遍历到
    int i = 0;
    visited[i] = 1;
    printf("%d  ", G.adjList[i].data);
    
    EnQueue(&Q, i);

    EdgeNode *p;
    while (!QueueEmpty(&Q))
    {
        DeQueue(&Q, &i);
        p = G.adjList[i].firstEdge;
        
        while (p)   // 取出一个顶点，该顶点所对应的边链表，走到p=NULL，走到链表头，说明搜索完了该顶点所连接的所有顶点。
        // 此时再执行外层while循环，再从队列中取出一个点
        {

            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                printf("%d  ", G.adjList[p->adjvex].data);
                
                EnQueue(&Q, p->adjvex);
            }
            p = p->next;
        }
        
        
    }
    //*/
    
    /*
    
    for (int i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%d  ", G.adjList[i].data);
            
            EnQueue(&Q, i);

            EdgeNode *p;
            while (!QueueEmpty(&Q))
            {
                DeQueue(&Q, &i);
                p = G.adjList[i].firstEdge;
                
                while (p)   // 取出一个顶点，该顶点所对应的边链表，走到p=NULL，走到链表头，说明搜索完了该顶点所连接的所有顶点。
                // 此时再执行外层while循环，再从队列中取出一个点
                {
                    if (!visited[p->adjvex])
                    {
                        visited[p->adjvex] = 1;
                        printf("%d  ", G.adjList[p->adjvex].data);
                        
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
    */
    
}





int main()
{
    AdjListGraph G;
    
    CreateAdjListGraph(&G);
    
    PrintAdjList(G);
    
    BFSTravers(G);
    

    
    
    return 0;
}
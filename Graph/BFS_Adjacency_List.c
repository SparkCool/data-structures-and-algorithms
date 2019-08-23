#include <stdio.h>
#include <stdlib.h>


#define MAXVEX 128
#define MAX 20

typedef struct EdgeNode
{
    int adjvex;  // �߱�ڵ��������洢�ñ�����������һ��������±�
    int weight;  // �ñߵ�Ȩ��
    struct EdgeNode *next;  // ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode
{
    int data;
    EdgeNode *firstEdge;  // ָ���һ���ڽӵ�
}VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;
}AdjListGraph;


// ����ͼ���ڽӱ�ṹ
void CreateAdjListGraph(AdjListGraph *G)
{
    int i, j, k;
    printf("���붥�����ͱ�����");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();  // ���������Ļس���
    
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("�����%d����������ݣ�", i+1);
        scanf("%d", &G->adjList[i].data); // ���붥����Ϣ
        getchar();
        G->adjList[i].firstEdge = NULL;  // ���߱���Ϊ�ձ�
    }
    
    for (k = 0; k < G->numEdges; k++)
    {
        printf("�����<vi, vj>���±꣨�磺2 5����");
        scanf("%d%d", &i, &j);
        getchar();
        
        EdgeNode *e; 
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;  // ����iָ�򶥵�j
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;  // ����jָ�򶥵�i
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



/*--------------���¡���������صĺ���------------*/
typedef struct 
{
    int data[MAX];
    int front;
    int rear;
}SqQueue;

// ѭ�����г�ʼ��
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
        printf("����������\n");
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % MAX;
}


void DeQueue(SqQueue *Q, int *e)
{
    if (QueueEmpty(Q))
        printf("�����ѿգ�\n");
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % MAX;
}
/*--------------���ϡ���������صĺ���------------*/

int visited[MAXVEX] = {0};

void BFSTravers(AdjListGraph G)
{
    SqQueue Q;
    InitQueue(&Q);
    
    ///*
    
    // ͬ���ģ�Ϊ����Ӧ����ͨͼ���������Ҫ�޸Ĵ��룬��������һ��forѭ����ȷ��ÿ����ͨ��ͼ���ܱ�����
    int i = 0;
    visited[i] = 1;
    printf("%d  ", G.adjList[i].data);
    
    EnQueue(&Q, i);

    EdgeNode *p;
    while (!QueueEmpty(&Q))
    {
        DeQueue(&Q, &i);
        p = G.adjList[i].firstEdge;
        
        while (p)   // ȡ��һ�����㣬�ö�������Ӧ�ı������ߵ�p=NULL���ߵ�����ͷ��˵���������˸ö��������ӵ����ж��㡣
        // ��ʱ��ִ�����whileѭ�����ٴӶ�����ȡ��һ����
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
                
                while (p)   // ȡ��һ�����㣬�ö�������Ӧ�ı������ߵ�p=NULL���ߵ�����ͷ��˵���������˸ö��������ӵ����ж��㡣
                // ��ʱ��ִ�����whileѭ�����ٴӶ�����ȡ��һ����
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
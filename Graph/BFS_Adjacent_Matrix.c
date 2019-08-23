#include <stdio.h>

#define MAXVEX 128
#define INF 65535

#define MAX 20  // ѭ�����г���

typedef struct
{
    int vexs[MAXVEX];  // ������洢����Ԫ�أ����ﶥ��Ԫ�ص���������ѡ��int
    int arc[MAXVEX][MAXVEX];  // �ڽӾ��� ���ݴ���Ȩ��
    int numVertexes, numEdges;  // ͼ�е�ǰ�Ķ������ͱ���
}MGraph;

// �������ڽӾ����ʾ
void CreateMGraph(MGraph *G)
{
    int i, j, k;
    printf("���붥�����ͱ�����");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    getchar();  // ���������Ļس���
    
    
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INF;               // ��ʼ���ڽӾ���
        
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("�����%d����������ݣ�", i+1);
        scanf("%d", &G->vexs[i]);
        getchar();
    }
    
    for (k = 0; k < G->numEdges; k++)
    {
        printf("�����<vi, vj>���±꣨�磺2 5����");
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


int visited[MAXVEX] = {0};  // ���ڱ���ѷ��ʵĶ���

void BFSTraverse(MGraph G)
{
    SqQueue Q;
    InitQueue(&Q);
    
    int i, j;
    
    // ��������ֻ��������ͨͼ����������ڷ���ͨͼ����Ҫ����һ�����ѭ��
    // ��while��Ϊһ����ͨ��ͼ��������˳�����Ҫʹ������forѭ�����½���һ��δ���ʵ���ͨ��ͼ�Ķ���
    // ���������ע�ͣ����Ǽ�һ�����ѭ�����ڲ���ȫһ��
    
    ///*
    i = 0; // ���±�Ϊ0�Ķ��㿪ʼ����
    visited[i] = 1;
    printf("%d  ", G.vexs[i]);
    
    EnQueue(&Q, i);
    
    while (!QueueEmpty(&Q))  // ��ǰ���в�Ϊ��
    {
        DeQueue(&Q, &i);
        
        for (j = 0; j < G.numVertexes; j++)  // �ò�ѭ���ǴӶ������ó�һ�����㣬ͨ������G�ж�Ӧ��һ�У��ҳ���ö����������������㣬���²�ڵ�
        // ��ѭ�����п��ܿ���������ܹ�һ��һ���Ѱ�ң���һ����ʵ��
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
    for (i = 0; i < G.numVertexes; i++) // ���±�Ϊ0�Ķ��㿪ʼ����
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%d  ", G.vexs[i]);
            
            EnQueue(&Q, i);
            
            while (!QueueEmpty(&Q))  // ��ǰ���в�Ϊ��
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
    
    CreateMGraph(&G);  // ��������ͼ���ڽӾ����ʾ
    
    PrintMGraphMat(G);  // ��ӡ�ڽӾ���
    
    BFSTraverse(G); // DFS�������ж���
    
    printf("\n");
    
    
    
    return 0;
}


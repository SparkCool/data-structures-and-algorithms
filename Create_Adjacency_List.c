#include <stdio.h>
#include <stdlib.h>


#define MAXVEX 128

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

int main()
{
    AdjListGraph G;
    
    CreateAdjListGraph(&G);
    
    PrintAdjList(G);
    
    
    return 0;
}
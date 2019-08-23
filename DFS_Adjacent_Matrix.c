#include <stdio.h>

#define MAXVEX 128
#define INF 65535

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

int visited[MAXVEX];  // ���ڱ���ѷ��ʵĶ���

void DFS(MGraph G, int i)
{
    visited[i] = 1;  // ���ﶥ��i���������ѷ���
    
    printf("%d  ", G.vexs[i]);  // �Ա������Ķ���Ĳ�����������м򵥵ش�ӡ��ֵ����
    
    int j;
    for (j = 0; j < G.numVertexes; j++)  // �Ծ���ĵ�i��������Ѱ����ö�������ϵ��û�з��ʵ���һ������
    {
        if (G.arc[i][j] == 1 && visited[j] == 0)
            DFS(G, j);
    }
}

void DFSTraverse(MGraph G)
{
    // ��ʼ��visited����Ԫ��Ϊ0
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = 0;
    
    // ��V0���㿪ʼ����
    DFS(G, 0);
    printf("\n");
    
/* ��һ�����ʽ�����ǵ�����ͨͼ������Ҫ��ÿ����ͨ��ͼ���б��������£�*/
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
    
    CreateMGraph(&G);  // ��������ͼ���ڽӾ����ʾ
    
    PrintMGraphMat(G);  // ��ӡ�ڽӾ���
    
    DFSTraverse(G); // �������ж���
    
    return 0;
}


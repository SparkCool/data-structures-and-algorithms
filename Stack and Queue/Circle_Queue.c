// 循环队列
#include <stdio.h>

#define MAX 20

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

void PrintQueue(SqQueue Q)
{
    int i;
    while (!QueueEmpty(&Q))
    {
        DeQueue(&Q, &i);
        printf("%d  ", i);
    }
    printf("\n");
}


int main()
{
    SqQueue Q;
    InitQueue(&Q);
    
    EnQueue(&Q, 1001);
    EnQueue(&Q, 1002);
    EnQueue(&Q, 1003);
    EnQueue(&Q, 1004);
    
    printf("队列中全部元素为：\n");
    PrintQueue(Q);

    
    int i;
    DeQueue(&Q, &i);
    
    printf("元素%d出队列\n", i);
    printf("队列中全部元素为：\n");
    PrintQueue(Q);

    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node, *PtrNode;

void CreateList(PtrNode *head)
{
    *head = (PtrNode)malloc(sizeof(Node));
    (*head)->next = NULL;

    PtrNode node = *head;
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        PtrNode s;
        s = (PtrNode)malloc(sizeof(Node));

        s->data = a[i];
        s->next = node->next;
        node->next = s;
    }
}

void PrintList(PtrNode node)
{
    node = node->next;
    while(node)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}

void DeleteElem(PtrNode *head, int key, int method)
{
    PtrNode node;
    node = (*head)->next;

    while(node->next)
    {
        if (key == node->next->data)
            break;  // 循环退出后，node是前驱节点的地址

        node = node->next;
    }
    
    // 方法一：本函数删除
    if (method == 1)
    {   
        PtrNode q;
        q = node->next;
        printf("Number %d is going to be deleted\n", q->data);
        node->next = q->next;
        free(q);
    }

    // 方法二：传递结构体指针删除
    if (method == 2)
    { 
        Delete_StructPtr(node);  // 与方法一几乎一样，都是使用指向结构体的指针来修改结构体成员的值

    }

    // 方法三：传递成员地址删除
    else if (method == 3)    
    {
        Delete_MemberAddr(&(node->next));  // 因此传node传递的就是前驱节点4的next的地址，原则：修改谁就传谁的地址
    }
}

void Delete_StructPtr(PtrNode node)
{
    PtrNode q;
    q = node->next;
    printf("Number %d is going to be deleted\n", q->data);
    node->next = q->next;
    free(q);
}

void Delete_MemberAddr(PtrNode *p)
{
    PtrNode q = NULL;
    q = *p;
    printf("Number %d is going to be deleted\n", q->data);
    (*p) = (*p)->next;
    free(q);
}

int main()
{
    PtrNode head;  // 定义头指针
    
    CreateList(&head);  // 在函数中使head指向内存中一个变量，要修改head的值，传入地址
    PrintList(head);

    int key = 3;
    DeleteElem(&head, key, 2);
    PrintList(head);

    return 0;
}

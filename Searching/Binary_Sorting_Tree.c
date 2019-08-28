/* 二叉排序树(Binary Sorting Tree)的相关操作，定义、查找、插入、删除*/
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

// 二叉树结构
/* 二叉树的二叉链表节点结构定义*/
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *PtrBiTree;


// 二叉排序树的查找--注意递归方法的使用
/*递归查找二叉排序树T中是否存在key*/
/*指针f指向T的双亲，其初始调用值为NULL*/
/*若查找成功,则指针p只想该数据元素节点,并返回TRUE*/
/*否则指针p指向查找路径上访问的最后一个节点并返回FALSE*/
/*就是返回最接近key的叶子节点,在插入新节点时就是利用了该性质*/
int SearchBST(PtrBiTree T, int key, PtrBiTree f, PtrBiTree *p)
{
    if (!T)
    {
        *p = f;  // 查询直到叶子节点的左右孩子,查找失败,返回什么?要看f的实参是什么
                 // f的实参是T,即叶子节点
        return FALSE;
    }
    else if (key == T->data)
    {
        *p = T; // T的实参是T->lchild或T->rchild,是存储在双亲节点中的指向该节点的指针
        return TRUE;
    }
    else if (key < T->data)
        return SearchBST(T->lchild, key, T, p); // 在左子树继续查找
    else 
        return SearchBST(T->rchild, key, T, p);
}

// 二插排序树的插入操作
// 当查找失败时,根据key与叶子节点data的大小关系,选择作为左孩子或者右孩子插入
int InsertBST(PtrBiTree *T, int key)
{
    PtrBiTree p;
    if (!SearchBST(*T, key, NULL, &p))
    {
        PtrBiTree s = (PtrBiTree)malloc(sizeof(BiTNode));  // 如果查找不到,申请动态内存空间,进行连接存储新的key
        s->data = key;
        s->lchild = s->rchild = NULL;

        // 根据与叶子节点值的大小关系选择连接位置
        if (!p)  // p为空指针,也就是在SearchBST函数中只执行了*p = f
            *T = s;     // 即传入的NULL,二叉树为空; 插入s为新的根节点
        else if(key < p->data)
            p->lchild = s;  // 插入为左孩子
        else 
            p->rchild = s;
        
        return TRUE;
    }
    else
    {
        return FALSE;  // 找到了与key的值相等的节点,无法插入
    }
}

// 二插排序树的删除
/* 步骤就是先查找到拟删除节点的前驱,修改其指针*/
/* 与之前的SearchBST类似, 但是这里要得到**前驱的孩子节点指针**进行修改*/
int DeleteBST(PtrBiTree *T, int key)
{
    if (!T)
    {
        return FALSE;  // 不存在关键字等于key的数据元素
    }
    else
    {
        if (key == (*T)->data)
            Delete(T);  // 传递的是前驱节点结构体的孩子节点指针
        else if (key < (*T)->data)
            return DeleteBST(& (*T)->lchild, key);
        else
            return DeleteBST(& (*T)->rchild, key); 
    }
    
}

/* 删除p节点*/
/* 对三种情况进行区分: 没有右子树, 没有左子树, 有左右子树*/
int Delete(PtrBiTree *p)
{
    // 重要: 明白p的实参是前驱节点结构体的孩子指针成员的地址
    // 这里是通过指针直接修改该成员的值, 使其指向被删除节点的下一个结点
    PtrBiTree q, s;

    if ((*p)->rchild == NULL)// 没有右子树, 只需重接左子树
    {
        q = *p;  // 暂存p的值, 即删除节点的地址
        *p = (*p)->lchild;  // 通过指针直接修改该成员的值, 使其指向被删除节点的下一个结点
        free(q);
    }
    else if ((*p)->lchild == NULL) // 没有左子树, 只需重接右子树
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }

    else  // 既有左子树又有右子树
    {
        q = *p; 
        s = (*p)->lchild;  // 在左子树中查找最接近被删除节点的值的节点
                            // 也就是p的前驱节点

        while(s->rchild)  // 当s->lchild == NULL, s就是p的前驱节点
        {
            q = s; // 将s移到被删除节点后, 其左子树需要重新连接 
            s = s->rchild; // 根据排序二叉树的性质, p的前驱节点就是左子树最右侧的节点(后继节点就是右子树最左侧的节点)
        }

        (*p)->data = s->data;

        /* 下面这四句难点 注意理解 */
        if(q != *p)
            q->rchild = s->lchild;
        else if (q == *p)  // 没有执行while循环, 即p的左子树只有右子树
            q->lchild = s->lchild;  // 重接q的右子树

        free(s);
    }
    return TRUE;
    
}

/* 对排序二叉树进行中序遍历得到的就是从小到大的有序数列*/
void InOrderTraverse(PtrBiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%d  ", T->data);
    InOrderTraverse(T->rchild);
}

int main(void)
{
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};

    PtrBiTree T;
    for (int i=0; i < 10; i++)
    {
        InsertBST(&T, a[i]);  // 创建一棵二叉排序树
    }

    InOrderTraverse(T);
    printf("\n");

    int key = 47;
    DeleteBST(&T, key);
    printf("删除%d后的排序二叉树序列为:\n", key);
    InOrderTraverse(T);
    printf("\n");

    getchar();
    return 0;
}

// 堆排序
#include <stdio.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Heapify(int *tree, int i, int n)
{
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int max = i;
    // 在一个基本双亲-孩子结构中找出最大值放到最上面
    if (c1 < n && tree[c1] > tree[max])
        max = c1;
    if (c2 < n && tree[c2] > tree[max])
        max = c2;

    if (max != i)
    {
        swap(tree, i, max);
        Heapify(tree, max, n);  // 将最大值移到顶层后, 子树的排序可能会被破坏, 因此对max所在的双亲节点递归Heapify
    }    
}

// 首先对所有双亲节点进行一次堆排序作为初始化
void BuildHeap(int *tree, int n)
{
    int i; 
    int last_node = (n - 1);
    int parent = (last_node - 1) / 2;
    
    for (i = parent; i >= 0; i--)
        Heapify(tree, i, n);
}




void HeapSort(int *tree, int n)
{
    BuildHeap(tree, n);
    
    int i;
    for (i=n-1; i >= 1; i--)
    {
        swap(tree, 0, i);
        Heapify(tree, 0, i);
    }
}


int main()
{
    int tree[] = {2, 5, 3, 1, 10, 4};
    int n = 6;
    HeapSort(tree, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", tree[i]);

    getchar();
    return 0;
}
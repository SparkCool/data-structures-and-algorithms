// 归并排序算法--讲解视频: B
#include <stdio.h>

#define MAXSIZE 20

void Merge(int *arr, int L, int M, int R)
{
    // 左右两个待归并数组的长度
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;

    int left[MAXSIZE];
    int right[MAXSIZE];

    // 将数组填入两个数组, 等待排序
    int i, j;
    for (i=L; i < M; i++)  // 注意: 在每次分段递归中, 左侧数组的起点是原数组arr下标为L的位置.. 折腾了一个小时
        left[i-L] = arr[i];
    
    for (j=M; j <= R; j++) // 同理, 起点为M位置
        right[j-M] = arr[j];

    // 将左右两个数组归并排序到arr[]
    int k = L; // k用于指示在arr中的填入位置, 每次递归都是从L算作一次的起点
    i = 0; j = 0;
    while (i<LEFT_SIZE && j<RIGHT_SIZE)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // 把左右数组剩下的复制到arr中
    while (i < LEFT_SIZE)
        arr[k++] = left[i++];
    
    while(j < RIGHT_SIZE)
        arr[k++] = right[j++];   
    
}

void MergeSort(int *arr, int L, int R)
{
    if (L == R)
    {
        return;
    }
    else
    {
        int M;
        M = (L + R) / 2;

        MergeSort(arr, L, M);
        MergeSort(arr, M+1, R);
        Merge(arr, L, M+1, R);
    }
}

int main()
{
    int arr[] = {6, 8, 10, 9, 4, 5, 2, 7};
    int L = 0;
    int R = 7;

    MergeSort(arr, L, R);

    for (int k=0; k <= R; k++)
        printf("%d\n", arr[k]);


    getchar();
    return 0;
}
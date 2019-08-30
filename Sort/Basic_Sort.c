// 排序算法
// 排序用的顺序表结构
#include <stdio.h>
#define MAXSIZE 10   // 用于要排序数组个数最大值

#define FALSE 0 // 在改进冒泡排序中记录标志位
#define TRUE 1

typedef struct 
{
    int r[MAXSIZE+1];  // r[0]为用作哨兵或临时变量
    int length;   // 除去r[0]
}SqList;

// 交换L中数组r的下标为i和j的值
void swap(SqList *L, int i, int j)
{
    int temp = L->r[j];
    L->r[j] = L->r[i];
    L->r[i] = temp;
}

// 最简单的排序 把每个数都与后面的数比较, 将较小值放到前面
void BubbleSort0(SqList *L)
{
    int i, j;
    for (i=1; i < L->length; i++)
    {
        for (j=i+1; j <= L->length; j++)
        {
            if (L->r[i] > L->r[j])
            {
                swap(L, i, j);    // 如果前面的值的则交换
            }
        }
    }
}

// 标准冒泡排序
void BubbleSort(SqList *L)
{
    int i, j;
    for(i=1; i < L->length; i++)
    {
        for (j = L->length-1; j >= i; j--)  // 数组最后一位是L->r[length-1], 
        {
            if (L->r[j] > L->r[j+1])
                swap(L, j, j+1);
        }
    }
}


// 改进冒泡排序 
// 如果前一次冒泡循环没有进行交换, 则说明已经排序完毕, 不再执行循环
// 设置标志位, 记录前一次是否进行了排序

void BubbleSort2(SqList *L)
{
    int i, j;
    int flag = TRUE;
    for (i=1; i < L->length && flag; i++)
    {
        flag = FALSE;
        for (j=L->length-1; j >= i; j--)
        {
            if (L->r[j] > L->r[j+1])
            {
                swap(L, j, j+1);
                flag = TRUE;
            }
        }
    }
}


// 简单选择排序
void SelectSort(SqList *L)
{
    int i, j;
    int min;
    for (i=1; i < L->length; i++)
    {
        min = i;
        for (j=i+1; j <= L->length; j++)
            if (L->r[j] < L->r[min])
                min = j;
        
        if (min != i)
            swap(L, i, min);
    }
}


// 直接插入排序
void InsertSort(SqList *L)
{
    // 数组0位置存储哨兵值, 1位置设为已放好, 从2位置开始排序
    int i, j;
    for (i=2; i <= L->length; i++)
    {
        if (L->r[i] < L->r[i-1])
        {
            L->r[0] = L->r[i];

            for (j=i-1; L->r[j] > L->r[0]; j--)
                L->r[j+1] = L->r[j];

            L->r[j+1] = L->r[0];        }
    }
}

void ShellSort(SqList *L)
{
    int i, j;
    int increment = L->length;

do
{
    increment = increment/3 + 1;

    for (i=increment+1; i <=L->length; i++)
    {
        if (L->r[i] < L->r[i-increment])
        {
            L->r[0] = L->r[i];

            for (j=i-increment; j>0 && L->r[j] > L->r[0]; j-=increment)
                L->r[j+increment] = L->r[j];

            L->r[j+increment] = L->r[0];
        }
    } 
} while (increment > 1);

}


int main(void)
{
    // 初始化一个SqList结构体, 录入待排序的数组
    SqList L = {
        {0, 9, 1, 5, 8, 3, 7, 4, 6, 2}, 9
    };

    //BubbleSort0(&L);  // 简单排序

    //BubbleSort2(&L);  // 冒泡排序

    //SelectSort(&L);   // 简单选择排序

    //InsertSort(&L);  // 直接插入排序

    ShellSort(&L);     // 希尔排序


    for (int i=1; i <= L.length; i++)
        printf("%d  ", L.r[i]);


    getchar();
    return 0;
}
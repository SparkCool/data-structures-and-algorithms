// 快速排序
// 从当前数组选择一个数字, 一般选择第一个, 将其放到一个合适的位置, 使左边的数都小于该数, 右边的数都大于
// 通过递归, 实现全部有序

#include <stdio.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 选择子数组最左边的数, 调整数组, 使左边的数都小于, 右边的数都大于
// 把比pivotkey小的数换到左边, 大的数换到右边
int Partition(int *arr, int low, int high)
{
    int pivotkey = arr[low];
    while (low < high)
    {
        while(low < high && arr[high] >= pivotkey)
            high--;
        swap(arr, low, high);
        while(low < high && arr[low] <= pivotkey)
            low++;
        swap(arr, low, high);
    }
    return low;

}

// 递归, 对枢纽左右边的数进行同样的处理
void QuickSort(int *arr, int low, int high)
{
    int pivotkey;

    if (low < high)
    {
        pivotkey = Partition(arr, low, high);

        QuickSort(arr, low, pivotkey-1);
        QuickSort(arr, pivotkey+1, high);
    }
}


int main()
{
    int arr[] = {50, 10, 90, 30, 70, 40, 80, 60, 20};

    QuickSort(arr, 0, 8);  // 注意需要输入下标8而不是数组长度

    int i;
    for (i = 0; i < 9; i++)
        printf("%d\n", arr[i]);

    getchar();
    return 0;
}
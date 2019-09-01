// 快速选择排序的改进
#include <stdio.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 三取一, 优化选取枢轴; 把中间数放到下标为low的位置
void Median_Of_Three(int *arr, int low, int high)
{
    // 分别选取位置1/中间/最后
    int m = (low + high) / 2;
    
    // 确定顺序为中/小/大 
    if (arr[low] > arr[high])
        swap(arr, low, high);
    if (arr[m] > arr[high])
        swap(arr, m, high);  // 前两步把high位置确定为最大值

    if (arr[m] > arr[low])   // 在剩下的两个中选择较大者就是中间数
        swap(arr, low, m);        
}

int Paritition(int *arr, int low, int high)
{
    int pivotkey;
    Median_Of_Three(arr, low, high);

    pivotkey = arr[low];

    while (low < high)
    {
        while (low < high && arr[high] >= pivotkey)
            high--;
        arr[low] = arr[high];  // 优化不必要的交换
        
        while(low < high && arr[low] <= pivotkey)
            low++;
        arr[high] = arr[low];
    }

    arr[low] = pivotkey;
    return low;
}

void QuickSort(int *arr, int low, int high)
{
    int pivotkey;

    while(low < high)
    {
        pivotkey = Paritition(arr, low, high);
        QuickSort(arr, low, pivotkey-1);
        low = pivotkey+1;  //??尾递归 没看懂..
    }
}
int main()
{

    int arr[] = {20, 10, 90, 30, 70, 40, 80, 60, 50};

    QuickSort(arr, 0, 8);

    for (int i = 0; i < 9; i++)
        printf("%d\n", arr[i]);

    getchar();

    return 0;
}
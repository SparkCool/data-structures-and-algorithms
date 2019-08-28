/* 散列表查找实现*/
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 // 定义数列表长为数组的长度
#define NULLKEY -32768

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct 
{
    int *elem;  // 数组元素存储基址, 动态分配数组
    int count;  // 当前数据元素个数
}HashTable;

int m = HASHSIZE; // 数列表长, 全局变量

// 初始化数列表
int InitHashTable(HashTable *H)
{
    m = HASHSIZE;

    H->elem = (int *)malloc(m * sizeof(int));  // 使用动态内存, 给Hash表分配空间
    H->count = m;
    
    for (int i=0; i < m; i++)
        H->elem[i] = NULLKEY;
}

// 定义散列函数, 根据元素计算插入的地址
// 除留余数
int Hash(int key)
{
    return key % m;
}

void InsertHash(HashTable *H, int key)
{
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY)
    {
        addr = (addr+1) % m;
    }
    H->elem[addr] = key;
}

int SearchHash(HashTable *H, int key, int *addr)
{
    *addr = Hash(key);
    while(H->elem[*addr] != key)
    {
        *addr = (*addr+1) % m;
        if (H->elem[*addr] == NULLKEY || Hash(*addr) == key)
            return UNSUCCESS;
    }
    return SUCCESS;
}

int main()
{
    int a[12] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    
    HashTable H;
    InitHashTable(&H);

    for (int i=0; i < 12; i++)
    {
        InsertHash(&H, a[i]);  // 将数据存储在Hash表中
    }

    // 从Hash表中读取
    int addr = 0;
    SearchHash(&H, 56, &addr);
    printf("搜索的数据是%d\n", H.elem[addr]);

    return 0;
}
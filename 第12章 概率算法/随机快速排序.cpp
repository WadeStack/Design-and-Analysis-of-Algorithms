#include<bits/stdc++.h>
using namespace std;
int Partition(int r[ ], int  first, int end);
void RandQuickSort(int r[ ], int low, int high);
int Random(int a, int b);

int main()
{
    int r[]= {23,13,50,28,35,6,19};
    RandQuickSort(r,0,6);
    for(int i=0; i<7; i++)
        cout<<r[i]<<" ";
    return 0;
}
int Partition(int r[ ], int low, int high)          //划分
{
    int i = low, j = high;                       //初始化待划分区间
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
            j--;          //右侧扫描
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;     //将较小记录交换到前面
            i++;
        }
        while (i < j && r[i] <= r[j])
            i++;         //左侧扫描
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;     //将较大记录交换到后面
            j--;
        }
    }
    return i;                                // 返回轴值记录的位置
}
void RandQuickSort(int r[ ], int low, int high)         //快速排序
{
    int k, i, temp;
    if (low < high)
    {
        i = Random(low, high);
        temp = r[low];
        r[low] = r[i];
        r[i] = temp;
        k = Partition(r, low, high);    //划分，pivot是轴值在序列中的位置
        RandQuickSort(r, low, k-1);      //求解子问题1，对左侧子序列进行快速排序
        RandQuickSort(r, k+1, high);      //求解子问题2，对右侧子序列进行快速排序
    }
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )产生[0, 32767]之间的随机整数
}

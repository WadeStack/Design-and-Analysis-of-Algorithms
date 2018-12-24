#include<bits/stdc++.h>
using namespace std;
void InsertSort(int r[ ], int n);

int main()
{
    int r[]= {0,12,15,9,20,10,6};
    InsertSort(r,6);
    for(int i=1; i<7; i++)
        cout<<r[i]<<"  ";
    return 0;
}

void InsertSort(int r[ ], int n)              //待排序记录序列存储在r[1]~r[n]中
{
    for (int i = 2; i <= n; i++)               //从第2个记录开始执行插入操作
    {
        r[0] = r[i];                         //暂存待插记录，设置哨兵
        for (int j = i - 1; r[0] < r[j]; j--)        //寻找插入位置
            r[j + 1] = r[j];                    //记录后移
        r[j + 1] = r[0];
    }
}

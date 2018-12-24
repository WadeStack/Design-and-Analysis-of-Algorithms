#include<bits/stdc++.h>
using namespace std;
void MergeSort(int r[ ],  int s, int t);
void Merge(int r[ ], int r1[ ], int s, int m, int t);
int main()
{
    int r[8]= {8,1,2,9,6};
    MergeSort(r,0,4);
    for(int i=0; i<5; i++)
        cout<<r[i]<<" ";
    return 0;
}

void Merge(int r[ ], int r1[ ], int s, int m, int t)          //合并子序列
{
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= t)
    {
        if (r[i] <= r[j])                     //取r[i]和r[j]中较小者放入r1[k]
            r1[k++] = r[i++];
        else
            r1[k++] = r[j++];
    }
    while (i <= m)                  //若第一个子序列没处理完，则进行收尾处理
    {
        r1[k++] = r[i++];
    }
    while (j <= t)                   //若第二个子序列没处理完，则进行收尾处理
    {
        r1[k++] = r[j++];
    }
}
void MergeSort(int r[ ], int s, int t)
{
    int m;
    int r1[1000] = {0};
    if (s == t)
        return;                 //递归的边界条件
    else
    {
        m = (s + t)/2;                  //划分
        MergeSort(r, s, m);           //求解子问题1，归并排序前半个子序列
        MergeSort(r, m+1, t);         //求解子问题2，归并排序后半个子序列
        Merge(r, r1, s, m, t);            //合并解，合并相邻有序子序列
        for (int i = s; i <= t; i++)
            r[i] = r1[i];
    }
}




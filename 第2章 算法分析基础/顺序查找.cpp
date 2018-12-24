#include<bits/stdc++.h>
using namespace std;
int SeqSearch(int A[ ], int n, int k);
int main()
{
    int A[]= {4,1,8,6,3,9};
    int i=SeqSearch(A,6,3);
    cout<<"在数组中是第"<<i<<"个元素"<<endl;
    return 0;
}
int SeqSearch(int A[ ], int n, int k)   //在数组A[n]中查找值为k的记录
{
    for (int i = 0; i < n; i++)
        if (A[i] == k)
            break;
    if (i == n)
        return 0;             //查找失败，返回0
    else
        return i + 1;	              //查找成功，返回记录的序号
}

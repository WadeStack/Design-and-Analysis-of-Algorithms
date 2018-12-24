#include<bits/stdc++.h>
using namespace std;
void HeapSort(int r[ ], int n);
void SiftHeap(int r[ ], int k, int n);

int main()

{
    int r[]= {47,33,35,2,18,71,26,13};
    HeapSort(r,8);
    for(int i=0; i<8; i++)
        cout<<r[i]<<"  ";
    return 0;
}

void SiftHeap(int r[ ], int k, int n)
{
    int i, j, temp;
    i = k;
    j = 2 * i +1;                      //置i为要筛的结点，j为i的左孩子
    while (j < n)                       //筛选还没有进行到叶子
    {
        if (j < n-1  && r[j] < r[j+1])
            j++;    //比较i的左右孩子，j为较大者
        if (r[i] > r[j])                     //根结点已经大于左右孩子中的较大者
            break;
        else
        {
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;            //将被筛结点与结点j交换
            i = j;
            j = 2 * i+1;                 //被筛结点位于原来结点j的位置
        }
    }
}
void HeapSort(int r[ ], int n)
{
    int i, temp;
    for (i = (n-1)/2; i >= 0; i--)       //初始建堆，从最后一个分支结点至根结点
        SiftHeap(r, i, n) ;
    for (i = 1; i <= n-1; i++)         //重复执行移走堆顶及重建堆的操作
    {
        temp = r[0];
        r[0] = r[n-i];
        r[n-i] = temp;
        SiftHeap(r, 0, n-i);            //只需调整根结点
    }
}



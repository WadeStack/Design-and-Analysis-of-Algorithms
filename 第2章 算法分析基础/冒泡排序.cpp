#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int r[ ], int n);

int main()
{
    int i, r[]= {4,3,9,2,6,1};
    cout<<"排序前：";
    for(i=0; i<6; i++)
        cout<<r[i]<<" ";
    cout<<endl;
    BubbleSort(r,6);
    cout<<"排序后：";
    for(i=0; i<6; i++)
        cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}
void BubbleSort(int r[ ], int n)
{
    int bound, exchange = n - 1;           //第一趟起泡排序的区间是[0, n-1]
    while (exchange != 0)                //当上一趟排序有记录交换时
    {
        bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; j++)       //一趟起泡排序区间是[0, bound]
            if (r[j] > r[j + 1])
            {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;       //交换记录
                exchange = j;              //记载每一次记录交换的位置
            }
    }
}

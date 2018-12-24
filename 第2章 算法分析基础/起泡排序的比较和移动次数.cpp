#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int r[ ], int n);

int main()
{
    int r[]= {5,4,6,2,1,3};
    BubbleSort(r, 6);
    return 0;
}

void BubbleSort(int r[ ], int n)
{
    int count1 = 0, count2 = 0;     //count1和count2记载比较次数和移动次数
    int bound, exchange = n - 1;         //第一趟起泡排序的区间是[0, n-1]
    while (exchange != 0)              //当上一趟排序有记录交换时
    {
        bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; j++)        //一趟起泡排序区间是[0, bound]
            if (++count1 && r[j] > r[j+1])     //注意不能写作count1++
            {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                count2 = count2 + 3;      //1次交换是3次移动操作
                exchange = j;            //记载每一次记录交换的位置
            }
    }
    cout<<"比较次数是:"<<count1<<endl;
    cout<<"移动次数是:"<<count2<<endl;
}

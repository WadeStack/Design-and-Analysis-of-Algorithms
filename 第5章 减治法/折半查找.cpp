#include<bits/stdc++.h>
using namespace std;
int BinSearch1(int r[ ], int n, int k);

int main()
{
    int r[]= {7, 14, 18, 21, 23, 29, 31, 35, 38};
    int i=BinSearch1(r,9,18);
    cout<<"在数组中的下标是："<<i<<endl;
    return 0;
}

int BinSearch1(int r[ ], int n, int k)
{
    int low = 0, high = n - 1;               //设置查找区间，注意数组下标从0开始
    int mid;
    while (low <= high)                //当区间存在时
    {
        mid = (low + high) / 2;
        if (k < r[mid])
            high = mid - 1;
        else	if (k > r[mid])
            low = mid + 1;
        else
            return mid;                      //查找成功，返回元素序号
    }
    return 0;                                  //查找失败，返回0
}

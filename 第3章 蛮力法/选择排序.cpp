#include<bits/stdc++.h>
using namespace std;
void SelectSort(int r[ ], int n);

int main()
{
    int r[]= {1,6,7,5,3,8,9,2};
    SelectSort(r,8);
    for(int i=0; i<8; i++)
        cout<<r[i]<<"  ";
    return 0;
}
void SelectSort(int r[ ], int n)
{
    int i, j, index, temp;
    for (i = 0; i < n - 1; i++)  	            //对n个记录进行n-1趟选择排序
    {
        index = i;
        for (j = i + 1; j < n; j++)           //在无序区中查找最小记录
            if (r[j] < r[index])
                index = j;
        if (index != i)
        {
            temp = r[i];
            r[i] = r[index];
            r[index] = temp;
        }//交换记录
    }
}

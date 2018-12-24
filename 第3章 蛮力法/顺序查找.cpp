#include<bits/stdc++.h>
using namespace std;
int SeqSearch1(int r[ ], int n, int k);
int SeqSearch2(int r[ ], int n, int k);

int main()
{
    int r[]= {0,1,5,3,9,4};
    int k1 = SeqSearch1(r,5,3);
    int k2 = SeqSearch2(r,5,3);
    cout<<k1<<"  "<<k2<<endl;
    return 0;
}

int SeqSearch1(int r[ ], int n, int k)            //数组r[1] ~ r[n]存放查找集合
{
    int i = n;
    while (i > 0 && r[i] != k)                 //检测比较位置是否越界
        i--;
    return i;
}
int SeqSearch2(int r[ ], int n, int k)  //数组r[1] ~ r[n]存放查找集合
{
    int i = n;
    r[0] = k;            //设置哨兵
    while (r[i] != k)               //不用检测比较位置是否越界
        i--;
    return i;
}

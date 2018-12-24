#include<bits/stdc++.h>
using namespace std;
const int n = 20;
int a[n];
void PrimeCircle(int n);
int Check(int k);
int Prime(int x);

int main( )
{
    int n;
    cout<<"请输入一个整数；";
    cin>>n;
    PrimeCircle(n);
    return 0;
}

void PrimeCircle(int n)
{
    int i, k;
    for (i = 0; i < n; i++ )               //将数组a[n]初始化为0
        a[i] = 0;
    a[0] = 1;
    k = 1;           //指定第1个位置填写1，注意数组下标从0开始
    while (k >=1)
    {
        a[k] = a[k]+1;
        while (a[k] <= n)
            if (Check(k) == 1)
                break;         //位置k可以填写整数a[k]
            else
                a[k] = a[k] + 1;              //试探下一个数
        if (a[k] <= n && k == n - 1)          //求解完毕，输出解
        {
            for (i = 0; i < n; i++)
                cout<<a[i]<<"  ";
            return;
        }
        if (a[k] <= n && k < n - 1)
            k = k + 1;               //处理下一个位置
        else
        {
            a[k] = 0;
            k = k - 1;        //回溯
        }
    }
}
int Check(int k)                    //判断位置k的填写是否满足约束条件
{
    int flag = 0;
    for (int i = 0; i < k; i++)           //判断是否重复
        if (a[i] == a[k])
            return 0;
    flag = Prime(a[k] + a[k - 1]);
    if (flag == 1 && k == n - 1)
        flag = Prime(a[k] + a[0]);
    return flag;
}
int Prime(int x)                   //判断是否素数
{
    int i, n;
    n = (int)sqrt(x);
    for (i = 2; i <= n; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

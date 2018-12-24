#include<bits/stdc++.h>
using namespace std;
int Pollard(int n);
int Random(int a, int b);
int CommFactor(int m, int n);

int main()
{
    int x, y;
    cout<<"请输入一个整数：";
    cin>>x;
    y = Pollard(x);
    if (y == 0)
        cout<<"本次运行失败"<<endl;
    else
        cout<<x<<"的一个因子是："<<y<<endl;
    return 0;
}

int Pollard(int n)
{
    int a, b, c, d;
    a = Random(1, n - 1);                // a为[1, n-1]区间的随机整数
    b = (a * a) % n;
    while (b < n - 1)
    {
        c = (int)sqrt(b);
        if (c * c != b * b)
            b = b + n;         //求相应的b，满足b是一个完全平方数
    }
    if (b == n - 1)
        return 0;              //本次算法执行失败
    else
        d = CommFactor(a + b, n);      //调用欧几里德算法求最大公约数
    if (d > 1)
        return d;                  //若d为n的非平凡因子
    else
        return 0;                      //本次算法执行失败
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )产生[0, 32767]之间的随机整数
}
int CommFactor(int m, int n)
{
    int r = m % n;
    while (r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

#include<bits/stdc++.h>
using namespace std;
int CommFactor1(int m, int n);

int main()
{
    int a, b, r;
    cout<<"请输入两个自然数：";
    cin>>a>>b;
    r = CommFactor1(a, b);
    cout<<a<<"和"<<b<<"的最大公约数是："<<r<<endl;
    return 0;
}
int CommFactor1(int m, int n)
{
    int i, factor = 1;
    for (i = 2; i <= m && i <= n; i++)
    {
        while (m % i == 0 && n % i == 0)              //此处不能用if语句
        {
            factor = factor * i;
            m = m / i;
            n = n / i;
        }
    }
    return factor;
}

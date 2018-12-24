#include<bits/stdc++.h>
using namespace std;
int CommFactor2(int m, int n);

int main()
{
    int a, b, r;
    cout<<"请输入两个自然数：";
    cin>>a>>b;
    r = CommFactor2(a, b);
    cout<<a<<"和"<<b<<"的最大公约数是："<<r<<endl;
    return 0;
}

int CommFactor2(int m, int n)
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

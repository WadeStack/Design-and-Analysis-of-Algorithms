#include<bits/stdc++.h>
using namespace std;
const int n = 10;
int Random(int a, int b);
int FermatPrime(int n);

int main()
{
    int x, flag;
    cout<<"请输入一个整数：";
    cin>>x;
    flag = FermatPrime(x);
    if (flag)
        cout<<x<<"是素数"<<endl;
    else
        cout<<x<<"一定不是素数"<<endl;
    return 0;
}

int FermatPrime(int n)
{
    int a, b = 1;
    a = Random(2, n-1);              //产生[2, n-1]之间的一个随机整数
    for (int i = 1; i < n; i++)        //计算an-1 mod n
        b = (b * a) % n;
    if (b == 1)
        return 1;              //可能是素数或Carmichael数
    else
        return 0;                   //一定不是素数
}

int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )产生[0, 32767]之间的随机整数
}

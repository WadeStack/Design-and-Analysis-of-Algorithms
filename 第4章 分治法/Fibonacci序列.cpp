#include<bits/stdc++.h>
using namespace std;
int Fib(int n);
int fib(int n);
int main()
{

    int r=Fib(7);
    cout<<r<<endl;
    return 0;
}
int Fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fib(n-1) + Fib(n-2);
}

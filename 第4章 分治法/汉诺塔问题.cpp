#include<bits/stdc++.h>
using namespace std;
void Hanoi(int n, char A, char B, char C);

int main()
{
    char A, char B, char C;
    Hanoi(3,'A','B','C');
    cout<<endl;
    return 0;
}
void Hanoi(int n, char A, char B, char C)
{
    if (n == 1)
        cout<< A<<"->"<<C<<"  ";   //将碟子从A移到C上，递归结束
    else
    {
        Hanoi(n-1, A, C, B);            //将n-1个碟子从A借助C移到B上
        cout<<A<<"->"<<C<<"  ";          //将碟子从A移到C上
        Hanoi(n-1, B, A, C);            //将n-1个碟子从B借助A移到C上
    }
}

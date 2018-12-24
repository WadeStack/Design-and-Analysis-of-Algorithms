#include<bits/stdc++.h>
using namespace std;
const int n = 10;
void RandomShuffle(int r[ ], int n);
int Random(int a, int b);

int main()
{
    int r[n] = {1,2,9,10,3,4,5,6,7,8};
    RandomShuffle(r, n);
    for (int i = 0; i < n; i++)
        cout<<r[i]<<"  ";
    return 0;
}

void RandomShuffle(int r[ ], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        j = Random(0, n-1);                           //随机选择一个元素
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;                  //交换r[i]和r[j]
    }
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )产生[0, 32767]之间的随机整数
}



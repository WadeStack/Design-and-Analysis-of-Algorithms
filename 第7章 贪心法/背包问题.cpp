#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int KnapSack(int w[ ], int v[ ], int n, int C);

int main( )
{
    int w[n] = {10, 30, 20}, v[n] = {50, 120, 60};
    int C = 50;
    int value = KnapSack(w, v, 3, C);
    cout<<"背包获得的最大价值是："<<value<<endl;
    return 0;
}

int KnapSack(int w[ ], int v[ ], int n, int C)
{
    double x[10] = {0};           //物品可部分装入
    int maxValue = 0;
    for (int i = 0; w[i] < C; i++)
    {
        x[i] = 1;                 //将物品i装入背包
        maxValue += v[i];
        C = C - w[i];             //背包剩余容量
    }
    x[i] = (double)C/w[i];        //物品i装入一部分
    maxValue += x[i] * v[i];
    return maxValue;              //返回背包获得的价值
}

#include<bits/stdc++.h>
using namespace std;
const int n = 5;
int arc[n][n]= {{0,1,1,0,0},{1,0,1,1,1},{1,1,0,0,1},{0,1,0,0,1},{0,1,1,1,0}};
void Hamiton(int x[ ], int n);

int main()
{
    int x[n];
    Hamiton(x, n) ;
    return 0;
}
void Hamiton(int x[ ], int n)
{
    int i, k;
    int visited[10];                   //假设图最多有10个顶点
    for (i = 0; i < n; i++)                     //初始化顶点数组和标志数组
    {
        x[i] = 0;
        visited[i] = 0;
    }
    x[0] = 0;
    visited[0] = 1;              //从顶点0出发
    k = 1;
    while (k >= 1)
    {
        x[k] = x[k] + 1;                       //搜索下一顶点
        while (x[k] < n)
            if (visited[x[k]] == 0 && arc[x[k-1]][x[k]] == 1)
                break;
            else
                x[k] = x[k] + 1;
        if (x[k] < n && k == n - 1 && arc[x[k]][1] == 1)
        {
            for (k = 0; k < n; k++ )
                cout<<x[k] + 1<<"  ";           //输出顶点的编号，编号从1开始
            return;
        }
        else if (x[k] < n && k < n - 1 )
        {
            visited[x[k]] = 1;
            k = k + 1;
        }
        else                            //回溯
        {
            visited[x[k]] = 0;
            x[k] = 0;
            k = k - 1;
        }
    }
}

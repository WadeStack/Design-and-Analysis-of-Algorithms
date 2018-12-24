#include<bits/stdc++.h>
using namespace std;
const int n = 7;
const int m = 3;
void MultiMachine(int t[ ], int n, int d[ ], int m);

int main( )
{
    int t[n] = {16, 14, 6, 5, 4, 3, 2};
    int d[m] = {0};
    MultiMachine(t, n, d, m);
    return 0;
}

void MultiMachine(int t[ ], int n, int d[ ], int m)
{
    int S[3][7], rear[3];     //S[i]为存储机器i处理作业的队列，rear[i]为队尾下标
    int i, j, k;
    for (i = 0; i < m; i++)          //安排前m个作业
    {
        S[i][0] = i;
        rear[i] = 0;     //每个作业队列均只有一个作业
        d[i] = t[i];
    }
    for (i = m; i < n; i++)             //依次安排余下的每一个作业
    {
        for (j = 0, k = 1; k < m; k++)   //查找最先空闲的机器
            if (d[k] < d[j])
                j = k;
        rear[j]++;
        S[j][rear[j]] = i;     //将作业i插入队列S[j]
        d[j] = d[j] + t[i];
    }
    for (i = 0; i < m; i++)               //输出每个机器处理的作业
    {
        cout<<"机器"<<i<<"：";
        for (j = 0; S[i][j] >= 0; j++)
            cout<<"作业"<<S[i][j]<<"  ";
        cout<<endl;
    }
}

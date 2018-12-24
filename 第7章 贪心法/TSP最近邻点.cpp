#include<bits/stdc++.h>
using namespace std;
const int n = 5;
const int max = 100;
int TSP1(int arc[n][n], int w);

int main( )
{
    int arc[n][n] = {{max,3,3,2,6},{3,max,7,3,2},{3,7,max,2,5},{2,3,2,max,3},{6,2,5,3,max}};
    int minDist = TSP1(arc, 0);
    cout<<"最短哈密顿回路的长度是："<<minDist<<endl;
    return 0;
}

int TSP1(int arc[n][n], int w)
{
    int edgeCount = 0, TSPLength = 0;
    int min, u, v;
    int flag[n] = {0};                    //顶点均未加入哈密顿回路
    u = w;
    flag[w] = 1;
    while (edgeCount < n-1)               //循环直到边数等于n-1
    {
        min  = 100;
        for (int j = 0; j < n; j++)       //求arc[u]中的最小值
            if ((flag[j] == 0) && (arc[u][j] != 0) && (arc[u][j] < min))
            {
                v = j;
                min = arc[u][j];
            }
        TSPLength += arc[u][v];
        flag[v] = 1;
        edgeCount++;           //将顶点加入哈密顿回路
        cout<<u<<"-->"<<v<<endl;            //输出经过的路径
        u = v;
    }
    cout<<v<<"-->0"<<endl;                  //输出最后的回边
    return (TSPLength + arc[v][0]);
}

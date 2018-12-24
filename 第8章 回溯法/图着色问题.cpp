#include<bits/stdc++.h>
using namespace std;
const int n = 5;
int arc[n][n]= {{0,1,1,0,0},{1,0,1,1,1},{1,1,0,0,1},{0,1,0,0,1},{0,1,1,1,0}};
int color[n] = {0};
void GraphColor(int m);
int Ok(int k);
int main()
{
    GraphColor(3) ;
    return 0;

}

void GraphColor(int m)
{
    int i, k;
    for (i = 0; i < n; i++ )                     //将数组color[n]初始化为0
        color[i] = 0;
    k = 0;
    while (k >= 0)
    {
        color[k] = color[k] + 1;
        while (color[k] <= m)
            if (Ok(k))
                break;
            else
                color[k] = color[k] + 1;             //搜索下一个颜色
        if (color[k] <= m && k == n - 1)          //求解完毕，输出解
        {
            for (i = 0; i < n; i++)
                cout<<color[i]<<"  ";
            return;
        }
        else if (color[k] <= m && k < n - 1)
            k = k + 1;             //处理下一个顶点
        else
        {
            color[k] = 0;
            k = k - 1;    //回溯
        }
    }
}
int Ok(int k)   //判断顶点k的着色是否发生冲突
{
    for (int i = 0; i < k; i++)
        if (arc[k][i] == 1 && color[i] == color[k])
            return 0;
    return 1;
}

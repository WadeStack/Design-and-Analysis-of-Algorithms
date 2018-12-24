#include<bits/stdc++.h>
using namespace std;
const int N = 5;
int arc[N][N]= {{0,1,0,0,0},{1,0,1,1,0},{0,1,0,0,1},{0,1,0,0,1},{0,0,1,1,0}};
int color[N] = {0};
int Ok(int i);
void ColorGraph( );

int main( )
{
    ColorGraph( );
    for (int i = 0; i < N; i++)
        cout<<color[i]<<" ";
    return 0;
}

void ColorGraph()
{
    int k = 0;
    int flag = 1;
    while (flag == 1)
    {
        k++;
        flag = 0;
        for (int i = 0; i < N; i++)
        {
            if (color[i] == 0)
            {
                color[i] = k;
                if (!Ok(i))
                {
                    color[i] = 0;
                    flag = 1;
                }
            }
        }
    }
}

int Ok(int i)                        //判断顶点i的着色是否发生冲突
{
    for (int j = 0; j < N; j++)
        if (arc[i][j] == 1 && color[i] == color[j])
            return 0;
    return 1;
}


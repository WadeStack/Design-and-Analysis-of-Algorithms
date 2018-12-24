#include<bits/stdc++.h>
using namespace std;
#define N 5
double C[N+1][N+1];
int R[N+1][N+1];
double OptimalBST(double p[ ], int n);
int main()
{
    int i,j;
    double p[]= {0.1, 0.2, 0.4, 0.3};
    cout<<OptimalBST(p,4)<<endl;
    for( i=1; i<6; i++)
    {
        for( j=0; j<5; j++)
        {
            cout<<C[i][j]<<setw(6);
        }
        cout<<endl;
    }
    cout<<endl;
    for( i=1; i<6; i++)
    {
        for( j=0; j<5; j++)
        {
            cout<<R[i][j]<<setw(4);
        }
        cout<<endl;
    }
    return 0;
}
double OptimalBST(double p[ ], int n)
{
    int i, j, k, d, mink;
    double min, sum;
    for (i = 1; i <= n; i++)                //初始化主对角线和第一条次对角线
    {
        C[i][i-1] = 0;
        C[i][i] = p[i-1];
        R[i][i] = i;
    }
    C[n][n-1] = 0;
    for (d = 1; d < n; d++)                //按对角线逐条计算
        for (i = 1; i <= n-d; i++)
        {
            j = i + d;
            min = 1000;
            mink = i;
            sum = 0;     //假设1000为最大值
            for (k = i; k <= j; k++)
            {
                sum = sum + p[k-1];
                if (C[i][k-1] + C[k+1][j] < min)
                {
                    min = C[i][k-1] + C[k+1][j];
                    mink = k;
                }
            }
            C[i][j] = min + sum;
            R[i][j] = mink;
        }
    return C[1][n];
}

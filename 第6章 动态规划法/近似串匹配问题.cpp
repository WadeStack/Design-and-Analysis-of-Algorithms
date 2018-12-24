#include<bits/stdc++.h>
using namespace std;
int D[6][9];
int ASM(char P[ ], char T[ ], int m, int n);
int main()
{
    char P[]="happy";
    char T[]="hsppay";
    cout<<ASM(P,T,5,6)<<endl;
    return 0;
}
int min(int x,int y,int z)
{
    int min;
    if (x < y)
        min = x;
    else
        min = y;
    if (z < min)
        min = z;
    return min;
}
int ASM(char P[ ], char T[ ], int m, int n)
{
    int i, j;
    for (j = 1; j <= n; j++)                     //初始化第0行
        D[0][j] = j;
    for (i = 0; i <= m; i++)                    //初始化第0列
        D[i][0] = i;
    for (j = 1; j <= n; j++)                    //根据递推式依次计算每一列
    {
        for (i = 1; i <= m; i++)
        {
            if (P[i-1] == T[j-1])
                D[i][j] =min(D[i-1][j-1], D[i-1][j]+1, D[i][j-1]+1);
            else
                D[i][j] = min(D[i-1][j-1]+1, D[i-1][j]+1, D[i][j-1]+1);
        }
        for (i = 1; i <= m; i++)
            cout<<D[i][j]<<"  ";
        cout<<endl;

    }
    return D[m][n];
}

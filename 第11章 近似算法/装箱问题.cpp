#include<bits/stdc++.h>
using namespace std;
const int n = 10;
int FirstFit(int s[ ], int n, int b[ ], int C);

int main()
{
    int s[n] = {4, 2, 7, 3, 5, 4, 2, 3, 6, 2};
    int b[n] = {0}, C = 10;
    int num = FirstFit(s, n, b, C);
    cout<< "需要箱子的个数是："<<num<<endl;
    return 0;
}

int FirstFit(int s[ ], int n, int b[ ], int C)
{
    int i, j, k = -1;                  //k表示已装入物品的箱子的最大下标
    for (j = 0; j < n; j++)             //所有箱子的体积初始化为0
        b[j] = 0;
    for (i = 0; i < n; i++)             //装入第i个物品
    {
        j = 0;
        while (C - b[j] < s[i])          //查找第1个能容纳物品i的箱子
            j++;
        b[j] = b[j] + s[i];
        if (k < j)
            k = j;
    }
    return (k + 1);                        //注意数组下标从0开始，k为下标
}

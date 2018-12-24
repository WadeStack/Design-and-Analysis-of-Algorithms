#include<bits/stdc++.h>
using namespace std;
#define n 5
int DataTorwer(int d[n][n]);

int main()
{
    int d[n][n]= {{8},{12,6},{3,9,4},{6,5,7,8},{1,2,3,4,5}};
    int max=DataTorwer(d);
    cout<<max<<endl;
    return 0;
}

int DataTorwer(int d[n][n])         //求解数塔问题，数塔存储在数组d[n][n]中
{
    int maxAdd[n][n] = {0}, path[n][n] = {0};       //初始化
    int i, j;
    for (j = 0; j < n; j++)                         //初始化底层决策结果
        maxAdd[n-1][j] = d[n-1][j];
    for (i = n-2; i >= 0; i--)                       //进行第i层的决策
        for (j = 0; j <= i; j++)                 //填写addMax[i][j]，只填写下三角
            if (maxAdd[i + 1][j]>maxAdd[i + 1][j + 1])
            {
                maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j];
                path[i][j] = j;                  //本次决策选择下标j的元素
            }
            else
            {
                maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j + 1];
                path[i][j] = j + 1;               //本次决策选择下标j+1的元素
            }
    printf("路径为：%d", d[0][0]);         //输出最顶层数字
    j = path[0][0];        //顶层决策是选择下一层列下标为path[0][0]的元素
    for (i = 1; i < n; i++)
    {
        printf("-->%d", d[i][j]);
        j = path[i][j];        //本层决策是选择下一层列下标为path[i][j]的元素
    }
    printf("\n最大数值和为：");
    return maxAdd[0][0];               //返回最大数值和，即最终的决策结果
}

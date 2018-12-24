#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int BatchJob(int a[ ], int b[ ], int n);

int main()
{
    int a[n] = {2, 5, 4}, b[n] = {3, 2, 1};
    int bestTime = BatchJob(a, b, 3) ;
    cout<<"最短作业时间是："<<bestTime<<endl;
    return 0;
}

int BatchJob(int a[ ], int b[ ], int n)
{
    int i, k;
    int x[6], sum1[6], sum2[6];
    int bestTime = 1000;                     //假定最后完成时间不超过1000
    for (i = 1; i <= n; i++)
    {
        x[i] = -1;
        sum1[i] = 0;
        sum2[i] = 0;
    }
    sum1[0] = 0;
    sum2[0] = 0;
    k = 1;
    while (k >= 1)
    {
        x[k] = x[k] + 1;
        while (x[k] < n)
        {
            for (i = 1; i < k; i++)              //检测作业x[k]是否重复处理
                if (x[i] == x[k])
                    break;
            if (i == k)                       //作业x[k]尚未处理
            {
                sum1[k] = sum1[k-1] + a[x[k]];
                if (sum1[k] > sum2[k-1])
                    sum2[k] = sum1[k] + b[x[k]];
                else
                    sum2[k] = sum2[k-1] + b[x[k]];
                if (sum2[k] < bestTime)
                    break;
                else
                    x[k] = x[k] + 1;
            }
            else
                x[k] = x[k] + 1;             //作业x[k]已处理
        }
        if (x[k] < n && k < n)
            k = k + 1;                     //安排下一个作业
        else
        {
            if (x[k] < n && k == n)        //得到一个作业安排
                if (bestTime > sum2[k])
                {
                    bestTime = sum2[k];
                    cout<<"最短的作业安排是：";
                    for (int j = 1; j <= n; j++)
                        cout<<x[j] + 1<<"  ";        ////数组下标从0开始，打印作业编号从1开始
                }
            x[k] = -1;
            k = k - 1;             //重置x[k]，回溯
        }
    }
    return bestTime;
}

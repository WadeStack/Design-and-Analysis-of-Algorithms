#include<bits/stdc++.h>
using namespace std;
int ClosestPoints(int x[ ], int y[ ], int n);

int main()
{
    int x[]= {1,3,5,1};
    int y[]= {1,2,4,2};
    ClosestPoints(x,y,4);
    return 0;
}
int ClosestPoints(int x[ ], int y[ ], int n)
{
    int index1, index2;                           //记载最近点对的下标
    int d, minDist = 1000;                        //假设最大距离不超过1000
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)                  //只考虑i＜j的点对
        {
            d = (x[i]-x[j])* (x[i]-x[j]) + (y[i]-y[j])* (y[i]-y[j]);
            if (d < minDist)
            {
                minDist = d;
                index1 = i;
                index2 = j;
            }
        }
    cout<<"最近的点对是："<<index1<<"和"<<index2<<endl;
    return  minDist;
}

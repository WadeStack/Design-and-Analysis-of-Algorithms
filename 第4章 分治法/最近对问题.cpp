#include<bits/stdc++.h>
using namespace std;
const int n = 6;
struct point
{
    int x, y;
};

double Closest(point S[ ], int low, int high);
double Distance(point a, point b);
int Partition(point r[ ], int first, int end);
void QuickSort(point r[ ], int first, int end);

int main()
{
    point S[n] = {{1,1},{1,8},{2,6},{3,2},{4,1},{5,4}};
    double minDist = Closest(S,0,n-1);
    cout<<minDist<<endl;
    return 0;
}

double Closest(point S[ ], int low, int high)
{
    double d1, d2, d3, d;
    int mid, i, j, index;
    point P[n];                   //存放P1和P2
    if (high - low == 1)
        return Distance(S[low], S[high]);
    if (high - low == 2)
    {
        d1 = Distance(S[low], S[low+1]);
        d2 = Distance(S[low+1], S[high]);
        d3 = Distance(S[low], S[high]);
        if ((d1 < d2) && (d1 < d3))
            return d1;
        else if (d2 < d3)
            return d2;
        else
            return d3;
    }
    mid = (low + high)/2;
    d1 = Closest(S, low, mid);
    d2 = Closest(S, mid+1, high);
    if (d1 <= d2)
        d = d1;
    else
        d = d2;
    index = 0;
    for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--)
        P[index++] = S[i];
    for (i = mid + 1; (i <= high) && (S[i].x - S[mid].x < d); i++)
        P[index++] = S[i];
    QuickSort(P, 0, index-1);
    for (i = 0; i < index; i++)
    {
        for(j = i + 1; j < index; j++)
        {
            if (P[j].y - P[i].y >= d)
                break;
            else
            {
                d3 = Distance(P[i], P[j]);
                if (d3 < d)
                    d = d3;
            }
        }
    }
    return d;
}

double Distance(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int Partition(point r[ ], int first, int end)          //划分
{
    int i = first, j=end;                       //初始化待划分区间
    while (i < j)
    {
        while (i < j && r[i].y <= r[j].y)
            j--;          //右侧扫描
        if (i < j)
        {
            point temp = r[i];
            r[i] = r[j];
            r[j] = temp;     //将较小记录交换到前面
            i++;
        }
        while (i < j && r[i].y <= r[j].y)
            i++;         //左侧扫描
        if (i < j)
        {
            point temp = r[i];
            r[i] = r[j];
            r[j] = temp;     //将较大记录交换到后面
            j--;
        }
    }
    return i;                                // 返回轴值记录的位置
}
void QuickSort(point r[ ], int first, int end)        //快速排序
{
    int pivot;
    if (first < end)
    {
        pivot = Partition(r, first, end);    //划分，pivot是轴值在序列中的位置
        QuickSort(r, first, pivot-1);      //求解子问题1，对左侧子序列进行快速排序
        QuickSort(r, pivot+1, end);      //求解子问题2，对右侧子序列进行快速排序
    }
}

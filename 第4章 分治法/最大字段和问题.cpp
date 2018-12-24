#include<bits/stdc++.h>
using namespace std;
int MaxSum(int a[ ], int left, int right);
int main()
{
    int a[]= {-20,11,-4,13,-5,-2};
    int sum=MaxSum(a,0,5);
    cout<<sum;
    return 0;
}
int MaxSum(int a[ ], int left, int right)      //求序列a[left]~a[right]的最大子段和
{
    int sum = 0, midSum = 0, leftSum = 0, rightSum = 0,i,j;
    int center, s1, s2, lefts, rights;
    if (left == right)                      //如果序列长度为1，直接求解
        sum = a[left];
    else
    {
        center = (left + right)/2;             //划分
        leftSum = MaxSum(a, left, center);          //对应情况①，递归求解
        rightSum = MaxSum(a, center+1, right);      //对应情况②，递归求解
        s1 = 0;
        lefts = 0;                         //以下对应情况③，先求解s1
        for (i = center; i >= left; i--)
        {
            lefts += a[i];
            if (lefts > s1)
                s1 = lefts;
        }
        s2 = 0;
        rights = 0;                        //再求解s2
        for (j = center + 1; j <= right; j++)
        {
            rights += a[j];
            if (rights > s2)
                s2 = rights;
        }
        midSum = s1 + s2;                          //计算情况③的最大子段和
        if (midSum < leftSum)
            sum = leftSum;           //合并解，取较大者
        else
            sum = midSum;
        if (sum < rightSum)
            sum = rightSum;
    }
    return sum;
}

#include<bits/stdc++.h>
using namespace std;
int ArrayMin(int a[ ], int n);

int main()
{
    int a[]= {4,9,8,7,6};
    int min=ArrayMin(a,5);
    cout<<"数组中的最小值是："<<min<<endl;
    return 0;
}

int ArrayMin(int a[ ], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

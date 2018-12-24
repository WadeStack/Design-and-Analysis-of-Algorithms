#include<bits/stdc++.h>
using namespace std;
void Union(int A[ ], int n, int B[ ], int m, int C[ ] );

int main()
{
    int i, C[12];
    int A[5] = {1, 3, 5, 7, 9};
    int B[7] = {2, 3, 3, 4, 6, 7, 8};
    Union(A, 5, B, 7, C);
    cout<<"合并排序后：";
    for(i = 0; i < 12; i++)
        cout<<C[i]<<" ";
    cout<<endl;
    return 0;
}
void Union(int A[ ], int n, int B[ ], int m, int C[ ] )   //合并A[n]和B[m]
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
            C[k++] = A[i++];     //A[i]与B[j]中较小者存入C[k]
        else
            C[k++] = B[j++];
    }
    while (i < n)
        C[k++] = A[i++];    //收尾处理，序列A中还有剩余记录
    while (j < m)
        C[k++] = B[j++];    //收尾处理，序列B中还有剩余记录
}


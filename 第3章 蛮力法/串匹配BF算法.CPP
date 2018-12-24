#include<bits/stdc++.h>
using namespace std;
int BF(char S[ ], char T[ ]);

int main()
{
    char S[]="abcabcabcaccb";
    char T[]="abcacc";
    int index=BF(S,T);
    for (int i = 1; i < index; i++)
        cout<<" ";
    cout<<T<<"在"<<endl;
    cout<<S<<"中的位置是："<<index<<endl;
    return 0;
}

int BF(char S[ ], char T[ ])
{
    int index = 0;                            //主串从下标0开始第一趟匹配
    int i = 0, j = 0;                           //设置比较的起始下标
    while ((S[i] != '\0') && (T[j] != '\0'))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            index++;    //i和j分别回溯
            i = index;
            j = 0;
        }
    }
    if (T[j] == '\0')
        return index + 1;      //返回本趟匹配的开始位置（不是下标）
    else
        return 0;
}

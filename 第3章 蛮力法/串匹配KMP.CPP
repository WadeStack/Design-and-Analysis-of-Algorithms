#include<bits/stdc++.h>
using namespace std;
void GetNext(char T[ ], int next[ ]);
int KMP(char S[],char T[]);

int main()
{
    char  S[]="ababcabcacbab";
    char  T[]="abcac";
    int index = KMP(S,T);
    for (int i = 1; i < index; i++)
        cout<<" ";
    cout<<T<<"在"<<endl;
    cout<<S<<"中的位置是："<<index<<endl;;
    return 0;
}

int KMP(char S[],char T[])
{
    int i = 0, j = 0;
    int next[80] = {-1};
    GetNext(T,next);
    while (S[i] != '\0' && T[j] != '\0')
    {
        if(S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
    if(T[j] == '\0')
        return i - strlen(T) + 1;
    else
        return 0;
}
void GetNext(char T[], int next[])
{
    int i, j, len;
    next[0] = -1;
    for (j = 1; T[j]!='\0'; j++)
    {
        for (len = j - 1; len >= 1; len--)
        {
            for (i = 0; i < len; i++)
                if(T[i] != T[j-len+i])
                    break;
            if (i == len)
            {
                next[j] = len;
                break;
            }
        }
        if (len < 1)
            next[j] = 0;
    }
}

/* 以下为改进的蛮力算法
void GetNext(char T[ ], int next[ ])
{
	int j = 0, k = -1;
	next[0] = -1;
	while (T[j] != '\0')                           //直到字符串末尾
	{
		if (k == -1) {                           //无相同子串
			next[++j] = 0; k = 0;
		}else if (T[j] == T[k]) {                //确定next[j+1]的值
				k++;
				next[++j] = k;
			} else k = next[k];          //取T[0]...T[j]的下一个相等子串的长度
	}
 }
*/

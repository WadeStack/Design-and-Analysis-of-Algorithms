#include<bits/stdc++.h>
using namespace std;
char Game(char r[ ], int n);
int Comp(char a,char b);

int main()
{
    char r[]="AFGBEHCD";
    char c=Game(r,8);
    cout<<"最后的冠军是："<<c<<endl;
    return 0;
}
int Comp(char a,char b)
{
    if(a>b)
        return 1;
    else
        return 0;
}
char Game(char r[ ], int n)
{
    int i = n;
    while (i > 1)                        //比赛直到剩余1人即为冠军
    {
        i = i/2;
        for (int j = 0; j < i; j++)
            if (Comp(r[j+i], r[j]))            //胜者存入r[j]中
                r[j] = r[j+i];
    }
    return r[0];
}
